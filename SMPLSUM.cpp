                    #include<iostream>
                    #include<cmath>
                    #include<map>
                    #include<cstdlib>
                    #include<cstdio>
                    #include<cstring>
                    #define ULL unsigned long long
                    using namespace std;
                     
                    map<int,int> prime_factor;
                    int arr[10000001]; 
                 
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
                 
                void markMultiples(int arr[], int a, int n)
                {
                    int i = 1, num;
                    while ( (num = i*a) <= n )
                    {
                        arr[ num ] = a;
                        ++i;
                    }
                }
                 
                void SieveOfEratosthenes(int n)
                {
                    
                    if (n >= 2)
                    {
                        
                        for (int i=2; i<=n; ++i)
                        {
                            if ( arr[i] == 0 )
                            {
                                markMultiples(arr, i, n);
                            }
                        }
                    }
                
        }
                 
                    int main()
                    {
                    int t,n;
                    ULL ans=1;
             	    arr[1]=1;
        	    SieveOfEratosthenes(10000001);
                    scan(t);
                    while(t--)
                    {
                    scan(n);
                    ans=1;
                 		while(n > 1) {
        			int p =arr[n];ULL pw =1;
        			while(n%p == 0) {
        				pw *=p;
        				n /=p;}
        			ans *=pw*pw-(pw*pw-1)/(p+1);}
        	    cout<<ans<<"\n";
                    }
                    return 0;
                    }
