#include <iostream>
#include "seqstack.h"

using namespace std;

signed main()
{
    char ch;

    cout << "opt-1: Initialize the sequence stack S" << endl;
    SeqStack<char> S;
    cout << endl;

    cout << "opt-2: Check whether the sequence stack S is empty" << endl;

    if (S.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;
    cout << endl;

    cout << "opt-3: Push elements a,b,c,d and e onto the stack" << endl;

    for (char i = 'a'; i <= 'e'; ++i) {
        S.push(i);
        cout << "push " << i << " succeed." << endl;
    }
    cout << endl;

    cout << "opt-4: Output the size of stack" << endl;
    cout << S.size() << endl;
    cout << endl;

    cout << "opt-5: Outputs elements from the bottom to the top of the stack" <<
        endl;
    cout << S << endl;

    cout << "opt-6: Output stack sequence" << endl;

    while (!S.empty()) {
        S.pop(ch);
        cout << ch << ' ';
    }
    cout << endl << endl;
    cout << "opt-7: Release SeqStack S" << endl;
    return 0;
}
