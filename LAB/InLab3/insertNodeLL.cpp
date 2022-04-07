#include <iostream>
//#include "struct.cpp"
using namespace std;
struct node
{
    int data;
    node *next;
};
node *pushback(node *&head, int x)
{
    node *p = new node;
    p->data = x;
    p->next = head->next;
    head->next = p;
    return p;
}
node *createLinkedList(int n)
{
    // TO DO
    node *head = new node;
    node *cur = new node;
    node *pre = new node;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (i == 0)
        {
            head->data = x;
            head->next = nullptr;
            cur = head;
        }
        else
        {
            cur = pushback(cur, x);
        }
    }
    return head;
}

// node *insertNode(node *head, node *newNode, int position)
// {
//     // TO DO
//     node *cur = head;
//     int pos = 1;
//     while (pos != position || cur->next == nullptr)
//     {
//         cur = cur->next;
//         pos++;
//     }
//     newNode->next = cur->next;
//     cur->next = newNode;

//     return head;
// }
node *insertNode(node *head, node *newNode, int position)
{
    // TO DO
    node *cur = head;
    int pos = 1;
    bool flag = false;
    while (cur->next != nullptr)
    {
        if (position == 1)
        {
            newNode->next = head;
            head = newNode;
            cur = newNode->next;
            flag = true;
            break;
        }
        else if (pos + 1 == position)
        {
            newNode->next = cur->next;
            cur->next = newNode;
            cur = newNode->next;
            flag = true;
            break;
        }
        cur = cur->next;
        pos++;
    }
    if (!flag)
    {
        newNode->next = cur->next;
        cur->next = newNode;
        cur = newNode->next;
    }
    return head;
}
void print(node *head)
{
    while (head != nullptr)
    {
        cout << head->data << endl;
        head = head->next;
    }
}
int main()
{
    int n = 0;
    cin >> n;
    node *head = createLinkedList(n);
    node *newNode = new node();
    cin >> newNode->data;
    int position = 0;
    cin >> position;
    head = insertNode(head, newNode, position);
    print(head);
    return 0;
}