#include<stdio.h>
#include <stdlib.h>
#include"Std.h"

#define SIZE        30
#define SizeGen    10
#define SizeRev     6

u8 count = 5;
char arrS[SizeRev][50] = {"2    Pm to 2:30 Pm", "2:30 Pm to 3    Pm", "3    Pm to 3:30 Pm", "4    Pm to 4:30 Pm",
                          "4:30 Pm to 5    Pm", "Not Reserved"};
char arrN[SizeRev] = {0, 0, 0, 0, 0, 1};

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

Node *Add(Node *S) {
    Node *temp = (Node *) malloc(sizeof(Node));
    s32 count = 0;
    s32 id;
    Node *ptr = S;

    printf("ID     :  ");
    scanf("%ld", &id);
    if (ptr == NULL) {
        printf("Name   :  ");
        scanf("%s", temp->name);
        printf("Age    :  ");
        scanf("%d", &temp->age);
        printf("Gender :  ");
        scanf("%s", temp->gender);
        temp->ID = id;
        temp->Res = 5;
    } else {

        while (ptr != NULL) {
            if (ptr->ID == id)
                count++;

            ptr = ptr->Link;
        }
        if (count > 0)
            printf("Id Already Exists\n");
        else {
            printf("Name   :  ");
            scanf("%s", temp->name);
            printf("Age    :  ");
            scanf("%d", &temp->age);
            printf("Gender :  ");
            scanf("%s", temp->gender);
            temp->ID = id;
            temp->Res = 5;
        }
    }
    temp->Link = S;
    S = temp;
    return S;
}


void Display(Node *S) {

    s32 id;
    u8 True = 5;
    printf("\n\nEnter The Id : ");
    scanf("%ld", &id);
    Node *pn = S;

    while (pn != NULL) {
        if (id == pn->ID) {
            printf("Name   : %s\n", pn->name);
            printf("Age    : %d \n", pn->age);
            printf("Gender : %s \n", pn->gender);
            //printf("ID     : %d \n\n",pn->ID);
            True = 1;
        }
        pn = pn->Link;
    }
    if (True != 1)
        printf("Id not in the System");
}

void Edit(Node *S) {
    s32 id;
    Node *ptr = S;
    s32 pos = 0;
    printf("\n\nEnter The Id To Edit : ");
    scanf("%d", &id);
    while (ptr != NULL) {
        if (ptr->ID == id) {
            pos++;
            break;
        }
        ptr = ptr->Link;
    }
    if (pos > 0) {
        printf("Name : ");
        scanf("%s", ptr->name);
        printf("Age: ");
        scanf("%d", &ptr->age);
        printf("Gender : ");
        scanf("%s", ptr->gender);
    } else
        printf("incorrect ID !");


}

void Reserve(Node *S) {

    s32 id;
    Node *ptr = S;
    s32 pos = 0;
    u8 check = 0;
    u8 resv = 0;
    printf("\n\nEnter The Id To Reserve : ");
    scanf("%ld", &id);
    while (ptr != NULL) {

        if (ptr->ID == id) {
            pos++;
            break;
        }

        ptr = ptr->Link;
    }

    if (pos > 0) {
        for (u8 i = 0; i < count; i++) {
            if (arrN[i] == 0)
                printf("%d- %s\n", i + 1, arrS[i]);
            else {
                check++;
            }
        }
        if (check >= 5) {
            printf("\n Sorry No Availble Reservetions !");
            return;
        } else {
            printf("\nYou Choice = ");
            scanf("%d", &resv);
        }
        if (resv > 0 && resv <= 5) {
            ptr->Res = resv - 1;
            arrN[resv - 1] = 1;
        } else
            printf("Wrong Choice !");
    } else
        printf("incorrect ID !");

}


void Cancel(Node *S) {
    s32 id;
    Node *ptr = S;
    s32 pos = 0;


    printf("\n\nEnter The Id To Cancel Reserve : ");
    scanf("%ld", &id);
    while (ptr != NULL) {

        if (ptr->ID == id) {
            pos++;
            break;
        }

        ptr = ptr->Link;
    }

    if (pos > 0) {

        if (arrN[ptr->Res] == 1) {
            printf("Your Reservetion: ( %s ) is cancelled \n", arrS[ptr->Res]);
            arrN[ptr->Res] = 0;
            ptr->Res = 5;

        } else {
            printf("This ID didn't reseverd !");
        }

    } else
        printf("incorrect ID !");

}


void View(Node *S) {

    u8 i = 0;
    Node *ptr = S;

    if (ptr == NULL)
        printf("No Clients in Systems !");

    else {
        while (ptr != NULL) {
            i++;
            printf("%d- ID: %d ( %s ) \n", i, ptr->ID, arrS[ptr->Res]);

            ptr = ptr->Link;
        }
    }

}



