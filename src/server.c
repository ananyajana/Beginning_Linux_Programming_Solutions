#include "client.h"
#include <ctype.h>

int main()
{
	int server_fifo_id, client_fifo_id;
	struct data_to_pass_st my_data;
	int read_res;
	char client_fifo[256];
	char* tmp_char_ptr;

	mkfifo(SERVER_FIFO_NAME, 0777);
	server_fifo_id = open(SERVER_FIFO_NAME, O_RDONLY);
	if(server_fifo_id == -1){
		fprintf(stderr,  "Server fifo failure\n");
		exit(EXIT_FAILURE);
	}

	sleep(10);	// lets clients queue for demo purposes

	do{
		read_res = read(server_fifo_id, &my_data, sizeof(my_data));
		if(read_res > 0){
			tmp_char_ptr = my_data.some_data;
			while(*tmp_char_ptr){
				*tmp_char_ptr = toupper(*tmp_char_ptr);
				tmp_char_ptr++;
			}

			sprintf(client_fifo, CLIENT_FIFO_NAME, my_data.client_pid);

			client_fifo_id = open(client_fifo, O_WRONLY);
			if(client_fifo_id != -1){
				write(client_fifo_id, &my_data, sizeof(my_data));
			        close(client_fifo_id);
			}
		}
	} while(read_res > 0);
	close(server_fifo_id);
	unlink(SERVER_FIFO_NAME);
	exit(EXIT_SUCCESS);
}
