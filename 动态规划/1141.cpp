#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char c[300],ans[300];int l;
int f[200][200]={0},pre[200][200]={0};
bool open(char s)
{
    if(s=='['||s=='(') return true;
    return false;
}
bool close(char s)
{
    if(s==']'||s==')') return true;
    return false;
}
bool match(char s1,char s2)
{
    if(s1=='('&&s2==')') return true;
    else if(s1=='['&&s2==']') return true;
    return false;
}
void dfs(int lc,int rc,int la,int ra)
{
    if(lc>rc) return;
    if(lc==rc)
    {
        if(c[lc]=='('||c[lc]==')') {ans[la]='(';ans[la+1]=')';}
        else {ans[la]='[';ans[la+1]=']';}
        return ;
    }
    int pp=pre[lc][rc];
    if(pp==-1) {ans[la]=c[lc];ans[ra]=c[rc];dfs(lc+1,rc-1,la+1,ra-1);}
    else if(pp==-2)
    {
        if(c[lc]=='(') {ans[la]='(';ans[ra]=')';dfs(lc+1,rc,la+1,ra-1);}
        else {ans[la]='[';ans[ra]=']';dfs(lc+1,rc,la+1,ra-1);}
    }
    else if(pp==-3)
    {
        if(c[rc]==')') {ans[la]='(';ans[ra]=')';dfs(lc,rc-1,la+1,ra-1);}
        else {ans[la]='[';ans[ra]=']';dfs(lc,rc-1,la+1,ra-1);}
    }
    else
    {
        dfs(lc,pp,la,la+pp-lc+f[lc][pp]);
        dfs(pp+1,rc,la+pp-lc+f[lc][pp]+1,ra);
    }
}
int main()
{
    freopen("1141.in","r",stdin);
    scanf("%s",c);l=strlen(c);
    for(int k=1;k<=l;++k)
        for(int i=0;i<l;++i)
        {
            int j=i+k-1;
            if(j<l)
            {
                f[i][j]=-1;

                if(open(c[i])&&(f[i+1][j]+1<f[i][j]||f[i][j]<0)) {f[i][j]=f[i+1][j]+1;pre[i][j]=-2;}
                if(close(c[j])&&(f[i][j-1]+1<f[i][j]||f[i][j]<0)) {f[i][j]=f[i][j-1]+1;pre[i][j]=-3;}
                if(match(c[i],c[j])&&(f[i+1][j-1]<f[i][j]||f[i][j]<0)) {f[i][j]=f[i+1][j-1];pre[i][j]=-1;}
                for(int p=i;p<j;++p)
                {
                    if(f[i][p]+f[p+1][j]<f[i][j]||f[i][j]<0) {f[i][j]=f[i][p]+f[p+1][j];pre[i][j]=p;}
                }
            }
        }
    dfs(0,l-1,1,l+f[0][l-1]);
    for(int i=1;i<=l+f[0][l-1];++i) cout<<ans[i];
    cout<<endl;
    return 0;
}
