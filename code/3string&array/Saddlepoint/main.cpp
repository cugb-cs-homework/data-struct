#include <iostream>

using namespace std;
const int maxn = 25;

int n, m;
int A[maxn][maxn];
int row[maxn], col[maxn];

int main()
{
    cin>>n>>m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin>>A[i][j];
    int temp;
    for (int i = 0; i < n; ++i) {
        temp = INT_MAX;
        for (int j = 0; j < m; ++j)
            if (A[i][j] < temp) temp = A[i][j], row[i] = j;
    }
    for (int j = 0; j < m; ++j) {
        temp = INT_MIN;
        for (int i = 0; i < n; ++i)
            if (A[i][j] > temp)
                temp = A[i][j], col[j] = i;
    }
    for (int i = 0; i < n; ++i) {
        if (col[row[i]] == i)
            printf("Result--(%d, %d): %d\n", i, row[i], A[i][row[i]]);
    }
    return 0;
}

/*
4 4
9 7 6 8
20 26 22 29
90 44 25 30
12 4 2 6
*/
