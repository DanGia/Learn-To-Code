#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

node *createLinkedList(int n)
{
    node *head = nullptr;
    node *tail = nullptr;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        node *newNode = new node;

        newNode->next = nullptr;
        newNode->data = a;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
    }

    return head;
}
int lengthll(node *head)
{
    int l = 0;
    while (head != nullptr)
    {
        l++;
        head = head->next;
    }
    return l;
}
node *insertNode(node *head, node *newNode, int position)
{
    int l = lengthll(head);
    // cout << l << endl;
    // newNode = new node;
    // newNode->next = NULL;
    node *temp = head;
    if (position > l)
    {
        // insert at the end
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    else if (position <= 0)
    {
    }
    else
    {
        for (int i = 2; i < position; i++)
        {
            if (temp->next != NULL)
            {
                temp = temp->next;
            }
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;
    // TO DO
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
