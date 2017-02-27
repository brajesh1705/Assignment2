#include<bits/stdc++.h>
using namespace std;

int lcs( int *X, int *Y, int m, int n )
{
   int L[m+1][n+1];
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         L[i][j] = 0;
  
       else if (X[i-1] == Y[j-1])
         L[i][j] = L[i-1][j-1] + 1;
  
       else
         L[i][j] = max(L[i-1][j], L[i][j-1]);
     }
   }
   return L[m][n];
}
int main()
{
	int m,t,n;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		int a[n],b[n];
		for(int j=0;j<n;j++)
		{
			cin>>a[j];
			b[j]=a[j];
		}
		sort(b,b+n);
		for(int j=0;j<n;j++)
		{
			if(b[j-1]==b[j])
			b[j]=-1;
		}
		m=lcs(a,b,n,n);
		
		for (int k=1;k<n;k++)
		{
			int x=a[0];
			for(int j=0;j<n-1;j++)
			{
				a[j]=a[j+1];
			}
			a[n-1]=x;
			m=max(m,lcs(a,b,n,n));
		}
		cout<<m<<endl;
	}
}
