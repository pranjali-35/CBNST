//Regula Falsi Method Implementation
#include <stdio.h>
#include <math.h>

float check(float x){
	float ans = 3*x + sin(x) - exp(x);
    return ans;
}

int main(){
	printf("\n\nName:Pranjali Kothari\n20012810\n\n");
	printf("Equation is 3x + sin x - e^x\n");
	float a,b;
	printf("Enter the value of a and b : ");
	scanf("%f%f",&a,&b);
	
	if(check(a)*check(b) < 0){
		printf("Range is correct\n");
		float allowed_err;
		printf("Enter the allowed error : ");
		scanf("%f",&allowed_err);

		float x = (a - (((b-a)/(check(b)-check(a))) * (check(a))));
		while(fabs(check(x)) > allowed_err){
			if(check(a)*check(x) < 0)
				b = x;
			else if(check(x)*check(b) < 0)
				a = x;
			x = (a - (((b-a)/(check(b)-check(a))) * (check(a))));
			printf("x = %f  f(x) = %f\n",fabs(x),check(x));
		}printf("Root is = %f\n",fabs(x));
	}else
		printf("Range is incorrect\n");
		
	return 0;
}
