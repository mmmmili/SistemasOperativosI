# 🖥️ Planificación en Sistemas Operativos
La planificacion es el mecanismo que utiliza el sistema operativo para decidir que proceso o hilo obtiene acceso al procesador y por cuanto tiempo. 
## ⚖️ Algoritmos de Planificación
Existen diversos algoritmos para determinar el orden de ejecución de los procesos:
## 🗓️  FIRST-COME, FIRST-SERVED (FCFS)
  Los procesos se ejecutan en el orden que llegan a la cola de listos.  No se interrumpe un proceso una vez que comienza su ejecución (no apropiativo).
  🔹 Ejemplo: Supongamos 3 procesos:  
  - P1 llega en tiempo 0 y dura 5
  - P2 llega en tiempo 1 y dura 3
  - P3 llega en tiempo 2 y dura 1
  Orden de ejecución: P1 ➡ P2 ➡ P3
  🔹 Ventajas:  
  - Simple de implemetar
  - Justo en cuanto a orden de llegada
    
🔹 Desventajas:  
  - Puede provocar tiempos de espera altos si un proceso largo llega primero (efecto convoy)
  - No es apropiado para sistemas interactivos por el mal tiempo de respuesta.

🔹 Dónde se usa:
  - Procesamiento por lotes (batch)

  ## 🧠  SJF - SHORTEST JOB FIRST
  🔹 Descripción: 
  Se selecciona el proceso con el menor tiempo estimado de ejecucion. Puede ser:
  - No apropiativo: una vez que se asigna, no se interrumpe
  - Apropiativo: llamado Shortest Remaining Time First (SRTF), donde un nuevo proceso mas corto puede interrumpir el actual.

🔹 Ventajas: 
  - El mejor tiempo de espera promedio teóricamente posible.

🔹 Desventajas: 
  - No siempre se conoce la duracion del proceso
  - Puede causar inanicion

🔹 Dónde se usa:
  - Sistemas batch donde se puede predecir la duracion.

  ## 🕒 RR - Round Robin
  🔹 Descripción:
  Cada proceso recibe un QUANTUM de tiempo. Si no termina en ese tiempo pasa al final de la cola.
  
  🔹 Ventajas:
  - Justo y eficaz en sistemas multitarea
  - Buen tiempo de respuesta
 
  🔹 Desventajas:
  - Mucho overhead si el QUANTUM es muy pequeño.
  - Rendimiento bajo si el QUANTUM es muy grande.
  
  🔹 Dónde se usa:
   Sistemas interactivos y time-sharing.

 ## 📊 Planificacion por Prioridades
 🔹 Descripción:    
    Cada proceso tiene un prioridad. El CPU siempre se asigna al proceso con mayor prioridad.
    - Apropiativo: un proceso con mayor prioridad puede interrumpir al actual.
    - No apropiativo: el proceso actual continúa hasta terminar  
🔹 Ventajas:  
    - Permite dar tratamiento especial a procesos críticos.  
🔹 Desventajas:   
    - Puede causar inanición a procesos de baja prioridad.  
    - Inversión de prioridad: si un proceso bajo prioridad bloquea uno de alta, puede frenar el sistema.  
🔹 Dónde se usa:  
    - Sistemas de tiempo real, embebidos  
🔹 Solución a la inanición:   
    - Aging: la prioridad de un proceso aumenta con el tiempo de espera.  


  ## 🧪 Colas Multinivel 
  Los procesos se dividen en varias colas, cada una con su propia politica de planificacion. Ejemplo de colas:
  - Cola 1: interactivos (RR)
  - Cola 2: batch (FCFS)
  - Cola 3: procesos en segundo plano (prioridad baja)
  Las colas también pueden tener prioridades entre sí.

🔹 Ventajas:  
  - Organizacion clara segun tipo de proceso.  
  - Flexibilidad en como se manjena distintos tipos de tareas
    
🔹 Desventajas:  
   - Dificil de configurar  
   - Un proceso puede quedar atrapado en una cola de baja prioridad

      
🔹 Dónde se usa:  
  - SO que manejan distintos tipos de procesos (Linux o Windows)  

  ## 🔄 Multinivel Feedback Queue  
  🔹 Descripción:   
  Similar a multinivel queue, pero permite que los procesos cambien de cola segun su comportamiento.
  - Si un proceso usa mucha CPU, baja de nivel  
  - Si espera mucho, sube de nivel

🔹 Ventajas:  
  - Adapta el algoritmo a distintos tipos de procesos automaticamente  
  - Reduce el hambre de procesos
  
  
🔹 Donde se usa:  
  - Sistemas como UNIX, WINDOWS, LINUX modernos lo implementan.  

    





