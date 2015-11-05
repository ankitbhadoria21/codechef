#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
 
typedef struct {
 char x;
 int y;
}point;
 
point points[100000];
int results[100000];
bool comp(point a,point b)
{
return (a.y<b.y);
 
}
 
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
 
using namespace std;
 
int main()
{
int m,n,t;
scan(t);
int l=0;
while(t--)
{
scan(n);scan(m);
int k=0;
unsigned long long result=1;
 
for(int i=0;i<m;++i)
{
points[i].x=getchar_unlocked();scan(points[i].y);
}
 
sort(points,points+m,comp);
for(;k<m-1;++k)
{
if(points[k].x==points[k+1].x){continue;}
result=(result*(points[k+1].y-points[k].y))%1000000009;
}
results[l++]=result;
}
for(int i=0;i<l;++i)
    cout<<results[i]<<endl;
return 0;
}
