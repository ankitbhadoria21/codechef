        #include<stdio.h>
         
        void scan(int *a) {
                *a=0;
                char ch=getchar_unlocked();
                while(ch<'0' || ch>'9')ch=getchar_unlocked();
                while(ch>='0' && ch <='9')
              {
             *a=((*a)<<3)+((*a)<<1)+ch-'0';
            ch=getchar_unlocked();
           }
         }
         
        short row[250001];
        short column[250001];
        short m_abs(short a)
        {
        if(a<0) return -1*a;
        else return a;
        }
         
        int solve(int a[][500],int n)
        {
        int i,j,cur,steps,next;
        for(i=0;i<n;++i)
        for(j=0;j<n;++j)
        {
        row[a[i][j]]=0;
        row[a[i][j]]=i;
        column[a[i][j]]=0;
        column[a[i][j]]=j;
        }
        cur=1;next=2;
        steps=0;
        while(cur<n*n)
        {
        steps+=m_abs(row[cur]-row[next])+m_abs(column[cur]-column[next]);
        cur=next;
        ++next;
        }
        return steps;
        }
         
        int main()
        {
        int t,i,j,n,a[500][500];
        scan(&t);
        while(t--)
        {
        scan(&n);
        for(i=0;i<n;++i)
        for(j=0;j<n;++j)
        scan(&a[i][j]);
        printf("%i\n",solve(a,n));
        }
        return 0;
        }  
