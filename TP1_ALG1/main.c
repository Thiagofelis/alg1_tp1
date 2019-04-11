#include <stdio.h>
#include <stdlib.h>
#include "collegestack.h"
#include "students.h"
#include "proposalstack.h"
#include "college.h"
#include "aux_funcs.h"

int main(int argc, char** argv)
{
    FILE* coll_fp = fopen(argv[1], "r");
    FILE* stud_fp = fopen(argv[2], "r");

    char buffer[20];
    int i, min_g, max_s;

    read(coll_fp, buffer);
    int num_colleges = atoi(buffer);
    college coll_vec[num_colleges];

    for (i = 0; i < num_colleges; i++)
    {
        read(coll_fp, buffer);
        max_s = atoi(buffer);
        read(coll_fp, buffer);
        min_g = atoi(buffer);

        coll_vec[i] = college_createinstance(min_g, max_s);
    }

    read(stud_fp, buffer);
    int num_options, grade;
    int num_students = atoi(buffer);
    student stud_vec[num_students];

    for (i = 0; i < num_students; i++)
    {
        read(stud_fp, buffer);
        num_options = atoi(buffer);
        read(stud_fp, buffer);
        grade = atoi(buffer);

        int j;
        int options[num_options];
        for (j = 0; j < num_options; j++)
        {
            read(stud_fp, buffer);
            /* subtracts 1, because college 1 has index 0 */
            options[j] = atoi(buffer) - 1;
        }

        stud_vec[i] = student_createinstance(grade, num_options, options);
    }

    proposalstack prop_stack = proposalstack_build(num_students);

    int stud_index = proposalstack_pop(&prop_stack);
    int coll_index, stud_grade, returned_value;

    while (stud_index != -1)
    {
        coll_index = student_getbestoption(&(stud_vec[stud_index]));
        stud_grade = student_getgrade(&(stud_vec[stud_index]));

        while (coll_index != -1)
        /* if coll_index reaches -1, the student has gone through all his options, thus he's left unassigned to any college */
        {
            returned_value = college_addstudent(&(coll_vec[coll_index]), stud_index, stud_grade);

            if(returned_value == stud_index)
            /* if returned index equals to stud_index, then the student was not admitted. we get the next option on his list */
            {
                coll_index = student_getbestoption(&(stud_vec[stud_index]));
            }
            else
            /* the student was admitted. now we need to check if some other student was kicked out of the college */
            {
                student_assign(&(stud_vec[stud_index]), coll_index);

                if (returned_value != SUCCESS)
                /* some student was kicked out, so we need to add him to the proposal stack */
                {
                    student_assign(&(stud_vec[returned_value]), UNASSIGNED);
                    proposalstack_push(&prop_stack, returned_value);
                }
                break;
            }
        }
        stud_index = proposalstack_pop(&prop_stack);
    }

    int temp;
    printf("Grupos com alocacao\n");
    for (i = 0; i < num_students; i++)
    {
        temp = student_studyat(&(stud_vec[i]));
        if (temp != UNASSIGNED)
        {
            /* adds 1 because index 0 corresponds to student/college 1 */
            printf("%d %d\n", i + 1, temp + 1);
        }
    }

    printf("Candidatos nao alocados\n");
    for (i = 0; i < num_students; i++)
    {
        temp = student_studyat(&(stud_vec[i]));
        if (temp == UNASSIGNED)
        {
            /* adds 1 because index 0 corresponds to student 1 */
            printf("%d\n", i + 1);
        }
    }

    for (i = 0; i < num_students; i++)
    {
        /* frees from the heap the priority stacks that are not already empty */
        student_deleteinstance(&(stud_vec[i]));
    }

    for (i = 0; i < num_colleges; i++)
    {
        /* frees from the heap the student lists */
        college_deleteinstance(&(coll_vec[i]));
    }

     /* we don't need to empty the proposals stack, because the algorithm only ends when the stack is empty */
    return 0;
}
