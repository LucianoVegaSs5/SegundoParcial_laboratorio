/*
 * Controller.h
 *
 *  Created on: 18 jun. 2022
 *      Author: Luciano
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

/**
 * Carga el archivo de servicios llamando a la funcion parser que los carga en un linkedlist
 * @param pListaServicios
 * @param cargaArchivo
 * @return 1 si esta todo bien, -1 si algo salio mal
 */
int controller_cargarArchivoTxt(LinkedList* pListaServicios, int* cargaArchivo);

/** Lista todos los servicios de la linkedlist por campos
 *
 * @param pListaServicios
 * @return 1 si esta todo bien, -1 si algo salio mal
 */
int controller_listServicios(LinkedList* pListaServicios);

/**
 * Llama a la funcion ll_map que completa calculando el campo precioTotal de los servvicios
 * @param pListaServicios
 * @return 1 si esta todo bien, -1 si algo salio mal
 */
int controller_completarPrecioTotal(LinkedList* pListaServicios);

/**
 * Pregunta que tipo de servicio quiere filtrar el usuario para luego crear un archivo
 * @param pListaServicios
 * @return
 */
int controller_filtrarServicios(LinkedList* pListaServicios);

/**
 * Verfica que el nombre del archivo ingresado no sea una previamente filtrado
 * @param nombreArchivo
 * @return -1 si el archivo es filtrado, 1 sino lo es
 */
int verificarArhcivoFiltrado(char* nombreArchivo);

/**
 *  Muestra todas las descripciones de los servicios ordenados alfabeticamente
 * @param pListaServicios
 * @return 1 si esta todo bien, -1 si algo salio mal
 */
int controller_mostrarServicios(LinkedList* pListaServicios);

/**
 * Guarda la lista de las descripciones de los servicios en un archivo .csv
 * @param pListaServicios
 * @return 1 si esta todo bien, -1 si algo salio mal
 */
int controller_guardarServicios(LinkedList* pListaServicios);

#endif /* CONTROLLER_H_ */
