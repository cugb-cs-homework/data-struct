#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 15;
int n, m;
int matrix[maxn][maxn];
struct edge {
    int v, c;
    edge(int v, int c) : v(v),
        c(c)
    {
    }
};

vector<edge> G[maxn];

void init()
{
    memset(matrix, 0x3f, sizeof matrix);
    for (int i = 0; i < maxn; ++i) {
        matrix[i][i] = 0;
        G[i].clear();
    }
}

int main()
{
    cin>>n>>m;
    init();
    while (m--) {
        int u, v, w;
        cin>>u>>v>>w;
        matrix[u][v] = w;
    }
    cout<<"opt-1: Generate adjacency matrix from graph."<<endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            if (matrix[i][j] != inf)
                printf("(%d,%d,%d) \t", i, j, matrix[i][j]);
            else printf("(%d,%d,%s)\t", i, j, "non");
        cout<<endl;
    }
    cout<<endl;
    cout<<"opt-2: Generate adjacency list from adjacency matrix."<<endl;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (matrix[i][j] != inf) G[i].push_back(edge(j, matrix[i][j]));
        }
    for (int i = 1; i <= n; ++i) {
        cout<<"start at "<<i<<"--> ";
        for (auto e:G[i])
            if (e.v != i)
                printf("(%d,%d) ", e.v, e.c);
        cout<<endl;
    }
    cout<<endl;

    cout<<"opt-3: Generate adjacency matrix from adjacency list."<<endl;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j) {
            if (i == j) matrix[i][j] = 0;
            else matrix[i][j] = inf;
        }
    for (int i = 1; i <= n; ++i)
        for (auto e:G[i])
            matrix[i][e.v] = e.c;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j)
            if (matrix[i][j] != inf)
                printf("(%d,%d,%d) \t", i, j, matrix[i][j]);
            else printf("(%d,%d,%s)\t", i, j, "non");
        cout<<endl;
    }
    return 0;
}

/*
6 10
1 2 5
2 3 4
4 3 5
5 4 5
6 5 1
6 1 3
3 1 8
1 4 7
3 6 9
4 6 6
*/
