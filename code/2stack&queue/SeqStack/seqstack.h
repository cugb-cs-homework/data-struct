#ifndef SEQSTACK_H
#define SEQSTACK_H

template<class T>
class SeqStack
{
public:

    SeqStack(int sz = 100);
    ~SeqStack();
    void push(const T &e); // 元素压入栈
    bool pop(T &x);        // 弹出元素并保存在x
    bool top(T &x);        // 获取栈顶元素并保存在x
    int size() const;
    bool empty() const;
    bool full() const;
    void clear();
    int capacity() const;
    friend std::ostream &operator<<(std::ostream &os, SeqStack<T> &S)   // 放在模板类内随着实例化而实例化
    {
        os << "top: " << S.data[S.ptr] << std::endl;

        for (int i = 0; i < S.size();
             ++i) os << i << ": " << S.data[i] << std::endl;
        return os;
    }

private:

    T *data;          // 存储数据的顺序数组
    int ptr;          // 栈顶遍历指针
    int maxSize;      // 栈容量
    int increaseSize; // 每次扩容的大小
    void reSize();    // 扩容
};

template<class T>
SeqStack<T>::SeqStack(int sz) : ptr(-1),
    maxSize(sz),
    increaseSize(sz / 2)
{
    this->data = new T[maxSize];
    std::cout << "SeqStack initialized." << std::endl;
}

template<class T>
SeqStack<T>::~SeqStack()
{
    delete[] this->data;
    std::cout << "SeqStack destructed." << std::endl;
}

template<class T>
void SeqStack<T>::push(const T &e)
{
    if (this->maxSize - 1 == this->ptr) reSize();
    data[++ptr] = e;
}

template<class T>
bool SeqStack<T>::pop(T &x)
{
    if (this->ptr == -1) return false;

    x = data[ptr--];
    return true;
}

template<class T>
bool SeqStack<T>::top(T &x)
{
    if (this->ptr == -1) return false;

    x = this->data[this->ptr];
    return true;
}

template<class T>
int SeqStack<T>::size() const
{
    return this->ptr + 1;
}

template<class T>
bool SeqStack<T>::empty() const
{
    return this->ptr == -1;
}

template<class T>
bool SeqStack<T>::full() const
{
    return this->ptr == this->maxSize - 1;
}

template<class T>
void SeqStack<T>::clear()
{
    this->ptr = -1;
}

template<class T>
int SeqStack<T>::capacity() const
{
    return this->maxSize;
}

template<class T>
void SeqStack<T>::reSize()
{
    T *temp = new T[maxSize + increaseSize];

    for (int i = 0; i < ptr; ++i) temp[i] = this->data[i];
    maxSize = maxSize + increaseSize;
    delete this->data;
    this->data = temp;
}

// 于平常的函数重载模板泛型这样不会实例化编译器报错,问题参考;https://www.cnblogs.com/autosar/archive/2011/10/29/2228674.html
// template<class T>
// std::ostream& operator<<(std::ostream& os, SeqStack<T>& S) {
// os << "top: " << S.ptr;

// for (int i = 0; i <= S.size();
// ++i) os << i << ": " << S.data[i] << std::endl;
// return os;
// }

#endif // SEQSTACK_H
