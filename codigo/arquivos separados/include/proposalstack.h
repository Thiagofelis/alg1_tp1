#ifndef PROPOSALSTACK_H_INCLUDED
#define PROPOSALSTACK_H_INCLUDED

#define LIST_HEADER -1
#define END 0

typedef struct proposalstack
{
    int index;
    struct proposalstack* next;
} proposalstack;

proposalstack proposalstack_build (int number_of_cells);

int proposalstack_pop (proposalstack* header);

void proposalstack_push (proposalstack* header, int i);

#endif // PROPOSALSTACK_H_INCLUDED
