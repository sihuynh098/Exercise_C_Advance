#include "stdio.h"
#include "stdlib.h"

typedef enum Thang{
    Thang1=1,
    Thang2,
    Thang3,
    Thang4,
    Thang5,
    Thang6,
    Thang7,
    Thang8,
    Thang9,
    Thang10,
    Thang11,
    Thang12
}Thang;

void HienThang(Thang thang){
    switch(thang){
        case Thang1:
            printf("Day la Thang %d\n", thang);
            break;
        case Thang2:
            printf("Day la Thang %d\n", thang);
            break;
        case Thang3:
            printf("Day la Thang %d\n", thang);
            break;
        case Thang4:
            printf("Day la Thang %d\n", thang);
            break;
        case Thang5:
            printf("Day la Thang %d\n", thang);
            break;
        case Thang6:
            printf("Day la Thang %d\n", thang);
            break;
        case Thang7:
            printf("Day la Thang %d\n", thang);
            break;
        case Thang8:
            printf("Day la Thang %d\n", thang);
            break;
        case Thang9:
            printf("Day la Thang %d\n", thang);
            break;
        case Thang10:
            printf("Day la Thang %d\n", thang);
            break;
        case Thang11:
            printf("Day la Thang %d\n", thang);
            break;
        case Thang12:
            printf("Day la Thang %d\n", thang);
            break;
        default:
            printf("Thang khong dung dinh dang!");
    }
}

int main(){
    Thang thang;
    thang = Thang8;
    HienThang(thang);
    return 0;
}
