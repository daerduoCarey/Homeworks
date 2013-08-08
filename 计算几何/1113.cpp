#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const double pi=3.1415926;
int n,l;
double length=0.0;
int st[2001],ta;
struct node
{
    int x,y;
}p[2001];
int mul(int x1,int y1,int x2,int y2)
{
    return x1*y2-x2*y1;
}
bool cmp(node a,node b)
{
    int x1=a.x-p[1].x,x2=b.x-p[1].x,y1=a.y-p[1].y,y2=b.y-p[1].y;
    if(mul(x1,y1,x2,y2)>0) return true;
    else if(mul(x1,y1,x2,y2)==0&&(x1*x1+y1*y1)<(x2*x2+y2*y2)) return true;
    return false;
}
int pd(int a,int b,int c)
{
    int x1=p[a].x-p[b].x,x2=p[b].x-p[c].x,y1=p[a].y-p[b].y,y2=p[b].y-p[c].y;
    return mul(x1,y1,x2,y2);
}
double dis(int a,int b)
{
    return sqrt((p[a].x-p[b].x)*(p[a].x-p[b].x)*1.0+(p[a].y-p[b].y)*(p[a].y-p[b].y));
}
double ang(int a,int b,int c)
{
    double x1,x2,y1,y2,dis1,dis2;
    x1=p[b].x-p[a].x;y1=p[b].y-p[a].y;
    x2=p[c].x-p[b].x;y2=p[c].y-p[b].y;
    dis1=sqrt(x1*x1*1.0+y1*y1);
    dis2=sqrt(x2*x2*1.0+y2*y2);
    return acos((x1*x2+y1*y2)/(dis1*dis2));
}
int main()
{
    freopen("1113.in","r",stdin);
    cin>>n>>l;
    int mx,my,mm=-1;
    for(int i=1;i<=n;++i)
    {
        cin>>p[i].x>>p[i].y;
        if(mm==-1||(p[i].x<mx||(p[i].x==mx&&p[i].y<my)))
        {
            mm=i;mx=p[i].x;my=p[i].y;
        }
    }
    int tmp=p[1].x;p[1].x=p[mm].x;p[mm].x=tmp;
    tmp=p[1].y;p[1].y=p[mm].y;p[mm].y=tmp;
    sort(p+2,p+n+1,cmp);
    int f=0;
    for(int i=2;i<n;++i) if(pd(i-1,i,i+1)!=0) {f=1;break;}
    if(!f)
    {
        length=2*dis(1,n)+2*pi*l;
        printf("%.0f\n",length);
    }
    else
    {
        ta=2;st[1]=1;st[2]=2;
        for(int i=3;i<=n;++i)
        {
            while(ta>1&&pd(st[ta-1],st[ta],i)<=0) --ta;
            st[++ta]=i;
        }
        while(ta>1&&pd(st[ta-1],st[ta],1)<=0) --ta;
        st[++ta]=1;
        for(int i=1;i<ta;++i) length+=dis(st[i],st[i+1]);
        double angle=0;
        for(int i=2;i<ta;++i) angle+=ang(st[i-1],st[i],st[i+1]);
        angle+=ang(st[ta-1],st[ta],st[2]);
        length+=angle*l;
        printf("%.0f\n",length);
    }
    return 0;
}
