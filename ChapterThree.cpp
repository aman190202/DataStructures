#include <bits/stdc++.h>
class Node
{
    public:
    int data;
    Node *next;
};

void queue(Node** head_ref, int new_data)
{
    Node *new_node= new Node();
    new_node->data=new_data;
    new_node->next=NULL;

    if(*head_ref==NULL)
    {
        *head_ref=new_node;
        return;
    }
    
    Node *last=*head_ref;
    while(last->next!=NULL)
        last=last->next;
    
    last->next=new_node;
    return;
}

void stack(Node** head_ref, int  new_data)
{
    Node *new_node=new Node();
    new_node->data=new_data;
    new_node->next=*head_ref;
    (*head_ref)=new_node;
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
    std::cout<<"Empty Node has been Initialised. \n";
    int nodes{1};
    while(1)
    {
        std::cout<<"Linked List has "<<nodes<<" nodes at present\nEnter Q to implement Queue , S to implement stack and E to exit\n";
        char ch{};
        std::cin>>ch;
        int data{};
        std::cout<<"Enter the data : ";
        std::cin>>data;
        if(ch=='Q' || ch=='q')
            queue(&head,data);
        else if(ch=='S' || ch=='s')
            stack(&head,data);
        else 
            return 0;
        PrintList(head);
        nodes++;
    }
}