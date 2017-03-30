#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>path;
int k=1;
void subsetTrav(vector<int> set,int remain,int current)
{
  //cout<<"REmain:"<<remain<<endl;
  if(set[current]==remain)
  {
    //cout<<"Set Number:"<<set[current]<<endl;
    path.push_back(set[current]);
    cout<<"Set "<<k++<<"= ";
    for(int i=0;i<path.size();i++)
     cout<<path[i]<<" ";
    cout<<endl;
    path.clear();
  }

  if(set[current]<=remain && current+1<set.size())
  {
    //cout<<"Current:"<<current<<endl;
    //cout<<"Set Number:"<<set[current]<<endl;
    path.push_back(set[current]);

    subsetTrav(set,remain-set[current],current+1);
  }
  if(set[current]>remain)
  {
    if(path.size()!=0)
    {
      int x=path[path.size()-1];
      //cout<<"popped"<<x<<endl;
      path.pop_back();
      subsetTrav(set,remain+x,current);
    }
    else
      return;

  }
}

void SubsetFind(vector<int> set,int m)
{
  for(int i=0;i<set.size();i++)
  {
      //cout<<"Passed:"<<set[i]<<endl;
      subsetTrav(set,m,i);
      path.clear();
  }
}

int main(int argc, char const *argv[]) {
  int m,n;
  cin>>m;
  cin>>n;
  vector<int> set;
  while(n--)
  {
    int x;
    cin>>x;
    set.push_back(x);
  }
  sort(set.begin(),set.end());
  //cout<<"SIZE"<<set.size();
  SubsetFind(set,m);
  return 0;
}
