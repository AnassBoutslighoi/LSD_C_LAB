#include <stdlib.h>
#include <stdio.h>
#define N 3

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
		printf("\n %f",X[i]);
	}

	/***************************************/
	return X;
}
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

float *gauss(float A[N][N] ,float B[N], int n)
{
	/******Implement the Gaussian elimination******/
	/**********************************************/
	int i,j,k;
	float s;
	/*float **U;
	  U = malloc(sizeof(float	*)*n);	
	  for (i=0 ; i<n ; i++)
	  {
	  U[i] = malloc(sizeof(float*)*n);
	  }*/	
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
	/*
	   for(i=0;i<n;i++)
	   {
	   for (j=0;j<n;j++)
	   {
	   U[i][j] = A[i][j];
	   }
	   }*/
	/**********************************************/
	/*Resolve the system using the back substitution method*/
	/*You can use your solution of the exercice 1-b*/
	x = remontee(A, B, n);
	return x;
}
float *decomp_l(float A[N][N],float B[N], int n)
{
	//	float *I;
	int i,j,x;
	float s;
	float I[N][N] = {1,0,0,0,1,0,0,0,1};
	float *y;
	for (i=0;i<n;i++)
/*	{
		for (j=0;j<n;j++)
		{
			if(i=j)
			{
				I[i][j] = 1;
			}
			else
				I[i][j] = 0;
		}		
	}*/	
	for (int k = 0 ; k<N+1 ; k++)
	{
		for(i = k+1 ; i<N ; i++)
		{
			s  = A[i][k] /A[k][k];
			for (j = 0 ; j <N ; j++)
			{
				A[i][j] = A[i][j] - s * A[k][j];
				for (int x =i ; x<N && k<N-1 ; x++)
				{
					I[x][k] = s;
				}						
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			printf("\n %f A[%d][%d]",I[i][j],i,j);
		}
	}
	y = descente(I,B,n);
	return(y);
}

float *lu(float A[N][N], float B[N], int n)
{

	/******Implement the solution here******/
	/***************************************/
	float *y;
	float *x;
	y = decomp_l(A,B,n);
	x = gauss(A,y,n);
	/*for (i=0; i<N ; i++)
	{	*/
		
  /***************************************/
  return (x);
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
  x = lu(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", x[i], ",]"[i == n - 1]);
}

