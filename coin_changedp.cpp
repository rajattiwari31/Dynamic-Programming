#include<bits/stdc++.h>
using namespace std;

int coin_changedp(int arr[], int m , int n)
{
  int dp[n+1][m];
  for(int c=0; c<m; c++)
      dp[0][c]=1;
  for(int r=1; r<n+1; r++)
  {
    for(int c=0; c<m; c++)
    {
      int x=(r-arr[c]>=0)? dp[r-arr[c]][c]:0;//calculating after considering n with the graetest no.

      int y=(c>=1)? dp[r][c-1]:0;
      dp[r][c]=x+y;
    }
  }
  return dp[n][m-1];
}

int main()
{
  int arr[]={1,2,3};
  int m= sizeof(arr)/sizeof(arr[0]);
  int x=coin_changedp(arr, m, 4);
  cout<<"no. of ways are : "<<x<<endl;
  return 0;
}
