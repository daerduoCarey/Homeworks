#include<iostream>
#include<cstdio>
using namespace std;
int n;long long m;
long long f[100001]={0},a[100001]={0},s[100001]={0};
int q[200000]={0},ta=0;
int main()
{
    freopen("3017.in","r",stdin);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        s[i]=s[i-1]+a[i];
        if(a[i]>m) {cout<<"-1\n";return 0;}
    }
    for(int i=1;i<=n;++i)
    {
        f[i]=-1;
        while(ta>=1&&a[q[ta]]<=a[i]) --ta;
        q[++ta]=i;
        for(int j=ta;j>=1;--j)
        {
            int l=q[j-1]+1,r=q[j];
            while(l<r)
            {
                int mid=(l+r)/2;
                if(s[i]-s[mid-1]<=m) r=mid;
                else l=mid+1;
            }
            if(s[i]-s[l-1]>m) break;
            if(f[i]==-1||(f[l-1]+a[q[j]]<f[i]&&f[l-1]>=0)) f[i]=f[l-1]+a[q[j]];
        }
    }
    cout<<f[n]<<endl;
    return 0;
}
