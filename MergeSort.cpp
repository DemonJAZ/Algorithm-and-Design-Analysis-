#include <iostream>
#include <limits.h>
#include <fstream>
using namespace std;
void MergeSort(int arr[],int start, int end ){
  if(start<end)
  {
    int mid = (start+end)+1/2;
    MergeSort(arr,start,mid);
    MergeSort(arr,mid+1,end);
    Merge(arr,start,end);
  }
}
int main(int argc, char const *argv[]) {
  int arr[1000],i=0;
  ifstream myfile;
  myfile.open("data.txt");
  while (!myfile.eof()) {
    myfile>>arr[i];
    i++;
  }
  MergeSort(arr,0,i);


  return 0;
}
