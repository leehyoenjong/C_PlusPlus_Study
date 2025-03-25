#include <iostream>

using namespace std;

int main()
{
	srand((unsigned int)time(0));
	int iArray[25] = {};

	//1~25������ ���ڸ� �ִ´�.
	for (int i = 0; i < 25; ++i)
	{
		iArray[i] = i + 1;
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
	}

	int iBingo = 0;

	while (true)
	{
		system("cls");

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

		cout << "Bingo Line : " << iBingo << endl;
		if (iBingo >= 2)
		{
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

		//���� �� �� üũ�ϴ� ���� �Ź� ���ڸ� �Է��Ҷ����� ó������ ���� ī��Ʈ�� �� ���̴�
		//�׷��Ƿ� iBingo�� 0���� �ʱ�ȭ �Ѵ�.
		iBingo = 0;

		//����, ���� �� ���� �����ش�
		int iStar1 = 0, iStar2 = 0;
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
		}
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
	}

	return 0;
}