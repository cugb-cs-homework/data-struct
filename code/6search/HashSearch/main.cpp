#include <iostream>

using namespace std;

int val[] = {16, 74, 60, 43, 54, 90, 46, 31, 29, 88, 77}, A[13];

void hashinsert(int key)    // 将key插入hash
{
    int pos = key%13;
    while (A[pos]) {
        pos = (pos+1)%13;
        if (pos == key%13) {
            cout<<"Table is full."<<endl;
            return;
        }
    }
    A[pos] = key;
    cout<<"insert "<<key<<" at pos: "<<pos<<endl;
}

int hashfind(int key)   // 在hash中查找key所处的下标
{
    int pos = key%13;
    while (A[pos] != key) {
        pos = (pos+1)%13;
        if (pos == key%13) {
            cout<<"Did not find it."<<endl;
            return -1;
        }
    }
    return pos;
}

void hasherase(int key)
{
    int pos = hashfind(key);
    if (pos != -1) {
        A[pos] = 0;
        cout<<"erase "<<key<<" at pos: "<<pos<<endl;
        return;
    }
}

signed main()
{
    cout<<"opt-1: Construct the hash table."<<endl;
    for (int i = 0; i < 11; ++i) hashinsert(val[i]);
    for (auto e:A) cout<<e<<' ';
    cout<<endl;
    cout<<endl;
    cout<<"opt-2: Find the keyword 29."<<endl;
    cout<<hashfind(29)<<endl;
    cout<<endl;
    cout<<"opt-3: Delete 77 and insert it again."<<endl;
    hasherase(77);
    hashinsert(77);
    cout<<endl;
    cout<<"Final table."<<endl;
    for (auto e:A) cout<<e<<' ';
    return 0;
}
