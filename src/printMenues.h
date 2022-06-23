/*
 * printearMenues.h
 *
 *  Created on: 24 may. 2022
 *      Author: Luciano
 */

#ifndef PRINTEARMENUES_H_
#define PRINTEARMENUES_H_



#endif /* PRINTEARMENUES_H_ */


/**
 * @brief pregunta por el tipo de servicio que desea guardar el usuario
 *
 * @param tipoArchivo
 */
void preguntarTipo(int* tipoArchivo);


/**
 * @brief pregunta el orden en el que quiere el ordenamiento
 *
 * @param orden
 */
void preguntarOrden(int* orden);

/**
 * @brief muestra el menu principal y llama a una funcion para pedir el dato para el case
 *
 * @param opcion (int* )opcion
 */
void mostrarMenuPrincipal(int* opcion);

/**
 * @brief pregunta si se quiere guardar los cambios 1-si, 2-no pidiendo la opcion al usuario y validandola
 *
 * @param confirmar
 */
void guardarCambios(int* confirmar);

/**
 * @brief Si se escoge la opcion salir pide la confirmacion con 1 para si y 2 para no
 *
 * @param salir
 */
void mostrarMenuSalida(int *salir);

/**
 * @brief pregunta si el usiario desea continuar modificando
 *
 * @param continuar
 */
void preguntaContinuar(int* continuar);

/**
 * @brief pregunta sobre la manera de ordenamiento que prefiee el usuario
 *
 * @param sort
 */
void preguntarSort(int* sort);

/**
 * Le pregunta al usuario que lista desea ver
 * @param lista
 */
void preguntarLista(int* lista);

/**
 * Pregunta si el usuario quiere completar el ultim campo
 * @param opcion
 */
void preguntarMap(int* opcion);

