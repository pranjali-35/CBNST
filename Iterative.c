//Iterative Method Implementation
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

float f(float x){
    return (cos(x) - (3*x) + 1);
	//return (2*x - log10f(x) - 7);
}

float g(float x){               //value of x
    return ((cos(x) + 1)/3);
	//return ((log10f(x) + 7)/2.0); 
}

float df(float x){              //differentiation of x
	return ((sin(x)/3)*(-1));
    //return(fabs(1/(2*x*log(10))));  
}

int main(){
	float x;
	printf("Enter the value of x0 : ");
	scanf("%f",&x);

    if(fabs(df(x)) < 1){
        printf("Function is correct!!\n");
        float allowed_err;
        printf("Enter the allowed error : ");
        scanf("%f",&allowed_err);

        int flag = 0,it = 1;
        float x1;
        do{
            x1 = g(x);
            printf("Iteration %d : x = %f\n",it,x1);

            if(fabs(x1-x) <= allowed_err){
                flag = 1;
                printf("Root of the equation is %f after %d iterations\n",x1,it);
            }
            else{
                x = x1;
            }it++;
            
        }while(flag != 1);

    }
    
    else{
        printf("Change the function\n");
        exit(0);
    }

	return 0;
}
