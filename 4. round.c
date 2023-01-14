#include<stdio.h>
int main() {

    int i, q, n,count=0, avg_wt=0, avg_tat=0, btsum=0;

    printf("Enter the process number: ");
    scanf("%d", &n);
    int tat[n], wt[n], bt[n], mbt[n];

    printf("Enter Brust Time --\n");
    for(i=0; i<n; i++){
        printf("For P[%d]: ", i+1);
        scanf("%d", &bt[i]);
        mbt[i] = bt[i];
        btsum += bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &q);


    while (count < btsum) {
        for (i=0; i<n; i++) {
            if (bt[i]>=q) {
                    wt[i] += count;
                    count = count+q;
                    bt[i] = bt[i]-q;
                    if (bt[i]==0) {
                        tat[i] = count;
                    }
            }
            else {
                if (bt[i] != 0) {
                    wt[i] += count;
                    count += bt[i];
                    bt[i] = 0;
                    tat[i] = count;
                }
            }
        }
    }
    
    
    for(i=0;i<n;i++) {
      wt[i]=tat[i]-mbt[i];
      avg_wt += wt[i];
      avg_tat += tat[i];
   }

    printf("\nProcess\t\tBurst Time\tWaiting Time\tTAT");
    for(i=0; i<n; i++) {
        printf("\nP[%d]\t\t %d\t\t\t%d\t\t\t\t %d",i+1,mbt[i],wt[i],tat[i]);
    }


    printf("\nAverage Turn Around Time: \t%d", avg_wt/n);
    printf("\nAverage Waiting Time: \t%d", avg_tat/n);
    
    return 0;
}
