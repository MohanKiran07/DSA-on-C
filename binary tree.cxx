#include<stdio.h>
#include<stdlib.h>


//define the tree data structure
struct node 
{
    int data;
    struct node*left;
    struct node*right; 
};


// create a newnode 
struct node* newnode(int data)
{
    struct node*newnode=(struct node*)malloc(sizeof(struct node)) ;
    newnode->data=data;
    newnode->left=newnode->right=NULL;
    return newnode;
}


// search operation
struct node*search(struct node*root,int data)
{
    if (root==NULL || root->data==data)
    {
        return root;
    }
    else if(data>root->data)
    {
        return search(root->right,data);
    }
    else 
    {
        return search(root->left,data);
    }
}


//insertion into the node
struct node* insert(struct node*root,int data)
{
    if(root==NULL)
    {
        root=newnode(data);
    }
    else if(data>root->data)
    {
        root->right=insert(root->right,data);
    }
    else
    {
        root->left=insert(root->left,data);
    }
    return root;
}


// finding minimum in the tree
struct node* minimum(struct node*root)
{
    if(root==NULL)
    {
        return root;
    }
    if(root->left!=NULL)
    {
        return minimum(root->left);
    }
    return root;
}


// the God Damn Deletion.....
struct node*deletion(struct node*root,int data)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(data>root->data)
    {
        root->right=deletion(root->right,data);
    }
    else if(data<root->data)
    {
        root->left=deletion(root->left,data);
    }
    else
    {
        //root have no child
        if(root->left==NULL and root->right==NULL)
        {
            free(root);
            return NULL;
        }
        // root have one child 
        else if(root->left==NULL || root->right==NULL)
        {
            //root doesn't have left child 
            struct node*temp;
            if(root->left==NULL)
            {
                temp=root->right;
            }
            //root doesn't have right child 
            else
            {
                temp=root->left;
            }
            free(root);
            return temp;
        }
        // root have both the childs
        else
        {
            struct node*temp=minimum(root->right);
            root->data=temp->data;
            root->right=deletion(root->right,temp->data);
        }
    }
    return root;
}


// Display the tree in INORDER
struct node*inorder(struct node*root)
{
    if(root!=NULL)
    {
    inorder(root->left);
    printf("%d -> ",root->data);
    inorder(root->right);
    }
}


struct node*preorder(struct node*root)
{
    if(root!=NULL)
    {
        printf("%d ->",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}



struct node*postorder(struct node*root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ->",root->data);
    }
}



// Main function 
int main()
{
    struct node*root=newnode(20);
    insert(root, 5);

insert(root, 1);

insert(root, 15);

insert(root, 9);

insert(root, 7);
insert(root, 12);

insert(root, 30);

insert(root, 25);

insert(root, 40);

insert(root, 45);

insert(root, 42);

printf("\nBST with In-order:\n");

inorder(root);

printf("\n");

printf("\nBST with pre-order:\n");
preorder(root);
printf("\n");

printf("\nBST with post-order:\n");
postorder(root);
printf("\n");


root = deletion(root, 1);

root = deletion(root, 40);

root = deletion(root, 45);

root = deletion(root, 9);

printf("\nBST with In-order after deletions of few elements:\n");

inorder(root);

printf("\n");


// search operation
int key=42;

if(search(root,key)!=NULL)
{
    printf("\nKey is Found\n");
}
else
{
    printf("\nKey is not found\n");
}


return 0;
}
