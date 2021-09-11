#include <bits/stdc++.h>
class Node
{
    public:
    int data;
    Node* next;
};
void printList(Node* n)
{
    while (n != NULL) {
        std::cout << n->data << " ";
        n = n->next;
    }
}
int main()
{
    Node *head=new Node();
    Node *body=new Node();
    Node *end= new Node();

    head->data=1;
    head->next=body;
    body->data=2;
    body->next=end;
    end->data=3;
    end->next=nullptr;
    printList(head);
    return 0;
}
