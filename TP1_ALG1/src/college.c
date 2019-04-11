#include "college.h"
#include <stdio.h>
#include <stdlib.h>

college college_createinstance(int _min_grade, int _max_num_of_students)
{
    college new_instance;
    new_instance.max_num_of_students = _max_num_of_students;
    new_instance.min_grade = _min_grade;
    new_instance.header = studentlist_create();
    return new_instance;
}


int college_addstudent(college* instance, int student_index, int student_grade)
{
    if (student_grade >= instance->min_grade)
    {
        return studentlist_insert(&(instance->header), student_index, student_grade, instance->max_num_of_students);
    }

    return student_index;
}

void college_print(college* instance)
{
    studentlist_print(&(instance->header));
}

void college_deleteinstance(college* instance)
{
    studentlist_emptylist(&(instance->header));
}
