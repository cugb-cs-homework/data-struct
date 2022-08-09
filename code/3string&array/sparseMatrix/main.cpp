#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
const int maxn = 25;
typedef pair<int, int> P;

int n = 4, m = 4;

int a[][4] = {
    {1, 0, 3, -0},
    {0, 1, -0, 0},
    {0, -0, 1, 0},
    {-0, 0, 1, 1}
}, b[][4] = {
    {3, 0, 0, 0},
    {0, 4, 0, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 2}
};

struct node {
    int row, col, val;
};

struct matrix {
    int rows, cols, nums;
    node vals[maxn];
};

bool cmp(node x, node y)
{
    if (x.row < y.row) return x.row < y.row;
    return x.col < y.col;
}

void Creat(matrix &t, int arr[][4])
{
    t.rows = n, t.cols = m, t.nums = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (arr[i][j]) {
                t.vals[t.nums].row = i;
                t.vals[t.nums].col = j;
                t.vals[t.nums].val = arr[i][j];
                ++t.nums;
            }
}

void Reverse(matrix &t)
{
    for (int i = 0; i < t.nums; ++i)
        swap(t.vals[i].col, t.vals[i].row);
}

void Display(matrix &t)
{
    sort(t.vals, t.vals+t.nums, cmp);
    for (int i = 0; i < t.nums; ++i)
        printf("(%d, %d): %d\n", t.vals[i].row+1, t.vals[i].col+1, t.vals[i].val);
    printf("\n");
}

void add(matrix &res, matrix &x, matrix &y)
{
    map<P, int> mp;
    for (int i = 0; i < x.nums; ++i)
        mp[P(x.vals[i].col, x.vals[i].row)] += x.vals[i].val;
    for (int i = 0; i < y.nums; ++i)
        mp[P(y.vals[i].col, y.vals[i].row)] += y.vals[i].val;
    res.cols = x.cols, res.rows = x.rows, res.nums = 0;
    for (auto e:mp) {
        res.vals[res.nums].val = e.second;
        res.vals[res.nums].row = e.first.first;
        res.vals[res.nums].col = e.first.second;
        ++res.nums;
    }
}

signed main()
{
    matrix A, B, C;
    Creat(A, a), Creat(B, b);
    Reverse(A), Display(A);
    Reverse(A), add(C, A, B), Display(C);   // 再倒置回来
    return 0;
}
