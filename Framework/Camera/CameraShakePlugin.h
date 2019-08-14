//=====================================
//
//�J�����V�F�C�N�v���O�C���w�b�_[CameraShakePlugin.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _CAMERASHAKEPLUGIN_H_
#define _CAMERASHAKEPLUGIN_H_

#include "Camera.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class Camera::CameraShakePlugin : public BaseCameraPlugin, public BaseSingleton<CameraShakePlugin>
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
	~CameraShakePlugin() {}
};

#endif