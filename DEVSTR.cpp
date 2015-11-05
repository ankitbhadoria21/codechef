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
     
    inline void scan_s(char *a,int n) {
            int i=0;
            char ch=getchar_unlocked();
            while(ch!='0' || ch!='1')ch=getchar_unlocked();
            while(i++<n && (ch=='0' || ch =='1'))
          {
         a[i]=ch;
        ch=getchar_unlocked();
       }
     }
     
    int one[100001];
    int zero[100001];
    int count_1,count_2; 
    void build_array(char s[],int n)
    {
    for(int i=n-1;i>=0;--i)
    {
    if(s[i]=='1')
    {
        one[i]=one[i+1]+1;
        zero[i]=zero[i+1];
    }
    else{
        zero[i]=zero[i+1]+1;
        one[i]=one[i+1];
    }
    }
    }
    int solve(char arr[],int n,int k)
    {
    int i=0,one_d,zero_d;
    int count=0;
    if(k==1) {
    i=0;
    char prev,next;
    count_1=0,count_2=0;
    prev='1';next='0';
    while(i<n) {
    if(arr[i]^prev)count_1++;
    prev=(prev=='1')?'0':'1';
    if(arr[i]^next)count_2++;
    next=(next=='1')?'0':'1';
    i++;
    }
    return count_1>count_2?count_2:count_1;
    }
    else {
    build_array(arr,n);
    while(i<n)
    {
    if(i+k>=n) break;
    one_d=one[i]-one[i+k];
    zero_d=zero[i]-zero[i+k];
    if(arr[i+k]=='1')++one_d;
    else ++zero_d;
    if(one_d<=k && zero_d<=k)
    {
    i++; continue;
    }
    if(one_d==k+1 )
    {
    int diff=i+2*(k)<n?zero[i+k]-zero[i+2*(k)]:zero[i+k]-zero[n-1];
    if(diff+1<k ||(diff+1==k && arr[i+2*(k)]!='0')){
    arr[i+k]='0';
    ++zero[i+k];
    --one[i+k];
    i+=k;
    ++count;
    continue;
    }
    else if((diff+1==k && arr[i+2*(k)]=='0')){
    arr[i+k-1]='0';
    i+=k;
    ++count;
    continue;
    }
    }
    else if(zero_d==k+1 )
    {
        int diff=i+2*(k)<n?one[i+k]-one[i+2*(k)]:one[i+k]-one[n-1];
        if(diff+1<k ||(diff+1==k && arr[i+2*(k)]!='1')){
            arr[i+k]='1';
            ++one[i+k];
            --zero[i+k];
            i+=k;
           ++count;
           continue;
        }
        else if((diff+1==k && arr[i+2*(k)]=='1')){
            arr[i+k-1]='1';
            i+=k;
            ++count;
            continue;
        }
     
    }
     
    }
    return count;
    }
    }
    int main()
    {
    int t,n,k;
    char s[100001]={'\0'};
    scan(t);
    while(t--)
    {
    scan(n);scan(k);
    cin>>s;
    if(k==1)
    {
    cout<<solve(s,n,k)<<endl;
    int i=0;
    if(count_1<count_2){
    char curr='1';
    while(i++<n){
    cout<<curr;
    curr=(curr=='0')?'1':'0';
    }
    cout<<endl;
    }
    else {
    i=0;
    char curr='0';
    while(i++<n){
        cout<<curr;
        curr=(curr=='0')?'1':'0';
    }
    cout<<endl;
    }
    }
    else {
    cout<<solve(s,n,k)<<endl;
    cout<<s<<endl;
    }
    }
    return 0;
    }
     
