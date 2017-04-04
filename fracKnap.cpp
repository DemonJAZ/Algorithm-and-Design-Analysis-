/*
Fractional knapsack , optimum greedy

Input:
n :  number of item
weight[] : weight of n items
Profit[] : profit of n items
m : knapsack size

Output:
Max Profit
Vector Solution (item selected in sequence)

Solution approah:
1. Calculate Profit by weight in descendin order
2. Add to Calculate Max Profit to satisfy required knapsack
*/
#include <iostream>
#include <Vector>
#include <algorithm>
using namespace std;

class item{
public:
  int weight;
  int profit;
  float density;
public:
  item()
  {
      this->profit=0;
      this->weight=0;
      this->density=0;
  }
  inline void setDesnsity() { this->density = (float)this->profit/this->weight; }

  friend bool operator<(item const &a,item const &b)
  {
      return a.density<b.density;
  }
};

int main(int argc, char const *argv[]) {
  int n,k;
  cin>>n;
  cin>>k;
  item *items;
  items = new item[n];
  for (int i = 0; i < n; ++i)
  {
      cin>>items[i].weight;
  }
  for (int i = 0; i < n; ++i)
  {
      cin>>items[i].profit;
      items[i].setDesnsity();
  }
  sort(items,items+n);
  vector<float> itemsadded;
  for (int i = n-1; i >= 0; i--)
  {
      if(items[i].weight < k)
      {
          k-=items[i].weight;
          itemsadded.push_back(items[i].weight);
      }
      else
      {
          itemsadded.push_back(items[i].density*k);
          break;
      }
  }
  for(int i=0;i<itemsadded.size();i++)
  {
      cout<<itemsadded[i]<<" ";
  }
  cout<<endl;
  return 0;
}
