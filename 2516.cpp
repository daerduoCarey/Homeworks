#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>

using namespace std;

const int MAX_INT=20000000;
int n,m,k,ok,ans,total;
int order[51][51]={0},storage[51][51]={0},trans[51][51][51];
int a[200][200]={0},c[200][200]={0};
int q[10000]={0},he,ta,d[200]={0},f[200]={0},pre[200]={0};

int min(int x,int y) {if(x<y) return x; return y;}

int min_cost()
{
    int tt;
    int tmpans=0;
    while(1)
    {
        for(int i=0;i<=m+n+1;++i) {d[i]=pre[i]=0;f[i]=MAX_INT;}
        q[1]=0;d[0]=1;he=ta=1;f[0]=0;pre[0]=0;
        while(he<=ta)
        {
            tt=q[he++];
            for(int i=0;i<=m+n+1;++i)
                if(a[tt][i])
                {
                    if(f[tt]+c[tt][i]<f[i])
                    {
                        f[i]=f[tt]+c[tt][i];
                        pre[i]=tt;
                        if(!d[i]) {q[++ta]=i;d[i]=1;}
                    }
                }
            d[tt]=0;
        }
        if(f[m+n+1]<MAX_INT)
        {
            int kk=m+n+1,tmp=MAX_INT;
            while(pre[kk]!=kk)
            {
                if(a[pre[kk]][kk]<tmp) tmp=a[pre[kk]][kk];
                kk=pre[kk];
            }
            tmpans+=f[m+n+1]*tmp;
            kk=m+n+1;
            while(pre[kk]!=kk)
            {
                a[pre[kk]][kk]-=tmp;
                a[kk][pre[kk]]+=tmp;
                kk=pre[kk];
            }
        }
        else break;
    }
    return tmpans;
}

int main()
{
    freopen("2516.in","r",stdin);
    cin>>n>>m>>k;
    while(n)
    {
        ok=1;ans=0;total=0;
        for(int i=1;i<=n;++i) for(int j=1;j<=k;++j) cin>>order[i][j];
        for(int i=1;i<=m;++i) for(int j=1;j<=k;++j) cin>>storage[i][j];
        for(int i=1;i<=k;++i)
            for(int j=1;j<=n;++j)
                for(int kk=1;kk<=m;++kk)
                    cin>>trans[i][j][kk];
        for(int i=1;i<=k;++i)
        {
            int sum1=0,sum2=0;
            for(int j=1;j<=m;++j) sum1+=storage[j][i];
            for(int j=1;j<=n;++j) sum2+=order[j][i];
            if(sum1<sum2) {ok=0;break;}
        }
        for(int i=1;i<=k&&ok;++i)
        {
            memset(a,0,sizeof(a));
            memset(c,0,sizeof(c));
            total=0;
            for(int j=1;j<=m;++j) a[0][j]=storage[j][i];
            for(int j=1;j<=m;++j)
                for(int kk=1;kk<=n;++kk)
                {
                    c[j][m+kk]=trans[i][kk][j];
                    c[m+kk][j]=-trans[i][kk][j];
                    a[j][m+kk]=MAX_INT;
                }
            for(int j=1;j<=n;++j) a[m+j][m+n+1]=order[j][i];
            int tmpans=min_cost();
            ans+=tmpans;
        }
        if(!ok) cout<<-1<<endl;
        else cout<<ans<<endl;
        cin>>n>>m>>k;
    }
    return 0;
}
