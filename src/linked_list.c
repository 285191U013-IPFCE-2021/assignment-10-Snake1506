#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == &SENTINEL_node)
    p->next = &SENTINEL_node;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list (node * p)
{
  node *q = p;
  while (q != &SENTINEL_node)
    {
      node *t = q->next;
      free (q);
      q = t;
    }
}


/* print list to console */
void print_list (node * p)
{
    // Add your code for exercise 1
    // There is NO testcode for this

      if (p->next != &SENTINEL_node){
        printf("%d", p->value);
        print_list(p->next);
      }
      else
        printf("%d, ", p->value);
      
      
    }

    
    

int sum_squares (node * p)
{
    // Add your code for excercise 2
    // You can find the tests in tests.cpp

    if (p->next != &SENTINEL_node)
      return (square(p->value)+ sum_squares(p->next));
    else 
      return square(p->value);
}

node *map (node * p, int (*f) (int))
{
    // Add your code for excercise 3
    if (p->next != &SENTINEL_node)
      return map(p->next, square);
    else 
     return map(p->next, square);
}


int square (int x)
{
  return x * x;
}
