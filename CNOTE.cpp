#include<iostream>
#include<cstdio> 
using namespace std;
 
inline void scan(int &a) {
 a=0;
 char ch=getchar_unlocked();
 while(ch<'0' || ch>'9')ch=getchar_unlocked();
 while(ch>='0' && ch <='9')
	{
 a=(a<<3)+(a<<1)+ch-'0';
 ch=getchar_unlocked();
 }
}
void solve(int x,int y,int k,int n,int p[],int c[])
{
int left=x-y,i;
for(i=0;i<n;++i)
{
if(p[i]>=left && c[i]<=k) {cout<<"LuckyChef"<<endl;return;}
}
if(i==n) cout<<"UnluckyChef"<<endl;
 
}
 
int main()
{
int t,x,y,k,n,p[1000000],c[1000000];
scan(t);
while(t--)
{
scan(x);scan(y);scan(k);scan(n);
for(int i=0;i<n;++i)
{    scan(p[i]);scan(c[i]);
}
solve(x,y,k,n,p,c);
}
return 0;
}
 
