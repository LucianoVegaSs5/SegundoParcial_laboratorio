/*
 * printearMenues.c
 *
 *  Created on: 24 may. 2022
 *      Author: Luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input-UTN.h"

void preguntarLista(int* lista)
{
	pedirNumeros(lista, "\Desea ver:\n"
					"1) Solo descripciones\n"
					"2) Lista completa\n", "Error, elija una opcion valida\n", "Error, elija una opcion entre 1 y 2\n", 2, 1);
}


void preguntarOrden(int* orden)
{
	pedirNumeros(orden, "\nOrdenar de manera:\n"
					"1) ascendente\n"
					"2) descendente\n", "Error, elija una opcion valida\n", "Error, elija una opcion entre 1 y 2\n", 2, 1);
}

void preguntarTipo(int* tipoArchivo)
{
	pedirNumeros(tipoArchivo, "Tipos de servicio:\n"
					"1) Minorista\n"
					"2) Mayorista\n"
					"3) Exportar\n"
					"Seleccione el tipo de servicio: ", "Error, elija una opcion valida\n", "Error, debe elejir una opcion entre 1 y 3", 3,1);
}

void preguntarSort(int* sort)
{
	pedirNumeros(sort, "\nTipo de ordenamiento:\n"
			"1)Ordenar por id\n"
			"2)Ordenar por apellido\n"
			"Elija una opcion: ", "Error, opcion invalida\n", "Error, elija una opcion valida entre 1 y 2\n", 2, 1);
}

void mostrarMenuPrincipal(int* opcion)
{
	pedirNumeros(opcion, "\nMenu: \n"
			"1. Cargar Archivo.\n"
			"2. Imprimir lista.\n"
			"3. Asignar Totales.\n"
			"4. Filtrar por tipo.\n"
			"5. Mostrar servicios.\n"
			"6. Guardar servicios.\n"
			"7. Salir.\n", "Error, Elija una opcion valida por favor", "Error, elija una opcion entre 1-7.\n", 7 ,1);
}

void guardarCambios(int* confirmar)
{
	pedirNumeros(confirmar, "¿Desea guardar los cambios?\n"
			"1- Si\n"
			"2- No\n","Error, debe ingresar (1-2)\n", "Error, escoga una opcion valida", 2, 1);
}

void preguntaContinuar(int* continuar)
{
	pedirNumeros(continuar, "¿Desea continuar? \n"
			"1- Si\n"
			"2- No\n","Error, debe ingresar (1-2)\n", "Error, escoja una opcion valida", 2, 1);
}

void preguntarMap(int* opcion)
{
	pedirNumeros(opcion, "\nEl campo de Precio Total aún no ha sido completado ¿Desea cargarlo?\n"
			"1- Si\n"
			"2- No\n","Error, debe ingresar (1-2)\n", "Error, escoja una opcion valida", 2, 1);
}
