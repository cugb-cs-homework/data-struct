 #ifndef THREADTREENODE_H
#define THREADTREENODE_H

template<class T>
class ThreadTreeNode
{
public:
    T data;
    ThreadTreeNode<T> *lchild, *rchild, *father;
    bool ltag, rtag;
    ThreadTreeNode(T data, ThreadTreeNode<T> *lchild = nullptr, ThreadTreeNode<T> *rchild = nullptr,
                   ThreadTreeNode<T> *father = nullptr, bool ltag = 0, bool rtag = 0);
    ThreadTreeNode(const ThreadTreeNode<T> &N);
    ~ThreadTreeNode();
};

template<class T>
ThreadTreeNode<T>::ThreadTreeNode(const ThreadTreeNode<T> &N) :
    lchild(N.lchild),
    rchild(N.rchild),
    father(N.father),
    ltag(N.ltag),
    rtag(N.rtag)
{
}

template<class T>
ThreadTreeNode<T>::~ThreadTreeNode()
{
    delete(lchild);
    delete(rchild);
    delete(father);
}

template<class T>
ThreadTreeNode<T>::ThreadTreeNode(T data, ThreadTreeNode<T> *lchild, ThreadTreeNode<T> *rchild,
                                  ThreadTreeNode<T> *father, bool ltag, bool rtag) :
    data(data),
    lchild(lchild),
    rchild(rchild),
    father(father),
    ltag(ltag),
    rtag(rtag)
{
}

#endif // THREADTREENODE_H
