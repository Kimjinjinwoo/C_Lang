#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{

    FILE* fr = fopen("input.txt", "r");

    typedef struct account {
        int accountNum;
        char name[30];
        int deposit;
        int loan; // ¥Î√‚±›
    }account;
    int many = 0;

    account list[100];
    while (!feof(fr)) {
        many++;
        account info;
        fscanf(fr, "%d", &info.accountNum);
        fscanf(fr, "%s", info.name);
        fscanf(fr, "%d", &info.deposit);
        fscanf(fr, "%d", &info.loan);
        list[many - 1] = info;
    }

    account VIP = list[0];
    for (int i = 0; i < many; i++)
    {
        if (list[i].loan > VIP.loan)
            VIP = list[i];
    }

    fclose(fr);
    FILE* fw = fopen("output.txt", "w");
    fprintf(fw, "%d ", VIP.accountNum);
    fprintf(fw, "%s ", VIP.name);
    fprintf(fw, "%d ", VIP.deposit);
    fprintf(fw, "%d ", VIP.loan);

}