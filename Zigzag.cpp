#include<iostream>
using namespace std;
int main()
{
    int t;
    cout<<"Enter the number of Test Cases"<<endl;
    cin>>t;
    while(t--)                          
    {
        int n;
        cout<<"Enter the number of elements in the array."<<endl;
        cin>>n;
        int ar[n];
        cout<<"Enter the elements."<<endl;
        for(int i=0;i<n;i++)                             
            cin>>ar[i];
        int dp[2][n+1];
        dp[0][0]=dp[1][0]=1;
        for(int i=1;i<n;i++)
        {
            dp[0][i]=dp[1][i]=0;                
            for(int j=0;j<i;j++)                         
            {
                if(ar[j]<ar[i])
                    dp[0][i]=max(dp[0][i],1+dp[1][j]);
                if(ar[j]>ar[i])
                    dp[1][i]=max(dp[1][i],1+dp[0][j]);
            }
        }
        cout<<"The maximum length of the zigzag array is : "<<max(dp[0][n-1],dp[1][n-1])<<endl;
    }
}

