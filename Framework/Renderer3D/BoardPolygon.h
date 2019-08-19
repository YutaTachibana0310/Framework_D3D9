//=====================================
//
//�|���S���w�b�_[BoardPolygon.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _BOARDPOLYGON_H_
#define _BOARDPOLYGON_H_

#include "../../main.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class BoardPolygon
{
	friend class ResourceManager;
public:
	//�C���X�^���X�쐬�֐�
	static BoardPolygon* Create();

	//�C���X�^���X����֐�
	void Release();

	//�`�揈��
	void Draw();

	//�e�N�X�`���ǂݍ��ݏ���
	void LoadTexture(const char* path);

	//�T�C�Y�ݒ菈��
	void SetSize(D3DXVECTOR2 size);

	//UV�����ݒ菈��
	void SetTexDiv(D3DXVECTOR2 div);

	//�e�N�X�`���ʂ��ԍ��ݒ菈��
	void SetTextureIndex(int index);

	void AddRef();
protected:
	BoardPolygon();
	~BoardPolygon();


	LPDIRECT3DDEVICE9 pDevice;

	LPDIRECT3DVERTEXBUFFER9 vtxBuff;
	LPDIRECT3DTEXTURE9 texture;

	D3DXVECTOR2 texDiv;
	D3DXVECTOR2 texSize;

	UINT cntReference;
};

#endif