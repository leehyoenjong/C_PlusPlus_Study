// '#'이 들어가 있는 것은 전처리기라 표현하며 
// iosteam : 만들어진 라이브러리 기능들이 들어 있다.
// #include : 헤더파일을 여기에 포함시키는 기능
#include<iostream>

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
	cout << "Test Output";
	return 0;
}