#ifndef DBLISTNODE_H
#define DBLISTNODE_H

template<class T>
class DbListNode {
public:

    T data;
    DbListNode *prior, *next;
    DbListNode() = default;
    DbListNode(T           data,
               DbListNode *prior = nullptr,
               DbListNode *next = nullptr) : data(data), prior(prior),
        next(next) {}
};

#endif // DBLISTNODE_H
