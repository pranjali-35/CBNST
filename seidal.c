#include <stdio.h>

float f1(float y, float z){
    return ((44-y-2*z)/10);
}

float f2(float x, float z){
    return ((51-2*x-z)/10);
}

float f3(float x, float y){
    return ((61-x-2*y)/10);
}

void cal(float x, float y, float z, float allowed_err, int it){
    float x1 = f1(y,z);
    float y1 = f2(x1,z);
    float z1 = f3(x1,y1);

    float e1 = x1-x, e2 = y1 - y, e3 = z1 - z;
    if(e1 <= allowed_err && e2 <= allowed_err && e3 <= allowed_err){
        printf("\nx = %f, y = %f, z = %f\n",x1,y1,z1);
        return;
    }printf("Iteration%d : x = %f, y = %f, z = %f\n",it,x1,y1,z1);
    it++;
    cal(x1,y1,z1,allowed_err, it);
}

int main(){
    float x = 0, y = 0, z = 0, allowed_err;
    printf("Enter the allowed error : ");
    scanf("%f",&allowed_err);
    cal(x,y,z,allowed_err,1);

    return 0;
}
