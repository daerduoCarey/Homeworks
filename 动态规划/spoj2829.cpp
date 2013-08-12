#include<cstdio>
#include<cstring>
#include<cstdlib>
const int MOD=1000000000;
int test_num,n,m;
int c[51]={0},d[16]={0};
int f[2][32769]={0};
void add(int &x,int y)
{
    x+=y;x%=MOD;
}
int main()
{
    freopen("spoj2829.in","r",stdin);
    scanf("%d",&test_num);
    d[0]=1;
    for(int i=1;i<=15;++i) d[i]=d[i-1]<<1;
    for(int tim=1;tim<=test_num;++tim)
    {
        int t;
        scanf("%d%d",&n,&m);
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;++i) scanf("%d",&c[i]);
        t=m&1;
        for(int i=0;i<d[m];++i)
            f[t][i]=1;
        for(int i=2;i<=n;++i)
        {
            t=t^1;
            memset(f[t],0,sizeof(f[t]));
            for(int j=0;j<d[m];++j)
            {
                if(j%c[i-1])
                {
                    if(j&d[m-1])
                    {
                        add(f[t][j&(d[m-1]-1)],f[t^1][j]);
                    }
                    else
                    {
                        f[t][j&(d[m-1]-1)]=f[t^1][j];
                        f[t][(j&(~d[m-1]))|d[m-1]]=f[t^1][j];
                    }
                }
            }
            for(int j=1;j<m;++j)
            {
                t=t^1;
                memset(f[t],0,sizeof(f[t]));
                for(int k=0;k<d[m];++k)
                {
                    if((k&d[m-j-1])==0)
                    {
                        f[t][k|d[m-j-1]]=f[t^1][k];
                        f[t][k&(~d[m-j-1])]=f[t^1][k];
                    }
                    else
                    {
                        add(f[t][k&(~d[m-j-1])],f[t^1][k]);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<d[m];++i) if(i%c[n]) ans=(ans+f[t][i])%MOD;
        printf("%d\n",ans);
    }
    return 0;
}
