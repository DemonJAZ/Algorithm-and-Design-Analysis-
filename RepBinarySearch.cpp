#include <iostream>
#include <limits.h>
using namespace std;

void BinarySearch(int arr[],int start,int end,int f,int &min,int &max)
{
  int mid = (start+end)+1/2;
  if(start<end){
    if(arr[mid]==f)
    {
      if(arr[mid-1]==f)
        BinarySearch(arr,start,mid-1,f,min,max);
      else
      {
          if(mid < min)
            min = mid;
          return;
      }
      if(arr[mid+1]==f)
        BinarySearch(arr,mid+1,end,f,min,max);
      else
      {
        if(mid > max)
          max = mid;
        return;
      }
    }
    BinarySearch(arr,start,mid-1,f,min,max);
    BinarySearch(arr,mid+1,end,f,min,max);
  }
}
int main(int argc, char const *argv[]) {
  int arr[12]={2,3,4,4,4,4,4,4,5,8,8,10};
  int size=12;
  /*cin>>size;
  int *arr;
  arr = new int[size];
  for(int i = 0 ; i<size ; i++)
    cin>>arr[i];*/
  int f;
  std::cout << "Enter the element to search:";
  std::cin >> f;
  int minIndex,maxIndex;
  minIndex = INT_MAX;
  maxIndex = INT_MIN;

  BinarySearch(arr,0,12,f,minIndex,maxIndex);

  cout<<"Min:"<<minIndex<<endl<<"Max:"<<maxIndex<<endl;
  std::cout << maxIndex - minIndex +1 << '\n';
  return 0;
}
