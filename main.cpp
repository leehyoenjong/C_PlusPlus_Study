// '#'이 들어가 있는 것은 전처리기라 표현하며 
// iosteam : 만들어진 라이브러리 기능들이 들어 있다.
// #include : 헤더파일을 여기에 포함시키는 기능
#include<iostream>
#include<time.h>

//using namespace를 이용하여 std를 생략 가능
using namespace std;

enum NUM
{
	//아무것도 부여하지 않은 경우 0부터 시작
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

//가위 바위 보 열거체
enum SRP
{
	SRP_SCISSORS = 0,
	SRP_ROCK,
	SRP_PAPER,
	SRP_END
};

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


	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡSwitch문
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡSwich문" << endl;

	//switch문 : 값에 따라 실행문을 실행
	//switch(변수) { case 값 : 실행문 }

	int number = 3;
	cout << "숫자를 입력하세요 : ";
	cin >> number;

	//break : switch문을 빠져나가는 역할
	//case 3, 4일 때 실행문을 실행하고 break를 만나면 switch문을 빠져나간다.
	//default : case에 없는 값일 때 실행문을 실행
	switch (number)
	{
	case 1:
		cout << "1입니다." << endl;
		break;
	case 2:
		cout << "2입니다." << endl;
		break;
	case 3:
	case 4:
		cout << "3 또는 4입니다." << endl;
		break;

	default:
		cout << "그 외의 숫자입니다." << endl;
		break;
	}

	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ열거체
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ열거체" << endl;

	//열거체 : 연속된 숫자에 이름을 부여할 수 있는 기능
	//형태는 enum : 열거체를 선언할 때 사용하는 키워드
	//열거체명을 이용해 열거체 타이의 변수를 선언도 가능
	//열거체는 즉, 숫자에 이름을 부여하는 것이다.

	switch (number)
	{
	case NUM_1:
		cout << "열거체: 1입니다." << endl;
		break;
	case NUM_2:
		cout << "열거체: 2입니다." << endl;
		break;
	case NUM_3:
	case NUM_4:
		cout << "열거체: 3 또는 4입니다." << endl;
		break;
	case NUM_11:
		cout << "열거체: 11입니다." << endl;
		break;
	default:
		cout << "열거체: 그 외의 숫자입니다." << endl;
		break;
	}

	//열거체 타입의 변수 선언
	//열거체 타입의 변수는 무조건 4byte의 크기를 가진다.
	NUM eNumber = NUM_1;
	cout << "열거체 메모리 크기 : " << sizeof(eNumber) << endl;
	cout << "열거형 타입도 알수 있음 : " << typeid(eNumber).name() << endl;


	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ반복문
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ반복문" << endl;
	//반복문 : 조건에 따라 실행문을 반복
	//종류 : for문, while문, do while문
	//반복문을 빠져나오는 방법 : 조건이 거짓이 되면 빠져나오거나 break를 넣으면 빠져나옴

	//ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡwhile문
	cout << endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡwhile문" << endl;
	//while문 : 조건이 참일 때 실행문을 반복
	//while(조건) { 실행문 }
	number = 0;
	while (number < 10)
	{
		cout << "while문 실행중 : " << number << endl;
		number++;

		if (number == 4)
			break;
	}

	//화면을 깨끗히 지워주는 명령어
	system("cls");
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ가위바위보" << endl;
	//난수테이블 생성
	srand((unsigned int)time(0));

	//가위바위보 게임 만들기 
	int srp = 0;
	int iAI = 0;
	while (true)
	{
		cout << "가위(0) 바위(1) 보(2) 끝내기(3) 선택하시오 : ";
		cin >> srp;
		cout << "Player : " << (SRP)srp << endl;

		//잘못된 값 입력 시 처리
		//continue : 다음 반복문으로 넘어가는 명령어
		if (srp == SRP_END)
		{
			cout << "가위바위보 게임을 종료합니다." << endl;
			break;
		}
		else if (srp < SRP_SCISSORS || srp >= SRP_END)
		{
			cout << "잘못된 값을 입력하셨습니다." << endl;
			continue;
		}


		//난수 가위바위보 선택
		//SRP_END를 넣으면 0~2까지의 난수가 생성
		iAI = rand() % SRP_END;

		cout << "AI : " << (SRP)iAI << endl;

		//승자결정
		switch (srp)
		{
		case SRP_SCISSORS:
			if (iAI == SRP_SCISSORS)
				cout << "비겼습니다." << endl;
			else if (iAI == SRP_ROCK)
				cout << "졌습니다." << endl;
			else if (iAI == SRP_PAPER)
				cout << "이겼습니다." << endl;
			break;
		case SRP_ROCK:
			if (iAI == SRP_SCISSORS)
				cout << "이겼습니다." << endl;
			else if (iAI == SRP_ROCK)
				cout << "비겼습니다." << endl;
			else if (iAI == SRP_PAPER)
				cout << "졌습니다." << endl;
			break;
		case SRP_PAPER:
			if (iAI == SRP_SCISSORS)
				cout << "졌습니다." << endl;
			else if (iAI == SRP_ROCK)
				cout << "이겼습니다." << endl;
			else if (iAI == SRP_PAPER)
				cout << "비겼습니다." << endl;
			break;
		}
	}




