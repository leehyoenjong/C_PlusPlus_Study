#include <iostream>

using namespace std;


enum AI_MODE
{
	AM_EASY = 1,
	AM_HARD
};
enum LINE_NUMBER
{
	LN_H1,
	LN_H2,
	LN_H3,
	LN_H4,
	LN_H5,
	LN_V1,
	LN_V2,
	LN_V3,
	LN_V4,
	LN_V5,
	LN_LT,
	LN_RT
};


// 함수는 선언과 정의 부분으로 나눌 수 있음
void SetNumber(int* parray);
void Shuffle(int* parray);
void OutputNumber(int* parray, int ibingo);
AI_MODE SelectAIMode();
bool ChangeNumber(int* parray, int iInput);
int SeletAINumber(int* parray, AI_MODE emode);
int BingoCounting(int* parray);
int BingoCountingH(int* parray);
int BingoCountingV(int* parray);
int BingoCountingLTD(int* parray);
int BingoCountingRTD(int* parray);

int main()
{
	srand((unsigned int)time(0));
	int iArray[25] = {};
	int iAIArray[25] = {};

	//숫자 셋팅
	SetNumber(iArray);
	SetNumber(iAIArray);

	//섞기
	Shuffle(iArray);
	Shuffle(iAIArray);

	int iBingo = 0, iAIBingo = 0;

	//AI 난이도 선택
	AI_MODE iAIMode = SelectAIMode();

	while (true)
	{
		system("cls");

		//숫자를 5x5로 출력한다.
		cout << "================== Player ==================" << endl;
		OutputNumber(iArray, iBingo);

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
		OutputNumber(iAIArray, iAIBingo);


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
		bool bAcc = ChangeNumber(iArray, iInput);

		//bAcc가 true일 경우 중복된 숫자를 입력해서 숫자*로 만들지 못했으므로
		//다시 입력받기 위해 continue를 한다.
		if (bAcc)
		{
			continue;
		}

		//중복이 아니라면 AI도 숫자를 하나 선택해서 *로 만든다.
		bAcc = ChangeNumber(iAIArray, iInput);


		//AI가 숫자를 선택한다. AI모드에 맞춰서 선택한다.
		iInput = SeletAINumber(iAIArray, iAIMode);

		//AI가 선택한 숫자를 AI배열과 플레이어에서 *로 만들어준다.
		ChangeNumber(iArray, iInput);
		ChangeNumber(iAIArray, iInput);

		//빙고 수 를 체크하는 것은 매번 숫자를 입력할때마다 처음부터 새로 카운트를 할 것이다
		//그러므로 iBingo를 0으로 초기화 한다.
		iBingo = BingoCounting(iArray);
		iAIBingo = BingoCounting(iAIArray);
	}
	return 0;
}

// 함수의 정의 부분
void SetNumber(int* parray)
{
	// 배열의 주소를 받아서 값을 변경
	for (int i = 0; i < 25; ++i)
	{
		parray[i] = i + 1;
	}
}

void Shuffle(int* iArray)
{
	//섞기
	int iTemp = 0, idx1 = 0, idx2 = 0;
	for (int i = 0; i < 100; ++i)
	{
		idx1 = rand() % 25;
		idx2 = rand() % 25;
		iTemp = iArray[idx1];
		iArray[idx1] = iArray[idx2];
		iArray[idx2] = iTemp;
	}
}

AI_MODE SelectAIMode()
{
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

	return (AI_MODE)iAIMode;
}

void OutputNumber(int* parray, int ibingo)
{
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (parray[i * 5 + j] == INT_MAX)
			{
				cout << "*\t";
			}
			else
			{
				cout << parray[i * 5 + j] << "\t";
			}
		}
		cout << endl;
	}

	cout << "Bingo Line : " << ibingo << endl << endl;
}

