//=====================================
//
//�J��������[Camera.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "Camera.h"
#include "../Math/Easing.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�R���X�g���N�^
***************************************/
Camera::Camera()
{
	pluginList.push_back(CameraShakePlugin::Instance());
}

/**************************************
����������
***************************************/
void Camera::Init()
{
	const D3DXVECTOR3 InitPos = D3DXVECTOR3(0.0f, 0.0f, -150.0f);
	const D3DXVECTOR3 InitTarget = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	const float InitViewAngle = D3DXToRadian(60.0f);
	const float InitViewAspect = (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT;
	const float InitViewNear = 10.0f;
	const float InitViewFar = 50000.0f;

	transform.pos = InitPos;
	target = InitTarget;
	viewAngle = InitViewAngle;
	viewAspect = InitViewAspect;
	viewNear = InitViewNear;
	viewFar = InitViewFar;
}

/**************************************
�Z�b�g����
***************************************/
void Camera::Set()
{
	//��Ɨ̈�Ɍ��݂̃p�����[�^��ݒ�
	eyeWork = transform.pos;
	targetWork = target;
	upWork = transform.Up();

	//�v���O�C�����f
	for (auto& plugin : pluginList)
	{
		plugin->Apply(*this);
	}

	D3DXMATRIX view, projection;
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�r���[�s��쐬
	D3DXMatrixIdentity(&view);
	D3DXMatrixLookAtLH(&view,
		&eyeWork,
		&targetWork,
		&upWork);

	//�r���[�s��ݒ�
	pDevice->SetTransform(D3DTS_VIEW, &view);

	//�v���W�F�N�V�����s��쐬
	D3DXMatrixIdentity(&projection);
	D3DXMatrixPerspectiveFovLH(&projection,
		viewAngle,
		viewAspect,
		viewNear,
		viewFar);

	//�v���W�F�N�V�����s��ݒ�
	pDevice->SetTransform(D3DTS_PROJECTION, &projection);
}

/**************************************
�X�V����
***************************************/
void Camera::Update()
{
	//�e�v���O�C���X�V
	for (auto& plugin : pluginList)
	{
		plugin->Update();
	}
}

/**************************************
CameraShakePlugin�R���X�g���N�^
***************************************/
Camera::CameraShakePlugin::CameraShakePlugin()
{
	cntFrame = 0;
	ZeroMemory(&amplitude, sizeof(amplitude));
	duration = 0;
	active = false;
}

/**************************************
CameraShakePlugin�X�V����
***************************************/
void Camera::CameraShakePlugin::Update()
{
	if (!active)
		return;

	cntFrame++;
	
	if (cntFrame == duration)
	{
		active = false;
	}

}

/**************************************
CameraShakePlugin���f����
***************************************/
void Camera::CameraShakePlugin::Apply(Camera& camera)
{
	if (!active)
		return;

	float t = (float)cntFrame / duration;
	float range = Easing::EaseValue(t, 1.0f, 0.0f, EaseType::OutCirc);

	D3DXVECTOR3 offset;
	offset.x = Math::RandomRange(-range, range) * amplitude.x;
	offset.y = Math::RandomRange(-range, range) * amplitude.y;
	offset.z = Math::RandomRange(-range, range) * amplitude.z;

	camera.eyeWork += offset;
	camera.targetWork += offset;
}

/**************************************
CameraShakePlugin�Z�b�g����
***************************************/
void Camera::CameraShakePlugin::Set(D3DXVECTOR3 amplitude, int duration)
{
	cntFrame = 0;
	this->amplitude = amplitude;
	this->duration = duration;
	active = true;
}