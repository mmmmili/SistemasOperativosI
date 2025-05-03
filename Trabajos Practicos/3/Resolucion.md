# 📝 Trabajo Practico 3 - Sistemas Operativos
## 📍 Ejercicio 1
### a.
Este programa define tres procesos en Xinu:
- `main()`: crea y arranca los procesos consume y produce.

- `produce()`: incrementa la variable global n 2000 veces.

- `consume()`: imprime el valor de n 2000 veces.

La variable n es global y, por lo tanto, compartida entre procesos.

❌ El programador probablemente esperaba que el consumidor imprimiera el valor final de n = 2000, 2000 veces. Pero como no hay sincronización:

Es posible que el consumidor imprima valores incorrectos o incompletos.

‼️ La salida será impredecible.

### b.
✅ Codigo utilizando semaforos
```
#include <xinu.h>

void produce(void), consume(void);

int32 n = 0;
sem32 sem1;
sem32 sem2;

void principal(void)
{
  semP = semcreate(1);
  semC = semcreate(0);

  resume( create(consume, 1024, 20, "cons", 0) );
  resume( create(produce, 1024, 20, "prod", 0) );
}

void produce(void)
{
  int32 i ;
  for (i = 1; i <= 2000; i++) {
        wait(semP);  
        n++;
        signal(semC); 
  }
  
}

void consume(void)
{
  int32 i;
  for (i = 1; i <= 2000; i++) {
        wait(semC);   
        printf("The value of n is %d\n", n);
        signal(semP); 
  }

}
```

## Ejercicio 2
### a.
Hay dos procesos concurrentes:

- `incrementar()`: incrementa x continuamente.

- `operar()`: cuando x es múltiplo de 10, calcula y = x * 2 y verifica si y también es múltiplo de 10.
  
❌ Problema:
No hay sincronización entre incrementar() y operar(). Esto significa:

- incrementar() puede modificar x mientras operar() la está leyendo.

- Entonces x podría cambiar entre las dos líneas:
   ```
   y = x * 2;
   if ((y % 10) != 0) 
  ```  
Y por eso, aunque x era múltiplo de 10 al inicio, ya no lo es cuando se usa en el cálculo, generando valores erróneos de y.  

### b.

Xinu no tiene mutex nativo, pero sí tiene semáforos, que podemos usar para construir uno.
Debo implementar estas 3 funciones.

- void mutex_init(sid32 sem);
- void mutex_lock(sid32 sem);
- void mutex_unlock(sid32 sem);

```
mut.c

#include <xinu.h>

sid32 sem;
int32 pActual;

void mutex_init()
{
  sem = semcreate(1);
}

void mutex_lock()
{
  wait(sem);
  pActual = getPid();
}

int mutex_unlock()
{
  int resultado ;
  int32 pLlamador = getPid();
  if(pActual == pLlamador){
    signal(sem);
    resultado = 1;
    pActual = 0;
  }else{
    resultado = -1;
  }
  return resultado;
}

```

### c. 
```

#include <xinu.h>
#include <mut.h>

void operar(void), incrementar(void);
unsigned char x = 0;


void mut(void)
{
    mutex_init(); 

    resume( create(operar, 1024, 20, "process 1", 0) );
    resume( create(incrementar, 1024, 20, "process 2", 0) );
    sleep(10); // dejar que corran por un rato
}


void operar(void)
{
    int y = 0;
    printf("Si no existen mensajes de ERROR entonces todo va OK! \n");

    while (1) {
        mutex_lock();
        if ((x % 10) == 0) {
            y = x * 2;
            if ((y % 10) != 0)
                printf("\r ERROR!! y=%d, x=%d \r", y, x);
        }
        mutex_unlock();
    }
}


void incrementar(void)
{
    while (1) {
        mutex_lock();
        x = x + 1;
        mutex_unlock();
    }
}
```
