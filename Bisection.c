#include <stdio.h>
#include <math.h>
#include <conio.h>

float check(float x){
	float ans = (x*x*x)-(5*x)+1;
	return ans;
}

int main(){
	printf("\nPranjali Kothari\n20012810\n");
	float a,b;
	printf("Enter the value of a and b : ");
	scanf(" %f %f",&a,&b);

	printf("Equation is : (x^3 - 5x + 1)\n");
	
	if(check(a)*check(b) < 0){
		printf("Range is correct\n");
		float allowed_err;
		printf("Enter the allowed error : ");
		scanf("%f",&allowed_err);
		
		float x = (a+b)/2;
		while(fabs(check(x)) > allowed_err){
			if(check(a)*check(x) < 0)
				b = x;
			else if(check(x)*check(b) < 0)
				a = x;
			x = (a+b)/2;
			//printf("a = %f b = %f ",a,b);
			printf("x = %f  f(x) = %f\n",fabs(x),check(x));
		}//printf("x = %f  f(x) = %f\n",fabs(x),check(x));
	}else
		printf("Range is incorrect\n");
	
	return 0;
}
