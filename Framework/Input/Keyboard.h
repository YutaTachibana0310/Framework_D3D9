//=====================================
//
//�L�[�{�[�h�w�b�_[Keyboard.h]
//Author:GP12B332 21 ���ԗY��
//
//=====================================
#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_

#include "../../main.h"

/**************************************
�}�N����`
***************************************/
#define	NUM_KEY_MAX		(256)			// �L�[�ő吔

/**************************************
�N���X��`
***************************************/
class Keyboard
{
public:
	Keyboard();
	~Keyboard();

	HRESULT Init(HINSTANCE hInst, HWND hWnd, LPDIRECTINPUT8 pInput);
	void Update();

	static bool GetKeyboardPress(int nKey);
	static bool GetKeyboardTrigger(int nKey);
	static bool GetKeyboardRepeat(int nKey);
	static bool GetKeyboardRelease(int nKey);

private:
	LPDIRECTINPUTDEVICE8 m_pDIDevKeyboard = NULL;			// IDirectInputDevice8�C���^�[�t�F�[�X�ւ̃|�C���^(�L�[�{�[�h)
	BYTE	m_aKeyState[NUM_KEY_MAX];			// �L�[�{�[�h�̉�����Ԃ�ێ����郏�[�N
	BYTE	m_aKeyStateTrigger[NUM_KEY_MAX];	// �L�[�{�[�h�̃g���K�[��Ԃ�ێ����郏�[�N
	BYTE	m_aKeyStateRelease[NUM_KEY_MAX];	// �L�[�{�[�h�̃����[�X��Ԃ�ێ����郏�[�N
	BYTE	m_aKeyStateRepeat[NUM_KEY_MAX];		// �L�[�{�[�h�̃��s�[�g��Ԃ�ێ����郏�[�N
	int		m_aKeyStateRepeatCnt[NUM_KEY_MAX];	// �L�[�{�[�h�̃��s�[�g�J�E���^

	static Keyboard* mInstance;
};

#endif	