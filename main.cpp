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
	//���� �����Ҷ� �÷��̾� ���� ����

	//�������� �ʿ��� ����ġ ���
	const int iLevelUpEXP[LEVEL_MAX] = { 1000,2000,3000,4000, 5000,6000,7000,8000,9000,10000 };

	//Job_End�� 4�̴� �׷��� ������ 3���̹Ƿ� -1�� ���־� �� �������� �����ϵ��� ��
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
		cout << "������ �����ϼ��� : ";
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

		//���� �̸�
		tPlayer.eJob = (JOB)iJob;
		tPlayer.iLevel = 1;
		tPlayer.iExp = 0;
		tPlayer.tInventory.iGold = 10000;


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
	}

	//���� ����
	_tagMonster tMonsterArr[MT_BACK - 1] = {};

	//��� ����
	strcpy_s(tMonsterArr[0].strName, "���");
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

	//Ʈ�� ����
	strcpy_s(tMonsterArr[1].strName, "Ʈ��");
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

	//�巡�� ����
	strcpy_s(tMonsterArr[2].strName, "�巡��");
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

	//������ �Ǹ��� ������ ��� ����
	_tagItem tStoreWeapon[STORE_WEAPON_MAX] = {};
	_tagItem tStoreArmor[STORE_WEAPON_MAX] = {};

	//�� ������ ���� ����
	tStoreWeapon[0].eType = IT_WEAPON;
	strcpy_s(tStoreWeapon[0].strTypeName, "����");
	strcpy_s(tStoreWeapon[0].strName, "���");
	strcpy_s(tStoreWeapon[0].strDesc, "������ ���� ��");
	tStoreWeapon[0].iMin = 5;
	tStoreWeapon[0].iMax = 10;
	tStoreWeapon[0].iPrice = 1000;
	tStoreWeapon[0].iSell = 500;

	tStoreWeapon[1].eType = IT_WEAPON;
	strcpy_s(tStoreWeapon[1].strTypeName, "����");
	strcpy_s(tStoreWeapon[1].strName, "ö��");
	strcpy_s(tStoreWeapon[1].strDesc, "ö�� ���� ��");
	tStoreWeapon[1].iMin = 20;
	tStoreWeapon[1].iMax = 30;
	tStoreWeapon[1].iPrice = 5000;
	tStoreWeapon[1].iSell = 4000;

	tStoreWeapon[2].eType = IT_WEAPON;
	strcpy_s(tStoreWeapon[2].strTypeName, "����");
	strcpy_s(tStoreWeapon[2].strName, "Ȳ�ݰ�");
	strcpy_s(tStoreWeapon[2].strDesc, "Ȳ������ ���� ��");
	tStoreWeapon[2].iMin = 50;
	tStoreWeapon[2].iMax = 100;
	tStoreWeapon[2].iPrice = 15000;
	tStoreWeapon[2].iSell = 10000;

	//��
	tStoreArmor[0].eType = IT_ARMOR;
	strcpy_s(tStoreArmor[0].strTypeName, "��");
	strcpy_s(tStoreArmor[0].strName, "���� ����");
	strcpy_s(tStoreArmor[0].strDesc, "������ ���� ����");
	tStoreArmor[0].iMin = 5;
	tStoreArmor[0].iMax = 10;
	tStoreArmor[0].iPrice = 1000;
	tStoreArmor[0].iSell = 500;

	tStoreArmor[1].eType = IT_ARMOR;
	strcpy_s(tStoreArmor[1].strTypeName, "��");
	strcpy_s(tStoreArmor[1].strName, "ö ����");
	strcpy_s(tStoreArmor[1].strDesc, "ö�� ���� ����");
	tStoreArmor[1].iMin = 20;
	tStoreArmor[1].iMax = 30;
	tStoreArmor[1].iPrice = 5000;
	tStoreArmor[1].iSell = 4000;

	tStoreArmor[2].eType = IT_ARMOR;
	strcpy_s(tStoreArmor[2].strTypeName, "��");
	strcpy_s(tStoreArmor[2].strName, "Ȳ�� ����");
	strcpy_s(tStoreArmor[2].strDesc, "Ȳ������ ���� ����");
	tStoreArmor[2].iMin = 50;
	tStoreArmor[2].iMax = 100;
	tStoreArmor[2].iPrice = 15000;
	tStoreArmor[2].iSell = 10000;


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
				else if (imenu == MT_BACK)
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

					//�÷��̾� ����
					cout << "********* Player *********" << endl;
					cout << "�̸� : " << tPlayer.strName << "\t���� : " << tPlayer.strJobNAME << endl;
					cout << "���� : " << tPlayer.iLevel << "\t����ġ : " << tPlayer.iExp << " / " << iLevelUpEXP[tPlayer.iLevel - 1] << endl;
					//���⸦ �����ϰ� �̝��� ��� ���ݷ¿� ������ݷ��� �߰��Ͽ� ���
					if (tPlayer.bEquip[EQ_WEAPON] == true)
					{
						cout << "���ݷ� : " << tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin << " - " << tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax << endl;
					}
					else
					{
						cout << "���ݷ� : " << tPlayer.iAttackMin << " /  " << tPlayer.iAttackMax << endl;
					}

					//�� ���� �� 
					if (tPlayer.bEquip[EQ_ARMOR] == true)
					{
						cout << "���� : " << tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin << " - " << tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
					}
					else
					{
						cout << "���� : " << tPlayer.iArmorMin << " /  " << tPlayer.iArmorMax << endl;
					}
					cout << "ü�� : " << tPlayer.iHp << " / " << tPlayer.iHpMax << endl;
					cout << "���� : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;
					cout << "���� ��� : " << tPlayer.tInventory.iGold << endl;

					//���� ���� ���
					cout << "********* Monster *********" << endl;
					cout << "�̸� : " << tMonster.strName << endl;
					cout << "���� : " << tMonster.iLevel << "\tȹ�� ����ġ : " << tMonster.iExp << endl;
					cout << "���ݷ� : " << tMonster.iAttackMax << " /  " << tMonster.iAttackMax << endl;
					cout << "���� : " << tMonster.iArmorMax << " / " << tMonster.iArmorMax << endl;
					cout << "ü�� : " << tMonster.iHp << " / " << tMonster.iHpMax << endl;
					cout << "���� : " << tMonster.iMP << " / " << tMonster.iMPMax << endl;
					cout << "���� ��� : " << tMonster.iGoleMin << " / " << tMonster.iGoleMax << endl;

					cout << "1. ����" << endl;
					cout << "2. ��������" << endl;
					cout << "�޴��� ������ �ּ��� : ";
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

						//�÷��̾ ����
						// ������� min 5 Max15 �� ���
						// 15 - 5 + 1���ϸ� 11�� ��
						// 11�� ���� �������� 0~10�� �ǰ� ���⿡ min���� 5�� ���ϰ� �Ǹ� 5~15���̷� ���� ������ ��
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

						//���׿����� : ���ǽ� ? true�϶��� : flase�϶� ��
						idamage = idamage < 1 ? 1 : idamage;

						//���� hp�� ���ҽ�Ų��
						tMonster.iHp -= idamage;

						cout << tPlayer.strName << " �� " << tMonster.strName << " ���� " << idamage << " ���ظ� �������ϴ�. " << endl;

						//���Ͱ� �׾��� ���
						if (tMonster.iHp <= 0)
						{
							cout << tMonster.strName << " ���Ͱ� ����Ͽ����ϴ�." << endl;
							tPlayer.iExp += tMonster.iExp;
							int igold = rand() % ((tMonster.iGoleMax - tMonster.iGoleMin + 1) + tMonster.iGoleMin);
							tPlayer.tInventory.iGold += igold;

							//���� �ٽ� ��Ȱ
							tMonster.iHp = tMonster.iHpMax;
							tMonster.iMP = tMonster.iMPMax;

							cout << tMonster.iExp << " ����ġ�� ȹ���Ͽ����ϴ�. " << endl;
							cout << igold << " ��带 ȹ���Ͽ����ϴ�." << endl;

							//�������� �ߴ��� üũ
							if (tPlayer.iExp >= iLevelUpEXP[tPlayer.iLevel - 1])
							{
								//�������� �ʿ��� ��ŭ�� ����
								tPlayer.iExp -= iLevelUpEXP[tPlayer.iLevel - 1];

								//������ ó��
								++tPlayer.iLevel;
								cout << "������ �ϼ̽��ϴ�!" << endl;

								//�ɷ�ġ ���
								int ijobindex = tPlayer.eJob - 1;
								int hpup = rand() % ((tLvUpTable[ijobindex].iHpMax - tLvUpTable[ijobindex].iHpMin + 1) + tLvUpTable[ijobindex].iHpMin);
								int mpup = rand() % ((tLvUpTable[ijobindex].iMpMax - tLvUpTable[ijobindex].iMpMin + 1) + tLvUpTable[ijobindex].iMpMin);

								tPlayer.iAttackMin += tLvUpTable[ijobindex].iAttackMin;
								tPlayer.iAttackMax += tLvUpTable[ijobindex].iAttackMax;
								tPlayer.iArmorMax += tLvUpTable[ijobindex].iArmorMax;
								tPlayer.iArmorMin += tLvUpTable[ijobindex].iArmorMin;

								tPlayer.iHpMax += hpup;
								tPlayer.iMPMax += mpup;

								//ü�°� ������ ȸ�� ��Ų��.
								tPlayer.iHp = tPlayer.iHpMax;
								tPlayer.iMP = tPlayer.iMPMax;
							}
							system("pause");
							break;
						}

						//���Ͱ� ����ִٸ� ���Ͱ� ����
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

						//�÷��̾� ������ ����
						tPlayer.iHp -= idamage;

						cout << tMonster.strName << " �� " << tPlayer.strName << " ���� " << idamage << " ���ظ� �������ϴ�. " << endl;

						//���Ͱ� �׾��� ���
						if (tPlayer.iHp <= 0)
						{
							cout << tPlayer.strName << " �÷��̾ ����Ͽ����ϴ�." << endl;
							int iexp = tPlayer.iExp * 0.1f;
							int igold = tPlayer.tInventory.iGold * 0.1f;
							tPlayer.iExp -= iexp;
							tPlayer.tInventory.iGold -= igold;

							cout << iexp << " ����ġ�� �Ҿ����ϴ�. " << endl;
							cout << igold << " ��带 �Ҿ����ϴ�." << endl;

							//�÷��̾��� hp�� mp�� ȸ���Ѵ�
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
				cout << "******��******" << endl;
				cout << "1. ���� ����" << endl;
				cout << "2. �� ����" << endl;
				cout << "3. �ڷΰ���" << endl;
				cout << "������ �����ϼ��� : ";
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
						cout << "****** ���� ���� ******" << endl;

						for (size_t i = 0; i < STORE_WEAPON_MAX; i++)
						{
							cout << i + 1 << ". �̸� : " << tStoreWeapon[i].strName << "\t ���� : " << tStoreWeapon[i].strTypeName << endl;
							cout << "���ݷ� : " << tStoreWeapon[i].iMin << " - " << tStoreWeapon[i].iMax << endl;
							cout << "�ǸŰ��� : " << tStoreWeapon[i].iPrice << "\t���Ű��� : " << tStoreWeapon[i].iSell << endl;
							cout << "���� : " << tStoreWeapon[i].strDesc << endl << endl;
						}

						cout << STORE_WEAPON_MAX + 1 << ". �ڷΰ���" << endl;
						cout << "�����ݾ� : " << tPlayer.tInventory.iGold << " GOLD" << endl;
						cout << "���� ���� : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
						cout << "������ �������� �����ϼ��� : ";
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
							cout << "�߸� �����Ͽ����ϴ�." << endl;
							system("pause");
							continue;
						}

						//���� �ǸŸ�� �迭�� �ε����� �����ش�
						int iWeaponIndex = imenu - 1;

						//�κ��丮�� �� á���� �˻�
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "������ �� á���ϴ�." << endl;
							system("pause");
							continue;
						}

						//���� ������ ���
						else if (tPlayer.tInventory.iGold < tStoreWeapon[iWeaponIndex].iPrice)
						{
							cout << "���� �ݾ��� �����մϴ�." << endl;
							system("pause");
							continue;
						}

						// ó���� iItemCount�� �ϳ��� �߰��Ǿ� ���� �ʱ� ������ 0���� �ʱ�ȭ �Ǿ� �����Ƿ� 0�� �ε����� ������ �������� �߰��ϰ� �ȴ�. �׸��� ī��Ʈ�� 1�� �ȴ�.
						//�������� �߰��Ҷ��� 1�� �ε����� �߰��ϰ� �ȴ�.
						tPlayer.tInventory.titem[tPlayer.tInventory.iItemCount] = tStoreWeapon[iWeaponIndex];
						++tPlayer.tInventory.iItemCount;

						//��� ����
						tPlayer.tInventory.iGold -= tStoreWeapon[iWeaponIndex].iPrice;

						cout << tStoreWeapon[iWeaponIndex].strName << " �������� �����Ͽ����ϴ�." << endl;
						system("pause");
					}
					break;
				case SM_ARMOR:
					while (true)
					{
						system("cls");
						cout << "****** �� ���� ******" << endl;

						for (size_t i = 0; i < STORE_ARMOR_MAX; i++)
						{
							cout << i + 1 << ". �̸� : " << tStoreArmor[i].strName << "\t ���� : " << tStoreArmor[i].strTypeName << endl;
							cout << "���ݷ� : " << tStoreArmor[i].iMin << " - " << tStoreArmor[i].iMax << endl;
							cout << "�ǸŰ��� : " << tStoreArmor[i].iPrice << "\t���Ű��� : " << tStoreArmor[i].iSell << endl;
							cout << "���� : " << tStoreArmor[i].strDesc << endl << endl;
						}

						cout << STORE_ARMOR_MAX + 1 << ". �ڷΰ���" << endl;
						cout << "�����ݾ� : " << tPlayer.tInventory.iGold << " GOLD" << endl;
						cout << "���� ���� : " << INVENTORY_MAX - tPlayer.tInventory.iItemCount << endl;
						cout << "������ �������� �����ϼ��� : ";
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
							cout << "�߸� �����Ͽ����ϴ�." << endl;
							system("pause");
							continue;
						}

						//���� �ǸŸ�� �迭�� �ε����� �����ش�
						int iarmorindex = imenu - 1;

						//�κ��丮�� �� á���� �˻�
						if (tPlayer.tInventory.iItemCount == INVENTORY_MAX)
						{
							cout << "������ �� á���ϴ�." << endl;
							system("pause");
							continue;
						}

						//���� ������ ���
						else if (tPlayer.tInventory.iGold < tStoreArmor[iarmorindex].iPrice)
						{
							cout << "���� �ݾ��� �����մϴ�." << endl;
							system("pause");
							continue;
						}

						// ó���� iItemCount�� �ϳ��� �߰��Ǿ� ���� �ʱ� ������ 0���� �ʱ�ȭ �Ǿ� �����Ƿ� 0�� �ε����� ������ �������� �߰��ϰ� �ȴ�. �׸��� ī��Ʈ�� 1�� �ȴ�.
						//�������� �߰��Ҷ��� 1�� �ε����� �߰��ϰ� �ȴ�.
						tPlayer.tInventory.titem[tPlayer.tInventory.iItemCount] = tStoreArmor[iarmorindex];
						++tPlayer.tInventory.iItemCount;

						//��� ����
						tPlayer.tInventory.iGold -= tStoreArmor[iarmorindex].iPrice;

						cout << tStoreArmor[iarmorindex].strName << " �������� �����Ͽ����ϴ�." << endl;
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
				cout << "****** ���� ******" << endl;
				cout << "�̸� : " << tPlayer.strName << "\t���� : " << tPlayer.strJobNAME << endl;
				cout << "���� : " << tPlayer.iLevel << "\t����ġ : " << tPlayer.iExp << endl;


				//���⸦ �����ϰ� �̝��� ��� ���ݷ¿� ������ݷ��� �߰��Ͽ� ���
				if (tPlayer.bEquip[EQ_WEAPON] == true)
				{
					cout << "���ݷ� : " << tPlayer.iAttackMin << " + " << tPlayer.tEquip[EQ_WEAPON].iMin << " - " << tPlayer.iAttackMax << " + " << tPlayer.tEquip[EQ_WEAPON].iMax << endl;
				}
				else
				{
					cout << "���ݷ� : " << tPlayer.iAttackMin << " /  " << tPlayer.iAttackMax << endl;
				}

				//�� ���� �� 
				if (tPlayer.bEquip[EQ_ARMOR] == true)
				{
					cout << "���� : " << tPlayer.iArmorMin << " + " << tPlayer.tEquip[EQ_ARMOR].iMin << " - " << tPlayer.iArmorMax << " + " << tPlayer.tEquip[EQ_ARMOR].iMax << endl;
				}
				else
				{
					cout << "���� : " << tPlayer.iArmorMin << " /  " << tPlayer.iArmorMax << endl;
				}
				cout << "ü�� : " << tPlayer.iHp << " / " << tPlayer.iHpMax << endl;
				cout << "���� : " << tPlayer.iMP << " / " << tPlayer.iMPMax << endl;

				if (tPlayer.bEquip[EQ_WEAPON])
				{
					cout << "���� ���� : " << tPlayer.tEquip[EQ_WEAPON].strName << endl;
				}
				else
				{
					cout << "���� ���� : ����" << endl;
				}

				if (tPlayer.bEquip[EQ_ARMOR])
				{
					cout << "���� �� : " << tPlayer.tEquip[EQ_ARMOR].strName << endl;
				}
				else
				{
					cout << "���� �� : ����" << endl;
				}

				cout << "���� ��� : " << tPlayer.tInventory.iGold << endl;

				cout << "****** ���� ******" << endl;
				for (int i = 0; i < tPlayer.tInventory.iItemCount; i++)
				{
					cout << i + 1 << ". �̸� : " << tPlayer.tInventory.titem[i].strName << "\t ���� : " << tPlayer.tInventory.titem[i].strTypeName << endl;
					cout << "���ݷ� : " << tPlayer.tInventory.titem[i].iMin << " - " << tPlayer.tInventory.titem[i].iMax << endl;
					cout << "�ǸŰ��� : " << tPlayer.tInventory.titem[i].iPrice << "\t���Ű��� : " << tPlayer.tInventory.titem[i].iSell << endl;
					cout << "���� : " << tPlayer.tInventory.titem[i].strDesc << endl << endl;
				}

				cout << tPlayer.tInventory.iItemCount + 1 << ". �ڷΰ���" << endl;
				cout << "������ �������� �����ϼ��� : ";

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
					cout << "�߸� �����Ͽ����ϴ�." << endl;
					system("pause");
					continue;
				}

				//������ �ε����� �����ش�.
				int idx = iInven - 1;

				//����� �������� ��� �������� ������ ���� ���� ������ �����ϰ� �Ѵ�.
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

				// �������� �����Ǿ� ���� ��� �����Ǿ� �ִ� �����۰� ������ �������� ��ü�� �־���Ѵ�.
				//Swap �˰��� Ȱ��
				if (tPlayer.bEquip[eq] == true)
				{
					_tagItem tSwap = tPlayer.tEquip[eq];
					tPlayer.tEquip[eq] = tPlayer.tInventory.titem[idx];
					tPlayer.tInventory.titem[idx] = tSwap;
				}
				//�����Ǿ� ���� ���� ��� �κ��丮 �������� ����â���� �ű��
				//�κ��丮�� 1ĭ �������
				else
				{
					tPlayer.tEquip[eq] = tPlayer.tInventory.titem[idx];

					for (int i = idx; i < tPlayer.tInventory.iItemCount - 1; i++)
					{
						tPlayer.tInventory.titem[i] = tPlayer.tInventory.titem[i + 1];
					}
					--tPlayer.tInventory.iItemCount;

					//���� �߱� ������ true�� ����
					tPlayer.bEquip[eq] = true;
				}
				cout << tPlayer.tEquip[eq].strName << " �������� ���� �Ͽ����ϴ�." << endl;
				system("pause");
			}

			break;
		default:
			break;
		}
	}
	return 0;
}
