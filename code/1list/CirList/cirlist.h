#ifndef CIRLIST_H
#define CIRLIST_H
#include "cirlistnode.h"

template<class T>
class CirList
{
public:

    CirList();
    CirList(const CirList<T> &L) = default;
    ~CirList();
    int  length() const;           // 顺序表当前长度
    bool empty() const;            // 判断顺序表是否为空
    bool valid(int pos) const;     // 判断访问下标是否合法
    bool getData(int pos, T &x)const;      // 获取下标对应元素并保存在x
    bool setData(int pos, const T &e);      // 设置下标对应元素
    int  search(const T &e) const; // 寻找元素在表中的下标
    bool insert(int pos, const T &e);       // 在指定下标插入元素
    void push_back(const T &e);    // 尾插法插入元素
    bool remove(int pos, T &x);            // 除指定下标元素并将删除元素保存在x
    void output() const;           // 遍历表中元素

private:

    CirListNode<T> *head, *rear;
    int sz = 0;
};

template<class T>
CirList<T>::CirList()
{
    this->head = new CirListNode<T>;
    this->head->next = head;
    this->rear = this->head;
    this->sz = 0;
    std::cout << "CirList initialized." << std::endl;
}

template<class T>
CirList<T>::~CirList()
{
    CirListNode<T> *temp1 = this->head->next, *temp2; // 考虑释放空表情况

    delete head;

    while (temp1 != head) {
        temp2 = temp1;
        temp1 = temp1->next;
        delete temp2;
    }
    this->sz = 0;
    std::cout << "CirList destructed." << std::endl;
}

template<class T>
int CirList<T>::length() const
{
    return this->sz;
}

template<class T>
bool CirList<T>::empty() const
{
    return this->sz == 0;
}

template<class T>
bool CirList<T>::valid(int pos) const
{
    return pos >= 1 && pos <= this->sz;
}

template<class T>
bool CirList<T>::getData(int pos, T &x) const
{
    if (valid(pos)) {
        CirListNode<T> *temp = this->head;

        for (int i = 0; i < pos; ++i) temp = temp->next;
        x = temp->data;
        return true;
    }
    return false;
}

template<class T>
bool CirList<T>::setData(int pos, const T &e)
{
    if (valid(pos)) {
        CirListNode<T> *temp = this->head;

        for (int i = 0; i < pos; ++i) temp = temp->next;
        temp->data = e;
        return true;
    }
    return false;
}

template<class T>
int CirList<T>::search(const T &e) const
{
    CirListNode<T> *temp = this->head->next;
    int res = 1;

    while (temp != head) {
        if (temp->data == e) return res;

        temp = temp->next, ++res;
    }
    return -1;
}

template<class T>
bool CirList<T>::insert(int pos, const T &e)
{
    if ((pos < 1) || (pos > this->sz + 1)) return false;

    CirListNode<T> *temp1 = this->head, *temp2 = new CirListNode<T>;

    for (int i = 0; i < pos - 1; ++i) temp1 = temp1->next;
    temp2->data = e, temp2->next = temp1->next;
    temp1->next = temp2;

    if (temp2->next == head) this->rear = temp2;
    ++this->sz;
    return false;
}

template<class T>
void CirList<T>::push_back(const T &e)
{
    CirListNode<T> *temp = new CirListNode<T> { e, head };

    this->rear->next = temp;
    this->rear = temp;
    ++this->sz;
}

template<class T>
bool CirList<T>::remove(int pos, T &x)
{
    if (!valid(pos)) return false;

    CirListNode<T> *temp1 = head, *temp2;

    for (int i = 0; i < pos - 1; ++i) temp1 = temp1->next;
    temp2 = temp1->next;
    temp1->next = temp2->next;
    x = temp2->data;

    if (temp2->next == head) this->rear = temp1;
    delete temp2;
    --this->sz;
    return true;
}

template<class T>
void CirList<T>::output() const
{
    CirListNode<T> *temp = head->next;

    while (temp != head) {
        std::cout << temp->data;

        if (temp->next != head) std::cout << "->";
        temp = temp->next;
    }
    std::cout << std::endl;
}

#endif // CIRLIST_H
