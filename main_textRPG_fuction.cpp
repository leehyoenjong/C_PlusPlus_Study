#include <time.h>
#include <iostream>

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

enum EQUIP
{
	EQ_WEAPON,
	EQ_ARMOR,
	EQ_MAX,
};

enum ITEM_TPYE
{
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK,
};

#define NAME_SIZE 32
#define ITEM_DESC_LENGTH 32
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3
#define LEVEL_MAX 10
const int g_iLevelUpEXP[LEVEL_MAX] = { 1000,2000,3000,4000, 5000,6000,7000,8000,9000,10000 };

struct _tagLevelUpStatus
{
	int iAttackMin;
	int iAttackMax;
	int iArmorMin;
	int iArmorMax;
	int iHpMin;
	int iHpMax;
	int iMpMin;
	int iMpMax;
};

struct _tagItem
{
	char strName[NAME_SIZE];
	char strTypeName[NAME_SIZE];
	ITEM_TPYE eType;
	int iMin;
	int iMax;
	int iPrice;
	int iSell;
	char strDesc[ITEM_DESC_LENGTH];
};

struct _tagInventory
{
	_tagItem titem[INVENTORY_MAX];
	int iItemCount;
	int iGold;
};

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
	_tagItem tEquip[EQ_MAX];
	bool bEquip[EQ_MAX];
	_tagInventory tInventory;
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

//���ڸ� �Է¹޴´� �Է� �������� ó�� ���ְ� INT_MAX�� �����ϸ� ����
int InputInt()
{
	int iInput;
	cin >> iInput;

	if (cin.fail())
	{
		cin.clear();
		cin.ignore(1024, '\n');
		return INT_MAX;
	}

	return iInput;
}

//���� �޴��� ȭ�鿡 �����ְ� �Է¹��� �޴� ��ȯ
// �Է� ���� Ȥ�� �߸��� ��ȣ �Է� �� MM_NONE�� ����
int OutputMainMenu()
{
	//�κ� ����
	system("cls");
	cout << "******�κ�******" << endl;
	cout << "1. ��" << endl;
	cout << "2. ����" << endl;
	cout << "3. ����" << endl;
	cout << "4. ����" << endl;

	cout << "�޴��� �����ϼ���! : ";
	int iMenu = InputInt();

	if (iMenu == INT_MAX || iMenu <= MM_NONE || iMenu > MM_EXIT)
	{
		return MM_NONE;
	}

	return iMenu;
}

int OutputMapMenu()
{
	system("cls");
	cout << "******��******" << endl;
	cout << "1. ����" << endl;
	cout << "2. ����" << endl;
	cout << "3. �����" << endl;
	cout << "4. �ڷΰ���" << endl;

	cout << "���̵��� ������ �ּ��� : ";
	int iMenu = InputInt();

	if (iMenu == INT_MAX || iMenu <= MT_NONE || iMenu > MT_BACK)
	{
		return MT_BACK;
	}

	return iMenu;
}

int SelectJob()
{
	//���� ���� 
	int iJob = JOB_NONE;
	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "1. ���" << endl;
		cout << "2. �ü�" << endl;
		cout << "3. ������" << endl;
		cout << "������ �����ϼ��� : ";
		iJob = InputInt();

		if (iJob <= JOB_NONE || iJob >= JOB_END)
		{
			iJob = JOB_NONE;
		}
	}
	return iJob;
}

void SetPlayer(_tagPlayer* pPlayer)
{
	//�̸� ����
	cout << "�̸� : ";
	//������ ���ڿ��� �� ä�������� null�� �ν� ���ϱ� ����
	cin.getline(pPlayer->strName, NAME_SIZE - 1);

	pPlayer->eJob = (JOB)SelectJob();
	//���� �̸�
	pPlayer->iLevel = 1;
	pPlayer->iExp = 0;
	pPlayer->tInventory.iGold = 10000;

	switch (pPlayer->eJob)
	{
	case JOB_KNIGHT:
		strcpy_s(pPlayer->strJobNAME, "���");
		pPlayer->iAttackMin = 5;
		pPlayer->iAttackMax = 10;
		pPlayer->iArmorMin = 15;
		pPlayer->iArmorMin = 20;
		pPlayer->iHpMax = 500;
		pPlayer->iHp = 500;
		pPlayer->iMP = 100;
		pPlayer->iMPMax = 100;
		break;
	case JOB_ARCHER:
		strcpy_s(pPlayer->strJobNAME, "�ü�");
		pPlayer->iAttackMin = 10;
		pPlayer->iAttackMax = 15;
		pPlayer->iArmorMin = 10;
		pPlayer->iArmorMin = 15;
		pPlayer->iHpMax = 400;
		pPlayer->iHp = 400;
		pPlayer->iMP = 200;
		pPlayer->iMPMax = 200;
		break;
	case JOB_WIZARD:
		strcpy_s(pPlayer->strJobNAME, "������");
		pPlayer->iAttackMin = 15;
		pPlayer->iAttackMax = 20;
		pPlayer->iArmorMin = 5;
		pPlayer->iArmorMin = 10;
		pPlayer->iHpMax = 300;
		pPlayer->iHp = 300;
		pPlayer->iMP = 300;
		pPlayer->iMPMax = 300;
		break;
	}
}

//���� ����
_tagMonster CreateMonster(const char* pName, int iAttackMin, int iAttackMax, int iArmorMin, int ArmorMax, int iHP, int iMP, int iLevel, int iExp, int iGoldMin, int IGoldMax)
{
	_tagMonster tMonster = {};

	strcpy_s(tMonster.strName, pName);
	tMonster.iAttackMin = iAttackMin;
	tMonster.iAttackMax = iAttackMax;
	tMonster.iArmorMin = iArmorMin;
	tMonster.iArmorMax = ArmorMax;
	tMonster.iHp = iHP;
	tMonster.iHpMax = iHP;
	tMonster.iMP = iMP;
	tMonster.iMPMax = iMP;
	tMonster.iLevel = iLevel;
	tMonster.iExp = iExp;
	tMonster.iGoleMin = iGoldMin;
	tMonster.iGoleMax = IGoldMax;
	return tMonster;
}

