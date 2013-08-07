#include<iostream>
#include<cstdio>
using namespace std;
const int cy[10]={0,-1,-1,-1,0,0,0,1,1,1};
const int cx[10]={0,-1,0,1,-1,0,1,-1,0,1};
int t,n=0;
char c;
long long sum=0;
int x[2000000]={0},y[2000000]={0};
long long mul(long long x1,long long y1,long long x2,long long y2)
{
    return x1*y2-x2*y1;
}
int main()
{
    freopen("1654.in","r",stdin);
    cin>>t;
    for(int kk=1;kk<=t;++kk)
    {
        getchar();sum=0;
        c=getchar();
        int tt;n=0;
        tt=c-'0';
        while(tt!=5)
        {
            ++n;
            x[n]=x[n-1]+cx[tt];
            y[n]=y[n-1]+cy[tt];
            c=getchar();
            tt=c-'0';
        }
        for(int i=1;i<n;++i)
        {
            sum+=mul(x[i],y[i],x[i+1],y[i+1]);
        }
        sum+=mul(x[n],y[n],x[1],y[1]);
        if(sum<0) sum=-sum;
        if(sum%2) cout<<sum/2<<".5\n";
        else cout<<sum/2<<endl;
    }
    return 0;
}
