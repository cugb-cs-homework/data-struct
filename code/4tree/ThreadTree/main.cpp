#include <iostream>
#include "threadtree.h"
using namespace std;

BinTree<char> B;
string str = "ABC##E##DFY###G##";

signed main()
{
    B.buildbyPre(str);
    cout<<"opt-1: Build thread tree"<<endl;
    ThreadTree<char> T(B);
    cout<<"opt-2: Traverse the thread tree"<<endl;
    cout<<"Prerec traversal: ";
    T.preRec(T.getRoot());
    cout<<endl;
    cout<<"PreUnrec traversal: ";
    T.preUnrec(T.getRoot());
    cout<<endl;
    cout<<"Midrec traversal: ";
    T.midRec(T.getRoot());
    cout<<endl;
    cout<<"MidUnrec traversal: ";
    T.midUnrec(T.getRoot());
    cout<<endl;
    cout<<"Postrec traversal: ";
    T.postRec(T.getRoot());
    cout<<endl;
    cout<<"PostUnrec traversal: ";
    T.postUnrec(T.getRoot());
    cout<<endl<<endl;
    cout<<"opt-3: Find the pre and post node of B"<<endl;
    T.findPreAndNext('B');
    cout<<endl;
    cout<<"opt-4: Insert character I at pos of B lchild"<<endl;
    cout<<"Insert before the pre and post node of B"<<endl;
    T.findPreAndNext('B');
    T.InsertLchild('I', 'B');
    cout<<"Insert after the pre and post node of B"<<endl;
    T.findPreAndNext('B');
    cout<<endl;
    cout<<"opt-5: Release the thread tree";
    cout<<endl;
    return 0;
}
