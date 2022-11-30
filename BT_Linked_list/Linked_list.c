#include "Linked_list.h"

struct Node arr[Max_arr] = {0};

void Menu(void){
    printf("\n===---Chuong trinh quan ly LINKED_LIST---===\n");
    printf("1. Nhap 'c' de tao Linked_list cac so nguyen.\n");
    printf("2. Nhap 'p' de in day.\n");
    printf("3. Nhap 'i' de them mot phan tu vao day.\n");
    printf("4. Nhap 'd' de xoa mot phan tu tai mot vi tri k\n");
    printf("5. Nhap 's' de sap xep day so theo chieu tang dan\n");
    printf("6. Nhap 'x' de sap xep theo chieu giam.\n");
    printf("7. Nhap 'f' de tim kiem 1 so x co trong day khong\n");
    printf("8. Nhap 'e' de thoat chuong trinh\n");
    printf("------------------------------------------------------------\n");
}

void clean_stdin(){
    while(getchar() != '\n'){
    }
}

char check_char(){
    char a;
    int dk=0;
    while(dk==0){
        if((scanf(" %c", &a)) == 1 && getchar() == '\n'){
            dk=1;
        }else{
            printf("Vui long nhap su lua chon phu hop: ");
            clean_stdin();
        }
    }
    return a;
}

int check_int(){
    int a=0;
    int dk=0;
    while(dk==0){
        if((scanf("%d", &a)) == 1 && getchar() == '\n'){
            dk=1;
        }else{
            printf("Vui long nhap mot so nguyen duong: ");
            clean_stdin();
        }
    }
    return a;
}

void init_node(Node *head){
    static int flag = 1;
    if(flag == 1){
        *head = NULL;
        flag = 0;
    }
}

void input_node(Node *head){
    int pt;
    int sl;
    init_node(head);
    assign();
    if(head != NULL)
    {
        clear_node_all(head);
    }
    do{
        printf("Nhap vao so luong Node: ");
        sl = check_int();
    }while(sl < 0 && printf("Vui long nhap so lon 0!\n"));

    for(int i=1;i<=sl;i++){
        printf("Nhap gia tri moi cho node%d: ", i);
        scanf("%d", &pt);
        insert_end_node(head, pt);
    }
}

void assign(){
    for(int i=0;i<Max_arr;i++){
        arr[i].next = &unuse;
    }
}

Node allocation(){
    Node temp = NULL;
    for(int i=0; i < Max_arr && temp == NULL;i++){
        if(arr[i].next == &unuse){
            temp = &arr[i];
        }
    }
    return temp;
}

Node creat_node(int value)
{    
    Node p = allocation();
    p->data = value;
    p->next = NULL;
    return p;
}

void print_node(Node head){
    int sl;
    sl = length_node(head);
    for(int i=1;i<=sl;i++){
        printf("Gia tri tai node%d: %d\n", i, get_value_node(head, i));
    }
}

void insert_end_node(Node *head, int value){
    Node temp = creat_node(value);
    Node p = NULL;
    if(*head == NULL){
        *head = temp;
    }else{
        p = *head;
        while(p->next != NULL){
            p = p->next;
        }
        p->next = temp;
    }
}

void insert_first_node(Node *head, int value){
    Node temp = creat_node(value);
    if(*head == NULL){
        *head = temp;
    }else{
        temp->next = *head;
        *head = temp;
    }
}

void insert_node(Node *head, int value,int index){
    Node p = *head;
    int kt=0;
    if(index == 1 || *head == NULL){
        insert_first_node(head, value);
    }else{
        int i=2;
        while (p != NULL && i != index)
        {
            p = p->next;
            i++;
        }
        if(p == NULL){
            insert_end_node(head, value);
        }else{
            Node temp = creat_node(value);
            temp->next = p->next; 
            p->next = temp;
        }
    }
}

void clear_node_first(Node *head){
    Node p = *head;
    if(*head == NULL){
        printf("Khong co gi de xoa!\n");
    }else{
        *head = p->next;
        p->data = 0;
        p->next = &unuse;
    }
}

void clear_node_end(Node *head){
    Node p = *head;
    while (p->next->next != NULL)
    {
        p = p->next;
    }
    p->next->next = &unuse;
    p->next->data = 0;
    p->next = NULL;  
}

void clear_node_at(Node *head, int index){
    Node p = *head;
    Node a = NULL;
    if(index == length_node(*head)){
        clear_node_end(head);
    }else if(index == 1){
        clear_node_first(head);
    }else{
        int i=1;
        while(i != index){
            a = p;
            p = p->next;
            i++;
        }
        a->next = p->next;
        p->next = &unuse;
    }
} 

void clear_node_all(Node *head)
{
    Node p = *head;
    while (*head != NULL)
    {
        *head = (*head)->next;
        p->next = &unuse;
        p = *head;
    }
}

int get_value_node(Node head, int index){
    Node p = head;
    int i=1;
    while (p->next != NULL && i != index)
    {
        p = p->next;
        i++;
    }
    return p->data;
}

int length_node(Node head){
    int i=1;
    Node p = head;
    while(p->next != NULL){
        p = p->next;
        i++;
    }
    return i;
}

int search_node(Node head, int value){
    int pos = 1;
    for(Node p = head;p != NULL;p = p->next){
        if(p->data == value){
            return pos;
        }
        pos++;
    }
    return 0;
}

void node_ascending(Node *head){
    int tg;
    Node p;
    Node a;
    for(p = *head;p->next != NULL;p = p->next){
        for(a = p->next;a != NULL; a = a->next){
            if(p->data > a->data){
                tg = p->data;
                p->data = a->data;
                a->data = tg;
            }
        }
    }
}

void node_decrease(Node *head){
    int tg;
    Node i;
    Node j;
    for(i = *head;i->next != NULL;i = i->next){
        for(j = i->next;j != NULL;j = j->next){
            if(i->data < j->data){
                tg = i->data;
                i->data = j->data;
                j->data = tg;
            }
        }
    }
}