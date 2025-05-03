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
#include <xinu.h>

void mutex_init(sid32 sem)
{
  sem = semcreate(1);
}

void mutex_lock(sid32 sem)
{
  wait(sem);
}

void mutex_unlock(sid32 sem)
{
  signal(sem);
}

```
