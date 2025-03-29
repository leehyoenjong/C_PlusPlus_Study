#include <iostream>
#include <time.h>


using namespace std;

enum MAIN_MENU
{
	MM_NONE,
	MM_MAP,
	MM_STORE,
	MM_INVENTORY,
	MM_EXIT
};

enum MM_TYPE
{
	MT_NONE,
	MT_EASY,
	MT_NORMAL,
	MT_HARD,
	MT_BACK
};

enum JOB
{
	JOB_NONE,
	JOB_KNIGHT,
	JOB_ARCHER,
	JOB_WIZARD,
	JOB_END
};

#define NAME_SIZE 32

struct _tagPlayer
{
	char strName[NAME_SIZE];
	char strJobNAME[NAME_SIZE];
	JOB eJob;
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHp;
	int iHpMax;
	int iMP;
	int iMPMax;
	int iExp;
	int iLevel;
};

struct _tagMonster
{
	char strName[NAME_SIZE];
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHp;
	int iHpMax;
	int iMP;
	int iMPMax;
	int iExp;
	int iLevel;
	int iGoleMin;
	int iGoleMax;
};

int main()
{
	srand((unsigned int)time(0));
	//���� �����Ҷ� �÷��̾� ���� ����

	_tagPlayer tPlayer = {};

	//�̸� ����
	cout << "�̸� : ";
	//������ ���ڿ��� �� ä�������� null�� �ν� ���ϱ� ����
	cin.getline(tPlayer.strName, NAME_SIZE - 1);


	//���� ���� 
	int iJob = JOB_NONE;
	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "1. ���" << endl;
		cout << "2. �ü�" << endl;
		cout << "3. ������" << endl;
		cout << "������ �����ϼ��� : " << endl;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}
		else if (iJob <= JOB_NONE || iJob >= JOB_END)
		{
			iJob = JOB_NONE;
		}

		//���� �̸�
		tPlayer.eJob = (JOB)iJob;

		switch (tPlayer.eJob)
		{
		case JOB_KNIGHT:
			strcpy_s(tPlayer.strJobNAME, "���");
			tPlayer.iAttackMin = 5;
			tPlayer.iAttackMax = 10;
			tPlayer.iArmorMin = 15;
			tPlayer.iArmorMin = 20;
			tPlayer.iHpMax = 500;
			tPlayer.iHp = 500;
			tPlayer.iMP = 100;
			tPlayer.iMPMax = 100;
			break;
		case JOB_ARCHER:
			strcpy_s(tPlayer.strJobNAME, "�ü�");
			tPlayer.iAttackMin = 10;
			tPlayer.iAttackMax = 15;
			tPlayer.iArmorMin = 10;
			tPlayer.iArmorMin = 15;
			tPlayer.iHpMax = 400;
			tPlayer.iHp = 400;
			tPlayer.iMP = 200;
			tPlayer.iMPMax = 200;
			break;
		case JOB_WIZARD:
			strcpy_s(tPlayer.strJobNAME, "������");
			tPlayer.iAttackMin = 15;
			tPlayer.iAttackMax = 20;
			tPlayer.iArmorMin = 5;
			tPlayer.iArmorMin = 10;
			tPlayer.iHpMax = 300;
			tPlayer.iHp = 300;
			tPlayer.iMP = 300;
			tPlayer.iMPMax = 300;
			break;
		}

		tPlayer.iLevel = 1;
		tPlayer.iExp = 0;
	}

	//���� ����
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	//��� ����
	strcpy_s(tMonsterArr[0].strName, "���");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMin = 30;
	tMonsterArr[0].iArmorMin = 2;
	tMonsterArr[0].iArmorMax = 5;
	tMonsterArr[0].iHp = 100;
	tMonsterArr[0].iHpMax = 100;
	tMonsterArr[0].iMP = 10;
	tMonsterArr[0].iMPMax = 10;
	tMonsterArr[0].iLevel = 1;
	tMonsterArr[0].iExp = 1000;
	tMonsterArr[0].iGoleMin = 500;
	tMonsterArr[0].iGoleMax = 1500;

	//Ʈ�� ����
	strcpy_s(tMonsterArr[1].strName, "Ʈ��");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMin = 130;
	tMonsterArr[1].iArmorMin = 60;
	tMonsterArr[1].iArmorMax = 90;
	tMonsterArr[1].iHp = 2000;
	tMonsterArr[1].iHpMax = 2000;
	tMonsterArr[1].iMP = 100;
	tMonsterArr[1].iMPMax = 100;
	tMonsterArr[1].iLevel = 5;
	tMonsterArr[1].iExp = 7000;
	tMonsterArr[1].iGoleMin = 6000;
	tMonsterArr[1].iGoleMax = 8000;

	//�巡�� ����
	strcpy_s(tMonsterArr[2].strName, "�巡��");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMin = 500;
	tMonsterArr[2].iArmorMin = 200;
	tMonsterArr[2].iArmorMax = 400;
	tMonsterArr[2].iHp = 30000;
	tMonsterArr[2].iHpMax = 30000;
	tMonsterArr[2].iMP = 20000;
	tMonsterArr[2].iMPMax = 20000;
	tMonsterArr[2].iLevel = 10;
	tMonsterArr[2].iExp = 30000;
	tMonsterArr[2].iGoleMin = 20000;
	tMonsterArr[2].iGoleMax = 50000;

	

	while (true)
	{
		//�κ� ����
		system("cls");
		cout << "******�κ�******" << endl;
		cout << "1. ��" << endl;
		cout << "2. ����" << endl;
		cout << "3. ����" << endl;
		cout << "4. ����" << endl;

		cout << "�޴��� �����ϼ���! : ";
		int imenu;
		cin >> imenu;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1024, '\n');
			continue;
		}

		if (imenu == MM_EXIT)
		{
			break;
		}

		//�޴��� ���� ó�� 
		switch (imenu)
		{
			//�� ����
		case MM_MAP:
			while (true)
			{
				system("cls");
				cout << "******��******" << endl;
				cout << "1. ����" << endl;
				cout << "2. ����" << endl;
				cout << "3. �����" << endl;
				cout << "4. �ڷΰ���" << endl;

				cout << "���̵��� ������ �ּ��� : ";
				cin >> imenu;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}

				//�� if���� �� �޴��� �����ֱ� ���� while�� ���� �����Ƿ� �� while���� ��������
				if (imenu == MT_BACK)
				{
					break;
				}

				//������ �޴� 1�� ���ָ� ���� �迭�� �ε����� �ȴ�
				//�׷��� �ؼ� �ش� ���� ���� ����
				_tagMonster tMonster = tMonsterArr[imenu - 1];

				//���� ����
				while (true)
				{
					switch (imenu)
					{
					case MT_EASY:
						cout << "********* ���� *********" << endl;
						break;
					case MT_NORMAL:
						cout << "********* ���� *********" << endl;
						break;
					case MT_HARD:
						cout << "********* ����� *********" << endl;
						break;
					}
				}
			}
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		default:
			break;
		}
	}
	return 0;
}