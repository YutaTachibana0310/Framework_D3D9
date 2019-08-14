//=====================================
//
//カメラ処理[Camera.cpp]
//Author:GP12A332 21 立花雄太
//
//=====================================
#include "Camera.h"
#include "../Math/Easing.h"

/**************************************
マクロ定義
***************************************/

/**************************************
コンストラクタ
***************************************/
Camera::Camera()
{
	pluginList.push_back(CameraShakePlugin::Instance());
}

/**************************************
初期化処理
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
セット処理
***************************************/
void Camera::Set()
{
	//作業領域に現在のパラメータを設定
	eyeWork = transform.pos;
	targetWork = target;
	upWork = transform.Up();

	//プラグイン反映
	for (auto& plugin : pluginList)
	{
		plugin->Apply(*this);
	}

	D3DXMATRIX view, projection;
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//ビュー行列作成
	D3DXMatrixIdentity(&view);
	D3DXMatrixLookAtLH(&view,
		&eyeWork,
		&targetWork,
		&upWork);

	//ビュー行列設定
	pDevice->SetTransform(D3DTS_VIEW, &view);

	//プロジェクション行列作成
	D3DXMatrixIdentity(&projection);
	D3DXMatrixPerspectiveFovLH(&projection,
		viewAngle,
		viewAspect,
		viewNear,
		viewFar);

	//プロジェクション行列設定
	pDevice->SetTransform(D3DTS_PROJECTION, &projection);
}

/**************************************
更新処理
***************************************/
void Camera::Update()
{
	//各プラグイン更新
	for (auto& plugin : pluginList)
	{
		plugin->Update();
	}
}

/**************************************
CameraShakePluginコンストラクタ
***************************************/
Camera::CameraShakePlugin::CameraShakePlugin()
{
	cntFrame = 0;
	ZeroMemory(&amplitude, sizeof(amplitude));
	duration = 0;
	active = false;
}

/**************************************
CameraShakePlugin更新処理
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
CameraShakePlugin反映処理
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
CameraShakePluginセット処理
***************************************/
void Camera::CameraShakePlugin::Set(D3DXVECTOR3 amplitude, int duration)
{
	cntFrame = 0;
	this->amplitude = amplitude;
	this->duration = duration;
	active = true;
}