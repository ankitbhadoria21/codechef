#include<stdio.h>
 
int calc(int arr[],int n,int k)
{
int count,i;
count=0;
 
for(i=0;i<n;++i)
{
if(k==0 && arr[i]%2){return 1;}
if(!(arr[i]%2)){count++;}
if(count==k){return 1;}
}
 
return 0;
 
}
 
int main()
{
int t,n,k,arr[50],i;
 
scanf("%d",&t);
while(t--)
{
i=0;
scanf("%d %d",&n,&k);
while(i<n)
{
scanf("%d",&arr[i]);
i++;
}
 
if(calc(arr,n,k))printf("YES\n");else printf("NO\n");
 
}
 
return 0;
 
}
