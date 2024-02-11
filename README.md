# Proyecto-Estructura-de-Datos
## Caso a resolver:
El dueño de un restaurante requiere un programa que le apoye a determinar la cantidad de raciones a preparar diariamente, asi como considerar que platos a la carta prepara (deberá considerar las fechas anteriores que se consumieron estos platos).
Las raciones de menú varían según la inversión en cada receta y postres. Así como el número de calorías.

En el restaurante los pedidos de platos son directos por parte de los clientes cuando llegan al restaurante, lo hacen atravesó de una pantalla táctil. Allí se queda registrado los datos del cliente que según la edad que este le brinde al programa. El número de calorías a consumir está sujeto a la edad del cliente. Por lo que el software al saber la edad recomienda el plato de menor o mayor calorías.


## Estrategias para resolver el caso:
* ### Vamos a crear LISTA SIMPLE para llenar la informacion de los platos predeterminadamente en el codigo.
* ### Otra LISTA SIMPLE para almacenar la informacion, gastos inversion, ganancia de cada DIA.
* ### Una PILA, una para la informacion de pedidos del cliente para tener el historial de todos los pedidos hechos durante la semana.
* ### Y una estructura o ARRAY (por determinarse xdd si saben cual seria mejor avisen) para el stock de los platos invertidos en la semana.

### Ahora en un bucle de semanas y dias, haremos los pedidos en el Menu tactil, donde ahi dependiendo de la edad se va a recomendar y mostrar los platos, y ahi va a elejir el pedido que se va a almacenar en la pila de pedido y a la vez el plato escogido se va a restar 1 en la pila de stock de inversion semanal, asi repitiendo en toda la semana.

### Al termiar la primera semana, se va a mostrar la lista simple del dia lunes a domingo cada la cantidad de ventas y que platos se compro cada dia, despues se va a mostrar y calcular la ganancia semanal, lo cual indicara si hubo ganancias (mas del doble de la inversion recuperada), si no hubo ganancias (menos de la inversion), y que reconsidere ajustar los precios de cada plato de la listaSimple (si es menor que el doble pero mayor que la inversion).

### Despues de la indiacion se va a pedir OLBIGATORIAMENTE aumentar el stock de inversion de los platos, dependiendo del plato ya que se va a mostrar el costo y la cantidad de platos que se quiere invertir para la proxima semana.
## Ahora OPCIONALMENTE se va a pedir reajustar los precios de los platos en el restaurante de esta manera para que se beneficie los costos y ganancia segun quiera.
## Ahora si hay otra semana la siguiente semana, se vera como los precios se cambiaron si es que se ajustaron y los cambios necesarios como el stock etc. ...

Estructuras:
- ListaSimple para los platos.
- Pila para los pedidos durante la semana.
- Pila para la reserva de platos invertidos de la semana.

### *APARTADO MENU TACTIL (VISUAL DE CLIENTE)
* RecomendarPlatos
* PedidosClientes
* etc...
### *APARTADO INVERSION (VISUAL ADMIN)
* InversionPredeterminada...
* CalcularGanancias, etc
* etc...
