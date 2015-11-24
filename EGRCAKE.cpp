                        #include<iostream>
                        using namespace std;

                        inline int bin_gcd(int u,int v)
                        {
                        int shift;
                        if(u==0)return v;
                        if(v==0) return u;
                        for(shift =0;((u|v)&1)==0;++shift)
                        {
                        u>>=1;
                        v>>=1;
                        }
                        while((u&1)==0)u>>=1;
                        do{
                        while((v&1)==0)v>>=1;
                        if(u>v){
                        int tmp=u;
                        u=v;v=tmp;
                        }
                        v=v-u;
                        }while(v!=0);
                        return u<<shift;
                        }
                        
                        void solve(int n,int m){
                        int g=bin_gcd(n,m);
                	    if(g==1) cout<<"Yes\n";
                        else cout<<"No "<<n/g<<"\n";
                        }
                         
                        int main()
                        {
                        int t,n,m;
                        cin>>t;
                        while(t--)
                        {
                        cin>>n;cin>>m;
                        solve(n,m);
                        }
                        return 0;
                        }
