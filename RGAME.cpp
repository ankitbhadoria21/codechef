     	    #include<iostream>
            #define MODULO 1000000007
             
            using namespace std;
             
            unsigned long long store[100001];
            unsigned long long pow_i[100001];
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
             
            unsigned long long solve(int arr[],int n)
            {
            if(n==2) return (2*(unsigned long long)arr[0]*arr[1])%MODULO;
            unsigned long long tmp;
            store[0]=(2*arr[0])%MODULO;
            store[1]=((2*arr[1])%MODULO+store[0])%MODULO;
            for(int i=2;i<n;++i)
            {
            tmp=(pow_i[i]*arr[i])%MODULO;
            store[i]=(tmp+store[i-1])%MODULO;
            }
            unsigned long long sum=0;
            for(int i=1;i<n;++i)
            {
            sum=(2*sum+arr[i]*store[i-1])%MODULO;
            }
            return sum;
             
            }
             
            int main()
            {
            int arr[100001];
            int t,n;
            cin>>t;
            pow_i[1]=2llu;
            for(int i=2;i<=100000;++i)
            pow_i[i]=(pow_i[i-1]*2)%MODULO;
            while(t--){
            scan(n);
            for(int i=0;i<=n;++i)
            scan(arr[i]);
            cout<<solve(arr,n+1)<<endl;
            }
            return 0;
            }
