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
El QUANTUM en XINU es de 2 ms, si lo cambiaramos a 100 ms el sistema no funcionaria con tiempo compartido ya que si el tiempo es alto, es probable que el proceso termine su ejecucion antes de que termine el QUANTUM por lo que todo el sistema se quedaria esperando a que se termine el QUANTUM
### c) Investigue cómo se llaman y cómo funcionan los algoritmos de planificación de procesos del sistema operativo Windows y Linux.  


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

