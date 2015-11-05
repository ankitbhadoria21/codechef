    #include<iostream>
    #include<cmath>
    #include<map>
    #include<cstdlib>
    #include<cstdio> 
    using namespace std;
    int flag=0; 
     
    inline void scan(long long &a) {
            a=0;
            char ch=getchar_unlocked();
            while(ch<'0' || ch>'9')ch=getchar_unlocked();
            while(ch>='0' && ch <='9')
          {
         a=(a<<3)+(a<<1)+ch-'0';
        ch=getchar_unlocked();
       }
     }
     
      long long gcd(long long a,long long b)
      {
          long long quo;
          long long temp=a;
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
       
     
            int main()
            {
                long long t;
                long long a,b;
                scan(t);
                while(t--)
             {
             scan(a);scan(b);
            long long gc,gc1;
            gc=gc1=gcd(a,b);
            while(gc!=1){
            b=b/gc;
            gc1=gc;
            gc=gcd(a,b);
            }
            if(b==1)
            cout<<"Yes\n";
            else cout<<"No\n";
            }
    	return 0;
            }
     
