#ifndef STUDENTLIST_H_INCLUDED
#define STUDENTLIST_H_INCLUDED

#define SUCCESS -1
#define END 0

typedef struct studentlist
{
    int index;
    int grade;
    struct studentlist* next;
} studentlist;

int studentlist_insert(studentlist* header, int student_index, int student_grade, int max_size, int* occupied_places);

studentlist studentlist_create();

void studentlist_emptylist(studentlist* header);

void studentlist_print(studentlist* header);

#endif // STUDENTLIST_H_INCLUDED
