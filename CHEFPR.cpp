    #include<iostream>
    #include<algorithm>
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
     
    inline int func(int a,int b)
    {
    return a>b?1:0;
    }
     
    int calc(int arr[],int n)
    {
    int sum=0,i;
    if(n==1){
     if(arr[0]<2) return -1;
     else return 2;
     
    }
    sort(arr,arr+n,func);
    for(i=0;i<n-1;++i)
    {
    if(arr[i]<2) return -1;
    sum+=arr[i];
    }
    if(arr[i]>=2){
    sum=sum+2;
    return sum;
    }
    else return -1;
    }
     
    int main()
    {
    int t,n,arr[100000];
    scan(t);
    while(t--)
    {
    scan(n);
    for(int i=0;i<n;++i)
    scan(arr[i]);
    cout<<calc(arr,n)<<endl;
    }
    return 0;
    }
     
