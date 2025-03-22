// '#'�� �� �ִ� ���� ��ó����� ǥ���ϸ� 
// iosteam : ������� ���̺귯�� ��ɵ��� ��� �ִ�.
// #include : ��������� ���⿡ ���Խ�Ű�� ���
#include<iostream>
#include<time.h>

//using namespace�� �̿��Ͽ� std�� ���� ����
using namespace std;

enum NUM
{
	//�ƹ��͵� �ο����� ���� ��� 0���� ����
	NUM_0,
	NUM_1,
	NUM_2,
	NUM_3,
	NUM_4,
	NUM_5,
	NUM_6,
	NUM_7,
	NUM_8,
	NUM_9,
	NUM_10
};

#define NUM_11 11

// ���� ���� : ������ -> ���� -> ����
// ������ : ���� �۾�(�ҽ��ڵ带 ����(������ ���)�� ��ȯ)
// ���� : �����ϵ� ������ �������Ϸ� ��ȯ
// ���� : ���������� ����
// Ctrl + Shift + B : ������ �� ���� ����

// C++�� �������� main �Լ��̴�. main �Լ��� �ݵ�� �־�� ��
int main()
{
	//C++ ǥ�� ����� ��κ��� std��� namespace �ȿ� ����, �̸��� ��ġ�� ���� ����
	//cout : �ܼ�â�� ������ִ� ���, "" �ȿ� �ִ� ���ڿ��� ȭ�鿡 ���
	std::cout << "Test Output";

	//<< std::endl : ����(�ٹٲ�)
	std::cout << "Hello World" << std::endl;

	//using namespace std�� �̿��� std�� ���� ����
	cout << "Test Output" << std::endl;

	//���� ������
	cout << ("10 < 20 = ") << (10 < 20) << endl;
	cout << ("10 <- 20 = ") << (10 <= 20) << endl;
	cout << ("10 > 20 = ") << (10 > 20) << endl;
	cout << ("10 >= 20 = ") << (10 >= 20) << endl;
	cout << ("10 == 20 = ") << (10 == 20) << endl;
	cout << ("10 != 20 = ") << (10 != 20) << endl;

	//cin�� �Է��� �޾� �־��ִ� ����
	cout << "���ڸ� �Է����ּ��� : ";
	int Number;
	cin >> Number;

	//��Ʈ ������
	cout << "10 ~ 20 = " << (10 <= Number && Number <= 20) << endl;


	//��Ʈ �� ������ 
	// 
	// �����н� 
	//���� : 2����, 8����, 10����, 16����
	//2���� : 0~1, 
	//8���� : 0~7, 
	//10���� : 0~9, 
	//16���� : 0~9, A~F

	//87�� 2����, 16������ ��ȯ
	// 2���� : 1010111
	// 16���� : 57

	//Q. 87 & 53 = ?
	//	-87 : 1010111
	//	- 53 : 110101
	cout << "87 & 53 = " << (87 & 53) << endl;


	//��� : ������ �ʴ� ��, �ѹ� ���� ���� ������ �ʴ´�
	//����� ����� ���ÿ� ���� �����ؾ���
	//const : ����� ������ �� ����ϴ� Ű����
	const int iAttack = 0x00000001; // 2���� :		 1
	const int iArmor = 0x00000002; // 2���� :		10
	const int iHP = 0x00000004; // 2���� :		   100
	const int iMP = 0x00000008; // 2���� :		  1000
	const int iCritical = 0x00000010; // 2���� : 10000

	// 1 | 100 = 101 | 10000 = 10101
	int iBuf = iAttack | iHP | iCritical;

	// 10101 & 1 = 00001
	cout << "Attack : " << (iBuf & iAttack) << endl;

	//10101 & 10 = 0
	cout << "Armor : " << (iBuf & iArmor) << endl;
	cout << "Mp: " << (iBuf & iMP) << endl;
	cout << "Hp : " << (iBuf & iHP) << endl;
	cout << "Critical : " << (iBuf & iCritical) << endl;

	//������ ����� : �����ڸ� �ٿ��� ����� �� �ִ�.

	// 10101 ^ 100 = 10001
	iBuf ^= iHP; // iBuf = iBuf ^ iHP
	cout << "iBuf : " << iBuf << endl;

	// 10001 ^ 100 = 10101
	// XOR�� �̿��� �����״� ����ġ ���� �͵� ���� 
	iBuf ^= iHP; // iBuf = iBuf ^ iHP
	cout << "iBuf : " << iBuf << endl;

	// 10101 ^ 100 = 10001
	iBuf ^= iHP; // iBuf = iBuf ^ iHP
	cout << "iBuf : " << iBuf << endl;


	//����Ʈ ������ : <<. >>
	//���� ���� �����Ͽ� ������ ������ ��
	//�� ������ ���� ������ ������ ������ �ϰ� ��

	// Q. 20 << 2 = ?
	// 20 : 10100
	// 20 << 2 = 80
	// 20 << 2 : 101 0000
	// 20 << 3 = 160
	// 20 << 3 = 1010 0000
	// 20 << 4 = 320
	// 20 << 4 = 10100 0000

	// ��� ���� 20�� 2�� , 20�� 3��, 20�� 4���� �ȴ�.
	// ����Ʈ �����ڷ� �ϸ� ������ ������ �ȴ�.

	// 20 >> 1 = 10 
	// 20 >> 1 = 10100 >> 1 = 1010
	// 20 >> 2 = 5
	// 20 >> 2 = 10100 >> 2 = 101
	// 20 >> 3 = 2
	// 20 >> 3 = 10100 >> 3 = 10
	// ������� Ȱ���Ѵٸ� ������ ������ �����ϴ�.
	// ������ �̶�� ���� ��ü�� ���ſ� �����̶� ����Ʈ ������ �̿��ϸ� ������ ���� 
	// 20 / 2 ���� 20 * 0.5�� �� ������	20 >> 1�� �� ������.


	int iHght = 187;
	int iLow = 13560;

	int iNumber = iHght;

	//iNumber���� 187�� �� ����, �� ���� << 1 �� �������� �̵� ��Ű��
	// ���� 16��Ʈ�� ���� ���� �ȴ�.
	iNumber <<= 16;

	//���� 16��Ʈ�� ä���
	iNumber |= iLow;

	// High ���� ����Ѵ�
	cout << "High : " << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000FFFF) << endl;
	//F�� ǥ���ϴ� ������ 16������ ǥ���ϱ� ����	


	//�ѤѤѤѤѤѤѤѤѤ�if��
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤ�if��" << endl;

	//�б⹮ ũ�� 2���� if��, switch��
	//if�� : ���ǿ� ���� ���๮�� ����
	// if(����) { ���๮ }
	if (true)
	{
		cout << "True" << endl;
	}

	if (false)
	{
		cout << "False" << endl;
	}

	if ((iBuf & iAttack) != 0)
	{
		cout << "Attack ������ ����" << endl;
	}

	if ((iBuf & iArmor) != 0)
	{
		cout << "Armor ������ ����" << endl;
	}

	//else : if���� ������ �� ����
	//else { ���๮ }
	cout << "�ѤѤѤѤѤѤѤѤѤ�else" << endl;
	if (false)
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "else" << endl;
	}

	//else if : if���� ������ �� �ٽ� ������ �˻�
	//else if(����) { ���๮ }
	cout << "�ѤѤѤѤѤѤѤѤѤ�else if" << endl;
	if (false)
	{
		cout << "True" << endl;
	}
	else if (true)
	{
		cout << "else if" << endl;
	}
	else
	{
		cout << "else" << endl;
	}



	//�ѤѤѤѤѤѤѤѤѤѳ���
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѳ���" << endl;

	// srand�� unsigned int�� �޾Ƶ��̱� ������, time�� unsigned int�� ����ȯ�Ͽ� �����Ѵ�.
	// ����ȯ�̶�? �������� ���¸� �ٲٴ� ��
	// int a = 10; float b = (float)a;
	// time�� �ð��� �޾ƿ��� �Լ�

	//������ �����ϱ� ���� srand�� ���
	//srand�� ������ �����ϱ� ���� �õ尪�� �����ϴ� �Լ�
	//time�� �̿��ϴ� ������ ������ ������ �ٸ� ������ �����ϱ� ����
	srand((unsigned int)time(0));

	//rand�� 0~32767������ ���� ��ȯ�Ѵ�.(�� ���� ����)
	cout << "���� ���� : " << rand() << endl;
	cout << "���� ���� : " << rand() << endl;
	cout << "���� ���� : " << rand() << endl;

	//0~99������ ���� ���� 
	cout << "0~99������ ���� ���� : " << (rand() % 100) << endl;

	//100~200������ ���� ����
	cout << "100~200������ ���� ���� : " << (rand() % 101 + 100) << endl;

	//99.9999������ ���� ����
	cout << "99.9999������ ���� ���� : " << (rand() % 10000 / 100.f) << endl;


	//�ѤѤѤѤѤѤѤѤѤ�Switch��
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤ�Swich��" << endl;

	//switch�� : ���� ���� ���๮�� ����
	//switch(����) { case �� : ���๮ }

	int number = 3;
	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> number;

	//break : switch���� ���������� ����
	//case 3, 4�� �� ���๮�� �����ϰ� break�� ������ switch���� ����������.
	//default : case�� ���� ���� �� ���๮�� ����
	switch(number)
	{
		case 1:
			cout << "1�Դϴ�." << endl;
			break;
		case 2:
			cout << "2�Դϴ�." << endl;
			break;
		case 3:
		case 4:
			cout << "3 �Ǵ� 4�Դϴ�." << endl;
			break;

		default:
			cout << "�� ���� �����Դϴ�." << endl;
			break;
	}

	//�ѤѤѤѤѤѤѤѤѤѿ���ü
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѿ���ü" << endl;

	//����ü : ���ӵ� ���ڿ� �̸��� �ο��� �� �ִ� ���
	//���´� enum : ����ü�� ������ �� ����ϴ� Ű����
	//����ü���� �̿��� ����ü Ÿ���� ������ ���� ����
	//����ü�� ��, ���ڿ� �̸��� �ο��ϴ� ���̴�.

	switch (number)
	{
	case NUM_1:
		cout << "����ü: 1�Դϴ�." << endl;
		break;
	case NUM_2:
		cout << "����ü: 2�Դϴ�." << endl;
		break;
	case NUM_3:
	case NUM_4:
		cout << "����ü: 3 �Ǵ� 4�Դϴ�." << endl;
		break;
	case NUM_11:
		cout << "����ü: 11�Դϴ�." << endl;
		break;
	default:
		cout << "����ü: �� ���� �����Դϴ�." << endl;
		break;
	}

	//����ü Ÿ���� ���� ����
	//����ü Ÿ���� ������ ������ 4byte�� ũ�⸦ ������.
	NUM eNumber = NUM_1;
	cout << "����ü �޸� ũ�� : " << sizeof(eNumber) << endl;
	cout << "������ Ÿ�Ե� �˼� ���� : " << typeid(eNumber).name() << endl;


	//�ѤѤѤѤѤѤѤѤѤѹݺ���
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѹݺ���" << endl;
	//�ݺ��� : ���ǿ� ���� ���๮�� �ݺ�
	//���� : for��, while��, do while��
	//�ݺ����� ���������� ��� : ������ ������ �Ǹ� ���������ų� break�� ������ ��������

	//�ѤѤѤѤѤѤѤѤѤ�while��
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤ�while��" << endl;
	//while�� : ������ ���� �� ���๮�� �ݺ�
	//while(����) { ���๮ }
	number = 0;
	while (number < 10)
	{
		cout << "while�� ������ : " << number << endl;
		number++;

		if (number == 4)
			break;
	}



	return 0;
}

