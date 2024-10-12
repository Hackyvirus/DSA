#include<stdio.h>

int binarySearch(int arr[], int size, int val);
int binarySearch ( int arr[], int size, int val){
  int low = 0;
  int high = size -1;
  
while (low <= high){
    int mid = (low+ high)/2;
    
    if(mid == val){
      printf("The value is %d\n", mid);
      return mid;
    }else if(mid>val){
      high= mid -1;
    }else{
      low = mid + 1;
    }
  }
  return -1;
}
int main(){
  int arr[] = {1,2,3,4,5,6,7,8,9,10};
  int size = sizeof(arr)/sizeof(arr[0]);
  int v = binarySearch(arr,size,4);
  // printf("The value is %d",v);
  return 0;
}
