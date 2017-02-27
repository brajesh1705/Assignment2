#include<bits/stdc++.h>
using namespace std;
int main()
{
	int w,h,a,b,c,d,n;
	cin>>w>>h;
	cin>>n;
	int col[w+1][h+1],row[w+1][h+1];
	long long int dp[w+1][h+1];
	for(int i=0;i<=w;i++)
	{
		for(int j=0;j<=h;j++)
		{
			col[i][j]=dp[i][j]=row[i][j]=0;
		}
	}
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>c>>d;
		if(d>b)
			row[c][d]=1;
		else if(d!=b)
			row[a][b]=1;
		if(a<c)
			col[c][d]=1;
		else if(a!=c)
			col[a][b]=1;
	}
	dp[0][0]=1;
	for(int i=1;i<w+1;i++)
    {
        if(col[i][0])
            dp[i][0]=0;
        else
            dp[i][0]=dp[i-1][0];
        if(row[0][i])
            dp[0][i]=0;
        else
            dp[0][i]=dp[0][i-1];
    }
    for(int i=1;i<h+1;i++)
    {
        for(int j=1;j<w+1;j++)
        {
        	
            if(!col[j][i])
                dp[j][i]+=dp[j-1][i];
            if(!row[j][i])
                dp[j][i]+=dp[j][i-1];
        }
    }
	cout<<dp[w][h]<<endl;
}
