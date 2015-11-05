    #include<iostream>
    #include<cstdio>
    using namespace std;
     
    inline void scan(int &a)
    {
        int sign=1;
        char ch=getchar_unlocked();
        a=0;
        while(ch!='-' && (ch<'0' || ch>'9'))ch=getchar_unlocked();
        if(ch=='-'){sign= -1;ch=getchar_unlocked();}
        while(ch>='0' && ch<='9')
        {
            a=(a<<3)+(a<<1)+ch-'0';
            ch=getchar_unlocked();
        }
        if(sign==-1)a=-1*a;
     
    }
    int main()
    {
    int t,n,m,arr[100];
    scan(t);
    while(t--)
    {
    int max=-1;int sum=0;
    scan(n);scan(m);
    for(int i=0;i<n;++i)
    {
    scan(arr[i]);
    if(arr[i]>max)
    max=arr[i];
    sum+=arr[i];
    }
    if(!((m-n*m+sum)%n))
    cout<<"Yes\n";
    else cout<<"No\n";
    }
     
    return 0;
    }
