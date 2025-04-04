# 🖥️ Trabajo Práctico 1: Creación y Finalización de Procesos
## 📚 Ejercicio 1: Descarga y Configuración de Xinu
🔽 Descarga del Código Fuente
Para obtener el código fuente de Xinu, ejecuta:

```bash  
  
wget http://se.fi.uncoma.edu.ar/so/misc/xinu-pc.tar.gz  
📦 Desempaquetado
```  
``` bash  

tar xvf xinu-pc.tar.gz  
🛠️ Compilación
```
``` bash

cd xinu-pc/compile/  
make clean  
make  
▶️ Ejecución en QEMU
```  
``` bash 
  
make run-qemu  
Para acceder al shell de Xinu, presiona CTRL+ALT+3.
```

### ❓ Preguntas
### 🔧 Componentes principales del sistema Xinu:
Basándonos en el árbol de archivos de XINU, podemos encontrar:

1.  ⚙️ Núcleo (Kernel)

    -  🏗️ Gestión de procesos (create.c, kill.c).
    -  ⏳ Planificación (resched.c).
    - 🔒 Sincronización (semaphore.c).
    - ⚡ Interrupciones (intr.S).
    - 🧠 Memoria (meminit.c).
2. 📂 Sistema de archivos

    - 💾 Local (lfs*).
    - 🌐 Remoto (rfs*).
    - 🚀 RAM disk (ram*.c).
3. 🌐 Redes

    - 📶 Tarjeta de red Intel 82545EM (eth*.c).
    - 🕸️ Protocolos: ARP, IP, UDP (arp.c, ip.c).
    - 📡 DHCP & DNS (dhcp.c, dns.c).
4.  🐚 Shell y comandos

    - 💻 Intérprete (shell.c).
    - 📜 Comandos (xsh_*.c como xsh_ping, xsh_arp).
  5. 📚 Bibliotecas estándar
    - 📝 Funciones de C (str*.c, printf.c).

     ### 🖥️ Periféricos soportados:

| Periférico          | Drivers/Archivos        |
|--------------------|-----------------------|
| Consola/VGA 🖥️    | `vga.c`, `text_on_vga.c` |
| Teclado ⌨️        | `kbd*.c`               |
| Mouse 🐭          | `mice*.c`              |
| Red (Ethernet) 🌐 | `eth*.c`, `e1000e.h`   |
| RAM Disk 💾       | `ram*.c`               |
| PCI 🔌           | `pci.c`                |
| Reloj (RTC) ⏰    | `clk*.c`               |


## 🖥️ Ejercicio 2: Modificación de main.c
Edita el archivo main.c para emitir un mensaje en la pantalla VGA:

``` c  
  
#include <xinu.h>  
  
void main() {  
    kprintf("¡Hola, mundo desde Xinu!\n");  
    // Código existente...  
}
``` 
Compila y verifica que el mensaje se muestre al iniciar Xinu.  
  
## 🛠️ Ejercicio 3: Incorporación de un Programa al Shell  
Creación del Programa 

Crea un archivo hello.c en el directorio shell/ con el siguiente contenido:

``` c
  
#include <xinu.h>  
  
shellcmd hello(int nargs, char *args[]) {  
    printf("¡Hola, mundo!\n");  
    return 0;  
}
```
Registro en el Shell

include/shprototypes.h: Agrega la declaración del prototipo:

``` c
   
shellcmd hello(int nargs, char *args[]);  
shell/cmdtab.c: Añade la entrada correspondiente:  
  
```c
  
{"hello", FALSE , hello},
``` 
Compilación y Verificación  

Compila Xinu y, en el shell, ejecuta hello para verificar que funciona correctamente.

### Pregunta

¿Por qué en Xinu no se llama main() la función principal de cada nuevo programa?

En Xinu, las funciones del shell deben seguir el formato shellcmd nombre_funcion(...) para ser reconocidas y gestionadas adecuadamente por el shell.
## Visualización de Procesos 📊👀
Para ver los procesos en ejecución, usa el comando ps (Process Status). Este muestra una lista de todos los procesos activos, incluyendo sus IDs, estados, prioridades y más detalles.

### 🔹 Ejemplo de salida:

``` Pid Name             State Prio Ppid Stack Base Stack Ptr  Stack Size
--- ---------------- ----- ---- ---- ---------- ---------- ----------
  0 prnull           ready    0    0 0x005FDFFC 0x00146284     8192
  1 rdsproc          susp   200    0 0x005FBFFC 0x005FBFC8    16384
  3 Main process     recv    20    2 0x005E7FFC 0x005E7F64    65536
  4 shell            recv    50    3 0x005F7FFC 0x005F7C7C     8192
 11 ps               curr    20    4 0x005F5FFC 0x005F5FC4     8192
```
