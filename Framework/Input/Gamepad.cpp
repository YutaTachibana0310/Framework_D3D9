//=====================================
//
//�Q�[���p�b�h����[Gamepad.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "Gamepad.h"

/**************************************
�}�N����`
***************************************/
#define DEADZONE		5000			// �e����25%�𖳌��]�[���Ƃ���
#define RANGE_MAX		1000			// �L���͈͂̍ő�l
#define RANGE_MIN		-1000			// �L���͈͂̍ŏ��l

#define INPUT_SHORTWAIT (6)

GamePad* GamePad::mInstance = NULL;
LPDIRECTINPUTDEVICE8	pGamePad[GAMEPADMAX] = { NULL,NULL,NULL,NULL };// �p�b�h�f�o�C�X
int		padCount;			// ���o�����p�b�h�̐�

/*************************************
�R���X�g���N�^
***************************************/
GamePad::GamePad()
{
	if (mInstance == NULL)
	{
		mInstance = this;
	}
}

/**************************************
�p�b�h�����R�[���o�b�N
***************************************/
BOOL CALLBACK SearchPadCallback(LPDIDEVICEINSTANCE lpddi, LPVOID, LPDIRECTINPUT8 inputInterface)
{
	HRESULT result;

	result = inputInterface->CreateDevice(lpddi->guidInstance, &pGamePad[padCount++], NULL);
	return DIENUM_CONTINUE;	// ���̃f�o�C�X���

}

/**************************************
����������
***************************************/
HRESULT GamePad::Init(LPDIRECTINPUT8 inputInterface)			// �p�b�h������
{
	HRESULT		result;
	int			i;

	padCount = 0;
	// �W���C�p�b�h��T��
	inputInterface->EnumDevices(DI8DEVCLASS_GAMECTRL, (LPDIENUMDEVICESCALLBACK)SearchPadCallback, NULL, DIEDFL_ATTACHEDONLY);
	// �Z�b�g�����R�[���o�b�N�֐����A�p�b�h�𔭌������������Ă΂��B

	for (i = 0; i < padCount; i++) {
		// �W���C�X�e�B�b�N�p�̃f�[�^�E�t�H�[�}�b�g��ݒ�
		result = pGamePad[i]->SetDataFormat(&c_dfDIJoystick);
		if (FAILED(result))
			return false; // �f�[�^�t�H�[�}�b�g�̐ݒ�Ɏ��s

	  // ���[�h��ݒ�i�t�H�A�O���E���h����r�����[�h�j
	  //		result = pGamePad[i]->SetCooperativeLevel(hWindow, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	  //		if ( FAILED(result) )
	  //			return false; // ���[�h�̐ݒ�Ɏ��s

	  // ���̒l�͈̔͂�ݒ�
	  // X���AY���̂��ꂼ��ɂ��āA�I�u�W�F�N�g���񍐉\�Ȓl�͈̔͂��Z�b�g����B
	  // (max-min)�́A�ő�10,000(?)�B(max-min)/2�������l�ɂȂ�B
	  // ����傫������΁A�A�i���O�l�ׂ̍��ȓ�����߂炦����B(�p�b�h�̐��\�ɂ��)
		DIPROPRANGE				diprg;
		ZeroMemory(&diprg, sizeof(diprg));
		diprg.diph.dwSize = sizeof(diprg);
		diprg.diph.dwHeaderSize = sizeof(diprg.diph);
		diprg.diph.dwHow = DIPH_BYOFFSET;
		diprg.lMin = RANGE_MIN;
		diprg.lMax = RANGE_MAX;
		// X���͈̔͂�ݒ�
		diprg.diph.dwObj = DIJOFS_X;
		pGamePad[i]->SetProperty(DIPROP_RANGE, &diprg.diph);
		// Y���͈̔͂�ݒ�
		diprg.diph.dwObj = DIJOFS_Y;
		pGamePad[i]->SetProperty(DIPROP_RANGE, &diprg.diph);

		// �e�����ƂɁA�����̃]�[���l��ݒ肷��B
		// �����]�[���Ƃ́A��������̔����ȃW���C�X�e�B�b�N�̓����𖳎�����͈͂̂��ƁB
		// �w�肷��l�́A10000�ɑ΂��鑊�Βl(2000�Ȃ�20�p�[�Z���g)�B
		DIPROPDWORD				dipdw;
		dipdw.diph.dwSize = sizeof(DIPROPDWORD);
		dipdw.diph.dwHeaderSize = sizeof(dipdw.diph);
		dipdw.diph.dwHow = DIPH_BYOFFSET;
		dipdw.dwData = DEADZONE;
		//X���̖����]�[����ݒ�
		dipdw.diph.dwObj = DIJOFS_X;
		pGamePad[i]->SetProperty(DIPROP_DEADZONE, &dipdw.diph);
		//Y���̖����]�[����ݒ�
		dipdw.diph.dwObj = DIJOFS_Y;
		pGamePad[i]->SetProperty(DIPROP_DEADZONE, &dipdw.diph);

		//�W���C�X�e�B�b�N���͐���J�n
		pGamePad[i]->Acquire();
	}

	return true;

}

