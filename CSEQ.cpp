#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
 
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
  
  unsigned long long calc(int n,int l,int r,int m)
  {
      int w=n,k=r-l+1;
      unsigned long long result=0;
      int *sum;
      sum=(int*)calloc(1,sizeof(int)*(k+1));
      if(!sum) return 1;
      sum[1]=1;
      int i,j;
      for(i=2;i<=k;++i)
          sum[i]=(sum[i-1]+1)%m;
          result=(result+sum[i-1])%m;
          for( i=1;i<w;++i)
          {
              for(j=2;j<=k;++j)
              {
                  sum[j]=(sum[j-1]+sum[j]);
                  if(sum[j]>m) sum[j]=sum[j]%m;
              }
              result=(result+sum[j-1]);
              if(result>m)result=result%m;
          }
          free(sum);
          return result;
           
  }
   
    
    int main()
    {
        int m=1000003;
        int t,n,l,r;
        scan(t);
        while(t--)
        {
            scan(n);
            scan(l);
            scan(r);
            printf("%d\n",calc(n,l,r,m));
        }
        return 0;
    }
