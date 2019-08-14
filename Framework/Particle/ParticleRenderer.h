//=====================================
//
//�p�[�e�B�N�������_���[�w�b�_[ParticleRenderer.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _PARTICLERENDERER_H_
#define _PARTICLERENDERER_H_

#include "../../main.h"
#include <vector>

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class ParticleRenderer
{
public:
	ParticleRenderer();
	~ParticleRenderer();

	void BeginDraw();
	void EndDraw();

	void EmbedTransform(const 

private:
	LPDIRECT3DVERTEXDECLARATION9 declare;
	LPD3DXEFFECT effect;
	LPDIRECT3DINDEXBUFFER9 indexBuff;
	LPDIRECT3DVERTEXBUFFER9 transformBuff, uvBuff;
	static D3DXHANDLE hMtxView, hMtxProjection, hMtxInvView;

	void LoadEffect();
	void MakeDeclaration();
	void MakeTransformBuffer();
	void MakeUVBuffer();
	void MakeIndexBuffer();
;

#endif