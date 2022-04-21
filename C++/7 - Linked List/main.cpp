#include <bits/stdc++.h>
#include "function.h"
using namespace std;

int main()
{
    Node *head = NULL;
    Node *second = NULL;
    Node *third = NULL;

    head = new Node;
    second = new Node;
    third = new Node;

    head->data = 1;
    head->next = second; // link first node to second node

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = NULL;

    printList(second);

    return 0;
}