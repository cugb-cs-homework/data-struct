#include <iostream>

using namespace std;
const int n = 10;
int arr[n+1] = {-1, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

void quickSort(int low, int high)
{
    int i, j, key;
    if (low > high) return;
    i = low;
    j = high;
    key = arr[low];
    while (i != j) {
        while (j > i && arr[j] >= key) j--;
        while (i < j && arr[j] <= key) i++;
        if (i != j) {
            int middle = arr[i];
            arr[i] = arr[j];
            arr[j] = middle;
        }
    }
    arr[low] = arr[i];
    arr[i] = key;
    cout<<"confirm element "<<arr[i]<<" pos-->";
    for (int i = 1; i <= n; ++i) cout<<arr[i]<<' ';
    cout<<endl;
    quickSort(low, i-1);
    quickSort(i+1, high);
}

signed main()
{
    cout<<"sort before: ";
    for (int i = 1; i <= n; ++i) cout<<arr[i]<<' ';
    cout<<endl;
    quickSort(1, 10);
    cout<<"sort after: ";
    for (int i = 1; i <= n; ++i) cout<<arr[i]<<' ';
    cout<<endl;
    return 0;
}
