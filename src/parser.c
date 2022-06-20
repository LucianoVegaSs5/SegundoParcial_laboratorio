/*
 * parser.c
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

int parser_servicioFromTxt(LinkedList* pListaServicios,FILE* pFile)
{
	int retorno;
	char idAux[4];
	char descripcionAux[25];
	char tipoAux[4];
	char precioUnitarioAux[25];
	char cantidadAux[8];
	char precioTotalAux[25];

	eServicio* servicioAux;

	if(pListaServicios != NULL && pFile != NULL)
	{
		fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", idAux, descripcionAux, tipoAux, precioUnitarioAux, cantidadAux, precioTotalAux);
		do
		{
			if(fscanf(pFile,"%[^,], %[^,], %[^,], %[^,], %[^,], %[^\n]\n", idAux, descripcionAux, tipoAux, precioUnitarioAux, cantidadAux, precioTotalAux) != 1)
			{
				servicioAux = Servicio_newParametros(idAux,descripcionAux,tipoAux,precioUnitarioAux,cantidadAux, precioTotalAux);
				if(servicioAux != NULL)
				{
					ll_add(pListaServicios, servicioAux);
					retorno = 1;
				}
				else
				{
					printf("Error al levantar datos, porfavor intentelo de nuevo\n");
				}
			}

		}while(!feof(pFile));

	}
	else
	{
		printf("Lo sentimos! Hubo urror al cargar el archivo modo txt.\n");
	}

	return retorno;
}

