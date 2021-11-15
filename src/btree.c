#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>


struct tree_node * Insert (int x, struct tree_node *t)
{
  // Insert item x into the tree t
  if (t == NULL){
      t = Initialize(t);
      t->item = x;
  }
  else if (x <= t->item)
    return (Insert(x, t->left));
  else
    return (Insert(x, t->right));

  return (t);
}


struct tree_node* minVal(struct tree_node* t) 
{
  /* Retun the node with minmum value found in the tree.*/
  struct tree_node* current = t;

  // loop down to find the leftmodst leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}



struct tree_node * Remove (int x, struct tree_node *t)
{
 // Remove one item from the tree t

 // base case
  if (t == NULL)
    return (t);

  struct tree_node* p = t;
  
  //find if the item that is gater or smuller then the node
  if (x < t->item)
    t->left = Remove(x, t->left);
  else if (x > t->item)
    t->right = Remove(x, t->right);
  
  else // when x = t->item
  {
    // node with only one child or no child
    if (t->right == NULL)
    {
      p = t->right;
      free(t);
      return p;
    }
    else if (t->left == NULL)
    {
      p = t->left;
      free(t);
      return (p);
    }
    
    //node with two children:
    struct tree_node* prev = minVal(t->right);

    t->item = p->item;

    t->right = Remove(t->item, t->right);

    return t;
  }
}


int Contains (int x, struct tree_node *t)
{

  // Return true if the tree t contains item x. Return false otherwise.
  if (x == t->item)
    return 1;
  else if (x < t->item)
    return Contains(x, t->left);
  else if (x > t->item)
    return Contains(x, t->right);
  else
  return 0;

}


struct tree_node * Initialize (struct tree_node *t)
{
  // Create an empty tree
  struct tree_node *p = malloc(sizeof(struct tree_node));
  p->left = NULL;
  p->right = NULL;

  return p;
}

int Empty (struct tree_node *t)
{
  // Test if empty
  if (t == NULL)
    return 1;
  else
      return 0;
}

int Full (struct tree_node *t)
{
    // Test if full
    return false;
}
