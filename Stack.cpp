// A REPRESENTATION OF STACK USING LINKED LIST
#include <bits/stdc++.h>
class Node
{
    public:
    int data;
    Node *next;
};

void add(Node** head_ref,int data_ref)
{
    Node* new_node= new Node();
    new_node->data=data_ref;
    new_node->next=*head_ref;
    *head_ref=new_node;
}

void remove(Node** head_ref)
{
    Node* temp= *head_ref;
    *head_ref=temp->next;
    free(temp);
}

void PrintList(Node* head)
{   
    system("cls");
    std::cout<<"STACK PRESENTATION : ";
    while(head!=NULL)
    {
        std::cout<<head->data<<" ";
        head=head->next;
    }
    std::cout<<"\n";
    
}

int main()
{
    system("cls");
    std::cout<<"Enter the number to initialise your Stack : ";
    int data_init{};
    std::cin>>data_init;

    Node* head= new Node();
    head->data=data_init;
    head->next=NULL;

    
    char a{};
    while(true)
    {
        std::cout<<"ENTER A to add data to stack, R to remove and E to exit : ";
        std::cin>>a;

        if(a=='E')
            return 0;

        if(a=='A')
        {
            std::cout<<"ENTER THE DATA : ";
            std::cin>>data_init;
            add(&head,data_init);
        }
        else if(a=='R')
            remove(&head);
        
        PrintList(head);
    }
    
}