bool ChangeNumber(int* parray, int iInput)
{
	//모든 숫자를 차례대로 검사해 입력한 숫자와 같은 숫자가 있는지 찾아낸다
	for (int i = 0; i < 25; ++i)
	{
		//같은 숫자가 있을 경우 
		if (iInput == parray[i])
		{
			//숫자를 *로 만들기 위해 특수한 값인 INT_MAX로 변경
			parray[i] = INT_MAX;

			//더이상 다른 숫자를 찾아볼 필요가 없으므로 for문을 빠져나간다.
			return false;
		}
	}

	//중복된 숫자를 입력했기 때문에 true로 return
	return true;
}

int SeletAINumber(int* pArray, AI_MODE iAIMode)
{
	//선택안된 목록 배열을 만들어준다
	int iNoneSelect[25] = {};
	int iNoneSelCnt = 0;

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
			if (pArray[i] != INT_MAX)
			{
				//*이 아닌 숫자일 경우 iNoneSelect를 인덱스로 활용
				//선택 안된 목록에 추가
				iNoneSelect[iNoneSelCnt] = pArray[i];
				++iNoneSelCnt;
			}
		}

		//for문을 빠져 나오게 되면 선택안된 목록이 만들어지고
		//선택안된 목록의 개수가 만들어진다.
		//그러므로 0~iNoneSelCnt-1까지의 숫자를 랜덤으로 뽑아서
		//그 숫자를 *로 만들어주면 된다.
		return iNoneSelect[rand() % iNoneSelCnt];
	case AM_HARD:
		// 하드모드는 현재 숫자중 빙고줄 완성 가능성이 가장 높은 줄을 찾아, 그 줄에 있는 숫자중 하나를 *로 만든다.
		int iLine = 0;
		int iStarCount = 0;
		int iSaveCount = 0;

		//가로 라인 중에 가장 *이 많은 라인을 찾아낸다.
		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				//가로줄 체크
				if (pArray[i * 5 + j] == INT_MAX)
				{
					++iStarCount;
				}
			}

			//별이 5개보다 미만이여야 빙고가 아님 && 새로운 라인을 찾았을 때
			//그 라인의 별 갯수를 저장하고 그 라인을 선택한다.
			//이렇게 하면 별이 가장 많은 라인을 찾을 수 있다.
			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				//가로 라인중 가장 별이 많은 라인을 체크
				//가로 라인은 0~4로 의미를 부여
				iLine = i;
				iSaveCount = iStarCount;
			}
		}
		//가로 라인 중 가장	별이 많은 라인을 찾았다.
		//이 값을 가지고 세로 라인들과 비교하여 별이 가장 많은 라인을 찾아낸다.
		for (int i = 0; i < 5; ++i)
		{
			iStarCount = 0;
			for (int j = 0; j < 5; ++j)
			{
				if (pArray[j * 5 + i] == INT_MAX)
				{
					++iStarCount;
				}
			}

			if (iStarCount < 5 && iSaveCount < iStarCount)
			{
				//세로 라인중 가장 별이 많은 라인을 체크
				//세로 라인은 5~9로 의미를 부여
				iLine = i + 5;
				iSaveCount = iStarCount;
			}
		}

		//왼쪽 -> 오른쪽 대각선 체크
		iStarCount = 0;
		for (int i = 0; i < 25; i += 6)
		{
			if (pArray[i] == INT_MAX)
			{
				++iStarCount;
			}
		}
		if (iStarCount < 5 && iSaveCount < iStarCount)
		{
			//왼쪽 -> 오른쪽 대각선 체크
			//대각선은 10번으로 의미를 부여
			iLine = LN_LT;
			iSaveCount = iStarCount;
		}

		//오른쪽 -> 왼쪽 대각선 체크
		iStarCount = 0;
		for (int i = 4; i <= 20; i += 4)
		{
			if (pArray[i] == INT_MAX)
			{
				++iStarCount;
			}
		}
		if (iStarCount < 5 && iSaveCount < iStarCount)
		{
			//오른쪽 -> 왼쪽 대각선 체크
			//대각선은 11번으로 의미를 부여
			iLine = LN_RT;
			iSaveCount = iStarCount;
		}

		//모든 라인을 조사했으면 iLine에는 가장 별이 많은 라인이 저장되어 있다.
		//그 라인에 있는 *이 아닌 숫자중 하나를 선택한다.
		//가로줄일 경우
		if (iLine <= LN_H5)
		{
			for (int i = 0; i < 5; ++i)
			{
				if (pArray[iLine * 5 + i] != INT_MAX)
				{
					return pArray[iLine * 5 + i];
				}
			}
		}
		//세로줄일 경우
		else if (iLine <= LN_V5)
		{
			for (int i = 0; i < 5; ++i)
			{
				if (pArray[i * 5 + (iLine - 5)] != INT_MAX)
				{
					return  pArray[i * 5 + (iLine - 5)];
				}
			}
		}
		//왼쪽 -> 오른쪽 대각선
		else if (iLine == LN_LT)
		{
			for (int i = 0; i < 25; i += 6)
			{
				if (pArray[i] != INT_MAX)
				{
					return pArray[i];
				}
			}
		}
		//오른쪽 -> 왼쪽 대각선
		else if (iLine == LN_RT)
		{
			for (int i = 4; i <= 20; i += 4)
			{
				if (pArray[i] != INT_MAX)
				{
					return pArray[i];
				}
			}
		}
		break;
	}

	return -1;
}

