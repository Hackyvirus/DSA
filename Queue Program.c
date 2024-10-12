#include<stdio.h>
#include<stdlib.h>

#define max 5

typedef struct {
  int front, rear, size;
  int arr[max];
} Queue;

void initQueue(Queue * queue);
void initQueue(Queue * queue){
  queue->front = 0;
  queue->rear = 0;
  queue->size = 0;
}
int isFull(Queue * queue);
int isFull(Queue * queue){
  return queue->size == max;
}

int isEmpty(Queue * queue);
int isEmpty(Queue * queue){
  return queue->size == 0;
}

int enqueue(Queue * queue, int data);
int enqueue(Queue * queue, int data){
  if(isFull(queue)){
    printf("Queue is Full\n");
    return -1;
  }else{

    queue->arr[queue->rear] = data;
    printf("%d is Enqued to the Queue\n");
    queue->rear  = (queue->rear + 1) % max;
    queue->size++;
  }
}

int dequeue(Queue * queue);
int dequeue(Queue * queue){
  if(isEmpty(queue)){
    printf("Queue is Empty\n");
    return -1;
  }else{
    int value = queue->arr[queue->front];
    printf("The Dequeued Element is %d\n",value);
    queue->front = (queue->front+1) % max;
    queue->size--;
  }
}

void peek(Queue * queue);
void peek(Queue * queue){
  if(isEmpty(queue)){
    printf("Queue is Empty\n");
  }else{
    printf("The Front Element is %d\n", queue->arr[queue->front]);
  }
}

void Display(Queue * queue);
void Display(Queue * queue){
  if(isEmpty(queue)){
    printf("Queue is Empty\n");
  }
  else{
    for(int i = 0;i< queue->size;i++){
      printf("The Queue Elements are %d\n", queue->arr[i]);
    }
  }
}

int main(){
  Queue queue;
  initQueue(&queue);
  enqueue(&queue, 10);
  peek(&queue);
  enqueue(&queue, 11);
  peek(&queue);
  enqueue(&queue, 12);
  peek(&queue);
  
  printf("\n");
  Display(&queue);
  printf("\n");
  
  dequeue(&queue);
  peek(&queue);
  dequeue(&queue);
  peek(&queue);
  dequeue(&queue);
  peek(&queue);
  
  printf("\n");
  Display(&queue);
  printf("\n");
  
  return 0;
}
