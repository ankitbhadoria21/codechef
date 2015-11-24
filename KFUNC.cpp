                #include<iostream>
                #include<cstdio>
                #define ULL unsigned long long
                using namespace std;
                 
                ULL store[10];
                inline void scan(ULL &a) {
                        a=0;
                        char ch=getchar_unlocked();
                        while(ch<'0' || ch>'9')ch=getchar_unlocked();
                        while(ch>='0' && ch <='9')
                        {
                        a=(a<<3)+(a<<1)+ch-'0';
                        ch=getchar_unlocked();
                        }
                }
                inline int sum_d(ULL d)
                {
                int result=0;
                if(d>=0 && d<=9) return d;
                while(d)
                {
                result=(result+d%10);
                if(result>9)
                {
                int tmp=result%10;
                int tmp1=result/10;
                result=tmp+tmp1;
                }
                d/=10;
                }
                return result;
                }
                 
                ULL solve(ULL a,ULL d,ULL l,ULL r)
                {
                int D=sum_d(d);
                int start=sum_d(a+(l-1)*D);
                int next=sum_d(start+D);
                ULL result=start,i=1;
                store[1]=start;
                while(i<(r-l+1) && next!=start){
                ++i;
                store[i]=next;
                result=result+next;
                next=sum_d(next+D);
                }
                if(next==start){
                ULL temp=(r-l+1)/i;
                result=result*temp;
                ULL j=1;
                while(j<=((r-l+1)%i))
                {
                result+=store[j++];
                }
                }
                return result;
                }
                 
                int main()
                {
                ULL t,a,d,l,r;
                scan(t);
                while(t--)
                {
                scan(a);scan(d);scan(l);scan(r);
                cout<<solve(a,d,l,r)<<"\n";
                }
                }
