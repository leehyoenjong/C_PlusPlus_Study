#include <iostream>

using namespace std;


enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};

int main()
{
	srand((unsigned int)time(0));
	int iArray[25] = {};
	int iAIArray[25] = {};

	//1~25까지의 숫자를 넣는다.
	for (int i = 0; i < 25; ++i)
	{
		iArray[i] = i + 1;
		iAIArray[i] = i + 1;
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

		//AI 숫자도 섞어준다.
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = iAIArray[idx1];
		iAIArray[idx1] = iAIArray[idx2];
		iAIArray[idx2] = iTemp;
	}

	int iBingo = 0, iAIBingo = 0;
	int iAIMode = 0;

	while (true)
	{
		cout << "1. Easy" << endl;
		cout << "2. Hard" << endl;
		cout << "AI 난이도를 선택하세요 : ";
		cin >> iAIMode;

		if (iAIMode >= AM_EASY && iAIMode <= AM_HARD)
		{
			break;
		}
	}

	//선택안된 목록 배열을 만들어준다
	int iNoneSelect[25] = {};
	int iNoneSelCnt = 0;


	while (true)
	{
		system("cls");

		//숫자를 5x5로 출력한다.
		cout << "================== Player ==================" << endl;

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

		cout << "Bingo Line : " << iBingo << endl << endl;

		cout << "================== AI ==================" << endl;
		cout << "AI 난이도 : ";
		switch (iAIMode)
		{
		case AM_EASY:
			cout << "Easy" << endl;
			break;
		case AM_HARD:
			cout << "Hard" << endl;
			break;
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (iAIArray[i * 5 + j] == INT_MAX)
				{
					cout << "*\t";
				}
				else
				{
					cout << iAIArray[i * 5 + j] << "\t";
				}
			}
			cout << endl;
		}

		cout << "AI Bingo Line : " << iBingo << endl << endl;


		//줄수가 2이상일 경우 빙고라인을 체크한다.
		if (iBingo >= 2)
		{
			cout << "Player 승리" << endl;
			break;
		}
		else if (iAIBingo >= 2)
		{
			cout << "AI 승리" << endl;
			break;
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

		//중복이 아니라면 AI도 숫자를 하나 선택해서 *로 만든다.
		for (int i = 0; i < 25; i++)
		{
			if (iAIArray[i] == iInput)
			{
				iAIArray[i] = INT_MAX;
				break;
			}
		}

		//AI가 선택할 수 있는 목록에서 숫자를 선택한다.
		switch (iAIMode)
		{
			/*
			AI Easy 모드
			- 랜덤으로 숫자를 뽑아서 *로 만든다.
			*/
		case AM_EASY:
			//선택 안된 숫자 개수는 목록을 만들때 카운트한다.
			iNoneSelCnt = 0;

			//선택 안된 숫자 목록 만들어준다
			for (int i = 0; i < 25; ++i)
			{
				//현재 숫자가 *이 아닐 경우
				if (iAIArray[i] != INT_MAX)
				{
					//*이 아닌 숫자일 경우 iNoneSelect를 인덱스로 활용
					//선택 안된 목록에 추가
					iNoneSelect[iNoneSelCnt] = iAIArray[i];
					++iNoneSelCnt;
				}
			}

			//for문을 빠져 나오게 되면 선택안된 목록이 만들어지고
			//선택안된 목록의 개수가 만들어진다.
			//그러므로 0~iNoneSelCnt-1까지의 숫자를 랜덤으로 뽑아서
			//그 숫자를 *로 만들어주면 된다.
			iInput = iNoneSelect[rand() % iNoneSelCnt];
			break;
		case AM_HARD:
			break;
		}

		//AI가 선택한 숫자를 AI배열과 플레이어에서 *로 만들어준다.
		for (int i = 0; i < 25; i++)
		{
			if (iInput == iArray[i])
			{
				iArray[i] = INT_MAX;
				break;
			}
		}
		for (int i = 0; i < 25; i++)
		{
			if (iInput == iAIArray[i])
			{
				iAIArray[i] = INT_MAX;
				break;
			}
		}

		//빙고 수 를 체크하는 것은 매번 숫자를 입력할때마다 처음부터 새로 카운트를 할 것이다
		//그러므로 iBingo를 0으로 초기화 한다.
		iBingo = 0;
		iAIBingo = 0;

		//가로, 세로 줄 수를 구해준다
		int iStar1 = 0, iStar2 = 0;
		int iAIStar1 = 0, iAIStar2 = 0;
		for (int i = 0; i < 5; i++)
		{
			//한줄 체크하기 전 먼저 0으로 초기화
			iStar1 = iStar2 = 0;
			for (int j = 0; j < 5; j++)
			{
				//가로 별 갯수 구해준다
				if (iArray[i * 5 + j] == INT_MAX)
				{
					++iStar1;
				}
				//세로 별 개수	구해준다
				if (iArray[j * 5 + i] == INT_MAX)
				{
					++iStar2;
				}

				//가로 별 갯수 구해준다
				if (iAIArray[i * 5 + j] == INT_MAX)
				{
					++iAIStar1;
				}
				//세로 별 개수	구해준다
				if (iAIArray[j * 5 + i] == INT_MAX)
				{
					++iAIStar2;
				}
			}

			//j for문이 끝났을 때 iStar1이 5라면 가로 한줄이 모두 *이라는 의미
			if (iStar1 == 5)
			{
				++iBingo;
			}
			if (iStar2 == 5)
			{
				++iBingo;
			}

			//j for문이 끝났을 때 iStar1이 5라면 가로 한줄이 모두 *이라는 의미
			if (iAIStar1 == 5)
			{
				++iAIBingo;
			}
			if (iAIStar2 == 5)
			{
				++iAIBingo;
			}
		}
		//왼쪽 상단 -> 오른쪽 하단 대각선 체크
		//대각선으로 6씩 증가
		iStar1 = 0;
		iAIStar1 = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (iArray[i] == INT_MAX)
			{
				++iStar1;
			}
			if (iAIArray[i] == INT_MAX)
			{
				++iAIStar1;
			}
		}
		if (iStar1 == 5)
		{
			++iBingo;
		}
		if (iAIStar1 == 5)
		{
			++iAIBingo;
		}

		//오른쪽 상단 -> 왼쪽 하단 대각선 체크
		//대각선으로 4씩 증가
		iStar1 = 0;
		iAIStar1 = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (iArray[i] == INT_MAX)
			{
				++iStar1;
			}
			if (iAIArray[i] == INT_MAX)
			{
				++iAIStar1;
			}
		}
		if (iStar1 == 5)
		{
			++iBingo;
		}
		if (iAIStar1 == 5)
		{
			++iAIBingo;
		}
	}

	return 0;
}