#include <bits/stdc++.h>
using namespace std;
int n,k;
int w[101];
int v[101];
int dp[101][100001];

int main() {
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>w[i]>>v[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			if(w[i]>j)
			{
				dp[i][j]=dp[i-1][j];
			}
			else
			{
				dp[i][j]=max(
					dp[i-1][j], 
					dp[i-1][j-w[i]]+v[i]
				);
			}
		}
	}
    cout << dp[n][k] << "\n";
    return 0;
}
