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
ejecute vmmap

- segmento de texto
  DV : 100814000-100818000
  TV : 16 KB

- segmento de datos
  DV: 100818000-10081c000
  TV: 16KB

- heap → memoria dinámica
  DV:         
  133800000-13b800000   
  13b800000-143800000    
  143800000-14b800000   
  14b800000-153800000    
  153800000-15b800000    
  15b800000-163800000   
  163800000-166180000 
  TV: 937.5M
  
- stack → pila 
  DV: 16b5ec000-16edf0000
  TV: 56 MB

### f. i
Coincide aproximadamente la cantidad de memoria virtual utilizada que la que se reservo.
  
## Ejercicio 2
### a. 
El tiempo de ejecucion de la version 2 es de 2,26s
El tiempo de ejecucion de la version 3 es de 4,15s



## Ejercicio 3.

La fragmentación es cuando:  
Se asigna una unidad fija de memoria (una página, por ejemplo 4 KB), pero el proceso solo necesita una parte de ella.
Ejemplo: si se asigna una página de 4 KB pero solo se usan 2 KB, los 2 KB restantes están desperdiciados.
