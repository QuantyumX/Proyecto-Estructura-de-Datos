# Proyecto-Estructura-de-Datos
## Caso a resolver:
El dueño de un restaurante requiere un programa que le apoye a determinar la cantidad de raciones a preparar diariamente, asi como considerar que platos a la carta prepara (deberá considerar las fechas anteriores que se consumieron estos platos).
Las raciones de menú varían según la inversión en cada receta y postres. Así como el número de calorías.

En el restaurante los pedidos de platos son directos por parte de los clientes cuando llegan al restaurante, lo hacen atravesó de una pantalla táctil. Allí se queda registrado los datos del cliente que según la edad que este le brinde al programa. El número de calorías a consumir está sujeto a la edad del cliente. Por lo que el software al saber la edad recomienda el plato de menor o mayor calorías.


## Estrategias para resolver el caso:
* ### Creacion de LISTA SIMPLE para llenar la informacion de los platos en el codigo.
* ### Creacion de LISTA SIMPLE para almacenar la informacion, gastos inversion, ganancia de cada DIA de la semana.
* ### Creacion de 2 COLAS, una para la informacion  del cliente, y otra cola para los datos de los PEDIDOS de este mismo cliente, sirviendo como campo de la COLA general. (se eliminara los datos cada dia).
* ### Creacion de 2 PILAS, una para la informacion del cliente y tener un historial semanal, y otra para los datos de pedidos de este mismo cliente, sirviendo como campo de la PILA general (Se va a ir asignando con la misma informacion de las colas de cada dia). (Se eliminara los datos cada fin de semana)

### Iniciaremos con bucles de SEMANAS, DIAS, CLIENTES, y PEDIDOS de cada cliente, haremos los pedidos en el Menu tactil, donde ahi dependiendo de la edad del cliente, se va a recomendar y mostrar los platos, y ahi va a elejir el pedido  y la cantidad de RACIONES que se va a almacenar en la COLA y ala vez en la PILA de es forma el plato escogido se va a restar a la cantidad de raciones escogidas en el stock LISTA de platos del plato escogido.

### Al termiar la primera semana, se va a mostrar un MENU DE OPCIONES DE ADMINISTRACION, donde podremos ver 
* ### La pila/historial de todos los pedidos de la semana desde el mas reciente hasta el ma viejo.
* ### La Lista simple de InfoDia, donde veremos cada dia los ingresos y ganancias y calculando asi las ganancias de la semana apoyando asi al dueño.
* ### Observar la lista de Platos que hay actualmente y sus datos.
* ### AJUSTAR el inventario, donde habra otro menu para configurar el inventario/lista de platos.
  * #### Aumentar el stock: Aca ingresamos el nombre del plato que queremos aumentarle mas stock para que puedan comprar la siguente semana.
  * #### Cambiar el precio: Aca ingresamos el nombre del plato que queremos cambiarle de precio, de esa forma segun como le benficie.
  * #### Ingresar un nuevo plato: Aca ingresamos con todos los datos a un nuevo plato, para la lista de platos y forme parte del menu.
  * #### Eliminar un plato; Aca ingresamos el nombre del plato que queremos eliminar del menu.

