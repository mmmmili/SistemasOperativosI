# Trabajo Practico 2
## Ejercicio 1
### `suspend(pid)`
Este system call se usa para suspender (pausar) la ejecución de un proceso identificado por su PID (Process ID). Cuando se llama a suspend(pid) el proceso pasa de estado LISTO a estado 
SUSPENDIDO y no se le asignara la CPU hasta que sea reactivado. Sirve para detener un proceso sin matarlo ni eliminarlo.
### `resume(pid)`
Este syscall reactiva un proceso que fue suspendido con suspend(pid).Cambia de estado SUSPENDIDO a lISTO y la CPU puede volver a ejecutarlo. Se utiliza para reanudar la ejecucion de un proceso que fue pausado temporalmente
### `getprio(pid)`
Este syscall se utiliza para consultar la prioridad actual de un proceso en ejecucion o espera. Devuelve un numero entero >= 0 que representa la prioridad del proceso y si el pid es inválido o el proceso no existe, devuelve SYSERR (-1)
### `chprio(pid, newprio)`
Este syscall cambia la prioridad de un proceso al nuevo valor newprio. Se utiliza para modificar dinamicamente el orden de ejecucion de los procesos. Retorna la prioridad anterior del proceso
### `getpid()`
Este syscall devuelve el PID del proceso que lo esta llamando.
### `sleepms(ms)`
Bloquea (duerme) el proceso actual durante una cantidad de milisegundos y libera la CPU para que otros procesos se puedan ejecutar mientras tanto 


### a)  ¿Se puede hacer un suspend(pid) del proceso pid estando el proceso pid en estado “sleeping”?
No se puede hacer suspend(pid) a un proceso en estado sleeping, solo se puede hacer a procesos que esten en estado LISTO o EJCUTANTO

### b) ¿cuánto vale el quantum en XINU?. ¿Que problema o comportamiento puede haber si usted cambia el quantum a 100ms?
El QUANTUM en XINU es de 2 ms, si lo cambiaramos a 100 ms el sistema tiempo compartido se pierde ya que esta ilusion de que todos los programas estan ejecutandose en paralelo no sucederia. ej: el que toma la cpu es el relok, no se podria utilizar ningun otro programa hasta que el reloj no termine su quantum y devuelva la cpu

### c) Investigue cómo se llaman y cómo funcionan los algoritmos de planificación de procesos del sistema operativo Windows y Linux. Redacte una respuesta-aprendizaje. Esto implica: no buscar en google/chatgpt y sólo copiar y pegar. Intente dar una explicación general.
La planificacion en UNIX emplea colas multinivel usando Round Robin en cada una. La prioridad se ajusta dinamicamente para implementar "envejecimiento" cuando el proceso espera, para evitar la inanicion.
La planificacion en UNIX propone un tiempo constante de orden O(1). Tiene mecanismos de afinidad al procesador y equilibrado de carga, asu como un reparto equitativo de recursos y soporte para areas interactivas.
Es un algoritmo basado en prioridades y apropiativo, con dos rangos distintos de prioridades:
- Uno de tiempo real (0 a 99)
- Y un valor normal (100 a 140).
Estos dos rangos se asignan a un esquema de prioridades global, en el que los valores mas bajos indican prioridades mas altas.
A diferencia de otros sistemas, linux asigna a las tareas de prioridad mas alta quantums mas largos y a las de prioridad mas baja quantums mas cortos.
El kernel mantiene una lista de todas las tareas ejecutables en una estructura de datos denominada cola de ejecucion (runqueue). Cada procesador mantiene su propia cola de ejecucion y la planifica de manera independiente.

- apropiativo, basado en prioridades. dos rangos de prioridades: tiempo compartido y tiempo real.
- tiempo real rango entre 0 a 99 y valor de nice entre 100 y 140
- una tarea esta disponible para running mientras le quede tiempo en su intervalo de tiempo (active)
- si no le queda tiempo (expired) no esta disponible para running hasta que todas las otras tareas utilicen sus interevalos de tiempo
- todas las tareas en runable mantienen la informacion en la estructura de datos runqueue por CPU
La planificacion de Windows XP es apropiativa basada en prioridades. La parte del kernel que la gestiona se llama despachador. Este usa un esquema de prioridades de 32 niveles para determinar el orden de ejecucion. Las prioridades se dividen en dos clases:
- Clase variable: contiene procesos cuyas prioridades van de 1 a 15 m
- Clase tiempo real: contiene procesos con prioridades de 16 a 31. El proceso con prioridad lo gestiona la memoria.




## Ejercicio2
### a) 
```
 #include <xinu.h>

void hijo(void);

void primos(void){
    int primo = create(hijo, 8192, 20, "process 1", 0);
    resume( primo);

    for (int i = 2; i < 5000; i++) {
            int esPrimo = 1;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    esPrimo = 0;
                    break;
                }
            }
            if (esPrimo) {
                kprintf("Padre: %d\n", i);
            }
    }

    kill(primo);
    kprintf("hijomatado");
    exit();
	
}


void hijo(){
    
    for (int i = 5000; i < 10000; i++) {
            int esPrimo = 1;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    esPrimo = 0;
                    break;
                }
            }
            if (esPrimo) {
                kprintf("Hijo: %d\n", i);
            }
        }
}
```

### b) 


```
#include <xinu.h>

void hijo(void);

void primos(void){
    int primo = create(hijo, 8192, 20, "process 1", 0);
    int prioriHijo = getprio(primo);
    int priorPadre = getprio(primos);
    
    chprio(getpid(), 30);
    resume( primo);

    for (int i = 2; i < 10; i++) {
            int esPrimo = 1;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    esPrimo = 0;
                    break;
                }
            }
            if (esPrimo) {
                kprintf("Padre: %d\n", i);
            }
    }

    sleep(NULL);
    kill(primo);
    kprintf("hijomatado");
    exit();
	
}


void hijo(){
    
    for (int i = 10; i < 20; i++) {
            int esPrimo = 1;
            for (int j = 2; j < i; j++) {
                if (i % j == 0) {
                    esPrimo = 0;
                    break;
                }
            }
            if (esPrimo) {
                kprintf("Hijo: %d\n", i);
            }
        }
}
```

## Ejercicio 5
Averigue como puede ver el estado de cada proceso en ejecución de un sistema UNIX (Linux/MAC OS), etc. ¿Qué estados posibles existen en UNIX? ¿Qué significa el estado zombie en UNIX según Tanenbaum?
Para ver el estado de un proceso en linux se puede usar el comando `top`
R: En ejecucion o listo para ser ejecutado.
S: Suspendido El proceso se encuentra a la espera de ser reanudado
D: El proceso se encuentra a la espera de I/O
T: Detenido
Z: Zombificado, un proceso difunto que aun no ha sido reclamado por el proceso padre.

Segun tanenbaum, un proceso zombie es un proceso que termino pero su proceso padre aun no lo llamo "wait()". Todos los procesos transicionan a este estado cuando terminan pero generalmente existen como zombies muy poco tiempo.


## Ejercicio 3


