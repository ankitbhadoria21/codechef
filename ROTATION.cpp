    #include<iostream>
    int arr[100000];
    int result[100000];
    using namespace std;
     
    int main()
    {
    int n,m,i,aor=0,opt=0,j=0;
    int flag=0;
    char ch;
    cin>>n>>m;
    for(i=0;i<n;++i)
    cin>>arr[i];
     
    for(i=0;i<m;++i)
    {
    cin>>ch>>opt;
    if(ch=='R'){
    result[j++]=arr[(opt-1+aor)%n];}
    if(ch=='C'){aor=(aor+opt)%n;}
    if(ch=='A'){aor=(aor+n-opt)%n;}
    }
    for(i=0;i<j;++i)
    cout<<result[i]<<"\n";
    return 0;
    }
     
