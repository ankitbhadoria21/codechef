    #include<iostream>
    #include<cstdio> 
    #define ULL unsigned long long 
    using namespace std;
    int arr[100000];
     
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
     
    ULL solve(int n)
    {
    int prev=0,next=1;
    ULL result=0;
    while(next<=n-1)
    {
    if(arr[prev]^arr[next])
    {
        if(prev==0)
            result+=2;
        else if(prev>=1) {
           if( arr[prev-1]^arr[prev])
            result+=1;
           else result+=2;
    }
    }
    prev=next;
    next=prev+1;;
    }
    return result;
    }
     
     
    int main()
    {
    int t,n;
    scan(t);
    while(t--)
    {
    scan(n);
    for(int i=0;i<n;++i)
        scan(arr[i]);
    cout<<solve(n)<<endl;
     
    }
    return 0;
    }
     
