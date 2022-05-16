20 puntos

1. Explica por que este programa funciona con threads pero no podria funcionar con procesos.
Esto se debe a que pthread_join cuenta con apuntadores e hilos suficientes mientras que en el caso de los procesos no es el caso. 
Además los procesos son demaciado "pesados" para esta tarea, los hilos son eficientes para estas tareas pequeñas, los hilos
pueden compartir el mismo espacio en memoria si pertenecen al mismo proceso, mientras que los procesos no. Esto da una facilidad de
trabajar con las mismas variables y datos a los hilos e igualmente facilita su comunicación.
Si quisieramos hacer lo mismo para los procesos sería demaciado demandante y consumiria demaciados recursos. 

2. Que pasaria si alguno de los hilos encuentra un error y termina antes que los demas?
El programa "crashearía" enteramente. Esto quiere decir que se cerrarían todos los hilos utilizados junto con el programa.  