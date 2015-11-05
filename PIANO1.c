    #include<stdio.h>
    #include<string.h>
     
     
    int calc(char *s,int n)
    {
        int sum=0,i;
        int result=0;
        for(i=0;i<strlen(s);++i)
                sum+=((s[i]=='T')?2:1);
     
                for(i=1;i<=12*n-sum;++i)
                        result+=(12*n-i)/sum;
     
                        return result;
    }
     
    int main()
    {
        int t,n;
        char s[101];
        char ch;
        scanf("%d",&t);
        while(t--)
        {
            scanf("%s",s);
            scanf("%d",&n);
            printf("%d\n",calc(s,n));
        }
        return 0;
    } 
