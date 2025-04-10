#include <iostream>

using namespace std;


//구조체 
//- 관련 있는 변수들을 모아 하나의 새로운 타입을 만들어주는 기능

//형태
//- struct 구조체명 {}; 의 형태로 구성 

//배열과 구조체의 공통점 : 
// - 데이터 집합이다.
// 연속된 메모리 블럭에 할당되며 구조체 맴버들은 연속된 메모리 블럭으로 잡히게 된다.

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
	//변수를 초기화 해주지 않으면 쓰레기 값이 들어감
	_tagStudent tStudent_s;
	_tagStudent tStudent = {};
	_tagStudent tStudentArr[100] = {};

	// 구조체 맴버에 접근할때는 . 을 이용해 접근
	tStudent.iKor = 100;

	//문자열을 배열에 넣을 떄는 단순 대입으로 불가능
	//tStudent.strName = "내이름은 무엇일까"; X
	// strcpy_s 라는 함수로 문자열을 복사해줘야하며 오른쪽에 있는 문자열을 왼쪽에 복사해준다.
	strcpy_s(tStudent.strName, "내이름은 무엇일까");
	cout << "이름 길이 : " << strlen(tStudent.strName) << endl;

	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡ 초기화 안함" << endl;
	cout << "이름 : " << tStudent.strName << endl;
	cout << "국어 : " << tStudent.iKor << endl;
	cout << "영어 : " << tStudent.iEng << endl;

	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡ 초기화 함" << endl;
	cout << "이름 : " << tStudent.strName << endl;
	cout << "국어 : " << tStudent.iKor << endl;
	cout << "영어 : " << tStudent.iEng<< endl;


	//문자열 붙이는 함수
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡ 문자열 붙이기" << endl;
	strcat_s(tStudent.strName, "너는 아니?");
	cout << "이름 : " << tStudent.strName << endl;
	cout << "이름 길이 : " << strlen(tStudent.strName) << endl;

	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡ 문자열 비교" << endl;
	cout << "학생 이름을 검색 해주세요 : ";
	strcpy_s(tStudent.strName, "길동좌");
	char strName[NAME_SIZE] = {};
	cin >> strName;

	//strcmp 문자열 비교 함수, 같을 경우 0을 반환
	if (strcmp(tStudent.strName, strName) == 0)
	{
		cout << "학생 찾음" << endl;
	}
	else
	{
		cout << "학생 못찾음" << endl;
	}
	return 0;
}