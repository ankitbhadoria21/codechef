#include<iostream>
#define ULL unsigned long long
using namespace std;
 
ULL arr[100001];
 
int search(ULL arr[],ULL n,int start,int end)
{
if(start>end) return -1;
int mid=start+(end-start)/2;
if((arr[mid]<n && (arr[mid+1]>n || mid+1>n || mid-1<0))) return mid;
else if(arr[mid]>n)return search(arr,n,start,mid-1);
else if(arr[mid]<n) return search(arr,n,mid+1,end);
return -1;
}
 
void build(ULL arr[],int n) {
arr[1]=1;
for(int i=2;i<=n;++i)
    arr[i]=arr[i-1]+i;
}
 
int main()
{
int n,t,ind;ULL s;
cin>>t;
while(t--)
{
cin>>n>>s;
if((ULL)n*(n+1)/2 == s) cout<<0<<endl;
else if ((ULL)n*(n+1)/2 < s) cout<<1<<endl;
else if (s == n) cout<<n-1<<endl;
else {
build(arr,n);
ind=search(arr,s,1,n);
while (s-arr[ind]<n-ind)
{
ind--;
}
cout<<n-ind<<endl;
}
}
return 0;
}
