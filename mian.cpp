//利用列表实现栈的功能并实现一个进制转换
//20.7.28成功改进了inserlast函数，使其功能正常化
#include<iostream>
#include<string>
using namespace std;

class node{
public:
    int S;
    node* pred;
    node* succ;
    node(int e){S = e; pred = NULL; succ = NULL;}
    node(int e, node* p, node* s){S = e; pred = p; succ = s;}
    node(){S = -1; pred = NULL; succ = NULL;}
    void replacement(int e){S = e;}
    void insertPred(int const& e);
    void insertSucc(int e);
};

void node::insertPred(int const& e){
    node* ins = new node(e, pred, this);
    pred->succ = ins; pred = ins;
    cout << "前驱插入：" << e << endl;//检查插入
}

void node::insertSucc(int e){
    node* ins = NULL;
    ins = new node(e,this,succ);
    this->succ = ins;
}

class list{
public:
    int size;
    node* header;
    node* trailer;
    list(){
        size = 0;
        header = new node;
        trailer = new node;
        header->succ = trailer;
        trailer->pred = header;
        header->pred = NULL;
        trailer->succ = NULL;
    }
    void insertlast(int const& x);//在trailer之前的最后一个插入值
    void insertNodelast(node* x);//在trailer之前插入一个节点
    int shownode(int n);
};

void list::insertlast(int const& x){
    trailer->insertPred(x);
    size++;
    cout << "trailer的前驱：" << trailer->pred->S << endl;//检查列表字符插入
}

void list::insertNodelast(node* x){
    x->succ = trailer;
    x->pred = trailer->pred;
    trailer->pred->succ = x;
    trailer->pred = x;
    size++;
    cout << "节点插入完成，当前规模：" << size << endl;
}

int list::shownode(int n){
    if(n > size || n == 0) {cout << "fault: meaningless Number" << endl; return -1;}
    int ans;
    node* utility = header->succ;
    for(int i = 1; i<=n; i++){
        ans = utility->S;
        utility = utility->succ;
        cout << "节点内容展示：" << ans << "，当前节点的序号：" << i << endl;
        if(i == n)break;
    }
    return ans;
}

int main(){
    list test_1;
    node testnode(101), testnode2(203);
    test_1.insertNodelast(&testnode);
    cout << test_1.shownode(1) << endl;
    test_1.insertNodelast(&testnode2);
    cout << test_1.shownode(1) << endl;
    test_1.insertlast(414);
    cout << test_1.shownode(3) << endl;
    cout << "列表大小：" << test_1.size << endl;
    return 0;
}
