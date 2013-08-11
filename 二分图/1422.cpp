#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int zushu;
int n,m;
int a[121][121]={0},v[121]={0},match[121]={0};
bool find(int x)
{
    for(int i=1;i<=n;++i)
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
    freopen("1422.in","r",stdin);
    cin>>zushu;
    for(int tim=1;tim<=zushu;++tim)
    {
        memset(a,0,sizeof(a));
        memset(match,0,sizeof(match));
        cin>>n>>m;
        int x,y;
        for(int i=1;i<=m;++i)
        {
            cin>>x>>y;
            a[x][y]=1;
        }
        int ans=0;
        for(int i=1;i<=n;++i)
        {
            memset(v,0,sizeof(v));
            if(find(i)) ++ans;
        }
        cout<<n-ans<<endl;
    }
    return 0;
}
