/*
 ============================================================================
 Name        : SegundoParcial_laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "printMenues.h"
#include "eServicios.h"
#include "Controller.h"

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	int cargaArchivo = 1;
	LinkedList* listaServicios = ll_newLinkedList();

	do{
		mostrarMenuPrincipal(&opcion);

		switch(opcion)
		{
			case 1:
				if(controller_cargarArchivoTxt(listaServicios, &cargaArchivo)!= 1)
				{
					printf("\nOcurrio un error cargando el archivo\n"
							"Tenga en cuenta escribir el nombre del archivo sin la extension y verifique el nombre del archivo\n");
				}
				break;
			case 2:
				if(controller_listServicios(listaServicios)!=1)
				{
					printf("\nOcurrio un error al mostrar el listado\n");
				}
				break;
			case 3:
				if(controller_completarPrecioTotal(listaServicios) !=  1)
				{
					printf("\nOcurrio un error al calcular los precios totales\n");
				}
				break;
			case 4:
				if(controller_filtrarServicios(listaServicios) !=  1)
				{
					printf("\nOcurrio un error al intentar filtrar los tipos\n");
				}
				break;
			case 5:
				if(controller_mostrarServicios(listaServicios)!= 1)
				{
					printf("\nOcurrio un error al mostrar los servicios\n");
				}
				break;
			case 6:
				if(controller_guardarServicios(listaServicios) != 1)
				{
					printf("\nOcurrio un error guardar el archivo con servicios\n");
				}
				break;
			case 7:
				printf("\nSaliendo del sistema...\n");
				break;
		}


	}while(opcion != 7);

	ll_deleteLinkedList(listaServicios);

}
