#include<stdio.h>
int main() {
	
	int n,m,c,i,j,k;
	printf("How many blocks: ");
	scanf("%d",&m);
	printf("Number of files: ");
	scanf("%d",&n);
	int s[m], l[m], temp[m];
	
	for(i=0;i<=m;i++)
		temp[i]=224;
	
	printf("\nEnter the file infos ---\n");
    for(i=0;i<n;i++) {
        printf("For File [%d]\n", i+1);
        printf("Enter starting block: ");
        scanf("%d",&s[i]);
        printf("Enter the size: ");
        scanf("%d",&l[i]);
    }
	    
   printf("\n\nFile Allocated as ---\n");
   printf("File Name\tStart Block\t Length"); 
   
    for(i=0;i<n;i++) {
    	for(k=s[i],j=0;j<l[i];j++,k++) {
			if(temp[k]==224)
				c=0;
			else {
				c=1;
				break;
			}
		}
		
		if(c==1)
			printf("\nCannot be allocated (already blocked by file-%d)",(temp[k]+1));
		if(c==0) {
			for(k=s[i],j=0;j<l[i];j++,k++)
				temp[k]=i;
			printf("\nFile-%d\t\t%d\t\t\t %d",(i+1),s[i],(s[i]+l[i]-1));
		}
	}
	return 0;
}
