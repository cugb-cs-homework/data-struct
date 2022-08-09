#include <iostream>
#include <algorithm>
using namespace std;

bool binarySearch(int nums[], int len, int target)
{
    int left = 0;
    int right = len - 1;  // 注意查找区间为全闭区间

    while (left <= right) {  // 注意二分查找终止时为查找区间left>right
// cout<<"dubug: "<<left<<' '<<right<<endl;
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {// 锁定到某个target时返回
            cout<<"match succeed at pos: "<<mid<<endl;
            return true;
        } else if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        cout<<"match failed at pos: "<<mid<<endl;
    }
    return false;
}

signed main()
{
    int x = 5;
    int a[] = {3, 6, 2, 10, 1, 8, 5, 7, 4, 9};
    cout<<"sort before: ";
    for (auto e: a) cout<<e<<' ';
    cout<<endl;
    sort(a, a + 10);
    cout<<"sort  after: ";
    for (auto e:a) cout<<e<<' ';
    cout<<endl;
    bool flag = binarySearch(a, 10, x);
    if (flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
