#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
 
#define ULL unsigned long long
 
inline void scan(ULL &a) {
    a=0;
    char ch=getchar_unlocked();
    while(ch<'0' || ch>'9')ch=getchar_unlocked();
    while(ch>='0' && ch <='9')
    {
        a=(a<<3)+(a<<1)+ch-'0';
        ch=getchar_unlocked();
    }
     
}
 
ULL f[10000001]={1,1};
ULL s[10000001];
ULL f_t,sum_t;
 
void calc_f(int n, int m)
{
    ULL imodm,prev=1,sum,prev_t=1;
    
    for(int i=2;i<=m;++i)
    {
        imodm=i%m;
        prev=(prev*imodm)%m;
        f[i]=(prev_t+(prev*imodm))%m;
        prev_t=f[i];
  }
prev=0;
for(int i=1;i<=m;++i)
{
    imodm=i%m;
    s[i]=(prev+imodm)%m;
    prev=s[i];
}
 
}
 
ULL solve(ULL p[],int n,int m)
{
    ULL result=0;
    calc_f(n,m);
    for(int i=1;i<=n;++i)
    {
    if(p[i]>m){result=(result+ (((s[p[i]-(p[i]/m)*m]+(s[m]*(p[i]/m)%m)%m)*(p[i]%m))%m)+f[m])%m;}
    else result=(result+ ((s[p[i]]*(p[i]%m))%m+f[p[i]])%m)%m;
    }
return result;
}
 
 
int main()
{
    int n,m;
    ULL p[100001];
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        scan(p[i]);
   cout<<solve(p,n,m)<<endl;
    return 0;
 
}
