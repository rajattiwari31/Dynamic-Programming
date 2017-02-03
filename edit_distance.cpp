#include<bits/stdc++.h>
using namespace std;

int minnimum(int x, int y, int z)
{
  return min(min(x,y),z);
}

int editDistDP(char *str1, char *str2, int m ,int n)
{
  int dp[m+1][n+1], r , c;
  for(r=0; r<=m; r++)
  {
    for(c=0; c<=n; c++)
    {
      if(r==0)
         dp[r][c]=c;  // if length of FIRST string is 0 than the minimum opeartions are the length of SECOND string
      else if(c==0)
         dp[r][c]==r; // if length of SECOND string is 0 than the minimum opeartions are the length of FIRST string
      else if(str1[r-1]==str2[c-1])
         dp[r][c]=dp[r-1][c-1];
      else
         {
           dp[r][c]=1+minnimum(dp[r][c-1],dp[r-1][c],dp[r-1][c-1]) ;//insert, remove, replace
         }
    }
  }
  return dp[m][n];
}
int main()
{
  char str1[]="SUNDAY";
  char str2[]="SATURDAY";
  int m=strlen(str1);
  int n=strlen(str2);
  int x=editDistDP(str1,str2,m,n);
  cout<<"The no. Of operations are:"<<x<<endl;
  return 0;
}
