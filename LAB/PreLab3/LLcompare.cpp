#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};

node *createLinkedList(int n); // The implementation is provided implicitly

bool isEqual(node *head1, node *head2)
{
    // TO DO
    node *p1 = head1;
    node *p2 = head2;
    bool flag = true;
    while (p1 != NULL || p2 != NULL)
    {
        if (p1->data != p2->data)
        {
            flag = false;
            break;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    if ((!p1 && p2) || (!p2 && p1))
    {
        return false;
    }
    return flag;
}

int main()
{
    int n = 0;
    cin >> n;
    node *head1 = createLinkedList(n);
    int m = 0;
    cin >> m;
    node *head2 = createLinkedList(m);
    cout << isEqual(head1, head2) << endl;
    return 0;
}
