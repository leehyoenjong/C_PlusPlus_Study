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
#define ITEM_DESC_LENGTH 32
#define INVENTORY_MAX 20
#define STORE_WEAPON_MAX 3
#define STORE_ARMOR_MAX 3
#define LEVEL_MAX 10

enum ITEM_TPYE
{
	IT_NONE,
	IT_WEAPON,
	IT_ARMOR,
	IT_BACK
};

enum STORE_MENU
{
	SM_NONE,
	SM_WEAPON,
	SM_ARMOR,
	SM_BACK
};

enum EQUIP
{
	EQ_WEAPON,
	EQ_ARMOR,
	EQ_MAX,
};

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

	//레벨업에 필요한 경험치 목록
	const int iLevelUpEXP[LEVEL_MAX] = { 1000,2000,3000,4000, 5000,6000,7000,8000,9000,10000 };

	//Job_End는 4이다 그런데 직업은 3개이므로 -1을 해주어 각 직업별로 생성하도록 함
	_tagLevelUpStatus tLvUpTable[JOB_END - 1] = {};
	tLvUpTable[JOB_KNIGHT - 1].iAttackMin = 4;
	tLvUpTable[JOB_KNIGHT - 1].iAttackMax = 10;
	tLvUpTable[JOB_KNIGHT - 1].iArmorMin = 8;
	tLvUpTable[JOB_KNIGHT - 1].iArmorMax = 15;
	tLvUpTable[JOB_KNIGHT - 1].iHpMin = 50;
	tLvUpTable[JOB_KNIGHT - 1].iHpMax = 100;
	tLvUpTable[JOB_KNIGHT - 1].iMpMin = 10;
	tLvUpTable[JOB_KNIGHT - 1].iMpMax = 20;

	tLvUpTable[JOB_ARCHER - 1].iAttackMin = 4;
	tLvUpTable[JOB_ARCHER - 1].iAttackMax = 10;
	tLvUpTable[JOB_ARCHER - 1].iArmorMin = 4;
	tLvUpTable[JOB_ARCHER - 1].iArmorMax = 10;
	tLvUpTable[JOB_WIZARD - 1].iHpMin = 30;
	tLvUpTable[JOB_WIZARD - 1].iHpMax = 60;
	tLvUpTable[JOB_WIZARD - 1].iMpMin = 30;
	tLvUpTable[JOB_WIZARD - 1].iMpMax = 50;

	tLvUpTable[JOB_WIZARD - 1].iAttackMin = 15;
	tLvUpTable[JOB_WIZARD - 1].iAttackMax = 20;
	tLvUpTable[JOB_WIZARD - 1].iArmorMin = 3;
	tLvUpTable[JOB_WIZARD - 1].iArmorMax = 7;
	tLvUpTable[JOB_WIZARD - 1].iHpMin = 10;
	tLvUpTable[JOB_WIZARD - 1].iHpMax = 20;
	tLvUpTable[JOB_WIZARD - 1].iMpMin = 50;
	tLvUpTable[JOB_WIZARD - 1].iMpMax = 100;

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

	//상점에 판매할 아이템 목록 생성
	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_WEAPON_MAX] = {};

	//각 아이템 정보 설정
	tStoreWeapon[0].eType = IT_WEAPON;
	strcpy_s(tStoreWeapon[0].strTypeName, "무기");
	strcpy_s(tStoreWeapon[0].strName, "목검");
	strcpy_s(tStoreWeapon[0].strDesc, "나무로 만든 검");
	tStoreWeapon[0].iMin = 5;
	tStoreWeapon[0].iMax = 10;
	tStoreWeapon[0].iPrice = 1000;
	tStoreWeapon[0].iSell = 500;

	tStoreWeapon[1].eType = IT_WEAPON;
	strcpy_s(tStoreWeapon[1].strTypeName, "무기");
	strcpy_s(tStoreWeapon[1].strName, "철검");
	strcpy_s(tStoreWeapon[1].strDesc, "철로 만든 검");
	tStoreWeapon[1].iMin = 20;
	tStoreWeapon[1].iMax = 30;
	tStoreWeapon[1].iPrice = 5000;
	tStoreWeapon[1].iSell = 4000;

	tStoreWeapon[2].eType = IT_WEAPON;
	strcpy_s(tStoreWeapon[2].strTypeName, "무기");
	strcpy_s(tStoreWeapon[2].strName, "황금검");
	strcpy_s(tStoreWeapon[2].strDesc, "황금으로 만든 검");
	tStoreWeapon[2].iMin = 50;
	tStoreWeapon[2].iMax = 100;
	tStoreWeapon[2].iPrice = 15000;
	tStoreWeapon[2].iSell = 10000;

	//방어구
	tStoreArmor[0].eType = IT_ARMOR;
	strcpy_s(tStoreArmor[0].strTypeName, "방어구");
	strcpy_s(tStoreArmor[0].strName, "나무 갑옷");
	strcpy_s(tStoreArmor[0].strDesc, "나무로 만든 갑옷");
	tStoreArmor[0].iMin = 5;
	tStoreArmor[0].iMax = 10;
	tStoreArmor[0].iPrice = 1000;
	tStoreArmor[0].iSell = 500;

	tStoreArmor[1].eType = IT_ARMOR;
	strcpy_s(tStoreArmor[1].strTypeName, "방어구");
	strcpy_s(tStoreArmor[1].strName, "철 갑옷");
	strcpy_s(tStoreArmor[1].strDesc, "철로 만든 갑옷");
	tStoreArmor[1].iMin = 20;
	tStoreArmor[1].iMax = 30;
	tStoreArmor[1].iPrice = 5000;
	tStoreArmor[1].iSell = 4000;

	tStoreArmor[2].eType = IT_ARMOR;
	strcpy_s(tStoreArmor[2].strTypeName, "방어구");
	strcpy_s(tStoreArmor[2].strName, "황금 갑옷");
	strcpy_s(tStoreArmor[2].strDesc, "황금으로 만든 갑옷");
	tStoreArmor[2].iMin = 50;
	tStoreArmor[2].iMax = 100;
	tStoreArmor[2].iPrice = 15000;
	tStoreArmor[2].iSell = 10000;


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
					cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " << tPlayer.iExp << " / " << iLevelUpEXP[tPlayer.iLevel - 1] << endl;
					//무기를 장착하고 이씅ㄹ 경우 공격력에 무기공격력을 추가하여 출력
					if (tPlayer.bEquip[EQ_WEAPON] == true)
					{
						cout << "공격력 : " << tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin << " - " << tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax << endl;
					}
					else
					{
						cout << "공격력 : " << tPlayer.iAttackMin << " /  " << tPlayer.iAttackMax << endl;
					}

					//방어구 장착 시 
					if (tPlayer.bEquip[EQ_ARMOR] == true)
					{
						cout << "방어력 : " << tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin << " - " << tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
					}
					else
					{
						cout << "방어력 : " << tPlayer.iArmorMin << " /  " << tPlayer.iArmorMax << endl;
					}
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
						int iattackmin = tPlayer.iAttackMin;
						int iattackmax = tPlayer.iAttackMax;

						if (tPlayer.bEquip[EQ_WEAPON])
						{
							iattackmin += tPlayer.tEquip[EQ_WEAPON].iMin;
							iattackmax += tPlayer.tEquip[EQ_WEAPON].iMax;
						}


						int iattack = rand() % ((iattackmax - iattackmin + 1) + iattackmin);
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

							//레벨업을 했는지 체크
							if (tPlayer.iExp >= iLevelUpEXP[tPlayer.iLevel - 1])
							{
								//레벨업에 필요한 만큼만 차감
								tPlayer.iExp -= iLevelUpEXP[tPlayer.iLevel - 1];

								//레벨업 처리
								++tPlayer.iLevel;
								cout << "레벨업 하셨습니다!" << endl;

								//능력치 상승
								int ijobindex = tPlayer.eJob - 1;
								int hpup = rand() % ((tLvUpTable[ijobindex].iHpMax - tLvUpTable[ijobindex].iHpMin + 1) + tLvUpTable[ijobindex].iHpMin);
								int mpup = rand() % ((tLvUpTable[ijobindex].iMpMax - tLvUpTable[ijobindex].iMpMin + 1) + tLvUpTable[ijobindex].iMpMin);

								tPlayer.iAttackMin += tLvUpTable[ijobindex].iAttackMin;
								tPlayer.iAttackMax += tLvUpTable[ijobindex].iAttackMax;
								tPlayer.iArmorMax += tLvUpTable[ijobindex].iArmorMax;
								tPlayer.iArmorMin += tLvUpTable[ijobindex].iArmorMin;

								tPlayer.iHpMax += hpup;
								tPlayer.iMPMax += mpup;

								//체력과 마나를 회복 시킨다.
								tPlayer.iHp = tPlayer.iHpMax;
								tPlayer.iMP = tPlayer.iMPMax;
							}
							system("pause");
							break;
						}

						//몬스터가 살아있다면 몬스터가 공격
						iattack = rand() % ((tMonster.iAttackMax - tMonster.iAttackMin + 1) + tMonster.iAttackMin);

						int iarmorkmin = tPlayer.iArmorMin;
						int iarmormax = tPlayer.iArmorMax;

						if (tPlayer.bEquip[EQ_ARMOR])
						{
							iattackmin += tPlayer.tEquip[EQ_ARMOR].iMin;
							iattackmax += tPlayer.tEquip[EQ_ARMOR].iMax;
						}
						iarmor = rand() % ((iattackmax - iattackmin + 1) + iattackmin);
						idamage = iattack - iarmor;

						idamage = idamage <= 0 ? 0 : idamage;

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
			while (true)
			{
				system("cls");
				cout << "******맵******" << endl;
				cout << "1. 무기 상점" << endl;
				cout << "2. 방어구 상점" << endl;
				cout << "3. 뒤로가기" << endl;
				cout << "상점을 선택하세요 : ";
				int imenu;
				cin >> imenu;
				system("cls");
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else if (imenu == SM_BACK)
				{
					break;
				}

				switch (imenu)
				{
				case SM_WEAPON:
					while (true)
					{
						system("cls");
						cout << "****** 무기 상점 ******" << endl;

						for (size_t i = 0; i < STORE_WEAPON_MAX; i++)
						{
							cout << i + 1 << ". 이름 : " << tStoreWeapon[i].strName << "\t 종류 : " << tStoreWeapon[i].strTypeName << endl;
							cout << "공격력 : " << tStoreWeapon[i].iMin << " - " << tStoreWeapon[i].iMax << endl;
							cout << "판매가격 : " << tStoreWeapon[i].iPrice << "\t구매가격 : " << tStoreWeapon[i].iSell << endl;
							cout << "설명 : " << tStoreWeapon[i].strDesc << endl << endl;
						}

						cout << STORE_WEAPON_MAX + 1 << ". 뒤로가기" << endl;
						cout << "보유금액 : " << tPlayer.tInventory.iGold << " GOLD" << endl;
						cout << "남은 공간 : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
						cout << "구입할 아이템을 선택하세요 : ";
						cin >> imenu;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}
						else if (imenu == STORE_WEAPON_MAX + 1)
						{
							break;
						}
						else if (imenu < 1 || imenu > STORE_WEAPON_MAX + 1)
						{
							cout << "잘못 선택하였습니다." << endl;
							system("pause");
							continue;
						}

						//상점 판매목록 배열의 인덱스를 구해준다
						int iWeaponIndex = imenu - 1;

						//인벤토리가 꽉 찼는지 검사
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "가방이 꽉 찼습니다." << endl;
							system("pause");
							continue;
						}

						//돈이 부족할 경우
						else if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponIndex].iPrice)
						{
							cout << "보유 금액이 부족합니다." << endl;
							system("pause");
							continue;
						}

						// 처음에 iItemCount는 하나도 추가되어 있지 않기 때문에 0으로 초기화 되어 있으므로 0번 인덱스에 구매한 아이템을 추가하게 된다. 그리고 카운트가 1이 된다.
						//다음번에 추가할때는 1번 인덱스에 추가하게 된다.
						tPlayer.tInventory.titem[tPlayer.tInventory.iItemCount] = tStoreWeapon[iWeaponIndex];
						++tPlayer.tInventory.iItemCount;

						//골드 차감
						tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponIndex].iPrice;

						cout << tStoreWeapon[iWeaponIndex].strName << " 아이템을 구매하였습니다." << endl;
						system("pause");
					}
					break;
				case SM_ARMOR:
					while (true)
					{
						system("cls");
						cout << "****** 방어구 상점 ******" << endl;

						for (size_t i = 0; i < STORE_ARMOR_MAX; i++)
						{
							cout << i + 1 << ". 이름 : " << tStoreArmor[i].strName << "\t 종류 : " << tStoreArmor[i].strTypeName << endl;
							cout << "공격력 : " << tStoreArmor[i].iMin << " - " << tStoreArmor[i].iMax << endl;
							cout << "판매가격 : " << tStoreArmor[i].iPrice << "\t구매가격 : " << tStoreArmor[i].iSell << endl;
							cout << "설명 : " << tStoreArmor[i].strDesc << endl << endl;
						}

						cout << STORE_ARMOR_MAX + 1 << ". 뒤로가기" << endl;
						cout << "보유금액 : " << tPlayer.tInventory.iGold << " GOLD" << endl;
						cout << "남은 공간 : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
						cout << "구입할 아이템을 선택하세요 : ";
						cin >> imenu;

						if (cin.fail())
						{
							cin.clear();
							cin.ignore(1024, '\n');
							continue;
						}
						else if (imenu == STORE_ARMOR_MAX + 1)
						{
							break;
						}
						else if (imenu < 1 || imenu > STORE_ARMOR_MAX + 1)
						{
							cout << "잘못 선택하였습니다." << endl;
							system("pause");
							continue;
						}

						//상점 판매목록 배열의 인덱스를 구해준다
						int iarmorindex = imenu - 1;

						//인벤토리가 꽉 찼는지 검사
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "가방이 꽉 찼습니다." << endl;
							system("pause");
							continue;
						}

						//돈이 부족할 경우
						else if (tPlayer.tInventory.iGold < tStoreArmor[iarmorindex].iPrice)
						{
							cout << "보유 금액이 부족합니다." << endl;
							system("pause");
							continue;
						}

						// 처음에 iItemCount는 하나도 추가되어 있지 않기 때문에 0으로 초기화 되어 있으므로 0번 인덱스에 구매한 아이템을 추가하게 된다. 그리고 카운트가 1이 된다.
						//다음번에 추가할때는 1번 인덱스에 추가하게 된다.
						tPlayer.tInventory.titem[tPlayer.tInventory.iItemCount] = tStoreArmor[iarmorindex];
						++tPlayer.tInventory.iItemCount;

						//골드 차감
						tPlayer.tInventory.iGold -= tStoreArmor[iarmorindex].iPrice;

						cout << tStoreArmor[iarmorindex].strName << " 아이템을 구매하였습니다." << endl;
						system("pause");
					}
					break;
				}
			}
			break;
		case MM_INVENTORY:
			while (true)
			{
				system("cls");
				cout << "****** 정보 ******" << endl;
				cout << "이름 : " << tPlayer.strName << "\t직업 : " << tPlayer.strJobNAME << endl;
				cout << "레벨 : " << tPlayer.iLevel << "\t경험치 : " << tPlayer.iExp << endl;


				//무기를 장착하고 이씅ㄹ 경우 공격력에 무기공격력을 추가하여 출력
				if (tPlayer.bEquip[EQ_WEAPON] == true)
				{
					cout << "공격력 : " << tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin << " - " << tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax << endl;
				}
				else
				{
					cout << "공격력 : " << tPlayer.iAttackMin << " /  " << tPlayer.iAttackMax << endl;
				}

				//방어구 장착 시 
				if (tPlayer.bEquip[EQ_ARMOR] == true)
				{
					cout << "방어력 : " << tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin << " - " << tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
				}
				else
				{
					cout << "방어력 : " << tPlayer.iArmorMin << " /  " << tPlayer.iArmorMax << endl;
				}
				cout << "체력 : " << tPlayer.iHp << " / " << tPlayer.iHpMax << endl;
				cout << "마나 : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;

				if (tPlayer.bEquip[EQ_WEAPON])
				{
					cout << "장착 무기 : " << tPlayer.tEquip[EQ_WEAPON].strName << endl;
				}
				else
				{
					cout << "장착 무기 : 없음" << endl;
				}

				if (tPlayer.bEquip[EQ_ARMOR])
				{
					cout << "장착 방어구 : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;
				}
				else
				{
					cout << "장착 방어구 : 없음" << endl;
				}

				cout << "보유 골드 : " << tPlayer.tInventory.iGold << endl;

				cout << "****** 가방 ******" << endl;
				for (int i = 0; i < tPlayer.tInventory.iItemCount; i++)
				{
					cout << i + 1 << ". 이름 : " << tPlayer.tInventory.titem[i].strName << "\t 종류 : " << tPlayer.tInventory.titem[i].strTypeName << endl;
					cout << "공격력 : " << tPlayer.tInventory.titem[i].iMin << " - " << tPlayer.tInventory.titem[i].iMax << endl;
					cout << "판매가격 : " << tPlayer.tInventory.titem[i].iPrice << "\t구매가격 : " << tPlayer.tInventory.titem[i].iSell << endl;
					cout << "설명 : " << tPlayer.tInventory.titem[i].strDesc << endl << endl;
				}

				cout << tPlayer.tInventory.iItemCount + 1 << ". 뒤로가기" << endl;
				cout << "장착할 아이템을 선택하세요 : ";

				int iInven;
				cin >> iInven;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(1024, '\n');
					continue;
				}
				else if (iInven == tPlayer.tInventory.iItemCount + 1)
				{
					break;
				}
				else if (iInven < 1 || iInven > tPlayer.tInventory.iItemCount + 1)
				{
					cout << "잘못 선택하였습니다." << endl;
					system("pause");
					continue;
				}

				//아이템 인덱스를 구해준다.
				int idx = iInven - 1;

				//제대로 선택했을 경우 아이템의 종류에 따라 장착 부위를 결정하게 한다.
				EQUIP eq;
				switch (tPlayer.tInventory.titem[idx].eType)
				{
				case IT_WEAPON:
					eq = EQ_WEAPON;
					break;
				case IT_ARMOR:
					eq = EQ_ARMOR;
					break;
				}

				// 아이템이 장착되어 있을 경우 장착되어 있는 아이템과 장착할 아이템을 교체해 주어야한다.
				//Swap 알고리즘 활용
				if (tPlayer.bEquip[eq] == true)
				{
					_tagItem tSwap = tPlayer.tEquip[eq];
					tPlayer.tEquip[eq] = tPlayer.tInventory.titem[idx];
					tPlayer.tInventory.titem[idx] = tSwap;
				}
				//장착되어 있지 않을 경우 인벤토리 아이템을 장착창으로 옮기고
				//인벤토리는 1칸 비워진다
				else
				{
					tPlayer.tEquip[eq] = tPlayer.tInventory.titem[idx];

					for (int i = idx; i < tPlayer.tInventory.iItemCount - 1; i++)
					{
						tPlayer.tInventory.titem[i] = tPlayer.tInventory.titem[i + 1];
					}
					--tPlayer.tInventory.iItemCount;

					//장착 했기 때문에 true로 변경
					tPlayer.bEquip[eq] = true;
				}
				cout << tPlayer.tEquip[eq].strName << " 아이템을 장착 하였습니다." << endl;
				system("pause");
			}

			break;
		default:
			break;
		}
	}
	return 0;
}
