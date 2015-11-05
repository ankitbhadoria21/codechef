        #include<iostream>
        #include<cstdio>
        #define ULL unsigned long long
        #define MODU 1000000007
        using namespace std;
        ULL u[1001],l[1001],ttl_sph[1001];
        ULL sum_ttl[1002],sum[1002][2];
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
        void solve(int c)
        {
        ULL temp,temp1;
        for(int i=1;i<=c;++i)
        ttl_sph[i]=(u[i]*l[i])%MODU;
        sum[1][0]=ttl_sph[1];
        for(int i=2;i<=c;++i)
        {
        sum[i][0]=(sum[i-1][0]+ttl_sph[i])%MODU;
        }
        for(int j=2;j<=c;++j)
        {
        for(int i=j;i<=c;++i)
        {
        temp=(sum[i-1][j%2]*ttl_sph[i])%MODU;
        temp1=(sum_ttl[j]+temp)%MODU;
        sum_ttl[j]=temp1;
        sum[i][(j+1)%2]=sum_ttl[j];
        }
        }
        }
        int main()
        {
        int m,n,c,a;
        scan(n);scan(m);scan(c);
        for(int i=1;i<=n;++i)
        {
        scan(a);
        u[a]+=1;
        }
        for(int i=1;i<=m;++i)
        {
        scan(a);
        l[a]+=1;
        }
        solve(c);
        for(int i=2;i<=c+1;++i)
        printf("%d ",sum_ttl[i]);
        printf("\n");
        return 0;
        }  
