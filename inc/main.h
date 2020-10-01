 /*
 * ******************************[Header File]*************************************//**
 * \addtogroup main
 * @{
 * @copyright 
 * 2016, Luccioni Jesús Emanuel. \n
 * All rights reserved.\n
 * This file is part of port module.\n
 * Redistribution is not allowed on binary and source forms, with or without 
 * modification.\n
 * Use is permitted with prior authorization by the copyright holder.\n
 * \file main.h
 * \brief modulo principal "header file". 
 * \version v01.01
 * \date   26 de feb. de 2017
 * \note none
 * \author JEL, Jesus Emanuel Luccioni
 * \li piero.jel@gmail.com
 * 
 *************************************************************************************/
/** @} doxygen end group definition */

#ifndef __main_h__
#define __main_h__
/*
 * ============================[Open, cplusplus]============================
 */
#ifdef __cplusplus
extern "C" {
#endif    

/*
 *   
 * *********************************************************************************************
 *
 * ===========================[ Begin labels definitions  ]============================
 *
 * ******************************************************************************************** 
 * 
 */    
#ifndef __apis_version__
/** 
 * \def __apis_version__
 * @brief Establecemos la Version para el conjunto de APIs locales
 *  \li + 1 : 
 *          @ref keyboard_getline() 
 *          @ref console_printf()
 */   
#define __apis_version__    0
 
#endif  

    
    
 /*
  * 
  *********************************************************************************************
  *
  * ===========================[ End labels definitions    ]============================
  *
  * ********************************************************************************************  
  */      
 /*
 * 
 * 
 * *********************************************************************************************
 *
 * ===========================[ Begin MCROS Functions ]============================
 *
 * ******************************************************************************************** 
 * 
 */      
/*
 * ****************************************************************************//**
 * \def PRINT_SIZE_LEYEND()
 * \brief Macro Funcion para imprimir por pantalla la leyenda correspondiente al
 * macro \ref PRINT_SIZE().
 * \return nothig 
 * \n \e Formato :
 * \n \li \f$ nombre    tamaño[byte]    tamaño[bit]\f$   
 *********************************************************************************/
/*
 * ****************************************************************************//**
 * \def PRINT_SIZE(typeVar)
 * \brief Macro Funcion para imprimir por pantalla el tamaño del tipo de variable
 * \e typeVar, pasado como parametro. Con el formato especificado por la leyenda 
 * establecida en \ref PRINT_SIZE_LEYEND().
 * \return nothig 
 * \n \e Formato :
 * \n \li \f$ nombre    tamaño[byte]    tamaño[bit]\f$   
 *********************************************************************************/ 
#if defined(__M32__)
#define PRINT_SIZE_LEYEND()     printf("\tnombre\t\ttamaño [Bytes]\t\ttamaño [bits]\n")
#define PRINT_SIZE(typeVar)     printf("    %-20s    %-20d    %-20d\n",#typeVar,sizeof(typeVar),(sizeof(typeVar)*8))
/*#define STDstream_PRINT(STDtype)	#STDtype"\t%d\n",STDtype*/
#elif defined(__M64__)
#define PRINT_SIZE_LEYEND()     printf("\tnombre\t\ttamaño [Bytes]\t\ttamaño [bits]\n")
#define PRINT_SIZE(typeVar)     printf("    %-20s    %-20ld    %-20ld\n",#typeVar,sizeof(typeVar),(sizeof(typeVar)*8))
#elif defined(__Mhost__)
#define PRINT_SIZE_LEYEND()     
#define PRINT_SIZE(typeVar)     
#else 
#warning "Arquitectura definida de forma incorrecta"
#define PRINT_SIZE_LEYEND()     
#define PRINT_SIZE(typeVar)     
#endif
/*
 * 
 * *********************************************************************************************
 *
 * ===========================[ End Macros Functions ]============================
 *
 * ******************************************************************************************** 
 */  
/*
 * 
 * 
 * *********************************************************************************************
 *
 * ===========================[ Begin APIs Declaration ]============================
 *
 * ******************************************************************************************** 
 * 
 */
#if (__apis_version__ == 1)
/*
* 
┌────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                    │  
│                                                                                    │  
│ ─────────────────────────[ Begin apis version 01     ]────────────────────────     │
│                                                                                    │
│                                                                                    │             
└────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 01
*/
/*
*
* ****************************************************************************//**
* \fn void keyboard_getline(const char * format, ...)
* \brief descripcion breve
* \param format: string con formato.
* \param ... : listado de argumento que se corresponde string con formato
* \return nothing
*********************************************************************************/
void keyboard_getline(const char * format, ...);
/*
*
* ****************************************************************************//**
* \fn void console_printf(const char * format, ... )
* \brief descripcion breve
* \param format: string con formato.
* \param ... : listado de argumento que se corresponde string con formato
* \return nothing
*********************************************************************************/
void console_printf(const char * format, ... );
/*
*
* ****************************************************************************//**
* \fn void string_PlaceText(char *pS,const char *txt )
* \brief Funcion para colocar una linea de texto en un string o array del 
* tipo char.
* \param pS: Puntero al String (array del tipo char).
* \param txt: Puntero al array que contiene el string a colocar, o un string 
* del tipo "place text".
* \return nothing  
*********************************************************************************/
void string_PlaceText(char *pS,const char *txt );

/*
*
* ****************************************************************************//**
* \fn uint32_t factorial(uint32_t n);
* \brief funcion recursiva para el calculo del factorial
 * \f[
 * n! = \prod_{k=1}^n (k)
 * \f]
* \param value: valor sobre el cual se requiere obtener el factorial.
*   \li should be un valor del tipo entero positivo.
* \return valor entero que representa el factorial
* \author jel 
* \note
*********************************************************************************/
uint32_t factorial(uint32_t n);
/*
┌────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                    │  
│                                                                                    │  
│ ─────────────────────────[ End apis version 01       ]────────────────────────     │
│                                                                                    │
│                                                                                    │             
└────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif(__apis_version__ == 2)

/*
* 
┌────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                    │  
│                                                                                    │  
│ ─────────────────────────[ Begin apis version 02     ]────────────────────────     │
│                                                                                    │
│                                                                                    │             
└────────────────────────────────────────────────────────────────────────────────────┘
TODO: version 02
*/
#warning "version aun no definida"

/*
┌────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                    │  
│                                                                                    │  
│ ─────────────────────────[ End apis version 02       ]────────────────────────     │
│                                                                                    │
│                                                                                    │             
└────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#else /* #if (__apis_version__ == 1) */
/* #warning "__apis_version__ estabelcido de forma incorrecta"*/
#endif /* #if (__apis_version__ == 1) */
/*
 * 
 * *********************************************************************************************
 *
 * ===========================[ End APIs Declaration ]============================
 *
 * ******************************************************************************************** 
 */    
/*
 * 
 * 
 * *********************************************************************************************
 *
 * ===========================[ Begin main Declaration ]============================
 *
 * ******************************************************************************************** 
 * 
 */
/*
*
* ****************************************************************************//**
* \fn int main(int argn,char **arg);
* \brief funcion principal punto de partida de la aplicacion.
* \param argn numeros de Arguemtnos por defecto es '1'.
* \param arg array de arguemento, arg[0] := path/appname.
* \return return estado de la ejecucion.
 *  + EXIT_SUCCESS : ejecucion finalizada de forma exitosa.
 *  + EXIT_FAIL : ejecucion finalizada con error.
*********************************************************************************/
int main(int argn,char **arg);
/*
 * 
 * *********************************************************************************************
 *
 * ===========================[ End main Declaration ]============================
 *
 * ******************************************************************************************** 
 * 
 * 
 */
/*
 * ============================[close, cplusplus]============================
 */
#ifdef __cplusplus
}
#endif
/** @} doxygen end group definition */
/*==================[end of file]============================================*/
#endif /* #ifndef __main_h__ */
