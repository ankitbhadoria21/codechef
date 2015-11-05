    #include<iostream>
    #include<cstdio>
    #include<algorithm>
    #include<cstdio> 
    using namespace std;
     
    long long pow_mat[100000];
     
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
     
    void create(int m)
    {
    pow_mat[0]=1;
    for(int i=1;i<100000;++i)
    {
    pow_mat[i]=(pow_mat[i-1]*2)%m;
    }
    }
     
    int solve(int a[],int n,int m)
    {
    sort(a,a+n,less<int>());
    long long sum_p=0,sum_n=0;
        for(int i=0;i<n;++i)
        {
            sum_p=(sum_p+(pow_mat[i]*a[i]))%m;
            sum_n=(sum_n+(m-(pow_mat[n-i-1]*a[i])%m))%m;
        }
     
        return (sum_p+sum_n)%m;
    }
    int main()
    {
    int t,n,j=0,result[5],arr[100000],m=1000000007;
    scan(t);
    create(m);
    while(t--)
    {
    scan(n);
    for(int i=0;i<n;++i)
        scan(arr[i]);
    result[j++]=solve(arr,n,m);
    }
    for(int i=0;i<j;++i)
    fprintf(stdout,"%d\n",result[i]);
    return 0;
    }  
