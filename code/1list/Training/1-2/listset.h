#ifndef LISTSET_H
#define LISTSET_H
#include "list.h"
#include <map>

template<class T>
class ListSet : public List<T>
{
public:

    ListSet() = default;
    ListSet(const ListSet<T> &S);
    ListSet<T> &operator+=(const ListSet<T> &S);
    ListSet<T> &operator-=(const ListSet<T> &S);
    ListSet<T> &operator^=(const ListSet<T> &S);
    ListSet<T> &operator=(const ListSet<T> &S);
    void        insert(const T &e); // 覆盖父类函数
    void        clear();

private:

    void unique(); // 辅助函数用来内部去重
};

template<class T>
void ListSet<T>::unique()
{
    std::map<T, bool> mp;
    ListNode<T> *temp1 = this->head, *temp2; // 前驱结点和判断结点

    while (temp1->next != nullptr) {         // 直至最后一个元素也被去重
        temp2 = temp1->next;

        if (mp[temp2->data]) {
            temp1->next = temp2->next;
            delete temp2;

            if (temp2 == this->rear) this->rear = temp1;
            --this->sz;
        } else mp[temp2->data] = true;
        temp1 = temp1->next;
    }
}

template<class T>
ListSet<T>::ListSet(const ListSet<T> &S) : List<T >::List()
{
    ListNode<T> *temp = S.head->next;

    while (temp != nullptr) {
        this->push_back(temp->data);
        temp = temp->next;
    }
}

template<class T>
void ListSet<T>::insert(const T &e)
{
    if (this->search(e) == -1) this->push_back(e);
}

template<class T>
ListSet<T> &ListSet<T>::operator+=(const ListSet &S)
{
    ListNode<T> *temp = S.head->next;

    while (temp != nullptr) {
        this->push_back(temp->data);
        temp = temp->next;
    }
    unique();
    return *this;
}

template<class T>
ListSet<T> &ListSet<T>::operator-=(const ListSet<T> &S)
{
    std::map<T, bool> mp;
    ListNode<T> *temp = S.head->next;

    while (temp != nullptr) {
        mp[temp->data] = true;
        temp = temp->next;
    }
    ListNode<T> *temp1 = this->head, *temp2; // 前驱结点和删除结点

    while (temp1->next != nullptr) {
        temp2 = temp1->next;

        if (mp[temp2->data]) {
            temp1->next = temp2->next;

            if (temp2 == this->rear) this->rear = temp1;
            delete temp2;
            --this->sz;
        } else temp1 = temp1->next;
    }
    return *this;
}

template<class T>
ListSet<T> &ListSet<T>::operator^=(const ListSet<T> &S)
{
    std::map<T, int> mp;
    ListNode<T> *temp = this->head->next;

    while (temp != nullptr) {
        mp[temp->data] = true;
        temp = temp->next;
    }
    clear();
    temp = S.head->next;

    while (temp != nullptr) {
        if (mp[temp->data]) insert(temp->data);
        temp = temp->next;
    }
    return *this;
}

template<class T>
ListSet<T> &ListSet<T>::operator=(const ListSet<T> &S)
{
    this->clear();
    ListNode<T> *temp = S.head->next;

    while (temp != nullptr) {
        this->push_back(temp->data);
        temp = temp->next;
    }
    return *this;
}

template<class T>
void ListSet<T>::clear()
{
    ListNode<T> *temp;

    while (this->head->next != nullptr) {
        temp = this->head->next;
        this->head->next = temp->next;
        delete temp;
    }
    this->sz = 0;
    this->rear = this->head;

    // std::cout << "ListSet has been cleared." << std::endl;
}

#endif // LISTSET_H
