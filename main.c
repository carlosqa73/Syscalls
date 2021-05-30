#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>


int main(int argc, char* argv[]){

	if(argc > 3){
		fprintf(stderr, "Error de uso: ./mycat filename\n");
		exit(EXIT_FAILURE);
	}


	char buff[1024];
	int bytes;

	if(argc == 1){			//Se asume que este caso es cuando se utiliza pipe
		bytes = read(0, buff, 1024);
		write(1, buff, bytes);
		return 0;
	}

	else{

		int fd = open(argv[1], O_RDONLY);

		if(fd == -1){
			perror("Error al abrir el archivo\n");
			exit(EXIT_FAILURE);
		}
		//bytes = read(fd, argv[1], 1000);
		//close(fd);
		while((bytes = read(fd, buff, 1024)) > 0){
			write(1, buff, bytes);			//El 1 es stdout
		}
		close(fd);
	}

	//printf("Se leyeron %d bytes\n", bytes);
}
