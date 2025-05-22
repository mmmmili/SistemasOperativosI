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
