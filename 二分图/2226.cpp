#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int m,n,b=0,g=0;
char c[51][51];
int a[3001][3001]={0},v[3001]={0},match[3001]={0};
int hh[3001],hl[3001],hr[3001],ss[3001],sl[3001],sr[3001];
bool find(int x)
{
    for(int i=1;i<=g;++i)
        if(a[x][i]&&!v[i])
           {
               v[i]=1;
               if(!match[i]||find(match[i]))
               {
                   match[i]=x;
                   return true;
               }
           }
    return false;
}
int main()
{
    freopen("2226.in","r",stdin);
    cin>>m>>n;
    for(int i=1;i<=m;++i)
    {
        getchar();
        for(int j=1;j<=n;++j) c[i][j]=getchar();
    }
    for(int i=1;i<=m;++i)
    {
        int j=1,r;
        while(j<=n)
        {
            while(j<=n&&c[i][j]=='.') ++j;
            if(j>n) break;
            r=j+1;
            while(c[i][r]=='*'&&r<=n) ++r;
            ++b;
            hh[b]=i;hl[b]=j;hr[b]=r-1;
            j=r+1;
        }
    }
    for(int i=1;i<=n;++i)
    {
        int j=1,r;
        while(j<=m)
        {
            while(j<=m&&c[j][i]=='.') ++j;
            if(j>m) break;
            r=j+1;
            while(c[r][i]=='*'&&r<=m) ++r;
            ++g;
            ss[g]=i;sl[g]=j;sr[g]=r-1;
            j=r+1;
        }
    }
    for(int i=1;i<=b;++i)
        for(int j=1;j<=g;++j)
    {
        if(hh[i]>=sl[j]&&hh[i]<=sr[j]&&hl[i]<=ss[j]&&ss[j]<=hr[i])
            a[i][j]=1;
    }
    int ans=0;
    for(int i=1;i<=b;++i)
    {
        memset(v,0,sizeof(v));
        if(find(i)) ++ans;
    }
    cout<<ans<<endl;
    return 0;
}
