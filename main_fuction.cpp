#include <iostream>

using namespace std;

/*
�Լ� : ����� ������ش�.
������ ����� �� �ִ� ��ǰ�̶� ����.

���� : ��ȯŸ�� �Լ���(�Ű�����){}�� ���·� ����

��ȯŸ�� : �Լ��� ��ȯ�ϴ� ���� Ÿ��
�Լ��� : �Լ��� �̸��� �ǹ��ϸ� �������̸� �� �Լ��� ������ ��Ȯ�� ǥ���ϴ� ���� �������� ����
�Ű����� : �Լ��� ȣ��� �� ���޵Ǵ� ��, �������� �ְ� �������� ����
{} : �Լ��� ��ü, �Լ��� ����� �� ����Ǵ� �ڵ尡 ��
*/

// ����� ��ȯ���ִ� �Լ� ���¸� Call by Value
int Sum(int a, int b)
{
	//return Ű���带 �̿��� ��ȯ���� �������ش�.
	return a + b;
}

// void�� �̿��� ��ȯ���� ���� �Լ��� ���� �� ����
void OutputText()
{
	cout << "OutputText" << endl;
}

int OutputNumber(int num)
{
	cout << "OutputNumber : " << num << endl;
	return num;
}

//��������
// ���������� ���α׷��� ����ɶ����� �޸𸮿� ��������
// ���������� ��� �Լ����� ���� ����
int g_iNum = 0;

// num�� ChangeNumber�� �ڵ� ���ȿ� ���������� �ǴܵǱ� ������ ���� num���� �ٸ���.
// ���������� stack������ ����Ǳ� ������ �Լ��� ������ �������.
void ChangeNumber(int num)
{
	num = 10;
	cout << "int num : " << num << endl;
}


void g_ChangeNumber()
{
	g_iNum = 10;
}

//������� �������ִ� �Լ� ���¸� Call by Address�� �Ѵ�.
void ChangeNumber_point(int* num)
{
	// �������� ���� num�� ���� ����
	*num = 10;
}


/*
�Լ��� �����ε� : ���� �̸��� �Լ��� ������ ���� �� �ִ�.
�����ε� ���� : �Լ��� �̸��� ������ �Ű������� Ÿ���̳� ������ �޶�� �Ѵ�.
*/
void ChangeNumber(float num)
{
	num = 20.3f;
	cout << "float num : " << num << endl;
}

//�Լ��� ����Ʈ �Ű����� : �Լ��� �Ű������� �⺻���� �������� �� �ִ�.
//�Ű������� �ѱ��� �ʾƵ� �⺻������ ���ȴ�.
void Output(int num = 10)
{
	cout << "Output : " << num << endl;
}

int main()
{
	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤ��Լ�" << endl;
	// �Լ��� ȣ���Ҷ� �Լ���(����); ���·� ȣ��, ����̰� Ȱ�� ����
	cout << "Sum : " << Sum(10, 20) << endl; // 30
	cout << "Sum : " << Sum(100, 200) << endl; // 300
	OutputText();
	OutputNumber(100);

	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤ���������" << endl;
	//���� ������ �ʾҴ�.
	int num = 0;
	ChangeNumber(num);
	cout << "num : " << num << endl; // 0

	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤ���������" << endl;
	g_iNum = 0;
	g_ChangeNumber();
	cout << "g_iNum : " << g_iNum << endl; // 10

	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѿ�����" << endl;
	int numpoint = 0;
	ChangeNumber_point(&numpoint);
	cout << "numpoint : " << numpoint << endl; // 10

	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤ��Լ� �����ε�" << endl;
	ChangeNumber(10); // int������ �����ε�
	ChangeNumber(0.0f); // float������ �����ε�

	cout << endl;
	cout << endl;
	cout << "�ѤѤѤѤѤѵ���Ʈ �Ű�����" << endl;
	Output(); // 10
	Output(100); // 100

	return 0;
}