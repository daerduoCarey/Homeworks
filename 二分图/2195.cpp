#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAX_INT=10000000;
int m,n,totr,toth,tot;
int c[300][300]={0},a[300][300]={0};
char cc;
int rx[101],ry[101],hx[101],hy[101];
int q[100000]={0},d[300]={0},he,ta,f[300]={0},pre[300]={0};
int dis(int x,int y)
{
    return abs(rx[x]-hx[y])+abs(ry[x]-hy[y]);
}
int main()
{
    freopen("2195.in","r",stdin);
    cin>>m>>n;
    while(m)
    {
        getchar();totr=toth=0;
        for(int i=1;i<=m;++i)
        {
            for(int j=1;j<=n;++j)
            {
                cc=getchar();
                if(cc=='H')
                {
                    ++toth;
                    hx[toth]=i;hy[toth]=j;
                }
                else if(cc=='m')
                {
                    ++totr;
                    rx[totr]=i;ry[totr]=j;
                }
            }
            getchar();
        }
        tot=toth;
        memset(a,0,sizeof(a));
        memset(c,0,sizeof(c));
        for(int i=1;i<=tot;++i) a[0][i]=1;
        for(int i=tot+1;i<=tot+tot;++i) a[i][2*tot+1]=1;
        for(int i=1;i<=tot;++i)
            for(int j=1;j<=tot;++j)
            {
                a[i][j+tot]=MAX_INT;
                c[i][j+tot]=dis(i,j);
                c[j+tot][i]=-dis(i,j);
            }
        int ans=0;
        while(1)
        {
            memset(d,0,sizeof(d));
            memset(pre,0,sizeof(pre));
            for(int i=0;i<=2*tot+1;++i) f[i]=MAX_INT;
            ta=he=1;q[1]=0;f[0]=0;d[0]=1;pre[0]=0;
            while(he<=ta)
            {
                int x=q[he++];
                for(int i=0;i<=2*tot+1;++i)
                    if(a[x][i]&&c[x][i]+f[x]<f[i])
                    {
                        f[i]=f[x]+c[x][i];pre[i]=x;
                        if(!d[i]) {q[++ta]=i;d[i]=1;}
                    }
                d[x]=0;
            }
            if(f[2*tot+1]<MAX_INT)
            {
                int tmp=MAX_INT,tt=2*tot+1;
                while(pre[tt]!=tt)
                {
                    if(a[pre[tt]][tt]<tmp) tmp=a[pre[tt]][tt];
                    tt=pre[tt];
                }
                tt=2*tot+1;ans+=tmp*f[2*tot+1];
                while(pre[tt]!=tt)
                {
                    a[pre[tt]][tt]-=tmp;
                    a[tt][pre[tt]]+=tmp;
                    tt=pre[tt];
                }
            }
            else break;
        }
        cout<<ans<<endl;
        cin>>m>>n;
    }
    return 0;
}
