#include <iostream>

using namespace std;


struct _tagStudent
{
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main()
{
	//������ : ����Ű�� ��
	//�ּҸ� ����Ű�� ����
	//�Ϲ� ������ ���� �����ϴ� ����
	//�����ʹ� �ּҸ� �����ϴ� ����
	//��� ���� Ÿ���� ������ Ÿ�� ������ ����
	//�����ʹ� �޸� �ּҸ� ��Ƴ��� �����̱� ������ x86���� ������ �� ������ 4byte, x64�� ������ �� 8byte�� ����


	//�����ʹ� �ڱ� ������ �ƹ��� ���� �Ҽ� ����, �ݵ�� �ٸ� ������ �޸� �ּҸ� ������ �־�� ���� �� �� �ִ�.
	//�޸� �ּҿ� ������ ���� ������ �� ����

	//���� : ����Ÿ�� *������ �� ���·� ����

	//�Ϲ� ����
	int iInt = 10;
	//������ ����, &�� �ּҸ� �������� ������
	//pInt�� &iInt�� �������ν� �ּҸ� ����Ű�� ������ ������ �Ǿ���
	int* pInt = &iInt;


	cout << "�ѤѤѤѤѤѤѤѤѤѤѸ޸� Ȯ��" << endl;
	cout << sizeof(int*) << endl; //x84���� 4byte | x64���� 8byte
	cout << sizeof(char*) << endl; //x84���� 4byte | x64���� 8byte
	cout << sizeof(double) << endl; //x84���� 8byte | x64���� 8byte
	cout << sizeof(double*) << endl; //x84���� 4byte | x64���� 8byte

	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѤ��ּ� �� �� Ȯ��" << endl;
	cout << "iInt �ּ� : " << &iInt << endl; //iInt�� �ּ�
	cout << "iInt �� : " << iInt << endl; //iInt�� ��
	cout << "pInt �ּ� : " << &pInt << endl; //iInt�� �ּ�
	cout << "pInt �� : " << pInt << endl; //iInt�� ��
	cout << "pInt �� : " << *pInt << endl; //iInt�� ��


	//pInt�� �̿��� iInt�� ���� ����
	//�������� �̿��� ���� �����ų� ���� ����
	//�������� ������ �տ� *�� �ٿ��ָ� ��
	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѺ��� �� �ּ� �� �� Ȯ��" << endl;
	*pInt = 20;
	cout << "iInt �ּ� : " << &iInt << endl; //iInt�� �ּ�
	cout << "iInt �� : " << iInt << endl; //iInt�� ��
	cout << "pInt �ּ� : " << &pInt << endl; //iInt�� �ּ�
	cout << "pInt �� : " << pInt << endl; //iInt�� ��
	cout << "pInt �� : " << *pInt << endl; //iInt�� ��

	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѹ迭 : " << endl;
	// �����Ϳ� �迭�� ���� : �迭���� �� �����ʹ�.
	// �迭���� �迭�� ù��° �ּҸ� ����Ű�� �ִ�.
	int iArr[5] = { 1,2,3,4,5 };
	cout << "iArr �ּ� : " << iArr << endl; //iArr�� �ּ�
	cout << "iArr[0] �ּ� : " << &iArr[0] << endl; //iArr�� �ּ�

	//iArr���� pArray��� ������ ������ ���� iArr�� �ּҸ� ����Ű�� ����
	//pArray�� iArr�� �ּҸ� ����Ű�� ����
	//iArr�� �迭�� ������ �����ϵ��� pArray�ε� �迭�� ������ ������ �ֳ��ϸ� �迭�� �� �ּ��̱� ����
	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѰ� ���� : " << endl;
	int* pArray = iArr;
	pArray[2] = 100;
	cout << "pArray[2] : " << pArray[2] << endl; //100
	cout << "iArr[2] : " << iArr[2] << endl; //100

	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѤ������� ���� : " << endl;
	//������ ���� : +, - ������ �����ϸ�, ++, --�� �����ѵ� 1�� �����ϰ� �Ǹ� �ܼ��� �޸� �ּ� ���� 1 �����ϴ� ���� �ƴ� ����Ű�� ������ Ÿ���� ���� Ÿ�� ũ�⸸ŭ �����ϰ� ��
	//int�������� ��� 4byte, char�������� ��� 1byte, double�������� ��� 8byte�� �����ϰ� ��
	cout << "pArray       :" << pArray << endl; //iArr�� �ּ�
	cout << "pArray + 2   :" << pArray + 2 << endl; //iArr�� �ּ�
	cout << "*pArray      :" << *pArray << endl; //iArr�� �ּ�
	cout << "*(pArray +2) :" << *(pArray + 2) << endl; //iArr�� �ּ�


	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѤ�char ������: " << endl;
	//const�� �ٲٸ� ���ڿ��� ������ �� ���� 
	// ���� �ٲٸ� �޸� �ּҰ� �ٲ�
	const char* pText = "text";
	cout << "pText �ּ� : " << (int*)pText << endl; //pText�� �ּ�
	pText = "texts";
	cout << "pText �ּ� : " << (int*)pText << endl; //pText�� �ּ�
	pText = "texts";
	cout << "pText �ּ� : " << (int*)pText << endl; //pText�� �ּ�
	pText = "textsss";
	cout << "pText �ּ� : " << (int*)pText << endl; //pText�� �ּ�
	
	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѱ���ü ������: " << endl;
	_tagStudent student = {};
	student.iKor = 100;
	cout << "student.iKor : " << student.iKor << endl; //100


	_tagStudent* pStudent = &student;
	// ������ �켱���� ������ .�� ���� �ν���
	//�޸� �ּ� .�� �߸��� �����̸� *pStudent�� ��ȣ�� ������ �� 
	// .�� �̿��� ����ũ�� ����� �ɹ������� �����ؾ���
	(*pStudent).iKor = 50;
	cout << "student.iKor : " << student.iKor << endl; //50

	// ->�� �̿��� ����Ű�� ����� �ɹ��� ���� ����
	pStudent->iKor = 80;
	cout << "student.iKor : " << student.iKor << endl; //80

	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѤ�void ������: " << endl;
	// void : Ÿ���� ����.
	// void* ������ �����ϸ� ��� Ÿ���̵� �޸��ּҵ� ����ų �� �ִ�.
	void* pvoid = &iInt;
	cout << "iInt �ּ� : " << &iInt << endl; //iInt�� �ּ�
	cout << "pvoid �ּ� : " << pvoid << endl; //pvoid�� �ּ�

	cout << endl;
	cout << "������ �� iInt �� : " << iInt << endl; //iInt�� �ּ�
	// ��, �������� �Ұ����ϰ� �޸� �ּҸ� ���� ����
	//*pvoid = 10; //������ �Ұ���
	int* pConvefrt = (int*)pvoid; //����ȯ�� ����� ������ ����
	*pConvefrt = 10; //������ ����
	cout << "������ �� iInt �� : " << iInt << endl; //iInt�� �ּ�
	*((int*)pvoid) = 20; //������ ����
	cout << "������ �� iInt �� : " << iInt << endl; //iInt�� �ּ�

	cout << endl;
	pvoid = &pStudent;
	cout << "pStudent �ּ� : " << &pStudent << endl; //pStudent�� �ּ�
	cout << "pvoid �ּ� : " << pvoid << endl; //pvoid�� �ּ�

	return 0;
}