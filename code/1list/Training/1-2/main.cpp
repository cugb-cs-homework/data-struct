#include <iostream>
#include "listset.h"
using namespace std;

signed main()
{
    ListSet<int> s1, s2;
    int a[5] = { 1, 2, 3, 4, 5 }, b[5] = { 3, 4, 5, 6, 7 };

    for (auto e:a) s1.insert(e);

    for (auto e:b) s2.insert(e);
    cout << "s1: ";
    s1.output();
    cout << "s2: ";
    s2.output();

    ListSet<int> s3(s1);
    s3 += s2;
    cout << "s1+s2: ";
    s3.output();

    s3 = s1;
    s3 ^= s2;
    cout << "s1^s2: ";
    s3.output();

    s3 = s1;
    s3 -= s2;
    cout << "s1-=s2: ";
    s3.output();
    return 0;
}
