#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

struct menu {
    int pay, tax;
    char Ctab[9];
    char name[30];
};

typedef struct menu mnu;
mnu order;

bool cashier() {
    char name[3][20] = {"James", "Alex", "Mika"};
    int ls;

    printf("============================\n");
    printf("Avalaible cashier today\n");
    for(int i = 0; i < 3; ++i) {
        printf("%d. %s\n", i+1, name[i]);
    }
    printf("Do you want login as...?? = ");
    scanf("%d", &ls);

    switch(ls) {
        case 1:
            printf("You login as James.\n");
            return true;
        case 2:
            printf("You login as Alex.\n");
            return true;
        case 3:
            printf("You login as Mika.\n");
            return true;
        default:
            return false;
    }
}

int main(void) {
    char cashier_name[30];
    char pck;
    int choice;

    if (!cashier()) {
        printf("Invalid cashier selection.\n");
        return 1;
    }

    system("cls");
    printf("\tWelcome!!\n");

Head:
    printf("\nMENU : \n");
    printf("1. Burger = 10000\n");
    printf("2. Sausage = 5000\n");
    printf("3. Fish 'n Chips = 10000\n");

    printf("If there's order from client, input it below:\n");
    printf("\nClient name: ");
    scanf(" %s", order.name);

    printf("What's their choice? = ");
    scanf("%d", &choice);
    fflush(stdin); //

    switch(choice) {
        case 1:
            printf("Client pick a Burger, are you sure? (Y/T) = ");
            scanf(" %c", &pck);

            if(pck == 'Y' || pck == 'y') {
                order.pay = 10000 + (10000 * 0.10);
                printf("Client buy a burger, Total = %d\n", order.pay);
            }
            else if(pck == 'T' || pck == 't') {
                printf("Client didn't choose a burger.\n");
                goto Head;
            }
            else {
                printf("Invalid input.\n");
                goto Head;
            }
            break;

        case 2:
            printf("Client pick a Sausage, are you sure? (Y/T) = ");
            scanf(" %c", &pck);

            if(pck == 'Y' || pck == 'y') {
                order.pay = 5000 + (5000 * 0.15);
                printf("Client buy a sausage, Total = %d\n", order.pay);
            }
            else if(pck == 'T' || pck == 't') {
                printf("Client didn't choose a sausage.\n");
                goto Head;
            }
            else {
                printf("Invalid input.\n");
                goto Head;
            }
            break;

        case 3:
            printf("Client pick a Fish 'n Chips, are you sure? (Y/T) = ");
            scanf(" %c", &pck);

            if(pck == 'Y' || pck == 'y') {
                order.pay = 10000 + (10000 * 0.20);
                printf("Client buy a Fish 'n Chips, Total = %d\n", order.pay);
            }
            else if(pck == 'T' || pck == 't') {
                printf("Client didn't choose a Fish 'n Chips.\n");
                goto Head;
            }
            else {
                printf("Invalid input.\n");
                goto Head;
            }
            break;

        default:
            printf("Invalid code !!\n");
            goto Head;
    }

    return 0;
}
