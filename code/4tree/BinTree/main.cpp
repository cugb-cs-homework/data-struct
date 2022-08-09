#include <iostream>
#include <string>
#include "BinTree.h"
using namespace std;

string str = "ABC##E##DFY###G##";
signed main()
{
    cout<<"opt-1: Build binary tree"<<endl;
    BinTree<char> B;
    B.buildbyPre(str);
    cout<<endl;

    cout<<"opt-2: Traverse the binary tree"<<endl;
    cout<<"Prerec traversal: ";
    B.preRec(B.getRoot());
    cout<<endl;
    cout<<"PreUnrec traversal: ";
    B.preUnrec(B.getRoot());
    cout<<endl;
    cout<<"Midrec traversal: ";
    B.midRec(B.getRoot());
    cout<<endl;
    cout<<"MidUnrec traversal: ";
    B.midUnrec(B.getRoot());
    cout<<endl;
    cout<<"Postrec traversal: ";
    B.postRec(B.getRoot());
    cout<<endl;
    cout<<"PostUnrec traversal: ";
    B.postUnrec(B.getRoot());
    cout<<endl<<endl;
    cout<<"opt-3: Output binary tree generalized table"<<endl;
    B.Print(cout);
    cout<<endl;
    cout<<"opt-4: Output the children of node D"<<endl;
    B.getSon('D');
    cout<<endl;
    cout<<"opt-5: Output the number of leaf nodes in the binary tree"<<endl;
    cout<<B.getLeaf()<<endl;
    cout<<endl;
    cout<<"opt-6: Output the height of the binary tree"<<endl;
    cout<<B.getHeight()<<endl;
    cout<<endl;
    cout<<"opt-7: The number of levels of output node D"<<endl;
    cout<<B.getLevel('D')<<endl;
    cout<<endl;
    cout<<"opt-8: Release the binary tree";
    cout<<endl;
    return 0;
}
