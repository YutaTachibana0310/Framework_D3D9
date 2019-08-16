//=====================================
//
//�L�[�{�[�h����[Keyboard.cpp]
//Author:GP12A332 21 ���ԗY��
//
//=====================================
#include "Keyboard.h"

//=============================================================================
// static�����o
//=============================================================================
Keyboard* Keyboard::mInstance = NULL;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
Keyboard::Keyboard()
{
	if (mInstance == NULL)
	{
		mInstance = this;
	}
}

//=============================================================================
// �L�[�{�[�h�̏���������
//=============================================================================
HRESULT Keyboard::Init(HINSTANCE hInst, HWND hWnd, LPDIRECTINPUT8 inputInterface)
{
	HRESULT hr;

	// �f�o�C�X�I�u�W�F�N�g���쐬
	hr = inputInterface->CreateDevice(GUID_SysKeyboard, &m_pDIDevKeyboard, NULL);
	if (FAILED(hr) || m_pDIDevKeyboard == NULL)
	{
		MessageBox(hWnd, "�L�[�{�[�h���˂��I", "�x���I", MB_ICONWARNING);
		return hr;
	}

	// �f�[�^�t�H�[�}�b�g��ݒ�
	hr = m_pDIDevKeyboard->SetDataFormat(&c_dfDIKeyboard);
	if (FAILED(hr))
	{
		MessageBox(hWnd, "�L�[�{�[�h�̃f�[�^�t�H�[�}�b�g��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
		return hr;
	}

	// �������[�h��ݒ�i�t�H�A�O���E���h����r�����[�h�j
	hr = m_pDIDevKeyboard->SetCooperativeLevel(hWnd, (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE));
	if (FAILED(hr))
	{
		MessageBox(hWnd, "�L�[�{�[�h�̋������[�h��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
		return hr;
	}

	// �L�[�{�[�h�ւ̃A�N�Z�X�����l��(���͐���J�n)
	m_pDIDevKeyboard->Acquire();

	return S_OK;
}

//=============================================================================
// �L�[�{�[�h�̏I������
//=============================================================================
Keyboard::~Keyboard()
{
	if (m_pDIDevKeyboard)
	{// �f�o�C�X�I�u�W�F�N�g�̊J��
		m_pDIDevKeyboard->Release();
		m_pDIDevKeyboard = NULL;
	}

	if (mInstance == this)
	{
		mInstance = NULL;
	}
}

//=============================================================================
// �L�[�{�[�h�̍X�V����
//=============================================================================
void Keyboard::Update(void)
{
	HRESULT hr;
	BYTE aKeyState[NUM_KEY_MAX];

	// �f�o�C�X����f�[�^���擾
	hr = m_pDIDevKeyboard->GetDeviceState(sizeof(aKeyState), aKeyState);
	if (SUCCEEDED(hr))
	{
		for (int nCntKey = 0; nCntKey < NUM_KEY_MAX; nCntKey++)
		{
			m_aKeyStateTrigger[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & aKeyState[nCntKey];
			m_aKeyStateRelease[nCntKey] = (m_aKeyState[nCntKey] ^ aKeyState[nCntKey]) & ~aKeyState[nCntKey];
			m_aKeyStateRepeat[nCntKey] = m_aKeyStateTrigger[nCntKey];

			if (aKeyState[nCntKey])
			{
				m_aKeyStateRepeatCnt[nCntKey]++;
				if (m_aKeyStateRepeatCnt[nCntKey] >= 20 && m_aKeyStateRepeatCnt[nCntKey] % 5 == 0)
				{
					m_aKeyStateRepeat[nCntKey] = aKeyState[nCntKey];
				}
				//else
				//{
				//	m_aKeyStateRepeat[nCntKey] = 0;
				//}
			}
			else
			{
				m_aKeyStateRepeatCnt[nCntKey] = 0;
				m_aKeyStateRepeat[nCntKey] = 0;
			}

			m_aKeyState[nCntKey] = aKeyState[nCntKey];
		}
	}
	else
	{
		// �L�[�{�[�h�ւ̃A�N�Z�X�����擾
		m_pDIDevKeyboard->Acquire();
	}

	return;
}

//=============================================================================
// �L�[�{�[�h�̃v���X��Ԃ��擾
//=============================================================================
bool Keyboard::GetKeyboardPress(int nKey)
{
	return (mInstance->m_aKeyState[nKey] & 0x80) ? true : false;
}

//=============================================================================
// �L�[�{�[�h�̃g���K�[��Ԃ��擾
//=============================================================================
bool Keyboard::GetKeyboardTrigger(int nKey)
{
	return (mInstance->m_aKeyStateTrigger[nKey] & 0x80) ? true : false;
}

//=============================================================================
// �L�[�{�[�h�̃��s�[�g��Ԃ��擾
//=============================================================================
bool Keyboard::GetKeyboardRepeat(int nKey)
{
	return (mInstance->m_aKeyStateRepeat[nKey] & 0x80) ? true : false;
}

//=============================================================================
// �L�[�{�[�h�̃����|�X��Ԃ��擾
//=============================================================================
bool Keyboard::GetKeyboardRelease(int nKey)
{
	return (mInstance->m_aKeyStateRelease[nKey] & 0x80) ? true : false;
}