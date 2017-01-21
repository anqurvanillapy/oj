/**
 *  292. Nim Game
 *
 *  You are playing the following Nim Game with your friend: There is a heap of
 *  stones on the table, each time one of you take turns to remove 1 to 3
 *  stones. The one who removes the last stone will be the winner. You will take
 *  the first turn to remove the stones.
 *
 *  Both of you are very clever and have optimal strategies for the game. Write
 *  a function to determine whether you can win the game given the number of
 *  stones in the heap.
 *  
 *  - Example:
 *      + If there are 4 stones in the heap, then you will never win the game:
 *      no matter 1, 2, or 3 stones you remove, the last stone will always be
 *      removed by your friend.
 *  - Hint:
 *      + If there are 5 stones in the heap, could you figure out a way to
 *      remove the stones such that you will always be the winner?
 */

#include <stdio.h>
#include <stdbool.h>

bool canWinNim(int n);

int
main(int argc, char const *argv[])
{
    bool can_win;

    can_win = canWinNim(1);
    printf("%d\n", can_win);

    return 0;
}

/* === solution === */

bool
canWinNim(int n)
{
    if (!( n % 4 )) return false;
    else return true;
}

/* === EOS === */
