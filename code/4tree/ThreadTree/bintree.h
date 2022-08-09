#ifndef BINTREE_H
#define BINTREE_H
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

#include "bintreenode.h"

template<class T>
class BinTree
{
public:
    BinTree();
    BinTree(const BinTree<T> &A);   // 拷贝构造函数
    ~BinTree();
    void buildbyPre(const std::string &s);   // 前序遍历结果建树
    void Print(std::ostream &os);   // 输出二叉树
    int getLeaf();// 获取叶子数量
    int getHeight();  // 获取高度
    int getNum();  // 获取结点数量
    int getLevel(T e);    // 获取结点层次
    void getSon(T e); // 获取结点孩子
    BinTreeNode<T> *getRoot() const;    // 获取该树的根

    // 非递归用栈进行模拟
    void midRec(BinTreeNode<T> *p);    // 从结点递归中序
    void midUnrec(BinTreeNode<T> *p);  // 从结点非递归中序
    void preRec(BinTreeNode<T> *p);    // 从结点递归前序
    void preUnrec(BinTreeNode<T> *p);  // 从结点非递归前序
    void postRec(BinTreeNode<T> *p);   // 从结点递归后续
    void postUnrec(BinTreeNode<T> *p); // 从结点非递归后续

private:
    int height, leaf, num;  // 高度,叶子数量,结点数量
    BinTreeNode<T> *root;   // 根节点
    void release(BinTreeNode<T> *p); // 从结点递归向下释放结点
    BinTreeNode<T> *setNode(const std::string &str, int &pos); // 从串中根据指定位置生成结点并继续递推
    void print(std::ostream &os, BinTreeNode<T> *t);    // 广义表形式输出
    int calHeight(BinTreeNode<T> *p);   // 从结点递归向下计算高度(定义上来说是深度)
    BinTreeNode<T> *find(BinTreeNode<T> *p, T x);   // 辅助函数从结点递归向下找值为x的结点
    int calLevel(BinTreeNode<T> *p);    // 从结点向上遍历计算层次
    void copy(BinTreeNode<T> *p, BinTreeNode<T> *q);    // 结点之间深复制
};

template<class T>
BinTree<T>::BinTree() : height(0),
    leaf(0),
    num(0),
    root(nullptr)
{
// std::cout<<"BinTree builed succeed."<<std::endl;
}

template<class T>
BinTree<T>::BinTree(const BinTree<T> &A) : height(A.height),
    leaf(A.leaf),
    num(A.num)
{
    root = new BinTreeNode<T>(A.root);
    copy(this->root, A.root);
}

template<class T>
BinTree<T>::~BinTree()
{
    release(root);
// std::cout<<"BinTree has been released!"<<std::endl;
}

template<class T>
void BinTree<T>::release(BinTreeNode<T> *p)
{
    if (p == nullptr) return;
    release(p->lchild);
    release(p->rchild);
    delete p;
}

template<class T>
void BinTree<T>::copy(BinTreeNode<T> *p, BinTreeNode<T> *q)
{
    if (q->lchild != nullptr) {
        p->lchild = new BinTreeNode<T>(q->lchild);
        copy(p->lchild, q->lchild);
        p->lchild->father = p;
    }
    if (q->rchild != nullptr) {
        p->rchild = new BinTreeNode<T>(q->rchild);
        copy(p->rchild, q->rchild);
        p->rchild->father = p;
    }
}

template<class T>
void BinTree<T>::buildbyPre(const std::string &str)
{
    height = leaf = num = 0;
    if (str[0] != '#') {
        int pos = 0;
        root = setNode(str, pos);
        root->father = nullptr;
        height = calHeight(root);
    } else std::cerr<<"Empty BinTree"<<std::endl;
}

template<class T>
BinTreeNode<T> *BinTree<T>::setNode(const std::string &str, int &pos)   // 一定是要引用传值的
{
    BinTreeNode<T> *temp = new BinTreeNode<T>(str[pos]);
    ++pos;

    if (str[pos] != '#') {
        temp->lchild = setNode(str, pos);
        temp->lchild->father = temp;
    } else {
        temp->lchild = nullptr;
        ++pos;
    }

    if (str[pos] != '#') {
        temp->rchild = setNode(str, pos);
        temp->rchild->father = temp;
    } else {
        temp->rchild = nullptr;
        ++pos;
    }
    if (temp->lchild == nullptr && temp->rchild == nullptr) ++leaf;
    ++num;
    return temp;
}

