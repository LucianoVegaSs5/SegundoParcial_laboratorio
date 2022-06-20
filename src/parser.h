/*
 * parser.h
 *
 *  Created on: 18 jun. 2022
 *      Author: Luciano
 */

#ifndef PARSER_H_
#define PARSER_H_

/**
 * 	recibe un puntero a file y una linkedlist donde todos los archivos los leera y los añadira a la linkedlist transformando los campos
 * @param pListaServicios
 * @param pFile
 * @return 1 si esta todo bien, -1 si algo salio mal
 */
int parser_servicioFromTxt(LinkedList* pListaServicios,FILE* pFile);



#endif /* PARSER_H_ */
