/****************************************************************************
* Function Name      : kb_i_process
******************************************************************************
* Description   : This process takes messages from the CCI and timer, and 
*: places them in the output buffer. This process gets the CPU 
*: when it receives a signal from the UNIX CRT process, which 
*: only occurs when the buffer is empty. After this data has been
*: sent, the RTX primitive (send_console_chars, which actually 
*: writes the data into share memory) sends back an envelope of 
*: type DISPLAY_ACK. This means that the data has been written 
*: to the shared memory, and not necessarily that is has been 
*: outputted to the CPU. This is important to know for debugging 
*: purposes. 
*/

void kb_i_process() {
	if (kb_i_process_PID->msg.q->head != NULL){
		msg_env *env = kb_i_process_PID->msg.q->head;
		int invoking_process = env[1];
	}
	while(kb_com_mem->data[i] != “/n” || i==MEMORY_SIZE-1){ 
    /**** We don't want to over-write the flag bit ****/
        env->data[i] = KB_mmap[i];
        i++;
    }
    env->type = CONSOLE_INPUT;
    message_send(invoking_process_PCB_ID, env);
}
/****************************************************************************
* Function Name      : crt_i_process
******************************************************************************
* Description   : This process takes messages an sends it to the console if it is 
*: a certain type. This means that the data has been written 
*: to the shared memory, and not necessarily that is has been 
*: outputted to the CPU. This is important to know for debugging 
*: purposes. 
*/
void crt_i_process() {
	if(crt_com_mem_>ok_flag==0){ // If the buffer is empty
		 /**Get a message. Returns Null if no messages**/
         msg_env *env = msg_env K_message_receive();   
    	if(env->type == CONSOLE_OUTPUT && message_recieved) {
    		/**If the message type is right(ie. Not Null.**/
        	K_send_console_chars(env);
        	crt_com_mem->ok_flag=1;
    	}
    }  
    else if(env->type == DISPLAY_ACK)   
             K_release_msg_env(env);
    return;
}

