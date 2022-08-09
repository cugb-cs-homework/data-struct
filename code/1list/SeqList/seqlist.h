#ifndef SEQLIST_H
#define SEQLIST_H

#include <iostream>

template<class T>
class SeqList {
public:

    SeqList(int sz = 100);                  // 初始构造函数
    SeqList(const SeqList<T>& L) = default; // 拷贝构造函数
    ~SeqList();                             // 析构函数
    int  capacity() const;                  // 顺序表的最大容量
    int  length() const;                    // 顺序表当前长度
    bool empty() const;                     // 判断顺序表是否为空
    bool full() const;                      // 判断顺序表是否已满
    bool valid(int pos) const;              // 判断访问下标是否合法
    bool getData(int pos,
                 T & x)const;               // 获取下标对应元素并保存在x
    bool setData(int      pos,
                 const T& e);               // 设置下标对应元素
    int  search(const T& e) const;          // 寻找元素在表中的下标
    bool insert(int      pos,
                const T& e);                // 在指定下标插入元素
    bool push_back(const T& e);             // 尾插法插入元素
    bool remove(int pos,
                T & x);                     //删除指定下标元素并将删除元素保存在x
    void output() const;                    // 遍历表中元素

private:

    T *data;                  // 动态数组指针
    int maxSize;              // 动态数组的最大空间
    int next;                 //下一个元素下标
    void reSize(int newSize); // 辅助动态数组重新分配空间的函数
};

template<class T>
void SeqList<T>::reSize(int newSize) {
    if (newSize <= 0) std::cerr << "reSize falied." << std::endl;
    else if (newSize == maxSize) return;
    else {
        if (newSize > this->maxSize) {
            T *temp = new T[newSize];

            for (int i = 0; i < next; ++i) temp[i] = this->data[i];
            delete[] this->data;
            this->data = temp;
        }
        else next = newSize;
        this->maxSize = newSize;
    }
}

template<class T>
SeqList<T>::SeqList(int sz) {
    this->data = new T[sz];
    this->maxSize = sz; this->next = 0;
    std::cout << "SeqList initialized." << std::endl;
}

template<class T>
SeqList<T>::~SeqList() {
    delete[]data;
    std::cout << "SeqList destructed." << std::endl;
}

template<class T>
int SeqList<T>::capacity() const {
    return this->maxSize;
}

template<class T>
int SeqList<T>::length() const {
    return this->next;
}

template<class T>
bool SeqList<T>::empty() const {
    return this->next == 0;
}

template<class T>
bool SeqList<T>::full() const {
    return this->next == this->maxSize;
}

template<class T>
bool SeqList<T>::valid(int pos) const {
    return pos >= 0 && pos < this->next;
}

template<class T>
bool SeqList<T>::getData(int pos, T& x) const {
    if (valid(pos)) {
        x = this->data[pos];
        return true;
    }
    return false;
}

template<class T>
bool SeqList<T>::setData(int pos, const T& e) {
    if (valid(pos)) {
        this->data[pos] = e;
        return true;
    }
    return false;
}

template<class T>
int SeqList<T>::search(const T& e) const {
    for (int i = 0; i < this->next; ++i)
        if (this->data[i] == e) return i;

    return -1;
}

template<class T>
bool SeqList<T>::insert(int pos, const T& e) {
    //    if ((pos == 0) && (this->next == 0)) { // 特判头插法第一个元素
    //        this->data[0] = e;
    //        ++this->next;
    //        return true;
    //    }

    if ((pos < 0) || (pos > this->next)) return false;  //不能用valid函数判断因为可以在最后一个元素的后一个位置插入

    if (this->next + 1 > this->maxSize) reSize(this->maxSize * 2);

    for (int i = this->next; i >= pos + 1; --i) this->data[i] = this->data[i - 1];
    this->data[pos] = e;
    ++this->next;
    return true;
}

template<class T>
bool SeqList<T>::push_back(const T& e) { // 函数复用
    return insert(this->next, e);
}

template<class T>
bool SeqList<T>::remove(int pos, T& x) {
    if (!valid(pos)) return false;

    x = this->data[pos];

    for (int i = pos; i < this->next - 1; ++i) this->data[i] = this->data[i + 1];
    --this->next;
    return true;
}

template<class T>
void SeqList<T>::output() const {
    for (int i = 0; i < this->next; ++i) {
        std::cout << this->data[i];

        if (i != this->next - 1) std::cout << "->";
    }
    std::cout << std::endl;
}

#endif // SEQLIST_H
