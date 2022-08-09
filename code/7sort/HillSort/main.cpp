#include <iostream>

using namespace std;

const int n = 10, t = 4;
int arr[n+1] = {-1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}, dlta[4] = {5, 3, 2, 1};

void HillInsert(int k)
{
    for (int i = k+1; i <= n; i++) {
        if (arr[i] < arr[i-k]) {
            arr[0] = arr[i];
            int j;
            for (j = i-k; j > 0 && arr[0] < arr[j]; j -= k)
                arr[j+k] = arr[j];
            arr[j+k] = arr[0];
        }
    }
}

void HillSort()
{
    for (int i = 0; i < t; ++i) {
        HillInsert(dlta[i]);
        cout<<"swap element at dlta: "<<dlta[i]<<"--> ";
        for (int i = 1; i <= n; ++i) cout<<arr[i]<<' ';
        cout<<endl;
    }
}

signed main()
{
    cout<<"sort before: ";
    for (int i = 1; i <= n; ++i) cout<<arr[i]<<' ';
    cout<<endl;
    HillSort();
    cout<<"sort after: ";
    for (int i = 1; i <= n; ++i) cout<<arr[i]<<' ';
    cout<<endl;
    return 0;
}
