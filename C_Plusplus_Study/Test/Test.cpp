#include <iostream>
#include <bitset>
#include <string.h>

using namespace std;

int arr[51][51];
int T;
int M, N, K;
int G_Cnt;

void Find()
{
    int check[4][2] = 
    {
        1, 0, // 위
        0, -1, // 왼
        -1, 0, //아래
        0, 1, // 오
    };

    for (int y = 0; y < M; y++)
    {
        int tempX = 0;
        for (int x = 0; x < N; x++)
        {
            if (arr[y][x] == 1)
            {
                tempX = x;
                break;
            }
        }

      
    }

}

int main()
{
    memset(arr, -1, sizeof(arr));

    cin >> T;

    int testCnt = 0;
    while (testCnt < T)
    {
        // 입력
        for (int i = 0; i < T; i++)
        {
            cin >> M >> N >> K;
        }

        // 배열에 대입
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < M; x++)
			{
                int tempX, tempY;
                cin >> tempX, tempY;
                arr[tempY][tempX] = 1;
			}
		}

        // 배추흰지렁이 확인
        

        // 배열 초기화
        memset(arr, -1, sizeof(arr));

        // 횟수증가
        testCnt++;
    }


    return 0;
}