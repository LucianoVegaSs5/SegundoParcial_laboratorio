/*
 * eServicios.c
 *
 *  Created on: 18 jun. 2022
 *      Author: Luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "input-UTN.h"
#include "eServicios.h"

eServicio* Servicio_new()
{
	eServicio* NuevoPasajero = (eServicio*) malloc(sizeof(eServicio));

	return NuevoPasajero;
}

void Servicio_delete(eServicio* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

int Servicio_setId(eServicio* this,int id)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->id = id;

		retorno = 1;
	}

	return retorno;
}
int Servicio_getId(eServicio* this,int* id)
{
	int retorno = -1;

	if(this != NULL)
	{
		*id = this->id;
		retorno = 1;

	}
	return retorno;
}

int Servicio_setdescripcion(eServicio* this,char* descripcion)
{
	int retorno = -1;

	if(this !=  NULL && descripcion != NULL)
	{
		strcpy(this->descripcion,descripcion);
		retorno = 1;
	}

	return retorno;
}
int Servicio_getdescripcion(eServicio* this,char* descripcion)
{
	int retorno = -1;

	if(this !=  NULL)
	{
		strcpy(descripcion,this->descripcion);
		retorno = 1;
	}

	return retorno;
}

int Servicio_setTipo(eServicio* this,int tipo)
{
	int retorno = -1;

	if(this !=  NULL)
	{
		this->tipo = tipo;
		retorno = 1;
	}

	return retorno;
}
int Servicio_getTipo(eServicio* this,int* tipo)
{
	int retorno = -1;

	if(this !=  NULL)
	{
		*tipo = this->tipo;
		retorno = 1;
	}

	return retorno;
}

int Servicio_setPrecioUnitario(eServicio* this, float precioUnitario)
{
	int retorno = -1;

	if(this != NULL && precioUnitario > 0)
	{
		this->precioUnitario = precioUnitario;
		retorno = 1;
	}

	return retorno;
}
int Servicio_getPrecioUnitario(eServicio* this,float* precioUnitario)
{
	int retorno = -1;

	if(this !=  NULL)
	{
		*precioUnitario = this->precioUnitario;
		retorno = 1;
	}

	return retorno;
}

int Servicio_setCantidad(eServicio* this,int cantidad)
{
	int retorno = -1;

	if(this !=  NULL)
	{
		this->cantidad = cantidad;
		retorno = 1;
	}

	return retorno;
}
int Servicio_getCantidad(eServicio* this,int* cantidad)
{
	int retorno = -1;

	if(this !=  NULL)
	{
		*cantidad = this->cantidad;
		retorno = 1;
	}

	return retorno;
}

int Servicio_setPrecioTotal(eServicio* this, float precioTotal)
{
	int retorno = -1;

	if(this != NULL)
	{
		this->precioTotal = precioTotal;
		retorno = 1;
	}

	return retorno;
}
int Servicio_getPrecioTotal(eServicio* this,float* precioTotal)
{
	int retorno = -1;

	if(this !=  NULL)
	{
		*precioTotal = this->precioTotal;
		retorno = 1;
	}

	return retorno;
}

eServicio* Servicio_newParametros(char* idStr,char* descripcionStr,char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* precioTotalStr)
{
	eServicio* servicio;
	servicio = Servicio_new();

	int validarCampos = 0;

	if(Servicio_setId(servicio, atoi(idStr)))
	{
		if(Servicio_setdescripcion(servicio, descripcionStr))
		{
			if(Servicio_setTipo(servicio, atoi(tipoStr)))
			{
				if(Servicio_setPrecioUnitario(servicio, atof(precioUnitarioStr)))
				{
					if(Servicio_setCantidad(servicio, atoi(cantidadStr)))
					{
						if(Servicio_setPrecioTotal(servicio, atof(precioTotalStr)))
						{
							validarCampos = 1;
						}
					}
				}
			}
		}
	}

	if(validarCampos == 0)
	{
		servicio = NULL;
	}

	return servicio;
}

void Servicio_print(eServicio* this)
{
	if(this != NULL)
	{
		int id;
		char descripcion[50];
		float precioUnitario;
		int tipo;
		char tipoString[20];
		int cantidad;
		float precioTotal;

		if(Servicio_getId(this, &id))
		{
			if(Servicio_getdescripcion(this, descripcion))
			{
				if(Servicio_getPrecioUnitario(this, &precioUnitario))
				{
					if(Servicio_getCantidad(this, &cantidad))
					{
						if(Servicio_getPrecioTotal(this, &precioTotal))
						{
							if(Servicio_getTipo(this, &tipo))
							{
								if(tipo == 1)
								{
									strcpy(tipoString, "MINORISTA");
								}
								else
								{
									if(tipo == 2)
									{
										strcpy(tipoString, "MAYORISTA");
									}
									else
									{
										strcpy(tipoString, "EXPORTAR");
									}
								}

								printf("%-6d||%-25s||%-12s\t||%-15.2f\t||%-6d\t||%.2f\n", id, descripcion, tipoString, precioUnitario, cantidad, precioTotal);
							}
						}
					}
				}
			}
		}
	}
}

void calcularTotal(void* servicio)
{
	float precioTotal;
	int cantidad;
	float precioUnitario;
	if(servicio != NULL)
	{
		if(Servicio_getPrecioTotal(servicio, &precioTotal))
		{
			if(Servicio_getCantidad(servicio, &cantidad))
			{
				if(Servicio_getPrecioUnitario(servicio, &precioUnitario))
				{
					precioTotal = cantidad * precioUnitario;
					Servicio_setPrecioTotal(servicio, precioTotal);

				}
			}
		}
	}
}

int filtrarTipoMinorista(void* servicio)
{
	int retorno = 0;
	int tipo;

	if(servicio!= NULL)
	{
		if(Servicio_getTipo(servicio, &tipo))
		{
			if(tipo == 1)
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}

int filtrarTipoMayorista(void* servicio)
{
	int retorno = 0;
	int tipo;

	if(servicio!= NULL)
	{
		if(Servicio_getTipo(servicio, &tipo))
		{
			if(tipo == 2)
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}

int filtrarTipoExportar(void* servicio)
{
	int retorno = 0;
	int tipo;

	if(servicio!= NULL)
	{
		if(Servicio_getTipo(servicio, &tipo))
		{
			if(tipo == 3)
			{
				retorno = 1;
			}
		}
	}
	return retorno;
}

void mostrarSoloDescripcion(eServicio* servicio)
{
	char descripcion[50];

	if(servicio != NULL)
	{
		if(Servicio_getdescripcion(servicio, descripcion))
		{
			printf("||-%-28s||\n",descripcion);
		}
	}
}

int Servicio_sortByDesc(void* servicioUno, void* servicioDos)
{
	int retorno = -1;
	char descripcionUno[50];
	char descripcionDos[50];

	if(servicioUno != NULL && servicioDos != NULL)
	{
		if(Servicio_getdescripcion(servicioUno, descripcionUno))
		{
			if(Servicio_getdescripcion(servicioDos, descripcionDos))
			{
				if(strcmp(descripcionUno, descripcionDos) <= 0)
				{
					retorno = -1;
				}
				else
				{
					retorno = 1;
				}
			}
		}
	}

	return retorno;
}
