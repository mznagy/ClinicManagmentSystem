/*
 * main.c
 *
 *  Created on: Sep 29, 2023
 *      Author: mznagy
 */
#include<stdio.h>
#include"Std.h"
#include"ProjHeader.h"

#define PW 1234

int main() {
    s32 mode, pw, try = 0;
    s32 feut;
    Node *Start = NULL;
    u8 num;
    printf("=====================================================================\n\t\t Welcome In Clinc Managment System");
    while (1) {
        printf("\n\n=====================================================================\nChoose:\n1-Admin Mode\n2-User Mode\n\nChoice: ");
        scanf("%ld", &mode);


        switch (mode) {

            case 1:
                printf("Enter Password: ");
                while (try <= 3) {
                    scanf("%ld", &pw);
                    if (pw == PW)
                        break;
                    printf("Wrong Password , You Have %ld Tries Left!\n", 3 - try);
                    try++;
                }
                if (try <= 3) {
                    printf("=====================================================================\n\t\t You Login Successfully In Admin Mode\n\n");
                    while (1) {
                        printf("\n=====================================================================\nChoose:\n1-Add new patient record.\n2-Edit patient record.\n3-Reserve a slot with the doctor.\n4-Cancel reservation.\n\nChoice: ");
                        scanf("%ld", &feut);
                        switch (feut) {
                            default:
                                printf("Wrong Choice\n!");
                                break;
                            case 1:
                                printf("\n=====================================================================\n\t\t Add Client\n");
                                Start = Add(Start);
                                break;
                            case 2:
                                printf("\n=====================================================================\n\t\t Edit Client\n");
                                Edit(Start);
                                break;
                            case 3:
                                printf("\n=====================================================================\n\t\t Reservetion of Client\n");
                                Reserve(Start);
                                break;
                            case 4:
                                printf("\n=====================================================================\n\t\t Cancel Reservetion of Client\n");
                                Cancel(Start);
                                break;
                        }
                        printf("\n=====================================================================\n\nDo You Want More Operations In Admin Mode :\n1- Yes \n2- No\nChoice :  ");
                        scanf("%d", &num);
                        if (num == 1)
                            continue;
                        else
                            break;
                    }
                } else {
                    printf("Access Denied Sorry !\n");
                    try = 0;
                }
                break;
            case 2:
                printf("=====================================================================\n\t\t Welcome In User Mode\n\n");
                while (1) {
                    printf("\n=====================================================================\nChoose:\n1-View patient record..\n2-View today reservations.\n\nChoice: ");
                    scanf("%ld", &feut);
                    switch (feut) {
                        default:
                            printf("Wrong Choice!");
                            break;
                        case 1:
                            printf("\n=====================================================================\n\t\t View Client Info \n");
                            Display(Start);
                            break;
                        case 2:
                            printf("\n=====================================================================\n\t\t View Reservations \n");
                            View(Start);
                            break;
                    }

                    printf("\n=====================================================================\n\nDo You Want More Operations In User Mode :\n1- Yes \n2- No\nChoice :  ");
                    scanf("%d", &num);
                    if (num == 1)
                        continue;

                    else
                        break;
                }
                break;

            default:
                printf("Wrong Choice !");
                break;
        }
        printf("\n=====================================================================\n\nDo You Shut Down System :\n1- Yes \n2- No\nChoice :  ");
        scanf("%d", &num);

        if (num == 1)
            break;
        else {
            continue;
        }
    }
    return 0;
}