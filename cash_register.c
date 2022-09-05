#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

static void interrupt(int signal)
{
    fputs("\nSignal interrupted. Stopping the program...\n", stderr);
    exit(signal);
}

static void print_introduction()
{
    fputs("\n", stdout);
    fputs("The mechanism is simple:\n" \
                    "\tProviding a price adds it to the entire sum\n" \
                    "\tProviding anything else (excluding whitespaces) ends the calculation.\n", stdout);
    fputs("\n", stdout);
}

int main()
{
    signal(SIGINT, interrupt);

    fputs("Hello, Cash Register!\n", stdout);

    print_introduction();
    
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
        if (temp < 0)
        {
            fprintf(stderr, "Please provide a valid price\n");
            continue;
        }
        sum += temp;
    }

    fprintf(stdout, "Final sum: %.2f\n", sum);
}