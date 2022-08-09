#include <iostream>

using namespace std;

// 标从1开始,0作为哨兵位
const int n = 10;
int arr[n+1] = {-1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

void dirInsertSort()
{
    for (int i = 2; i <= n; i++) {
        if (arr[i] <= arr[i-1]) {
            arr[0] = arr[i];
            int j;
            for (j = i-1; arr[0] < arr[j]; --j)
                arr[j+1] = arr[j];
            arr[j+1] = arr[0];
            cout<<"confirm element "<<arr[j+1]<<" pos--> ";
            for (int i = 1; i <= n; ++i) cout<<arr[i]<<' ';
            cout<<endl;
        }
    }
}

int main()
{
    cout<<"sort before: ";
    for (int i = 1; i <= n; ++i) cout<<arr[i]<<' ';
    cout<<endl;
    dirInsertSort();
    cout<<"sort after: ";
    for (int i = 1; i <= n; ++i) cout<<arr[i]<<' ';
    cout<<endl;
    return 0;
}
