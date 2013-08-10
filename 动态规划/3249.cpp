#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
const int MAX_INT=2000000001;
int n,m;
int a[100001],f[100001],deg[100001],outdeg[100001],out[100001];
int q[100001]={0},he,ta;
int e[1000001]={0},ne[1000001]={0},tot;
void ins(int x,int y)
{
    ++tot;
    e[tot]=y;
    ne[tot]=out[x];
    out[x]=tot;
}
int main()
{
    freopen("3249.in","r",stdin);
    while(scanf("%d%d",&n,&m)==2)
    {
        tot=0;
        memset(deg,0,sizeof(deg));
        memset(outdeg,0,sizeof(outdeg));
        memset(e,0,sizeof(e));
        memset(ne,0,sizeof(ne));
        memset(out,0,sizeof(out));
        for(int i=1;i<=n;++i) {scanf("%d",&a[i]);f[i]=-MAX_INT;}
        he=1;ta=0;
        for(int i=1;i<=m;++i)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ++deg[y];++outdeg[x];
            ins(x,y);
        }
        he=1;ta=0;
        for(int i=1;i<=n;++i) if(deg[i]==0) {q[++ta]=i;f[i]=a[i];}
        while(he<=ta)
        {
            int tt=q[he++];
            int tar=out[tt];
            while(tar)
            {
                --deg[e[tar]];
                if(deg[e[tar]]==0) q[++ta]=e[tar];
                if(f[tt]+a[e[tar]]>f[e[tar]]) f[e[tar]]=f[tt]+a[e[tar]];
                tar=ne[tar];
            }
        }
        int ff=-1,ans;
        for(int i=1;i<=n;++i)
        {
            if(outdeg[i]==0&&(ff==-1||f[i]>ans)) {ans=f[i];ff=0;}
        }
        printf("%d\n",ans);
    }
    return 0;
}
