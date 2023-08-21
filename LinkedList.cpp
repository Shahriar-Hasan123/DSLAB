#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
Node *create_node(int data, Node *next)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
void PrintNode(Node *root)
{

    Node *ptr = root;
    cout << "Linked List: ";
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}
Node *insert_begin(Node* root,int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = root;
    return node;
}
Node *insert_end(Node *root,int data)
{
    Node *node, *ptr=root;
    node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    while(ptr->next!=NULL)
        ptr = ptr->next;
    ptr->next = node;
}
Node *insertion(Node *root,int data,int pos)
{
    Node *ptr = root, *node;
    node = (Node *)malloc(sizeof(Node));
    node->data = data;
    pos--;
    while(pos!=1)
    ptr = ptr->next,pos--;
    node->next = ptr->next;
    ptr->next = node;
}
Node *delete_begin(Node *root)
{
    if(root==NULL)
    cout << "List is already empty" << endl;
    else
    root = root->next;
    return root;
}
void delete_end(Node *root)
{
   if(root==NULL)
    cout << "List is already empty" << endl;
   else if(root->next==NULL)
    root = NULL;
   else
   {
    while(root->next->next!=NULL)
        root = root->next;

     root->next = NULL;
   }
}
void deletion(Node *root,int pos)
{
   if (root == NULL)
     cout << "List already empty" << endl;
   else if (pos == 1)
     root = root->next;
   else
   {
     pos--;
     while (pos != 1)
     {
        pos--;
        root = root->next;
       }
       root->next = root->next->next;
    }
}
int main()
{
    int a[] = {7, 9, 10, 45, 78, 29, 90, 34};
    Node *head = NULL;
    Node *node[8];
    for (int i = 0; i < 8; i++)
        node[i] = create_node(a[i], NULL);
    for (int i = 0; i < 7; i++)
        node[i]->next = node[i + 1];
    head = node[0];
    PrintNode(head);

    cout << "\n..........Insertion...........\n\n";
    cout << "Insert at the begining: " << endl;
    head=insert_begin(head, 3);
    head = insert_begin(head, 2);
    PrintNode(head);

    cout << "Insert at the end: " << endl;
    insert_end(head,100);
    insert_end(head, 200);
    PrintNode(head);

    cout << "Insert at certain position: " << endl;
    insertion(head, 8, 4);
    PrintNode(head);

    cout << "Delete from begin: " << endl;
    head=delete_begin(head);
    PrintNode(head);

    cout << "Delete from end: " << endl;
    delete_end(head);
    PrintNode(head);

    cout << "Delete from certain position: " << endl;
    deletion(head,7);
    PrintNode(head);

    return 0;
}