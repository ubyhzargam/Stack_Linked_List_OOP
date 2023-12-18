#include<iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};


class Stack
{
    private:
        Node *top;
        int size=0;
    public:
        Stack()
    {
            top=NULL;
    }
    void Push(int x);
    int  Pop();
    void Display();
    int peek(int pos);
    int StackTop();
    bool isEmpty();
    bool isFull();
    int Size();
};

void Stack ::Push(int x)
{
    Node *t;
    t=new Node;
    if(t==NULL)
    {
        cout<<"Stack overflow"<<endl;
    }
    else
    {
        size++;
        t->data=x;
        t->next=top;
        top=t;
    }
}

int Stack :: Pop()
{
    int x=-1;
    if(top==NULL)
    {
        cout<<"Stack underflow"<<endl;
        return x;
    }
    else
    {
        size--;
        Node *p=top;
        top=top->next;
        x=p->data;
        free(p);
        return x;
    }
}

void Stack :: Display()
{
    cout<<" The elements stored in the Stack are :"<<endl;
    if(top==NULL)
        cout<<"The stack is empty "<<endl;
    Node *p=top;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

int Stack :: peek(int pos)
{
    int x=-1;
    Node *t=top;
    int index=pos-1;
    int position=size-index-1;
    if(pos>size)
        cout<<"Invalid Index"<<endl;
    else
    {
        for(int i=0;i<position;i++)
        {
            t=t->next;
        }
        x=t->data;
    }
    return x;
}

int Stack :: StackTop()
{
    int x=-1;
    if(top==NULL)
    {
        cout<<"The stack is empty "<<endl;
    }
    else
    {
        x=top->data;
    }
    return x;
}

bool Stack :: isEmpty()
{
    if(top==NULL)
        return true;
    else
        return false;
}

bool Stack :: isFull()
{
    Node *t=new Node;
    if(t==NULL)
        return true;
    else
        return false;
}

int Stack :: Size()
{
    int c=0;
    Node *t;
    t=top;
    while(t!=NULL)
    {
        c++;
        t=t->next;
    }
    return c;
}

int main()
{
    Stack stk;
    stk.Push(10);
    stk.Push(20);
    stk.Push(30);
    stk.Display();
    stk.Pop();
    stk.Display();
    cout <<stk.peek(1)<<endl;
    cout <<stk.isEmpty()<<endl;
    cout<<stk.isFull()<<endl;
    cout<<stk.Size()<<endl;
    cout<<stk.StackTop()<<endl;
    return 0;
}
