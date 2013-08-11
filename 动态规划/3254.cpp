#include<iostream>
#include<cstdio>
using namespace std;
int m,n,d=1;
int a[13][13]={0},f[13][5000]={0},p[13]={0};
bool check(int x)
{
    int ff=1;
    while(x>1)
    {
        if((x&3)==3) {ff=0;break;}
        x=x>>1;
    }
    return ff;
}
int main()
{
    freopen("3254.in","r",stdin);
    cin>>m>>n;
    for(int i=1;i<=n;++i) d*=2;
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>a[i][j];
            p[i]=(a[i][j]<<(j-1))|p[i];
        }
    }
    for(int i=0;i<=d-1;++i)
        if((i|p[1])==p[1]&&check(i)) f[1][i]=1;
    for(int i=1;i<m;++i)
        for(int j=0;j<=d-1;++j)
            for(int k=0;k<=d-1;++k)
                if(check(k)&&(k&j)==0&&(k|p[i+1])==p[i+1])
                    f[i+1][k]=(f[i+1][k]+f[i][j])%100000000;
    int ans=0;
    for(int i=0;i<=d-1;++i) ans=(ans+f[m][i])%100000000;
    cout<<ans<<endl;
    return 0;
}
