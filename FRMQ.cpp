        #include<iostream>
        #include<cmath>
        #include<cstdlib>
	#include<cstdio>
        #define MAX_Y 21
        #define MAX_X 100000
        #define max_e(x,y) ((x)>(y)?(x):(y))
        #define min_e(x,y) ((x)>(y)?(y):(x))
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
        int max_a[MAX_Y][MAX_X];
        int log_c[100002];
        void create(int arr[],int n)
        {
        for(int len=0;len<n;++len)
        max_a[0][len]=len;
        for(int win=1;(1<<win)<=n;++win)
        for(int start=0;start+(1<<win)-1<n;++start)
        {
        if(arr[max_a[win-1][start+(1<<(win-1))]]>arr[max_a[win-1][start]])
        max_a[win][start]=max_a[win-1][start+(1<<(win-1))];
        else max_a[win][start]=max_a[win-1][start];
        }
        }
        int query(int arr[],int n,int start,int end)
        {
        int k=log_c[end-start+1];
        if(arr[max_a[k][start]]>=arr[max_a[k][end-(1<<k)+1]])
        return arr[max_a[k][start]];
        else return arr[max_a[k][end-(1<<k)+1]];
        }
        int main()
        {
        int n,x1,y1,m,x[100001],y[100001],max_v,arr[100000],min_v,q1,q2;
        register int n1;
        unsigned long long sum=0;
        scan(n);
        for(int i=0;i<n;++i)
        scan(arr[i]);
        scan(m);scan(x1);scan(y1);
        create(arr,n);
        log_c[0]=-1;
        for(int i=1;i<=100002;++i) log_c[i]=log_c[i-1]+((i & (i - 1)) == 0 ? 1 : 0);
        n1=n-1;
        for(int i=0;i<n;++i)
        {
        x[i]=(i+7);
        while(x[i]>=n1)x[i]-=n1;
        y[i]=(i+11);
        while(y[i]>=n)y[i]-=n;
        }
        for(int i=0;i<m;++i)
        {
        sum+=(x1>y1?query(arr,n,y1,x1):query(arr,n,x1,y1));
        x1=x[x1];
        y1=y[y1];
        }
        cout<<sum<<"\n";
        return 0;
        }   
     
