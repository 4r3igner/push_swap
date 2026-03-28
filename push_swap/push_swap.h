#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//---------------------------------------------------------------------
//                        STRUCT DEFINE                                |
//---------------------------------------------------------------------
typedef struct cycled_llist
{
  int                   value;
  int                   index;
  struct  cycled_llist  *next;
  struct  cycled_llist  *prev;

}c_llist;

//--------------------STRUCT MOVES-------------------------------------
c_llist *create_node(c_llist  **head, int value);
c_llist *add_back(c_llist **head, c_llist *new_node);
void  update_lindex(c_llist **head,int flag);


//---------------------------------------------------------------------
//                         MOVING OPERATIONS                           |
//---------------------------------------------------------------------
void  sa(c_llist **head_a,int flag);
void  sb(c_llist **head_b,int flag);
void  ss(c_llist **head_a, c_llist  **head_b);

void pa(c_llist **head_a, c_llist **head_b);
void pb(c_llist **head_a, c_llist **head_b);

void  ra(c_llist  **head_a, int flag);
void  rb(c_llist  **head_b, int flag);
void  rr(c_llist  **head_a,c_llist  **head_b);

void  rra(c_llist  **head_a, int flag);
void  rrb(c_llist  **head_b, int flag);
void  rrr(c_llist  **head_a,c_llist  **head_b);







#endif
