//=====================================
//
//�}�E�X����[Mouse.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "Mouse.h"

/**************************************
�}�N����`
***************************************/

/**************************************
�O���[�o���ϐ�
***************************************/
Mouse* Mouse::mInstance = NULL;

/**************************************
�R���X�g���N�^
***************************************/
Mouse::Mouse()
{
	if (mInstance == NULL)
	{
		mInstance = this;
	}
}

/**************************************
����������
***************************************/
HRESULT Mouse::Init(HINSTANCE hInst, HWND hWindow, LPDIRECTINPUT8 inputInterface)
{
	HRESULT result;
	// �f�o�C�X�쐬
	result = inputInterface->CreateDevice(GUID_SysMouse, &pMouse, NULL);
	if (FAILED(result) || pMouse == NULL)
	{
		MessageBox(hWindow, "No mouse", "Warning", MB_OK | MB_ICONWARNING);
		return result;
	}
	// �f�[�^�t�H�[�}�b�g�ݒ�
	result = pMouse->SetDataFormat(&c_dfDIMouse2);
	if (FAILED(result))
	{
		MessageBox(hWindow, "Can't setup mouse", "Warning", MB_OK | MB_ICONWARNING);
		return result;
	}
	// ���̃A�v���Ƌ������[�h�ɐݒ�
	result = pMouse->SetCooperativeLevel(hWindow, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE));
	if (FAILED(result))
	{
		MessageBox(hWindow, "Mouse mode error", "Warning", MB_OK | MB_ICONWARNING);
		return result;
	}

	// �f�o�C�X�̐ݒ�
	DIPROPDWORD prop;

	prop.diph.dwSize = sizeof(prop);
	prop.diph.dwHeaderSize = sizeof(prop.diph);
	prop.diph.dwObj = 0;
	prop.diph.dwHow = DIPH_DEVICE;
	prop.dwData = DIPROPAXISMODE_REL;		// �}�E�X�̈ړ��l�@���Βl

	result = pMouse->SetProperty(DIPROP_AXISMODE, &prop.diph);
	if (FAILED(result))
	{
		MessageBox(hWindow, "Mouse property error", "Warning", MB_OK | MB_ICONWARNING);
		return result;
	}

	// �A�N�Z�X���𓾂�
	pMouse->Acquire();
	return result;
}

/**************************************
�I������
***************************************/
Mouse::~Mouse()
{
	if (pMouse)
	{
		pMouse->Unacquire();
		pMouse->Release();
		pMouse = NULL;
	}

	if (mInstance == this)
	{
		mInstance = NULL;
	}
}

/**************************************
�X�V����
***************************************/
HRESULT Mouse::Update()
{
	HRESULT result;
	// �O��̒l�ۑ�
	DIMOUSESTATE2 lastMouseState = mouseState;
	// �f�[�^�擾
	result = pMouse->GetDeviceState(sizeof(mouseState), &mouseState);
	if (SUCCEEDED(result))
	{
		mouseTrigger.lX = mouseState.lX;
		mouseTrigger.lY = mouseState.lY;
		mouseTrigger.lZ = mouseState.lZ;
		// �}�E�X�̃{�^�����
		for (int i = 0; i<8; i++)
		{
			mouseTrigger.rgbButtons[i] = ((lastMouseState.rgbButtons[i] ^
				mouseState.rgbButtons[i]) & mouseState.rgbButtons[i]);
		}
	}
	else	// �擾���s
	{
		// �A�N�Z�X���𓾂Ă݂�
		result = pMouse->Acquire();
	}

	return result;

}

/**************************************
�}�E�X���W�擾����
***************************************/
D3DXVECTOR3 Mouse::GetMousePosition(HWND hWnd)
{
	POINT position;
	
	if (GetCursorPos(&position))
	{
		ScreenToClient(hWnd, &position);

		if (position.x < 0)
		{
			position.x = 0;
		}
		else if (position.x > SCREEN_WIDTH)
		{
			position.x = SCREEN_WIDTH;
		}

		if (position.y < 0)
		{
			position.y = 0;
		}
		else if (position.y > SCREEN_HEIGHT)
		{
			position.y = SCREEN_HEIGHT;
		}

		return D3DXVECTOR3((float)position.x, (float)position.y, 0.0f);
	}
	else
	{
		return D3DXVECTOR3(0, 0, 0);
	}
}

/**************************************
�}�E�X���͌��o����
***************************************/
BOOL Mouse::GetPressLeft(void)
{
	return (BOOL)(mInstance->mouseState.rgbButtons[0] & 0x80);	// �����ꂽ�Ƃ��ɗ��r�b�g������
}
BOOL Mouse::GetTriggerLeft(void)
{
	return (BOOL)(mInstance->mouseTrigger.rgbButtons[0] & 0x80);
}
BOOL Mouse::GetPressRight(void)
{
	return (BOOL)(mInstance->mouseState.rgbButtons[1] & 0x80);
}
BOOL Mouse::GetTriggerRight(void)
{
	return (BOOL)(mInstance->mouseTrigger.rgbButtons[1] & 0x80);
}
BOOL Mouse::GetPressCenter(void)
{
	return (BOOL)(mInstance->mouseState.rgbButtons[2] & 0x80);
}
BOOL Mouse::GetTriggerCenter(void)
{
	return (BOOL)(mInstance->mouseTrigger.rgbButtons[2] & 0x80);
}

/**************************************
�}�E�X���W�擾����
***************************************/
float Mouse::GetX(void)
{
	return float(mInstance->mouseState.lX);
}
float Mouse::GetY(void)
{
	return float(mInstance->mouseState.lY);
}
float Mouse::GetZ(void)
{
	return float(mInstance->mouseState.lZ);
}