void SetMonster(_tagMonster* pMonsterArr)
{
	pMonsterArr[0] = CreateMonster("���", 20, 30, 2, 5, 100, 10, 1, 1000, 500, 1500);
	pMonsterArr[1] = CreateMonster("Ʈ��", 80, 130, 60, 90, 2000, 100, 5, 7000, 6000, 8000);
	pMonsterArr[2] = CreateMonster("�巡��", 250, 500, 200, 400, 30000, 20000, 10, 30000, 20000, 3000);
}

void OutputBattleTag(int iMenu)
{
	switch (iMenu)
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

void OutputMonster(_tagMonster* pMonster)
{
	//���� ���� ���
	cout << "********* Monster *********" << endl;
	cout << "�̸� : " << pMonster->strName << endl;
	cout << "���� : " << pMonster->iLevel << "\tȹ�� ����ġ : " << pMonster->iExp << endl;
	cout << "���ݷ� : " << pMonster->iAttackMax << " /  " << pMonster->iAttackMax << endl;
	cout << "���� : " << pMonster->iArmorMax << " / " << pMonster->iArmorMax << endl;
	cout << "ü�� : " << pMonster->iHp << " / " << pMonster->iHpMax << endl;
	cout << "���� : " << pMonster->iMP << " / " << pMonster->iMPMax << endl;
	cout << "���� ��� : " << pMonster->iGoleMin << " / " << pMonster->iGoleMax << endl;
}

void OutputPlayer(_tagPlayer* pPlayer)
{
	//�÷��̾� ����
	cout << "********* Player *********" << endl;
	cout << "�̸� : " << pPlayer->strName << "\t���� : " << pPlayer->strJobNAME << endl;
	cout << "���� : " << pPlayer->iLevel << "\t����ġ : " << pPlayer->iExp << " / " << g_iLevelUpEXP[pPlayer->iLevel - 1] << endl;
	//���⸦ �����ϰ� �̝��� ��� ���ݷ¿� ������ݷ��� �߰��Ͽ� ���
	if (pPlayer->bEquip[EQ_WEAPON] == true)
	{
		cout << "���ݷ� : " << pPlayer->iAttackMin << " + " << pPlayer->tEquip[EQ_WEAPON].iMin << " - " << pPlayer->iAttackMax << " + " << pPlayer->tEquip[EQ_WEAPON].iMax << endl;
	}
	else
	{
		cout << "���ݷ� : " << pPlayer->iAttackMin << " /  " << pPlayer->iAttackMax << endl;
	}

	//�� ���� �� 
	if (pPlayer->bEquip[EQ_ARMOR] == true)
	{
		cout << "���� : " << pPlayer->iArmorMin << " + " << pPlayer->tEquip[EQ_ARMOR].iMin << " - " << pPlayer->iArmorMax << " + " << pPlayer->tEquip[EQ_ARMOR].iMax << endl;
	}
	else
	{
		cout << "���� : " << pPlayer->iArmorMin << " /  " << pPlayer->iArmorMax << endl;
	}
	cout << "ü�� : " << pPlayer->iHp << " / " << pPlayer->iHpMax << endl;
	cout << "���� : " << pPlayer->iMP << " / " << pPlayer->iMPMax << endl;
	cout << "���� ��� : " << pPlayer->tInventory.iGold << endl;
}

int OutputBattleMenu()
{
	cout << "1. ����" << endl;
	cout << "2. ��������" << endl;
	cout << "�޴��� ������ �ּ��� : ";
	int iMenu = InputInt();

	if (iMenu == INT_MAX || iMenu <= BATTLE_NONE || iMenu > BATTLE_BACK)
	{
		return BATTLE_NONE;
	}

	return iMenu;
}

void RunBattle(_tagPlayer* pPlayer, _tagMonster* pMonsterArr, int iMenu)
{
	_tagMonster tMonster = pMonsterArr[iMenu - 1];

	while (true)
	{
		system("cls");
		OutputBattleTag(iMenu);

		//�÷��̾� ����
		OutputPlayer(pPlayer);

		//���� ���
		OutputMonster(&tMonster);

		switch (OutputBattleMenu())
		{
		case BATTLE_ATTACK:
			break;
		case BATTLE_BACK:
			return;
		}
	}
}

void RunMap(_tagPlayer* pPlayer, _tagMonster* tMonsterArr)
{
	while (true)
	{
		int iMenu = OutputMapMenu();
		if (iMenu == INT_MAX || iMenu <= MT_NONE || iMenu >= MT_BACK)
		{
			return;
		}

		//���� ����
		RunBattle(pPlayer, tMonsterArr, iMenu);
	}
}

int main()
{
	srand((unsigned int)time(0));
	bool bLoop = true;

	//���� �����Ҷ� �÷��̾� ���� ����
	_tagPlayer tPlayer = {};

	//�÷��̾��� ������ �����Ѵ�.
	SetPlayer(&tPlayer);

	//���� ����
	_tagMonster tMonsterArr[MT_BACK - 1] = {};
	SetMonster(tMonsterArr);

	while (bLoop)
	{
		switch (OutputMainMenu())
		{
		case MM_MAP:
			RunMap(&tPlayer, tMonsterArr);
			break;
		case MM_STORE:
			break;
		case MM_INVENTORY:
			break;
		case MM_EXIT:
			bLoop = false;
			break;
		}
	}

	return 0;
}