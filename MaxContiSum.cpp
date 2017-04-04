#include <iostream>
using namespace std;
//int max(int a,int b)
//{
//  return a>b?a:b;
//}

int maxSum(int arr[],int n)
{
  int current_sum=arr[0];
  int max_sum=arr[0];
  for(int i= 1;i<n;i++)
  {
    current_sum = max( arr[i] , current_sum+arr[i]);
    max_sum = max(current_sum,max_sum);
    //cout<<max_sum<<endl;
  }
  return max_sum;
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int arr[n];
  for(int i=0 ; i<n ; i++)
  {
    cin>>arr[i];
  }
  cout<<maxSum(arr,n)<<endl;
  return 0;
}
