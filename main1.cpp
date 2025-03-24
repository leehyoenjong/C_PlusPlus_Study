#include <iostream>

using namespace std;

int main()
{
	srand((unsigned int)time(0));
	int iArray[25] = {};

	//1~25까지의 숫자를 넣는다.
	for (int i = 0; i < 25; ++i)
	{
		iArray[i] = i + 1;
	}

	//섞기
	int iTemp, idx1, idx2;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = iArray[idx1];
		iArray[idx1] = iArray[idx2];
		iArray[idx2] = iTemp;
	}

	while (true)
	{
		system("cls");

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iArray[i * 5 + j] == INT_MAX)
				{
					cout << "*\t";
				}
				else
				{
					cout << iArray[i * 5 + j] << "\t";
				}
			}
			cout << endl;
		}

		cout << "숫자를 입력하세요(0 : 종료) : ";
		int iInput;
		cin >> iInput;
		
		//종료
		if (iInput == 0)
		{
			break;
		}
		//1~25 사이의 숫자가 아닌 경우
		else if (iInput < 1 || iInput > 25)
		{
			cout << "잘못된 숫자입니다." << endl;
			continue;
		}

		//중복 입력 체크하기 위한 변수
		bool bAcc = true;

		//모든 숫자를 차례대로 검사해 입력한 숫자와 같은 숫자가 있는지 찾아낸다
		for (int i = 0; i < 25; i++)
		{
			//같은 숫자가 있을 경우 
			if (iInput == iArray[i]) 
			{
				//숫자를 찾았을 경우 중복된 숫자가 아니므로 
				//bAcc를 false로 만든다
				bAcc = false;

				//숫자를 *로 만들기 위해 특수한 값인 INT_MAX로 변경
				iArray[i] = INT_MAX;

				//더이상 다른 숫자를 찾아볼 필요가 없으므로 for문을 빠져나간다.
				break;
			}
		}

		//bAcc가 true일 경우 중복된 숫자를 입력해서 숫자*로 만들지 못했으므로
		//다시 입력받기 위해 continue를 한다.
		if (bAcc)
		{
			continue;
		}
	}

	return 0;
}