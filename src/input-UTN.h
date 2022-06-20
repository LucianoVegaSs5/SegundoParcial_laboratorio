/*
 * UTN_validaciones.h
 *
 *  Created on: 13 may. 2022
 *      Author: Luciano
 */

#ifndef UTN_VALIDACIONES_H_
#define UTN_VALIDACIONES_H_

#endif /* UTN_VALIDACIONES_H_ */

/**
 * @brief recibe un array y verifica si hay almenos una letra si es asi devuelve -1, sino devuelve 1
 *
 * @param cadena
 * @return 1 si no hay letras, sino devuelve -1
 */
int validarCadenaDeNumeros(char* cadena);


/**
 * @brief pide un nombre por consola y verifica que el array Nombre no tenga numeros y hace un buqle con la variable retorno
 * hasta que se escriba bien el nombre
 *
 * @param nombre (char [])
 * @param mensaje (char [])
 * @param mensajeError (char [])
 * @return retorna 1 si salio todo bien
 */
int pedirString(char* nombre, char* mensaje, char* mensajeError);

/**
 * @brief pide un numero como array y verifica que todos sean numeros, si es asi lo transforma a int y compara que este entre los rangos
 * pedidos, el bucle se hace con la variable retorno
 *
 * @param numero (int*) puntero en el que se guarda la variable
 * @param mensaje  (char  *) mensaje para pedir el dato
 * @param mensajeError (char* ) mensaje usado para indicar el error si no se ingreso numeros
 * @param mensajeError2 (char *) mensaje de error utilizado para indicar que este entre los rangos el numero pedido
 * @param maximo (int)
 * @param minimo (int )
 * @return
 */
int pedirNumeros(int* numero, char* mensaje, char* mensajeError, char* mensajeError2, int maximo, int minimo);

/**
 * @brief pide un numero como array y verifica que todos sean numeros, si es asi lo transforma a float y compara que este entre los rangos
 * pedidos, el bucle se hace con la variable retorno
 *
 * @param numero (float*) puntero en el que se guarda la variable
 * @param mensaje  (char  *) mensaje para pedir el dato
 * @param mensajeError (char* ) mensaje usado para indicar el error si no se ingreso numeros
 * @param mensajeError2 (char *) mensaje de error utilizado para indicar que este entre los rangos el numero pedido
 * @param maximo (int)
 * @param minimo (int )
 * @return
 */
int pedirNumerosFloat(float* numero, char* mensaje, char* mensajeError, char* mensajeError2, int maximo, int minimo);
