#include<stdio.h>

void bs(int arr[], int size);
void bs(int arr[], int size){
  for(int i = 0; i< size-1;i++){
    for(int j = 0; j< size-i-1;j++){
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j]= arr[j+1] ;
         arr[j+1] = temp;
      }
    }
  }
}
void printArr(int arr[],int size);
void printArr(int arr[],int size){
  for(int i = 0;i<size;i++){
    printf("%d\n",arr[i]);
  }
}

int main(){
  int arr[] = {1,5,43,23,2,3,7,8,9,6,10,55};
  int size = sizeof(arr)/sizeof(arr[0]);
 bs(arr,size);
 printArr(arr,size);
  // printf("The value is %d",v);
  return 0;
}
