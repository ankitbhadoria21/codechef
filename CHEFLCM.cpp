    #include<iostream>
    #include<cmath>
    #include<map>
    #include<cstdlib>
    #define ULL unsigned long long
    using namespace std;
     
    map<int,int> prime_factor;
     
    int gcd(int a,int b)
    {
    int quo;
    int temp=a;
    a=(a>b)?a:b;
    b=(a>b)?b:temp;
    while(b!=0)
    {
    temp=a;
    quo=a/b;
    a=b;
    b=temp-quo*b;
    }
    return a;
     
    }
     
    int modulo(int a,int b,int c){
    long long x=1,y=a; 
    while(b > 0){
    if(b%2 == 1){
    x=(x*y)%c;
    }
    y = (y*y)%c; 
    b /= 2;
    }
    return x%c;
    }
     
    long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
    if(b%2 == 1){
    x = (x+y)%c;
    }
    y = (y*2)%c;
    b /= 2;
    }
    return x%c;
    }
     
    bool miller(long long p,int iteration){
    if(p<2){
    return false;
    }
    if(p!=2 && p%2==0){
    return false;
    }
    long long s=p-1;
    while(s%2==0){
    s/=2;
    }
    for(int i=0;i<iteration;i++){
    long long a=rand()%(p-1)+1,temp=s;
    long long mod=modulo(a,temp,p);
    while(temp!=p-1 && mod!=1 && mod!=p-1){
    mod=mulmod(mod,mod,p);
    temp *= 2;
    }
    if(mod!=p-1 && temp%2==0){
    return false;
    }
    }
    return true;
    }
     
     
    int pollard(int n)
    {
    int x=rand()%(n-1)+1;
    int y=x;
    int c=rand()%(n-1)+1;
    int g=1;
    if(!(n%2)) return 2;
    while(g==1)
    {
    x=(mulmod(x,x,n)+c)%n;
    y=(mulmod(y,y,n)+c)%n;
    y=(mulmod(y,y,n)+c)%n;
    g=gcd((int)abs((double)(x-y)),n);
    }
    return g;
     
    }
     
    void factor(int n)
    {
    if(n==1) return;
    if(miller(n,20))
    {
    prime_factor[n]+=1;
    return;
    }
    int d=pollard(n);
    factor(d);
    factor(n/d);
    }
     
    int main()
    {
    int t,n;
    ULL result=1;
    map<int,int>::iterator it;
    cin>>t;
    while(t--)
    {
    cin>>n;
    result=1;
    factor(n);
    it=prime_factor.begin();
    for(;it!=prime_factor.end();++it)
    result*=(pow((double)it->first,it->second+1)-1)/(it->first-1);
    cout<<result<<endl;
    prime_factor.clear();
    }
    return 0;
    } 
