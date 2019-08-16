//=============================================================================
//
// 入力処理 [input.h]
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
// クラス定義
//*****************************************************************************
class Input
{
public:
	Input();
	~Input();

	HRESULT Init(HINSTANCE hInst, HWND hWnd);
	void Update();

private:
	LPDIRECTINPUT8 pDInput;					// IDirectInput8インターフェースへのポインタ
	GamePad *pad;
	Keyboard *keyboard;
	Mouse *mouse;

	static Input* mInstance;
};
//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************

#endif