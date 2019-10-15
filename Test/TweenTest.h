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
#include "../Framework/Math/Easing.h"
#include <functional>

/**************************************
�O���錾
***************************************/

/**************************************
�}�N���E�񋓎q��`
***************************************/

/**************************************
�N���X��`
***************************************/
class TweenObject : public TransformObject
{
	using TransformObject::TransformObject;
public:
	void Move(const D3DXVECTOR3& target, EaseType type);
	void Rotate(const D3DXVECTOR3& target, EaseType type);
	void Scale(const D3DXVECTOR3& target, EaseType type);
	void Callback(const D3DXVECTOR3& rotTarget, EaseType type, const std::function<void(void)>& callback);
};

class TweenTest : public BaseScene
{
public:
	void Init();
	void Uninit();
	void Update();
	void Draw();

private:
	TweenObject *object;
};

#endif