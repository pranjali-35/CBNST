#include <stdio.h>
#include <math.h>

int main(){
    int n;
    printf("Enter the number of terms : ");
    scanf("%d",&n);

    float x[n],y[n],x2[n],xy[n],y2[n], sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0, sumy2 = 0;
    printf("Enter the value of x and corresponding y : \n");
    for(int i = 0 ; i < n ; i++){
        scanf("%f%f",&x[i],&y[i]);
        x2[i] = pow(x[i],2);
        y2[i] = pow(y[i],2);
        xy[i] = x[i]*y[i];
        sumx += x[i];
        sumy += y[i];
        sumxy += xy[i];
        sumx2 += x2[i];
        sumy2 += y2[i];
    }

    float xa = sumx/n;
    float ya = sumy/n;

    int choice;
    printf("1.y on x\n2.x on y\nEnter choice : ");
    scanf("%d",&choice);

    float byx,bxy;
    switch(choice){
        case 1:
            //byx = (n.sumxy - sumx.sumy)/(n.sumx2 - (sumx)2)
            byx = ((n*sumxy) - (sumx*sumy))/((n*sumx2) - (pow(sumx,2)));
            printf("Regression coefficient is %f\n",byx);
            printf("Equation of line : y - %f = %f(x - %f)\n",ya,byx,xa);
            break;
        case 2 :
            bxy = ((n*sumxy) - (sumx*sumy))/((n*sumy2) - (pow(sumy,2)));
            printf("Regression coefficient is %f\n",byx);
            printf("Equation of line : y - %f = %f(x - %f)\n",ya,bxy,xa);
            break;
        default :
            printf("Enter valid choice\n");
            return 0; 
    }   
}
