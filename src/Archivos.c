/*
 * Archivos.c
 *
 *  Created on: 19 jun. 2022
 *      Author: Luciano
 */

#include "linkedList.h"
#include "printMenues.h"
#include "eServicios.h"
#include "input-UTN.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>

int generarArchivoFiltrado(LinkedList* listaFiltrada, char* nombreDelArchivo, char* tipoServicio)
{
	int retorno = 0;
	FILE* pFile;
	int len;
	eServicio* servicioAux;

	int idAux;
	char idAuxChar[4];
	char descripcionAux[25];
	char precioUnitarioAuxChar[25];
	float precioUnitarioAux;
	char cantidadAuxChar[8];
	int cantidad;
	char precioTotalAuxChar[25];
	float precioTotalAux;

	if(listaFiltrada != NULL)
	{
		pFile = fopen(nombreDelArchivo, "w");

		if(pFile != NULL)
		{
			len = ll_len(listaFiltrada);

			fprintf(pFile, "id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio\n");

			for(int i = 0; i<len; i++)
			{
				servicioAux = ll_get(listaFiltrada, i);

				if(servicioAux != NULL)
				{
					if(Servicio_getId(servicioAux, &idAux))
					{
						if(Servicio_getdescripcion(servicioAux, descripcionAux))
						{
							if(Servicio_getPrecioUnitario(servicioAux, &precioUnitarioAux))
							{
								if(Servicio_getCantidad(servicioAux, &cantidad))
								{
									if(Servicio_getPrecioTotal(servicioAux, &precioTotalAux))
									{
										itoa(idAux,idAuxChar,10);
										gcvt(precioUnitarioAux,5,precioUnitarioAuxChar);
										itoa(cantidad, cantidadAuxChar, 10);
										gcvt(precioTotalAux,5,precioTotalAuxChar);

										fprintf(pFile,"%s,%s,%s,%s,%s,%s\n",idAuxChar,descripcionAux,tipoServicio,precioUnitarioAuxChar,cantidadAuxChar,precioTotalAuxChar);
										retorno = 1;

									}
								}
							}
						}
					}
				}
			}
			fclose(pFile);
		}
	}

	return retorno;
}

int cargarArchivoOrdenado(LinkedList* pArrayListaServicios)
{
	int retorno = -1;

	int len;
	FILE* pFile;
	eServicio* servicioAux;
	char nombreArchivo[] = "servDesc.csv";


	int idAux;
	char idAuxChar[4];
	char descripcionAux[25];
	char precioUnitarioAuxChar[25];
	float precioUnitarioAux;
	char cantidadAuxChar[8];
	int cantidad;
	char precioTotalAuxChar[25];
	float precioTotalAux;
	char tipoServicio[25];
	int tipoAux;


	if(pArrayListaServicios != NULL)
	{
		pFile = fopen("servDesc.csv", "w");

		if(pFile != NULL)
		{
			len = ll_len(pArrayListaServicios);

			fprintf(pFile, "id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio\n");

			for(int i = 0; i<len; i++)
			{
				servicioAux = ll_get(pArrayListaServicios, i);

				if(servicioAux != NULL)
				{
					if(Servicio_getId(servicioAux, &idAux))
					{
						if(Servicio_getdescripcion(servicioAux, descripcionAux))
						{
							if(Servicio_getPrecioUnitario(servicioAux, &precioUnitarioAux))
							{
								if(Servicio_getCantidad(servicioAux, &cantidad))
								{
									if(Servicio_getPrecioTotal(servicioAux, &precioTotalAux))
									{
										Servicio_getTipo(servicioAux, &tipoAux);
										if(tipoAux == 1)
										{
											strcpy(tipoServicio, "MINORISTA");
										}
										else
										{
											if(tipoAux == 2)
											{
												strcpy(tipoServicio, "MAYORISTA");
											}
											else
											{
												strcpy(tipoServicio, "EXPORTAR");
											}
										}
										itoa(idAux,idAuxChar,10);
										gcvt(precioUnitarioAux,5,precioUnitarioAuxChar);
										itoa(cantidad, cantidadAuxChar, 10);
										gcvt(precioTotalAux,5,precioTotalAuxChar);

										fprintf(pFile,"%s,%s,%s,%s,%s,%s\n",idAuxChar,descripcionAux,tipoServicio,precioUnitarioAuxChar,cantidadAuxChar,precioTotalAuxChar);
										retorno = 1;

									}
								}
							}
						}
					}
				}
			}

			printf("\nEl archivo se creo con exito!\n");
			printf("El nombre del archivo es: - %s -\n", nombreArchivo);
			fclose(pFile);
		}
	}

	return retorno;
}


int cargarDescripciones(LinkedList* pArrayListaServicios)
{
	int retorno = -1;
	int len;
	FILE* pFile;
	eServicio* servicioAux;
	char descripcionAux[50];
	char nombreArchivo[] = "servDesc.csv";

	if(pArrayListaServicios != NULL)
	{
		pFile = fopen("servDesc.csv", "w");

		if(pFile != NULL)
		{
			len = ll_len(pArrayListaServicios);

			fprintf(pFile, "descripcion_servicios\n");

			for(int i = 0; i<len; i++)
			{
				servicioAux = ll_get(pArrayListaServicios, i);

				if(Servicio_getdescripcion(servicioAux, descripcionAux))
				{
					fprintf(pFile,"%s\n",descripcionAux);
					retorno = 1;
				}
			}

			printf("\nEl archivo se creo con exito!\n");
			printf("El nombre del archivo es: - %s -\n", nombreArchivo);
			fclose(pFile);
		}
	}

	return retorno;
}
