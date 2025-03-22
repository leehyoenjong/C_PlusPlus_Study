// '#'이 들어가 있는 것은 전처리기라 표현하며 
// iosteam : 만들어진 라이브러리 기능들이 들어 있다.
// #include : 헤더파일을 여기에 포함시키는 기능
#include<iostream>
#include<time.h>

//using namespace를 이용하여 std를 생략 가능
using namespace std;

// 실행 과정 : 컴파일 -> 빌드 -> 실행
// 컴파일 : 번역 작업(소스코드를 기계어(저수준 언어)로 변환)
// 빌드 : 컴파일된 파일을 실행파일로 변환
// 실행 : 실행파일을 실행
// Ctrl + Shift + B : 컴파일 및 빌드 가능

// C++의 시작점은 main 함수이다. main 함수는 반드시 있어야 함
int main()
{
	//C++ 표준 기능의 대부분은 std라는 namespace 안에 존재, 이름이 겹치는 것을 방지
	//cout : 콘솔창에 출력해주는 기능, "" 안에 있는 문자열을 화면에 출력
	std::cout << "Test Output";

	//<< std::endl : 개행(줄바꿈)
	std::cout << "Hello World" << std::endl;

	//using namespace std를 이용해 std를 빼고 가능
	cout << "Test Output" << std::endl;

	//관계 연산자
	cout << ("10 < 20 = ") << (10 < 20) << endl;
	cout << ("10 <- 20 = ") << (10 <= 20) << endl;
	cout << ("10 > 20 = ") << (10 > 20) << endl;
	cout << ("10 >= 20 = ") << (10 >= 20) << endl;
	cout << ("10 == 20 = ") << (10 == 20) << endl;
	cout << ("10 != 20 = ") << (10 != 20) << endl;

	//cin은 입력을 받아 넣어주는 역할
	cout << "숫자를 입력해주세요 : ";
	int Number;
	cin >> Number;

	//비트 연산자
	cout << "10 ~ 20 = " << (10 <= Number && Number <= 20) << endl;


	//비트 논리 연산자 
	// 
	// 선행학습 
	//진수 : 2진수, 8진수, 10진수, 16진수
	//2진수 : 0~1, 
	//8진수 : 0~7, 
	//10진수 : 0~9, 
	//16진수 : 0~9, A~F

	//87을 2진수, 16진수로 변환
	// 2진수 : 1010111
	// 16진수 : 57

	//Q. 87 & 53 = ?
	//	-87 : 1010111
	//	- 53 : 110101
	cout << "87 & 53 = " << (87 & 53) << endl;


	//상수 : 변하지 않는 값, 한번 정한 값은 변하지 않는다
	//상수는 선언과 동시에 값을 지정해야함
	//const : 상수를 선언할 때 사용하는 키워드
	const int iAttack = 0x00000001; // 2진수 :		 1
	const int iArmor = 0x00000002; // 2진수 :		10
	const int iHP = 0x00000004; // 2진수 :		   100
	const int iMP = 0x00000008; // 2진수 :		  1000
	const int iCritical = 0x00000010; // 2진수 : 10000

	// 1 | 100 = 101 | 10000 = 10101
	int iBuf = iAttack | iHP | iCritical;

	// 10101 & 1 = 00001
	cout << "Attack : " << (iBuf & iAttack) << endl;

	//10101 & 10 = 0
	cout << "Armor : " << (iBuf & iArmor) << endl;
	cout << "Mp: " << (iBuf & iMP) << endl;
	cout << "Hp : " << (iBuf & iHP) << endl;
	cout << "Critical : " << (iBuf & iCritical) << endl;

	//연산자 축약형 : 연산자를 줄여서 사용할 수 있다.

	// 10101 ^ 100 = 10001
	iBuf ^= iHP; // iBuf = iBuf ^ iHP
	cout << "iBuf : " << iBuf << endl;

	// 10001 ^ 100 = 10101
	// XOR을 이용해 껐다켰다 스위치 같은 것도 가능 
	iBuf ^= iHP; // iBuf = iBuf ^ iHP
	cout << "iBuf : " << iBuf << endl;

	// 10101 ^ 100 = 10001
	iBuf ^= iHP; // iBuf = iBuf ^ iHP
	cout << "iBuf : " << iBuf << endl;


	//쉬프트 연산자 : <<. >>
	//값대 값을 연산하여 값으로 나오게 됨
	//이 연산자 또한 이진수 단위의 연산을 하게 됨

	// Q. 20 << 2 = ?
	// 20 : 10100
	// 20 << 2 = 80
	// 20 << 2 : 101 0000
	// 20 << 3 = 160
	// 20 << 3 = 1010 0000
	// 20 << 4 = 320
	// 20 << 4 = 10100 0000

	// 결과 값이 20에 2승 , 20에 3승, 20에 4승이 된다.
	// 쉬프트 연산자로 하면 연산이 빠르게 된다.

	// 20 >> 1 = 10 
	// 20 >> 1 = 10100 >> 1 = 1010
	// 20 >> 2 = 5
	// 20 >> 2 = 10100 >> 2 = 101
	// 20 >> 3 = 2
	// 20 >> 3 = 10100 >> 3 = 10
	// 나누기로 활용한다면 빠르게 연산이 가능하다.
	// 나눗셈 이라는 연산 자체가 무거운 연산이라 쉬프트 연산을 이용하면 빠르게 가능 
	// 20 / 2 보다 20 * 0.5가 더 빠르고	20 >> 1이 더 빠르다.


	int iHght = 187;
	int iLow = 13560;

	int iNumber = iHght;

	//iNumber에는 187이 들어가 있음, 이 값을 << 1 이 방향으로 이동 시키면
	// 상위 16비트의 값이 들어가게 된다.
	iNumber <<= 16;

	//하위 16비트를 채운다
	iNumber |= iLow;

	// High 값을 출력한다
	cout << "High : " << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000FFFF) << endl;
	//F로 표현하는 이유는 16진수로 표현하기 위함	


	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡif문
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡif문" << endl;

	//분기문 크게 2가지 if문, switch문
	//if문 : 조건에 따라 실행문을 실행
	// if(조건) { 실행문 }
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
		cout << "Attack 버프가 있음" << endl;
	}

	if ((iBuf & iArmor) != 0)
	{
		cout << "Armor 버프가 있음" << endl;
	}

	//else : if문이 거짓일 때 실행
	//else { 실행문 }
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡelse" << endl;
	if (false)
	{
		cout << "True" << endl;
	}
	else
	{
		cout << "else" << endl;
	}

	//else if : if문이 거짓일 때 다시 조건을 검사
	//else if(조건) { 실행문 }
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡelse if" << endl;
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



	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ난수
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ난수" << endl;

	// srand는 unsigned int를 받아들이기 때문에, time는 unsigned int로 형변환하여 전달한다.
	// 형변환이란? 데이터의 형태를 바꾸는 것
	// int a = 10; float b = (float)a;
	// time은 시간을 받아오는 함수

	//난수를 생성하기 위해 srand를 사용
	//srand는 난수를 생성하기 위한 시드값을 설정하는 함수
	//time을 이용하는 이유는 실행할 때마다 다른 난수를 생성하기 위함
	srand((unsigned int)time(0));

	//rand는 0~32767까지의 값을 반환한다.(즉 난수 생성)
	cout << "난수 생성 : " << rand() << endl;
	cout << "난수 생성 : " << rand() << endl;
	cout << "난수 생성 : " << rand() << endl;

	//0~99까지의 난수 생성 
	cout << "0~99까지의 난수 생성 : " << (rand() % 100) << endl;

	//100~200까지의 난수 생성
	cout << "100~200까지의 난수 생성 : " << (rand() % 101 + 100) << endl;

	//99.9999까지의 난수 생성
	cout << "99.9999까지의 난수 생성 : " << (rand() % 10000 / 100.f) << endl;


	return 0;
}