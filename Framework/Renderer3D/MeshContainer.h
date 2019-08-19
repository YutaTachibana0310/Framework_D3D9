//=====================================
//
//���b�V���R���e�i�w�b�_[MeshContainer.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _MESHCONTAINER_H_
#define _MESHCONTAINER_H_

#include "../../main.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class MeshContainer
{
	friend class ResourceManager;
public:
	static MeshContainer* Create();
	void Release();

	HRESULT Load(const char* filePath);	//X�t�@�C���̓ǂݍ���
	void Draw();						//���f����`��

	UINT GetMaterialNum();
	void GetMaterial(UINT index, D3DMATERIAL9& out);
	void SetMaterialColor(const D3DXCOLOR& color, UINT index);
	void SetMaterialAlpha(float alpha, UINT index);

	void AddRef();

protected:								
	MeshContainer();					//�R���X�g���N�^
	~MeshContainer();					//�f�X�g���N�^


	LPD3DXMESH mesh;					//���b�V���f�[�^
	D3DMATERIAL9* materials;			//�}�e���A�����
	LPDIRECT3DTEXTURE9 *textures;		//�e�N�X�`��
	DWORD materialNum;					//�}�e���A����

	UINT cntReference;
};

#endif