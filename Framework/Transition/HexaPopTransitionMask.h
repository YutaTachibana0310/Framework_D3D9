//=====================================
//
//�w�L�T�|�b�v�g�����W�V�����w�b�_[HexaTransitionMaskPop.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _HEXAPOPTRANSITIONMASK_H_
#define _HEXAPOPTRANSITIONMASK_H_

#include "../../main.h"
#include "BaseTransitionMask.h"
#include "../Math/Easing.h"

#include <vector>

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class HexaPopTransitionMask : public BaseTransitionMask
{
public:
	//�R���X�g���N�^�A�f�X�g���N�^
	HexaPopTransitionMask();
	~HexaPopTransitionMask();

	MaskResult Update() override;				//�X�V����
	void Draw() override;						//�`�揈��
	void Set(bool isTransitionOut) override;	//�Z�b�g����
	
private:
	//�}�X�N�̈�ƂȂ�Z�p�`�̃C���i�[�N���X
	class Hexagon
	{
	public:
		Hexagon(D3DXVECTOR3 pos);

		void Init();
		void Update(HexaPopTransitionMask& parent);
		bool IsLastHexa(HexaPopTransitionMask& parent);

		Transform transform;
		int cntFrame;
		bool active;
	};

	//�J�E���^
	int cntFrame;
	UINT rowIndex;

	//�Z�p�`�̃x�N�^�[�ƃC�e���[�^
	std::vector<std::vector<Hexagon*>> hexList;
	std::vector<std::vector<Hexagon*>::iterator> itrList;

	//�C�[�W���O�p�����[�^
	D3DXVECTOR3 startScale, endScale;
	EaseType type;

	//�I���t���O
	bool isFinished;
};
#endif