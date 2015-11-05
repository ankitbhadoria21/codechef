        #include<iostream>
        #include<cmath>
        #include<map>
        #include<cstdlib>
        #include<cstdio>
        #define ULL unsigned long long
        using namespace std;
        int prime[5000001];
        int fact[5000001];
        int some_prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167};
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
        inline int modulo(int a,int b,int c){
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
        inline long long mulmod(long long a,long long b,long long c){
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
        inline bool miller(long long p,int iteration){
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
        inline int pollard(int n)
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
        int factor(int n)
        {
        int d;
        if(n==1) return 0;
        if(miller(n,8))
        {
        prime[n]=1;
        if(n%4==1){
        return 1;}
        else return 0;
        }
        d=pollard(n);
        int d1=factor(d);int d2=0;
        if(!d1)
        d2=factor(n/d);
        if(d1||d2)return 1;
        else return 0;
        }
        int main()
        {
        int t,n,flag;
        scan(t);
        for(int k=0;k<t;++k)
        {
        scan(n);
        if(n>=1 && n<=4){printf("NO\n");continue;}
        if(fact[n]==1){printf("YES\n");continue;}
        for(int i=0;i<39;++i)
        while(some_prime[i]%4!=1 && !(n%some_prime[i]))
        n=n/some_prime[i];
        int st=factor(n);
        if(st==1)
        {
        printf("YES\n");for(int i=1;i*n<=5000000;++i)fact[i*n]=1;
        }
        else printf("NO\n");
        }
        return 0;
        }  
