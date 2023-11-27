#include <iostream>
#include <iomanip>
using namespace std;

// 오늘의 주제 : 연습문제

const int MAX = 100;
int board[MAX][MAX] = {};
int N;

void PrintBoard()
{
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << setfill('0') << setw(2) << board[y][x] << " ";
		}
		cout << endl;
	}
}

int dir[4][2] =
{
	0,1, // 오른쪽
	1,0, // 아래
	0,-1, // 왼쪽
	-1,0, // 위
};

int turnCnt = 0;
int cnt = 1;
int row = 0;
int col = 0;
int addCol = 0;
int addRow = 0;

void SetTurn()
{
	turnCnt %= 4;
	addRow = dir[turnCnt][0];
	addCol = dir[turnCnt][1];
}

void SetBoard()
{
	while (true)
	{
		SetTurn();
		
		if (col + addCol >= N || row + addRow >= N || col + addCol < 0 || row + addRow < 0)
		{
			turnCnt++;
			SetTurn();
		}

		board[row][col] = cnt;
		row += addRow;
		col += addCol;

		// 다 채우면 브레이크
		if (cnt == N * N)
			break;

		if (board[row][col] != 0)
		{
			cnt--;
			row -= addRow;
			col -= addCol;
			turnCnt++;
			SetTurn();
		}

		cnt++;
	}
}

int main()
{
	cin >> N;

	SetBoard();

	PrintBoard();

	return 0;
}