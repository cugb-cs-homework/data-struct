#ifndef SEQQUEUE_H
#define SEQQUEUE_H

template<class T>
class SeqQueue
{
public:

    SeqQueue(int sz = 4);
    ~SeqQueue();
    void push(const T &e);
    bool pop(T &x);
    bool front(T &x);
    void clear();
    int  size() const;
    bool empty() const;
    bool full() const;
    void capacity() const;
    SeqQueue(const SeqQueue &A); // main中用到了拷贝构造需要避免浅复制

private:

    T *data;
    int head, rear, maxSize; // 一个元素的下标,最后一元素后一个位置的下标,最大空间
    void reSize(int newSize);
};

template<class T>
SeqQueue<T>::SeqQueue(int sz) : head(0),
    rear(0),
    maxSize(sz)
{
    this->data = new T[maxSize];

    // std::cout << "SeqQueue initialized." << std::endl;
}

template<class T>
SeqQueue<T>::SeqQueue(const SeqQueue &A) : head(A.head),
    rear(A.rear),
    maxSize(
        A.maxSize)
{
    this->data = new T[maxSize];

    for (int i = A.head; i != A.rear; i = (i + 1) % maxSize) data[i] = A.data[i];
}

template<class T>
void SeqQueue<T>::push(const T &e)
{
    if (this->full()) reSize(maxSize * 2);
    this->data[this->rear] = e;
    this->rear = (this->rear + 1) % maxSize;
}

template<class T>
SeqQueue<T>::~SeqQueue()
{
    delete[]this->data;

    // std::cout << "SeqQueue destructed." << std::endl;
}

template<class T>
bool SeqQueue<T>::pop(T &x)
{
    if (this->empty()) return false;

    x = this->data[head];
    head = (head + 1) % maxSize;

    if ((this->maxSize > 4) && (this->size() < this->maxSize / 4)) reSize(
            this->maxSize / 2);
    return true;
}

template<class T>
bool SeqQueue<T>::front(T &x)
{
    if (this->empty()) return false;

    x = this->data[head];
    return true;
}

template<class T>
void SeqQueue<T>::clear()
{
    head = rear;
    reSize(4);
}

template<class T>
int SeqQueue<T>::size() const
{
    return (rear - head + maxSize) % maxSize;
}

template<class T>
bool SeqQueue<T>::empty() const
{
    return this->rear == this->head;
}

template<class T>
bool SeqQueue<T>::full() const
{
    return (this->rear + 1) % maxSize == this->head;
}

template<class T>
void SeqQueue<T>::capacity() const
{
    return this->maxSize;
}

template<class T>
void SeqQueue<T>::reSize(int newSize)
{
    if (size() > this->maxSize) return;

    T *temp = new T[newSize];
    int p = 0;

    while (this->head != this->rear) {
        temp[p++] = this->data[this->head];
        this->head = (this->head + 1) % this->maxSize;
    }
    delete[]this->data;
    this->data = temp;
    this->head = 0, this->rear = p;
    this->maxSize = newSize;
}

#endif // SEQQUEUE_H
