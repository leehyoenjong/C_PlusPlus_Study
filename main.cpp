// '#'�� �� �ִ� ���� ��ó����� ǥ���ϸ� 
// iosteam : ������� ���̺귯�� ��ɵ��� ��� �ִ�.
// #include : ��������� ���⿡ ���Խ�Ű�� ���
#include<iostream>

//using namespace�� �̿��Ͽ� std�� ���� ����
using namespace std;

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
	cout << "Test Output";
	return 0;
}