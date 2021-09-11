#include <bits/stdc++.h>
class Node
{   
    public:
    int data;
    Node *next;
};

void push(Node **head_ref, int data_new)
{
    Node *new_node= new Node();
    new_node->data=data_new;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

void deletion(Node **head, int del_data)
{
    Node *temp= *head;
    Node *prev= NULL;
    if(temp!=NULL && temp->data==del_data)
    {
        *head=temp->next;
        delete temp;
        return;
    }
    else
    {
        while(temp!=NULL && temp->data!=del_data)
        {
            prev=temp;
            temp=temp->next;
        }

        if(temp==NULL)
        {
            std::cout<<"Data not present!\n";
            return;
        }

        prev->next=temp->next;
        delete temp;
    }
}

void PrintList(Node *head)
{
    Node *temp=head;
    std::cout<<"The elements in the Linked List are\n";
    while(temp!=NULL)
    {
        std::cout<<temp->data<<" ";
        temp=temp->next;
    }
    std::cout<<"\n";
}


int main()
{
    system("cls");
    Node* head= new Node();
    std::cout<<"New Linked List Initialised\n";
    int nodes{1};
    while(1)
    {
        std::cout<<"Linked List has "<<nodes<<" nodes at present\nEnter P to implement Push, D to implement Deletion and E to exit\n";
        char ch{};
        std::cin>>ch;
        int data{};
        std::cout<<"Enter the data : ";
        std::cin>>data;
        if(ch=='P' || ch=='p')
        {
            push(&head,data);
            nodes++;
        }
        else if(ch=='D' || ch=='d')
        {
            deletion(&head,data);
            nodes--;
        }
        else 
            return 0;
        PrintList(head);
    }

}