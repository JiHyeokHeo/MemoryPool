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
        1, 0, // ��
        0, -1, // ��
        -1, 0, //�Ʒ�
        0, 1, // ��
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
        // �Է�
        for (int i = 0; i < T; i++)
        {
            cin >> M >> N >> K;
        }

        // �迭�� ����
		for (int y = 0; y < N; ++y)
		{
			for (int x = 0; x < M; x++)
			{
                int tempX, tempY;
                cin >> tempX, tempY;
                arr[tempY][tempX] = 1;
			}
		}

        // ������������ Ȯ��
        

        // �迭 �ʱ�ȭ
        memset(arr, -1, sizeof(arr));

        // Ƚ������
        testCnt++;
    }


    return 0;
}