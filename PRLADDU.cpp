#include<cstdio>
#include<iostream>
using namespace std; 
 
inline void scan(int *a)
{
    int sign=1;
    char ch=getchar_unlocked();
    *a=0;
    while(ch!='-' && (ch<'0' || ch>'9'))ch=getchar_unlocked();
    if(ch=='-'){sign= -1;ch=getchar_unlocked();}
    while(ch>='0' && ch<='9')
    {
        *a=((*a)<<3)+((*a)<<1)+ch-'0';
        ch=getchar_unlocked();
    }
    if(sign==-1)*a=-1*(*a);
 
}
 
int sum[100000];
int dino[100000];
unsigned long res[100000];
int arr[100000];
 
int main()
{
int t,n,l=0;
int j;
scan(&t);
while(t--)
{
int local_sum=0;int ind=0;
unsigned long result=0;
int elem_so_far=0;
int prev=0;
int till_ttl=0;
int i;
int k;
scan(&n);
 
for(k=0;k<n;++k)
{
scan(&arr[k]);
if(arr[k]<0) 
{
dino[ind]=k;
sum[ind++]=local_sum;
}
else local_sum+=arr[k];
}
 
 
for(i=0;i<ind;++i)
{
 
if(-1*arr[dino[i]]==sum[i]-till_ttl)
{
 
while(prev<n && prev<dino[i])
{
if(arr[prev]<0){prev++;continue;}
result+=(dino[i]-prev)*arr[prev];
till_ttl+=arr[prev];
prev++;
}
while(prev<n && arr[prev]<0)
prev++;
continue;
}
 
if(-1*arr[dino[i]]<sum[i]-till_ttl)
{
 
elem_so_far=0;
while(prev<n && elem_so_far!=-1*arr[dino[i]])
{
if(arr[prev]<0){prev++;continue;}
if(arr[prev]<=-1*arr[dino[i]]-elem_so_far)
{
 result+=(arr[prev])*(dino[i]-prev);
 elem_so_far+=arr[prev];
 till_ttl+=arr[prev];
 prev++;
}
else {
result+=(-1*arr[dino[i]]-elem_so_far)*(dino[i]-prev);
arr[prev]=arr[prev]-(-1*arr[dino[i]]-elem_so_far);
till_ttl+=(-1*arr[dino[i]]-elem_so_far);
elem_so_far+=(-1*arr[dino[i]]-elem_so_far);
}
}
 
arr[dino[i]]=0;
continue;
}
 
if(-1*arr[dino[i]]>sum[i]-till_ttl)
{
 
elem_so_far=0;
while(prev<n && prev<dino[i])
{
if(arr[prev]<0){prev++;continue;}
result+=(dino[i]-prev)*arr[prev];
elem_so_far+=arr[prev];
till_ttl+=arr[prev];
prev++;
}
while(prev<n && arr[prev]<0)
prev++;
while(prev<n && elem_so_far!=-1*arr[dino[i]])
{
if(arr[prev]<0){prev++;continue;}
if(arr[prev]<=-1*arr[dino[i]]-elem_so_far)
{
     result+=(arr[prev])*(prev-dino[i]);
      elem_so_far+=arr[prev];
       till_ttl+=arr[prev];
        prev++;
}
else {
    result+=(-1*arr[dino[i]]-elem_so_far)*(prev-dino[i]);
    arr[prev]-=(-1*arr[dino[i]]-elem_so_far);
    till_ttl+=(-1*arr[dino[i]]-elem_so_far);
    elem_so_far+=(-1*arr[dino[i]]-elem_so_far);
}
 
}
 
continue;
}
 
}//for
res[l++]=result;
}//while
 
for(j=0;j<l;++j)
printf("%lu\n",res[j]);
return 0;
}//main 
