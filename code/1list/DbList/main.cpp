#include <iostream>
#include "dblist.h"
using namespace std;

signed main()
{
    char ch;

    cout << "opt-1: Initialize double list H" << endl;
    DbList<char> H;
    cout << endl;
    cout<<"opt-2: Inserts elements a,b,c,d, and e in sequence by using tail interpolation"
        << endl;

    for (char i = 'a'; i <= 'e'; ++i) {
        H.push_back(i);
        cout << "insert " << i << " succeed." << endl;
    }
    cout << endl;
    cout << "opt-3: Traverse double list H and the length of L" << endl;
    H.output();
    cout << H.length() << endl;
    cout << endl;
    cout << "opt-4: Check whether the double list H is empty" << endl;

    if (H.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;
    cout << endl;
    cout << "opt-5: Output the third element in the double list H" << endl;

    if (H.getData(3, ch)) cout << ch << endl;
    else cerr << "getData failed." << endl;
    cout << endl;
    cout << "opt-6: Output the position of element d" << endl;
    cout << H.search('d') << endl;
    cout << endl;
    cout << "opt-7: Insert the f element at the fourth element position" << endl;

    if (H.insert(4, 'f')) cout << "insert f succeed." << endl;
    else cout << "insert f failed." << endl;
    cout << endl;
    cout << "opt-8: Delete the third element of H" << endl;

    if (H.remove(3, ch)) cout << "remove " << ch << " succeed." << endl;
    else cerr << "remove " << ch << " failed." << endl;
    cout << endl;
    cout << "opt-9: Output double list H" << endl;
    H.output();
    cout << endl;
    cout << "opt-10: Release double list H" << endl;
    return 0;
}
