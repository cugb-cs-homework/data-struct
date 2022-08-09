#include <bits/stdc++.h>
using namespace std;
const int N = 15;

struct node {
    int x, y;
    node(int x, int y) : x(x),
        y(y)
    {
    }
};

vector<node> vec;
vector<vector<node> > ans;

/*皇后肯定是每一行放一个，我要考虑怎末放列数*/
int n;
int sum = 0; // 记录器
int x[N]; // 标记皇后放置的列数

bool place(int k)   // 判断此列数是否可以存放
{
    for (int i = 1; i < k; i++)
        if (abs(k-i) == abs(x[k]-x[i]) || x[k] == x[i])
            // abs是C++的绝对值函数，任意两行的皇后不能够相邻或者同列
            return 0;
    return 1;
}

int queen(int t)
{
    if (t > n) { // 若是皇后全部能够摆完，即当放置的皇后超过n时，可行解个数加1，此时n必须大于0
        sum++;
        ans.push_back(vec);
    } else
        for (int i = 1; i <= n; i++) {// 通过枚举来确定一行皇后可以放的位置
            x[t] = i; // 标明第t个皇后放在第i列
            if (place(t)) { // 如果可以放在某一位置，则继续放下一皇后
                vec.push_back(node(t, i));
                queen(t+1);
                vec.pop_back();
            }
        }
    return sum;
}

signed main()
{
    while (cin>>n)
    {
        ans.clear();
        vec.clear();
        memset(x, 0, sizeof x);
        sum = 0;
        if (n == 0) break;
        queen(1);
        cout<<sum<<endl;
        for (auto e1:ans) {
            for (auto e2:e1)
                printf("(%d, %d) ", e2.x, e2.y);
            cout<<endl;
        }
    }
    return 0;
}
