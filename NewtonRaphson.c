//Newton Raphson Method Implementation
#include <stdio.h>
#include <math.h>

float f(float x){
    return (x*x -12);
    //return (3*x - cos(x) - 1);
}

float df(float x){
    return 2*x;
    //return (3 + sin(x));
}

int main(){
    float x, x0, allowed_err;
    printf("Enter the initial value of x : ");
    scanf("%f",&x0);

    if(df(x0) == 0){
        printf("Failed!!!\n");
        return 0;
    }

    printf("Enter the allowed error : ");
    scanf("%f",&allowed_err);

    int it = 1;
    while(1){
        if(df(x0) == 0){
            printf("Method failed!!!\n");
            return 0;
        }x = x0 - (f(x0)/df(x0));
        if(fabs(x-x0) < allowed_err){
            printf("Iteration %d : x = %f\n",it,x);
            printf("Root is %f\n",x);
            break;
        }else{
            printf("Iteration %d : x = %f\n",it,x);
            x0 = x;
            it++;            
        }
    }return 0;
}



/*  ---------------------------------------------------------------------------------------------------------------------------------------------------------------
float f(float x)
{
    return 3 * x - cos(x) - 1;
}

float diff(float x)
{
    return 3 + sin(x);
}

int main()
{
    printf("\nName : Pranjali Kothari\n20012810\n\n");
    int i = 1;
    float x1, x2, x, x0, error;

    printf("\nEquation = 3x - cosx - 1");
    printf("\nEnter the Error : ");
    scanf("%f", &error);

    do
    {
        printf("\nEnter the value of x1 and x2 : ");
        scanf("%f%f", &x1, &x2);
        if (f(x1) * f(x2) > 0)
        {
            printf("These values are Invalid\n");
            continue;
        }
        else
        {
            printf("\nRoots Lie between %f and %f\n", x1, x2);
            break;
        }
    } while (1);

    if (fabs(f(x1)) < fabs(f(x2)))
        x0 = x1;
    else
        x0 = x2;

    do
    {
        x = x0 - (f(x0) / diff(x0));

        if (fabs(x - x0) < error)
        {
            printf("Iterations = %d  Roots = %f\n", i, x);
            printf("\nRoot = %f \nTotal Iterations = %d\n", x, i);
            return 0;
        }
        printf("Iterations = %d  Roots = %f\n", i, x);
        x0 = x;
        i++;

    }while(1);
}*/
