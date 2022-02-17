//Diffrent operations on Singly linked list

#include <stdio.h>
#include <stdlib.h>


struct node
	{
	   int data;
	   struct node *link;
	};
struct node *first; 



void print(struct node*);
struct node* deletenode(int);
struct node* Insert_first(int);
struct node* Insert_last(int);
struct node* Insert_ord(int);
struct node* copy();
void main()
	{
		//struct node *head;
		
		// struct node* head = (struct node*) malloc(sizeof(struct node));
		//head->data=50;
		
		int ch,x,a;
		
		struct node* cop_rtn;
		while(ch!=7)
		{
			printf("Press 1 for add node at first\npress 2 for insert at last\nPress 4 for insert at order\nPress 4 for print\nPress 5 for copy\npress 6 for delete\npress 7 for quit\n");
			scanf("%d",&ch);
			switch(ch)
				{
					case 1: printf("Enter element\n");
						scanf("%d",&x);
						Insert_first(x);
						break;

					case 2: printf("Enter element\n");
						scanf("%d",&x);
						Insert_last(x);
						break;

					case 3:	printf("Enter element\n");
						scanf("%d",&x);
						Insert_ord(x);
						break;
					
					case 4: print(first);
						break;

					case 5: cop_rtn=copy();
						print(cop_rtn);
						break;

					case 6: printf("\nEnter Element to be deleted\n");
						scanf("%d",&a);
						deletenode(a);
						break;
							
				
				}
		}
		
			
		
		
	}

struct node* Insert_first(int new_data)
{

	
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    
	if(first==NULL)
	{
		new_node->link=NULL;
		
		new_node->data=new_data;
		first=new_node;
		
		
		printf("\n\nfirst node created with value %d\n\n",new_data);
		return first;
	} 
		

  	 else
		{
			
   			 new_node->data=new_data;
  
    			
    			new_node->link=first;
  
   			
			//head=NULL;
    			first=new_node;
			printf("\n\nNew node added in beginning with value %d\n\n",new_data);
			return first;
		}
  
   

	
}

struct node* Insert_ord(int new_data)
{
	struct node *temp;
	
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data=new_data;
    
	if(first==NULL)
	{
		new_node->link=NULL;
		
		
		first=new_node;
		
		
		printf("\nfirst node created with value %d\n",new_data);
	} 
	 else if(new_data < first->data)
		{
			new_node->link=first;
			first=new_node;	
		}
		

  	 else
		{
			
   			
  
    			temp=first;
			while(temp->link!=NULL)
			{
			if(temp->data < new_data   && temp->link->data > new_data)
				{
					new_node->link=temp->link;
					temp->link=new_node;
					printf("\n\nNew node added in order with value %d\n\n",new_data);
					return first;
					
				}
				temp=temp->link;
				//temp->link=new_node;
				//new_node->link=NULL;
			}
				temp->link=new_node;
				new_node->link=NULL;
				/*else
					{
					temp->link = new_node;
					new_node->link=NULL;
					}*/  
   			
			//head=NULL;
    			//first=new_node;
			printf("\nNew node added in order with value %d\n",new_data);
			return first;
		}
  
   

	
}

struct node* Insert_last(int new_data)
{
	struct node *temp;
	
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
	new_node->data=new_data;
    
	if(first==NULL)
	{
		new_node->link=NULL;
		
		
		first=new_node;
		
		
		printf("\n\nfirst node created with value %d\n\n",new_data);
		return first;
	} 
	
		

  	 else
		{
			
   			 
  
    			temp=first;
			while(temp->link!=NULL)
				{
					temp=temp->link;
				}
    			temp->link=new_node;
			new_node->link=NULL;
  
   			
			//head=NULL;
    			//first=new_node;
			printf("\n\nNew node added in end with value %d\n\n",new_data);
			return first;
		}
  
   

	
}

struct node* deletenode(int x)
	{
		struct node* temp;
		if(first==NULL)
			{
				printf("\nDeletion not possible\n");
				//return NULL;
			}
		else if(first->link==NULL)
			{
				if(first->data==x)
				{
				first=NULL;
				printf("Element deleted\n");
				free(first);
				//return NULL;
				}
				else
					printf("\nElement not found\n");
			}
		else
			{
				temp=first;
				while(temp->link!=NULL)
					{
						if(first->data==x)
							{
							first=temp->link;
							printf("Element deleted\n");
							return first;
							}
						 if(temp->link->data==x)
							{
								temp->link=temp->link->link;
								printf("Element deleted\n");
								return first;
							}
						temp=temp->link;
					}
				
			}
	}

struct node* copy()
		{
			int count=0;
			struct node *start;
			struct node *temp;
			struct node *save;
			if(first==NULL)
				{
				printf("No elements to copy\n");
				return NULL;
				}
			else
				{
					//start = (struct node*)malloc(sizeof(struct node));
					temp=first;
					while(temp!=NULL)
						{
							 struct node *new_node = (struct node*)malloc(sizeof(struct node));
							new_node->data=temp->data;
							
							count++;
								if(count==1)
									{
									start=new_node;
									save=start;
									start->link=NULL;
									}
							else
							{
	
							save->link=new_node;
							new_node->link=NULL;		
							save=new_node;
							
							}
						temp=temp->link;
							
						}
					return start;
					
				}
		}
void print(struct node *begin)
	{
		int count=0;
		if(first==NULL)
			printf("nothing to print\n");
		else
		{
		struct node *temp;
		//emp=(struct node*)malloc(sizeof(struct node));
		temp=begin;
			while(temp!=NULL)
				{
					//printf("h\n");
					printf("%d ",temp->data);
					count++;
					temp=temp->link;
				}
			printf("\n");
			printf("\nCount=%d\n",count);
		}
	}
