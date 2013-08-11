#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int m,n,d=1;
int p[101]={0},f[2][1025][1025]={0},gs[1025]={0},ch[1025]={0};
int s[101][1025]={0};
int geshu(int x)
{
    int tot=0;
    while(x)
    {
        if(x&1) ++tot;
        x=x>>1;
    }
    return tot;
}
bool check(int x)
{
    if (x & (x<<1)) return false;
    if (x & (x<<2)) return false;
    return true;
}
int main()
{
    freopen("1185.in","r",stdin);
    cin>>m>>n;char c;
    for(int i=1;i<=n;++i) d*=2;
    for(int i=0;i<d;++i) {ch[i]=check(i);gs[i]=geshu(i);}
    for(int i=1;i<=m;++i)
    {
        getchar();
        for(int j=1;j<=n;++j)
        {
            c=getchar();
            if(c=='P') p[i]=(p[i]<<1)|1;
            else p[i]=p[i]<<1;
        }
        for(int j=0;j<d;++j)
            if((j|p[i])==p[i]&&ch[j]) s[i][++s[i][0]]=j;
    }
    int ans=0;
    for(int i=1;i<=s[1][0];++i)
    {
        f[1][0][s[1][i]]=gs[s[1][i]];
        if(f[1][0][s[1][i]]>ans) ans=f[1][0][s[1][i]];
    }
    if(m==1) {cout<<ans<<endl;return 0;}
    for(int i=1;i<=s[1][0];++i)
        for(int j=1;j<=s[2][0];++j)
            if((s[1][i]&s[2][j])==0) f[0][s[1][i]][s[2][j]]=f[1][0][s[1][i]]+gs[s[2][j]];
    for(int i=3;i<=m;++i)
    {
        for(int k1=1;k1<=s[i-2][0];++k1)
            for(int k2=1;k2<=s[i-1][0];++k2)
                if((s[i-2][k1]&s[i-1][k2])==0)
            {
                for(int j=1;j<=s[i][0];++j)
                {
                    if((s[i-2][k1]&s[i][j])==0&&(s[i-1][k2]&s[i][j])==0&&f[i%2][s[i-1][k2]][s[i][j]]<f[(i+1)%2][s[i-2][k1]][s[i-1][k2]]+gs[s[i][j]])
                        f[i%2][s[i-1][k2]][s[i][j]]=f[(i+1)%2][s[i-2][k1]][s[i-1][k2]]+gs[s[i][j]];
                }
            }
    }
    ans=0;
    for(int i=1;i<=s[m-1][0];++i)
        for(int j=1;j<=s[m][0];++j)
            if(f[m%2][s[m-1][i]][s[m][j]]>ans) ans=f[m%2][s[m-1][i]][s[m][j]];
    cout<<ans<<endl;
    return 0;
}
