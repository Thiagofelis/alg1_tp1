#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate(int* random_numbers, int num_options, int num_colleges)
{
    random_numbers[0] = rand() % num_colleges;
    int i, j;
    for (j = 1; j < num_options; j++)
    {
        random_numbers[j] = rand() % num_colleges;
        for (i = 0; i < j; i++)
        {
            if (random_numbers[i] == random_numbers[j])
            {
                i = -1;
                random_numbers[j] = rand() % num_colleges;
            }
        }
    }
}

int main()
{
    FILE* stud_fp = fopen("candidatos.txt", "w");
    FILE* coll_fp = fopen("universidades.txt", "w");

    int num_options_is_random = 1;

    int num_colleges = 10000;
    int num_options = 10;
    int num_students = 200000;

    int random_numbers[num_options];

    srand(time(0));
    int i, j;

    fprintf(coll_fp, "%d\n", num_colleges);
    for (i = 0; i < num_colleges; i++)
    {
        fprintf(coll_fp, "%d %d\n", rand() % num_options, rand() % 1001);
    }
    int max_options;
    fprintf(stud_fp, "%d\n", num_students);

    for (i = 0; i < num_students; i++)
    {
        if (num_options_is_random)
        {
            max_options = rand() % num_options;
        }
        else
        {
            max_options = num_options;
        }
        fprintf(stud_fp, "%d %d\n", max_options, rand() % 1001);

        generate(random_numbers, num_options, num_colleges);
        if (max_options > 0)
        {
            for (j = 0; j < max_options - 1; j++)
            {
                fprintf(stud_fp, "%d ", random_numbers[j] + 1);
            }
            fprintf(stud_fp, "%d\n", random_numbers[max_options - 1] + 1);
        }
        else
        {
            fprintf(stud_fp, "\n");
        }
    }

    return 0;
}
