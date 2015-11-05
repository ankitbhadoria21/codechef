#include<stdio.h>
 
void check(long x,long y)
{
long n;
int nx=0,ny=0;
if(x==0 && y==0){printf("YES\n");return;}
if(y==0 && ((x>0 && x%2l)))
{
printf("YES\n");
return;
}
if(y==0 && (x<0 && !(x%2l)))
{printf("YES\n"); return;}
 
if(y==0 && (x>0 && !(x%2l)))
{
printf("NO\n");return;
}
 
if(y==0 && (x<0 && (x%2)))
{printf("NO\n"); return;}
 
if(x==0 && !(y%2l))
{
printf("YES\n");
return ;
}
if(x==0 && y%2l)
{
printf("NO\n");
return ;
}
 
 
if(x>0)
{
if(!((x-1)%2)){n=(x-1)/2l+1; nx=1;}
else if(!(y%2)){n=(y>0)?y/2l:(-1*y/2l);ny=1;}
else {printf("NO\n");return;}
if(nx && y>=-2*(n-1) && y<=2*n)
{printf("YES\n");return;}
if(nx && y<-2*(n-1) && (y%2l)) {printf("NO\n");return;}
if(nx && y>2*n && (y%2l)) {printf("NO\n");return;}
if(nx && y<-2*(n-1) && !(y%2l)) {printf("YES\n");return;}
if(nx && y>2*n && !(y%2l)) {printf("YES\n");return;}
if(ny && y>0 && x>=0 && x<=(1+(n-1)*2))
{
printf("YES\n");return;
}
if(ny && y>0 && x>(1+(n-1)*2) && !(x%2l)){printf("NO\n");return;}
if(ny && y>0 && x>(1+(n-1)*2) && (x%2)){printf("YES\n");return;}
if(ny && y<0 && x>=0 && x<=1+n*2)
{
printf("YES\n");return;
}
if(ny && y<0 && x>1+n*2 && !(x%2l)){printf("NO\n");return;}
if(ny && y<0 && x>1+n*2 && x%2l){printf("YES\n");return;}
}
 
if(x<0)
{
if(!(x%2)){n=-1*x/2l;nx=1;}
else if(!(y%2)){n=(y>0)?y/2l:(-1*y/2l);ny=1;}
else {printf("NO\n");return;}
if(nx && y>=-2*n && y<=2*n)
{printf("YES\n");return;}
if(nx && y>2*n && (y%2l)){printf("NO\n");return;}
if(nx && y<-2*n && (y%2l)){printf("NO\n");return;}
if(nx && y>2*n && !(y%2l)){printf("YES\n");return;}
if(nx && y<-2*n && !(y%2l)){printf("YES\n");return;}
if(ny && x>=-2*n && x<=0)
{
printf("YES\n");return;
}
if(ny && x<-2*n && x%2l){printf("NO\n");return;}
if(ny && x<-2*n && !(x%2l)){printf("YES\n");return;}
}
 
}
 
 
int main()
{
int t;
long x,y;
scanf("%d",&t);
while(t--)
{
scanf("%ld %ld",&x,&y);
check(x,y);
}
 
}
