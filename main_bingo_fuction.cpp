#include <iostream>

using namespace std;


enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};
enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};


// �Լ��� ����� ���� �κ����� ���� �� ����
void SetNumber(int* parray);
void Shuffle(int* parray);
void OutputNumber(int* parray, int ibingo);
AI_MODE SelectAIMode();
bool ChangeNumber(int* parray, int iInput);
int SeletAINumber(int* parray, AI_MODE emode);
int BingoCounting(int* parray);
int BingoCountingH(int* parray);
int BingoCountingV(int* parray);
int BingoCountingLTD(int* parray);
int BingoCountingRTD(int* parray);

int main()
{
	srand((unsigned int)time(0));
	int iArray[25] = {};
	int iAIArray[25] = {};

	//���� ����
	SetNumber(iArray);
	SetNumber(iAIArray);

	//����
	Shuffle(iArray);
	Shuffle(iAIArray);

	int iBingo = 0, iAIBingo = 0;

	//AI ���̵� ����
	AI_MODE iAIMode = SelectAIMode();

	while (true)
	{
		system("cls");

		//���ڸ� 5x5�� ����Ѵ�.
		cout << "================== Player ==================" << endl;
		OutputNumber(iArray, iBingo);

		cout << "================== AI ==================" << endl;
		cout << "AI ���̵� : ";
		switch (iAIMode)
		{
		case AM_EASY:
			cout << "Easy" << endl;
			break;
		case AM_HARD:
			cout << "Hard" << endl;
			break;
		}
		OutputNumber(iAIArray, iAIBingo);


		//�ټ��� 2�̻��� ��� ��������� üũ�Ѵ�.
		if (iBingo >= 2)
		{
			cout << "Player �¸�" << endl;
			break;
		}
		else if (iAIBingo >= 2)
		{
			cout << "AI �¸�" << endl;
			break;
		}

		cout << "���ڸ� �Է��ϼ���(0 : ����) : ";
		int iInput;
		cin >> iInput;

		//����
		if (iInput == 0)
		{
			break;
		}
		//1~25 ������ ���ڰ� �ƴ� ���
		else if (iInput < 1 || iInput > 25)
		{
			cout << "�߸��� �����Դϴ�." << endl;
			continue;
		}

		//�ߺ� �Է� üũ�ϱ� ���� ����
		bool bAcc = ChangeNumber(iArray, iInput);

		//bAcc�� true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ����*�� ������ �������Ƿ�
		//�ٽ� �Է¹ޱ� ���� continue�� �Ѵ�.
		if (bAcc)
		{
			continue;
		}

		//�ߺ��� �ƴ϶�� AI�� ���ڸ� �ϳ� �����ؼ� *�� �����.
		bAcc = ChangeNumber(iAIArray, iInput);


		//AI�� ���ڸ� �����Ѵ�. AI��忡 ���缭 �����Ѵ�.
		iInput = SeletAINumber(iAIArray, iAIMode);

		//AI�� ������ ���ڸ� AI�迭�� �÷��̾�� *�� ������ش�.
		ChangeNumber(iArray, iInput);
		ChangeNumber(iAIArray, iInput);

		//���� �� �� üũ�ϴ� ���� �Ź� ���ڸ� �Է��Ҷ����� ó������ ���� ī��Ʈ�� �� ���̴�
		//�׷��Ƿ� iBingo�� 0���� �ʱ�ȭ �Ѵ�.
		iBingo = BingoCounting(iArray);
		iAIBingo = BingoCounting(iAIArray);
	}
	return 0;
}

// �Լ��� ���� �κ�
void SetNumber(int* parray)
{
	// �迭�� �ּҸ� �޾Ƽ� ���� ����
	for (int i = 0; i < 25; ++i)
	{
		parray[i] = i + 1;
	}
}

void Shuffle(int* iArray)
{
	//����
	int iTemp = 0, idx1 = 0, idx2 = 0;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = iArray[idx1];
		iArray[idx1] = iArray[idx2];
		iArray[idx2] = iTemp;
	}
}

AI_MODE SelectAIMode()
{
	int iAIMode = 0;

	while (true)
	{
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI ���̵��� �����ϼ��� : ";
		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD)
		{
			break;
		}
	}

	return (AI_MODE)iAIMode;
}

void OutputNumber(int* parray, int ibingo)
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (parray[i * 5 + j] == INT_MAX)
			{
				cout << "*\t";
			}
			else
			{
				cout << parray[i * 5 + j] << "\t";
			}
		}
		cout << endl;
	}

	cout << "Bingo Line : " << ibingo << endl << endl;
}

