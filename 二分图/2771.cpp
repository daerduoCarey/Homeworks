#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int zushu,n,b,g;
int bh[501],gh[501],lbm[501],lgm[501],lbf[501],lgf[501],th;
char bm[501][200],gm[501][200],bf[501][200],gf[501][200];
char tm[200],tf[200],ts;
int a[501][501]={0},v[501]={0},match[501]={0};
int cmpm(int xx,int yy)
{
    if(lbm[xx]<lgm[yy]) return -1;
    else if(lbm[xx]>lgm[yy]) return 1;
    else
    {
        int ff=0;
        while(ff<lbm[xx]&&bm[xx][ff]==gm[yy][ff]) ++ff;
        if(ff==lbm[xx]) return 0;
        else if(bm[xx][ff]<gm[yy][ff]) return -1;
        else return 1;
    }
}
int cmpf(int xx,int yy)
{
    if(lbf[xx]<lgf[yy]) return -1;
    else if(lbf[xx]>lgf[yy]) return 1;
    else
    {
        int ff=0;
        while(ff<lbf[xx]&&bf[xx][ff]==gf[yy][ff]) ++ff;
        if(ff==lbf[xx]) return 0;
        else if(bf[xx][ff]<gf[yy][ff]) return -1;
        else return 1;
    }
}
bool find(int x)
{
    for(int i=1;i<=g;++i)
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
    freopen("2771.in","r",stdin);
    scanf("%d",&zushu);
    for(int kk=1;kk<=zushu;++kk)
    {
        scanf("%d",&n);b=0;g=0;
        memset(match,0,sizeof(match));
        for(int i=1;i<=n;++i)
        {
            scanf("%d %c %s %s\n",&th,&ts,tm,tf);
            if(ts=='M')
            {
                ++b;
                bh[b]=th;
                for(int j=0;j<strlen(tm);++j) bm[b][j]=tm[j];lbm[b]=strlen(tm);
                for(int j=0;j<strlen(tf);++j) bf[b][j]=tf[j];lbf[b]=strlen(tf);
            }
            else
            {
                ++g;
                gh[g]=th;
                for(int j=0;j<strlen(tm);++j) gm[g][j]=tm[j];lgm[g]=strlen(tm);
                for(int j=0;j<strlen(tf);++j) gf[g][j]=tf[j];lgf[g]=strlen(tf);
            }
        }
        memset(a,0,sizeof(a));
        for(int i=1;i<=b;++i)
            for(int j=1;j<=g;++j)
            {
                if(abs(bh[i]-gh[j])<=40&&cmpm(i,j)==0&&cmpf(i,j)!=0)
                    a[i][j]=1;
            }
        int ans=0;
        for(int i=1;i<=b;++i)
        {
            memset(v,0,sizeof(v));
            if(find(i)) ++ans;
        }
        cout<<n-ans<<endl;
    }
    return 0;
}
