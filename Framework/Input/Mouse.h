//=====================================
//
//マウスヘッダ[Mouse.h]
//Author:GP12B332 21 立花雄太
//
//=====================================
#ifndef _MOUSE_H_
#define _MOUSE_H_

#include "../../main.h"

/**************************************
マクロ定義
***************************************/

/**************************************
クラス定義
***************************************/
class Mouse
{
public:
	Mouse();
	~Mouse();

	HRESULT Init(HINSTANCE hInst, HWND hWnd, LPDIRECTINPUT8 pInput);
	HRESULT Update();

	static BOOL IsMouseLeftPressed(void);      // 左クリックした状態
	static BOOL IsMouseLeftTriggered(void);    // 左クリックした瞬間
	static BOOL IsMouseRightPressed(void);     // 右クリックした状態
	static BOOL IsMouseRightTriggered(void);   // 右クリックした瞬間
	static BOOL IsMouseCenterPressed(void);    // 中クリックした状態
	static BOOL IsMouseCenterTriggered(void);  // 中クリックした瞬間
	static float GetMouseX(void);               // マウスがX方向に動いた相対値
	static float GetMouseY(void);               // マウスがY方向に動いた相対値
	static float GetMouseZ(void);               // マウスホイールが動いた相対値

	static D3DXVECTOR3 GetMousePosition(HWND hWnd);

private:
	static Mouse* mInstance;
	LPDIRECTINPUTDEVICE8 pMouse = NULL; // mouse

	DIMOUSESTATE2   mouseState;		// マウスのダイレクトな状態
	DIMOUSESTATE2   mouseTrigger;	// 押された瞬間だけON
};
/**************************************
プロトタイプ宣言
***************************************/


#endif