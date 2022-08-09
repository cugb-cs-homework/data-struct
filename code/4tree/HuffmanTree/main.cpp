#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

struct node {
    string data; // date非空的就是叶结点
    int val;
    string code;
    node *lchild, *rchild;
    node() = default;
    node(const node &A) :
        data(A.data),
        val(A.val),
        code(A.code),
        lchild(A.lchild),
        rchild(A.rchild)
    {
    }

    node(string data, int val, string code = "", node *lchild = nullptr, node *rchild = nullptr) :
        data(data),
        val(val),
        code(code),
        lchild(lchild),
        rchild(rchild)
    {
    }

    bool operator <(const node y) const
    {
        return this->val > y.val;   // 设置val大的优先级高
    }
};

vector<node> vec;

void encode(node *now, string str)
{
    now->code = str;
    if (now->data != "") vec.push_back(node(*now));
    if (now->lchild != nullptr) encode(now->lchild, now->code+'0');
    if (now->rchild != nullptr) encode(now->rchild, now->code+'1');
}

bool cmp(node x, node y)
{
    if (x.code.size() != y.code.size()) return x.code.size() < y.code.size();
    for (int i = 0; i < (int)x.code.size(); ++i) {
        if (x.code[i] != y.code[i])
            return x.code[i] < y.code[i];
    }
    return 0;
}

void release(node *rt)
{
    if (rt->lchild != nullptr || rt->rchild != nullptr) {
        if (rt->lchild != nullptr) release(rt->lchild);
        if (rt->rchild != nullptr) release(rt->rchild);
    } else delete rt;
}

signed main()
{
    priority_queue<node> que;
    int n;
    cin>>n;
    node *temp;
    for (int i = 0; i < n; ++i) {
        string d;
        int f;
        cin>>d>>f;
        que.push(node(d, f));
    }
    while (que.size() > 1) {    // 建立好二叉树
        temp = new node;
        node *p = new node(que.top());
        temp->lchild = p;
        que.pop();
        p = new node(que.top());
        temp->rchild = p;
        que.pop();
        temp->val = temp->lchild->val+temp->rchild->val;
        temp->code = temp->data = "";
        que.push(*temp);
    }
    temp = new node(que.top());
    encode(temp, "");
    sort(vec.begin(), vec.end(), cmp);
    int avg = 0;
    cout<<endl<<endl<<"Huffman Code as follows: "<<endl;
    for (auto e:vec) {
        avg += e.code.size();
        cout<<e.data<<'\t'<<e.code<<endl;
    }
    cout<<"ASL: "<<avg*1.0/vec.size()<<endl;    // sum_{查找每个元素概率*比较次数}
    release(temp);
    return 0;
}

/*15
The 1192
of 677
a 541
to 518
and 462
In 450
that 242
he 195
is 190
at 181
on 174
for 157
his 138
are 124
be 123
*/
