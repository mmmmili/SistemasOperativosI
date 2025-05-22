# 📍 Trabajo Practico 4 
## 📚 Ejercicio 1
📃 Como la camara de fotos almacena datos que no van a cambiar de tamaño a lo largo del tiempo es conveniente utilizar un gestor de archivos de bloques contigua ya que con este metodo 
no necesitamos contemplar que un archivo crezca de tamaño
## 📚 Ejercicio 2
### 📌 a.
Partiendo del directorio raiz, 
`1` el primer acceso sera para buscar a `export` en su lista de archivos (i-nodos),  
`2` se accedera al bloque de export,
`3` se buscara `home` en su lista de archivos
`4` se accedera al bloque de home,
`5` se buscara `alumno` en su lista de inodos,
`6` se accedera al archivo. 
`7` se buscara el archivo `so` y 
`8` se accedera a so
`9` se encuentra el archivo `tareas.txt`

### 📌 b. 

Tamaño total del archivo: 

- Cantidad de punteros en un bloque:
  1 puntero son 32 bits (4B)
  1 puntero --- 4B
1024 punteros  = ---  4096B (4KB)

- Direct:  12 x 4KB = 49.152 KB
- Double: 1024 KB x 1024 KB x 4KB = 1.048.576 x 4 = 4.194.304 KB
Total = 4.194.304 KB + 49.152 = 4GB

## Ejercicio 3
### a.
1. Leer el Boot Sector que contiene informacion basica sobre el sistema de archivos como: el tipo de fat,el numero de sectores reservados, ubicacion de la fat
   ubicacion del directorio raiz.
2. Acceder al directorio raiz que se comporta como un directorio normal
3. Buscar la entrada fotos en el directorio raiz. El sistema lee secuencialmente las entradas del directorio raiz. Cada entrada tiene nombre, atributos, hora/fecha, y numero del primer cluster. Si encuentra una entrada con nombre `fotos`, verifica que sea un subdirectorio.
4. Acceder al contenido del subdirectorio `fotos`. Usando el numero de cluster inicial, accede al area de datos. Lee la fat para encontrar todoso los clusters que pertenecen al subdirectorio fotos. En esa area busca la entrada `barilo`
5. Acceder al subdirectorio `barilo`. Nuevamente usa el numero de cluster inicial para barilo para acceder a sus contenidos.
6. Buscar el archivo `plaza.jpg` y si la encuentra se obtiene el numero de cluster inicial y el tamaño del archivo, el archivo existe y puede abrirse.
7. Si no se encuentra el archivo en cualquiera de los pasos, el sistema retorna error
### b. 




