#include<stdio.h>
void main()
{
   int p[10],tt[10],bt[10],wt[10],j,n,i,temp;
   float avg_tt=0.0,avg_wt=0.0;
   printf("Enter the number of process\n");
   scanf("%d",&n);
   printf("Enter the burst time\n");
   for(i=0;i<n;i++)
   {
     p[i]=i+1;
     scanf("%d",&bt[i]);
   }
   for(i=0;i<n;i++)
   {
      printf("process id: %d\n",p[i]);
      printf("burst time: %d\n",bt[i]);
   }
   for(i=0;i<n-1;i++)
     for(j=0;j<n-i-1;j++)
       if(bt[j]>bt[j+1]){
            temp=p[j];
            p[j]=p[j+1];
            p[j+1]=temp;
            temp=bt[j];
            bt[j]=bt[j+1];
            bt[j+1]=temp;
  }
  wt[0]=0;
   for(i=1;i<=n;i++)
   {
       wt[i]=wt[i-1]+bt[i-1];
   }  
   for(i=0;i<n;i++)
   {
    
     tt[i]=wt[i]+bt[i];
   }  
   for(i=0;i<n;i++)
   {
   avg_wt += wt[i];
   avg_tt += tt[i];
   }
   avg_wt /=n;
   avg_tt /= n;
   printf("\nGantchart\n\n");
   printf("\nprocess\t\tburst time\t\twaiting time\t\tturnaround time\n");
    printf("------------------------------------------------------------------------------------------------------------\n");
   for(i=0;i<n;i++)
   {
     
     printf("|p%d\t\t\t|%d\t\t\t|%d\t\t\t|%d\t\n",p[i],bt[i],wt[i],tt[i]);
     printf("------------------------------------------------------------------------------------------------------------\n");
 
   }
   printf("\naverage waiting time %.2f\n",avg_wt);
    printf("\naverage turnaround time %.2f\n",avg_tt);
    
       
  
 }         
       
