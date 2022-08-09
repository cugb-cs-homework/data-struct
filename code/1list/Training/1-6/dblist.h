#ifndef DBLIST_H
#define DBLIST_H

#include "iostream"
#include "dblistnode.h"

template<class T>
class DbList {
public:

    DbList();
    DbList(const DbList<T>& L) = default;
    ~DbList();
    int  length() const;           // 顺序表当前长度
    bool empty() const;            // 判断顺序表是否为空
    bool valid(int pos) const;     // 判断访问下标是否合法
    bool getData(int pos,
                 T & x)const;      // 获取下标对应元素并保存在x
    bool setData(int      pos,
                 const T& e);      // 设置下标对应元素
    int  search(const T& e) const; // 寻找元素在表中的下标
    bool insert(int      pos,
                const T& e);       // 在指定下标插入元素
    void push_back(const T& e);    // 尾插法插入元素
    bool remove(int pos,
                T & x);            //删除指定下标元素并将删除元素保存在x

private:

    DbListNode<T> *head, *rear; // 指向头结点的头指针
    int sz = 0;                 // 记录元素的数量
};

template<class T>
DbList<T>::DbList() {
    head = new DbListNode<T>;
    this->head->next = nullptr, this->head->prior = nullptr, this->rear = head;
    this->sz = 0;

    //    std::cout << "DbList initialized." << std::endl;
}

template<class T>
DbList<T>::~DbList() { // 改用从后向前遍历释放
    DbListNode<T> *temp1 = this->rear, *temp2;

    while (temp1 != nullptr) {
        temp2 = temp1;
        temp1 = temp1->prior;
        delete temp2;
    }
    this->sz = 0;

    //    std::cout << "DbList destructed." << std::endl;
}

template<class T>
int DbList<T>::length() const {
    return this->sz;
}

template<class T>
bool DbList<T>::empty() const {
    return this->sz == 0;
}

template<class T>
bool DbList<T>::valid(int pos) const {
    return pos >= 1 && pos <= this->sz;
}

template<class T>
bool DbList<T>::getData(int pos, T& x) const {
    if (valid(pos)) {
        if (pos <= this->sz / 2) { // 正向遍历找更快
            DbListNode<T> *temp = this->head;

            for (int i = 0; i < pos; ++i) temp = temp->next;
            x = temp->data;
        }
        else { // 反向遍历找更快
            DbListNode<T> *temp = this->rear;

            for (int i = 0; i < this->sz - pos; ++i) temp = temp->prior;
            x = temp->data;
        }
        return true;
    }
    return false;
}

template<class T>
bool DbList<T>::setData(int pos, const T& e) {
    if (valid(pos)) {
        if (pos <= this->sz / 2) { // 正向遍历找更快
            DbListNode<T> *temp = this->head;

            for (int i = 0; i < pos; ++i) temp = temp->next;
            temp->data = e;
        }
        else { // 反向遍历找更快
            DbListNode<T> *temp = this->rear;

            for (int i = 0; i < this->sz - pos; ++i) temp = temp->prior;
            temp->data = e;
        }
        return true;
    }
    return false;
}

template<class T>
int DbList<T>::search(const T& e) const { // 正向遍历和反向遍历好坏一样
    DbListNode<T> *temp = this->head->next;
    int res = 1;

    while (temp != nullptr) {
        if (temp->data == e) return res;

        temp = temp->next, ++res;
    }
    return -1;
}

template<class T>
bool DbList<T>::insert(int pos, const T& e) {
    if ((pos < 1) || (pos > this->sz + 1)) return false;

    DbListNode<T> *temp1, *temp2;

    if (pos <= this->sz + 1 / 2) {                     // 正向遍历找更快
        temp1 = this->head, temp2 = new DbListNode<T>; // 前驱结点和插入结点

        for (int i = 0; i < pos - 1; ++i) temp1 = temp1->next;
        temp1->next->prior = temp2;
        temp2->data = e, temp2->prior = temp1, temp2->next = temp1->next;
        temp1->next = temp2;
    }
    else {                                             // 反向遍历找更快
        temp1 = this->rear, temp2 = new DbListNode<T>; // 前驱结点和插入结点

        for (int i = 0; i < this->sz - pos + 1; ++i) temp1 = temp1->prior;
        temp1->next->prior = temp2;
        temp2->data = e, temp2->prior = temp1, temp2->next = temp1->next;
        temp1->next = temp2;
    }

    if (temp2->next == nullptr) this->rear = temp2;
    ++this->sz;
    return true;
}

template<class T>
void DbList<T>::push_back(const T& e) {
    DbListNode<T> *temp = new DbListNode<T>{ e, this->rear, nullptr };

    this->rear->next = temp;
    this->rear = temp;
    ++this->sz;
}

template<class T>
bool DbList<T>::remove(int pos, T& x) {
    if (!valid(pos)) return false;

    DbListNode<T> *temp1, *temp2;

    if (pos <= this->sz / 2) { // 正向遍历找更快
        temp1 = this->head;    // 前驱结点和插入结点

        for (int i = 0; i < pos - 1; ++i) temp1 = temp1->next;
        temp2 = temp1->next;
    }
    else {                  // 反向遍历找更快
        temp1 = this->rear; // 前驱结点和插入结点

        for (int i = 0; i < this->sz - pos + 1; ++i) temp1 = temp1->prior;
        temp2 = temp1->next;
    }

    x = temp2->data;

    if (temp2->next == nullptr) this->rear = temp1;
    else temp2->next->prior = temp1, temp1->next = temp2->next;

    --this->sz;
    delete temp2;
    return true;
}

#endif // DBLIST_H
