#ifndef HEADER
#define HEADER

#define SIZE        30
#define SizeGen    10
typedef struct n {

    u8 name[SIZE];
    u8 age;
    u8 gender[SizeGen];
    s32 ID;
    u8 Res;
    struct n *Link;
} Node;


Node *Add(Node *S);

void Display(Node *S);

void Edit(Node *S);

void Reserve(Node *S);

void Cancel(Node *S);

void View(Node *S);

#endif