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
El tiempo de ejecucion de la version 1 es de 21,01s
El tiempo de ejecucion de la version 2 es de 5,22s
El tiempo de ejecucion de la version 3 es de 8,55s

### b.
Version 1: 
Performance counter stats for './ej1':

       995.670.045      dTLB-store-misses                                          
     1.008.933.732      cache-misses                                                

      21,008444547 seconds time elapsed

      20,657441000 seconds user
       0,327642000 seconds sys
Version 2: 
Performance counter stats for './v2':

         1.602.284      dTLB-store-misses                                          
        16.324.885      cache-misses                                                

       5,216423308 seconds time elapsed

       4,919403000 seconds user
       0,291727000 seconds sys

Version 3: 
Performance counter stats for './v3':

       260.845.787      dTLB-store-misses                                          
       270.903.691      cache-misses                                                

       8,554540110 seconds time elapsed

       8,251713000 seconds user
       0,287711000 seconds sys

  ### 📊 Resumen de rendimiento (perf)

| Versión   | `dTLB-store-misses`     | `cache-misses`        | Tiempo total (s) |
|-----------|--------------------------|------------------------|------------------|
| Versión 1 | 995.670.045              | 1.008.933.732          | 21,01            |
| Versión 2 | 1.602.284                | 16.324.885             | 5,22             |
| Versión 3 | 260.845.787              | 270.903.691            | 8,55             |


🔹 La TLB (Translation Locaside Buffer) es una cache que se encuentra dentro de la MMU (Memory Managment Unit) y que almacena traducciones recientes de direcciones virtuales a direcciones físicas. Contiene parte de la tabla de paginas del proceso que se esta ejecutando. Se utiliza para acelerar el proceso de traducción de direcciones de memoria en sistemas con memoria virtual, si la TLB tiene la pagina q se necesita se produce un hit sino es un fallo.
🔹  La Cache de Datos es una memoria rapida que se encuentra dentro del procesador y que almacena datos frecuentemente usados. Contiene datos que el procesador accede frecuenemente, suele estar dividida en varios niveles. Y se utiliza para reducir el tiempo de acceso a los datos que estan en RAM.

### 1. 

## Ejercicio 3.

La fragmentación es cuando:  
Se asigna una unidad fija de memoria (una página, por ejemplo 4 KB), pero el proceso solo necesita una parte de ella.
Ejemplo: si se asigna una página de 4 KB pero solo se usan 2 KB, los 2 KB restantes están desperdiciados.
