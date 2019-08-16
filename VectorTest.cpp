//=====================================
//
//�e���v���[�g����[VectorTest.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "VectorTest.h"
#include "Framework\Tool\DebugWindow.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�O���[�o���ϐ�
***************************************/
void VectorTest::Uninit()
{
	SAFE_DELETE(mesh);
}

/**************************************
�v���g�^�C�v�錾
***************************************/
void VectorTest::Init()
{
	mesh = new MeshContainer();
	mesh->Load("data/MODEL/transform.x");

	transform3D.pos = Vector3::Zero;
	transform3D.IdentifyRotation();
}

/**************************************
�v���g�^�C�v�錾
***************************************/
void VectorTest::Update()
{
	Debug::Begin("Vector");

	static D3DXVECTOR3 target = Vector3::Forward;
	if (Debug::Button("Set"))
	{
		target.x = Math::RandomRange(-20.0f, 20.0f);
		target.y = Math::RandomRange(-20.0f, 20.0f);
		target.z = Math::RandomRange(-20.0f, 20.0f);
	}

	float angle = Vector3::Angle(transform3D.Forward(), target);
	D3DXVECTOR3 axis = Vector3::Axis(transform3D.Forward(), target);
	transform3D.RotateByAxis(angle * 0.3f, axis);
	
	Debug::Text("target : %f, %f, %f", target.x, target.y, target.z);
	Debug::Text("angle : %f", angle);
	Debug::Text("axis : %f, %f, %f", axis.x, axis.y, axis.z);
	Debug::Text("forward : %f, %f, %f", transform3D.Forward().x, transform3D.Forward().y, transform3D.Forward().z);

	Debug::End();
}

/**************************************
�v���g�^�C�v�錾
***************************************/
void VectorTest::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	transform3D.SetWorld();
	mesh->Draw();
}
