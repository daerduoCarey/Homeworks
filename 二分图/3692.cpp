#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int g,b,m,tot=0;
int a[201][201]={0},v[201]={0},match[201]={0};
bool find(int x)
{
    for(int i=1;i<=b;++i)
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
    freopen("3692.in","r",stdin);
    cin>>g>>b>>m;
    while(g!=0||b!=0||m!=0)
    {
        ++tot;
        if(g==0) cout<<"Case "<<tot<<": "<<b<<endl;
        else if(b==0) cout<<"Case "<<tot<<": "<<g<<endl;
        else
        {
            memset(match,0,sizeof(match));
            int x,y;
            for(int i=1;i<=g;++i) for(int j=1;j<=b;++j) a[i][j]=1;
            for(int i=1;i<=m;++i)
            {
                cin>>x>>y;
                a[x][y]=0;
            }
            int ans=0;
            for(int i=1;i<=g;++i)
            {
                memset(v,0,sizeof(v));
                if(find(i)) ++ans;
            }
            cout<<"Case "<<tot<<": "<<b+g-ans<<endl;
        }
        cin>>g>>b>>m;
    }
    return 0;
}
