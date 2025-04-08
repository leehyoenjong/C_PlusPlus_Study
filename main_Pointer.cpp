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
	//포인터 : 가르키는 것
	//주소를 가르키는 변수
	//일반 변수는 값을 저장하는 변수
	//포인터는 주소를 저장하는 변수
	//모든 변수 타입은 포인터 타입 선언이 가능
	//포인터는 메모리 주소를 담아놓은 변수이기 때문에 x86으로 개발할 시 무조건 4byte, x64로 개발할 시 8byte가 나옴


	//포인터는 자기 스스로 아무런 일을 할수 없고, 반드시 다른 변수의 메모리 주소를 가지고 있어야 일을 할 수 있다.
	//메모리 주소에 접근해 값을 제어할 수 있음

	//형태 : 변수타입 *변수명 의 형태로 선언

	//일반 변수
	int iInt = 10;
	//포인터 변수, &는 주소를 가져오는 연산자
	//pInt는 &iInt를 해줌으로써 주소를 가르키는 포인터 변수가 되었음
	int* pInt = &iInt;


	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ메모리 확인" << endl;
	cout << sizeof(int*) << endl; //x84기준 4byte | x64기준 8byte
	cout << sizeof(char*) << endl; //x84기준 4byte | x64기준 8byte
	cout << sizeof(double) << endl; //x84기준 8byte | x64기준 8byte
	cout << sizeof(double*) << endl; //x84기준 4byte | x64기준 8byte

	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ주소 및 값 확인" << endl;
	cout << "iInt 주소 : " << &iInt << endl; //iInt의 주소
	cout << "iInt 값 : " << iInt << endl; //iInt의 값
	cout << "pInt 주소 : " << &pInt << endl; //iInt의 주소
	cout << "pInt 값 : " << pInt << endl; //iInt의 값
	cout << "pInt 값 : " << *pInt << endl; //iInt의 값


	//pInt를 이용해 iInt의 값을 변경
	//역참조를 이용해 값을 얻어오거나 변경 가능
	//역참조는 포인터 앞에 *를 붙여주면 됨
	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ변경 후 주소 및 값 확인" << endl;
	*pInt = 20;
	cout << "iInt 주소 : " << &iInt << endl; //iInt의 주소
	cout << "iInt 값 : " << iInt << endl; //iInt의 값
	cout << "pInt 주소 : " << &pInt << endl; //iInt의 주소
	cout << "pInt 값 : " << pInt << endl; //iInt의 값
	cout << "pInt 값 : " << *pInt << endl; //iInt의 값

	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ배열 : " << endl;
	// 포인터와 배열의 관계 : 배열명은 곧 포인터다.
	// 배열명은 배열의 첫번째 주소를 가르키고 있다.
	int iArr[5] = { 1,2,3,4,5 };
	cout << "iArr 주소 : " << iArr << endl; //iArr의 주소
	cout << "iArr[0] 주소 : " << &iArr[0] << endl; //iArr의 주소

	//iArr에게 pArray라는 포인터 변수를 만들어서 iArr의 주소를 가르키게 해줌
	//pArray는 iArr의 주소를 가르키고 있음
	//iArr로 배열을 수정이 가능하듯이 pArray로도 배열을 수정이 가능함 왜냐하면 배열은 곧 주소이기 때문
	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ값 변경 : " << endl;
	int* pArray = iArr;
	pArray[2] = 100;
	cout << "pArray[2] : " << pArray[2] << endl; //100
	cout << "iArr[2] : " << iArr[2] << endl; //100

	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ포인터 연산 : " << endl;
	//포인터 연산 : +, - 연산을 제공하며, ++, --도 가능한데 1을 증가하게 되면 단순히 메모리 주소 값이 1 증가하는 것이 아닌 가르키는 포인터 타입의 변수 타입 크기만큼 증가하게 됨
	//int포인터의 경우 4byte, char포인터의 경우 1byte, double포인터의 경우 8byte가 증가하게 됨
	cout << "pArray       :" << pArray << endl; //iArr의 주소
	cout << "pArray + 2   :" << pArray + 2 << endl; //iArr의 주소
	cout << "*pArray      :" << *pArray << endl; //iArr의 주소
	cout << "*(pArray +2) :" << *(pArray + 2) << endl; //iArr의 주소


	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡchar 포인터: " << endl;
	//const를 바꾸면 문자열로 저장할 수 있음 
	// 값을 바꾸면 메모리 주소가 바뀜
	const char* pText = "text";
	cout << "pText 주소 : " << (int*)pText << endl; //pText의 주소
	pText = "texts";
	cout << "pText 주소 : " << (int*)pText << endl; //pText의 주소
	pText = "texts";
	cout << "pText 주소 : " << (int*)pText << endl; //pText의 주소
	pText = "textsss";
	cout << "pText 주소 : " << (int*)pText << endl; //pText의 주소
	
	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ구조체 포인터: " << endl;
	_tagStudent student = {};
	student.iKor = 100;
	cout << "student.iKor : " << student.iKor << endl; //100


	_tagStudent* pStudent = &student;
	// 연산자 우선순위 때문에 .을 먼저 인식함
	//메모리 주소 .은 잘못된 문법이며 *pStudent를 괄호로 감싸잔 후 
	// .을 이용해 가리크는 대상의 맴버변술에 접근해야함
	(*pStudent).iKor = 50;
	cout << "student.iKor : " << student.iKor << endl; //50

	// ->을 이용해 가르키는 대상의 맴버에 접근 가능
	pStudent->iKor = 80;
	cout << "student.iKor : " << student.iKor << endl; //80

	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡvoid 포인터: " << endl;
	// void : 타입이 없다.
	// void* 변수를 선언하면 모든 타입이든 메모리주소든 가르킬 수 있다.
	void* pvoid = &iInt;
	cout << "iInt 주소 : " << &iInt << endl; //iInt의 주소
	cout << "pvoid 주소 : " << pvoid << endl; //pvoid의 주소

	cout << endl;
	cout << "역참조 전 iInt 값 : " << iInt << endl; //iInt의 주소
	// 단, 역참조가 불가능하고 메모리 주소만 저장 가능
	//*pvoid = 10; //역참조 불가능
	int* pConvefrt = (int*)pvoid; //형변환을 해줘야 역참조 가능
	*pConvefrt = 10; //역참조 가능
	cout << "역참조 후 iInt 값 : " << iInt << endl; //iInt의 주소
	*((int*)pvoid) = 20; //역참조 가능
	cout << "역참조 후 iInt 값 : " << iInt << endl; //iInt의 주소

	cout << endl;
	pvoid = &pStudent;
	cout << "pStudent 주소 : " << &pStudent << endl; //pStudent의 주소
	cout << "pvoid 주소 : " << pvoid << endl; //pvoid의 주소

	return 0;
}