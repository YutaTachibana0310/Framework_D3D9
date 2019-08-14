//=====================================
//
//�J�����w�b�_[Camera.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../../main.h"
#include "../Pattern/BaseSingleton.h"
#include "../Transform.h"

#include <vector>

/**************************************
�J�����v���O�C�����N���X
***************************************/
class Camera;
class BaseCameraPlugin
{
public:
	virtual void Update() = 0;
	virtual void Apply(Camera& camera) = 0;
};

/**************************************
Camera�N���X
***************************************/
class Camera : public BaseSingleton<Camera>
{
	friend class BaseSingleton<Camera>;
public:
	void Init();		//������
	void Update();		//�X�V
	void Set();			//�J������񔽉f����

protected:
	//SRT���
	Transform transform;

	//�����_
	D3DXVECTOR3 target;

	//���_�A�����_�A������i��Ɨp�̈�j
	D3DXVECTOR3 eyeWork;
	D3DXVECTOR3 targetWork;
	D3DXVECTOR3 upWork;

	//����p�A�A�X�y�N�g��A�j�A�l�A�t�@�[�l
	float viewAngle;
	float viewAspect;
	float viewNear;
	float viewFar;

	//�v���O�C�����X�g
	std::vector<BaseCameraPlugin*> pluginList;

private:
	Camera();
	Camera(const Camera&) {}
	~Camera() {}

public:
	/**************************************
	�J������h�炷�v���O�C���N���X
	***************************************/
	class CameraShakePlugin : public BaseCameraPlugin, public BaseSingleton<CameraShakePlugin>
	{
		friend class BaseSingleton<CameraShakePlugin>;
	public:
		void Update();
		void Apply(Camera& camera);
		void Set(D3DXVECTOR3 amplitude, int duration = 30);

	private:
		int cntFrame;
		D3DXVECTOR3 amplitude;
		int duration;
		bool active;

		CameraShakePlugin();
		CameraShakePlugin(const CameraShakePlugin&) {}
		~CameraShakePlugin(){}
	};
};

#endif