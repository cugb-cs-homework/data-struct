#ifndef BINTREENODE_H
#define BINTREENODE_H

template<class T>
class BinTreeNode
{
public:
    T data;
    BinTreeNode<T> *lchild, *rchild, *father;
    BinTreeNode(T data, BinTreeNode<T> *lchild = nullptr, BinTreeNode<T> *rchild = nullptr,
                BinTreeNode<T> *father = nullptr);
    BinTreeNode(const BinTreeNode<T> &N);
    ~BinTreeNode();
};

template<class T>
BinTreeNode<T>::BinTreeNode(T data, BinTreeNode<T> *lchild, BinTreeNode<T> *rchild,
                            BinTreeNode<T> *father) :
    data(data),
    lchild(lchild),
    rchild(rchild),
    father(father)
{
}

template<class T>
BinTreeNode<T>::BinTreeNode(const BinTreeNode<T> &N) :
    data(N.data),
    lchild(N.lchild),
    rchild(N.rchild),
    father(N.father)
{
}

template<class T>
BinTreeNode<T>::~BinTreeNode()
{
    delete lchild;
    delete rchild;
    delete father;
}

#endif // BINTREENODE_H
