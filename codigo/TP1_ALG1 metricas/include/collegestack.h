#ifndef COLLEGESTACK_H_INCLUDED
#define COLLEGESTACK_H_INCLUDED

#define LIST_HEADER -1
#define END 0

typedef struct collegestack_cell
{
    int college_index;
    struct collegestack_cell* next_cell;
} collegestack_cell;

collegestack_cell collegestack_create (int list_size, int* elements);

int collegestack_pop (collegestack_cell* header);

void collegestack_emptylist(collegestack_cell* header);

void collegestack_print(collegestack_cell* header);


#endif // COLLEGESTACK_H_INCLUDED
