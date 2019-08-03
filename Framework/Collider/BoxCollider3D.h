//=====================================
//
//�{�b�N�X�R���C�_�[3D�w�b�_[BoxCollider3D.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _BOXCOLLIDER3D_H_
#define _BOXCOLLIDER3D_H_

#include "../../main.h"
#include "../Pattern/ObserveSubject.h"

#include <map>
#include <list>

#define BOXCOLLIDER3D_USE_DEBUG

/**************************************
BoxCollider3DTag�񋓎q
***************************************/
enum class BoxCollider3DTag
{
	PlayerBomber,
	Enemy,
	Max
};

/**************************************
BoxCollider3D�N���X
***************************************/
class BoxCollider3D : public ObserveSubject
{
public:
	friend class BoxCollider3D;

	//�R���X�g���N�^�A�f�X�g���N�^
	BoxCollider3D(BoxCollider3DTag tag, D3DXVECTOR3 *pPos);
	BoxCollider3D(BoxCollider3DTag tag, D3DXVECTOR3 *pPos, D3DXVECTOR3 size);
	~BoxCollider3D();

	//�Փ˔���A�T�C�Y�Z�b�g�A���W�A�h���X�Z�b�g
	bool CheckCollision(BoxCollider3D *other);
	void SetSize(D3DXVECTOR3 size);
	void SetPosAddress(D3DXVECTOR3 *pPos);

	//�Փ˔���
	static void UpdateCollision();
	void RegisterToCheckList();
	void RemoveFromCheckList();

	//�A�N�e�B�u����
	bool active;

#ifdef BOXCOLLIDER3D_USE_DEBUG
	//�f�o�b�O�p�`�揈��
	static void DrawCollider(BoxCollider3D *collider);
#endif

private:
	BoxCollider3D() {}

	BoxCollider3DTag tag;	//�^�O
	D3DXVECTOR3 *pPos;		//�e�̍��W�A�h���X
	D3DXVECTOR3 size;		//�T�C�Y
	D3DXVECTOR3 offset;		//�I�t�Z�b�g

	static std::map<BoxCollider3DTag, std::list<BoxCollider3D*>> checkDictionary;


#ifdef BOXCOLLIDER3D_USE_DEBUG
	static UINT instanceCount;		//�C���X�^���X�J�E���g
	static D3DMATERIAL9 material;	//�`��p�}�e���A��
	static LPD3DXMESH mesh;			//�`��p���b�V��
#endif
};
#endif