#include <iostream>

using namespace std;


//����ü 
//- ���� �ִ� �������� ��� �ϳ��� ���ο� Ÿ���� ������ִ� ���

//����
//- struct ����ü�� {}; �� ���·� ���� 

//�迭�� ����ü�� ������ : 
// - ������ �����̴�.
// ���ӵ� �޸� ���� �Ҵ�Ǹ� ����ü �ɹ����� ���ӵ� �޸� ������ ������ �ȴ�.

#define NAME_SIZE 32

struct _tagStudent
{
	char strName[NAME_SIZE];
	int iNumber;
	int iKor;
	int iEng;
	int iMath;
	int iTotal;
	float fAvg;
};

int main()
{
	//������ �ʱ�ȭ ������ ������ ������ ���� ��
	_tagStudent tStudent_s;
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};

	// ����ü �ɹ��� �����Ҷ��� . �� �̿��� ����
	tStudent.iKor = 100;

	//���ڿ��� �迭�� ���� ���� �ܼ� �������� �Ұ���
	//tStudent.strName = "���̸��� �����ϱ�"; X
	// strcpy_s ��� �Լ��� ���ڿ��� ����������ϸ� �����ʿ� �ִ� ���ڿ��� ���ʿ� �������ش�.
	strcpy_s(tStudent.strName, "���̸��� �����ϱ�");
	cout << "�̸� ���� : " << strlen(tStudent.strName) << endl;

	cout << "�ѤѤѤѤѤѤѤ� �ʱ�ȭ ����" << endl;
	cout << "�̸� : " << tStudent.strName << endl;
	cout << "���� : " << tStudent.iKor << endl;
	cout << "���� : " << tStudent.iEng << endl;

	cout << "�ѤѤѤѤѤѤѤ� �ʱ�ȭ ��" << endl;
	cout << "�̸� : " << tStudent.strName << endl;
	cout << "���� : " << tStudent.iKor << endl;
	cout << "���� : " << tStudent.iEng<< endl;


	//���ڿ� ���̴� �Լ�
	cout << "�ѤѤѤѤѤѤѤ� ���ڿ� ���̱�" << endl;
	strcat_s(tStudent.strName, "�ʴ� �ƴ�?");
	cout << "�̸� : " << tStudent.strName << endl;
	cout << "�̸� ���� : " << strlen(tStudent.strName) << endl;

	cout << "�ѤѤѤѤѤѤѤ� ���ڿ� ��" << endl;
	cout << "�л� �̸��� �˻� ���ּ��� : ";
	strcpy_s(tStudent.strName, "�浿��");
	char strName[NAME_SIZE] = {};
	cin >> strName;

	//strcmp ���ڿ� �� �Լ�, ���� ��� 0�� ��ȯ
	if (strcmp(tStudent.strName, strName) == 0)
	{
		cout << "�л� ã��" << endl;
	}
	else
	{
		cout << "�л� ��ã��" << endl;
	}
	return 0;
}