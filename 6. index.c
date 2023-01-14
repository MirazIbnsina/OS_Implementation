#include<stdio.h>
int main() {
	
    int c,n,m,i,j,p;
    int produce[100];
    char pro;

    printf("Enter the size of buffer: ");
    scanf(" %d",&n);

    printf("If there are any Procedure? (yes-1 or no-0): ");
    scanf("%d",&pro);
    
    repeat:
    
    if(pro==1) {
        printf("How many procedure: ");
        scanf("%d",&m);
        
        if(m>=n) {
            printf("Producer has to wait.");
        } else {
            printf("Enter %d items: \n",n-m);
            p = n-m;
            for(i=1;i<=p;i++)  
            scanf("%d", &produce[i]);
            
            printf("\nAllocation complete!\n");
            
            for(i=1;i<=p;i++){
            printf("%d Buffer Filled by %d\n",m+i,produce[i]);
            }
            
        }
    }
    else {
        printf("\nNo producer.\n");
    }
    
    
    printf("Do you want to repeat (1/0): ");
    scanf("%d",&c);
	if(c==1) {
		goto repeat;
	}
	else {
		exit(0);
	}
    return 0;
}
