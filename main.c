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
		bytes = read(0, buff, 1024);		//Se lee desde stdin
		if(bytes == -1){
			perror("Error al leer desde stdin\n");
			exit(EXIT_FAILURE);
		}
		write(1, buff, bytes);			//Se escribe en stdout
		return 0;
	}

	else{

		int fd = open(argv[1], O_RDONLY);		//Se abre el archivo

		if(fd == -1){					//Si el descriptor es -1 entonces hubo un error en open
			perror("Error al abrir el archivo\n");
			exit(EXIT_FAILURE);
		}
		//bytes = read(fd, argv[1], 1000);
		//close(fd);
		while((bytes = read(fd, buff, 1024)) > 0){
			write(1, buff, bytes);			//Se escribe en stdout
		}
		close(fd);
	}

	//printf("Se leyeron %d bytes\n", bytes);
}