/**************************************
�I������
***************************************/
GamePad::~GamePad()
{
	for (int i = 0; i < GAMEPADMAX; i++) {
		if (pGamePad[i])
		{
			pGamePad[i]->Unacquire();
			pGamePad[i]->Release();
		}
	}

	if (mInstance == this)
	{
		mInstance = NULL;
	}
}

/**************************************
�X�V����
***************************************/
void GamePad::Update(void)
{
	HRESULT			result;
	DIJOYSTATE2		dijs;
	int				i;

	for (i = 0; i < padCount; i++)
	{
		DWORD lastPadState;
		lastPadState = padState[i];
		padState[i] = 0x00000000l;	// ������

		result = pGamePad[i]->Poll();	// �W���C�X�e�B�b�N�Ƀ|�[����������
		if (FAILED(result)) {
			result = pGamePad[i]->Acquire();
			while (result == DIERR_INPUTLOST)
				result = pGamePad[i]->Acquire();
		}

		result = pGamePad[i]->GetDeviceState(sizeof(DIJOYSTATE), &dijs);	// �f�o�C�X��Ԃ�ǂݎ��
		if (result == DIERR_INPUTLOST || result == DIERR_NOTACQUIRED) {
			result = pGamePad[i]->Acquire();
			while (result == DIERR_INPUTLOST)
				result = pGamePad[i]->Acquire();
		}

		if (dijs.lZ != 0 && dijs.lRx != 0)
		{
			padAxislRx[i] = (float)(dijs.lRx);
			padAxislRy[i] = (float)(dijs.lRy);

		}
		else
		{
			padAxislRx[i] = (float)(dijs.lZ + dijs.lRx);
			padAxislRy[i] = (float)(dijs.lRz + dijs.lRy);

		}

		// �R�Q�̊e�r�b�g�ɈӖ����������A�{�^�������ɉ����ăr�b�g���I���ɂ���
		//* y-axis (forward)
		if (dijs.lY < 0)					padState[i] |= BUTTON_UP;
		//* y-axis (backward)
		if (dijs.lY > 0)					padState[i] |= BUTTON_DOWN;
		//* x-axis (left)
		if (dijs.lX < 0)					padState[i] |= BUTTON_LEFT;
		//* x-axis (right)
		if (dijs.lX > 0)					padState[i] |= BUTTON_RIGHT;
		//* �`�{�^��
		if (dijs.rgbButtons[0] & 0x80)	padState[i] |= BUTTON_A;
		//* �a�{�^��
		if (dijs.rgbButtons[1] & 0x80)	padState[i] |= BUTTON_B;
		//* �b�{�^��
		if (dijs.rgbButtons[2] & 0x80)	padState[i] |= BUTTON_C;
		//* �w�{�^��
		if (dijs.rgbButtons[3] & 0x80)	padState[i] |= BUTTON_X;
		//* �x�{�^��
		if (dijs.rgbButtons[4] & 0x80)	padState[i] |= BUTTON_Y;
		//* �y�{�^��
		if (dijs.rgbButtons[5] & 0x80)	padState[i] |= BUTTON_Z;
		//* �k�{�^��
		if (dijs.rgbButtons[6] & 0x80)	padState[i] |= BUTTON_L;
		//* �q�{�^��
		if (dijs.rgbButtons[7] & 0x80)	padState[i] |= BUTTON_R;
		//* �r�s�`�q�s�{�^��
		if (dijs.rgbButtons[8] & 0x80)	padState[i] |= BUTTON_START;
		//* �l�{�^��
		if (dijs.rgbButtons[9] & 0x80)	padState[i] |= BUTTON_M;

		// Trigger�ݒ�
		padTrigger[i] = ((lastPadState ^ padState[i])	// �O��ƈ���Ă���
			& padState[i]);					// ��������ON�̂��

											// Release�ݒ�
		padRelease[i] = ((lastPadState ^ padState[i]))	//�O��ƈ���Ă���
			& (~padState[i]);				//��OFF�̂��

											//�X�e�B�b�N��Repeat���菈��
		padAxisYRepeat[i] = GetTriggerY(i);

		if (BUTTON_UP & padState[i])
		{
			axisYRepeatCnt[i]++;
			if (axisYRepeatCnt[i] >= 20 && axisYRepeatCnt[i] % INPUT_SHORTWAIT == 0)
			{
				padAxisYRepeat[i] = 1;
			}
		}
		else if (BUTTON_DOWN & padState[i])
		{
			axisYRepeatCnt[i]++;
			if (axisYRepeatCnt[i] >= 20 && axisYRepeatCnt[i] % INPUT_SHORTWAIT == 0)
			{
				padAxisYRepeat[i] = -1;
			}
		}
		else
		{
			axisYRepeatCnt[i] = 0;
			padAxisYRepeat[i] = 0;
		}

		padAxisXRepeat[i] = GetTriggerX(i);

		if (BUTTON_RIGHT & padState[i])
		{
			axisXRepeatCnt[i]++;
			if (axisXRepeatCnt[i] >= 20 && axisXRepeatCnt[i] % INPUT_SHORTWAIT == 0)
			{
				padAxisXRepeat[i] = 1;
			}
		}
		else if (BUTTON_LEFT & padState[i])
		{
			axisXRepeatCnt[i]++;
			if (axisXRepeatCnt[i] >= 20 && axisXRepeatCnt[i] % INPUT_SHORTWAIT == 0)
			{
				padAxisXRepeat[i] = -1;
			}
		}
		else
		{
			axisXRepeatCnt[i] = 0;
			padAxisXRepeat[i] = 0;
		}

	}

}

