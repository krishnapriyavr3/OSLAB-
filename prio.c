#include<stdio.h>
int main()
{
   int n,p[10],at[10],bt[10],ct[10],tt[10],wt[10],temp[10],pr[10],smallest,count=0,time;
   double avg_tt=0,avg_wt=0,end=0;
   printf("Enter the number of processes\n");
   scanf("%d",&n);
   printf("Enter the arrival time and burst time and priority of the processes\n");
   for(int i=0;i<n;i++)
   {
     printf("p%d\n",i+1);
     scanf("%d%d%d",&at[i],&bt[i],&pr[i]);
     temp[i]=bt[i];
   }
   pr[9]=9876;
   char ganttChart[100] = {0};
   for(time=0;count!=n;time++)
   {
     smallest=9;
     for(int i=0;i<n;i++)
     if(at[i]<=time&&pr[i]<pr[smallest]&&bt[i]>0)
     smallest=i;
     bt[smallest]--;
     if(bt[smallest]==0)
     {
       count++;
       end=time+1;
       ct[smallest]=end;
       wt[smallest]=end-at[smallest]-temp[smallest];
       tt[smallest]=end-at[smallest];
     }
   }
    printf("\nGantt Chart: ");
    for (int i = 0; i < time; i++) {
        if (ganttChart[i] != 0) {
            printf(" %c", ganttChart[i]);
        }
    }
    printf("\n");
   printf("\n---------------------------------------------");
   printf("\nProc\tAT\tBT\tCT\tWT\tTT\n");
   printf("-----------------------------------------------\n");      
   for(int i=0;i<n;i++)
   {
     printf("\np%d\t%d\t%d\t%d\t%d\t%d\n",i+1,at[i],temp[i],ct[i],wt[i],tt[i]);
     avg_wt += wt[i];
     avg_tt += tt[i];
     }
   printf("------------------------------------------------");    
  printf("\nAverage turn around time :%lf\n",avg_tt/n);
  printf("Average waiting time :%lf",avg_wt/n);
 }      
