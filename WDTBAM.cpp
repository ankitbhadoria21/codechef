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
        int w[1001];
        int solve(char ans[],char chef_a[],int n)
        {
        int max=w[0],count=0;
        for(int i=0;i<n;++i)
        {
        if(ans[i]==chef_a[i] )
        {
        count++;
        if(w[count]>max)
        max=w[count];
        }
        }
        if(count==n) return w[count];
        else return max;
        }
        int main()
        {
        char ans[1000],chef_a[1000];
        int t,n;
        scan(t);
        while(t--)
        {
        scan(n);
        for(int i=0;i<n;++i)
        cin>>ans[i];
        for(int i=0;i<n;++i)
        cin>>chef_a[i];
        for(int i=0;i<n+1;++i)
        scan(w[i]);
        cout<<solve(ans,chef_a,n)<<endl;
        }
        return 0;
        }  
