#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
void push_front(Node *head, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;

    new_node->next = head;
    head = new_node;
}
//insert mid insert_after
void insert_after(Node* pre_node, int new_data){
    if(pre_node == NULL){
        cout << "The given previous node cannot be NULL";
    }

    //allocate new node;
    Node* new_node = new Node;
    new_node->data = new_data;// put new data to node data
    //move the next of pre node as newnode
    pre_node->next = new_node;

}

//insert last
void 

void printList(Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
}