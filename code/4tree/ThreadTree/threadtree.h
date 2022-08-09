#ifndef THREADTREE_H
#define THREADTREE_H
#include "threadtreenode.h"
#include "bintree.h"

template<class T>
class ThreadTree
{
public:
    ThreadTree();
    ThreadTree(const BinTree<T> &A);  // 注意必须将函数声明为const因为内部调用了常函数getRoot()
    ~ThreadTree();
    void findPreAndNext(T x);   // 找到值为x结点的前驱和后继结点
    void InsertLchild(T x, T y);    // 将值为x节点插入到值为y当前节点的左子树(前提建立在了结点的权值唯一)
    // 非递归用栈进行模拟
    void midRec(ThreadTreeNode<T> *p);    // 从结点递归中序
    void midUnrec(ThreadTreeNode<T> *p);  // 从结点非递归中序
    void preRec(ThreadTreeNode<T> *p);    // 从结点递归前序
    void preUnrec(ThreadTreeNode<T> *p);  // 从结点非递归前序
    void postRec(ThreadTreeNode<T> *p);   // 从结点递归后续
    void postUnrec(ThreadTreeNode<T> *p); // 从结点非递归后续
    ThreadTreeNode<T> *getRoot();
private:
    ThreadTreeNode<T> *root;    // 根节点
    void release(ThreadTreeNode<T> *p);
    void threadInit(ThreadTreeNode<T> *now, ThreadTreeNode<T> * &pre);
    ThreadTreeNode<T> *find(ThreadTreeNode<T> *p, T x);
    void copy(ThreadTreeNode<T> *p, const BinTreeNode<T> *q);
    ThreadTreeNode<T> *pre(ThreadTreeNode<T> *p);
    ThreadTreeNode<T> *post(ThreadTreeNode<T> *p);
    ThreadTreeNode<T> *last(ThreadTreeNode<T> *p);
    ThreadTreeNode<T> *first(ThreadTreeNode<T> *p);
};

template<class T>
ThreadTree<T>::ThreadTree() : root(nullptr)
{
    std::cout<<"ThreadTree builed succeed."<<std::endl;
}

template<class T>
ThreadTree<T>::ThreadTree(const BinTree<T> &A)
{
    if (A.getRoot() == nullptr) {
        std::cerr<<"ThreadTree build failed."<<std::endl;
        return;
    }
    this->root = new ThreadTreeNode<T>(A.getRoot()->data);
    copy(root, A.getRoot());
    ThreadTreeNode<T> *prep = nullptr;    // 空结点
    threadInit(this->root, prep);
    prep->rtag = 1;
    std::cout<<"ThreadTree builed succeed."<<std::endl;
}

template<class T>
ThreadTree<T>::~ThreadTree()
{
    release(root);
    std::cout<<"ThreadTree has been released!"<<std::endl;
}

template<class T>
void ThreadTree<T>::findPreAndNext(T x)
{
    ThreadTreeNode<T> *temp = find(root, x);
    if (temp != nullptr) {
        if (pre(temp) != nullptr) std::cout<<"pre data: "<<pre(temp)->data<<std::endl;
        else std::cout<<"pre data: #"<<std::endl;
        if (post(temp) != nullptr) std::cout<<"post data: "<<post(temp)->data<<std::endl;
        else std::cout<<"post data: #"<<std::endl;
    }
}

template<class T>
void ThreadTree<T>::InsertLchild(T x, T y)
{
    ThreadTreeNode<T> *temp = find(this->root, y);
    if (temp == nullptr) {
        std::cout<<"dont find the prenode you want to insert."<<std::endl;
        return;
    }
    ThreadTreeNode<T> *prep = pre(temp);
    ThreadTreeNode<T> *newnode = new ThreadTreeNode<T>(x, temp->lchild, temp, temp);// 该节点的后继就是temp
    newnode->rtag = 1, newnode->ltag = temp->ltag;

    if (temp->ltag == 0) temp->lchild->father = newnode; // 设置结点原左子女的信息
    if (prep != nullptr && prep->rtag) prep->rchild = newnode;
    temp->lchild = newnode;  // 设置当前结点的左侧信息
    temp->ltag = 0;
}

template<class T>
void ThreadTree<T>::midRec(ThreadTreeNode<T> *p)
{
    if (p == nullptr) return;
    if (p->ltag != 1) midRec(p->lchild);
    std::cout<<p->data;
    if (p->rtag != 1) midRec(p->rchild);
}

