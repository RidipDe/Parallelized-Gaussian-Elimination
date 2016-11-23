#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define size 4

void lwMat();
void upMat();
void print();


int main(int argc, char *argv[])
{
	//srand (static_cast <unsigned> (time(0)));
	int v = atoi(argv[1]);
	int no =v;
	float mat[size][size] = {{8, 3, 4, 5}, {14, 4, 33, 23}, {15, 4, 23, 7}, {4, 11, 17, 1}};
	float b[size] = {31, 17, 22, 51};
	
	for(int n=0; n<no; n++)
	{
		for(int m=0; m<no; m++)
		{	
			mat[n][m] = 0;
			b[n] = 0;
			float r = rand()+1;
			mat[n][m] = r;
			r = rand()+1;
			b[n] = r;
		}
	}
    lwMat();
    print();
      
}

void upMat()
{
    int r,c,k = size-1;
        //printf("%d",mat[1][0]);
	
        for( r=0; r<size-1; r++)
        {
            for(c=k; c>0; c--)
            {
                //if(k< size-1){
                    //printf("%d Multiply by %d, subtract %d * row N2 %d = ", mat[r][c], mat[k][k], piv, mat[k][c]);

                        float res = (mat[r][c] * mat[size-1][c]);

                        mat[r][k] -= res;
                //}


            }
        }
}


void lwMat()
{
    int r,c,k = 0;
    
    while(k<size)
    {
        for( r=k+1; r<size; r++)
        {
            float piv = mat[r][k];
            float dig = mat[r-1][r-1];
                for(c=0; c<size; c++)
            {
                if(k< size-1){
                   //printf("%d Multiply by %d, subtract %d * row N2 %d = ", mat[r][c], mat[k][k], piv, mat[k][c]);

                        mat[r][c] = (mat[r][c] * mat[k][k]) - (piv * mat[k][c]);

                        //printf("The val is %d\n", dig);
                        //mat[r-1][c] /= dig;
                }


            }
            //printf("%d Multiply by %d, subtract %d * row N1 %d \n ", b[r], mat[k][k], piv, b[k]);
                if(k< size-1){
                float res = (b[r] * mat[k][k]) - (piv * b[k]);
                //printf("%f", res);
                b[r] = res;
                }


                //printf("%d\n", res);
            //printf("\n");
        }
        k++;
    }
    b[k-1] /= mat[k-1][k-1];

    for(int r=0; r<size; r++)
        {
            float piv =  mat[r][r];
			for(int c=0; c<size; c++)
			{
				mat[r][c] /= piv;
				b[r] /= piv;
			}
			printf("\n");
        }
        
}

void print()
{

    for(int r=0; r<size; r++)
        {
                for(int c=0; c<size; c++)
                {

                        printf("%f\t",mat[r][c]);
                }
                printf("\n");
        }

        for(int r=0; r<size; r++)
        {

                printf("%f\t", b[r]);
                printf("\n");
        }

}
