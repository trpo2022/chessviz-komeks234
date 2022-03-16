#include <libchessviz/chessviz.h>

#include <stdio.h>
int main()
{
    char desc[9][9];
    int MoveNum = 1;
    int flag = 1;
    makeboard(desc);
    print_board(desc);
    while (flag == 1) {
        printf("%d. ", MoveNum);
        white_t(desc);
        black_t(desc);
        print_board(desc);
        MoveNum += 1;
    }
    return 0;
}
