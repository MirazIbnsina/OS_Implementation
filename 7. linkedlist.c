#include<stdio.h>
int main() {
	
	printf("How many blocks: ");
	int b;
	scanf("%d",&b);
	int f[50],p,i,j,k,a,s,l,n,c;
	for(i=0;i<b;i++)
	f[i]=0;
	
	printf("Total allocated blocks:");
	scanf("%d",&p);
	printf("\nEnter allocated blocks---\n");
	for(i=0;i<p;i++) {
		printf("For Block-%d: ", i+1);
		scanf("%d",&a);
		f[a]=1;
	}

	
	repeat:
    printf("\nEnter starting block: ");
    scanf("%d",&s);
    printf("Enter the size: ");
    scanf("%d",&l);
	
	k=l;
	for(j=s;j<(k+s);j++) {
		if(f[j]==0) {
			if(j<b) {
				f[j]=1;
				printf("\n%d->%d",j,f[j]);
			} else {
			 	printf("\nNo more space in memory");
			 }
		}
		else {
			printf("\n%d-> already allocated",j);
			k++;
		}
	}

	printf("\nDo you want to enter more file?(1/0)");
	scanf("%d",&c);
	if(c==1)
	goto repeat;
	else
	exit(0);
	return 0;
}
