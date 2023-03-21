# Proyecto Hotel

Este es un programa en C++ que implementa una lista enlazada simple para manejar un registro de huéspedes y habitaciones. El programa utiliza una clase Nodo para representar cada nodo en la lista enlazada. Cada nodo tiene dos miembros de datos: un entero que representa el número de habitación y una cadena que representa el nombre del huesped. El programa define una serie de funciones que se utilizan para manipular la lista enlazada, como agregar un nuevo huesped, buscar un huesped en la lista, mostrar la lista de huespedes ordenados alfabéticamente y mostrar la lista de huespedes en orden.

La clase Nodo tiene dos constructores que permiten crear un nuevo nodo con un número de habitación y un nombre de huésped, o un nuevo nodo que se enlaza a otro nodo. La clase Nodo también tiene una serie de métodos para obtener y establecer los valores de los miembros de datos, así como para obtener y establecer el enlace al nodo siguiente.

La función "nuevoHuesped" permite al usuario ingresar un nuevo nombre de huesped y número de habitación y agregar un nuevo nodo a la lista enlazada. La función también escribe el nombre del huesped y el número de habitación en un archivo de texto

La función "buscarHuesped" permite al usuario buscar un huesped en la lista enlazada ingresando su nombre. Si se encuentra un nodo con ese nombre de huesped, se muestra el número de habitación correspondiente. Si no se encuentra un nodo con ese nombre, se muestra un mensaje de error.

La función "mostrarAlfabeticamente" ordena los nombres de huespedes en orden alfabético y los muestra junto con los números de habitación correspondientes.

La función "mostrarenOrden" simplemente muestra la lista de huespedes y sus números de habitación en el orden en que se ingresaron.

La función "revisarDisponibilidad" se utiliza para verificar si una habitación está disponible o no. Si se ingresa un número de habitación que ya está ocupado, la función busca la habitación anterior y la siguiente para ver si están disponibles. Si encuentra una habitación disponible, la función devuelve su número de habitación. Si no se encuentra ninguna habitación disponible, la función le pide al usuario que ingrese un número de habitación diferente y llama a sí misma recursivamente para verificar la disponibilidad de esa habitación. Si no se puede encontrar ninguna habitación disponible después de varios intentos, la función devuelve un mensaje de error.
