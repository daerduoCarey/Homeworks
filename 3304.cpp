#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double eps=1e-8;
int t,n;
double x1[101],x2[101],y11[101],y2[101];
double px[300],py[300];
double mul(double xx1,double yy1,double xx2,double yy2)
{
    return xx1*yy2-xx2*yy1;
}
double dist(double xx1,double yy1,double xx2,double yy2)
{
    return sqrt((xx1-xx2)*(xx1-xx2)+(yy1-yy2)*(yy1-yy2));
}
int main()
{
    freopen("3304.in","r",stdin);
    cin>>t;
    for(int todo=1;todo<=t;++todo)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            cin>>x1[i]>>y11[i]>>x2[i]>>y2[i];
            px[2*i-1]=x1[i];py[2*i-1]=y11[i];
            px[2*i]=x2[i];py[2*i]=y2[i];
        }
        int f=0;
        for(int i=1;i<=2*n&&!f;++i)
            for(int j=i+1;j<=2*n;++j)
            if(dist(px[i],py[i],px[j],py[j])>eps)
            {
                int ff=1;
                for(int k=1;k<=n;++k)
                {
                    if(mul(x1[k]-px[i],y11[k]-py[i],px[i]-px[j],py[i]-py[j])*mul(x2[k]-px[i],y2[k]-py[i],px[i]-px[j],py[i]-py[j])>0)
                       {ff=0;break;}
                }
                if(ff) {f=1;break;}
            }
        if(f) cout<<"Yes!"<<endl;
        else cout<<"No!"<<endl;
    }
    return 0;
}
