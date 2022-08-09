#include <iostream>

using namespace std;
int A[5] = { 5, 33, 26, 78, 25 }; // 分治

int getmax(int l, int r)
{
    if (l == r) return A[l];

    int mid = (l + r) >> 1;
    return max(getmax(l, mid), getmax(mid + 1, r));
}

int getsum(int l, int r)
{
    if (l == r) return A[l];

    int mid = (l + r) >> 1;
    return getsum(l, mid) + getsum(mid + 1, r);
}

double getaverage(int l, int r)
{
    if (l == r) return A[l];

    int mid = (l + r) >> 1;
    return (getaverage(l,
                       mid) * (mid - l + 1)+getaverage(mid + 1, r) * (r - mid)) * 1.0 / (r - l + 1);
}

signed main()
{
    for (auto e:A) cout<<e<<' ';
    cout<<endl;
    cout << "max element: " << getmax(0, 4) << endl;
    cout << "sum: " << getsum(0, 4) << endl;
    cout << "average: " << getaverage(0, 4) << endl;
    return 0;
}