template<class T>
void ThreadTree<T>::midUnrec(ThreadTreeNode<T> *p)
{
    p = first(p);
    while (p) {
        std::cout<<p->data;
        p = post(p);
    }
}

template<class T>
void ThreadTree<T>::preRec(ThreadTreeNode<T> *p)
{
    if (p == nullptr) return;
    std::cout<<p->data;
    if (p->ltag != 1) preRec(p->lchild);
    if (p->rtag != 1) preRec(p->rchild);
}

template<class T>
void ThreadTree<T>::preUnrec(ThreadTreeNode<T> *p)
{
    while (p != nullptr) {
        std::cout<<p->data;
        if (p->ltag != 1) p = p->lchild;
        else if (p->ltag != 1) p = p->rchild;
        else {
            while (p && p->rtag) p = p->rchild;
            if (p != nullptr) p = p->rchild;
        }
    }
}

template<class T>
void ThreadTree<T>::postUnrec(ThreadTreeNode<T> *p)
{
    while (p->rtag == 0 || p->ltag == 0) {
        if (p->ltag == 0) p = p->lchild;
        else p = p->rchild;
    }
    std::cout<<p->data;
    while (p->father != nullptr) {
        if (p == p->father->rchild || p->father->rtag == 1) p = p->father;
        else {
            p = p->father->rchild;
            while (p->rtag == 0 || p->ltag == 0) {
                if (p->ltag == 0) p = p->lchild;
                else p = p->rchild;
            }
        }
        std::cout<<p->data;
    }
}

template<class T>
void ThreadTree<T>::postRec(ThreadTreeNode<T> *p)
{
    if (p == nullptr) return;
    if (p->ltag != 1) preRec(p->lchild);
    if (p->rtag != 1) preRec(p->rchild);
    std::cout<<p->data;
}

template<class T>
ThreadTreeNode<T> *ThreadTree<T>::getRoot()
{
    return this->root;
}

template<class T>
void ThreadTree<T>::release(ThreadTreeNode<T> *p)
{
    if (p->lchild != nullptr && p->ltag == 0) release(p->lchild);
    if (p->rchild != nullptr && p->rtag == 0) release(p->rchild);
    delete(p);
}

template<class T>
void ThreadTree<T>::threadInit(ThreadTreeNode<T> *now, ThreadTreeNode<T> * &pre)
{
    if (now == nullptr) return;
    if (now->lchild != nullptr) threadInit(now->lchild, pre);
    else now->lchild = pre, now->ltag = 1;
    if (pre != nullptr && pre->rchild == nullptr) pre->rchild = now, pre->rtag = 1;
    pre = now;
    threadInit(now->rchild, pre);
}

template<class T>
ThreadTreeNode<T> *ThreadTree<T>::find(ThreadTreeNode<T> *p, T x)
{
    if (p == nullptr) return nullptr;
    if (x == p->data) return p;
    ThreadTreeNode<T> *temp;
    if (p->ltag == 0 && (temp = find(p->lchild, x)) != nullptr) return temp;
    if (p->rtag == 0 && (temp = find(p->rchild, x)) != nullptr) return temp;
    return nullptr;
}

template<class T>
void ThreadTree<T>::copy(ThreadTreeNode<T> *p, const BinTreeNode<T> *q)
{
    if (q->lchild != nullptr) {
        p->lchild = new ThreadTreeNode<T>(q->lchild->data);
        copy(p->lchild, q->lchild);
        p->lchild->father = p;
    }
    if (q->rchild != nullptr) {
        p->rchild = new ThreadTreeNode<T>(q->rchild->data);
        copy(p->rchild, q->rchild);
        p->rchild->father = p;
    }
}

template<class T>
ThreadTreeNode<T> *ThreadTree<T>::pre(ThreadTreeNode<T> *p)
{
    if (p->ltag == 1) return p->lchild;
    else return last(p->lchild); // 说明需要从头重新遍历找前驱结点
}

template<class T>
ThreadTreeNode<T> *ThreadTree<T>::post(ThreadTreeNode<T> *p)
{
    if (p->rtag == 1) return p->rchild;
    else return first(p->rchild);   // 说明需要从头重新遍历找后继结点
}

template<class T>
ThreadTreeNode<T> *ThreadTree<T>::last(ThreadTreeNode<T> *p)
{
    while (p->rtag != 1) p = p->rchild;
    return p;
}

template<class T>
ThreadTreeNode<T> *ThreadTree<T>::first(ThreadTreeNode<T> *p)
{
    while (p->ltag != 1) p = p->lchild;
    return p;
}

#endif // THREADTREE_H
