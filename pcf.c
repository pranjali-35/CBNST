#include <stdio.h>
#include <math.h>

int main(){
    int n, m = 3;
    printf("Enter the number of terms : ");
    scanf("%d",&n);

    float x[n],y[n],x2[n],xy[n],x3[n],x4[n],x2y[n], sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0, sumx3 = 0, sumx4 = 0, sumx2y = 0;
    printf("Enter the value of x and corresponding y : \n");
    for(int i = 0 ; i < n ; i++){
        scanf("%f%f",&x[i],&y[i]);
        x2[i] = pow(x[i],2);
        xy[i] = x[i]*y[i];
        x2y[i] = x2[i]*y[i];
        sumx += x[i];
        sumy += y[i];
        sumxy += xy[i];
        sumx2 += x2[i];
        sumx3 += pow(x[i],3);
        sumx4 += pow(x[i],4);
        sumx2y += x2y[i];
    }

    float a[m][m+1];
    //sumy = n.a + b.sumx + c.sumx2
    //sumxy = a.sumx + b.sumx2 + c.sumx3
    //sumx2y = a.sumx2 + b.sumx3 + c.sumx4

    a[0][0] = n, a[0][1] = sumx, a[0][2] = sumx2, a[0][3] = sumy;
    a[1][0] = sumx, a[1][1] = sumx2, a[1][2] = sumx3, a[1][3] = sumxy;
    a[2][0] = sumx2, a[2][1] = sumx3, a[2][2] = sumx4, a[2][3] = sumx2y;

    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < m ; j++){
            if(i != j){
                float res = a[j][i]/a[i][i];
                for(int k = 0 ; k <= m ; k++){
                    a[j][k] -= (res*a[i][k]);
                }
            }
        }
    }

    float ans[m];
    for(int i = 0 ; i < m ; i++){
        ans[i] = a[i][m]/a[i][i];
    }

    printf("a = %0.2f  b = %0.2f  c = %0.2f\n",ans[0],ans[1],ans[2]);
    printf("Equation of line : y = %0.2f + %0.2fx + %0.2fx^2\n",ans[0],ans[1],ans[2]);

    return 0;
}
