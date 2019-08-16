//=====================================
//
//�}�E�X�w�b�_[Mouse.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _MOUSE_H_
#define _MOUSE_H_

#include "../../main.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�N���X��`
***************************************/
class Mouse
{
public:
	Mouse();
	~Mouse();

	HRESULT Init(HINSTANCE hInst, HWND hWnd, LPDIRECTINPUT8 pInput);
	HRESULT Update();

	static BOOL GetPressLeft(void);      // ���N���b�N�������
	static BOOL GetTriggerLeft(void);    // ���N���b�N�����u��
	static BOOL GetPressRight(void);     // �E�N���b�N�������
	static BOOL GetTriggerRight(void);   // �E�N���b�N�����u��
	static BOOL GetPressCenter(void);    // ���N���b�N�������
	static BOOL GetTriggerCenter(void);  // ���N���b�N�����u��
	static float GetX(void);               // �}�E�X��X�����ɓ��������Βl
	static float GetY(void);               // �}�E�X��Y�����ɓ��������Βl
	static float GetZ(void);               // �}�E�X�z�C�[�������������Βl

	static D3DXVECTOR3 GetMousePosition(HWND hWnd);

private:
	static Mouse* mInstance ;
	LPDIRECTINPUTDEVICE8 pMouse = NULL; // mouse

	DIMOUSESTATE2   mouseState;		// �}�E�X�̃_�C���N�g�ȏ��
	DIMOUSESTATE2   mouseTrigger;	// �����ꂽ�u�Ԃ���ON
};
/**************************************
�v���g�^�C�v�錾
***************************************/


#endif