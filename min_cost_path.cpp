#include<bits/stdc++.h>
using namespace std;
int minnimum(int x, int y, int z)
{
  return min(min(x,y),z);
}
int min_cost(int cost[3][3],int m,int n)
{
  int dp[3][3];
  dp[0][0]=cost[0][0];
  for(int r=1; r<=m; r++)
  {
    dp[r][0]=dp[r-1][0] + cost[r][0];
  }
  for(int c=1; c<=n; c++)
  {
    dp[0][c]=dp[0][c-1] + cost[0][c];
  }
  for(int r=1; r<=m; r++)
  {
    for(int c=1; c<=n; c++)
    {
      dp[r][c]=cost[r][c] + minnimum(dp[r-1][c],dp[r][c-1],dp[r-1][c-1]);
    }
  }
  return dp[m][n];
}
int main()
{
  int cost[3][3]={{1,2,3},
                  {4,8,2},
                  {1,5,3}};
  int x=min_cost(cost,2,2);
  cout<<"The minimum cost to reach at (2,2) is :"<<x<<endl;
  return 0;
}
