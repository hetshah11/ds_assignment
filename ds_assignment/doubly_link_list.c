//Diffrent operations on doubly linked list
#include <stdio.h>
#include <stdlib.h>


struct node
	{
           struct node *lptr;
	   int data;
	   struct node *rptr;
	};
struct node *first;
struct node *last;
 



void print(struct node*);
struct node* Insert_first(int);
struct node* Insert_last(int);
struct node* Insert_ord(int);
struct node* deletenode(int);
//struct node* copy();
void main()
	{
		//struct node *head;
		
		// struct node* head = (struct node*) malloc(sizeof(struct node));
		//head->data=50;
		
		int ch,x,a;
		
		struct node* cop_rtn;
		while(ch!=6)
		{
			printf("Press 1 for add node at first\npress 2 for insert at last\nPress 4 for insert at order\nPress 4 for print\nPress 5 for delete\npress 6 for quit");
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

					case 5: printf("Enter element to be deletedn\n");
						scanf("%d",&a);
						deletenode(a);
						break;
			

					//case 5: cop_rtn=copy();
						//print(cop_rtn);
							
				
				}
		}
		
			
		
		
	}

struct node* Insert_first(int new_data)
{

	
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    
	if(first==NULL)
	{
		new_node->lptr=NULL;
		new_node->rptr=NULL;
		
		new_node->data=new_data;
		first=new_node;
		last=new_node;
		
		
		printf("\n\nfirst node created with value %d\n\n",new_data);
		return first;
	} 
		

  	 else
		{
			
   			 new_node->data=new_data;
  
    			
    			new_node->rptr=first;
			first->lptr=new_node;
			first=new_node;
			first->lptr=NULL;
  
   			
			//head=NULL;
    			//first=new_node;
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
		new_node->lptr=NULL;
		new_node->rptr=NULL;
		
		
		first=new_node;
		last=new_node;
		
		printf("\nfirst node created with value %d\n",new_data);
	} 
	 else if(new_data < first->data)
		{
			new_node->lptr=NULL;
			new_node->rptr=first;
			first->lptr=new_node;
			first=new_node;	
		}
		

  	 else
		{
			
   			
  
    			temp=first;
			while(temp->rptr!=NULL)
			{
			if(temp->data < new_data   && temp->rptr->data > new_data)
				{
					new_node->rptr=temp->rptr;
					temp->rptr->lptr=new_node;
					temp->rptr=new_node;
					
					new_node->lptr=temp;
					printf("\n\nNew node added in order with value %d\n\n",new_data);
					return first;
					
				}
				   temp=temp->rptr;
				//temp->link=new_node;
				//new_node->link=NULL;
			}     
				  temp->rptr=new_node;
				  new_node->lptr=temp;
				//temp->link=new_node;
				new_node->rptr=NULL;
				last=new_node;
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
		new_node->lptr=NULL;
		new_node->rptr=NULL;
		
		
		first=new_node;
		last=new_node;
		
		
		printf("\n\nfirst node created with value %d\n\n",new_data);
		return first;
	} 
	
		

  	 else
		{
			
   			 
  
    			temp=first;
			while(temp->rptr!=NULL)
				{
					temp=temp->rptr;
				}
    			temp->rptr=new_node;
			new_node->lptr=last;
			new_node->rptr=NULL;
			last=new_node;
  
   			
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
		else if(first->rptr==NULL)
			{
				if(first->data==x)
				{
				first=NULL;
				last=NULL;
				
				//free(first);
				//return NULL;
				}
				else
					printf("\nElement not found\n");
			}
		else
			{
				temp=first;
				while(temp->rptr!=NULL)
					{
						if(first->data==x)
							{
							first=temp->rptr;
							first->lptr=NULL;
							//last->link=first;
							printf("\nelement deleted\n");
							return first;
							
							}
						 if(temp->rptr->data==x)
							{
								if(temp->rptr==last)
								{
								temp->rptr=NULL;
								
								last=temp;
								//last->link=first;
								printf("\nelement deleted\n");
								}
								else
									{
								    		temp->rptr=temp->rptr->rptr;
								    		temp->rptr->lptr=temp;
										printf("\nelement deleted\n");
									}
									
								return first;
							}
						temp=temp->rptr;
					}
				printf("\nElement not found\n");
				
			}
	}


/*struct node* copy()
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
		}*/
void print(struct node *begin)
	{
		int count=0;;
		struct node *temp;
		if(first==NULL)
			printf("\nNo elements to be deleted\n");
		//emp=(struct node*)malloc(sizeof(struct node));
	else
		{
		temp=begin;
			while(temp!=NULL)
				{
					//printf("h\n");
					printf("%d ",temp->data);
					count++;
					temp=temp->rptr;
				}
			printf("\n");
			printf("\nCount=%d\n",count);
			printf("\n\nfirst=%d\n\n",first->data);
			printf("\n\nlast=%d\n\n",last->data);
		}
	}
