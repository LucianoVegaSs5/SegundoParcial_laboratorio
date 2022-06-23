/*
 * Archivos.h
 *
 *  Created on: 19 jun. 2022
 *      Author: Luciano
 */

#ifndef ARCHIVOS_H_
#define ARCHIVOS_H_


/**
 * Genera un archivo csv con la lista filtrada segun el servicio
 * @param listaFiltrada
 * @param nombreDelArchivo
 * @param tipoServicio
 * @return 1 si esta todo bien, -1 si algo salio mal
 */
int generarArchivoFiltrado(LinkedList* listaFiltrada, char* nombreDelArchivo, char* tipoServicio);

/**
 * genera un archivo con las descripciones de todos los servicios ordenadas alfabeticamente
 * @param pArrayListaServicios
 * @return 1 si esta todo bien, -1 si algo salio mal
 */
int cargarDescripciones(LinkedList* pArrayListaServicios);

/**
 * Genera un archivo con todos los datos de los servicios ordenados pordescripcion
 * @param pArrayListaServicios
 * @return1 si esta todo bien, -1 si algo salio mal
 */
int cargarArchivoOrdenado(LinkedList* pArrayListaServicios);

#endif /* ARCHIVOS_H_ */
