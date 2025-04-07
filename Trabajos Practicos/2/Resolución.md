# Trabajo Practico 2
## Ejercicio 1
### `suspend(pid)`
Este system call se usa para suspender (pausar) la ejecución de un proceso identificado por su PID (Process ID). Cuando se llama a suspend(pid) el proceso pasa de estado LISTO a estado 
SUSPENDIDO y no se le asignara la CPU hasta que sea reactivado. Sirve para detener un proceso sin matarlo ni eliminarlo.
### `resume(pid)`
Este syscall reactiva un proceso que fue suspendido con suspend(pid).Cambia de estado SUSPENDIDO a lISTO y la CPU puede volver a ejecutarlo. Se utiliza para reanudar la ejecucion de un proceso que fue pausado temporalmente
### `getprio(pid)`
Este syscall se utiliza para consultar la prioridad actual de un proceso en ejecucion o espera. Devuelve un numero entero >= 0 que representa la prioridad del proceso y si el pid es inválido o el proceso no existe, devuelve SYSERR 
### `chprio(pid, newprio)`