/**************************************
�v���X���o����
***************************************/
BOOL GamePad::GetPress(int padNo, DWORD button)
{
	return (button & mInstance->padState[padNo]);
}

/**************************************
�g���K�[���o����
***************************************/
BOOL GamePad::GetTrigger(int padNo, DWORD button)
{
	return (button & mInstance->padTrigger[padNo]);
}

/**************************************
�����[�X���o����
***************************************/
BOOL GamePad::GetRelease(int padNo, DWORD button)
{
	return (button & mInstance->padRelease[padNo]);
}

/**************************************
X���g���K�[���o����
***************************************/
int GamePad::GetTriggerX(int padNo)
{
	if (GetTrigger(padNo, BUTTON_RIGHT))
		return 1;

	else if (GetTrigger(padNo, BUTTON_LEFT))
		return -1;

	else
		return 0;
}

/**************************************
Y���g���K�[���o����
***************************************/
int GamePad::GetTriggerY(int padNo)
{
	if (GetTrigger(padNo, BUTTON_UP))
		return 1;

	else if (GetTrigger(padNo, BUTTON_DOWN))
		return -1;

	else
		return 0;
}

/**************************************
�p�b�h����Ԃ�����
***************************************/
int GamePad::GetPadCount(void)
{
	return mInstance->padCount;
}

/**************************************
�E�X�e�B�b�NX�����͌v�Z����
***************************************/
float GamePad::GetRightStickX(int padNo)
{
	if (padNo >= mInstance->padCount)
	{
		return 0.0f;
	}

	return (mInstance->padAxislRx[padNo] / 65535.0f) - 0.5f;
}


/**************************************
�E�X�e�B�b�NY�����͌v�Z����
***************************************/
float GamePad::GetRightStickY(int padNo)
{
	if (padNo >= mInstance->padCount)
	{
		return 0.0f;
	}


	return (mInstance->padAxislRy[padNo] / 65535.0f) - 0.5f;
}


