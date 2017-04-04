#include <iostream>
#include <limits.h>
#include <fstream>
using namespace std;
void Merge(int arr[],int start, int mid , int end) {
  int n1 = mid - start + 1;
  int n2 = end - mid;

  int L[n1],R[n2];

  for(int  i = 0 ; i < n1 ; i++)
    L[i] = arr[start+i];
  for(int  i = 0 ; i < n2 ; i++)
    R[i] = arr[mid + 1 + i];

  int i = 0 , j = 0 , k=start;

  while (i<n1 && j<n2) {

    if(L[i]<=R[j])
    {
      arr[k++] = L[i++];
    }
    else
    {
      arr[k++] = R[j++];
    }
  }
  while(i<n1)
  {
    arr[k++] = L[i++];
  }
  while(j<n2)
  {
    arr[k++] = R[j++];
  }
}



void MergeSort(int arr[],int start, int end ){
  if(start < end)
  {
    int mid = (start+end)/2;
    MergeSort(arr,start,mid);
    MergeSort(arr,mid+1,end);
    Merge(arr,start,mid,end);
    for(int i = start ; i < end ; i++)
    {
      cout<<" "<<arr[i]<<" ";
    }
    cout<<endl;
  }
}
int main(int argc, char const *argv[]) {
  int *arr,i=0,size;
  /*ifstream myfile;
  myfile.open("data.txt");
  myfile>>size;
  arr = new int[size];
  while (!myfile.eof()) {
    myfile>>arr[i];
    i++;
  }*/
  cin>>size;
  arr = new int[size];
  for(int i= 0 ; i< size ; i++)
  {
    cin>>arr[i];
  }
  MergeSort(arr,0,size-1);
  //Merge(arr,0,size/2,size);
  for(int i= 0 ; i< size ; i++)
  {
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  return 0;
}
