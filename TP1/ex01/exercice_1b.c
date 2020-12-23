#include <stdio.h>
#include <stdlib.h>
#define N 4

float *remontee(float A[N][N], float B[N], int n)
{

	/* A hint: you cant return an array which is allocated in the stack memory. \
	 ** you may consider to create a dynamically allocated array and return a pointer to it. \
	 ** https://gribblelab.org/CBootCamp/7_Memory_Stack_vs_Heap.html
	 */
	int i = 0 ;
	float s ;
	int j = 0 ;
	float   *X;
	X = malloc(sizeof(float)*n);

	X[n-1] = B[n-1]/A[n-1][n-1];

	/******Implement the solution here******/
	/***************************************/
	for(i= n-2 ; i>-1 ; i--)
	{
		s = 0 ;
		for (j=i+1 ; j<n;j++)
		{
			s = s + A[i][j]*X[j];  
		}
		X[i] = (B[i] - s)/A[i][i];
	}





	/***************************************/
	return X;
}

int main()
{
	float   *x;
	int n;
	float A[N][N] , B[N];
 	printf("Enter the size of the matrix: ");
 	scanf("%d", &n);
  	//float A[4][4]={{3,1,-1,4},{0,2,1,-5},{0,0,2,-7},{0,0,0,3}};
	//float B[4]={8,-7,0,6};


  /* Filling the matrix A */
  printf("Filling the matrix A\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%f", &A[i][j]);
    }
  }

  /* Filling the vector B*/

  printf("Filling the vector B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }
  /* The calculation of the result */
  x = remontee(A, B,n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", x[i], ",]"[i == n - 1]);
}

