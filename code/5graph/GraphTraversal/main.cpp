#include <bits/stdc++.h>
using namespace std;
const int maxn = 15;

bool vis[maxn];
vector<int> vec, G[maxn];
int pre[maxn];

void dfsRec(int st)
{
    for (auto e:G[st]) {
        if (!vis[e]) {
            cout<<st<<"->"<<e<<endl;
            vec.push_back(e);
            vis[e] = 1;
            dfsRec(e);
        }
    }
}

void dfsUnrec()
{
    stack<int> sta;
    sta.push(1);
    vis[1] = 1;
    while (sta.size()) {
        int now = sta.top();
        if (now != 1) cout<<pre[now]<<"->"<<now<<endl;
        vec.push_back(now);
        sta.pop();
        vis[now] = 1;
        for (auto e: G[now])
            if (!vis[e]) {
                pre[e] = now;
                sta.push(e);
            }
    }
}

void bfs()
{
    vis[1] = 1;
    vec.push_back(1);
    queue<int> que;
    que.push(1);
    while (que.size()) {
        int now = que.front();
        que.pop();
        for (auto e:G[now]) {
            if (!vis[e]) {
                cout<<now<<"->"<<e<<endl;
                vec.push_back(e);
                vis[e] = 1;
                que.push(e);
            }
        }
    }
}

int main()
{
    int n, m;
    cin>>n>>m;
    while (m--) {
        int u, v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    cout<<"opt-1: dfsRec from node 1."<<endl;
    memset(vis, 0, sizeof vis);
    vec.push_back(1);
    vis[1] = 1;
    dfsRec(1);
    cout<<"Result: ";
    for (auto e:vec) cout<<e<<' ';
    cout<<endl<<endl;
    cout<<"opt-2: dfsUnrec from node 1."<<endl;
    memset(vis, 0, sizeof vis);
    vec.clear();
    dfsUnrec();
    for (auto e:vec) cout<<e<<' ';
    cout<<endl<<endl;
    cout<<"opt-3: bfs from node 1."<<endl;
    memset(vis, 0, sizeof vis);
    vec.clear();
    bfs();
    cout<<"Result: ";
    for (auto e:vec) cout<<e<<' ';
    cout<<endl<<endl;
    return 0;
}

/*
6 10
1 2
1 4
2 3
3 1
3 6
4 3
4 6
5 6
6 5
6 1
*/
