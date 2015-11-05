#include<stdio.h>
 
typedef struct val{
int loc1;
int pre;
struct val *next;
struct val *prev;
}val;
 
val *loc[400]={0,};
val *head[400]={0,};
int  element[200]={0,};
 
void create(int n,int m,int arr[])
{
 
int i;
for(i=0;i<400;++i)
{
val *temp=malloc(sizeof(val));
loc[i]=temp;
}
 
for(i=0;i<m;++i)
{
val *temp=(val *)malloc(sizeof(val));
temp->loc1=i;
if(!head[arr[i]-1]){loc[arr[i]-1]->next=temp;temp->prev=loc[arr[i]-1];head[arr[i]-1]=temp;continue;}
if(head[arr[i]-1]){temp->next=loc[arr[i]-1]->next;temp->prev=loc[arr[i]-1];loc[arr[i]-1]->next->prev=temp;loc[arr[i]-1]->next=temp;}
 
}
 
}
 
int search(int wid_index,int curr,int *j)
{
 
int i=0;
int max=-1;
int index;
val *temp;
for(;i<wid_index;++i)
{
while(head[element[i]]!=loc[element[i]] && (head[element[i]]->loc1)<curr) head[element[i]]=head[element[i]]->prev;
if(head[element[i]]==loc[element[i]]) {*j=i;return element[i];}
if(max< (head[element[i]]->loc1)-curr)
{
max=head[element[i]]->loc1-curr;
index=element[i];
*j=i;
}
 
}
 
return index;
}
 
int solve(int n,int m,int arr[])
{
int i,j;
int window=0;
int count=0;
int wid_index=0;
int rep_index;
create(n,m,arr);
for(i=0;i<m;++i)
{
if(!(loc[arr[i]-1]->pre) && window<n)
{
count++;window++;loc[arr[i]-1]->pre=1;
element[wid_index++]=arr[i]-1;
continue;
}
if(window==n)
{
if(loc[arr[i]-1]->pre)continue;
j=search(wid_index,i,&rep_index);
loc[j]->pre=0;
loc[arr[i]-1]->pre=1;
element[rep_index]=arr[i]-1;
count++;
}
 
}
return count;
}
 
 
int main()
{
int t,n,m;
int i,j;
int arr[400];
scanf("%d",&t);
while(t--)
{
i=0;
for(j=0;j<400;++j)
{
if(j<200) element[j]=0;
loc[j]=0;
head[j]=0;
}
 
scanf("%d %d",&n,&m);
while(i<m){arr[i]=0;scanf("%d",&arr[i]);i++;}
printf("%d\n",solve(n,m,arr));
fflush(stdin);
}
return 0;
}