int BingoCounting(int* parray)
{
	int iBingo = 0;

	//가로줄 체크
	iBingo += BingoCountingH(parray);
	//세로줄 체크
	iBingo += BingoCountingV(parray);
	//왼쪽 -> 오른쪽 대각선 체크
	iBingo += BingoCountingLTD(parray);
	//오른쪽 -> 왼쪽 대각선 체크
	iBingo += BingoCountingRTD(parray);
	return iBingo;
}
int BingoCountingH(int* iArray)
{
	//줄 수를 구해준다
	int iStar1 = 0;
	int iBingo = 0;

	for (int i = 0; i < 5; i++)
	{
		//한줄 체크하기 전 먼저 0으로 초기화
		iStar1 = 0;
		for (int j = 0; j < 5; j++)
		{
			//별 갯수 구해준다
			if (iArray[i * 5 + j] == INT_MAX)
			{
				++iStar1;
			}
		}

		//j for문이 끝났을 때 iStar1이 5라면 가로 한줄이 모두 *이라는 의미
		if (iStar1 == 5)
		{
			++iBingo;
		}
	}

	return iBingo;
}

int BingoCountingV(int* iArray)
{
	//줄 수를 구해준다
	int iStar1 = 0;
	int iBingo = 0;

	for (int i = 0; i < 5; i++)
	{
		//한줄 체크하기 전 먼저 0으로 초기화
		iStar1 = 0;
		for (int j = 0; j < 5; j++)
		{
			//별 갯수 구해준다
			if (iArray[j * 5 + i] == INT_MAX)
			{
				++iStar1;
			}
		}

		//j for문이 끝났을 때 iStar1이 5라면 가로 한줄이 모두 *이라는 의미
		if (iStar1 == 5)
		{
			++iBingo;
		}
	}
	return iBingo;
}

int BingoCountingLTD(int* iArray)
{
	//줄 수를 구해준다
	int iStar1 = 0;
	int iBingo = 0;

	//왼쪽 상단 -> 오른쪽 하단 대각선 체크
	//대각선으로 6씩 증가
	iStar1 = 0;
	for (int i = 0; i < 25; i += 6)
	{
		if (iArray[i] == INT_MAX)
		{
			++iStar1;
		}
	}
	if (iStar1 == 5)
	{
		++iBingo;
	}
	return iBingo;
}

int BingoCountingRTD(int* iArray)
{
	int iStar1 = 0;
	int iBingo = 0;
	//오른쪽 상단 -> 왼쪽 하단 대각선 체크
	//대각선으로 4씩 증가
	iStar1 = 0;
	for (int i = 4; i <= 20; i += 4)
	{
		if (iArray[i] == INT_MAX)
		{
			++iStar1;
		}
	}
	if (iStar1 == 5)
	{
		++iBingo;
	}
	return iBingo;
}
