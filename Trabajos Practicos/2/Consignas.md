# TRABAJO PRACTICO 2

## Ejercicio 1.

Estudie en XINU para que sirven las siguientes system calls (puede revisar el código fuente de XINU, o el libro XINU):
`suspend(pid);`
`resume(pid);`
`getprio(pid);`
`chprio(pid, newprio);`
`getpid();`
`sleepms(ms);`

- a. ¿Se puede hacer un suspend(pid) del proceso pid estando el proceso pid en estado “sleeping”?
- b. Repase el TP anterior: ¿cuánto vale el quantum en XINU?. ¿Que problema o comportamiento
puede haber si usted cambia el quantum a 100ms?
- c. Investigue cómo se llaman y cómo funcionan los algoritmos de planificación de procesos del
sistema operativo Windows y Linux. Redacte una respuesta-aprendizaje. Esto implica: no buscar en
google/chatgpt y sólo copiar y pegar. Intente dar una explicación general.

## Ejercicio 2. Estado sleeping and prioridades
- a. Desarrollar un programa en XINU que genere dos procesos para mostrar números primos. Un proceso
debe mostrar los primos del 1 al 5000, y el segundo proceso del 5000 al 10000.
- b. Modifique el programa anterior para darle al primer proceso de cálculo de primos mayor prioridad que al
segundo proceso. Verifique su ejecución e indique cómo se comporta el planificador de CPU de XINU al
ejecutar estos dos procesos de este inciso.
- c. XINU provee el system call sleepms() para que un proceso voluntariamente “delegue” la CPU durante un
tiempo en milisegundos. Al delegar la CPU, XINU coloca al proceso en estado “DURMIENDO” (estado
“bloqueado” en la literatura teórica). Cuando el tiempo de dormir finaliza, XINU coloca al proceso en
estado de “LISTO”.
Utilice este system call para modificar el comportamiento del programa del inciso b., de manera tal que el
proceso 1, luego de 100 numeros primos calculados, duerma durante 10ms. Verifique su ejecución e
indique cómo se comporta el planificador de CPU de XINU al ejecutar los dos procesos (siendo el proceso 1
de mayor prioridad que 2).
## Ejercicio 3. Ejemplos de Planificación de CPU
Sea un sistema con la siguiente carga de procesos. El planificador de CPU del sistema es por prioridades,
round-robin, apropiativo.
Proceso Prioridad Ráfaga Arribo a la cola de listos
P1 8 15 0
P2 3 20 0
P3 4 20 20
P4 4 20 25
P5 5 5 45
P6 5 15 55
A más alto número de prioridad mayor prioridad. El quantum del sistema es de 10 unidades. A misma
prioridad el planificador es round-robin.
- a. Mostrar el orden de ejecución y las ráfagas de CPU de los procesos.
- b. ¿Cuánto es el tiempo de turnaround para cada proceso? ¿Y el valor medio contando todos los
procesos?
- c. ¿Cuál es el tiempo de espera para cada proceso? ¿Y el valor medio contando todos los procesos?

## Ejercicio 4.
Sea un sistema con la siguiente carga de procesos.
Proceso Ráfaga Prioridad
P1 5 4
P2 3 1
P3 1 2
P4 7 2
P5 4 3
Los procesos arriban al sistema en el momento 0, en este orden: P1 , P2 , P3 , P4 , P5.
- a. Mostrar el orden de ejecución y las ráfagas de CPU de los procesos si el planificador es FCFS, SJF,
con prioridades no-apropiativo, round-robin (quatum = 2).
- b. ¿Cuánto es el tiempo de turnaround para cada proceso? ¿Y el valor medio contando todos los
procesos? (para cada algoritmo).
- c. ¿Cuál es el tiempo de espera para cada proceso? ¿Y el valor medio contando todos los procesos?
(para cada algoritmo).
- d. ¿Cuál de los algoritmos produce el mínimo promedio de tiempo de espera?
## Ejercicio 5.
- a. Averigue como puede ver el estado de cada proceso en ejecución de un sistema UNIX (Linux/MAC
OS), etc. ¿Qué estados posibles existen en UNIX? ¿Qué significa el estado zombie en UNIX según
Tanenbaum?
- b. Averigue como puede ver el estado de cada proceso en ejecución de un sistema UNIX (Linux/MAC
OS), etc.
