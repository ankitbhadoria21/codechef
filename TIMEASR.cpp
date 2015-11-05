        #include<iostream>
	#include<cstdio>
        #include<cmath>
        #define abs1(x) ((x)>0?(x):-1*(x))
        using namespace std;
        void solve(double a)
        {
        double temp1,temp2,temp3;
        for(int i=0;i<=11;++i)
        for(int j=0;j<=59;++j)
        {
        temp1=(double)abs1(60*i-11*j)/2;
        if(temp1>180)temp1=360-temp1;
        temp2=(double)abs(temp1-a);
        temp3=(double)1/120;
        if(temp2<=temp3)
        {
        if(i>9 && j>9)
        cout<<i<<":"<<j<<"\n";
        else if(i<=9 && j>9)
        cout<<"0"<<i<<":"<<j<<"\n";
        else if(i>9 && j<=9)cout<<i<<":"<<"0"<<j<<"\n";
        else cout<<"0"<<i<<":"<<"0"<<j<<"\n";
        }
        }
        }
        int main()
        {
        ios_base::sync_with_stdio(false);
        int t;
        double a;
        cin>>t;
        while(t--)
        {
        cin>>a;
        solve(a);
        }
        return 0;
        }  
