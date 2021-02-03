#include <stdio.h>
#include <stdlib.h>
#include "../include/proposalstack.h"

proposalstack proposalstack_build (int number_of_cells)
{
    proposalstack header;
    header.index = LIST_HEADER;
    proposalstack* temp = &header;
    proposalstack* temp2;

    int i;
    for (i = 0; i < number_of_cells; i++)
    {
        temp2 = malloc(sizeof(proposalstack));
        temp->next = temp2;

        temp2->index = i;
        temp = temp2;
    }

    temp->next = END;

    return header;
}

int proposalstack_pop (proposalstack* header)
{
    if (header->next == END)
    {
        return -1;
    }
    proposalstack* temp = header->next;
    int i = header->next->index;
    header->next = header->next->next;
    free(temp);
    return i;
}

void proposalstack_push (proposalstack* header, int i)
{
    proposalstack* temp = header->next;
    header->next = malloc(sizeof(proposalstack));
    header->next->next = temp;
    header->next->index = i;
}

