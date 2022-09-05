#include <stdio.h>

int main()
{
    puts("Hello, Cash Register!");

    puts("");
    fprintf(stdout, "The mechanism is simple:\n" \
                    "\tProviding a number adds it to the entire sum\n" \
                    "\tProviding anything else ends the calculation.\n");
    puts("");
    
    float temp = -1;
    float sum = 0;
    int num_param = 1;

    while (num_param == 1)
    {
        fprintf(stdout, "Current sum: %.2f\n", sum);
        fprintf(stdout, "+: ");
        num_param = fscanf(stdin, "%f", &temp);
        if (num_param != 1)
            break;
        sum += temp;
    }

    fprintf(stdout, "Final sum: %.2f\n", sum);
}