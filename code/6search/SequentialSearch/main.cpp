#include <iostream>

using namespace std;

signed main()
{
    int x = 5;
    int a[] = {3, 6, 2, 10, 1, 8, 5, 7, 4, 9};
    bool flag = false;
    for (int i = 0; i < 10; ++i) {
        if (a[i] == x) {
            cout<<"match succeed at pos: "<<i<<endl;
            flag = true;
            break;
        } else cout<<"match failed at pos: "<<i<<endl;
    }
    if (flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
