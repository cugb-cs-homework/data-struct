#include <iostream>
#include <map>
#include "seqstack.h"
using namespace std;

map<char, int> val;
char op[] = "()-+/*"; // 优先级
SeqStack<char> S;
SeqStack<int> ans;
string function;

inline bool check(string input)
{
    return input[0] >= '0' && input[0] <= '9';
}

void getsum(char op)
{
    int a, b, x;

    ans.top(b);
    ans.pop(x);
    ans.top(a);
    ans.pop(x);
    int sum = 0;

    if (op == '*') sum = a * b;
    else if (op == '/') sum = a / b;
    else if (op == '+') sum = a + b;
    else sum = a - b;
    ans.push(sum);
}

signed main()
{
    for (int i = 0; i < 6; ++i) val[op[i]] = i;

    // freopen("in.txt", "r", stdin);
    string input;
    char ch, x;

    while (cin >> input) { // 1 * 2 + 5 - ( 6 + 7 - ( 5 + 71 ) * 19 ) - 15 * 14
        if (check(input)) {
            function += input;
            int num = stoi(input);

            // cout << num << ' ';
            ans.push(num); // 数字压入栈
            continue;
        }
        ch = input[0];

        switch (ch) {
        case '(':
            S.push(ch);
            break;

        case ')':
            S.top(x);

            while (!S.empty() && x != '(') {
                function += x;

                // cout << x << ' ';
                getsum(x);
                S.pop(x);
                S.top(x);
            }
            S.pop(x);
            break;

        default:
            S.top(x);

            while (!S.empty() && val[x] >= val[ch]) {
                function += x;

                // cout << x << ' ';
                getsum(x);
                S.pop(x);
                S.top(x);
            }
            S.push(ch);
            break;
        }
    }

    while (!S.empty()) {
        S.top(x);
        function += x;

        // cout << x << ' ';
        getsum(x);
        S.pop(x);
    }
    int res;
    ans.top(res);
    cout << function << endl;
    cout << res << endl;
    return 0;
}
