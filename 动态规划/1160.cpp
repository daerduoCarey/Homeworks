#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int a[301]={0},f[301][31]={0};
int total(int l,int r)
{
    int sum=0;
    for(int i=l;i<=r;++i)
        sum+=abs(a[i]-a[(l+r)>>1]);
    return sum;
}
int main()
{
    freopen("1160.in","r",stdin);
    cin>>n>>m;
    memset(f,63,sizeof(f));
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        f[i][1]=0;
        for(int j=1;j<=i;++j) f[i][1]+=abs(a[j]-a[(i+1)/2]);
    }
    for(int j=2;j<=m;++j)
        for(int i=j;i<=n;++i)
    {
        for(int k=1;k<=i;++k)
            if(f[i-k][j-1]+total(i-k+1,i)<f[i][j])
                f[i][j]=f[i-k][j-1]+total(i-k+1,i);
    }
    cout<<f[n][m]<<endl;
    return 0;
}
