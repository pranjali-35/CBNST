#include <stdio.h>
#include <math.h>

int main(){
    int n, m = 2;
    printf("Enter the number of terms : ");
    scanf("%d",&n);

    float x[n],y[n],x2[n],xy[n], sumx = 0, sumy = 0, sumx2 = 0, sumxy = 0;
    printf("Enter the value of x and corresponding y : \n");
    for(int i = 0 ; i < n ; i++){
        scanf("%f%f",&x[i],&y[i]);
        x2[i] = pow(x[i],2);
        xy[i] = x[i]*y[i];
        sumx += x[i];
        sumy += y[i];
        sumxy += xy[i];
        sumx2 += x2[i];
    }

    //sumy = n.a + b.sumx
    //sumxy = a.sumx + b.sumx2
    float a[m][m+1];
    a[0][0] = n, a[0][1] = sumx, a[0][2] = sumy;
    a[1][0] = sumx, a[1][1] = sumx2, a[1][2] = sumxy;
    
    //gauss jordan
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < m ; j++){
            if(i != j){
                int res = a[j][i]/a[i][i];
                for(int k = 0 ; k <= m ; k++){
                    a[j][k] -= (res*a[i][k]);
                }
            }
        }
    }float ans[m];
    for(int i = 0 ; i < m ; i++){
        ans[i] = a[i][m]/a[i][i];
    }

    printf("a = %0.2f, b = %0.2f\n",ans[0],ans[1]);
    printf("Equation of line is y = %0.2f + %0.2fx\n",ans[0],ans[1]);

}