bool ChangeNumber(int* parray, int iInput)
{
	//��� ���ڸ� ���ʴ�� �˻��� �Է��� ���ڿ� ���� ���ڰ� �ִ��� ã�Ƴ���
	for (int i = 0; i < 25; ++i)
	{
		//���� ���ڰ� ���� ��� 
		if (iInput == parray[i])
		{
			//���ڸ� *�� ����� ���� Ư���� ���� INT_MAX�� ����
			parray[i] = INT_MAX;

			//���̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 �����Ƿ� for���� ����������.
			return false;
		}
	}

	//�ߺ��� ���ڸ� �Է��߱� ������ true�� return
	return true;
}

int SeletAINumber(int* pArray, AI_MODE iAIMode)
{
	//���þȵ� ��� �迭�� ������ش�
	int iNoneSelect[25] = {};
	int iNoneSelCnt = 0;

	//AI�� ������ �� �ִ� ��Ͽ��� ���ڸ� �����Ѵ�.
	switch (iAIMode)
	{
		/*
		AI Easy ���
		- �������� ���ڸ� �̾Ƽ� *�� �����.
		*/
	case AM_EASY:
		//���� �ȵ� ���� ������ ����� ���鶧 ī��Ʈ�Ѵ�.
		iNoneSelCnt = 0;

		//���� �ȵ� ���� ��� ������ش�
		for (int i = 0; i < 25; ++i)
		{
			//���� ���ڰ� *�� �ƴ� ���
			if (pArray[i] != INT_MAX)
			{
				//*�� �ƴ� ������ ��� iNoneSelect�� �ε����� Ȱ��
				//���� �ȵ� ��Ͽ� �߰�
				iNoneSelect[iNoneSelCnt] = pArray[i];
				++iNoneSelCnt;
			}
		}

		//for���� ���� ������ �Ǹ� ���þȵ� ����� ���������
		//���þȵ� ����� ������ ���������.
		//�׷��Ƿ� 0~iNoneSelCnt-1������ ���ڸ� �������� �̾Ƽ�
		//�� ���ڸ� *�� ������ָ� �ȴ�.
		return iNoneSelect[rand() % iNoneSelCnt];
	case AM_HARD:
		// �ϵ���� ���� ������ ������ �ϼ� ���ɼ��� ���� ���� ���� ã��, �� �ٿ� �ִ� ������ �ϳ��� *�� �����.
		int iLine = 0;
		int iStarCount = 0;
		int iSaveCount = 0;

		//���� ���� �߿� ���� *�� ���� ������ ã�Ƴ���.
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				//������ üũ
				if (pArray[i * 5 + j] == INT_MAX)
				{
					++iStarCount;
				}
			}

			//���� 5������ �̸��̿��� ���� �ƴ� && ���ο� ������ ã���� ��
			//�� ������ �� ������ �����ϰ� �� ������ �����Ѵ�.
			//�̷��� �ϸ� ���� ���� ���� ������ ã�� �� �ִ�.
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				//���� ������ ���� ���� ���� ������ üũ
				//���� ������ 0~4�� �ǹ̸� �ο�
				iLine = i;
				iSaveCount = iStarCount;
			}
		}
		//���� ���� �� ����	���� ���� ������ ã�Ҵ�.
		//�� ���� ������ ���� ���ε�� ���Ͽ� ���� ���� ���� ������ ã�Ƴ���.
		for (int i = 0; i < 5; ++i)
		{
			iStarCount = 0;
			for (int j = 0; j < 5; ++j)
			{
				if (pArray[j * 5 + i] == INT_MAX)
				{
					++iStarCount;
				}
			}

			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				//���� ������ ���� ���� ���� ������ üũ
				//���� ������ 5~9�� �ǹ̸� �ο�
				iLine = i + 5;
				iSaveCount = iStarCount;
			}
		}

		//���� -> ������ �밢�� üũ
		iStarCount = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (pArray[i] == INT_MAX)
			{
				++iStarCount;
			}
		}
		if (iStarCount < 5 && iSaveCount < iStarCount)
		{
			//���� -> ������ �밢�� üũ
			//�밢���� 10������ �ǹ̸� �ο�
			iLine = LN_LT;
			iSaveCount = iStarCount;
		}

		//������ -> ���� �밢�� üũ
		iStarCount = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (pArray[i] == INT_MAX)
			{
				++iStarCount;
			}
		}
		if (iStarCount < 5 && iSaveCount < iStarCount)
		{
			//������ -> ���� �밢�� üũ
			//�밢���� 11������ �ǹ̸� �ο�
			iLine = LN_RT;
			iSaveCount = iStarCount;
		}

		//��� ������ ���������� iLine���� ���� ���� ���� ������ ����Ǿ� �ִ�.
		//�� ���ο� �ִ� *�� �ƴ� ������ �ϳ��� �����Ѵ�.
		//�������� ���
		if (iLine <= LN_H5)
		{
			for (int i = 0; i < 5; ++i)
			{
				if (pArray[iLine * 5 + i] != INT_MAX)
				{
					return pArray[iLine * 5 + i];
				}
			}
		}
		//�������� ���
		else if (iLine <= LN_V5)
		{
			for (int i = 0; i < 5; ++i)
			{
				if (pArray[i * 5 + (iLine - 5)] != INT_MAX)
				{
					return  pArray[i * 5 + (iLine - 5)];
				}
			}
		}
		//���� -> ������ �밢��
		else if (iLine == LN_LT)
		{
			for (int i = 0; i < 25; i += 6)
			{
				if (pArray[i] != INT_MAX)
				{
					return pArray[i];
				}
			}
		}
		//������ -> ���� �밢��
		else if (iLine == LN_RT)
		{
			for (int i = 4; i <= 20; i += 4)
			{
				if (pArray[i] != INT_MAX)
				{
					return pArray[i];
				}
			}
		}
		break;
	}

	return -1;
}

