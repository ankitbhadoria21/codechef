#include<iostream>
#include<vector>
#include<climits>
#include<cstdio>
using namespace std;
 
vector<int> primes;
char mem[10001];
 
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
 
void generate_primes(int n)
{
for(int i=2;i<=n;++i)
{
if(mem[i]==1)continue;
for(int j=2;j*i<=10000;++j)
mem[i*j]='1';
}
for(int i=2;i<=n;++i)
if(mem[i]!='1'){primes.push_back(i);
}
}
 
int solve(int arr[],int n)
{
int final[100000];
int min_sum=INT_MAX;
int size=primes.size();
 
for(int i=0;i<size;++i)
{
int req=(primes[i]-arr[0]%primes[i])%primes[i];
int curr_sum=req;
final[0]=arr[0]+req;
 
for(int j=1;j<n;++j)
{
if(final[j-1]<arr[j])
req=(primes[i]-arr[j]%primes[i])%primes[i];
else req=final[j-1]-arr[j];
final[j]=arr[j]+req;
curr_sum+=req;
}
if(curr_sum<min_sum)min_sum=curr_sum;
}
return min_sum;
}
 
int main()
{
int t,n,arr[10000];
scan(t);
generate_primes(10000);
while(t--)
{
scan(n);
for(int i=0;i<n;++i)
scan(arr[i]);
cout<<solve(arr,n)<<endl;
}
return 0;
} 
