#include <iostream>
using namespace std;

struct GlNode {
    bool tag;   // 标记是否为表的头结点
    union { // 组合
        char data;
        struct GlNode *sublist;
    } val;
    struct GlNode *next;    // 一个元素结点位置
};

GlNode *creat(char * &s)
{
    GlNode *head;
    char ch = *s;   // 获取一个字符
    ++s;
    if (ch != '\0') {
        head = new GlNode();
        if (ch == '(') {// 创建一个新的结点
            head->tag = 1;// 新结点为表头结点
            head->val.sublist = creat(s);   // 递归构造
        } else if (ch == ')') head = nullptr;
        else {
            head->tag = 0;  // 新结点为原子结点
            head->val.data = ch;
        }
    } else head = nullptr;  // 串结束子表为空
    ch = *s;
    ++s;
    if (head != nullptr) {
        if (ch == ',') head->next = creat(s);
        else head->next = nullptr;
    }
    return head;
}

void display(GlNode *g)
{
    if (g != nullptr) {
        if (g->tag) {
            cout<<"(";
            if (g->val.sublist == nullptr) cout<<"";
            else display(g->val.sublist);
        } else cout<<g->val.data;
    }
    if (g->tag) cout<<")";
    if (g->next != nullptr) {
        cout<<",";
        display(g->next);
    }
}

int getLength(GlNode *g)
{
    int cnt = 0;
    g = g->val.sublist;
    while (g != nullptr) {
        ++cnt;
        g = g->next;
    }
    return cnt;
}

int getDepth(GlNode *g)
{
    int maxx = 0, depth;
    if (!g->tag) return 0;
    g = g->val.sublist;
    if (g == nullptr) return 1;
    while (g != nullptr) {
        if (g->tag) {
            depth = getDepth(g);
            if (depth > maxx) maxx = depth;
        }
        g = g->next;
    }
    return maxx + 1;
}

signed main()
{
    char s[] = "(b,(b,a,( ),d),((a,b),c,(( ))))";
    char *ps = (char *)&s;
    GlNode *ghead = creat(ps);
    display(ghead);
    cout<<endl;
    cout<<"Length: "<<getLength(ghead)<<endl;
    cout<<"Depth: "<<getDepth(ghead)<<endl;
    return 0;
}
