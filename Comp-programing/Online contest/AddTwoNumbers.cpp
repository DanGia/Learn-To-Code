#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    return p;
}

struct LinkedList
{
    Node *head;
    Node *tail;
};

void init(LinkedList &lst)
{
    lst.head = NULL;
    lst.tail = NULL;
}

void insertTail(LinkedList &lst, int x)
{
    Node *p = createNode(x);
    if (lst.head == NULL)
    {
        lst.head = lst.tail = p;
    }
    else
    {
        lst.tail->next = p;
        lst.tail = p;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    int gcd = __gcd(a, b);
    cout << gcd;
    return 0;
}