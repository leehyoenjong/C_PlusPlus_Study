#include <iostream>

using namespace std;

/*
함수 : 기능을 만들어준다.
일종의 사용할 수 있는 부품이라 본다.

형태 : 반환타입 함수명(매개변수){}의 형태로 구성

반환타입 : 함수가 반환하는 값의 타입
함수명 : 함수의 이름을 의미하며 가급적이면 이 함수의 역할을 정확히 표시하는 것이 가독성에 좋음
매개변수 : 함수가 호출될 때 전달되는 값, 있을수도 있고 없을수도 있음
{} : 함수의 본체, 함수가 실행될 때 수행되는 코드가 들어감
*/

// 결과를 반환해주는 함수 형태를 Call by Value
int Sum(int a, int b)
{
	//return 키워드를 이용해 반환값을 지정해준다.
	return a + b;
}

// void를 이용해 반환값이 없는 함수를 만들 수 있음
void OutputText()
{
	cout << "OutputText" << endl;
}

int OutputNumber(int num)
{
	cout << "OutputNumber : " << num << endl;
	return num;
}

//전역변수
// 전역변수는 프로그램이 종료될때까지 메모리에 남아있음
// 전역변수는 모든 함수에서 접근 가능
int g_iNum = 0;

// num은 ChangeNumber의 코드 블럭안에 지역변수로 판단되기 때문에 밖의 num과는 다르다.
// 지역변수로 stack영역에 저장되기 때문에 함수가 끝나면 사라진다.
void ChangeNumber(int num)
{
	num = 10;
	cout << "int num : " << num << endl;
}


void g_ChangeNumber()
{
	g_iNum = 10;
}

//결과값을 변경해주는 함수 형태를 Call by Address라 한다.
void ChangeNumber_point(int* num)
{
	// 역참조를 통해 num의 값을 변경
	*num = 10;
}


/*
함수의 오버로딩 : 같은 이름의 함수를 여러개 만들 수 있다.
오버로딩 조건 : 함수의 이름은 같지만 매개변수의 타입이나 개수가 달라야 한다.
*/
void ChangeNumber(float num)
{
	num = 20.3f;
	cout << "float num : " << num << endl;
}

//함수의 디폴트 매개변수 : 함수의 매개변수에 기본값을 지정해줄 수 있다.
//매개변수를 넘기지 않아도 기본값으로 사용된다.
void Output(int num = 10)
{
	cout << "Output : " << num << endl;
}

int main()
{
	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡ함수" << endl;
	// 함수를 호출할때 함수명(인자); 형태로 호출, 몇번이건 활용 가능
	cout << "Sum : " << Sum(10, 20) << endl; // 30
	cout << "Sum : " << Sum(100, 200) << endl; // 300
	OutputText();
	OutputNumber(100);

	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡ지역변수" << endl;
	//값이 변하지 않았다.
	int num = 0;
	ChangeNumber(num);
	cout << "num : " << num << endl; // 0

	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡ전역변수" << endl;
	g_iNum = 0;
	g_ChangeNumber();
	cout << "g_iNum : " << g_iNum << endl; // 10

	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡ역참조" << endl;
	int numpoint = 0;
	ChangeNumber_point(&numpoint);
	cout << "numpoint : " << numpoint << endl; // 10

	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡ함수 오버로딩" << endl;
	ChangeNumber(10); // int형으로 오버로딩
	ChangeNumber(0.0f); // float형으로 오버로딩

	cout << endl;
	cout << endl;
	cout << "ㅡㅡㅡㅡㅡㅡ디폴트 매개변수" << endl;
	Output(); // 10
	Output(100); // 100

	return 0;
}