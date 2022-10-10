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
            if(i != j){
                float res = a[j][i]/a[i][i];
                for(int k = 0 ; k <= n ; k++){
                    a[j][k] = a[j][k] - (res*a[i][k]);
                }
            }
        }
    }
    //Print diagonal matrix
    printf("Diagonal matrix : \n");
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j <= n ; j++){
            printf("%.2f      ",a[i][j]);
        }printf("\n");
    }

    float ans[n];
    for(int i = 0 ; i < n ; i++){
        ans[i] = a[i][n]/a[i][i];
    }
    
    printf("The value of unknowns : ");
    for(int i = 0 ; i < n ; i++){
        printf("x%d = %f\n",i,ans[i]);
    }

    return 0;    
}
