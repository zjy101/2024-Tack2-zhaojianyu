#include<iostream>
using namespace std;
//const int MaxSize = 100;

template<class T>
struct Node
{
    T data;
    Node<T>* next;
};

template <class T>
class LinkList
{
public:
    LinkList(); //建立只有头结点的空链表
    ~LinkList();             //析构函数
    int Length();          //求单链表的长度
    int Locate(T x);       //求单链表中值为x的元素序号
    void Insert(int i, T x);   //在单链表中第i个位置插入元素值为x的结点
    void Reverse();        //reverse list
    void DispList();           //遍历单链表，按序号依次输出各元素
private:
    Node<T>* first; //单链表的头指针
};

template<class T>
LinkList<T>::LinkList()
{
    first = new Node<T>;
    first->next = NULL;
}

template<class T>
LinkList<T>::~LinkList()
{
    Node<T>* p = first;
    while (p != NULL)
    {
        Node<T>* q = p;
        p = p->next;
        delete q;
    }
}

template<class T>
int LinkList<T>::Length()
{
    int a = 0;
    Node<T>* p = first->next;
    while (p != NULL)
    {
        a++;
        p = p->next;
    }
    return a;
}

template<class T>
int LinkList<T>::Locate(T x)
{
    Node<T>* p;
    p = first;
    int j = 0;
    while (p->next != NULL)
    {
        p = p->next;
        j++;
        if (p->data == x)
            return j;
    }
    if (p->next == NULL) return 0;
}

template<class T>
void LinkList<T>::Insert(int i, T x)
{
    Node<T>* p;
    p = first;
    int j = 0;
    while (p != NULL && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (p == NULL || i < 1) throw 1;
    else
    {
        Node<T>* s;
        s = new Node<T>;
        s->data = x;
        s->next = p->next;
        p->next = s;
    }
}
template <class T>
void LinkList<T>::Reverse()
{
    Node<T>* p = nullptr;
    Node<T>* q = first->next;
    Node<T>* r = nullptr;
    while (q != nullptr)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    first->next = p;
}
template <class T>
void LinkList<T>::DispList()
{
    cout << "The length:" << Length() << endl;
    cout << "The elements:" << endl;
    Node<T>* p = first->next;
    while (p != nullptr)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int main() 
{
    LinkList<int> list;
    int num;
    while (cin >> num && num != 0) {
        list.Insert(1, num);
    }
    cout << "The length:" << list.Length() << endl;
    cout << "The elements:" << endl;
    list.DispList();
    int target;
    cin >> target;
    int pos = list.Locate(target);
    if (pos != -1) {
        cout << "Found position:" << pos << endl;
    }
    else {
        cout << "No found" << endl;
    }
    list.Reverse();
    cout << "The length:" << list.Length() << endl;
    cout << "The elements:" << endl;
    list.DispList();
    return 0;
}