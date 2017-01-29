#include <bits/stdc++.h>
using namespace std;

void lcs(char *a, char *b, int n, int m)
{
int l[n+1][m+1];

  for(int r=0; r<=n; r++)
  {
      for(int c=0; c<=m; c++)
      {
        if(r==0|| c==0)
            l[r][c]=0;
        else if (a[r-1]==b[c-1])
        {
          l[r][c]=1+l[r-1][c-1];
        }
        else
        {
          l[r][c]=max(l[r-1][c],l[r][c-1]);
        }
      }
  }
  printf("longest common subsequence is : %d\n",l[n][m]);
}

int main()
{
   char a[]="AGGTAB";
   char b[]="AGXTXAYB";
   int n=strlen(a);
   int m=strlen(b);
   lcs(a,b,n,m);
   return 0;
}
