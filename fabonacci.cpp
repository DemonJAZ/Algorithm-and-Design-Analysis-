#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
void fabonacci(int a, int b, int n)
{
  if(n>0)
  {
    v.push_back(v[a]+v[b]);
    fabonacci(a+1,b+1,n-1);
  }
  else
    return;
}

int main(int argc, char const *argv[]) {

  v.push_back(1);
  v.push_back(1);
  cout<<"Enter the number of series elements you want to print:";
  int n;
  cin>>n;
  fabonacci(0,1,n);
  for(int i = 0; i<v.size() ; i++)
    cout<<v[i]<<" ";
  cout<<endl;
  return 0;
}
