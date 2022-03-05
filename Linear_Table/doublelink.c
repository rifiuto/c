#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef int Doublelink;
typedef struct DoubleLinkTable {
  Doublelink elem;
  struct DoubleLinkTable *prev;
  struct DoubleLinkTable *next;
}DLT;
/* ===========algorithm 2.18=============== */
int InitDoubleLink(DLT **node, Doublelink element);
int tail_insert(DLT *node, Doublelink element); /* tail insert */
int insert_with_index(DLT *node, int index, Doublelink element); /* insert element with the index */
/* ===========algorithm 2.19=============== */
int delete_with_index(DLT *node, int index);
/* ======================================== */
void print(DLT *node);
/* ======================================== */

int main(int argc, char *argv[]) {
  printf("These code are used for double link.\n");
  DLT *doublenode;
  InitDoubleLink(&doublenode, INT_MAX);
  Doublelink array[] = {1, 3, 49, 20};
  int length = sizeof(array) / sizeof(Doublelink);
  for(int i=0;i<length;i++){
    tail_insert(doublenode, array[i]);
  }
  insert_with_index(doublenode, 4, 100);
  print(doublenode);
  int delete_index=5;
  printf("After delete with index %d:\n", delete_index);
  delete_with_index(doublenode, delete_index);
  print(doublenode);
  return 0;
}

int InitDoubleLink(DLT **node, Doublelink element)
{
  (*node) = (DLT *) malloc(sizeof(DLT));
  if (!(*node)) {
    printf("Malloc error");
    return 1;
  }

  (*node)->elem = element;
  (*node)->next=NULL;
  (*node)->prev=NULL;
  return 0;
}

int tail_insert(DLT *node, Doublelink element)
{
  DLT *need;
  InitDoubleLink(&need, element);
  while(node->next){
    node=node->next;
  }
  node->next = need;
  need->prev = node;
  return 0;
}

void print(DLT *node)
{
  node = node->next;
  while (node) {
    printf("%d ", node->elem);
    node = node->next;
  }
  printf("\b\n");
}

int insert_with_index(DLT *node, int index, Doublelink element)
{
  DLT *need;
  InitDoubleLink(&need, element);
  int count=0;
  while (node && count<index) {
    count++;
    node = node->next;
  }
  if (!node || count < index) {
    printf("Index is error\n");
    return 1;
  }
  if (!node->next) {
    tail_insert(node, element);
  }else {
    need->next = node->next;
    need->prev = node;
    node->next->prev = need;
    node->next = need;
  }
  return 0;
}

int delete_with_index(DLT *node, int index)
{
  int count=0;
  while (node && count<index) {
    count++;
    node = node->next;
  }
  if (!(node->next) || count < index) {
    printf("Index is error\n");
    return 1;
  }
  DLT *temp=node->next;
  temp->prev = node;
  node->next = temp->next;
  free(temp);
  return 0;
}
