# osint-c++
La función FindUserURLs recibe dos parámetros: input, que es el texto en el que se buscarán las URLs, y username, que es el nombre de usuario que se desea buscar en las URLs. Esta función devuelve un vector de cadenas que contiene todas las URLs que contienen el nombre de usuario especificado.

Dentro de la función FindUserURLs, se utiliza una expresión regular para buscar las URLs en el texto. La expresión regular urlRegex busca patrones que comiencen con "http://" o "https://" seguido de cualquier caracter que no sea espacio, "/", "?", o "#", seguido de cualquier caracter que no sea espacio. Esto captura la mayoría de las URLs en el texto.

Luego, se itera a través de las coincidencias encontradas con std::sregex_iterator, y se verifica si cada URL contiene el nombre de usuario utilizando la función std::string::find. Si el nombre de usuario está presente en la URL, se agrega la URL al vector userURLs.

En la función main, se muestra un banner en la consola y se solicita al usuario que ingrese un texto que pueda contener URLs. Luego, se solicita al usuario que ingrese un nombre de usuario específico.

El texto ingresado por el usuario y el nombre de usuario se pasan a la función FindUserURLs para encontrar las URLs que contienen el nombre de usuario.

Finalmente, se muestra el resultado en la consola. Si no se encuentran URLs para el nombre de usuario específico, se muestra un mensaje indicando que no se encontraron coincidencias. Si se encuentran URLs, se muestran en la consola una por una.
