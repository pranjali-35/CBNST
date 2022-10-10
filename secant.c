//Secant Method Implementation
#include<stdio.h>
#include<math.h>

float value(float x)
{
   return x*x*exp(-x/2) - 1;
}

float findX(float x1,float x2)
{
      return (x2 - ((x2-x1)/(value(x2)-value(x1)))*value(x2));
}

int main()
{
    printf("\nName : Pranjali Kothari\n20012810\n\n");
    printf("Equation = x^2*e^(-x/2) - 1\n");
    int i=1;
    float x1,x2,x,error;
    printf("\nEnter x1 and x2 : ");
    scanf("%f%f",&x1,&x2);
    printf("Enter the Error : ");
    scanf("%f",&error);
    
    x = findX(x1,x2);   
    
    while(1)
    {
      x1=x2;
      x2=x;
      printf("Iterations=%d  Root=%f\n",i,x);   
      x = findX(x1,x2);  
      if(fabs(x-x2) < error)
        break;
      i++; 
    }

    printf("\nRoot=%f \nTotal Iterations=%d\n\n",x,i+1);
    return 0;
}
