#ifndef LISTNODE_H
#define LISTNODE_H

template<class T>
class ListNode {
public:

    T data;
    ListNode *next;
    ListNode() = default;
    ListNode(T data, ListNode *next = nullptr) : data(data), next(next) {}
};

#endif // LISTNODE_H
