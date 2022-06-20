/*
 * Controller.c
 *
 *  Created on: 18 jun. 2022
 *      Author: Luciano
 */

#include "linkedList.h"
#include "printMenues.h"
#include "eServicios.h"
#include "input-UTN.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
#include "Archivos.h"


int verificarArhcivoFiltrado(char* nombreArchivo)
{
	int retorno = -1;

	if(nombreArchivo != NULL)
	{
		if(strcmp(nombreArchivo, "SrvExportar.csv") != 0)
		{
			if(strcmp(nombreArchivo, "SrvMinorista.csv") != 0)
			{
				if(strcmp(nombreArchivo, "SrvMayorista.csv") != 0)
				{
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}

int controller_cargarArchivoTxt(LinkedList* pListaServicios, int* cargaArchivo)
{
	int retorno = -1;
	char archivoNombre[20];
	FILE* pFile;

	if(*cargaArchivo)
	{
		if(pListaServicios != NULL)
		{
			printf("Ingrese el nombre del archivo a cargar sin el '.csv' :" );
			scanf("%s", archivoNombre);

			strcat(archivoNombre, ".csv");

			if(verificarArhcivoFiltrado(archivoNombre) != -1)
			{
				pFile = fopen(archivoNombre, "r");

				if(pFile !=  NULL)
				{
					if(parser_servicioFromTxt(pListaServicios, pFile))
					{
						*cargaArchivo = 0;
						retorno = 1;
						printf("\nSe realizo la carga del archivo exitosamente!\n");
					}

						fclose(pFile);
				}
			}
			else
			{
				retorno = 1;
				printf("\nError, se detecto que el archivo ingresado, es un archivo anteriormente filtrado\n");
			}
		}

	}
	else
	{
		retorno = 1;
		printf("Solo puede ejecutar un solo archivo\n");
	}
	return retorno;
}

int controller_listServicios(LinkedList* pListaServicios)
{
	int retorno = -1;
	int len;
	eServicio* servicio;

	if(ll_isEmpty(pListaServicios) == 0)
	{
		len = ll_len(pListaServicios);
		printf("=======================================================================================================\n");
		printf("ID            DESCRIPCION              TIPO 	     PRECIO UNITARIO 	    CANTIDAD	   PRECIO TOTAL    \n");
		printf("=======================================================================================================\n");
		for(int i =0; i<len; i++ )
		{
			servicio = ll_get(pListaServicios, i);
			if(servicio != NULL)
			{
				Servicio_print(servicio);
			}
			retorno = 1;
		}
		printf("=======================================================================================================\n");

	}
	else
	{
		if(ll_isEmpty(pListaServicios) == 1)
		{
			retorno = 1;
			printf("\nNecesita cargar el archivo para poder verlo\n");
		}
	}

	return retorno;
}

int controller_completarPrecioTotal(LinkedList* pListaServicios)
{
	int retorno = -1;
	LinkedList* listaMapeada = NULL;

	if(pListaServicios != NULL)
	{
		if(ll_isEmpty(pListaServicios) == 0)
		{
			listaMapeada = ll_map(pListaServicios,calcularTotal);
			if(listaMapeada != NULL)
			{
				printf("\nLos precios totales han sido asignados\n");
				retorno = 1;
			}
		}
		else
		{
			retorno = 1;
			printf("\nNecesita cargar un archivo primero\n");
		}
	}
	return retorno;
}

int controller_filtrarServicios(LinkedList* pListaServicios)
{
	int retorno = 0;
	int tipoArchivo;
	char nombreArchivo[25];
	char tipoServicio[25];

	LinkedList* listaFiltrada = NULL;

	if(pListaServicios != NULL)
	{
		if(ll_isEmpty(pListaServicios) == 0)
		{
			preguntarTipo(&tipoArchivo);
			switch(tipoArchivo)
			{
				case 1:
					listaFiltrada = ll_filter(pListaServicios, filtrarTipoMinorista);
					strcpy(nombreArchivo, "SrvMinorista.csv");
					strcpy(tipoServicio, "Minorista");
					break;
				case 2:
					listaFiltrada = ll_filter(pListaServicios,filtrarTipoMayorista);
					strcpy(nombreArchivo, "SrvMayorista.csv");
					strcpy(tipoServicio, "Mayorista");
					break;
				case 3:
					listaFiltrada = ll_filter(pListaServicios,filtrarTipoExportar);
					strcpy(nombreArchivo,"SrvExportar.csv");
					strcpy(tipoServicio, "Exportar");
					break;
			}

			if(generarArchivoFiltrado(listaFiltrada, nombreArchivo,  tipoServicio))
			{
				printf("\nEl archivo ha sido creado con exito\n");
				printf("Nombre del archivo: - %s -\n", nombreArchivo);
				ll_deleteLinkedList(listaFiltrada);
			}
			else
			{
				printf("\nOcurrio un error al crear el archivo\n");
			}

			retorno = 1;

		}
		else
		{
			retorno = 1;
			printf("\nNecesita cargar un archivo primero\n");
		}
	}

	return retorno;
}

int ordenarPorDescripcion(LinkedList* pListaServicios)
{
	int retorno = -1;

	if(pListaServicios != NULL)
	{
		if(ll_sort(pListaServicios, Servicio_sortByDesc, 1) == 0)
		{
			retorno = 1;
		}

	}

	return retorno;
}

int controller_mostrarServicios(LinkedList* pListaServicios)
{
	int retorno = -1;
	int len;
	eServicio* servicio;

	if(ll_isEmpty(pListaServicios) == 0)
	{
		if(ordenarPorDescripcion(pListaServicios))
		{
			len = ll_len(pListaServicios);
			printf("================================\n");
			printf("            SERVICIOS           \n");
			printf("================================\n");
			for(int i =0; i<len; i++ )
			{
				servicio = ll_get(pListaServicios, i);
				if(servicio != NULL)
				{
					mostrarSoloDescripcion(servicio);
					retorno = 1;
				}
			}
			printf("================================\n");
		}
		else
		{
			printf("Ocurrio un error al mostrar al ordenar los servicios\n");
		}

	}
	else
	{
		if(ll_isEmpty(pListaServicios) == 1)
		{
			retorno = 1;
			printf("\nNecesita cargar el archivo de servicios para poder verlos\n");
		}
	}

	return retorno;
}

int controller_guardarServicios(LinkedList* pListaServicios)
{
	int retorno = -1;

	if(pListaServicios != NULL)
	{
		if(ll_isEmpty(pListaServicios) == 0)
		{
			if(ordenarPorDescripcion(pListaServicios))
			{
				if(cargarDescripciones(pListaServicios))
				{
					retorno = 1;
				}
			}
		}
		else
		{
			retorno = 1;
			printf("\nNecesita primero cargar un archivo\n");
		}
	}

	return retorno;
}
