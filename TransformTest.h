//=====================================
//
//�g�����X�t�H�[���e�X�g�w�b�_[TransformTest.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _TRANSFORMTEST_H_
#define _TRANSFORMTEST_H_

#include "main.h"
#include "Framework\Renderer3D\MeshContainer.h"
#include "Framework\Core\BaseScene.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class TransformTest : public BaseScene
{
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

	Transform transform;
private:
	MeshContainer *mesh;
};

#endif