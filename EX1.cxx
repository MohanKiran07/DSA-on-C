#include<stdio.h>
#include<stdlib.h>


struct node
{
    int d;
    struct node*next;
};


struct node*create(int d)
{
    struct node*nn=(struct node*)malloc(sizeof(struct node));
    if(nn==NULL)
    {
        printf("Memory Allocation Fail");
        exit(1);
    }
    nn->d=d;
    nn->next=NULL;
    return nn;
}


void IB(struct node**head,int d)
{
        struct node*nn=create(d);
        nn->next=*head;
        *head=nn;
}    

  
    
 void IE(struct node**head,int d)  
 {
        struct node*nn=create(d);
        if(*head==NULL)
        {
           *head=nn;
           return;
        }
        struct node*t=*head;
        while(t->next!=NULL)
        {
            t=t->next;
        }
        t->next=nn;
        nn->next=NULL;
 }
 
 
 void IP(struct node**head,int d,int p)
 {
        if(p<=1)
        {
            IB(head,d);
            return;
        }
        struct node*nn=create(d);
        struct node*t=*head;
        for(int i=1;i<p-1 && t->next!=NULL;i++)
        {
            t=t->next;
        }
        if(t==NULL)
        {
            IE(head,d);
        }
        nn->next=t->next;
        t->next=nn;
 }
 
 void DB(struct node**h)
 {
     struct node*t=*h;
     *h=(*h)->next;
     free(t);
 }
 
 
 
 void DE(struct node**h)
 {
     struct node*t=*h;
     struct node*prev=NULL;
     while(t->next!=NULL)
     {
         prev=t;
         t=t->next;
     }
     if(prev!=NULL)
     {
     prev->next=NULL;
     free(t);
     }
     else
     {
         (*h)->next=NULL;
         free(t);
     }
 }
         
  
void DP(struct node**h,int p)
{
 if(p<=1)
 {
     DB(h);
 }
 struct node*t=*h,*prev=NULL;
 int c=1;
 while(t->next!=NULL && c<p)
 {
     prev=t;
     t=t->next;
     c++; 
 }
 if(prev)
 {
 prev->next=t->next;
 free(t);
 }
 }

void search(struct node *head,int key)
{
 int c=0;
 struct node *t=head;
 while(t!=NULL)
 {
   c++;
   if(key==t->data)
   {
    printf("Key is found at position %d",c);
    return;
   }
   t=t->next;
 }
 printf("Key is not found\n");
}
               
 
 void display(struct node**head)
 {
        struct node*t=*head;
        printf("\n~~~~~~~~~~~~~~~~~~~\n");
        while(t!=NULL)
        {
            printf("%d    ",t->d);
            t=t->next;
        }
        printf("\n~~~~~~~~~~~~~~~~~~~\n\n");
 }
                 
        
int main()   
{
           struct node*h=NULL,*nn=NULL,*t=NULL;
           int c,d,k,x,p;
           do{
               printf("Enter Data into the Node:");
               scanf("%d",&d) ;
               create(d);
               IE(&h,d);
               printf("Do u want to Insert More?:");
               scanf("%d",&c);
               }while(c==1);
     
               printf("\n~~~~~~~~~~~~~~~~~~\nOperations\n1.Insert at biginning\n2.insert at End\n3.Insert at specific position\n4.Delete at biginning\n5.Delete at End\n6.Delete at specific Position\n7.search operation\n0.Exit\n~~~~~~~~~~~~~~~~~~\n\n");
               while(1)
               {
                   printf("Enter your Choice:");
               scanf("%d",&x);
                   switch(x)
                   {
                       case 1:
                       printf("Enter Data into the Node:\n");
                       scanf("%d",&d);
                       IB(&h,d);
                       printf("Linked List After Insertion\n");
                       display(&h);
                       break;
                       
                       case 2:
                       printf("Enter Data into the Node:\n");
                       scanf("%d",&d);
                       IE(&h,d);
                       printf("Linked List After Insertion\n");
                       display(&h);
                       break;
                       
                       case 3:
                       printf("Enter Data into the Node:\n");
                       scanf("%d",&d);
                       printf("Enter the position:\n");
                       scanf("%d",&p);
                       IP(&h,d,p);
                       printf("Linked List After Insertion\n");
                       display(&h);
                       break;
                       
                       case 4:
                       DB(&h);
                       printf("Linked List After Deletion\n");
                       display(&h);
                       break;
                       
                       case 5:
                       DE(&h);
                       printf("Linked List After Deletion\n");
                       display(&h);
                       break;
                       
                        case 6:
                       printf("Enter the position:\n");
                       scanf("%d",&p);
                       DP(&h,p);
                       printf("Linked List After Insertion\n");
                       display(&h);
                       break;

                       case 7:
                       printf("Enter Search Key:\n");
                       scanf("%d",&k);
                       search (&h,k);
                       
                       case 0:
                       printf("Program Exit!");
                       exit(1);
                       break;
                       
                       default:
                       printf("Invalid");
                   }
               }
}        
