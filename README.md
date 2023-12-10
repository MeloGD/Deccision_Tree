# Deccision tree o árbol de clasificación desarrollado en C++.

A falta de hacer un makefile para gestionar el proyecto, se puede utilizar por ejemplo desde src:
  g++ -std=c++14 -Wall -g main.cpp csv_reader.cpp -o ../bin/output

## ¿Qué hace de moment?
- Lee el fichero CSV.
- Extrae tada una columna en función de su campo.
- Extrae toda la información de una persona o fila en función de su índice.
- Hace un recuento de todas las distintas categorías, por ejemplo, nº de personas estado unidenses, dentro de un campo o columna.

## TODO:
  - Crear una clase que herede desde "binary tree" llamada "deccision tree".
  - Escoger una estrategia de ramificación, dado que hay categorías que constan de más de dos posibilidades.
  - Diseñar una función que calcule los valores de entriopía.
