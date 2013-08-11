#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int d[12]={0},n,m;
long long f[12][12][3000]={0};
void print(int x)
{
    int tmp[4000]={0},tot=0;
    while(x)
    {
        ++tot;
        tmp[tot]=x&1;
        x=x>>1;
    }
    for(int i=tot;i>=1;--i) cout<<tmp[i];
}
int modify(int x,int k,int t)
{
    return ((x>>(n-k+1))<<(n-k+1))|(t<<(n-k))|(x%d[n-k]);
}
int main()
{
    freopen("2411.in","r",stdin);
    d[0]=1;
    for(int i=1;i<=11;++i) d[i]=d[i-1]*2;
    scanf("%d%d",&m,&n);
    while(m)
    {
        if((m*n)%2) {printf("0\n");scanf("%d%d",&m,&n);continue;}
        memset(f,0,sizeof(f));
        if(n>1) f[1][2][0]=1;
        if(m>1) f[1][1][1]=1;
        for(int i=1;i<n;++i)
            for(int j=0;j<d[i];++j)
            {
                if(m>1) f[1][i+1][(j<<1)|1]+=f[1][i][j];
                if(i+2<=n) f[1][i+2][j<<2]+=f[1][i][j];
            }
        for(int i=2;i<=m;++i)
        {
            for(int j=0;j<d[n];++j)
            {
                if(j>>(n-1)) f[i][1][j&(d[n-1]-1)]+=f[i-1][n][j];
                else
                {
                    if(i+1<=m) f[i][1][(1<<(n-1))|(j&(d[n-1]-1))]+=f[i-1][n][j];
                    if(n>=2&&(j>>(n-2)&1)==0) f[i][2][j&(d[n-2]-1)]+=f[i-1][n][j];
                }
            }
            for(int j=1;j<n;++j)
                for(int k=0;k<d[n];++k)
                if(f[i][j][k])
                {
                    if(k>>(n-j-1)&1) f[i][j+1][modify(k,j+1,0)]+=f[i][j][k];
                    else
                    {
                        if(j+2<=n&&(k>>(n-j-2)&1)==0) f[i][j+2][modify(modify(k,j+1,0),j+2,0)]+=f[i][j][k];
                        if(i+1<=m) f[i][j+1][modify(k,j+1,1)]+=f[i][j][k];
                    }
                }
        }
        long long ans=0;
        for(int i=0;i<d[n];++i) ans+=f[m][n][i];
        printf("%I64d\n",ans);
        scanf("%d%d",&m,&n);
    }
    return 0;
}
