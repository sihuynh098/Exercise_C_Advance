#include "stdio.h"
#include "stdlib.h"

typedef struct Array{
    int *ptr;
    int size;
}Array;

void Array_Input(Array *value){
    printf("Nhap vao so luong cua mang: ");
    scanf("%d", &value->size);

    value->ptr = (int *)calloc(value->size, sizeof(int));

    for(int i=0;i<value->size;i++){
        printf("Mang[%d] = ", i);
        scanf("%d", &value->ptr[i]);
    }
}

void Check_Even_Odd(Array value){
    Array Even;
    Array Odd;
    int count_Even=0, count_Odd=0;
    Even.ptr = (int *)calloc(count_Even, sizeof(int));
    Odd.ptr = (int *)calloc(count_Odd, sizeof(int));
    for(int i=0;i<value.size;i++){
        if(value.ptr[i] % 2 == 0){
            Even.ptr[count_Even] = value.ptr[i];
            count_Even++;
        }else{
            Odd.ptr[count_Odd] = value.ptr[i];
            count_Odd++;
        }
    }
    printf("Mang cac phan tu chan la: \n");
    for(int i=0;i<count_Even;i++){
        printf("Even[%d] = %d\n", i, Even.ptr[i]);
    }
    printf("Mang cac phan tu le la: \n");
    for(int i=0;i<count_Odd;i++){
        printf("Even[%d] = %d\n", i, Odd.ptr[i]);
    }
    free(Even.ptr);
    free(Odd.ptr);
}

int main(){
    Array value;
    Array_Input(&value);
    Check_Even_Odd(value);
    free(value.ptr);
    return 0;
}