#include <stdio.h>
#include <stdlib.h>
typedef int Linktype;
typedef struct link_node{
  Linktype elem;
  struct link_node *next;
}LN;
/*==============example 2.3.1=================*/
int Init_link_node(LN **node, Linktype element);
int distribute(LN **Node);
int tail_insert(LN *node, Linktype element);
int head_insert(LN **node, Linktype element);
void print(LN *node);
/*============================================*/
/*==============algorithm 2.7=================*/
int getelement(LN *node, Linktype target);
/*============================================*/
/*==============algorithm 2.8=================*/
int insert_with_index(LN *node, int index, Linktype element);
/*============================================*/
/*==============algorithm 2.9=================*/
int delete_with_index(LN *node, int index);
/*============================================*/
/*==============algorithm 2.11=================*/
LN *sorted_insert(LN *first, LN *second);
/*============================================*/

void free_ram(LN *node);
int main()

  /* On my habit, I like the first node is null */
  LN *link_head;
  Init_link_node(&link_head, 0);
  /* use the tail_insert function */
  Linktype array[] = {1, 23, 9, 34, 0};
  int length = sizeof(array) / sizeof(Linktype);
  /* printf("The length of array is %d\n", length); */
  for(int i=0;i<length;i++){
	tail_insert(link_head, array[i]);
  }
  print(link_head);
  /* use the head_insert function */
  Linktype array2[] = {1, 23, 9, 34, 0};
  int length2 = sizeof(array2) / sizeof(Linktype);
  /* printf("The length of array2 is %d\n", length2); */
  for(int i=0;i<length2;i++){
	head_insert(&link_head, array2[i]);
  }
  /* use print function */
  print(link_head);
  /* use the insert with index */
  insert_with_index(link_head, 3, 100);
  print(link_head);
  delete_with_index(link_head, 0);
  print(link_head);
  int index=getelement(link_head, 230);
  free_ram(link_head);
  /* the below code is used for merge two sorted link table */
  printf("Below code is used for merge two sorted link table\n");
  LN *first_head;
  Init_link_node(&first_head, 0);
  Linktype first[] = {1, 9, 11, 14, 16, 25};
  int lengthf = sizeof(first) / sizeof(Linktype);
  /* printf("The length of array is %d\n", length); */
  for(int i=0;i<lengthf;i++){
	tail_insert(first_head, first[i]);
  }
  LN *second_head;
  Init_link_node(&second_head, 0);
  Linktype second[] = {2, 5, 10, 15, 19};
  int lengths = sizeof(second) / sizeof(Linktype);
  /* printf("The length of array is %d\n", length); */
  for(int i=0;i<lengths;i++){
	tail_insert(second_head, second[i]);
  }
  print(first_head);
  print(second_head);
  print(sorted_insert(first_head, second_head));
  return 0;
}

int Init_link_node(LN **node, Linktype element)
{
  if(distribute(node)){
	printf("Malloc error");
  }
  (*node)->elem = element;
  (*node)->next=NULL;
  return 0;
}

int distribute(LN **node)
{
  *node = (LN *) malloc(sizeof(LN));
  if(!(*node)){
	printf("Malloc error");
	return 1;
  }
  return 0;
}

int tail_insert(LN *node, Linktype element)
{
  LN *need;
  Init_link_node(&need, element);
  while(node->next){
	node=node->next;
  }
  node->next=need;
  /* printf("%d\n", need->elem); */
  return 0;
}

int head_insert(LN **node, Linktype element)
{
  LN *need;
  Init_link_node(&need, element);
  need->next=(*node)->next;
  (*node)->next=need;
}

void print(LN *node)
{
  int count=0;
  while(node->next){
	node=node->next;
	printf("%d ", node->elem);
	count++;
  }
  printf("\b\nThe length of this link table is %d\n", count);
}

int getelement(LN *node,Linktype target)
{
  int index=0;
  while(node->next){
	node=node->next;
	if(node->elem == target){
	  printf("The index of target number %d in this link table is %d.\n", target, index);
	  return 0;
	  break;
	}
	index++;
  }
  printf("The target number %d is't in this link table.\n", target);
  return 1;
}

int insert_with_index(LN *node, int index, Linktype element)
{
  if(!(node->next)){
	printf("This link table is empty");
	return 1;
  }
  int count=0;
  while(node && count<index){
	node=node->next;
	count++;
  }
  if(!node||index>count){
	printf("This index %d is error\n", index);
	return 1;
  }
  LN *need;
  Init_link_node(&need, element);
  need->next=node->next;
  node->next=need;
  return 0;
}

void free_ram(LN *node)
{
  LN *temp;
  while(node){
	temp=node;
	node=node->next;
	free(temp);
  }
}

int delete_with_index(LN *node, int index)
{
  if(!(node->next)){
	printf("This link table is empty");
	return 1;
  }
  int count=0;
  while(node->next && count<index){
	node=node->next;
	count++;
  }
  /* printf("%d %d\n", index, count); */
  if(!(node->next)||index>count){
	printf("This index %d is error\n", index);
	return 1;
  }
  LN *need;
  Init_link_node(&need, 0);
  need=node->next;
  node->next=need->next;
  free(need);
}

LN *sorted_insert(LN *first, LN *second)
{
  LN *sort;
  Init_link_node(&sort, 0);
  first=first->next;
  second=second->next;
  while(first && second){
	if(first->elem < second->elem){
	  tail_insert(sort, first->elem);
	  first=first->next;
	}else{
	  tail_insert(sort, second->elem);
	  second=second->next;
	}
  }
  tail_insert(sort, first ? first->elem : second->elem);
  return sort;
}
