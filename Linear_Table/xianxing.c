#include <stdio.h>
#include <stdlib.h>
typedef int LineType;
#define INCREASE 1
typedef struct LineTable {
  LineType *elem;
  int length;
  int increase_length;
} LT;
/*============example 2.1=================*/
int InitLT(LineType array[], int length, LT *target);
void print(LT target);
int add_in_tail(LT first, LT *second);
int get_index(LT need, LineType target);
/*=======================================*/

/*============example 2.2================*/
LT sort_insert(LT first, LT second);
/*========================================*/

/*===========algorithm 2.3================*/
int index_insert(LT *first, int index, LineType element);
/*========================================*/
/*===========algorithm 2.4================*/
int index_delete(LT *first, int index);
/*========================================*/
int main()
{
  LT a;
  LineType array[] = {3, 5, 8, 11, 55};

  if(InitLT(array, sizeof(array) / sizeof(LineType), &a)){
	printf("Init error");
  }
  LT b;
  LineType array2[] = {2, 6, 8, 9, 11, 16, 20};
  if(InitLT(array2, sizeof(array2) / sizeof(LineType), &b)){
	printf("Init error");
  }
  
  print(a);
  print(b);

  /* add_in_tail(a, &b); */
  /* printf("After the add the tail"); */
  /* print(b); */
  
  /* use the add sort function */
  print(sort_insert(a, b));

  /* add_in_tail(a, &b); */
  /* printf("After the add the tail"); */
  /* print(b); */
  if(index_insert(&b, 5, 10)){
	printf("Use function index_insert error\n");
  }else{
	print(b);
  }
  /* index delete */
  if(index_delete(&b, 6)){
	printf("Use function index_insert error\n");
  }else{
	print(b);
  }
  
}
int InitLT(LineType array[], int length, LT *target)
{
  (*target).length = 0;
  (*target).increase_length = 0;
  (*target).elem = (LineType *)malloc(length * sizeof(LineType));
  if(!(*target).elem){
	printf("Malloc error");
	return 1;
  }
  for(int i=0;i<length;i++){
	(*target).elem[i] = array[i];
	(*target).length++;
	(*target).increase_length++;
  }

  (*target).increase_length = (*target).length;


  return 0;
}

void print(LT target)
{
  printf("This lenght is %d\n", target.length);
  for(int i=0,len=target.length;i<len;i++){
	printf("%d ", target.elem[i]);
  }
  printf("\b\n");
}

int add_in_tail(LT first, LT *second)
{
  (*second).increase_length += INCREASE;
  (*second).elem = (LineType *) realloc((*second).elem, (*second).increase_length);
  if(!(*second).elem){
	printf("Realloc Error");
  }
  for(int i=0,len=first.length;i<len;i++){
	if(get_index((*second), first.elem[i])){
	  if((*second).length == (*second).increase_length){
		(*second).increase_length += INCREASE;
		(*second).elem = (LineType *) realloc((*second).elem, (*second).increase_length);
		if(!(*second).elem){
		  printf("Realloc Error");
		}
		printf("Realloc\n");
	  }
	  (*second).elem[(*second).length++] = first.elem[i];
	}
  }
}

int get_index(LT need, LineType target)
{
  for(int i=0,len=need.length;i<len;i++){
	if(need.elem[i] == target){
	  return 0;
	}
  }
  return 1;
}


LT sort_insert(LT first, LT second)
{
  /* first and second is sorted */
  LT result;
  result.elem = (LineType *)malloc(sizeof(LineType) * (first.length + second.length));
  result.length=0, result.increase_length=0;
  if(!result.elem){
	printf("Malloc Error");
  }
  int count_a=0, count_b=0;
  while((count_a<first.length)&&(count_b<second.length)){
	if(first.elem[count_a]<second.elem[count_b]){
	  result.elem[result.length++] = first.elem[count_a];
	  count_a++;
	}else{
	  result.elem[result.length++] = second.elem[count_b];
	  count_b++;
	}
  }
  if(count_a==first.length){
	while(count_b<second.length){
	  result.elem[result.length++] = second.elem[count_b];
	  count_b++;
	}
  }else if(count_b==second.length){
	while(count_a<first.length){
	  result.elem[result.length++] = first.elem[count_a];
	  count_a++;
	}
  }
  result.increase_length=result.length;
  return result;
}


int index_insert(LT *first, int index, LineType element)
{
  if(index>(*first).length){
	printf("This index is error");
	return 1;
  }
  /* printf("%d %d\n", (*first).length, (*first).increase_length); */
  if((*first).increase_length-(*first).length<1){
	(*first).increase_length += INCREASE;
	if(!(*first).elem){
	  printf("Realloc Error");
	  return 1;
	}
	(*first).elem = (LineType *) realloc((*first).elem, (*first).increase_length);
  }
  int length=(*first).length;
  while(length>index){
	(*first).elem[length] = (*first).elem[length-1];
	length--;
  }
  (*first).elem[index] = element;
  (*first).length++;
  return 0;
}

int index_delete(LT *first, int index)
{
  if((*first).length == 0){
	printf("This linear table have no element");
	return 1;
  }
  int length=(*first).length;
  while(index<length){
	(*first).elem[index]=(*first).elem[index+1];
	index++;
  }
  (*first).length -= 1;
  return 0;
}
