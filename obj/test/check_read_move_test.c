#include <libchessviz/chessviz.h>

#include <ctest.h>

char mass[9][9]
        = {{'8', 'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
           {'7', 'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
           {'6', 32, 32, 32, 32, 32, 32, 32, 32},
           {'5', 32, 32, 32, 32, 32, 32, 32, 32},
           {'4', 32, 32, 32, 32, 32, 32, 32, 32},
           {'3', 32, 32, 32, 32, 32, 32, 32, 32},
           {'2', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
           {'1', 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
           {32, 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'}};

int step_integer[6] = {1, 1, 0, 1, 3};

CTEST(read_figures, BlackPawn)
{
    ASSERT_EQUAL(0, BlackPawnMove(step_integer, mass));
}

CTEST(read_figures, WhitePawn)
{
    step_integer[0] = 1;
    step_integer[1] = 6;
    step_integer[3] = 1;
    step_integer[4] = 5;
    ASSERT_EQUAL(0, WhitePawnMove(step_integer, mass));
}

CTEST(read_figures, WhiteHorse)
{
    step_integer[0] = 2;
    step_integer[1] = 7;
    step_integer[3] = 3;
    step_integer[4] = 5;
    ASSERT_EQUAL(0, WhiteHorseMove(step_integer, mass));
}

CTEST(read_figures, BlackHorse)
{
    step_integer[0] = 2;
    step_integer[1] = 0;
    step_integer[3] = 3;
    step_integer[4] = 2;
    ASSERT_EQUAL(0, BlackHorseMove(step_integer, mass));
}

CTEST(read_figures, WhiteBishop)
{
    step_integer[0] = 3;
    step_integer[1] = 7;
    step_integer[3] = 5;
    step_integer[4] = 5;
    ASSERT_EQUAL(1, BlackHorseMove(step_integer, mass));
}

CTEST(Input, InputValidation)
{
    ASSERT_EQUAL(0, InputValidation("e2-e4"));
}
