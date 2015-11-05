    #include<stdio.h>
    #include<string.h> 
     
    int calc(char s[],int n)
    {
    char prev=s[0],next;
    int loc,i,count=0,count_m=0,flag=1;
    if(n==1)return 0;
    i=1;
    while(s[i])
    {
    next=s[i];
    if(prev!=next)
    {
    prev=next;
    i++;
    continue;
    }
    else {
    if(flag)
    loc=i;
    flag=0;
    prev=((next=='+')?'-':'+');
    count++;
    i++;
    }
     
    }
    if(!flag) {
    prev=s[loc];
    i=loc+1;
    while(s[i])
    {
        next=s[i];
        if(next!=prev)
        {
        prev=next;
        i++;
        continue;
        }
        else 
            {prev=((next=='+')?'-':'+');
            count_m++;
            i++;
        }
    }
    return (count<count_m+loc)?count:count_m+loc;
    }
    return count;
    }
                                           
    int main()
    {
    int t;
    char s[100001];
    scanf("%d",&t);
    while(t--) {
    scanf("%s",s);
    printf("%d\n",calc(s,strlen(s)));
    }
    return 0;
    }
     
