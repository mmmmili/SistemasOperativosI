# 🖥️ Trabajo Práctico 1: Creación y Finalización de Procesos
## 📚 Ejercicio 1: Descarga y Configuración de Xinu
🔽 Descarga del Código Fuente
Para obtener el código fuente de Xinu, ejecuta:

```bash  
wget http://se.fi.uncoma.edu.ar/so/misc/xinu-pc.tar.gz  
```

``` bash  
tar xvf xinu-pc.tar.gz  
```
``` bash
cd xinu-pc/compile/  
make clean  
make  
```  
``` bash 
make run-qemu  
Para acceder al shell de Xinu, presiona CTRL+ALT+3.
```

## Comandos XINU
| 🔹 **Comando** | ✨ **Descripción** | 📌 **Ejemplo** |
|--------------|------------------|---------------|
| 📜 **ps** | Muestra los procesos en ejecución con su PID, estado y prioridad. | `xsh $ ps` |
| 📂 **ls** | Lista los archivos del sistema. | `xsh $ ls` |
| 📥 **cat [archivo]** | Muestra el contenido de un archivo. | `xsh $ cat ejemplo.txt` |
| 🏃 **echo [mensaje]** | Imprime un mensaje en pantalla. | `xsh $ echo "Hola, Xinu!"` |
| 📡 **netinfo** | Muestra la configuración de red. | `xsh $ netinfo` |
| 🔄 **reboot** | Reinicia el sistema operativo Xinu. | `xsh $ reboot` |
| ❌ **exit** | Sale del shell de Xinu. | `xsh $ exit` |
| 📊 **memstat** | Muestra el estado de la memoria del sistema. | `xsh $ memstat` |
| 🧪 **test [nombre]** | Ejecuta pruebas del sistema. | `xsh $ test timer` |
| 📖 **help** | Muestra una lista de comandos disponibles. | `xsh $ help` |
| 💀 **kill [PID]** | Termina un proceso en ejecución. | `xsh $ kill 5` |
| 📅 **date**


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
  
void hola() {  
    kprintf("¡Hola!\n");   
}
``` 
Compila y verifica que el mensaje se muestre al iniciar Xinu.  
  
## 🛠️ Ejercicio 3: Incorporación de un Programa al Shell  
Creación del Programa 

Crea un archivo hello.c en el directorio shell/ con el siguiente contenido:

``` c
  
#include <xinu.h>  
  
void hola() {  
    kprintf("¡Hola!\n");   
}
```

Registro en el Shell

include/ `shprototypes.h`: 

``` c
 extern shellcmd hola(int32, char *[]);
```
shell/ `cmdtab.c`:  
  
```c
{"hola", FALSE , hola},
```   

 🛠️ Compila Xinu y, en el shell, ejecuta hello para verificar que funciona .

### ¿Por qué en Xinu no se llama main() la función principal de cada nuevo programa?

En Xinu, el kernel ya tiene su propio `main()` donde se inicializa el sistema operativo y  se configura el hardware, por lo que si si varios archivos definieran main(), el linker no sabría cuál es el verdadero punto de entrada. Y daria error de compilacion.

## Visualización de Procesos 📊👀
Para ver los procesos en ejecución, usa el comando ps (Process Status). Este muestra una lista de todos los procesos activos, incluyendo sus IDs, estados, prioridades y más detalles.

### 🔹 Ejemplo:

``` Pid Name             State Prio Ppid Stack Base Stack Ptr  Stack Size
--- ---------------- ----- ---- ---- ---------- ---------- ----------
  0 prnull           ready    0    0 0x005FDFFC 0x00146284     8192
  1 rdsproc          susp   200    0 0x005FBFFC 0x005FBFC8    16384
  3 Main process     recv    20    2 0x005E7FFC 0x005E7F64    65536
  4 shell            recv    50    3 0x005F7FFC 0x005F7C7C     8192
 11 ps               curr    20    4 0x005F5FFC 0x005F5FC4     8192
```
### 🔍 Explicación:
1. PID (Process ID): Identificador único del proceso.

 - `0` (`prnull`): Proceso especial (nulo/inactivo).
- `1` (`rdsproc`): Proceso relacionado con disco remoto (suspendido).
- `3` (`Main process`): Proceso principal (en estado recv, esperando mensajes).
- `4` (`shell`): ¡El shell de Xinu! (también en recv).
 - `11` (`ps`): Proceso actual (el que se ejecutó).
2. Estados (State):

- `ready` : Listo para ejecutarse.
- `susp` : Suspendido (ejemplo: rdsproc).
- `recv` : Esperando recibir un mensaje (como el Main process y el shell).
- `curr` : En ejecución actual (ps).
3. Prioridad (Prio):

- Mayor número = Mayor prioridad (ejemplo: rdsproc tiene 200).
4. `PPID` (Parent PID):

- El shell (PID 4) fue creado por el Main process (PID 3).
- El comando ps (PID 11) fue lanzado desde el shell (PID 4).
5. Stack (Pila):

- Direcciones de memoria y tamaño asignado a cada proceso.

  