template<class T>
void BinTree<T>::Print(std::ostream &os)
{
    print(os, this->root);
    os<<std::endl;
}

template<class T>
int BinTree<T>::getLeaf()
{
    return this->leaf;
}

template<class T>
int BinTree<T>::getHeight()
{
    return this->height;
}

template<class T>
int BinTree<T>::getNum()
{
    return num;
}

template<class T>
int BinTree<T>::getLevel(T e)
{
    return calLevel(find(root, e));
}

template<class T>
void BinTree<T>::print(std::ostream &os, BinTreeNode<T> *t)
{
    os<<t->data;
    if (t->lchild != nullptr || t->rchild != nullptr) {
        os<<"(";
        if (t->lchild != nullptr) print(os, t->lchild);
        os<<",";
        if (t->rchild != nullptr) print(os, t->rchild);
        os<<")";
    }
}

template<class T>
int BinTree<T>::calHeight(BinTreeNode<T> *p)
{
    if (p == nullptr) return 0;
    else return std::max(calHeight(p->lchild), calHeight(p->rchild))+1;
}

template<class T>
BinTreeNode<T> *BinTree<T>::find(BinTreeNode<T> *p, T x)
{
    if (p == nullptr) return nullptr;
    if (p->data == x) return p;
    BinTreeNode<T> *temp;
    if ((temp = find(p->lchild, x)) != nullptr) return temp;
    if ((temp = find(p->rchild, x)) != nullptr) return temp;
    return nullptr;
}

template<class T>
int BinTree<T>::calLevel(BinTreeNode<T> *p)
{
    if (p == nullptr) { // 空指针没有结点
        std::cerr<<"element not exist."<<std::endl;
        return 0;
    }
    int level = 1;  // 向上遍历确定层数
    while (p != this->root) {
        p = p->father;
        ++level;
    }
    return level;
}

template<class T>
void BinTree<T>::getSon(T e)
{
    BinTreeNode<T> *temp = find(root, e);
    if (temp != nullptr)
        printf("lchild: %c rchild: %c\n", temp->lchild->data, temp->rchild->data);
}

template<class T>
void BinTree<T>::midRec(BinTreeNode<T> *t)
{
    if (t == nullptr) return;
    midRec(t->lchild);
    std::cout<<t->data;
    midRec(t->rchild);
}

template<class T>
void BinTree<T>::midUnrec(BinTreeNode<T> *t)
{
    std::stack<BinTreeNode<T> *> S;
    std::string ans;
    while (t != nullptr) {
        S.push(t);
        t = t->lchild;
    }
    while (!S.empty()) {
        t = S.top();
        S.pop();
        ans += t->data;
        if (t->rchild != nullptr) {
            t = t->rchild;
            while (t != nullptr) {
                S.push(t);
                t = t->lchild;
            }
        }
    }
    std::cout<<ans;
}

template<class T>
void BinTree<T>::preRec(BinTreeNode<T> *p)
{
    if (p == nullptr) return;
    std::cout<<p->data;
    preRec(p->lchild);
    preRec(p->rchild);
}

template<class T>
void BinTree<T>::preUnrec(BinTreeNode<T> *p)
{
    std::stack<BinTreeNode<T> *> S;
    std::string ans;
    S.push(p);
    while (!S.empty()) {
        p = S.top();
        S.pop();
        ans += p->data;
        if (p->rchild != nullptr) S.push(p->rchild);
        if (p->lchild != nullptr) S.push(p->lchild);
    }
    std::cout<<ans;
}

template<class T>
void BinTree<T>::postRec(BinTreeNode<T> *p)
{
    if (p == nullptr) return;
    postRec(p->lchild);
    postRec(p->rchild);
    std::cout<<p->data;
}

template<class T>
void BinTree<T>::postUnrec(BinTreeNode<T> *p)
{
    std::stack<BinTreeNode<T> *> S;
    BinTreeNode<T> *lastroot = nullptr;
    std::string ans;
    while (p != nullptr) {
        S.push(p);
        p = p->lchild;
    }
    while (!S.empty()) {
        p = S.top();
        if (p->rchild != nullptr && p->rchild != lastroot) {
            p = p->rchild;
            while (p != nullptr) {
                S.push(p);
                p = p->lchild;
            }
        } else {
            ans += p->data;
            lastroot = p;
            S.pop();
        }
    }
    std::cout<<ans;
}

template<class T>
BinTreeNode<T> *BinTree<T>::getRoot() const
{
    return this->root;
}

#endif // BINTREE_H
