#include <iostream>
#include "seqqueue.h"
using namespace std;

signed main()
{
    char ch;

    cout << "opt-1: Initialize the sequence queue Q" << endl;
    SeqQueue<char> Q;
    cout << endl;
    cout << "opt-2: Check whether the sequence queue Q is empty" << endl;

    if (Q.empty()) cout << "Yes" << endl;
    else cout << "No" << endl;
    cout << endl;
    cout << "opt-3: Push elements a,b,c into the queue" << endl;

    for (char i = 'a'; i <= 'c'; ++i) {
        Q.push(i);
        cout << "push " << i << " succeed." << endl;
    }
    cout << endl;
    cout << "opt-4: Extract an element and print the element" << endl;
    Q.pop(ch);
    cout << ch << endl;
    cout << endl;
    cout << "opt-5: Out the size of queue" << endl;
    cout << Q.size() << endl;
    cout << endl;
    cout << "opt-6: Push elements d,e,f into the queue" << endl;

    for (char i = 'd'; i <= 'f'; ++i) {
        Q.push(i);
        cout << "push " << i << " succeed." << endl;
    }
    cout << endl;
    cout << "opt-7: Output queue sequence" << endl;

    while (!Q.empty()) {
        Q.pop(ch);
        cout << ch << ' ';
    }
    cout << endl << endl;
    cout << "opt-8: Release SeqQueue Q" << endl;
    return 0;
}
