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

### 1. Version con peor rendimiento
La versión 1  tiene el peor rendimiento con 21,01 segundos. Es la que tiene mayor fallos de TLB y de Cache de datos, esto se debe a que su recorrido se realiza por columnas, primero avanza en j y dsp en i. cada cambio en i implica saltar una pagina. Este patron de acceso rompe la localidad espacial y fuerza el uso de usar muchas paginas diferentes, por lo que aumenta los fallos de tlb y reduce la efectividad de la cache, esto genera un mal rendimiento.

### 2. 
La version 2 tiene el mejor rendimiento con 5,22 segundos. Esta version recorre la memoria por filas, esto aprovecha la localidad espacial ya que se accede a datos contiguos y tambien reduce los fallos de TLB ya que cada pagina se utiliza completamente antes de pasar a la otra. Como su recorrido es eficiente en cuanto a fallos de cache y de TLB tiene un mejor rendimiento.

### 3. 
Versión 2 (mejor) accede por filas completas, lo que maximiza la localidad de caché y minimiza los fallos de la TLB.

Versión 3 (rendimiento intermedio) accede por bloques verticales: accede a 4 columnas a la vez, luego salta, y repite.

Como resultado la version 3 tiene menos cache misses que la version 1 pero aun asi accede de manera entrecortada a las paginas lo que genera mas fallos de cache que la version 2. 

Conclusion: la forma de recorrer la memoria tiene impacto en el uso de la tlb y cache , mientras mas localizada y secuencial sea la lectura el programa tendra mejor rendimiento 

## Ejercicio 3.

## Direcciones virtuales en arquitectura AMD64 (x86-64) con páginas de 4KB

En un sistema Linux actual que corre sobre procesadores Intel/AMD con arquitectura **AMD64**, se utiliza un esquema de **paginación jerárquica de 4 niveles** cuando el tamaño de página es de **4 KB**.

### 🧠 Estructura de una dirección virtual (48 bits)

Una dirección virtual de 48 bits se divide en campos que corresponden a los distintos niveles de la jerarquía de traducción:

| Bits       | Nombre del nivel                      | Descripción                          |
|------------|----------------------------------------|--------------------------------------|
| 47 – 39    | **PML4** (Page Map Level 4)            | Índice en la tabla PML4              |
| 38 – 30    | **PDPT** (Page Directory Pointer Table)| Índice en la tabla PDPT              |
| 29 – 21    | **PD** (Page Directory)                | Índice en el directorio de páginas   |
| 20 – 12    | **PT** (Page Table)                    | Índice en la tabla de páginas        |
| 11 – 0     | **Offset** dentro de la página         | Desplazamiento dentro de la página   |

Cada uno de estos niveles contiene **512 entradas**, ya que cada índice tiene 9 bits (2⁹ = 512).

---

### 📦 Tamaño de las tablas de páginas

Todas las tablas involucradas en el proceso de traducción (PML4, PDPT, PD, PT) tienen las siguientes características:

- **Cantidad de entradas:** 512
- **Tamaño de cada entrada:** 8 bytes (64 bits)
- **Tamaño total de cada tabla:** `512 × 8 = 4096 bytes = 4 KB`

---

### ✅ Nombres y tamaños según AMD Programmer's Manual

| Nivel | Nombre (según AMD)              | Tamaño | Entradas |
|-------|----------------------------------|--------|----------|
| 1     | Page Table                       | 4 KB   | 512      |
| 2     | Page Directory Table             | 4 KB   | 512      |
| 3     | Page Directory Pointer Table     | 4 KB   | 512      |
| 4     | Page Map Level 4 Table (PML4)    | 4 KB   | 512      |

---

> 📌 Nota: Aunque la arquitectura define direcciones de 64 bits, los sistemas actuales usan solo 48 bits efectivos. Los 16 bits superiores deben ser una extensión del bit 47 (extensión de signo), por lo que las direcciones virtuales válidas están en el rango de ±2⁴⁷.

### ¿Cuántos bits realmente se utilizan de la dirección virtual?

Actualmente, se utilizan **48 bits** de los 64 posibles. Esto permite direccionar hasta 256 TiB (2⁴⁸ bytes) de espacio de direcciones virtuales.

### ¿Cuál es el tamaño máximo de memoria virtual que un proceso puede utilizar?

El tamaño máximo es **2⁴⁸ bytes = 256 TiB** (teóricos), aunque en la práctica, los sistemas operativos limitan este valor. Por ejemplo, Linux puede reservar menos dependiendo de la configuración del kernel y de la arquitectura específica.

---

### ¿Cómo es posible que un proceso funcione si el tamaño de memoria virtual que utiliza es mayor que la memoria física?

Gracias a la **memoria virtual** y al uso de mecanismos como:

- **Paginación bajo demanda**: solo se cargan en memoria física las páginas que realmente se usan.
- **Swapping**: páginas no utilizadas se almacenan temporalmente en disco.
- **TLB y MMU**: permiten que el sistema operativo gestione dinámicamente la traducción entre direcciones virtuales y físicas.

Esto permite que un proceso vea un espacio de memoria continuo mucho mayor que la memoria física disponible.

---

### Sea un proceso que utiliza un total de 128 MB de memoria en este sistema.  
**¿Cuántas páginas necesita cargar el SO para que el proceso comience a ejecutarse?**

Si el proceso usa 128 MB de memoria y cada página tiene 4 KB:

\[
\frac{128\ \text{MB}}{4\ \text{KB}} = \frac{128 \times 2^{20}}{4 \times 2^{10}} = 32,768\ \text{páginas}
\]

Sin embargo, **el sistema operativo no necesita cargar todas esas páginas al inicio**. Con **paginación bajo demanda**, solo necesita cargar:

- Las **páginas que contienen el código inicial (por ejemplo, main)**.
- Las estructuras necesarias para comenzar la ejecución (stack, heap mínimo, etc.).
- Las tablas de páginas correspondientes.

Esto puede significar que bastan con unas **decenas de páginas** reales cargadas inicialmente.


La fragmentación es cuando:  
Se asigna una unidad fija de memoria (una página, por ejemplo 4 KB), pero el proceso solo necesita una parte de ella.
Ejemplo: si se asigna una página de 4 KB pero solo se usan 2 KB, los 2 KB restantes están desperdiciados.
