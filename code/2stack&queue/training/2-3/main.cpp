#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
const int maxn = 15;
const int dir[][2] = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };
struct node {
    int x, y;
    node() = default;
    node(int x, int y) : x(x),
        y(y)
    {
    }

    node operator=(const node &A)
    {
        this->x = A.x, this->y = A.y;
        return *this;
    }

    bool operator==(const node &A)
    {
        return this->x == A.x && this->y == A.y;
    }
};
int minn = 15;
stack<node> ans;
bool vis[maxn][maxn];
node pre[maxn][maxn]; // 前序结点

node st(1, 1), ed(5, 5);
bool mz[maxn][maxn] = {
    { 0, 0, 0, 0, 0, 0, 0 },
    { 0, 1, 1, 1, 1, 1, 0 },
    { 0, 1, 0, 0, 1, 0, 0 },
    { 0, 1, 0, 1, 1, 1, 0 },
    { 0, 1, 1, 1, 0, 1, 0 },
    { 0, 1, 0, 0, 1, 1, 0 },
    { 0, 0, 0, 0, 0, 0, 0 }
};

bool check(node now)
{
    return mz[now.x][now.y] == 1 && vis[now.x][now.y] == 0;
}

void trv(stack<node> s)
{
    node temp = s.top();

    cout << "(" << temp.x << "," << temp.y << ")";
    s.pop();

    while (s.size()) {
        temp = s.top();
        cout << "->(" << temp.x << "," << temp.y << ")";
        s.pop();
    }
    cout << endl;
}

void dfs(node now, int depth)
{
    vis[now.x][now.y] = 1;

    if (now == ed) {
        stack<node> temp;
        node a = now;

        while (!(a == st)) {
            temp.push(a);
            a = pre[a.x][a.y];
        }
        temp.push(st);
        trv(temp);

        if (depth < minn) minn = depth, ans = temp;
        return;
    }

    for (int i = 0; i < 4; ++i) {
        node nex(now.x + dir[i][0], now.y + dir[i][1]);

        if (check(nex)) {
            pre[nex.x][nex.y] = now;
            dfs(nex, depth + 1);
            vis[nex.x][nex.y] = 0;
        }
    }
}

signed main()
{
    dfs(st, 0);
    cout << "Min len: " << minn << endl;
    cout << "Min route: ";
    trv(ans);
    return 0;
}
