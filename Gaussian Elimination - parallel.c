// gcc ge.c -std=c99 -pthread -o manual



//time ./manual




















#include <stdio.h>
#include <pthread.h>

struct thread_data {
  int thread_id;
};


#define size 4

float mat[size][size] = {{8, 3, 4, 5}, {14, 4, 33, 23}, {15, 4, 23, 7}, {4, 11, 17, 1}};
float b[size] = {31, 17, 22, 51};
void *lwMat(void *);
void upMat();
void print();

int main(int args, char **arg)
{
    pthread_attr_t pthread_attr;
    pthread_attr_init( &pthread_attr);
    struct thread_data thread_data_arr[size];
    pthread_t tid[size];
    for (int i = 0; i < size; i++)
    {
        thread_data_arr[i].thread_id = i;
        tid[i] = i;
        int ret_val = pthread_create( & tid[i], &pthread_attr, lwMat, &thread_data_arr[i]);
        if (ret_val != 0)
                printf("Error in pthread_creation");
    }
        //lwMat();
        //upMat();

        for (int k = 0; k < size; k++)
        {
            int ret_val = pthread_join(tid[k], NULL);
            if (ret_val != 0)
                printf("Error in pthread_joinn");
        }
        print();
        pthread_exit(NULL);
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


void *lwMat(void *threadarg)
{
    int r,c,k = 0;
    struct thread_data *loc_data = (struct thread_data * ) threadarg;
        //printf("%d",mat[1][0]);

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
        pthread_exit(0);
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
