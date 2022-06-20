/*
 * eServicios.h
 *
 *  Created on: 18 jun. 2022
 *      Author: Luciano
 */

#ifndef ESERVICIOS_H_
#define ESERVICIOS_H_


typedef struct
{
	int id;
	char descripcion[50];
	int tipo;
	float precioUnitario;
	int cantidad;
	float precioTotal;
} eServicio;

/**
 * Construnctor tipo eServicio
 * @return la entidad con su espacio en memoria dinamica
 */
eServicio* Servicio_new();

/**
 * Libera la memoria del servicio
 * @param this
 */
void Servicio_delete(eServicio* this);

int Servicio_setId(eServicio* this,int id);
int Servicio_getId(eServicio* this,int* id);

int Servicio_setdescripcion(eServicio* this,char* descripcion);
int Servicio_getdescripcion(eServicio* this,char* descripcion);

int Servicio_setTipo(eServicio* this,int tipo);
int Servicio_getTipo(eServicio* this,int* tipo);

int Servicio_setPrecioUnitario(eServicio* this, float precioUnitario);
int Servicio_getPrecioUnitario(eServicio* this,float* precioUnitario);

int Servicio_setCantidad(eServicio* this,int cantidad);
int Servicio_getCantidad(eServicio* this,int* cantidad);

int Servicio_setPrecioTotal(eServicio* this, float precioTotal);
int Servicio_getPrecioTotal(eServicio* this,float* precioTotal);

/**
 * Constructor de una variable tipo eServicio que que recibe por parametros todos los campos y llama a la funcion Servicio_new()
 * @param idStr
 * @param descripcionStr
 * @param tipoStr
 * @param precioUnitarioStr
 * @param cantidadStr
 * @param precioTotalStr
 * @return eServicio con los campos recibidos por parametros
 */
eServicio* Servicio_newParametros(char* idStr,char* descripcionStr,char* tipoStr, char* precioUnitarioStr, char* cantidadStr, char* precioTotalStr);

/**
 * muestra todos los campos de la estructura eServico recibida por parametro
 * @param this
 */
void Servicio_print(eServicio* this);

/**
 * Completa el campo precio total multiplicando el campo cantidad por el campo precioUnitario de cada servicio
 * @param servicio
 */
void calcularTotal(void* servicio);

/**
 * Funciones que filtran por tipo de servicio exportar/Mayorista/minorista
 * @param servicio
 * @return retorna 1 si pas el filtro y -1 si no lo pasa
 */
int filtrarTipoExportar(void* servicio);
int filtrarTipoMayorista(void* servicio);
int filtrarTipoMinorista(void* servicio);

/**
 * muestra el campo descripcion del servicio recibido por parametro
 * @param servicio
 */
void mostrarSoloDescripcion(eServicio* servicio);

/**
 * Compara entre la descripcion de dos servicios para ordenarlas alfabeticamente
 * @param servicioUno
 * @param servicioDos
 * @return retorna 1 si esta bien el orden y -1 si hay que cambiar pocisiones
 */
int Servicio_sortByDesc(void* servicioUno, void* servicioDos);


#endif /* ESERVICIOS_H_ */
