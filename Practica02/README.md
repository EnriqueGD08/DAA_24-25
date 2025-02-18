# PR2: Simulador de la máquina RAM
- Diseño y análisis de algoritmos
- Esther M. Quintero

## Descripción de una máquina RAM

Una Máquina de Acceso Aleatorio (RAM) es aquella máquina teórica que se utiliza para el cálculo de la complejidad de los diferentes algoritmos en esta asignatura. Ello se debe a que posee 3 características básicas:

- No posee concurrencia.
- Sus instrucciones son de tiempo constante.
- Permite medir el número de instrucciones ejecutadas.

Así pues, podemos decir que la máquina RAM se divide en 5 grandes componentes:

- **Memoria de programa:** Guarda el conjunto de instrucciones de un programa. Esta memoria no es modificable.
- **Memoria de datos:** Posee una serie de registros indexados R0, R1, R2, …, Rn para almacenar datos. El registro R0 es un registro especial llamado acumulador, el cual ayuda en la realización de operaciones aritméticas, lógicas y de control.
- **Unidad de aritmética, control y lógica:** Permite realizar operaciones aritméticas (ADD, SUB, DIV, etc.), de control de programa (JUMP) o lógicas (JGTZ, JZERO).
- **Unidad de entrada:** Gestiona la entrada de datos de la máquina. La entrada de datos viene representada por una cinta de elementos, y para su lectura se dispone de un cabezal que se mueve a la siguiente posición cada vez que se realiza una operación de lectura (READ).
- **Unidad de salida:** Gestiona la salida de datos de la máquina. La salida de datos viene representada por una cinta de elementos, y para su escritura se dispone de un cabezal que se mueve a la siguiente posición cada vez que se realiza una operación de escritura (WRITE)

La máquina posee un conjunto de instrucciones finito, cada una de ellas formada por una combinación de OPERADOR + OPERANDO, pudiendo ser el operando una etiqueta. Las instrucciones disponibles en nuestra máquina RAM serán las siguientes:

| Instrucción | Descripción |
|----------|----------|
| LOAD op | El operando se carga en R0. |
| STORE op | El contenido de R0 se guarda en la memoria según lo indicado en el operando. |
| ADD op | El operando se suma a R0 y el resultado se almacena en R0. (R0 = R0 + op) |
| SUB op | El operando se resta a R0 y el resultado se almacena en R0. (R0 = R0 - op) |
| MUL op | El operando se multiplica con R0 y el resultado se almacena en R0. (R0 = R0 * op) |
| DIV op | El operando divide a R0 y el resultado se almacena en R0. (R0 = R0 / op) |
| READ op | Se lee un valor de la cinta de entrada y se almacena en la memoria según lo indicado en el operando. |
| WRITE op | Se escribe lo indicado por el operando en la cinta de salida. |
| JUMP etiq | El control del programa salta a la instrucción indicada por la etiqueta. |
| JZERO etiq | El control del programa salta a la instrucción indicada por la etiqueta si el valor de R0 es igual a 0 (R0 == 0). |
| JGTZ etiq | El control del programa salta a la instrucción indicada por la etiqueta si el valor de R0 es mayor a 0 (R0 > 0). |
| HALT | Detiene la ejecución del programa. |

Además de las etiquetas, la máquina RAM define 3 tipos de operandos:

- **Operando =i:** Constante con valor i. Por ejemplo, LOAD =10 → R0 = 10. Este tipo de operando no tiene sentido para instrucciones que necesiten el valor de un registro como STORE.
- **Operando i:** Indica el registro Ri (direccionamiento directo). Por ejemplo, LOAD 10 → R0 = R10.
- **Operando *i:** Indica el registro contenido en el registro Ri (direccionamiento indirecto). Por ejemplo, LOAD *10 → R0 = Rj, siendo j el contenido del registro Ri.

Un programa RAM consiste en una secuencia de instrucciones que se ejecutan de manera secuencial, salvo que se encuentren sentencias de control como JUMP, JZERO o JGTZ. La ejecución del programa se hace de acuerdo a las siguientes reglas:

- La ejecución comienza en la primera instrucción del programa, con todos los registros de la memoria vacíos y con los datos de entrada cargados en la cinta de entrada.
- Se ejecuta una instrucción, se modifican los registros de memoria necesarios o la cinta de salida y, acto seguido, se pasa a la ejecución de la siguiente instrucción.
- Las instrucciones READ y WRITE leen y escriben en las cintas correspondientes, y en ambos casos se avanza una posición en la cinta. No se puede utilizar como operando de las instrucciones READ y WRITE el registro R0. Así por ejemplo, las instrucciones READ 0 y WRITE 0 no son válidas.
- El programa termina cuando no hay más instrucciones a ejecutar o cuando se encuentra la instrucción HALT.

La complejidad de un programa en la máquina RAM es equivalente al número de instrucciones ejecutadas por el mismo.

## Objetivos de la práctica

Los siguientes objetivos se consideran condición necesaria pero no suficiente para aprobar la práctica:

- Programar un simulador de máquina RAM atendiendo a las especificaciones indicadas en la sección anterior y a los requisitos de la siguiente sección.
- Utilizar el paradigma de Programación Orientada a Objetos, así como seguir los principios SOLID y el patrón estrategia en caso de ser necesario.
- Utilizar los lenguajes de programación C++, Java o C#.

## Requisitos evaluables del simulador RAM

Los siguientes requisitos se evaluarán de cara a la entrega de la práctica:

- Todo el código deberá estar adecuadamente comentado y desarrollado atendiendo al paradigma de Programación Orientada a Objetos.
- Se deben seguir los principios SOLID así como el patrón estrategia, con el fin de poseer un buen diseño del software.
- El simulador debe funcionar con los ejemplos de prueba proporcionados junto con este enunciado.
- El programa RAM a cargar en la memoria, así como el contenido de la cinta de entrada y de la cinta de salida se modelarán mediante tres ficheros independientes, los cuales serán parámetros de entrada del programa. Estos son:
    - Fichero con el programa RAM.
    - Fichero con el contenido de la cinta de entrada.
    - Fichero con el contenido de la cinta de salida.
- Las instrucciones de la máquina RAM pueden estar escritas en mayúscula o en minúscula.
- Se pueden especificar comentarios en un programa RAM, indicados por el carácter #. La línea que empiece por # no se cargará como parte del programa RAM.
- Se deben contemplar los 3 tipos de operandos: constante, direccionamiento directo y direccionamiento indirecto.
- Se debe comprobar que las instrucciones sean válidas. Sólo se permiten las instrucciones ya especificadas en la tabla correspondiente, con el formato indicado en la misma. Por ejemplo, la instrucción STORE =3 no es válida, ya que STORE no permite un comando de tipo constante.
- Si se detecta algún error se debe imprimir en la consola un mensaje que indique la instrucción errónea y el número de línea dentro del programa RAM que lo provocó.
- Cuando se alcance una instrucción HALT o se detecte un error, el contenido de la cinta de salida debe volcarse en el fichero indicado.

Durante la defensa de la práctica se podrá solicitar algún tipo de modificación o prueba adicional, la cual afectará en diferente grado a la nota final.