int BingoCounting(int* parray)
{
	int iBingo = 0;

	//������ üũ
	iBingo += BingoCountingH(parray);
	//������ üũ
	iBingo += BingoCountingV(parray);
	//���� -> ������ �밢�� üũ
	iBingo += BingoCountingLTD(parray);
	//������ -> ���� �밢�� üũ
	iBingo += BingoCountingRTD(parray);
	return iBingo;
}
int BingoCountingH(int* iArray)
{
	//�� ���� �����ش�
	int iStar1 = 0;
	int iBingo = 0;

	for (int i = 0; i < 5; i++)
	{
		//���� üũ�ϱ� �� ���� 0���� �ʱ�ȭ
		iStar1 = 0;
		for (int j = 0; j < 5; j++)
		{
			//�� ���� �����ش�
			if (iArray[i * 5 + j] == INT_MAX)
			{
				++iStar1;
			}
		}

		//j for���� ������ �� iStar1�� 5��� ���� ������ ��� *�̶�� �ǹ�
		if (iStar1 == 5)
		{
			++iBingo;
		}
	}

	return iBingo;
}

int BingoCountingV(int* iArray)
{
	//�� ���� �����ش�
	int iStar1 = 0;
	int iBingo = 0;

	for (int i = 0; i < 5; i++)
	{
		//���� üũ�ϱ� �� ���� 0���� �ʱ�ȭ
		iStar1 = 0;
		for (int j = 0; j < 5; j++)
		{
			//�� ���� �����ش�
			if (iArray[j * 5 + i] == INT_MAX)
			{
				++iStar1;
			}
		}

		//j for���� ������ �� iStar1�� 5��� ���� ������ ��� *�̶�� �ǹ�
		if (iStar1 == 5)
		{
			++iBingo;
		}
	}
	return iBingo;
}

int BingoCountingLTD(int* iArray)
{
	//�� ���� �����ش�
	int iStar1 = 0;
	int iBingo = 0;

	//���� ��� -> ������ �ϴ� �밢�� üũ
	//�밢������ 6�� ����
	iStar1 = 0;
	for (int i = 0; i < 25; i += 6)
	{
		if (iArray[i] == INT_MAX)
		{
			++iStar1;
		}
	}
	if (iStar1 == 5)
	{
		++iBingo;
	}
	return iBingo;
}

int BingoCountingRTD(int* iArray)
{
	int iStar1 = 0;
	int iBingo = 0;
	//������ ��� -> ���� �ϴ� �밢�� üũ
	//�밢������ 4�� ����
	iStar1 = 0;
	for (int i = 4; i <= 20; i += 4)
	{
		if (iArray[i] == INT_MAX)
		{
			++iStar1;
		}
	}
	if (iStar1 == 5)
	{
		++iBingo;
	}
	return iBingo;
}
