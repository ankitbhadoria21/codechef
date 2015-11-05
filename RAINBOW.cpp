#include<iostream>
 
using namespace std;
 
unsigned int calc(unsigned int n)
{
int i=0,two=0,three=0,five=0;
unsigned int n1;
unsigned int rslt;
unsigned long long result=1;
for(i=6;i>=1;--i)
{
n1=n+i;
while(!(n1%2)&& two<4)
{
n1=n1/2;
two++;
}
while(!(n1%3)&& three<2)
{
n1=n1/3;
three++;
}
while(!(n1%5) && five<1)
{
n1=n1/5;
five++;
}
result*=n1;
result=result%1000000007;
}
return (unsigned int)result;
 
}
 
int main()
{
unsigned int num;
cin>>num;
if(num<13)
{
cout<<"0\n";
return 0;
}
if(num==13 || num==14)
{
cout<<"1\n";
return 0;
}
else cout<<calc((num-13)/2)<<"\n";
return 0;
}
