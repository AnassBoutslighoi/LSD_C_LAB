#include <stdio.h>
#include <stdlib.h>
#define N 10

float *remontee(float A[N][N], float B[N], int n)
{		
	/******Implement the solution here******/
	/***************************************/
	float *X;
	int i,j;
	float s;
	X = malloc(sizeof(float)*n);	

	X[n-1] = B[n-1]/A[n-1][n-1];
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

float *gauss(float A[N][N] ,float B[N], int n)
{
	/******Implement the Gaussian elimination******/
	/**********************************************/
	int i,j,k;
	float s;
	float *x;
	for (k = 0 ; i<n+1 ; k++)
	{
		for(i = k+1 ; i<n ; i++)
		{
			s  = A[i][k] /A[k][k];
			//printf(" \n %f",s); 
			for (j = 0 ; j <n ; j++)
			{ 
				A[i][j] = A[i][j] - s * A[k][j] ;
			//	printf(" \n %f A[%d][%d] ",A[i][j],i,j); 
			}
			B[i] = B[i] - s * B[k];
		}
	}
  /**********************************************/
  /*Resolve the system using the back substitution method*/
  /*You can use your solution of the exercice 1-b*/
  x = remontee(A, B, n);
  return(x);
}

int main()
{
  float   A[N][N], B[N];
  float   *x;
  int     n;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

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
  printf("Filling the matrix B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }

  /* The calculation of the result */
  x = gauss(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", x[i], ",]"[i == n - 1]);
}
