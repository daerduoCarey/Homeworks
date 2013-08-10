#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int n,p,head;
int a[151][151]={0},f[151][151]={0};
int m1[151]={0},m2[151]={0};
void dfs(int k)
{
    f[k][1]=0;
    for(int i=1;i<=n;++i)
        if(a[k][i])
        {
            dfs(i);
            for(int j=p;j>=1;--j)
            {
                f[k][j]=f[k][j]+1;
                for(int t=1;t<j;++t)
                    if(f[i][t]+f[k][j-t]<f[k][j])
                        f[k][j]=f[i][t]+f[k][j-t];
            }
        }
}
int main()
{
    freopen("1947.in","r",stdin);
    cin>>n>>p;int x,y;
    memset(f,63,sizeof(f));
    if(n==1) {cout<<0<<endl;return 0;}
    for(int i=1;i<n;++i)
    {
        cin>>x>>y;
        m1[x]=1;m2[y]=1;
        a[x][y]=1;
    }
    head=1;
    while(1)
    {
        if(m1[head]&&!m2[head]) break;
        ++head;
    }
    dfs(head);
    int ans=f[head][p];
    for(int i=1;i<=n;++i)
        if(i!=head)
        {
            if(ans==-1||f[i][p]+1<ans) ans=f[i][p]+1;
        }
    cout<<ans<<endl;
    return 0;
}
