#include <iostream>
#include "list.h"

using namespace std;

signed main()
{
    List<int> L, res;
    int a[10] = { 1, 9, 2, 8, 3, 7, 4, 6, 5 };

    for (auto e:a) L.push_back(e);
    int x = 5;
    int temp;

    for (int i = 1; i <= 10; ++i) {
        L.getData(i, temp);

        if (temp < x) res.push_back(temp);
    }

    for (int i = 1; i <= 10; ++i) {
        L.getData(i, temp);

        if (temp >= x) res.push_back(temp);
    }
    L.output();
    cout << "x: " << x << endl;
    res.output();
    return 0;
}
