//Inorder, preorder, postorder traversal

#include <stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *lptr;
  struct node *rptr;
} *n[7];

void preorder (struct node *);
void inorder (struct node *);
void postorder (struct node *);
int
main ()
{
  int i;
  struct node *new_node;
  for (i = 0; i < 7; i++)
    {
      new_node = (struct node *) malloc (sizeof (struct node));
      n[i] = new_node;
      n[i]->data = i + 1;
    }
  n[0]->lptr = n[1];
  n[0]->rptr = n[2];

  n[1]->lptr = n[3];
  n[1]->rptr = n[4];

  n[2]->lptr = n[5];
  n[2]->rptr = n[6];

  n[3]->lptr = NULL;
  n[3]->rptr = NULL;

  n[4]->lptr = NULL;
  n[4]->rptr = NULL;

  n[5]->lptr = NULL;
  n[5]->rptr = NULL;

  n[6]->lptr = NULL;
  n[6]->rptr = NULL;
  printf ("\npreorder traversal is\n");
  preorder (n[0]);
  printf ("\nInorder traversal is\n");
  inorder (n[0]);
  printf ("\nPostorderr traversal is\n");
  postorder (n[0]);
  return 0;
}

void
preorder (struct node *root)
{
  if (root != NULL)
    printf ("%d ", root->data);

  if (root->lptr != NULL)
    preorder (root->lptr);



  if (root->rptr != NULL)
    preorder (root->rptr);


}

void
inorder (struct node *root)
{


  if (root->lptr != NULL)
    preorder (root->lptr);

  if (root != NULL)
    printf ("%d ", root->data);



  if (root->rptr != NULL)
    preorder (root->rptr);


}

void
postorder (struct node *root)
{
  if (root->rptr != NULL)
    preorder (root->rptr);

  if (root->lptr != NULL)
    preorder (root->lptr);

  if (root != NULL)
    printf ("%d ", root->data);






}
