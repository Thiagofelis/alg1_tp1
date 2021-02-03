#ifndef STUDENTS_H_INCLUDED
#define STUDENTS_H_INCLUDED

#define UNASSIGNED -1
#define DELETED -2

#include "collegestack.h"

typedef struct student
{
    int grade;
    int posicao_universidade;
    int study_at;
    collegestack_cell priority_list_header;
} student;

student student_createinstance(int grade_number, int number_of_options, int* college_options);

int student_getbestoption(student* pointer);

void student_assign(student* pointer, int college);

int student_studyat(student* pointer);

int student_getgrade(student* pointer);

void student_deleteinstance(student* pointer);

#endif // STUDENTS_H_INCLUDED
