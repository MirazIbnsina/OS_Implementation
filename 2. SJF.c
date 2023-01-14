#include<stdio.h>
 
int main() {
    int n, i, avg_wt=0,avg_tat=0;
    
    printf("How many process(p)?: ");
    scanf("%d",&n);
    int bt[n-1],wt[n-1],tat[n-1];
    
    printf("\nEnter Burst Time --\n");
    for(i=0;i<n;i++) {
        printf("For P[%d]: ",i+1);
        scanf("%d",&bt[i]);
    }
    
    wt[0]=0;
    printf("\nProcess\t\tBurst\tWaiting\t\tTurnaround");
    for (i=0; i<n; i++) {
        wt[i+1] = bt[i]+wt[i];
        tat[i] = wt[i] + bt[i];
        printf("\n P[%d]\t\t %d\t\t %d\t\t\t %d",i+1,bt[i],wt[i],tat[i]);
        avg_wt+=wt[i];
        avg_tat+=tat[i];
    }
    
    printf("\n\nAverage Waiting Time:%d",avg_wt/i);
    printf("\nAverage Turn Around Time:%d",avg_tat/i);
 
    return 0;
}
