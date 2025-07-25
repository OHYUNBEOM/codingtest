#include<bits/stdc++.h>
using namespace std;
const int dy[]={-1,0,1,0};
const int dx[]={0,1,0,-1};
int n,m,ny,nx,ret;
int a[104][104];
int visited[104][104];
int contact[104][104];
void DFS(int y,int x)
{
	visited[y][x]=1;
	for(int i=0;i<4;i++)
	{
		ny=y+dy[i];
		nx=x+dx[i];
		if(ny<0 || ny>=n || nx<0 || nx>=m || visited[ny][nx]) continue;
		if(a[ny][nx]==0)
		{
			DFS(ny,nx);
		}
		else if(a[ny][nx]==1)
		{
			contact[ny][nx]++;
		}
	}
	return;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}
	while(true)
	{
		memset(visited,0,sizeof(visited));
		memset(contact,0,sizeof(contact));
		DFS(0,0);
		bool flag=false;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j]==1 && contact[i][j]>=2)
				{
					a[i][j]=0;
					flag=true;
				}
			}
		}
		if(flag) ret++;
		else break;
	}
	cout<<ret;
}