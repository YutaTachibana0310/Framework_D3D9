//=====================================
//
//�g�D�C�[���e�X�g�w�b�_[TweenTest.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _TWEENTEST_H_
#define _TWEENTEST_H_

#include "../main.h"
#include "../Framework\Core\BaseScene.h"
#include "../Framework/Renderer3D/TransformObject.h"

/**************************************
�O���錾
***************************************/

/**************************************
�}�N���E�񋓎q��`
***************************************/

/**************************************
�N���X��`
***************************************/
class TweenTest : public BaseScene
{
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
	TransformObject *object;
};

#endif