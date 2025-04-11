#include<stdio.h>
#define max 20
main()
{
   int bt[max] ,at[max],ft[max],wt[max],tat[max],p[max];
   int i,j,n,x=0,y=0,z=0,temp1,temp2,temp3,min=0,k,l;
   float t,u;
   printf("Enter the processes to be executed:\n");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   {
       printf("Enter the burst time for process-%d:\n",i);
       scanf("%d",&bt[i]);
       printf("Enter the arrival time for process-%d:\n",i);
       scanf("%d",&at[i]);
       printf("Enter the priority of process-%d:\n",i);
       scanf("%d",&p[i]);
   }
   for(i=1;i<=n;i++)
   {
       for(j=i+1;j<=n;j++)
       {
           if(at[i]>at[j])
           {
               temp1=at[i];
               at[i]=at[j];
               at[j]=temp1;
               temp2=bt[i];
               bt[i]=bt[j];
               bt[j]=temp2;
               temp3=p[i];
               p[i]=p[j];
               p[j]=temp3;
           }
       }
   }
   for(i=1;i<=n;i++)
   {
       min=min+bt[i];
       for(j=i+1;at[j]<=min;j++)
       {
           for(k=j+1;at[k]<=min;k++)
           {
               if(p[k]<p[j])
               {
                   temp1=bt[k];
                   bt[k]=bt[j];
                   bt[j]=temp1;
                   temp2=at[k];
                   at[k]=at[j];
                   at[j]=temp2;
                   temp3=p[i];
                   p[i]=p[j];
                   p[j]=temp3;
               }
           }
       }
   }
   for(i=1;i<=n;i++)
   {
       x=x+bt[i];
       ft[i]=x;
       if(i==1)
           wt[i]=y;
       else
           wt[i]=ft[i-1]-at[i];
           tat[i]=bt[i]+wt[i];
   }
   for(i=1;i<=n;i++)
   {
       y=y+tat[i];
       z=z+wt[i];
   }
   for(i=1;i<=n;i++)
   {
       printf("\nProcess:%d-->at:%d\t bt:%d\t ft:%d\t wt:%d\t tat:%d\t",i,at[i],bt[i],ft[i],wt[i],tat[i]);
   }
   printf("\nAverage waiting time:%d",z/n);
   printf("\nAverage turn around time:%d",y/n);}
