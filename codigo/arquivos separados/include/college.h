#ifndef COLLEGE_H_INCLUDED
#define COLLEGE_H_INCLUDED

#include "studentlist.h"

typedef struct college
{
    int min_grade;
    int max_num_of_students;
    studentlist header;
} college;

college college_createinstance(int _min_grade, int _max_num_of_students);

int college_addstudent(college* instance, int student_index, int student_grade);

void college_print(college* instace);

void college_deleteinstance(college* instance);

#endif // COLLEGE_H_INCLUDED
