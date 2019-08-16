//=====================================
//
//�Q�[������[Game.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "BaseGame.h"
#include "..\Input\input.h"
#include "..\Camera\Camera.h"
#include "..\Tool\DebugWindow.h"
#include "..\PostEffect\PostEffectManager.h"

/**************************************
�}�N����`
***************************************/
#define BACKCOLOR	(D3DCOLOR_RGBA(0, 0, 50, 255))

Camera* Camera::mInstance = NULL;
Input* Input::mInstance = NULL;
/**************************************
�R���X�g���N�^
***************************************/
BaseGame::BaseGame(HINSTANCE hInstance, HWND hWnd)
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�C���X�^���X�쐬
	sceneManager = new SceneManager();
	Camera::mInstance = new Camera();
	Input::mInstance = new Input();

	//�`��̈�쐬
	MakeScreen();
	MakeRenderTarget();

	//�|�X�g�G�t�F�N�g�Ƀ����_�[�e�N�X�`���ւ̎Q�Ƃ�n��
	PostEffectManager::Instance()->PassDefaultTarget(renderTexture);

	//�|�X�g�G�t�F�N�g�L����
	unsigned flgEffect = 0;
	for (int i = 0; i < PostEffectManager::PostEffect::Max; i++)
	{
		flgEffect |= 0x01;
		flgEffect = flgEffect << 1;
	}
	PostEffectManager::Instance()->SetUse(flgEffect);

	//�e�평����
	Input::mInstance->Init(hInstance, hWnd);
	Camera::mInstance->Init();
	Debug::Init(hWnd, pDevice);

}

/**************************************
�f�X�g���N�^
***************************************/
BaseGame::~BaseGame()
{
	SAFE_RELEASE(renderTexture);
	SAFE_RELEASE(renderSurface);
	SAFE_RELEASE(screenVtx);

	SAFE_DELETE(Camera::mInstance);
	SAFE_DELETE(Input::mInstance);

	Debug::Uninit();
}

/**************************************
�X�V����
***************************************/
void BaseGame::Update()
{
	Debug::Update();
	Input::mInstance->Update();
	Camera::mInstance->Update();

	sceneManager->Update();

	PostEffectManager::Instance()->Update();
}

/**************************************
�`�揈��
***************************************/
void BaseGame::Draw()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�����_�[�^�[�Q�b�g�؂�ւ�
	LPDIRECT3DSURFACE9 oldSuf;
	pDevice->GetRenderTarget(0, &oldSuf);
	pDevice->SetRenderTarget(0, renderSurface);
	pDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, BACKCOLOR, 1.0f, 0);

	//�J�����ݒ�
	Camera::mInstance->Set();

	//�V�[����`��
	sceneManager->Draw();

	//�����_�[�^�[�Q�b�g����
	pDevice->SetRenderTarget(0, oldSuf);
	SAFE_RELEASE(oldSuf);

	//�o�b�N�o�b�t�@�֕`��
	pDevice->SetTexture(0, renderTexture);
	pDevice->SetStreamSource(0, screenVtx, 0, sizeof(VERTEX_2D));
	pDevice->SetFVF(FVF_VERTEX_2D);
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, NUM_POLYGON);

	//�f�o�b�O�E�B���h�E�`��
	Debug::Draw();
}

/**************************************
�X�N���[���쐬����
***************************************/
void BaseGame::MakeScreen()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	pDevice->CreateVertexBuffer(sizeof(VERTEX_2D) * NUM_VERTEX,
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_2D,
		D3DPOOL_MANAGED,
		&screenVtx,
		0);

	VERTEX_2D *pVtx;
	screenVtx->Lock(0, 0, (void**)&pVtx, 0);

	pVtx[0].vtx = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	pVtx[1].vtx = D3DXVECTOR3(SCREEN_WIDTH, 0.0f, 0.0f);
	pVtx[2].vtx = D3DXVECTOR3(0.0f, SCREEN_HEIGHT, 0.0f);
	pVtx[3].vtx = D3DXVECTOR3(SCREEN_WIDTH, SCREEN_HEIGHT, 0.0f);

	pVtx[0].tex = D3DXVECTOR2(0.0f, 0.0f);
	pVtx[1].tex = D3DXVECTOR2(1.0f, 0.0f);
	pVtx[2].tex = D3DXVECTOR2(0.0f, 1.0f);
	pVtx[3].tex = D3DXVECTOR2(1.0f, 1.0f);

	pVtx[0].rhw =
		pVtx[1].rhw =
		pVtx[2].rhw =
		pVtx[3].rhw = 1.0f;

	pVtx[0].diffuse =
		pVtx[1].diffuse =
		pVtx[2].diffuse =
		pVtx[3].diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);

	screenVtx->Unlock();
}

/**************************************
�����_�[�^�[�Q�b�g�쐬����
***************************************/
void BaseGame::MakeRenderTarget()
{
	LPDIRECT3DDEVICE9 pDevice = GetDevice();

	//�����_�[�e�N�X�`���쐬
	pDevice->CreateTexture(SCREEN_WIDTH,
		SCREEN_HEIGHT,
		1,
		D3DUSAGE_RENDERTARGET,
		D3DFMT_X8R8G8B8,
		D3DPOOL_DEFAULT,
		&renderTexture,
		0);

	renderTexture->GetSurfaceLevel(0, &renderSurface);
}