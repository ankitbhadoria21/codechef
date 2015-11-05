    #include<iostream>
    #include<cstdio>
    #define ULL unsigned long long
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
     
    ULL solve(int arr[],int n)
    {
    ULL curr=1,start=0,ttl=0;
    int prev=arr[start];
    ULL count=0,temp;
    while(curr<n)
    {
    while(curr<n && arr[curr]>=prev)
    {
    prev=arr[curr];
    curr++;
    ttl++;
    }
    temp=(ttl*(ttl+1))/2;
    count+=temp;
    if(curr<n){
    start=curr;
    prev=arr[start];
    curr++;
    ttl=0;
    }
    }
    return n+count;
    }
     
    int main()
    {
    int t,arr[100000],n;
    scan(t);
    while(t--)
    {
    scan(n);
    for(int i=0;i<n;++i)
    scan(arr[i]);
    cout<<solve(arr,n)<<endl;
    }
    return 0;
    } 
