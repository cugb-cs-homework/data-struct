#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 1e3 + 5;

int n, cnt, temp[maxn];
bool vis[maxn];

void dfs(int pos)
{
    if (pos == n + 1) {
        ++cnt;

        for (int i = 1; i <= n; ++i) cout << temp[i] << ' ';
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            vis[i] = true;
            temp[pos] = i;
            dfs(pos + 1);
            vis[i] = false;
        }
    }
}

signed main()
{
    cout << "Input n: ";
    cin >> n;
    dfs(1);
    cout << "Total :" << cnt << endl;
    return 0;
}
