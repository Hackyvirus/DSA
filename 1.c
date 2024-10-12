#include<stdio.h>
#include<stdlib.h>

#define max 100

typedef struct {
  int top;
  int arr[100];
} Stack ;

void initStack(Stack * stack);
void initStack(Stack * stack){
  stack->top = -1;
}

int isFull(Stack * stack);
int isFull(Stack * stack){
  return stack->top == max-1;
}

int isEmpty(Stack * stack);
int isEmpty(Stack * stack){
  return stack->top == -1;
}

int Push(Stack * stack, int data);
int Push (Stack * stack, int data){
  if(isFull(stack)){
    printf("Stack is Full\n");
  }else{
    printf("%d is Added to stack",data);
    stack->arr[++(stack->top)] = data;
  }
}

int Pop(Stack * stack);
int Pop(Stack * stack){
  if(isEmpty(stack)){
    printf("Stack is Empty\n");
    return -1;
  }else{
    printf("%d is removed from the stack\n",stack->arr[stack->top]);
    stack->arr[(stack->top)--];
  }
}

void peek(Stack * stack);
void peek (Stack * stack){
  if(isEmpty(stack)){
    printf("Stack is Empty");
  }else{
    printf("The Top of Stack %d\n", stack->top);
  }
}

void Display(Stack * stack);
void Display(Stack * stack){
   int i = 0;
   for (i = 0; i<= stack->top;i++){
     printf("%d\n",stack->arr[i]);
   }
}

int main(){
  Stack stack;
  initStack(&stack);
  Push(&stack, 10);
  peek(&stack);
  Push(&stack, 11);
  peek(&stack);
  Push(&stack, 12);
  peek(&stack);
  printf("\n");
  Display(&stack);
  printf("\n");
  Pop(&stack);
  peek(&stack);
  Pop(&stack);
  peek(&stack);
  Pop(&stack);
  peek(&stack);
  Display(&stack);
  printf("\n");
  
  return 0;
}





















