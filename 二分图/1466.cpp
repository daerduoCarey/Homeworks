#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int n;
int a[501][501]={0},v[501]={0},match[501]={0};
bool find(int x)
{
    for(int i=0;i<n;++i)
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
    freopen("1466.in","r",stdin);
    while(cin>>n)
    {
        memset(match,0,sizeof(match));
        memset(a,0,sizeof(a));
        int x,y,z;
        for(int i=1;i<=n;++i)
        {
            scanf("%d: (%d) ",&x,&y);
            for(int j=1;j<=y;++j)
            {
                cin>>z;
                a[x][z]=1;
            }
        }
        int ans=0;
        for(int i=0;i<n;++i)
        {
            memset(v,0,sizeof(v));
            if(find(i)) ++ans;
        }
        cout<<n-ans/2<<endl;
    }
    return 0;
}
