#include <stdlib.h>
#include <stdio.h>

/**
 ***************************************************************
 * 
 **************************************************************/

struct PCB
{
	jmp buffer jmp_buffer;
	int PCB_status;
	int PCB_id;
	int PCB_priority;
	msq_q *msg_q;
	int *PC;
	//PCB *address;
};

struct PCB_dll
{
	PCB_node *head;
	PCB_node *tail;
};

struct PCB_node
{
	PCB_node *next;
	PCB_node *prev;
	PCB *node_data;
};

struct msg_env
{
	int type;
	char data[ENVELOPE_SIZE];
	int sender_ID;
	int recipient_ID;
	
};

struct msg_q
{
	msg_node *next;
	msg_node *prev;
};

struct msg_node
{
	msg_node *next;
	msg_node *prev;
	msg_env *msg_data;
};
