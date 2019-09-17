//=============================================================================
//
// ���͏��� [input.cpp]
// Author : 
//
//=============================================================================
#include "input.h"

//*****************************************************************************
// static�����o
//*****************************************************************************
#undef new
//*****************************************************************************
// �R���X�g���N�^
//*****************************************************************************
Input::Input()
{
	if (mInstance == NULL)
	{
		mInstance = this;
	}

	pad = new GamePad();
	keyboard = new Keyboard();
	mouse = new Mouse();
}

//=============================================================================
// ���͏����̏�����
//=============================================================================
HRESULT Input::Init(HINSTANCE hInst, HWND hWnd)
{
	HRESULT hr;

	//if(!pDInput)
	{
		// DirectInput�I�u�W�F�N�g�̍쐬
		hr = DirectInput8Create(hInst, DIRECTINPUT_VERSION,
									IID_IDirectInput8, (void**)&pDInput, NULL);
	}

	// �L�[�{�[�h�̏�����
	keyboard->Init(hInst, hWnd, pDInput);

	//�}�E�X������
	mouse->Init(hInst, hWnd, pDInput);

	//�p�b�h����������
	pad->Init(pDInput);

	return S_OK;
}

//=============================================================================
// ���͏����̏I������
//=============================================================================
Input::~Input()
{
	// �L�[�{�[�h�̏I������
	SAFE_DELETE(keyboard);

	//�}�E�X�I������
	SAFE_DELETE(mouse);

	//�p�b�h�I������
	SAFE_DELETE(pad);

	if(pDInput)
	{// DirectInput�I�u�W�F�N�g�̊J��
		pDInput->Release();
		pDInput = NULL;
	}

	if (mInstance == this)
	{
		mInstance = NULL;
	}
}

//=============================================================================
// ���͏����̍X�V����
//=============================================================================
void Input::Update(void)
{
	// �L�[�{�[�h�̍X�V
	keyboard->Update();

	//�}�E�X�X�V����
	mouse->Update();

	//�Q�[���p�b�h�X�V����
	pad->Update();
}

//=============================================================================
// ���������ւ̓��͏���
//=============================================================================
float Input::GetPressHorizontail(int no)
{
	if (no == 0)
	{
		if (Keyboard::GetPress(DIK_LEFT) || GamePad::GetPress(0, BUTTON_LEFT))
			return -1.0f;

		if (Keyboard::GetPress(DIK_RIGHT) || GamePad::GetPress(0, BUTTON_RIGHT))
			return 1.0f;

		return 0.0f;
	}

	if (GamePad::GetPress(no, BUTTON_LEFT))
		return -1.0f;

	if (GamePad::GetPress(no, BUTTON_RIGHT))
		return 1.0f;

	return 0.0f;
}

//=============================================================================
// ���������ւ̓��͏���
//=============================================================================
float Input::GetPressVertical(int no)
{
	if (no == 0)
	{
		if (Keyboard::GetPress(DIK_DOWN) || GamePad::GetPress(0, BUTTON_DOWN))
			return -1.0f;

		if (Keyboard::GetPress(DIK_UP) || GamePad::GetPress(0, BUTTON_UP))
			return 1.0f;

		return 0.0f;
	}

	if (GamePad::GetPress(no, BUTTON_DOWN))
		return -1.0f;

	if (GamePad::GetPress(no, BUTTON_UP))
		return 1.0f;

	return 0.0f;
}