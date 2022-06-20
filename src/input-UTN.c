/*
 * UTN.validaciones.c
 *
 *  Created on: 13 may. 2022
 *      Author: Luciano
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>




void getNumeroValidarMaxMin(int* numero, char mensaje[],char mensajeError[], int max, int min)
{
    int flag = 1;

    do{
        if(flag== 1)
        {
            printf("%s", mensaje);
            fflush(stdin);
            scanf("%d", numero);
            flag = 0;
        }
        else
        {
            printf("%s", mensajeError);
            fflush(stdin);
            scanf("%d", numero);
        }


    }while(*numero < min || *numero > max );
}

void ponerMayusculas(char* nombre)
{
    strlwr(nombre);

	nombre[0] = toupper(nombre[0]);

	for(int i = 0; i < strlen(nombre); i++)
	{
		if (nombre[i] == ' ')
		{
			nombre[i + 1] = toupper(nombre[i + 1]);
		}
	}

}

int pedirString(char* string, char* mensaje, char* mensajeError)
{
	int retorno = -1;
	int i;

	do
	{
		printf("%s",mensaje);
		fflush(stdin);
		gets(string);

		for (i = 0; i < strlen(string); i++)
		{
			if(isalpha(*(string+i)) == 0 && isspace(*(string+i))== 0 )
			{
				retorno = -1;
				printf("%s\n", mensajeError);
				break;
			}

			retorno = 1;
		}

	}while(retorno != 1);

	ponerMayusculas(string);

	return retorno;
}

int validarCadenaDeNumeros(char* cadena)
{
   int i=0;
   int retorno = 1;

   while(cadena[i] != '\0')
   {
       if(cadena[i] < '0' || cadena[i] > '9')
       {
           retorno = 0;
       }

       i++;
   }

   return retorno;
}

int pedirNumeros(int* numero, char* mensaje, char* mensajeError, char* mensajeError2, int maximo, int minimo)
{
    int validarCadena;
    char cadenaNumeros[20];
    int retorno;
    int numeroAux;

    do
    {
        if(cadenaNumeros != NULL && mensaje !=  NULL && mensajeError != NULL)
        {
            printf("%s", mensaje);
            fflush(stdin);
            gets(cadenaNumeros);

            validarCadena = validarCadenaDeNumeros(cadenaNumeros);
            if(validarCadena == 1)
            {
                numeroAux = atoi(cadenaNumeros);

                if(numeroAux < minimo || numeroAux > maximo)
                {
                    printf("%s", mensajeError2);
                        retorno = -1;
                }
                else
                {
                    retorno = 1;
                    *numero = numeroAux;
                }
            }
            else
            {
                printf("%s", mensajeError);
                retorno = -1;
            }
        }

    }while(retorno != 1);

    return retorno;
}
int pedirNumerosFloat(float* numero, char* mensaje, char* mensajeError, char* mensajeError2, int maximo, int minimo)
{
    int validarCadena;
    char cadenaNumeros[20];
    int retorno;
    float numeroAux;

    do
    {
        if(cadenaNumeros != NULL && mensaje !=  NULL && mensajeError != NULL)
        {
            printf("%s", mensaje);
            fflush(stdin);
            gets(cadenaNumeros);

            validarCadena = validarCadenaDeNumeros(cadenaNumeros);
            if(validarCadena == 1)
            {
                numeroAux = atof(cadenaNumeros);

                if(numeroAux < minimo || numeroAux > maximo)
                {
                    printf("%s", mensajeError2);
                        retorno = -1;
                }
                else
                {
                    retorno = 1;
                    *numero = numeroAux;
                }
            }
            else
            {
                printf("%s", mensajeError);
                retorno = -1;
            }
        }

    }while(retorno != 1);

    return retorno;
}


void getNumeroValidarMaxMinFloat(float *numero, char mensaje[],char mensajeError[], int max, int min)
{

    int flag = 1;

    do
    {
        if (flag== 1)
        {
            printf("%s\n", mensaje);
            fflush(stdin);
            scanf("%f", numero);
            flag = 0;
        }
        else
        {
            printf("%s\n", mensajeError);
            fflush(stdin);
            scanf("%f", numero);
        }


    }while(*numero < min || *numero > max );

}
