#include <libchessviz/chessviz.h>
#include <stdio.h>
#include <stdlib.h>

void makeboard(char desc[9][9])
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 1; j++) {
            desc[i][j] = 56 - i;
        }
    desc[8][0] = 32;
    for (int i = 8; i > 7; i--) {
        for (int j = 1; j < 9; j++)
            desc[i][j] = 96 + j;
    }
    for (int i = 2; i < 6; i++)
        for (int j = 1; j < 9; j++) {
            desc[i][j] = 32;
        }
    for (int i = 1; i < 2; i++)
        for (int j = 1; j < 9; j++) {
            desc[i][j] = 112;
        }
    for (int i = 6; i < 7; i++)
        for (int j = 1; j < 9; j++) {
            desc[i][j] = 80;
        }
    desc[7][1] = 82;
    desc[7][8] = 82;
    desc[7][2] = 78;
    desc[7][7] = 78;
    desc[7][3] = 66;
    desc[7][6] = 66;
    desc[7][4] = 81;
    desc[7][5] = 75;
    desc[0][1] = 114;
    desc[0][8] = 114;
    desc[0][2] = 110;
    desc[0][7] = 110;
    desc[0][3] = 98;
    desc[0][6] = 98;
    desc[0][4] = 113;
    desc[0][5] = 107;
}

void print_board(char desc[9][9])
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            printf("%c ", desc[i][j]);
        printf("\n");
    }
    printf("\n");
}

void black_m(int* step_i, char desc[9][9])
{
    if ((step_i[1] == 1) && (step_i[4] == step_i[1] + 2)
        && (desc[step_i[4]][step_i[3]] == ' ')) {
        desc[step_i[4]][step_i[3]]
                = desc[step_i[1]][step_i[0]];
        desc[step_i[1]][step_i[0]] = ' ';
    } else if (
            (desc[step_i[4]][step_i[3]] == ' ')
            && (step_i[4] == step_i[1] + 1)) {
        desc[step_i[4]][step_i[3]]
                = desc[step_i[1]][step_i[0]];
        desc[step_i[1]][step_i[0]] = ' ';
    } else if (
            (desc[step_i[4]][step_i[3]] > 'A')
            && (desc[step_i[4]][step_i[3]] < 'Z')
            && (step_i[4] == step_i[1] + 1)
            && ((step_i[3] == step_i[0] + 1)
                || (step_i[3] == step_i[0] - 1))) {
        desc[step_i[4]][step_i[3]]
                = desc[step_i[1]][step_i[0]];
        desc[step_i[1]][step_i[0]] = ' ';
    }
}
void white_m(int* step_i, char desc[9][9])
{
    if ((step_i[1] == 6) && (step_i[4] == step_i[1] - 2)
        && (desc[step_i[4]][step_i[3]] == ' ')) {
        desc[step_i[4]][step_i[3]]
                = desc[step_i[1]][step_i[0]];
        desc[step_i[1]][step_i[0]] = ' ';
    } else if (
            (desc[step_i[4]][step_i[3]] == ' ')
            && (step_i[4] == step_i[1] - 1)) {
        desc[step_i[4]][step_i[3]]
                = desc[step_i[1]][step_i[0]];
        desc[step_i[1]][step_i[0]] = ' ';
    } else if (
            (desc[step_i[4]][step_i[3]] > 'a')
            && (step_i[4] == step_i[1] - 1)
            && ((step_i[3] == step_i[0] + 1)
                || (step_i[3] == step_i[0] - 1))) {
        desc[step_i[4]][step_i[3]]
                = desc[step_i[1]][step_i[0]];
        desc[step_i[1]][step_i[0]] = ' ';
    }
}
void white_t(char desc[9][9])
{
    char step[6];
    int flag = 1, step_i[6];
    scanf("%s", step);
    while (flag == 1) {
        flag = 0;
        while ((step[0] < 'a') || (step[0] > 'h') || (step[2] != '-')) {
            printf("Move is wrong, do other\n");
            scanf("%s", step);
        }
        step[0] = step[0] - 96;
        step[1] = abs(step[1] - 56);
        step[3] = step[3] - 96;
        step[4] = abs(step[4] - 56);
        step_i[0] = step[0];
        step_i[1] = step[1];
        step_i[3] = step[3];
        step_i[4] = step[4];
        switch (desc[step_i[1]][step_i[0]]) {
        case 'P':
            white_m(step_i, desc);
            if (desc[step_i[1]][step_i[0]] == 'P') {
                flag = 1;
                printf("Move is wrong, do other\n");
            }
            break;
        default:
            printf("Move is wrong, do other\n");
            flag = 1;
        }
    }
}

void black_t(char desc[9][9])
{
    char step[6];
    int flag = 1, step_i[6];
    printf(" ");
    scanf("%s", step);
    while (flag == 1) {
        flag = 0;
        while ((step[0] < 'a') || (step[0] > 'h') || (step[2] != '-')) {
            printf("Move is wrong, do other\n");
            scanf("%s", step);
        }
        step[0] = step[0] - 96;
        step[1] = abs(step[1] - 56);
        step[3] = step[3] - 96;
        step[4] = abs(step[4] - 56);
        step_i[0] = step[0];
        step_i[1] = step[1];
        step_i[3] = step[3];
        step_i[4] = step[4];
        switch (desc[step_i[1]][step_i[0]]) {
        case 'p':
            black_m(step_i, desc);
            if (desc[step_i[1]][step_i[0]] == 'p') {
                flag = 1;
                printf("Move is wrong, do other\n");
            }
            break;
        default:
            printf("Move is wrong, do other\n");
            flag = 1;
        }
    }
}
