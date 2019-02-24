#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
		
	if(root == NULL) {
	
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
	  
	} else {
      
		struct node* cur;
		
		if(data <= root->data) {
            cur = insert(root->left, data);
            root->left = cur;
		} else {
            cur = insert(root->right, data);
            root->right = cur;
		}
	
		return root;
	}
}

/* you only have to complete the function given below.  
node is defined as  

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

*/

void printlo(struct node* root,int level)
{
    if (root==NULL)
    {
        return;
    }
    if (level==1)
    {
        printf("%d ",root->data);
    }
    else if (level>1)
    {
        printlo(root->left,level-1);
        printlo(root->right,level-1);
    }
}

int height(struct node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    int l=height(root->left);
    int r=height(root->right);
    if (l>r)
    {
        return l+1;
    }
    return r+1;
}

void levelOrder( struct node *root) {
    int h=height(root);
    for (int i=0;i<=h;i++)
    {
        printlo(root,i);
    }
}




