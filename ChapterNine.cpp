#include <bits/stdc++.h>
class Node
{   
    public:
    int data;
    Node* next;
};

void Push(Node** head_ref, int data_ref)
{
    Node *new_node=new Node();
    new_node->data=data_ref;
    new_node->next=*head_ref;
    (*head_ref)=new_node;
}

void PrintList(Node* head)
{
    system("cls");
    std::cout<<"THE STACK : ";
    while(head!=NULL)
    {
        std::cout<<head->data<<" ";
        head=head->next;
    }
    std::cout<<std::endl;
}

void Exchange(Node **head_ref, int x, int y)
{
    if(x==y)
        return ;
    
    Node *prevX= NULL, *currX= *head_ref, *prevY= NULL,*currY=*head_ref;

    while(currX && currX->data!=x)
    {
        prevX=currX;
        currX=currX->next;
    }

    while(currY && currY->data!=y)
    {
        prevY=currY;
        currY=currY->next;
    }

    if(currX==NULL || currY==NULL)
        return;

    if(prevX!=NULL)
        prevX->next=currY;
    else
        *head_ref=currY;
    
    if(prevY!=NULL)
        prevY->next=currX;
    else
        *head_ref=currX;
    
    Node* temp= currX->next;
    currX->next=currY->next;
    currY->next=temp;

}

int main()
{
    system("cls");
    std::cout<<"ENTER A NUMBER TO INITIALISE STACK : ";
    int data_new{};
    std::cin>>data_new;

    Node* head=new Node();
    head->data= data_new;
    head->next=NULL;

    while(1)
    {
        PrintList(head);
        std::cout<<"ENTER E TO EXCHANGE 2 NUMBER, A TO ADD A NUMBER AND Q TO QUIT : ";
        char a{};
        std::cin>>a;
        if(a=='Q')
            return 0;
        if(a=='E')
        {
            std::cout<<"ENTER THE TWO NUMBERS TO BE EXCHANGED : ";
            int x{},y{};
            std::cin>>x>>y;
            Exchange(&head,x,y);
        }
        else if(a=='A')
        {
            std::cout<<"ENTER THE NUMBER TO BE ADDED : ";
            std::cin>>data_new;
            Push(&head,data_new);
        }

    }
}