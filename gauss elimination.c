#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of unknowns : ");
    scanf("%d",&n);

    float a[n][n+1];
    printf("Enter the augmented matrix : \n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j <= n ; j++)
            scanf("%f",&a[i][j]);
    }
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < n ; j++){
            if(i < j){
                float res = a[j][i]/a[i][i];
                for(int k = 0 ; k <= n ; k++){
                    a[j][k] = a[j][k] - (res*a[i][k]);
                }
            }
        }
    }
    //Print upper triangular matrix
    printf("The Upper Triangular matrix : \n");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= n ; j++){
            printf("%.2f      ",a[i][j]);
        }printf("\n");
    }

    //Backward substitution
    float ans[n];
    ans[n-1] = a[n-1][n]/a[n-1][n-1];

    for(int i = n-2 ; i >= 0 ; i--){
        float s = 0;
        for(int j = i+1 ; j < n ; j++){
            s += a[i][j] * ans[j];
        }ans[i] = (a[i][n]-s)/a[i][i];
    }
    
    printf("The value of unknowns : ");
    for(int i = 0 ; i < n ; i++){
        printf("x%d = %f\n",i,ans[i]);
    }

    return 0;    
}
