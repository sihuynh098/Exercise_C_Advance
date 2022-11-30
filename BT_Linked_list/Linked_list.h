#ifndef __Linked_list_h__
#define __Linked_list_h__

#include <stdio.h>
#include <stdlib.h>

#define Max_arr 100

struct Node{
    int data;
    struct Node *next;
};
static struct Node unuse;
struct Node arr[Max_arr];

typedef struct Node *Node;
void assign(void);
Node allocation();
void Menu(void);
char check_char();
int check_int();
Node creat_node(int value);
void init_node(Node *head);
void print_node(Node head);
void insert_end_node(Node *head, int value);
void insert_first_node(Node *head, int value);
void insert_node(Node *head, int value,int index);
void clear_node_first(Node *head);
void clear_node_end(Node *head);
void clear_node_at(Node *head, int index);
void clear_node_all(Node *head);
int get_value_node(Node head, int index);
int length_node(Node head);
int search_node(Node head, int value);
void input_node(Node *head);
void node_ascending(Node *head);
void node_decrease(Node *head);

#endif