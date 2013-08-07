#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,l;
double length=0.0;
int st[2001],ta;
long long x[2001]={0},y[2001]={0};
int mul(int a,int b,int c)
{
    int x1,x2,y1,y2;
    x1=x[b]-x[a];y1=y[b]-y[a];
    x2=x[c]-x[b];y2=y[c]-y[b];
    return x1*y2-x2*y1;
}
double ang(int a,int b,int c)
{
    double x1,x2,y1,y2,dis1,dis2;
    x1=x[b]-x[a];y1=y[b]-y[a];
    x2=x[c]-x[b];y2=y[c]-y[b];
    dis1=sqrt(x1*x1*1.0+y1*y1);
    dis2=sqrt(x2*x2*1.0+y2*y2);
    return acos((x1*x2+y1*y2)/(dis1*dis2));
}
double dis(int a,int b)
{
    return sqrt((x[a]-x[b])*(x[a]-x[b])*1.0+(y[a]-y[b])*(y[a]-y[b])*1.0);
}
int main()
{
    freopen("1113.in","r",stdin);
    cin>>n>>l;
    int mx=20000,my=20000,mm;
    for(int i=0;i<n;++i)
    {
        cin>>x[i]>>y[i];
        if(x[i]<mx||(x[i]==mx&&y[i]<my))
        {
            mx=x[i];my=y[i];mm=i;
        }
    }
    ta=2;st[1]=mm;st[2]=(mm+1)%n;
    for(int i=2;i<=n;++i)
    {
        int t=(mm+i)%n;;
        while(ta>1&&mul(st[ta-1],st[ta],t)>=0) --ta;
        st[++ta]=t;
    }
    if(ta==2) {st[3]=st[2];st[2]=(mm+n-1)%n;ta=3;}
    for(int i=1;i<ta;++i) length+=dis(st[i],st[i+1]);
    double angle=0;
    for(int i=2;i<ta;++i) angle+=ang(st[i-1],st[i],st[i+1]);
    angle+=ang(st[ta-1],st[ta],st[2]);
    length+=l*angle;
    cout<<(int)(length+0.5)<<endl;
    return 0;
}
