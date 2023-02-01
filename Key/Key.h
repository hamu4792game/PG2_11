#pragma once
#include <Novice.h>

class Key
{
private:

	// �L�[���͌��ʂ��󂯎�锠
	//	�v���g�^�C�v�錾�Ɠ���
	static char keys[256];
	static char preKeys[256];

public:

	// �L�[���͂��󂯎��
	static void Input()
	{
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);
	}

	//	�L�[�������ꂽ��
	static bool IsTrigger(char keycord)
	{
		return preKeys[keycord] == 0 && keys[keycord] != 0;
	}

	//	�L�[��������Ă��鎞
	static bool IsPressed(char keycord)
	{
		return keys[keycord] != 0;
	}

};