    #include<iostream>
    #include<algorithm>
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
     
    bool comp(int a,int b)
    {
    return (a>b);
    }
     
    int main()
    {
    int t,r,g,b,m;
    int arr_r[100];
    int arr_g[100];
    int arr_b[100];int res[1000];int l=0;
    scan(t);
    while(t--)
    {
    scan(r);scan(g);scan(b);scan(m);
    for(int i=0;i<r;++i)
    scan(arr_r[i]);
    for(int j=0;j<g;++j)
    scan(arr_g[j]);
    for(int j=0;j<b;++j)
    scan(arr_b[j]);
    sort(arr_r,arr_r+r,comp);
    sort(arr_b,arr_b+b,comp);
    sort(arr_g,arr_g+g,comp);
    int max;int max_ind;
    for(int i=0;i<m;++i)
    {
    max=arr_r[0];
    max_ind=0;
    if(arr_g[0]>max){max=arr_g[0];max_ind=1;}
    if(arr_b[0]>max){max=arr_b[0];max_ind=2;}
    switch (max_ind){
    case 0: arr_r[0]/=2;
     break;
    case 1: arr_g[0]/=2;
    break;
    case 2: arr_b[0]/=2;
    break;
    }
     
    }
    max=arr_r[0];
    max_ind=0;
    if(arr_g[0]>max){max=arr_g[0];max_ind=1;}
    if(arr_b[0]>max){max=arr_b[0];max_ind=2;}
    res[l++]=max;
    }
    for(int i=0;i<l;++i)cout<<res[i]<<endl;
    return 0;
    } 
