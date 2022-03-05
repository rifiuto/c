#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef int  Circlelink;
typedef struct Circlesinglelink {
  Circlelink elem;
  struct Circlesinglelink *next;
}CLK;

/* ============algorithm 2.18============== */
int InitSingle(CLK **node, Circlelink element);
int head_insert(CLK **node, Circlelink element);
int make_circle(CLK *node);     /* this function no sense for these code, when you init, you can make the head node circle. */
void print(CLK *node);
/* ======================================== */
int main(int argc, char *argv[]) {
  printf("These code is used for circle link table.\n");
  CLK *singlehead;
  InitSingle(&singlehead, INT_MAX);
  singlehead->next=singlehead;
  Circlelink array[] = {1, 4, 2, 13, 30};
  int length = sizeof(array) / sizeof(Circlelink);
  for(int i=0;i<length;i++){
    head_insert(&singlehead, array[i]);
  }
  /* make_circle(singlehead); */
  print(singlehead);
  return 0;
}

int InitSingle(CLK **node, Circlelink element)
{
  (*node) = (CLK *)malloc(sizeof(CLK));
  if(!(*node)){
    printf("Malloc error");
    return 1;
  }
  (*node)->elem = element;
  (*node)->next = NULL;
  return 0;
}

int head_insert(CLK **node, Circlelink element)
{
  CLK *need, *temp=*node;
  if (InitSingle(&need, element)) {
    printf("Init node error");
    return 1;
  }
  need->next = (*node)->next;
  (*node)->next = need;
}


int make_circle(CLK *node)
{
  CLK *temp=node;
  while (node->next && node->next->elem != INT_MAX) {
    node=node->next;
  }
  node->next=temp;
}

void print(CLK *node)
{
  int count=0;
  /* printf("%d\n", node->elem); */
  node=node->next;
  while(node->elem!=INT_MAX){
	printf("%d ", node->elem);
	node=node->next;
	count++;
  }
  printf("\b\nThe length of this link table is %d\n", count);
}
