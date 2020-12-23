#include <stdio.h>
#include <stdlib.h>
#define N 10
float *descente(float A[N][N], float B[N], int n)
{
  float   *X;
  int i=0;
  int j=0;
  float s;  
  /* Here we allocate the result verctor \
  (you're gonna do it yourself in the next exercises)*/
  X = malloc(sizeof(float) * n);
   

  /******Implement the solution here******/
  /***************************************/
	for (i=0 ; i<n ; i++)
	{
		X[i] = 0;
	}		
	X[0] = B[0]/A[0][0]; 
	for (i = 1 ; i<n ; i++)
	{
		s = 0 ;
		for (j = 0; j<i ; j++ )
		{
	///		printf ("\n \t %d %d" , i,j);
			s = s + A[i][j] * X[j];
		}
        //printf(" \n %f",s);
	X[i] = (B[i] - s)/A[i][i]; 
	} 

  return (X);
}


int main()
{
  float   A[N][N], B[N];
  float   *x;
  int     n;
 /* A[0][0] = 4;
  A[0][1] = 0;
  A[0][2] = 0;
  A[1][0] = 2;
  A[1][1] = 3;
  A[1][2] = 0;
  A[2][0] = 8;
  A[2][1] = 6;
  A[2][2] = 1;
  B[0] = 1;
  B[1] = 2;
  B[2] = -3;*/

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
  x = descente(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
	  printf("%f%c", x[i], ",]"[i == n - 1]);
}
