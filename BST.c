//binary search tree
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int no;
	struct node *left, *right;
};struct node *root, *curr, *temp, *prev;

void insert()
{
	char ch;
	temp = malloc(sizeof(struct node));

	printf("Enter any number:");
	scanf("%d",&temp->no);
	
	temp->left = NULL;
	temp->right = NULL;
	root = temp;
	
	printf("Do you want to enter another node? (y/n)");
	fflush(stdin);
	getchar();
	ch = getchar();
	while(ch != 'n')
	{
		temp = malloc(sizeof(struct node));
		printf("Enter any number:");
		scanf("%d",&temp->no);
		curr = root;
		while(curr != NULL)
		{
			prev=curr;
			if(temp->no < curr->no)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if(temp->no < prev->no)
			prev->left=temp;
		else
			prev->right=temp;
		printf("do you want to enter another node(y/n)");
		fflush(stdin);
		getchar();
		ch=getchar();
	}
}

void inorder(struct node *curr)
{
	if(curr != NULL)
	{
		inorder(curr->left);
		printf("%d  ",curr->no);
		inorder(curr->right);
	}
}


void postorder(struct node *curr)
{

	if(curr != NULL)
	{
		postorder(curr->left);
		postorder(curr->right);
		printf("%d  ",curr->no);
	}
}

void preorder(struct node *curr)
{
	
	if(curr != NULL)
	{
		printf("%d ",curr->no);
		preorder(curr->left);
		preorder(curr->right);
	}
}

void search(struct node *root)
{
	int n, found=0;
	printf("\nenter the ele you want to search for: \n");
	scanf("%d",&n);
	curr=root;
	while(curr != NULL && found != 1)
	{
		if(curr->no == n)
			found=1;
		else
		{
			if(n < curr->no)
				curr=curr->left;
			else
				curr=curr->right;		
		}
	}
		if(found == 1)
			printf("\nelement is found\n");
		else
			printf("\nelement is not found\n");		
}

void delete_node(struct node *root)
{
	int n, found=0;
		printf("\nenter the ele you want to detete for: \n");
		scanf("%d",&n);
		curr=root;
		while(curr != NULL && found != 1)
		{
			if(curr->no == n)
				found=1;
			else
			{
				prev=curr;
				if(n < curr->no)
					curr=curr->left;
				else
					curr=curr->right;
			}
		}
		if(found == 1)
		{
			//case-1 :- delete leaf node
			if(curr->left == NULL && curr->right == NULL)          
			{
				if(prev->left == curr)
					prev->left = NULL;
				else
					prev->right=NULL;
				free(curr);
			}
		//case 2:-delete the middle node 
			else if(curr->left == NULL || curr->right == NULL)
			{
				//case 2.1                                               
				if(prev->left == curr)                             
				{
					if(curr->left == NULL)
						prev->left = curr->right;
					else
						prev->right = curr->right;
				}
				else
				{
					if(prev->right == curr)
						prev->right = curr->left;
					else
						prev->left = curr->left;
				}
				free(curr);
			}
			//case 3 :delete the root node
			else  
			{
				// 2 cases , 1) replace with the hightest from the left sub tree (or) with the lest from right tree
				temp=curr->left;
				while(temp->right != NULL)
				{
					prev=temp;
					temp = temp->right;
				}
				curr->no=temp->no;
				prev->right = temp->left;
				free(temp);
			}
		}
		else
			printf("element not found");			
}

int main()
{
	insert();
	printf("\n this is inorder\n");
	inorder(root);
	
	printf("\nthis is preorder\n");
	preorder(root);
	
	printf("\nthis is postorder\n");
	postorder(root);

	search(root);

	delete_node(root);

	printf("\n this is inorder after deletion \n");
	inorder(root);
}