	//화면을 깨끗히 지워주는 명령어
	system("cls");
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡfor문" << endl;

	//for문 : 조건이 참일 때 실행문을 반복
	//for(초기값; 조건; 증감) { 실행문 }
	//초기값 : 반복문을 시작할 때 초기값을 설정
	//조건 : 반복문을 빠져나올 조건
	//증감 : 반복문이 실행될 때마다 증감할 값

	//초기값 : i = 0, 조건 : i < 10, 증감 : i++
	for (int i = 0; i < 10; i++)
	{
		cout << "for문 실행중 : " << i << endl;
	}

	//구구단
	for (int i = 2; i < 10; i++)
	{
		cout << i << "단" << endl;
		for (int j = 1; j < 10; j++)
		{
			cout << i << " * " << j << " = " << i * j << endl;
		}
	}

	// 1~ 100 사이의 숫자 중 짝수만 출력
	for (int i = 2; i <= 100; i += 2)
	{
		cout << i << endl;
	}

	// 1 ~ 100 사이 숫자중 3과 7의 공배수만 출력하는 if문 만들기
	for (int i = 1; i <= 100; i++)
	{
		if (i % 3 == 0 && i % 7 == 0)
		{
			cout << i << endl;
		}
	}

	//화면을 깨끗히 지워주는 명령어
	system("cls");
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡdo while" << endl;

	//do while문 : 조건이 참일 때 실행문을 반복
	//선언 : do { 실행문 } while(조건)
	//do while문은 조건이 거짓이여도 한번은 실행된다.

	number = 0;
	do
	{
		cout << "do while문 실행중 : " << number << endl;
		number++;
	} while (number < 10);
	cout << "조건식: (number < 10)" << endl;


	//화면을 깨끗히 지워주는 명령어
	system("cls");
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ배열" << endl;
	/*
	배열 : 같은 타입의 변수를 하나의 이름으로 여러 개를 한번에 생성할수 있는 기능
	선언 : 타입 이름[크기] = { 값, 값, 값, ... }

	배열의 특징 :
	- 배열은 선언과 동시에 초기화를 해야한다.
	- 배열은 0부터 시작하며 인덱스를 이용해 접근할 수 있다.
	- 연속된 메모리 블럭에 할당된다.
	- 연속된 메모리 블럭 : 메모리 - [0][1][2][3][4][5][6][7][8][9]
	*/

	//값을 넣지 않고 선언
	//배열 뿐 아니라 일반 변수도 선언만 하고 값을 넣지 않으면 쓰레기 값이 들어가게 된다.
	int iArray_none[10];
	iArray_none[0] = 1;
	cout << "초기화 하지 않은 배열 인덱스[0] : " << iArray_none[0] << endl;
	cout << "초기화 하지 않은 배열 인덱스[5] : " << iArray_none[5] << endl;

	//0으로 초기화
	int iArray_zero[10] = { };
	cout << "0으로 초기화 한 배열 인덱스[0] : " << iArray_zero[0] << endl;
	cout << "0으로 초기화 한 배열 인덱스[5] : " << iArray_zero[5] << endl;

	//값을 넣고 선언
	int iArray[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "초기화 한 배열 인덱스[0] : " << iArray[0] << endl;
	cout << "초기화 한 배열 인덱스[5] : " << iArray[5] << endl;

	/*
	이차원 배열	: 배열 안에 배열을 넣어 2차원 배열을 만드는 것
	선언		: 타입 이름[크기][크기] = { { 값, 값, 값, ... }, { 값, 값, 값, ... }, ... }
	배열의 개수를 2개를 지정하면 이차원배열, 3개를 지정하면 삼차원배열이 된다.
	*/
	int iArray2D[2][5] = { {1, 2, 3, 4, 5}, {6, 7, 8, 9, 10} };
	cout << "이차원 배열 인덱스[0][0] : " << iArray2D[0][0] << endl;
	cout << "이차원 배열 인덱스[1][4] : " << iArray2D[1][4] << endl;


	return 0;
}

