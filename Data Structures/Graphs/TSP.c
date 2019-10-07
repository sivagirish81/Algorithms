#include <stdio.h>
#include <stdlib.h>

int get_next_permutation(int *permutation, int n);
void print_permutation(int *permutation, int n);
int tsp(int** graph, int n);

int main() {
	int n;//permutation of n symbols
	int i,ans; //loop index
	int** matrix; //cost matrix 
	

	scanf("%d", &n); //n > 1
	
	//matrix input
	matrix = (int**)malloc(sizeof(int*)*n);
	for(int i=0;i<n;i++)
	{
		matrix[i] = (int*)malloc(sizeof(int)*n);
		for(int j=0;j<n;j++)
		{
			scanf("%d",&matrix[i][j]);
		}

	}
	ans=tsp(matrix,n);
	printf("%d\n",ans);	

	return 0;
}


int tsp(int** graph, int n)
{
	int mincost=9999999;
	int cost;
	int *per; // permutation array
	per = (int *) malloc(n * sizeof(int));
	
	//first permutation
	for(int i=0; i < n; i++) 
	{
		per[i] = i+1;
	}	

	//do while there is a next permutation in lexicographic order
	do
	{
		cost = graph[0][per[0]];
		cost = cost +graph[per[n-2]][0];
		for(int i=0;i<=n-3;i++)
		{
			cost = cost + graph[per[i]][per[i+1]];
		}
		if(cost<mincost)
			mincost=cost;
		
	} while (get_next_permutation(per, n-1));
	return mincost;
}

// Get the next permutation in lexicographic order
int get_next_permutation(int *permutation, int n) {
	int i;
	int j;
	int k;
	int temp_int;
	int swaps;

	//find i
	for(i = n-2; i >= 0; i--) {
		if(permutation[i] < permutation[i+1]) {
			break;
		}
	}
	if(i == -1) {
		return 0;
	}

	for(j = i+1; j < n; j++) {
		if(permutation[j] < permutation[i]) {
			break;
		}
	}
	j--;

	temp_int = permutation[i];
	permutation[i] = permutation[j];
	permutation[j] = temp_int;

	//printf("DEBUG*i=%d,j=%d*", i, j); print_permutation(permutation, n);
	swaps = (n-1-i)/2;	
	for(k = 0; k < swaps; k++) {
		temp_int = permutation[i+1+k];
		permutation[i+1+k] = permutation[n-1-k];
		permutation[n-1-k] = temp_int;
	}
	return 1;
}

void print_permutation(int *permutation, int n) {
	int i;
	printf("[");
	for(i = 0; i < n-1; i++) {
		printf("%d, ", permutation[i]);
	}
	printf("%d]\n", permutation[n-1]);
}
