# Preguntas Teóricas


## 🔐 
### Las arquitecturas de microprocesadores modernas traen una instrucción por hardware llamada test-and-set(las que no traen para el mismo fin compare-and-swap). Explique una de las dos, para qué se utiliza, y de un ejemplo.
Test-and-Set es una instrucción atómica que permite implementar exclusión mutua.

- Lee una variable y la modifica en una sola operación atómica.
- Se usa para evitar condiciones de carrera.

  Ejemplo: 
```c
  bool test_and_set(bool *lock) {
    bool old = *lock;
    *lock = true;
    return old;
}
```


 ## 📜
 ### Explique por qué es importante POSIX. Justifique con un ejemplo.
 POSIX estandariza la interfaz entre aplicaciones y sistemas operativos tipo Unix.

-  Facilita la portabilidad de programas.

- Ej: fork(), open(), pthread_create() funcionan en Linux, macOS, BSD, etc.


 


##  Las prácticas de la materia deberían hacerse en Android y Windows, que son mas utilizados; XINU no puede ser utilizado fuera del ambiente académico. Defienda o critique la frase (o defienda y critique). Justificar.


## ¿Qué diferencia existe entre un sistema embebido y un sistema de tiempo real?.


 ## ¿Qué dificultad existe al momento de desarrollar un sistema operativo con arquitectura de microkernel?


## Se dice que los sistemas operativos definen y presentan a las aplicaciones una serie de “abstracciones”, y operaciones primitivas sobre esas abstracciones. ¿Qué significa esta sentencia?. ¿Qué tiene que ver con la definición de sistemas operativos, el control del hardware, y los servicios que proveen (los sistemas operativos)?. Justifique.


## ¿Cuándo y por qué un sistema operativo cambiaría un proceso de Listo a Listo suspendido?. ¿O de bloqueado a Bloqueado suspendido?.


## Describa un cambio de contexto (que es, para qué sirve, cómo se implementa, etc). Relacione en su respuesta con el modo kernel y modo usuario del procesador, ISR, organización de la memoria de la computadora. Justificar.



## Existen a nivel teórico, dos mecanismos de comunicación entre procesos. ¿Cuáles son? ¿Qué relación tienen las llamadas al sistema con estos mecanismos? ¿Qué mecanismo se utiliza generalmente en sistemas distribuidos?

## ¿Cuál es la motivación de la existencia de las llamadas al sistema?(syscalls)

## ¿Cómo se relaciona el PCB con otras estructuras de datos de los procesos de un sistema operativo? ilustre su respuesta con algunos ejemplos

## ¿Cómo interactúan el administrador de memoria y el administrador de disco en un sistema operativo? Justificar con ejemplos ilustrativos

