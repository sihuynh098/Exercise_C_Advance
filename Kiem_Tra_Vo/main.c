#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef enum{
    VO_DO=1,
    VO_VANG,
    VO_XANH
}VO;

typedef struct typebox{
    VO *ptr;
    int size;
}typebox;

void NhapVo(typebox *value){
    char name[7];
    printf("Nhap vao so luong VO: ");
    scanf("%d", &(value->size));

    value->ptr = (VO*)calloc((value->size), sizeof(VO));

    
    for(int i=0;i<value->size;i++){
        lable:
        printf("Nhap VO so %d: ",i);
        scanf("%s", name);
        if((strcmp((char*)"VO_DO", name)) == 0){
            value->ptr[i] = VO_DO;
        }else if((strcmp((char*)"VO_VANG", name)) == 0){
            value->ptr[i] = VO_VANG;
        }else if((strcmp((char*)"VO_XANH", name)) == 0){
            value->ptr[i] = VO_XANH;
        }else{
            printf("Ban da nhap sai dinh dang!\n");
            goto lable;
        }
    }
    for(int i=0;i<value->size;i++){
        printf("%d", value->ptr[i]);
    }
}

void Dem_Vo(typebox value){
    int demdo=0,demvang=0,demxanh=0, sum=0;
    for(int i=0;i<value.size;i++){
        if(value.ptr[i] == 1){
            demdo++;
        }else if(value.ptr[i] == 2){
            demvang++;
        }else{
            demxanh++;
        }
    }
    sum = (demdo/2)+(demvang/2)+(demxanh/2);
    printf("\nCo tong cong %d doi VO va trong do co:\n %d doi vo do \n %d doi vo vang\n %d doi vo xanh", sum, demdo/2, demvang/2, demxanh/2);
}

int main(){
    typebox value;
    NhapVo(&value);
    Dem_Vo(value);
    free(&value);
    return 0;
}