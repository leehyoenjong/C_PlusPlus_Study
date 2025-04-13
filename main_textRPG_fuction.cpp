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

//숫자르 입력받는다 입력 오류까지 처리 해주고 INT_MAX를 리턴하면 오류
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

//메인 메뉴를 화면에 보여주고 입력받은 메뉴 반환
// 입력 오류 혹은 잘못된 번호 입력 시 MM_NONE을 리턴
int OutputMainMenu()
{
	//로비 구성
	system("cls");
	cout << "******로비******" << endl;
	cout << "1. 맵" << endl;
	cout << "2. 상점" << endl;
	cout << "3. 가방" << endl;
	cout << "4. 종료" << endl;

	cout << "메뉴를 선택하세요! : ";
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
	cout << "******맵******" << endl;
	cout << "1. 쉬움" << endl;
	cout << "2. 보통" << endl;
	cout << "3. 어려움" << endl;
	cout << "4. 뒤로가기" << endl;

	cout << "난이도를 선택해 주세요 : ";
	int iMenu = InputInt();

	if (iMenu == INT_MAX || iMenu <= MT_NONE || iMenu > MT_BACK)
	{
		return MT_BACK;
	}

	return iMenu;
}

int SelectJob()
{
	//직업 설정 
	int iJob = JOB_NONE;
	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요 : ";
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
	//이름 설정
	cout << "이름 : ";
	//끝까지 문자열을 다 채워버리면 null을 인식 못하기 때문
	cin.getline(pPlayer->strName, NAME_SIZE - 1);

	pPlayer->eJob = (JOB)SelectJob();
	//직업 이름
	pPlayer->iLevel = 1;
	pPlayer->iExp = 0;
	pPlayer->tInventory.iGold = 10000;

	switch (pPlayer->eJob)
	{
	case JOB_KNIGHT:
		strcpy_s(pPlayer->strJobNAME, "기사");
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
		strcpy_s(pPlayer->strJobNAME, "궁수");
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
		strcpy_s(pPlayer->strJobNAME, "마법사");
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

//몬스터 생성
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
	pMonsterArr[0] = CreateMonster("고블린", 20, 30, 2, 5, 100, 10, 1, 1000, 500, 1500);
	pMonsterArr[1] = CreateMonster("트롤", 80, 130, 60, 90, 2000, 100, 5, 7000, 6000, 8000);
	pMonsterArr[2] = CreateMonster("드래곤", 250, 500, 200, 400, 30000, 20000, 10, 30000, 20000, 3000);
}

void OutputBattleTag(int iMenu)
{
	switch (iMenu)
	{
	case MT_EASY:
		cout << "********* 쉬움 *********" << endl;
		break;
	case MT_NORMAL:
		cout << "********* 보통 *********" << endl;
		break;
	case MT_HARD:
		cout << "********* 어려움 *********" << endl;
		break;
	}
}

void OutputMonster(_tagMonster* pMonster)
{
	//몬스터 정보 출력
	cout << "********* Monster *********" << endl;
	cout << "이름 : " << pMonster->strName << endl;
	cout << "레벨 : " << pMonster->iLevel << "\t획득 경험치 : " << pMonster->iExp << endl;
	cout << "공격력 : " << pMonster->iAttackMax << " /  " << pMonster->iAttackMax << endl;
	cout << "방어력 : " << pMonster->iArmorMax << " / " << pMonster->iArmorMax << endl;
	cout << "체력 : " << pMonster->iHp << " / " << pMonster->iHpMax << endl;
	cout << "마나 : " << pMonster->iMP << " / " << pMonster->iMPMax << endl;
	cout << "보유 골드 : " << pMonster->iGoleMin << " / " << pMonster->iGoleMax << endl;
}

void OutputPlayer(_tagPlayer* pPlayer)
{
	//플레이어 정보
	cout << "********* Player *********" << endl;
	cout << "이름 : " << pPlayer->strName << "\t직업 : " << pPlayer->strJobNAME << endl;
	cout << "레벨 : " << pPlayer->iLevel << "\t경험치 : " << pPlayer->iExp << " / " << g_iLevelUpEXP[pPlayer->iLevel - 1] << endl;
	//무기를 장착하고 이씅ㄹ 경우 공격력에 무기공격력을 추가하여 출력
	if (pPlayer->bEquip[EQ_WEAPON] == true)
	{
		cout << "공격력 : " << pPlayer->iAttackMin << " + " << pPlayer->tEquip[EQ_WEAPON].iMin << " - " << pPlayer->iAttackMax << " + " << pPlayer->tEquip[EQ_WEAPON].iMax << endl;
	}
	else
	{
		cout << "공격력 : " << pPlayer->iAttackMin << " /  " << pPlayer->iAttackMax << endl;
	}

	//방어구 장착 시 
	if (pPlayer->bEquip[EQ_ARMOR] == true)
	{
		cout << "방어력 : " << pPlayer->iArmorMin << " + " << pPlayer->tEquip[EQ_ARMOR].iMin << " - " << pPlayer->iArmorMax << " + " << pPlayer->tEquip[EQ_ARMOR].iMax << endl;
	}
	else
	{
		cout << "방어력 : " << pPlayer->iArmorMin << " /  " << pPlayer->iArmorMax << endl;
	}
	cout << "체력 : " << pPlayer->iHp << " / " << pPlayer->iHpMax << endl;
	cout << "마나 : " << pPlayer->iMP << " / " << pPlayer->iMPMax << endl;
	cout << "보유 골드 : " << pPlayer->tInventory.iGold << endl;
}

int OutputBattleMenu()
{
	cout << "1. 공격" << endl;
	cout << "2. 도망가기" << endl;
	cout << "메뉴를 선택해 주세요 : ";
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

		//플레이어 정보
		OutputPlayer(pPlayer);

		//몬스터 출력
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

		//전투 시작
		RunBattle(pPlayer, tMonsterArr, iMenu);
	}
}

int main()
{
	srand((unsigned int)time(0));
	bool bLoop = true;

	//게임 시작할때 플레이어 정보 설정
	_tagPlayer tPlayer = {};

	//플레이어의 정보를 정의한다.
	SetPlayer(&tPlayer);

	//몬스터 생성
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