#include "../include/collegestack.h"
#include <stdio.h>
#include <stdlib.h>

collegestack_cell collegestack_create (int list_size, int* elements)
{
    collegestack_cell header;

    header.college_index = LIST_HEADER;

    int i;
    collegestack_cell* temp = &header;
    collegestack_cell* temp2;

    for (i = 0; i < list_size; i++)
    {
        temp2 = malloc(sizeof(collegestack_cell));
        temp->next_cell = temp2;

        temp2->college_index = elements[i];
        temp = temp2;

    }
    temp->next_cell = END;

    return header;
}

void collegestack_emptylist(collegestack_cell* header)
{
    collegestack_cell* temp;
    while (header->next_cell != END)
    {
        temp = header->next_cell;
        header->next_cell = header->next_cell->next_cell;
        free(temp);
    }
}

int collegestack_pop (collegestack_cell* header)
{
    if (header->next_cell == END)
    {
        return -1;
    }
    collegestack_cell* temp = header->next_cell;
    int i = header->next_cell->college_index;
    header->next_cell = header->next_cell->next_cell;
    free(temp);
    return i;
}

void collegestack_print(collegestack_cell* header)
{
    collegestack_cell* temp = header;
    while(temp->next_cell != 0)
    {
        temp = temp->next_cell;
        printf ("(%d) ", temp->college_index);
    }
    printf ("end\n");
}
