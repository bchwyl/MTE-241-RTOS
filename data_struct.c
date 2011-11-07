#include <stdio.h>
#include <stdlib.h>
//#include message_q business 

#define ENVELOPE_SIZE 1024;

/**
 ***************************************************************
 * 
 **************************************************************/
 

struct *PCB dequeue(struct PCB_dll *target)
{
	if(*target != NULL)
	{
		PCB_node *temp = target->tail;
		target->tail = temp->prev;
		target->tail->next = NULL;
		return target->data;
	}
	else
		return NULL;
	
}

int enqueue(struct PCB_dll *target, PCB *new_pcb)
{
	if(*target != NULL && *new_pcb != NULL)
	{
		PCB_node *new_node;
		new_node->data = new_pcb;
		target->head->previous = new_node;
		new_node->next = target->head;
		new_node->prev = target->head;
		target->head = new_node;
	}
	else
		return 0;

	return 1; 
	
}

struct *msg_env dequeue(struct msg_q *target)
{
	
}
