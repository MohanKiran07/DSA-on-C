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
        printf("Fail");
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
     if(*h==NULL)
     {
         printf("Linked List is Empty");
     }
     
     struct node*t=*h;
     *h=(*h)->next;
     free(t);
 }
 
 
 
 void DE(struct node**h)
 {
     if(*h==NULL)
     {
         printf("Linked List is Empty");
     }
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
 if(*h==NULL)
     {
         printf("Linked List is Empty");
     }
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
   if(key==t->d)
   {
    printf("Key is found at position %d\n",c);
    return;
   }
   t=t->next;
 }
 printf("Key is not found\n");
}


void REV(struct node**h)
{
   struct node*prev=NULL,*nn=NULL,*t=*h;
   while(t!=NULL)
   {
         nn=t->next;
         t->next=prev;
         prev=t;
         t=nn;
    }
    *h=prev;
 }                                                                                                                                                             
 void RD(struct node**h)
 {
 struct node*c=*h,*t,*prev;
 while(c!=NULL)
 {
     t=c->next;
     prev=c;
     while(t!=NULL)
     {
         if(c->d==t->d)
         {
              prev->next=t->next;
              free(t);
              t=prev->next;
         }
         else
         {
             prev=t;
             t=t->next;
         }
      }
      c=c->next;
  }                                                                                                                                                     
  }
  
void BS(struct node** head) {
    if (*head == NULL || (*head)->next == NULL) 
    {
        return; 
    }

    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;

    do
     {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->d > ptr1->next->d) 
            {
                int temp = ptr1->d;
                ptr1->d = ptr1->next->d;
                ptr1->next->d = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1; 
    } while (swapped);
}             
   
void LEN(struct node*h)
{
    int c=0;
    struct node*t=h;
    while(t!=NULL) 
    {
         c++;
         t=t->next;
     }
     printf(" Length of Linked List is %d\n",c);
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
                 
void SPLIT(struct node* h) {
    if (h == NULL || h->next == NULL) {
        printf("List is too short to split.\n");
        return;
    }

    struct node* slowPtr = h;
    struct node* fastPtr = h->next;
    while (fastPtr != NULL) {
        fastPtr = fastPtr->next;
        if (fastPtr != NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
    }

    struct node* h2 = slowPtr->next;
    slowPtr->next = NULL;

    printf("First Half of Linked List:\n");
    display(&h);
    printf("Second Half of Linked List:\n");
    display(&h2);
}

                
int main()   
{
           struct node*h=NULL,*nn=NULL,*t=NULL;
           int c,d,x,k,p;
           do{
               printf("Enter Data into the Node:");
               scanf("%d",&d) ;
               create(d);
               IE(&h,d);
               printf("Do u want to Insert More?:");
               scanf("%d",&c);
               }while(c==1);
     
               printf("\n~~~~~~~~~~~~~~~~~~\nOperations\n1.Insert at biginning\n2.insert at End\n3.Insert at specific position\n4.Delete at biginning\n5.Delete at End\n6.Delete at specific Position\n7.Search Operation\n8.Reverse Operation\n9.Remove Duplicates\n10.Sort the Linked List\n11.Length of Linked List\n12.Display\n13.Split\n0.Exit\n~~~~~~~~~~~~~~~~~~\n\n");
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
                       printf("Linked List After Deletion\n");
                       display(&h);
                       break;
                       
                       case 7:
                       printf("Enter Search Key:\n");
                       scanf("%d",&k);
                       search (h,k);
                       break;
                       
                       case 8:
                       REV(&h);
                       printf("Reverse of Linked List:\n");
                       display(&h);
                       break;
                       
                       case 9:
                       RD(&h);
                       printf("Linked List after Remove of Duplicates:\n");
                       display(&h);
                       break;
                       
                       case 10:
                       BS(&h);
                       printf("Linked List after Sorting\n");
                       display(&h);
                       break;
                       
                       case 11:
                       LEN(h);                                             
                       break;     
                       
                       case 12:
                       display(&h);
                       break;  

                       case 13:
                       SPLIT(h);
                       break;
                       
                                                                                 
                       case 0:
                       printf("Program Exit!");
                       exit(1);
                       break;
                       
                       default:
                       printf("Invalid\n");
                   }
               }
}        
