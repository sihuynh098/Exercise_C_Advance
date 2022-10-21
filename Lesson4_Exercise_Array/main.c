#include "stdio.h"
#include "stdlib.h"

void Nhap(int mang[], int sl){
    for(int i=0;i<sl;i++){
        printf("Mang[%d] = ",i);
        scanf("%d", &mang[i]);
    }
}

void Array_Lon_Be(int mang[], int sl){
    int tamthoi;
    for(int i=0;i<sl-1;i++){
        for(int j=i+1;j<sl;j++){// 132 
            if(mang[i] < mang[j]){
                tamthoi = mang[i];
                mang[i] = mang[j];
                mang[j] = tamthoi;
            }
        }
    }
    printf("Mang duoc sap xep tu lon den be la: \n");
    for(int i=0;i<sl;i++){
        printf("Mang[%d] = %d\n", i, mang[i]);
    }
}

void Array_Be_Lon(int mang[], int sl){
    int tamthoi;
    for(int i=0;i<sl-1;i++){
        for(int j=i+1;j<sl;j++){// 132 
            if(mang[i] > mang[j]){
                tamthoi = mang[i];
                mang[i] = mang[j];
                mang[j] = tamthoi;
            }
        }
    }
    printf("Mang duoc sap xep tu be den lon la: \n");
    for(int i=0;i<sl;i++){
        printf("Mang[%d] = %d\n", i, mang[i]);
    }
}

void Array_Max(int mang[], int sl){
    int max=mang[0];
    for(int i=0;i<sl;i++){ 
        if(max < mang[i]){
            max = mang[i];
        }
    }
    printf("Phan tu lon nhat trong mang la: %d\n", max);
}

int main(){
    int sl, *ptr, luachon;
    printf("Nhap vao so luong phan tu cua mang: ");
    scanf("%d", &sl);
    ptr = (int *)calloc(sl, sizeof(int));
    Nhap(ptr, sl);
    while(1){
    printf("Nhap vao lua chon cua ban: ");
    scanf("%d", &luachon);
    if(luachon == 1)
        Array_Lon_Be(ptr, sl);
    else if(luachon == 2)
        Array_Be_Lon(ptr, sl);
    else if(luachon == 3)
        Array_Max(ptr, sl);
    else if(luachon == 4)
        break;
    }
    free(ptr);
    return 0;
}