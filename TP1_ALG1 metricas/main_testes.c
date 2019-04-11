#include <stdio.h>
#include <stdlib.h>
#include "collegestack.h"
#include "students.h"
#include "proposalstack.h"
#include "college.h"


int _main()
{
    college col = college_createinstance(10, 4);

    /*  0   1   2   3   4   5   6   7   8   9   10  11  12
        42  12  9   0   12  4   54  2   1   78  101 6   13*/

    college_print(&col);

    printf("%d ",  college_addstudent(&col, 1, 12));
    college_print(&col);

    printf("%d ",  college_addstudent(&col, 3, 0));
    college_print(&col);

    printf("%d ",  college_addstudent(&col, 6, 54));
    college_print(&col);

    printf("%d ",  college_addstudent(&col, 0, 42));
    college_print(&col);

    printf("%d ",  college_addstudent(&col, 7, 2));
    college_print(&col);

    printf("%d ",  college_addstudent(&col, 5, 4));
    college_print(&col);

    printf("%d ",  college_addstudent(&col, 4, 12));
    college_print(&col);

    printf("%d ",  college_addstudent(&col, 2, 9));
    college_print(&col);

    printf("%d ",  college_addstudent(&col, 8, 1));
    college_print(&col);

    printf("%d ",  college_addstudent(&col, 9, 78));
    college_print(&col);

    printf("%d ",  college_addstudent(&col, 10, 101));
    college_print(&col);

    printf("%d ",  college_addstudent(&col, 11, 6));
    college_print(&col);

    printf("%d ",  college_addstudent(&col, 12, 13));
    college_print(&col);



/*
    proposalstack header = proposalstack_build(5);

    printf("\n%d\n",  proposalstack_pop(&header));

    printf("\n%d\n",  proposalstack_pop(&header));

    proposalstack_push(&header, 8);

    proposalstack_push(&header, 81);


    printf("\n%d\n",  proposalstack_pop(&header));

    printf("\n%d\n",  proposalstack_pop(&header));

    printf("\n%d\n",  proposalstack_pop(&header));

    printf("\n%d\n",  proposalstack_pop(&header));

    printf("\n%d\n",  proposalstack_pop(&header));

    printf("\n%d\n",  proposalstack_pop(&header));

    printf("\n%d\n",  proposalstack_pop(&header));

    printf("\n%d\n",  proposalstack_pop(&header));



    int vec[3] = {4, 6, 1};
    student instance = student_createinstance(20, 3, vec);

    printf("\n%d\n", student_studyat(&instance));

    student_assign(&instance, 8);

    printf("\n%d\n", student_studyat(&instance));



    printf("\n%d\n", student_getbestoption(&instance));

    printf("\n%d\n", student_getbestoption(&instance));

    printf("\n%d\n", student_getbestoption(&instance));

    printf("\n%d\n", student_getbestoption(&instance));


    student_assign(&instance, 2);

    printf("\n%d\n", student_studyat(&instance));


    int vec[6] = {4, 6, 1, 8, 3, 9};
    collegestack_cell header = collegestack_create(6, vec);
    printf("Hello world!\n");
    collegestack_cell* temp = &header;

    while (temp != END){
        printf("%d ", temp->college_index);
        temp = temp->next_cell;
    }
    printf("\n%d\n", collegestack_pop(&header));

    temp = &header;
    while (temp != END){
        printf("%d ", temp->college_index);
        temp = temp->next_cell;
    }
*/
    return 0;
}
