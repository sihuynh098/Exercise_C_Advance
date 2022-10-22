#include "stdio.h"
#include "stdlib.h"

struct Array{
    int *ptr;
    int size;
};
typedef struct Array Array;


void Nhapthongtin(Array *value){
    printf("Nhap vao so phan tu cua mang: ");
    scanf("%d", &(value->size));

    value->ptr = (int*)calloc(value->size, sizeof(int));
    for(int i=0;i < value->size;i++){
        printf("Mang[%d] = ",i);
        scanf("%d", &value->ptr[i]);
    }
}

void Array_Lon_Be(Array *value){
    int thaythe;
    for(int i=0;i<(value->size) - 1;i++){
        for(int j=i+1;j<(value->size);j++){//132 
            if(value->ptr[i] < value->ptr[j]){
                thaythe = value->ptr[i];
                value->ptr[i] = value->ptr[j];
                value->ptr[j] = thaythe;
            }
        }
    }
    printf("Mang tu lon den be la: \n");
    for(int i=0;i<value->size;i++){
        printf("Mang[%d] = %d\n", i, value->ptr[i]);
    }
}

void Array_Be_Lon(Array *value){
    int thaythe;
    for(int i=0;i<(value->size) - 1;i++){
        for(int j=i+1;j<(value->size);j++){//132 
            if(value->ptr[i] > value->ptr[j]){
                thaythe = value->ptr[i];
                value->ptr[i] = value->ptr[j];
                value->ptr[j] = thaythe;
            }
        }
    }
    printf("Mang tu be den lon la: \n");
    for(int i=0;i<value->size;i++){
        printf("Mang[%d] = %d\n", i, value->ptr[i]);
    }
}

void Array_Max(Array value){
    int max = value.ptr[0];
    for(int i=0;i<value.size;i++){
        if(max < value.ptr[i]){
            max = value.ptr[i];
        }
    }
    printf("Phan tu lon nhat trong mang la: %d\n", max);
}

int main(){
    Array value;
    Nhapthongtin(&value);

    int luachon;
    while(1){
    printf("Nhap lua chon cua ban: ");
    scanf("%d", &luachon);
        if(luachon == 1){
            Array_Lon_Be(&value);
        }else if(luachon == 2){
            Array_Be_Lon(&value);
        }else if(luachon == 3){
            Array_Max(value);
        }else if (luachon == 4)
        {
            break;
        }else{
            printf("Vui long nhap lua chon cua ban tu 1->4!\n");
        }        
    }

    free(value.ptr);
    return 0;
}