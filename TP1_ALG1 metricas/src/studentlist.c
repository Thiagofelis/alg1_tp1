#include "studentlist.h"
#include <stdio.h>
#include <stdlib.h>

int studentlist_insert(studentlist* header, int student_index, int student_grade, int max_size, int* occupied_places)
{
    int i;
    studentlist* temp = header;
    for(i = 0; i < max_size; i++)
    {
        if(temp->next == END)
        { /* there is room, so we insert */
            temp->next = malloc(sizeof(studentlist));
            temp->next->next = END;
            temp->next->index = student_index;
            temp->next->grade = student_grade;
            *occupied_places = (*occupied_places) + 1;
            return SUCCESS;
        }
        else
        {
            if ((temp->next->grade < student_grade) ||
/* tie criteria => */ ((temp->next->grade == student_grade) && (student_index < temp->next->index)))
            { /* we swap the current student in the list with the new one */
                int temp1, temp2;
                temp1 = temp->next->grade;
                temp2 = temp->next->index;
                temp->next->grade = student_grade;
                temp->next->index = student_index;
                student_grade = temp1;
                student_index = temp2;
              /* and we continue the search, to try to reallocate the old student in the list */
            }
            temp = temp->next;
        }
    }

    /* it's important we return the index, cause if the index we returned
       is different from the index of the student we tried to insert, we need
       to add the student that was kicked out to the proposal stack
     */
    return student_index;
}

studentlist studentlist_create()
{
    studentlist header;
    header.grade = -1;
    header.index = -1;
    header.next = 0;
    return header;
}

void studentlist_emptylist(studentlist* header)
{
    studentlist* temp;
    while (header->next != END)
    {
        temp = header->next;
        header->next = header->next->next;
        free(temp);
    }
}

void studentlist_print(studentlist* header)
{
    studentlist* temp = header;
    while(temp->next != 0)
    {
        temp = temp->next;
        printf ("(%d,%d) ", temp->index, temp->grade);
    }
    printf ("end\n");
}
