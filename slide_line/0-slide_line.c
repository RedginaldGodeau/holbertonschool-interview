#include "slide_line.h"

int slide_left(int *line, size_t size)
{
    size_t i = 0;
    size_t i2 = 0;
    for (i = 0; i < size; i++)
    {
        if (line[i] == 0) {
            for (i2 = i; i2 < size; i2++)
            {
                if (line[i2] == 0)
                    continue;
                else
                {
                    int temp = line[i2];
                    line[i2] = 0;
                    line[i] = temp;
                    break;
                }
            }
        }
    }
    
    for (i = 1; i < size; i++)
    {
        if (line[i] == line[i - 1]) {
            line[i] = 0;
            line[i - 1] += line[i - 1];
        }
    }

    for (i = 0; i < size; i++)
    {
        if (line[i] == 0) {
            for (i2 = i; i2 < size; i2++)
            {
                if (line[i2] == 0)
                    continue;
                else
                {
                    int temp = line[i2];
                    line[i2] = 0;
                    line[i] = temp;
                    break;
                }
            }
        }
    }

    return (1);
}

int slide_right(int *line, size_t size)
{
    int i = 0;
    int i2 = 0;

    for (i = size - 1; i >= 0; i--)
    {
        if (line[i] == 0) {
            for (i2 = i; i2 >= (int) 0; i2--)
            {
                if (line[i2] == 0)
                    continue;
                else
                {
                    int temp = line[i2];
                    line[i2] = 0;
                    line[i] = temp;
                    break;
                }
            }
        }
    }

    for (i = size - 2; i >= 0; i--)
    {
        if (line[i] == line[i + 1]) {
            line[i] = 0;
            line[i + 1] += line[i + 1];
        }
    }

    for (i = size - 1; i >= 0; i--)
    {
        if (line[i] == 0) {
            for (i2 = i; i2 >= (int) 0; i2--)
            {
                if (line[i2] == 0)
                    continue;
                else
                {
                    int temp = line[i2];
                    line[i2] = 0;
                    line[i] = temp;
                    break;
                }
            }
        }
    }

    return (1);
}

int slide_line(int *line, size_t size, int direction)
{
    switch (direction)
    {
    case SLIDE_LEFT:
        slide_left(line, size);
        break;
    case SLIDE_RIGHT:
        slide_right(line, size);
        break;
    }

    return (1);
}
