#include "collegestack.h"
#include "students.h"
#include <stdio.h>
#include <stdlib.h>

student student_createinstance(int grade_number, int number_of_options, int* college_options)
{
    student new_instance;
    new_instance.grade = grade_number;
    new_instance.study_at = UNASSIGNED;

    new_instance.priority_list_header = collegestack_create(number_of_options, college_options);

    return new_instance;
}

int student_getbestoption(student* pointer)
{
    return collegestack_pop(&(pointer->priority_list_header));
}

void student_assign(student* pointer, int college)
{
    pointer->study_at = college;
}

int student_studyat(student* pointer)
{
    return pointer->study_at;
}

int student_getgrade(student* pointer)
{
    return pointer->grade;
}

void student_deleteinstance(student* pointer)
{
    collegestack_emptylist(&(pointer->priority_list_header));
}
