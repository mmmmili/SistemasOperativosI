# Trabajo Practico 5 - Gestion de Memoria
## Ejercicio 1
### a. 
El programa define `N = 240000` y `BSIZE = 4096`, por lo que la cantidad total de memoria solicitada es:
`N * BSIZE` = `240000 * 4096` = `983,040,000` bytes
### b. 
El tiempo de ejecucion, utilizando el comando `time` es de 8,61 segundos
### c. 
- la variable `pp` es global por lo que se almacena en el segmento de datos
- las variables `i,j,k` son locales de la funcion main() por lo que se almacena en la pila (stack)

### d.
la memoria asignada por `malloc` se ubica en el segmento heap, que es parecido al stack pero esta en direcciones mas bajas y crece hacia direcciones mas altas

### e.
Agregando estas lineas al comienzo del main
```
printf("Dirección de main: %p\n", (void*)main);
printf("Dirección de i: %p\n", (void*)&i);
printf("Dirección de j: %p\n", (void*)&j);
```
Obtengo:
```
Dirección de main: 0x100947d24
Dirección de i: 0x16f4bb0c8
Dirección de j: 0x16f4bb0c4
```

### f.

r-xp → segmento ejecutable (text)

rw-p → segmento de datos (data) o heap

[heap] → memoria dinámica (malloc)

[stack] → pila (donde están i, j, k)

## Ejercicio 2
