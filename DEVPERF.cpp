#include<iostream>
#include<climits>
#include<cmath>
#include<cstdio>
 
using namespace std;
 
int main()
{
int t,n,m;
cin>>t;
while(t--)
{
char c;
int min_x=INT_MAX,max_x=INT_MIN ,min_y=INT_MAX,max_y=INT_MIN;
cin>>n>>m;
for(int i=0;i<n;++i)
for(int j=0;j<m;++j)
{
cin>>c;
if(c=='*')
{
if(j>max_x)max_x=j;
if(j<min_x)min_x=j;
if(i>max_y)max_y=i;
if(i<min_y)min_y=i;
}
}
if(min_x==INT_MAX) {cout<<0<<endl;continue;}
int result=0;
int mid_x=min_x+(max_x-min_x)/2,mid_y=min_y+(max_y-min_y)/2;
result=max(max(abs((double)(mid_x-max_x)),abs((double)(mid_x-min_x))),max(abs((double)(mid_y-max_y)),abs((double)(mid_y-min_y))))+1;
cout<<result<<endl;
}
return 0;
} 
 
