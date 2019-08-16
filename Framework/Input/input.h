//=============================================================================
//
// ���͏��� [input.h]
// Author : 
//
//=============================================================================
#ifndef _INPUT_H_
#define _INPUT_H_

#include "../../main.h"
#include "Gamepad.h"
#include "Mouse.h"
#include "Keyboard.h"

//*****************************************************************************
// �N���X��`
//*****************************************************************************
class Input
{
public:
	Input();
	~Input();

	HRESULT Init(HINSTANCE hInst, HWND hWnd);
	void Update();

private:
	LPDIRECTINPUT8 pDInput;					// IDirectInput8�C���^�[�t�F�[�X�ւ̃|�C���^
	GamePad *pad;
	Keyboard *keyboard;
	Mouse *mouse;

	static Input* mInstance;
};
//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************

#endif