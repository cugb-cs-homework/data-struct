#include <iostream>
#include "seqlist.h"

using namespace std;

signed main()
{
    char ch;

    cout << "opt-1: Initialize sequence list L" << endl;
    SeqList<char> L(1);
    cout << endl;
    cout
        <<"opt-2: Inserts elements a,b,c,d, and e in sequence by using tail interpolation"
        << endl;

    for (char i = 'a'; i <= 'e'; ++i)
        if (L.push_back(i)) cout << "insert " << i << " succeed." << endl;
        else cerr << "insert " << i << " failed." << endl;
    cout << endl;
    cout << "opt-3: Traverse sequence list L and the length of L" << endl;
    L.output();
    cout << L.length() << endl;

    cout << "opt-4: Check whether the sequence list L is empty" << endl;

    if (L.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;
    cout << endl;
    cout << "opt-5: Output the third element in the sequence list L" << endl;

    if (L.getData(2, ch)) cout << ch << endl;
    else cerr << "getData failed." << endl;
    cout << endl;
    cout << "opt-6: Output the position of element d" << endl;
    cout << L.search('d') << endl;
    cout << endl;
    cout << "opt-7: Insert the f element at the fourth element position" << endl;

    if (L.insert(3, 'f')) cout << "insert f succeed." << endl;
    else cout << "insert f failed." << endl;
    cout << endl;
    cout << "opt-8: Delete the third element of L" << endl;

    if (L.remove(2, ch)) cout << "remove " << ch << " succeed." << endl;
    else cerr << "remove " << ch << " failed." << endl;
    cout << endl;
    cout << "opt-9: Output sequence list L" << endl;
    L.output();
    cout << endl;
    cout << "opt-10: Release sequence list L" << endl;
    return 0;
}
