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

struct _tagInventory
{
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

enum BATTLE
{
	BATTLE_NONE,
	BATTLE_ATTACK,
	BATTLE_BACK,
};

int main()
{
	srand((unsigned int)time(0));
	//게임 시작할때 플레이어 정보 설정

	_tagPlayer tPlayer = {};

	//이름 설정
	cout << "이름 : ";
	//끝까지 문자열을 다 채워버리면 null을 인식 못하기 때문
	cin.getline(tPlayer.strName, NAME_SIZE - 1);


	//직업 설정 
	int iJob = JOB_NONE;
	while (iJob == JOB_NONE)
	{
		system("cls");
		cout << "1. 기사" << endl;
		cout << "2. 궁수" << endl;
		cout << "3. 마법사" << endl;
		cout << "직업을 선택하세요 : ";
		cin >> iJob;

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

		//직업 이름
		tPlayer.eJob = (JOB)iJob;
		tPlayer.iLevel = 1;
		tPlayer.iExp = 0;
		tPlayer.tInventory.iGold = 10000;


		switch (tPlayer.eJob)
		{
		case JOB_KNIGHT:
			strcpy_s(tPlayer.strJobNAME, "기사");
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
			strcpy_s(tPlayer.strJobNAME, "궁수");
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
			strcpy_s(tPlayer.strJobNAME, "마법사");
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
	}

	//몬스터 생성
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	//고블린 생성
	strcpy_s(tMonsterArr[0].strName, "고블린");
	tMonsterArr[0].iAttackMin = 20;
	tMonsterArr[0].iAttackMax = 30;
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

	//트롤 생성
	strcpy_s(tMonsterArr[1].strName, "트롤");
	tMonsterArr[1].iAttackMin = 80;
	tMonsterArr[1].iAttackMax = 130;
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

	//드래곤 생성
	strcpy_s(tMonsterArr[2].strName, "드래곤");
	tMonsterArr[2].iAttackMin = 250;
	tMonsterArr[2].iAttackMax = 500;
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
		//로비 구성
		system("cls");
		cout << "******로비******" << endl;
		cout << "1. 맵" << endl;
		cout << "2. 상점" << endl;
		cout << "3. 가방" << endl;
		cout << "4. 종료" << endl;

		cout << "메뉴를 선택하세요! : ";
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

		//메뉴에 따른 처리 
		switch (imenu)
		{
			//맵 선택
		case MM_MAP:
			while (true)
			{
				system("cls");
				cout << "******맵******" << endl;
				cout << "1. 쉬움" << endl;
				cout << "2. 보통" << endl;
				cout << "3. 어려움" << endl;
				cout << "4. 뒤로가기" << endl;

				cout << "난이도를 선택해 주세요 : ";
				cin >> imenu;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				//이 if문은 맵 메뉴를 돌려주기 위한 while에 속해 있으므로 이 while문을 빠져나감
				else if (imenu == MT_BACK)
				{
					break;
				}

				//선택한 메뉴 1을 빼주면 몬스터 배열의 인덱스가 된다
				//그렇게 해서 해당 맵의 몬스터 생성
				_tagMonster tMonster = tMonsterArr[imenu - 1];


				//전투 시작
				while (true)
				{
					switch (imenu)
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

					//플레이어 정보
					cout << "********* Player *********" << endl;
					cout << "이름 : " << tPlayer.strName << "\t직업 : " << tPlayer.strJobNAME << endl;
					cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " << tPlayer.iExp << endl;
					cout << "공격력 : " << tPlayer.iAttackMax << " /  " << tPlayer.iAttackMax << endl;
					cout << "방어력 : " << tPlayer.iArmorMax << " / " << tPlayer.iArmorMax << endl;
					cout << "체력 : " << tPlayer.iHp << " / " << tPlayer.iHpMax << endl;
					cout << "마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
					cout << "보유 골드 : " << tPlayer.tInventory.iGold << endl;

					//몬스터 정보 출력
					cout << "********* Monster *********" << endl;
					cout << "이름 : " << tMonster.strName << endl;
					cout << "레벨 : " << tMonster.iLevel << "\t획득 경험치 : " << tMonster.iExp << endl;
					cout << "공격력 : " << tMonster.iAttackMax << " /  " << tMonster.iAttackMax << endl;
					cout << "방어력 : " << tMonster.iArmorMax << " / " << tMonster.iArmorMax << endl;
					cout << "체력 : " << tMonster.iHp << " / " << tMonster.iHpMax << endl;
					cout << "마나 : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
					cout << "보유 골드 : " << tMonster.iGoleMin << " / " << tMonster.iGoleMax << endl;

					cout << "1. 공격" << endl;
					cout << "2. 도망가기" << endl;
					cout << "메뉴를 선택해 주세요 : ";
					cin >> imenu;
					system("cls");
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1024, '\n');
						continue;
					}
					else if (imenu == BATTLE_BACK)
					{
						break;
					}
					switch (imenu)
					{
					case BATTLE_ATTACK:

						//플레이어가 공격
						// 예를들어 min 5 Max15 일 경우
						// 15 - 5 + 1을하면 11이 됨
						// 11로 나눈 나머지는 0~10이 되고 여기에 min값인 5를 더하게 되면 5~15사이로 값이 나오게 됨
						int iattack = rand() % ((tPlayer.iAttackMax - tPlayer.iAttackMin + 1) + tPlayer.iAttackMin);
						int iarmor = rand() % ((tMonster.iArmorMax - tMonster.iArmorMin + 1) + tMonster.iArmorMin);
						int idamage = iattack - iarmor;

						//삼항연산자 : 조건식 ? true일때값 : flase일때 값
						idamage = idamage < 1 ? 1 : idamage;

						//몬스터 hp를 감소시킨다
						tMonster.iHp -= idamage;

						cout << tPlayer.strName << " 가 " << tMonster.strName << " 에게 " << idamage << " 피해를 입혔습니다. " << endl;

						//몬스터가 죽었을 경우
						if (tMonster.iHp <= 0)
						{
							cout << tMonster.strName << " 몬스터가 사망하였습니다." << endl;
							tPlayer.iExp += tMonster.iExp;
							int igold = rand() % ((tMonster.iGoleMax - tMonster.iGoleMin + 1) + tMonster.iGoleMin);
							tPlayer.tInventory.iGold += igold;

							//몬스터 다시 부활
							tMonster.iHp = tMonster.iHpMax;
							tMonster.iMP = tMonster.iMPMax;

							cout << tMonster.iExp << " 경험치를 획득하였습니다. " << endl;
							cout << igold << " 골드를 획득하였습니다." << endl;
							system("pause");
							break;
						}

						//몬스터가 살아있다면 몬스터가 공격
						iattack = rand() % ((tMonster.iAttackMax - tMonster.iAttackMin + 1) + tMonster.iAttackMin);
						iarmor = rand() % ((tPlayer.iArmorMax - tPlayer.iArmorMin + 1) + tPlayer.iArmorMin);
						idamage = iattack - iarmor;

						//플레이어 데미지 받음
						tPlayer.iHp -= idamage;

						cout << tMonster.strName << " 가 " << tPlayer.strName << " 에게 " << idamage << " 피해를 입혔습니다. " << endl;

						//몬스터가 죽었을 경우
						if (tPlayer.iHp <= 0)
						{
							cout << tPlayer.strName << " 플레이어가 사망하였습니다." << endl;
							int iexp = tPlayer.iExp * 0.1f;
							int igold = tPlayer.tInventory.iGold * 0.1f;
							tPlayer.iExp -= iexp;
							tPlayer.tInventory.iGold -= igold;

							cout << iexp << " 경험치를 잃었습니다. " << endl;
							cout << igold << " 골드를 잃었습니다." << endl;

							//플레이어의 hp와 mp를 회복한다
							tPlayer.iHp = tPlayer.iHpMax;
							tPlayer.iMP = tPlayer.iMPMax;
						}
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
