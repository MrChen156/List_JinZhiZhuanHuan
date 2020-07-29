#include<iostream>
#include<string>
using namespace std;

class node{
public:
    string S;
    node* pred;
    node* succ;
    node(string e){S = e; pred = NULL; succ = NULL;}
    node(string e, node* p, node* s){S = e; pred = p; succ = s;}
    node(){S = "insertion failure"; pred = NULL; succ = NULL;}
    void replacement(string e){S = e;}
    void insertPred(string e);
    void insertSucc(string e);
};

void node::insertPred(string e){
    node* ins = new node(e, pred, this);
    this->pred = ins;
    cout << "字符前驱插入：" << e << endl;//检查字符插入
}

void node::insertSucc(string e){
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
    void insertlast(string x);//在trailer之前的最后一个插入值
    void insertNodelast(node* x);//在trailer之前插入一个节点
    string shownode(int n);
};

void list::insertlast(string x){
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

string list::shownode(int n){
    if(n > size || n == 0) return "fault: meaningless Number";
    string ans;
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
    node testnode("I am your Dad."), testnode2("You are my son.");
    test_1.insertNodelast(&testnode);
    cout << "节点1:" << test_1.shownode(1) << endl;
    test_1.insertNodelast(&testnode2);
    cout << "节点1:" << test_1.shownode(1) << endl;
    cout << "节点2:" << test_1.shownode(2) << endl;
    cout << "列表大小：" << test_1.size << endl;
    return 0;
}
