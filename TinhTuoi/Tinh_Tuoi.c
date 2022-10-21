#include "stdio.h"
#include "time.h"


int DieuKien(int ngay, int thang, int nam){
    if(ngay < 1 || ngay > 31){
        printf("ERROR !!! Khong co ngay %d!\n", ngay);
        return 0;
    }else if(thang < 1 || thang > 12){
        printf("ERROR !!! Khong co thang %d!\n", thang);
        return 0;
    }else if(nam > 2022){
        printf("ERROR !!! Chua toi nam %d!\n", nam);
        return 0;
    }else if(thang == 2 && ngay > 29){
        printf("ERROR !!! Thang %d Khong co ngay %d!\n", thang, ngay);
        return 0;
    }else if(thang == 4,6,9,11 && ngay > 30){
        printf("ERROR !!! Thang %d Khong co ngay %d!\n", thang, ngay);
        return 0;
    }else{
        return 1;
    }
}

void TinhTuoi(int thang, int nam){
    time_t my_time;
    time (&my_time);
    struct tm *timeinfo; 
    timeinfo = localtime (&my_time);
    timeinfo->tm_mday;
    
    int tuoi, namhientai, thanghientai;
    namhientai = timeinfo->tm_year+1900;
    thanghientai = timeinfo->tm_mon+1;
    if(thang >= thanghientai){
        tuoi = namhientai - nam - 1;
        printf("Tuoi ban la: %d tuoi %d thang", tuoi, thanghientai);
    }else{
        tuoi = namhientai - nam;
        printf("Tuoi ban la: %d tuoi %d thang", tuoi, thanghientai-thang);
    }
}

int main(){
    int ngay, thang, nam;
    do{
    printf("Nhap vao Ngay: ");
    scanf("%d", &ngay);
    printf("Nhap vao Thang: ");
    scanf("%d", &thang);
    printf("Nhap vao Nam: ");
    scanf("%d", &nam);
    }while(DieuKien(ngay, thang, nam) == 0);
    printf("Ngay %d Thang %d Nam %d\n", ngay, thang, nam);
    TinhTuoi(thang, nam);
    return 0;
}
