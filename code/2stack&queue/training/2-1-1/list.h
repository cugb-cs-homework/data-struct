#ifndef LIST_H
#define LIST_H
#include "listnode.h"

template<class T>
class List {
public:

    List();
    List(const List<T>& L) = default;
    ~List();
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
    void output() const;           // 遍历表中元素

private:

    ListNode<T> *head, *rear; // 指向头结点的头指针和尾插法用的指针
    int sz = 0;               // 记录元素的数量
};

template<class T>
List<T>::List() {
    this->head = new ListNode<T>; // 引入空结点
    this->head->next = nullptr;
    this->rear = this->head;
    this->sz = 0;

    //    std::cout << "List initialized." << std::endl;
}

template<class T>
List<T>::~List() {
    ListNode<T> *temp1 = this->head, *temp2;

    while (temp1 != nullptr) {
        temp2 = temp1;
        temp1 = temp1->next;
        delete temp2;
    }
    this->sz = 0;

    //    std::cout << "List destructed." << std::endl;
}

template<class T>
int List<T>::length() const {
    return this->sz;
}

template<class T>
bool List<T>::empty() const {
    return this->sz == 0;
}

template<class T>
bool List<T>::valid(int pos) const {
    return pos >= 1 && pos <= this->sz;
}

template<class T>
bool List<T>::getData(int pos, T& x) const {
    if (valid(pos)) {
        ListNode<T> *temp = this->head;

        for (int i = 0; i < pos; ++i) temp = temp->next;
        x = temp->data;
        return true;
    }
    return false;
}

template<class T>
bool List<T>::setData(int pos, const T& e) {
    if (valid(pos)) {
        ListNode<T> *temp = this->head;

        for (int i = 0; i < pos; ++i) temp = temp->next;
        temp->data = e;
        return true;
    }
    return false;
}

template<class T>
int List<T>::search(const T& e) const {
    ListNode<T> *temp = this->head->next;
    int res = 1;

    while (temp != nullptr) {
        if (temp->data == e) return res;

        temp = temp->next, ++res;
    }
    return -1;
}

template<class T>
bool List<T>::insert(int pos, const T& e) {
    //    if ((pos == 1) && (this->sz == 0)) {
    //        ListNode<T> *temp = new ListNode<T>;
    //        temp->next = nullptr, this->head->next = temp;
    //        ++this->sz;
    //        return true;
    //    }

    if ((pos < 1) || (pos > this->sz + 1)) return false;

    ListNode<T> *temp1 = this->head, *temp2 = new ListNode<T>; // 前驱结点和插入结点

    for (int i = 0; i < pos - 1; ++i) temp1 = temp1->next;
    temp2->data = e, temp2->next = temp1->next;
    temp1->next = temp2;

    if (temp2->next == nullptr) this->rear = temp2;
    ++this->sz;
    return true;
}

template<class T>
void List<T>::push_back(const T& e) {
    ListNode<T> *temp = new ListNode<T>{ e };

    this->rear->next = temp;
    this->rear = temp;
    ++this->sz;

    //    return insert(this->sz + 1, e); 可以复用上面的代码进行尾结点插入但是太慢
}

template<class T>
bool List<T>::remove(int pos, T& x) {
    if (!valid(pos)) return false;

    ListNode<T> *temp1 = head, *temp2; // 前驱结点和删除结点

    for (int i = 0; i < pos - 1; ++i) temp1 = temp1->next;
    temp2 = temp1->next;
    x = temp2->data;

    if (temp2->next == nullptr) this->rear = temp1;
    else temp1->next = temp2->next;
    delete temp2;
    --this->sz;
    return true;
}

template<class T>
void List<T>::output() const {
    ListNode<T> *temp = head->next;

    while (temp != nullptr) {
        std::cout << temp->data;

        if (temp->next != nullptr) std::cout << "->";
        temp = temp->next;
    }
    std::cout << std::endl;
}

#endif // LIST_H
