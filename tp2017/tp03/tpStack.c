#include <stdio.h>
#define MAX_SIZE 5

int push(int *stack, int *index, int val){
  if(*index == MAX_SIZE-1) return 0;
  *index = *index+1;
  stack[*index]=val;
  return 1;
}

int pop(int *stack, int *index, int *val){
  if (index < 0) return 0;
  *val = stack[*index];
  *index = *index-1;
  return 1;
}

int peek(int *stack, int index){
  return stack[index];
}

char empty(int index){
  if(index < 0) return 1;
  return 0;
}

char full(int index){
  if(index = MAX_SIZE-1) return 1;
  return 0;
}

int main() {
  int stack[MAX_SIZE];
  int index = -1;
  int val = 12;
  //Tester push(), pop(), peek()
  printf("Is it empty ? : %d\n", empty(index));
  for (char i = 0; i < 5; i++) {
    printf("Was it pushed ? : %d\n", push(stack, &index, val));
    printf("Current peak value : %d\n", peek(stack, index));
    val = val*2;
  }
  printf("Is it full ? : %d\n", full(index));
  printf("Was it popped ? : %d, was : ", pop(stack, &index, &val));
  printf("%d\n", val);
  printf("Current peak value : %d\n", peek(stack, index));
  return 0;
}
