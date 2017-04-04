#include <iostream>
#include <vector>
using namespace std;

int knapsacksolve(int n,int weight[],int val[],int k)
{
    cout<<"Pass1"<<endl;
    int arr[n][k+1];
    for (int i = 0; i < n; ++i)
    {
        arr[i][0]=0;
    }
    for(int i = 1; i < k+1; i++)
    {
        arr[0][i]=weight[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1 ; j<k+1 ; j++)
        {
            if(j<weight[i])
                arr[i][j]=arr[i-1][j];
            else
            {
                arr[i][j] = max( val[i] + arr[i-1][j-weight[i]] , arr[i-1][j]);
            }
        }
    }

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < k+1; j++)
    //     {
    //         cout<<arr[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    return arr[n-1][k-1];
}



int main(int argc, char* argv[])
{
    int n,k;
    cin>>n;
    cin>>k;
    int weight[n],val[n];
    for (int i = 0; i < n; ++i)
    {
        cin>>weight[i];
    }
    for (int i = 0; i < n; ++i)
    {
        cin>>val[i];
    }
    int result = knapsacksolve(n,weight,val,k);
    cout<<result<<endl;
    return 0;
}
