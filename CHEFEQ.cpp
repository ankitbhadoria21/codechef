    #include<iostream>
    #include<cstring>
     
    using namespace std;
    int occu[100001]={0};
     
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
     
    int calc(int arr[],int n)
    {
    int max=0;
    for(int i=0;i<n;++i)
    {
    occu[arr[i]]=occu[arr[i]]+1;
    if(occu[arr[i]]>max)
    {
        max=occu[arr[i]];
    }
    }
    return n-max;
    }
     
    int main()
    {
    int arr[100000],t,n;
    scan(t);
    while(t--) {
    scan(n);
    for(int i=0;i<100002;++i) occu[i]=0;
    for(int i=0;i<n;++i)
        scan(arr[i]);
    cout<<calc(arr,n)<<endl;
     
    }
    return 0;
    } 
