# 🧠 Trabajo Práctico 0  - Sistemas Operativos I

## ✅ 1. Tipos de datos básicos en C
  
```c  
 int a;  
 char b;
 float c;  
 long d; 
double e, f;
```

  ## 🖥️ 2. ¿Qué significa "word" en arquitectura?
     
En arquitectura de computadoras, una word es la unidad de datos que un procesador puede manejar o procesar de una sola vez.
💡 Ejemplo: En una arquitectura MIPS, una word tiene 8 bytes.

## 🧮 3. Tamaño de int en distintas arquitecturas


El tamaño de un int puede variar según la arquitectura:

- 🧱 8 bits: puede ser 8 o 16 bits

- 🧱 32 bits: generalmente 32 bits

- 🧱 64 bits: puede ser 32 o 64 bits

📎 En mi PC (según limits.h):  
```c
int:  
  Mínimo: -2147483648    
  Máximo: 2147483647
```

## 🅰️ 4. Diferencia entre %i y %c
```c
char a = 'M';  
printf("a = %i\n", a);       // Imprime: 77 (código ASCII)  
printf("La letra %c\n", a); // Imprime: M  
ℹ️ %i imprime el valor numérico (ASCII)  
ℹ️ %c imprime el carácter
```

## 🔢 5. Rango numérico de char y unsigned char
```c
char i;  
unsigned char j;  
  
i = 105  // 'i'  
j = 106  // 'j'  
```

## 🔡 6. Valor binario de variables
```c
char i = 'a';       // 0x61 → 01100001  
char j = 77;        // 0x4D → 01001101  
char k = 0x4D;      // 0x4D → 01001101  
  
printf("i = %x , j = %x , k = %x", i, j, k);  
```

## ❌ 7. Errores en declaraciones
| Declaración                  | ¿Es válida? | Motivo                                                                  |
|-----------------------------|-------------|-------------------------------------------------------------------------|
| `integer a;`                | ❌          | No existe el tipo `integer` en C, debería ser `int`.                   |
| `short i, j, k;`            | ✅          | Válida, `short` es un tipo de dato correcto.                           |
| `long float (h);`           | ❌          | No existe el tipo combinado `long float`, no es válido en C.           |
| `double long d3;`           | ❌          | Orden incorrecto, debería ser `long double`.                          |
| `unsigned float n;`         | ❌          | `float` no puede ser `unsigned`.                                       |
| `char 2j;`                  | ❌          | Las variables no pueden empezar con un número.                        |
| `int MY;`                   | ✅          | Válida, aunque no es común usar mayúsculas en nombres.                |
| `float ancho, alto, long;`  | ❌          | `long` es palabra reservada, no puede usarse como nombre de variable. |
| `bool i;`                   | ✅✅ (con `stdbool.h`) | Correcta solo si se incluye `#include <stdbool.h>`.             |


## 📏 8. Tamaño con sizeof()
Pasos para compilar y ejecutar:

`Crear el archivo .c`  

`Entrar a la carpeta del archivo`  

`Compilar: gcc archivo.c -o archivo`  

`Ejecutar: ./archivo`  

## ⚠️ 9. Incremento en char y unsigned char
```c  
  
char a = 127;  
unsigned char b = 255;
  
a++;  
b++;  
  
printf("a = %d, b = %u\n", a, b);
```  
👉 a desborda a negativo  
👉 b vuelve a 0

  ## ➗ 10. División entre distintos tipos
a) ¿Por qué r = a / b da entero?
```c  
  
int a = 5, b = 2;  
float r;  
r = (float)a / b;  // o a / (float)b
```  
b) División por cero

```c  
  
int a=1, b=2, c, d;  
c = a / b;  // = 0  
d = a / c;  // ❌ Error: división por cero
```  
c) Resultado de fragmento
```c  
  
printf("%d\n", 20/3);           // 6  
printf("%f\n", 20/3);           // 0.000000  
printf("%f\n", 20/3.);          // 6.666667  
printf("%d\n", 10%3);           // 1  
printf("%d\n", 3.1416);         // 🛑 No válido  
printf("%f\n", (double)20/3);   // 6.666667  
printf("%f\n", (int)3.1416);    // 3.000000  
printf("%d\n", (int)3.1416);  //3
```

## 🧮 11. Multiplicación de enteros
```c  
  
int resultado = 100000 * 100000;  
printf("%d\n", resultado);  // 1410065408
```  
👉 Se produce overflow. Usar long o long long.  

## 💀 12. Juego del Ahorcado
a) ¿Qué hacen estas líneas?
```c  
  
#include <stdio.h>    // Funciones de entrada/salida  
#include <stdlib.h>   // Funciones de sistema, memoria  
  
system("/bin/stty raw");   // Modo raw en terminal  
system("/bin/stty sane");  // Restaura terminal
```
b) Código básico del juego
[Ir al código del juego del ahorcado](ahorcadito.c)
