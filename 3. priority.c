#include<stdio.h>
 
int main() {
    int i,j,n,total=0,pos,temp,avg_wt,avg_tat;
    
    
    printf("Enter the process number: ");
    scanf("%d", &n);
    int tat[n], wt[n], bt[n], p[n], pr[n];

    for(i=0;i<n;i++) {
    	printf("For P[%d]: ", i+1);
        printf("Burst Time: ");
        scanf("%d",&bt[i]);
        printf("Priority: ");
        scanf("%d",&pr[i]);
    }
    
    for(i=0;i<n;i++) {
        pos=i;
        for(j=i+1;j<n;j++) {
            if(pr[j]<pr[pos])
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0;
    for(i=1;i<n;i++) {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
        avg_wt+=wt[i];
    }
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++) {
        tat[i]=bt[i]+wt[i];
        avg_tat+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",i,bt[i],wt[i],tat[i]);
    }
 
    printf("\n\nAverage Waiting Time=%d",avg_wt/n);
    printf("\nAverage Turnaround Time=%d\n",avg_tat/n);
 
return 0;
}
