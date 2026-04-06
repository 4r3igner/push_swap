#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include  <stdbool.h>

//---------------------------------------------------------------------
//                        STRUCT DEFINE                                |
//---------------------------------------------------------------------

typedef struct cycled_llist c_llist;

typedef struct bst
{
  int                 root;
  int                 index; 
  struct cycled_llist *ref2list;
  struct bst          *left;
  struct  bst         *right;
}t_binary;

typedef struct cycled_llist
{
  int                   num;
  int                   index;
  int                   pos;
  int                   cost_a;
  int                   cost_b;
  int                   total_cost;
  bool                  above_median;
  struct  cycled_llist  *target_node;
  struct  cycled_llist  *next;
  struct  cycled_llist  *prev;

}c_llist;

//--------------------STRUCT MOVES-------------------------------------

c_llist *create_node(int num);
c_llist *add_new_node(int num,  c_llist **head);
void  freenclean_list(c_llist **head);


t_binary  *create_bst(int  num,  c_llist *head);
t_binary  *insert_bst(int num,  t_binary  *root, c_llist *head,  int *is_dupp);
void  sort_bst(t_binary *root,  int *index);
void  freenclean_bst(t_binary **root);

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


//-------------------------------------------------------- 
//                      HELPERS
//--------------------------------------------------------- 

void  artons(char *src, int *arr, int *global_p);
int   checkncount(char  *src);
void  upd_position(c_llist  *head);
void  upd_median(c_llist  *head,  int stack_s);
void  error_handler();

void	set_target_b(c_llist *a, c_llist *b);
void	set_target_a(c_llist *a, c_llist *b);
void	sort_stacks(c_llist **a, c_llist **b);
void	finish_rotation(c_llist **stack, int cost, char name);
int stack_size(c_llist  *head);
bool  is_sorted(c_llist *head);
c_llist *find_max(c_llist  *head);
c_llist *find_min(c_llist  *head);
void  set_cost(c_llist  *a,c_llist  *b);
void  sort_three(c_llist  **head);
c_llist *find_cheapest(c_llist  *head);
void cost_formula(c_llist  *node);
void	move_nodes(c_llist **a, c_llist **b);




#endif
