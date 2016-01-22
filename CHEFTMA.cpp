#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
 
multiset<int> option;
 
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
 
int solve(int diff[],int n)
{
multiset<int>::iterator itr;
unsigned long long result=0;
for(int i=0;i<n;++i)
result+=diff[i];
for(int i=0;i<n && !option.empty();++i)
{
itr=option.lower_bound(diff[i]);
if(itr==option.end())
{
--itr;
result-=*itr;
option.erase(itr);
}
else {
if(*itr==diff[i])
{
result-=*itr;
option.erase(itr);
}
else if(itr!=option.begin())
{
--itr;
result-=*itr;
option.erase(itr);
}
 
}
 
}
return result;
}
 
int main()
{
int t,n,k,m;
int a[100000],b[100000],c;
cin>>t;
while(t--)
{
scan(n);scan(k);scan(m);
for(int i=0;i<n;++i)
scan(a[i]);
for(int i=0;i<n;++i)
scan(b[i]);
for(int i=0;i<k;++i){
scan(c);
option.insert(c);}
for(int i=0;i<m;++i){
scan(c);
option.insert(c);
}
int diff[100000];
for(int i=0;i<n;++i)
diff[i]=a[i]-b[i];
cout<<solve(diff,n)<<endl;
option.clear();
}
return 0;
