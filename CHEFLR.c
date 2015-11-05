#include<stdio.h>
char arr[100001];
 
int main()
{
int t;
int i;
unsigned long prev,level, val;
scanf("%d\n",&t);
while(t--)
{
i=0;
prev=1;level=1;
scanf("%s\n",arr);
while(arr[i])
{
level++;
if(!(level%2)) {
if(arr[i]=='l')val=(2*prev)%1000000007;
else val=(2*prev+2)%1000000007;
prev=val%1000000007;
i++;continue;
}
if(level%2) {
if(arr[i]=='l') val=(2*prev-1)%1000000007;
else val=(2*prev+1)%1000000007;
prev=val%1000000007;
i++;continue;
}
 
}
printf("%lu\n",prev);
}
return 0;
}
