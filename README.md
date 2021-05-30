# Syscalls  
Este es un programa que utiliza funciones wrappers como open(), read() y write()  
para mostrar contenidos de archivos por stdout, ademas de leer contenido de stdin  
y mostrarlos tambien en stdout.  

## Compilacion  
Para compilar el programa:  
```bash
make
```
Para hacer clean:  
```bash
make clean
```

## Uso
Para ejecutar el programa:  
```bash
./mycat filename
```

Para leer desde stdin:
```bash
sort filename | ./mycat
```
