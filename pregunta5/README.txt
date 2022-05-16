20 puntos

En el programa muchos, 3 procesos hacen un ciclo 3 veces, pero si lo ejecutas, se 
imprimen muchas mas lineas.

Por que?

Respuesta: 
Esto se debe a que estamos usando la función fork(), la cual crea nuevos procesos. Al final del programa se 
puede observar como se hace uso de la misma, es decir las lineas extras son procesos nuevos creados por fork() y el 
parametro "n". Las primera llamada a fork() es solamente el proceso padre, para las siguiente se crea el primer proceso 
hijo, es decir se llama 2 veces a la función. Y las siguiente a esas crean 3 procesos hijos por lo que se llama 4 veces a la función. 

Corrige el programa. Para que solo salgan las 9 lineas.

