# PR2: Simulador de la máquina RAM
- Diseño y análisis de algoritmos
- Enrique Gómez Díaz

## Descripción de una máquina RAM

Una Máquina de Acceso Aleatorio (RAM) es aquella máquina teórica que se utiliza para el cálculo de la complejidad de los diferentes algoritmos en esta asignatura. Ello se debe a que posee 3 características básicas:

- No posee concurrencia.
- Sus instrucciones son de tiempo constante.
- Permite medir el número de instrucciones ejecutadas.

## Instrucciones

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

## Estructura Utilizada

```plaintext
Maquina
│
├─ Instrucciones
│   ├─ ADD
│   ├─ SUB
│   └─ MUL
│
├─ MemoriaDatos
│
├─ MemoriaPrograma
│   └─ Parser
│
└─ Cinta
    ├─ CintaEntrada
    └─ CintaSalida
```
