#include<iostream>

bool binarySearch(int key, int arr[], int size)
{
    int low = 0;
    int high = size-1;
    while(low<=high)
    {
       int pivot = (low+high)/2;
       if(key<arr[pivot])
         high = pivot - 1;
       else if (key>arr[pivot])
         low = pivot + 1;
       else
          return true;
    }
    return false;
}

int main(){
    int arr[10] = {1,3,6};
    std::cout<<"find 1 "<<binarySearch(1,arr,3)<<std::endl;
}
