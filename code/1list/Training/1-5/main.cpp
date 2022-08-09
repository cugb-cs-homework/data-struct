#include <iostream>
#include "cirlist.h"
using namespace std;

void Josephus(int n, int s, int m)
{
    CirList<int> L; // 单循环链表写个函数就可以了

    for (int i = 1; i <= n; ++i) L.push_back(i);
    L.josephus(s, m);
}

signed main()
{
    Josephus(9, 1, 5);
    Josephus(9, 1, 0);
    Josephus(9, 1, 10);
    return 0;
}
