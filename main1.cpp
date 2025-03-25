#include <iostream>

using namespace std;


enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

int main()
{
	srand((unsigned int)time(0));
	int iArray[25] = {};
	int iAIArray[25] = {};

	//1~25������ ���ڸ� �ִ´�.
	for (int i = 0; i < 25; ++i)
	{
		iArray[i] = i + 1;
		iAIArray[i] = i + 1;
	}

	//����
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = iArray[idx1];
		iArray[idx1] = iArray[idx2];
		iArray[idx2] = iTemp;

		//AI ���ڵ� �����ش�.
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = iAIArray[idx1];
		iAIArray[idx1] = iAIArray[idx2];
		iAIArray[idx2] = iTemp;
	}

	int iBingo = 0, iAIBingo = 0;
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

	//���þȵ� ��� �迭�� ������ش�
	int iNoneSelect[25] = {};
	int iNoneSelCnt = 0;


	while (true)
	{
		system("cls");

		//���ڸ� 5x5�� ����Ѵ�.
		cout << "================== Player ==================" << endl;

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iArray[i * 5 + j] == INT_MAX)
				{
					cout << "*\t";
				}
				else
				{
					cout << iArray[i * 5 + j] << "\t";
				}
			}
			cout << endl;
		}

		cout << "Bingo Line : " << iBingo << endl << endl;

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
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iAIArray[i * 5 + j] == INT_MAX)
				{
					cout << "*\t";
				}
				else
				{
					cout << iAIArray[i * 5 + j] << "\t";
				}
			}
			cout << endl;
		}

		cout << "AI Bingo Line : " << iBingo << endl << endl;


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
		bool bAcc = true;

		//��� ���ڸ� ���ʴ�� �˻��� �Է��� ���ڿ� ���� ���ڰ� �ִ��� ã�Ƴ���
		for (int i = 0; i < 25; i++)
		{
			//���� ���ڰ� ���� ��� 
			if (iInput == iArray[i])
			{
				//���ڸ� ã���� ��� �ߺ��� ���ڰ� �ƴϹǷ� 
				//bAcc�� false�� �����
				bAcc = false;

				//���ڸ� *�� ����� ���� Ư���� ���� INT_MAX�� ����
				iArray[i] = INT_MAX;

				//���̻� �ٸ� ���ڸ� ã�ƺ� �ʿ䰡 �����Ƿ� for���� ����������.
				break;
			}
		}

		//bAcc�� true�� ��� �ߺ��� ���ڸ� �Է��ؼ� ����*�� ������ �������Ƿ�
		//�ٽ� �Է¹ޱ� ���� continue�� �Ѵ�.
		if (bAcc)
		{
			continue;
		}

		//�ߺ��� �ƴ϶�� AI�� ���ڸ� �ϳ� �����ؼ� *�� �����.
		for (int i = 0; i < 25; i++)
		{
			if (iAIArray[i] == iInput)
			{
				iAIArray[i] = INT_MAX;
				break;
			}
		}

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
				if (iAIArray[i] != INT_MAX)
				{
					//*�� �ƴ� ������ ��� iNoneSelect�� �ε����� Ȱ��
					//���� �ȵ� ��Ͽ� �߰�
					iNoneSelect[iNoneSelCnt] = iAIArray[i];
					++iNoneSelCnt;
				}
			}

			//for���� ���� ������ �Ǹ� ���þȵ� ����� ���������
			//���þȵ� ����� ������ ���������.
			//�׷��Ƿ� 0~iNoneSelCnt-1������ ���ڸ� �������� �̾Ƽ�
			//�� ���ڸ� *�� ������ָ� �ȴ�.
			iInput = iNoneSelect[rand() % iNoneSelCnt];
			break;
		case AM_HARD:
			break;
		}

		//AI�� ������ ���ڸ� AI�迭�� �÷��̾�� *�� ������ش�.
		for (int i = 0; i < 25; i++)
		{
			if (iInput == iArray[i])
			{
				iArray[i] = INT_MAX;
				break;
			}
		}
		for (int i = 0; i < 25; i++)
		{
			if (iInput == iAIArray[i])
			{
				iAIArray[i] = INT_MAX;
				break;
			}
		}

		//���� �� �� üũ�ϴ� ���� �Ź� ���ڸ� �Է��Ҷ����� ó������ ���� ī��Ʈ�� �� ���̴�
		//�׷��Ƿ� iBingo�� 0���� �ʱ�ȭ �Ѵ�.
		iBingo = 0;
		iAIBingo = 0;

		//����, ���� �� ���� �����ش�
		int iStar1 = 0, iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;
		for (int i = 0; i < 5; i++)
		{
			//���� üũ�ϱ� �� ���� 0���� �ʱ�ȭ
			iStar1 = iStar2 = 0;
			for (int j = 0; j < 5; j++)
			{
				//���� �� ���� �����ش�
				if (iArray[i * 5 + j] == INT_MAX)
				{
					++iStar1;
				}
				//���� �� ����	�����ش�
				if (iArray[j * 5 + i] == INT_MAX)
				{
					++iStar2;
				}

				//���� �� ���� �����ش�
				if (iAIArray[i * 5 + j] == INT_MAX)
				{
					++iAIStar1;
				}
				//���� �� ����	�����ش�
				if (iAIArray[j * 5 + i] == INT_MAX)
				{
					++iAIStar2;
				}
			}

			//j for���� ������ �� iStar1�� 5��� ���� ������ ��� *�̶�� �ǹ�
			if (iStar1 == 5)
			{
				++iBingo;
			}
			if (iStar2 == 5)
			{
				++iBingo;
			}

			//j for���� ������ �� iStar1�� 5��� ���� ������ ��� *�̶�� �ǹ�
			if (iAIStar1 == 5)
			{
				++iAIBingo;
			}
			if (iAIStar2 == 5)
			{
				++iAIBingo;
			}
		}
		//���� ��� -> ������ �ϴ� �밢�� üũ
		//�밢������ 6�� ����
		iStar1 = 0;
		iAIStar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iArray[i] == INT_MAX)
			{
				++iStar1;
			}
			if (iAIArray[i] == INT_MAX)
			{
				++iAIStar1;
			}
		}
		if (iStar1 == 5)
		{
			++iBingo;
		}
		if (iAIStar1 == 5)
		{
			++iAIBingo;
		}

		//������ ��� -> ���� �ϴ� �밢�� üũ
		//�밢������ 4�� ����
		iStar1 = 0;
		iAIStar1 = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (iArray[i] == INT_MAX)
			{
				++iStar1;
			}
			if (iAIArray[i] == INT_MAX)
			{
				++iAIStar1;
			}
		}
		if (iStar1 == 5)
		{
			++iBingo;
		}
		if (iAIStar1 == 5)
		{
			++iAIBingo;
		}
	}

	return 0;
}