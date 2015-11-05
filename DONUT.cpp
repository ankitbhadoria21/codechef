    #include<iostream>
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
     
    long long solve(int a[],int m)
    {
    int one=0,no_one=0,flag=0;
    long long ttl=0;
    if(m==1) return 0;
    for(int i=0;i<m;++i)
    if(a[i]==1)
    one++;
    else no_one++;
    if(one<=no_one-1)
    return no_one-1;
    else {
    if(no_one)
    {
    one-=no_one-1;
    ttl+=no_one-1;
    no_one=1;
    flag=1;
    }
    while(no_one<=one-3)
    {
    one-=3;
    ttl+=1;
    no_one+=1;
    }
    if(no_one)
    {
    one-=no_one-1;
    ttl+=no_one-1;
    if(one==1 || one==2)
    return ttl+1;
    else if(one==0)
    return ttl;
    else if(one==3)return ttl+2;
    }
    else if(flag) if(!one)return ttl;else if(one==1 || one==2)return ttl+1;else return ttl+2;
    else return one-1;
    } 
    }
     
    int main()
    {
    int t,n,m,a[20000];
    scan(t);
    while(t--)
    {
    scan(n);scan(m);
    for(int i=0;i<m;++i)
    scan(a[i]);
    cout<<solve(a,m)<<endl;
    }
    return 0;
    }
     
