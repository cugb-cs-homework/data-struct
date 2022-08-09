#include <iostream>
#include "trainmanage.h"
using namespace std;

signed main()
{
    trainmanage system;

    while (1) {
        system.menu();
        int opt;
        cin >> opt;

        if (opt == 0) break;
        else if (opt == 1) system.add();
        else if (opt == 2) system.remove();
        else if (opt == 3) system.search();
        else if (opt == 4) system.change();
        else if (opt == 5) system.display();
        else cout << "Unknown operation." << endl;
        cout << endl;
    }
    return 0;
}
