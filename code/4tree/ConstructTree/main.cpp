#include <iostream>

using namespace std;

struct node {
    char data;
    node *lchild, *rchild;
    node(char data, node *lchild = nullptr, node *rchild = nullptr) :
        data(data),
        lchild(lchild),
        rchild(rchild)
    {
    }
};

node *construct(string pre, string mid)
{
    int pos = mid.find(pre[0]);   // 第一个就是当前的根节点
    node *rt = new node(pre[0]);
    if (pos > 0) rt->lchild = construct(pre.substr(1, pos), mid.substr(0, pos)); // 左子树的前序和左子树的中序
    if (pos < (int)pre.size()-1) rt->rchild = construct(pre.substr(pos+1), mid.substr(pos+1)); // 右子树的前序和右子树的中序
    return rt;
}

void trv(ostream &os, node *rt)
{
    os<<rt->data;
    if (rt->lchild != nullptr || rt->rchild != nullptr) {
        os<<"(";
        if (rt->lchild != nullptr) trv(os, rt->lchild);
        os<<",";
        if (rt->rchild != nullptr) trv(os, rt->rchild);
        os<<")";
    }
}

signed main()
{
    string preorder = "ABECDFGHIJ", midorder = "EBCDAFHIGJ";
    node *rt = construct(preorder, midorder);
    trv(cout, rt);
    return 0;
}
