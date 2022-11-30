#include "stdio.h"
#include "string.h"
int Dodaichuoi(char chuoi[]){
    int i=0;
    while(chuoi[i] != '\0'){
        i++;
    }
    return i;
}

void KiemTraChuoi(char chuoi[]){
    
}

int main(){
    char s1[50];
    char s2[50];
    // int Dais1=Dodaichuoi(s1), Dais2 =  Dodaichuoi(s2);
    int count = 0;
    
    do{
        printf("Nhap chuoi cha: ");
        gets(s1);
        printf("Nhap chuoi con: ");
        gets(s2);
    }while(Dodaichuoi(s1) < Dodaichuoi(s2));
    for(int i=(Dodaichuoi(s1))-1;i>=0;i--){
        int j = Dodaichuoi(s2) - 1;
        if(s1[i] == s2[j] && s2[j] != '\0'){
            count++;
            j--;
        }
    }
    if((count) > 0){
        printf("Chuoi con da xuat hien trong chuoi cha va xuat hien %d lan", count);
    }else{
        printf("Chuoi con khong hien lan nao trong chuoi cha!!");
    }
    return 0;
}