#include <iostream>
#include <string>
#include "seqstack.h"
#include "list.h"

using namespace std;

signed main()
{
    string str = "hello_world";
    List<char> L, RL;

    for (auto e:str) L.push_back(e);
    SeqStack<char> S;
    cout << "before: "; L.output();
    char ch;

    for (int i = 1; i <= L.length(); ++i) {
        L.getData(i, ch);
        S.push(ch);
    }

    while (!S.empty()) {
        S.pop(ch);
        RL.push_back(ch);
    }
    cout << "after: "; RL.output();
    return 0;
}
