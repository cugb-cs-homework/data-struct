#include <iostream>
#include "seqqueue.h"

using namespace std;

void menu()
{
    std::cout << "================================" << std::endl;
    std::cout << "**** hospital manage system ****" << std::endl;
    std::cout << "****    [0] exit            ****" << std::endl;
    std::cout << "****    [1] line up         ****" << std::endl;
    std::cout << "****    [2] see a doctor    ****" << std::endl;
    std::cout << "****    [3] check queue     ****" << std::endl;
    std::cout << "****    [4] in order        ****" << std::endl;
    std::cout << "================================" << std::endl;
    std::cout << "Input your choice: ";
}

signed main()
{
    SeqQueue<string> Q;
    string temp;

    while (1) {
        menu();
        int opt;
        cin >> opt;

        if (opt == 0) {
            cout << "Thanks for using!" << endl;
            break;
        } else if (opt == 1) {
            cout << "Input your Medical record: ";
            cin >> temp;
            Q.push(temp);
            cout << temp << " in queue" << endl;
        } else if (opt == 2) {
            if (Q.empty()) cout << "No queues." << endl;
            else {
                Q.pop(temp);
                cout << temp << " see a doctor." << endl;
            }
        } else if (opt == 3) {
            SeqQueue<string> q(Q);

            while (!q.empty()) {
                q.pop(temp);
                cout << temp << " in queue." << endl;
            }
        } else if (opt == 4) {
            while (!Q.empty()) {
                Q.pop(temp);
                cout << temp << " see a doctor." << endl;
            }
        } else cout << "Invalid operation." << endl;
        cout << endl;
    }
    return 0;
}
