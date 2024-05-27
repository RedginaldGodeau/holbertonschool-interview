#include "sandpiles.h"

/**
 * sandfall - Sand Fall
 * @grid: 3x3 grid
 * @x: int
 * @y: int
 */
void sandfall (int grid[3][3], int x, int y) {
    if (grid[y][x] > 3)
    {
        grid[y][x] -= 4;

        if (y + 1 <= 2)
        {
            grid[y + 1][x] += 1;
        }
        if (y - 1 >= 0)
        {
            grid[y - 1][x] += 1;
        }

        if (x + 1 <= 2)
        {
            grid[y][x + 1] += 1;
        }
        if (x - 1 >= 0)
        {
            grid[y][x - 1] += 1;
        }
    }
}
/**
 * is_stable - check if stable
 * @grid: 3x3 grid
 * 
 * Return: 1 or 0
 */
short int is_stable (int grid[3][3])
{
    short int stable = 1;
    size_t i = 0;

    for (i = 0; i < 9; i++)
    {
        int x = i % 3;
        int y = i / 3;

        if (grid[y][x] > 3)
        {
            stable = 0;
            break;
        }
    }

    return stable;
}

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * sandpiles_sum - sandpiles
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    size_t i = 0;

    for (i = 0; i < 9; i++)
    {
        int x = i % 3;
        int y = i / 3;

        grid1[y][x] += grid2[y][x];
    }

    while (is_stable(grid1) == 0)
    {
        if (is_stable(grid1) == 1)
                break;

        printf("=\n");
        print_grid(grid1);

       for (i = 0; i < 9; i++)
        {
            int x = i % 3;
            int y = i / 3;

            if (is_stable(grid1) == 1)
                break;

            sandfall(grid1, x, y);
        }
    }
}
