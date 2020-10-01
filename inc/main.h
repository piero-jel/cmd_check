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
 * ****************************************************************************************************
 *
 * ===========================[ Begin APIs, macros , typedef Declaration ]============================
 *
 * ***************************************************************---------*****************************
 * 
 */


#if (__main_version__ == 0)
/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ Begin apis main version 0    ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
TODO: main version 0
*/


/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ End apis main version 0      ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (__main_version__ == 1)
/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ Begin apis main version 1    ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
TODO: main version 1
*/
/**
* \typedef fx_optiont_pfT
* \brief example de redifinicion puntero a funcion
*  prototipo: unsigned int fx (unsigned int,unsigned int);
* \note
* \warning
*
*/
typedef int (*fx_optiont_pfT) (char *arg);
/**
* \typedef menu_t ;
* \brief definimos el tipo de estructura
* \ref vtchar
* \ref vtint
* \ref vtdouble
* \note
* \warning
*/
typedef struct
{
    const char * opt ;     /**<@brief valor del tipo int */
    const char * leyenda ;
    //
    fx_optiont_pfT fxOption ;  /**<@brief valor del tipo double */
}menu_t;

/**
 * ****************************************************************************//**
 * \fn int option_lg(char * arg   );
 * \brief descripcion breve.
 * \details descripcon detallada.
 * \param arg : Argumento uno del tipo puntero a char, string .
 * \return valor de retorno del tipo int.
 * \note nota sobre la funcion.
 * \warning mensaje de precaucion sobre la funcion.
 * \par example :
  <PRE>
  op = option_lg("on" );
  </PRE>
 *********************************************************************************/
int option_lg(char * arg);
/**
 * ****************************************************************************//**
 * \fn int option_usb(char * arg   );
 * \brief descripcion breve.
 * \details descripcon detallada.
 * \param arg : Argumento uno del tipo puntero a char, string .
 * \return valor de retorno del tipo int.
 * \note nota sobre la funcion.
 * \warning mensaje de precaucion sobre la funcion.
 * \par example :
  <PRE>
  op = option_usb("view" );
  </PRE>
 *********************************************************************************/
int option_usb(char * arg);
fx_optiont_pfT get_funtionOption(menu_t *pmenu, char * option);
void print_menu(menu_t *pmenu);

/*
*
* ──────────────────────────[ Begin section lg ]────────────────────────
* definimos los string de opcion, leyenda y tambien la funcion para "lg"
*/
#define LEYEND_lg() \
   "--lg        : Visualiza los datos del LG\n"\
   "--lg on     : Habilita el LG (Base de Datos qTotem)\n"\
   "--lg off    : Deshabilita el LG (Base de Datos qTotem)\n"\
   "--lg up     : Realiza la secuencia para habilitar el LG. Detiene el Totem, habilita el LG y vuelve a iniciar el Totem.\n"\
   "--lg down   : Realiza la secuencia para deshabilitar el LG. Detiene el Totem, deshabilita el LG y vuelve a iniciar el Totem.\n"\

#define FUNCTION_lg() option_lg
#define OPTION_lg	"--lg"
/*
* ────────────────────────────[ End section lg ]─────────────────────────
*/
/*
*
* ──────────────────────────[ Begin section usb ]────────────────────────
* definimos los string de opcion, leyenda y tambien la funcion para "usb"
*/
typedef struct{
	 const char * id;
	 const char * brief;
}list_usb_sT;

/*
 *
Bus 007 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 002 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 006 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 005 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 001 Device 001: ID 1d6b:0002 Linux Foundation 2.0 root hub
Bus 004 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub
Bus 003 Device 002: ID 046d:c534 Logitech, Inc. Unifying Receiver
Bus 003 Device 001: ID 1d6b:0001 Linux Foundation 1.1 root hub

 */
list_usb_sT listDeviceUSB[]={
		  {"1d6b:0001","Linux Foundation 1.1 root hub"}
		 ,{"1d6b:0002","Linux Foundation 2.0 root hub"}
		 ,{"046d:c534","Logitech, Inc. Unifying Receiver"}
		 ,{NULL}
};

#define LEYEND_usb() \
   "--usb       : Realiza el check de los dispositivos USB que deben estar enumerados.\n"\
   "--usb view  : Visualiza todos los dispositivos conectados a los diferentes HUB USB.\n"\
   "--usb rules : Visualiza el contenido del archivo rules para el LG.\n"\
   "--usb update : Actualiza el contenido del archivo rules para el LG.\n"\

#define FUNCTION_usb() option_usb
#define OPTION_usb	"--usb"
/*
*
* ────────────────────────────[ End section usb ]─────────────────────────
*
*/




//#define OPTION(Opt) "--"#Opt
#define OPTION(Opt) OPTION_##Opt
#define LEYEND(Option) LEYEND_##Option()
#define FUNCTION(Option) FUNCTION_##Option()

/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ End apis main version 1      ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (__main_version__ == 2)
/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ Begin apis main version 2    ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
TODO: main version 2
*/


/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ End apis main version 2      ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (__main_version__ == 3)
/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ Begin apis main version 3    ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
TODO: main version 3
*/


/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ End apis main version 3      ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (__main_version__ == 4)
/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ Begin apis main version 4    ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
TODO: main version 4
*/


/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ End apis main version 4      ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (__main_version__ == 5)
/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ Begin apis main version 5    ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
TODO: main version 5
*/

/**
 * \typedef pFproccessQuery_pfT
 * \brief redefinicion de un puntero a funcion el cual toma como
 * argumento el numero de fila 'row', columna 'col' y el estring
 * campo. El resultado de la consulta en el campo fila columna establecido.
 * \details descripcion detallada
 * \note prototipo de funcion "void function (int row,int col, const char *strFied);"
 * \warning mensaje de precaucion sobre esta redefinicion
 */
typedef void (*pFproccessQuery_pfT) (int row,int col, const char *strFied);

typedef struct
{
	const char * query; /**<@brief string de la consulta */
	const char * leyenda; /**<@brief descripcion de la consulta  */
	//unsigned int col; /**<@brief Columna que necesitamos, si es 0xFFFFFFFF traemos todas */
}listQuery_sT;


/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ End apis main version 5      ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (__main_version__ == 6)
/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ Begin apis main version 6    ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
TODO: main version 6
*/
/*-- solo para eclipse, es automatico en el proceso de compilacion
 * y lo podmeos agregar desde Project -> Properties -> Patha and Symbols {solapa} symbols */
/* #define REMOTO_CONNECT */
#if ( defined(REMOTO_CONNECT))
#define CONN_INFO() \
		"user = postgres password = postgres \
	     hostaddr = 127.0.0.1 port = 5678 \
		 connect_timeout = 2\
		 dbname = "
#else/* #if (REMOTO_CONNECT == 1) */
#define CONN_INFO() \
		"user = postgres password = postgres \
	     hostaddr = 127.0.0.1 port = 5432 \
		 connect_timeout = 2\
		 dbname = "
#endif /*#if (REMOTO_CONNECT == 1)*/

/**
 * \typedef pFproccessQuery_pfT
 * \brief redefinicion de un puntero a funcion el cual toma como
 * argumento el numero de fila 'row', columna 'col' y el estring
 * campo. El resultado de la consulta en el campo fila columna establecido.
 * \details descripcion detallada
 * \note prototipo de funcion "void function (int row,int col, const char *strFied);"
 * \warning mensaje de precaucion sobre esta redefinicion
 */
typedef void (*pFproccessQuery_pfT) (int row,int col, const char *strFied);
typedef void (*pFemptlyQuery_pfT) (const char *leyendQuery);

typedef struct
{
	const char * query; /**<@brief string de la consulta */
	const char * leyenda; /**<@brief descripcion de la consulta  */
	pFproccessQuery_pfT proccessQuery; /**<@brief puntero a funcion que llama con el
	el campo resultado de la consulta */
	pFemptlyQuery_pfT emptlyQuery;/**<@brief puntero a funcion que llama cuando el resultado
	de la query esta vacia */
}query_sT;

/**
 *
 * ****************************************************************************//**
 * \fn int proccessListQuery(const char * connInfo   );
 * \brief descripcion breve.
 * \details descripcon detallada.
 * \param dbName : Nombre de la base de datos.
 * \param pListQuery : Lista de consultas.
 * \return valor de retorno del tipo int.
 * \note nota sobre la funcion.
 * \warning mensaje de precaucion sobre la funcion.
 * \par example :
  <PRE>
  if( proccessListQuery(arg_1))
  {
  	  ...success process
  }
  {
  	  ... failure process
  }
  </PRE>
 *********************************************************************************/
int proccessListQuery(const char *dbName, query_sT *pListQuery);
/**
 *
 * ****************************************************************************//**
 * \fn void print_field_query(int  r ,int c , const char * strQ);
 * \brief callback, no es llamada como una API. Es llamada automaticamente
 * al realizar la consulta de la base de datos.
 * \details descripcon detallada.
 * \param r : Argumento uno del tipo int.
 * \param , const char * strQ : Argumento uno del tipo ,int.
 * \return valor de retorno del tipo void.
 * \note nota sobre la funcion.
 * \warning mensaje de precaucion sobre la funcion.
 *
 *********************************************************************************/
void print_field_query(int r,int c, const char *strQ);

void print_emptly_query(const char *stley);

/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ End apis main version 6      ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (__main_version__ == 7)
/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ Begin apis main version 7    ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
TODO: main version 7
*/
/*-- solo para eclipse, es automatico en el proceso de compilacion
 * y lo podmeos agregar desde Project -> Properties -> Patha and Symbols {solapa} symbols */
/* #define REMOTO_CONNECT */


/*-- new line between commands*/
#define NEW_LINE_BETWEEN_CMD() /*\
	puts("")*/

#define VERSION_STRING()	"01v01d04"
#define AUTHOR_STRING() \
	"\033[0;35mJ.E.L"\
	"\e[0;32m - Jesus Emanuel Luccioni\t\n\e[0;32m"

#define AUTHOR_STRINGbrief() \
	" + Author : J.E.L (Jesus Emanuel Luccioni)\n"\
	" - meil: piero.jel@gmail.com\n"


/*-- En caso de necesitar imprimir el mensaje de error cunado retorna un valor menor a cero*/
#if 1
#define PCLOSE(Stream) pclose(Stream)
#else
#define PCLOSE(Stream)\
{\
	if(pclose(Stream) < 0)\
	{\
		PUTS_DEBUG("Error al cerrar el pipe");\
		return 1;\
	}\
	else\
	{\
		PUTS_DEBUG("Se cerro correctamente el PIPE");\
	}\
}
#endif


#if (defined(DEBUG_PRINT_DISABLE))
#define PRINT_STATUS_QUERY(Cond) {Cond;}
#else
#define PRINT_STATUS_QUERY(Cond)\
{\
	if(Cond)\
	{\
		puts("\n\t"SET_COLOR(FONT,RED)\
				   "EJECUCION FALLO.\n"SET_COLOR(FONT,RESET));\
    }\
	else\
	{\
		puts("\n\t"SET_COLOR(FONT,GREEN)\
				"EJECUCION SASTIFACTORIA..\n"SET_COLOR(FONT,RESET));\
	}\
}
#endif /* #if (defined(DEBUG_PRINT_DISABLE)) */

 /**
 * \typedef fx_optiont_pfT
 * \brief example de redifinicion puntero a funcion
 *  prototipo: unsigned int fx (unsigned int,unsigned int);
 * \note
 * \warning
 *
 */
 typedef int (*fx_optiont_pfT) (char *arg);
 /**
 * \typedef menu_t ;
 * \brief definimos el tipo de estructura
 * \ref vtchar
 * \ref vtint
 * \ref vtdouble
 * \note
 * \warning
 */
 typedef struct
 {
	 const char * leyend;
 }leyenda_sT;
 typedef struct
 {
     const char * opt ;     /**<@brief valor del tipo int */
     fx_optiont_pfT fxOption ;  /**<@brief valor del tipo double */
     /*leyenda_sT * pleyendList;*/
     const char *leyend;
     /*const char ** leyenda ;*/

 }menu_t;

/*  char * stdstring_find(const char *src,const char *target);*/
 unsigned char getCurrentDate(char *pbuff, size_t len);

 /**
  * ****************************************************************************//**
  * \fn int option_lg(char * arg   );
  * \brief descripcion breve.
  * \details descripcon detallada.
  * \param arg : Argumento uno del tipo puntero a char, string .
  * \return valor de retorno del tipo int.
  * \note nota sobre la funcion.
  * \warning mensaje de precaucion sobre la funcion.
  * \par example :
   <PRE>
   op = option_lg("on" );
   </PRE>
  *********************************************************************************/
 int option_lg(char * arg);
 /**
  * ****************************************************************************//**
  * \fn int option_usb(char * arg   );
  * \brief descripcion breve.
  * \details descripcon detallada.
  * \param arg : Argumento uno del tipo puntero a char, string .
  * \return valor de retorno del tipo int.
  * \note nota sobre la funcion.
  * \warning mensaje de precaucion sobre la funcion.
  * \par example :
   <PRE>
   op = option_usb("view" );
   </PRE>
  *********************************************************************************/
 int option_usb(char * arg);

 int option_error(char * arg);
 int option_event(char * arg);
 int option_bill(char * arg);
 int option_totem(char * arg);

 int option_ups(char * arg);
 int option_help(char * arg);
 int option_version(char *arg);
 int option_author(char *arg);


 fx_optiont_pfT get_funtionOption(menu_t *pmenu, char * option);

/*
 *
 * ──────────────────────────[ Begin section lg ]────────────────────────
 * definimos los string de opcion, leyenda y tambien la funcion para "lg"
 */
#define LEYEND_lg() \
		"\t--lg        : Visualiza los datos del LG\n"\
		"\t--lg on     : Habilita el LG (Base de Datos qTotem)\n"\
		"\t--lg off    : Deshabilita el LG (Base de Datos qTotem)\n"\
		"\t--lg log    : Visualiza el Log del Servidor del LG, a la fecha actual\n"

#define FUNCTION_lg() option_lg
#define OPTION_lg	"--lg"
/*
 * ────────────────────────────[ End section lg ]─────────────────────────
 */
/*
 *
 * ──────────────────────────[ Begin section usb ]────────────────────────
 * definimos los string de opcion, leyenda y tambien la funcion para "usb"
 */
 typedef struct{
	 const char * id;
	/* const char * brief;*/
	 const unsigned char en;
 }list_usb_sT;

 typedef struct{
	 const char * brief;
	 const unsigned char en;
 }list_usb_brief_sT;
#define LEYEND_usb() \
	"\t--usb       : Realiza el check de los dispositivos USB que deben estar enumerados.\n"\
    "\t--usb view  : Visualiza todos los dispositivos conectados a los diferentes HUB USB.\n"
 /*\
    "\t--usb rules : Visualiza el contenido del archivo rules para el LG.\n"\
    "\t--usb update : Actualiza el contenido del archivo rules para el LG.\n"*/

#define FUNCTION_usb() option_usb
#define OPTION_usb	"--usb"
 /*
  *
  * ────────────────────────────[ End section usb ]─────────────────────────
  *
  */
 /*
  *
  * ──────────────────────────[ Begin section error ]────────────────────────
  * definimos los string de opcion, leyenda y tambien la funcion para "error"
  */
  typedef struct{
 	 const char * id;
 	 const char * brief;
  }list_error_sT;

 #define LEYEND_error() \
     "\t--error     	: Visualiza los Errores desde la tabla dentro de Base de Datos \"qTotem\"\n"\
  	 "\t--error clean	: Limpia la tabla de Errores dentro de la Base de Datos \"qTotem\"\n"\
  	 "\t--error printer	: Verifica el estado de la impresora, \"PRINTER ID\"\n"\
  	 "\t--error stacker	: Verifica el estado del Stacker, \"Fuera de Lugar\"\n"\
  	 "\t--error posid	: Verifica si tenemos un error por POS ID, \"error F001\"\n"



 #define FUNCTION_error() option_error
 #define OPTION_error	"--error"
 /*
  *
  * ────────────────────────────[ End section error ]─────────────────────────
  *
  */
 /*
  *
  * ──────────────────────────[ Begin section event ]────────────────────────
  * definimos los string de opcion, leyenda y tambien la funcion para "event"
  */
  #define LEYEND_event() \
      "\t--event		: Visualiza Tabla de Eventos que esta dentro de Base de Datos \"qTotem\"\n"\
	  "\t--event clean	: Limpia la tabla de Eventos dentro de la Base de Datos \"qTotem\"\n"


  #define FUNCTION_event() option_event
  #define OPTION_event	"--event"
 /*
  *
  * ────────────────────────────[ End section event ]─────────────────────────
  *
  */
  /*
   *
   * ──────────────────────────[ Begin section bill ]────────────────────────
   * definimos los string de opcion, leyenda y tambien la funcion para "bill"
   */
   #define LEYEND_bill() \
     "\t--bill		: Visualiza La cantidad de Billetes en Stacker\n"


   #define FUNCTION_bill() option_bill
   #define OPTION_bill	"--bill"
  /*
   *
   * ────────────────────────────[ End section event ]─────────────────────────
   *
   */

  /*
   *
   * ──────────────────────────[ Begin section ups ]────────────────────────
   * definimos los string de opcion, leyenda y tambien la funcion para "bill"
   */
   #define LEYEND_ups() \
     "\t--ups		: Visualiza el Estado Actual de la UPS\n"

   #define FUNCTION_ups() option_ups
   #define OPTION_ups	"--ups"
 /*
  *
  * ────────────────────────────[ End section ups ]─────────────────────────
  *
  */
  /*
   *
   * ──────────────────────────[ Begin section totem ]────────────────────────
   * definimos los string de opcion, leyenda y tambien la funcion para "totem"
   */
   #define LEYEND_totem() \
		"\t--totem		: Visualiza el Estado Actual del totem\n"

   #define FUNCTION_totem() option_totem
   #define OPTION_totem	"--totem"
 /*
  *
  * ────────────────────────────[ End section totem ]─────────────────────────
  *
  */

 /*
  *
  * ──────────────────────────[ Begin section help ]────────────────────────
  * definimos los string de opcion, leyenda y tambien la funcion para "help"
  */
#define HEAD_help(nmbCmd)\
	printf(\
			"Mensaje de Ayuda, para el uso correcto del comando\n"\
			"Uso:\n\t %s { OPT1 [ARG1|ARG2|...] [OPT2 [ARG1|ARG2]] ...}\n\n",nmbCmd)
#define TAIL_help(nmbCmd)\
{\
	puts("Ejemplo de Uso:");\
	printf("\t %s --totem --error --event --bill --usb --ups \n",nmbCmd);\
    printf("\t %s --lg log --lg --error posid \n",nmbCmd);\
    printf("\t %s --bill --error stacker \n",nmbCmd);\
}

#define LEYEND_help() "\t--help       : Visualiza este mensaje de ayuda.\n"
#define FUNCTION_help() option_help
#define OPTION_help	"--help"
/*
 * ────────────────────────────[ End section help ]─────────────────────────
 */

 /*
  *
  * ──────────────────────────[ Begin section version ]────────────────────────
  * definimos los string de opcion, leyenda y tambien la funcion para "version"
  */
#define LEYEND_version() "\t--version       : Version de la aplicacion "VERSION_STRING()".\n"

#define FUNCTION_version() option_version
#define OPTION_version	"--version"

 /*
  *
  * ────────────────────────────[ End section version]─────────────────────────
  *
  */
 /*
  *
  * ──────────────────────────[ Begin section author ]────────────────────────
  * definimos los string de opcion, leyenda y tambien la funcion para "author"
  */
#define LEYEND_author() "\t--author       : "AUTHOR_STRING()"\n"

#define FUNCTION_author() option_author
#define OPTION_author	"--author"

 /*
  *
  * ────────────────────────────[ End section author]─────────────────────────
  *
  */


#define OPTION(Opt) OPTION_##Opt
#define LEYEND(Opt) LEYEND_##Opt()
#define FUNCTION(Opt) FUNCTION_##Opt()
/*-- fill macro function */
#define menu_FILL(Opt) {OPTION(Opt),FUNCTION(Opt),LEYEND(Opt)}
#define menu_TERMINATOR() {NULL}



#if ( defined(REMOTO_CONNECT))
#define CONN_INFO() \
		"user = postgres password = postgres \
	     hostaddr = 127.0.0.1 port = 5678 \
		 connect_timeout = 2\
		 dbname = "
#else/* #if (REMOTO_CONNECT == 1) */
#define CONN_INFO() \
		"user = postgres password = postgres \
	     hostaddr = 127.0.0.1 port = 5432 \
		 connect_timeout = 2\
		 dbname = "
#endif /*#if (REMOTO_CONNECT == 1)*/




/**
 * \typedef pFproccessQuery_pfT
 * \brief redefinicion de un puntero a funcion el cual toma como
 * argumento el numero de fila 'row', columna 'col' y el estring
 * campo. El resultado de la consulta en el campo fila columna establecido.
 * \details descripcion detallada
 * \note prototipo de funcion "void function (int row,int col, const char *strFied);"
 * \warning mensaje de precaucion sobre esta redefinicion
 */
typedef void (*pFproccessQuery_pfT) (int row,int col, const char *strFied);
typedef void (*pFemptlyQuery_pfT) (const char *leyendQuery);

typedef struct
{
	const char * query; /**<@brief string de la consulta */
	const char * leyenda; /**<@brief descripcion de la consulta  */
	pFproccessQuery_pfT proccessQuery; /**<@brief puntero a funcion que llama con el
	el campo resultado de la consulta */
	pFemptlyQuery_pfT emptlyQuery;/**<@brief puntero a funcion que llama cuando el resultado
	de la query esta vacia */
}query_sT;

typedef struct
{
	const char * update; /**<@brief string de la consulta */
	const char * leyenda; /**<@brief descripcion de la consulta  */
}update_sT;

/**
 *
 * ****************************************************************************//**
 * \fn int proccessListQuery(const char * connInfo   );
 * \brief descripcion breve.
 * \details descripcon detallada.
 * \param dbName : Nombre de la base de datos.
 * \param pListQuery : Lista de consultas.
 * \return valor de retorno del tipo int.
 * \note nota sobre la funcion.
 * \warning mensaje de precaucion sobre la funcion.
 * \par example :
  <PRE>
  if( proccessListQuery(arg_1))
  {
  	  ...success process
  }
  {
  	  ... failure process
  }
  </PRE>
 *********************************************************************************/
int proccessQuery(const char *dbName, query_sT *pListQuery);
int proccessUpdate(const char *dbName, update_sT *pListUpdate);
int proccessQueryWhere(const char *dbName, query_sT *pListQuery, const char * const *strWhere);
/**
 *
 * ****************************************************************************//**
 * \fn void print_field_query(int  r ,int c , const char * strQ);
 * \brief callback, no es llamada como una API. Es llamada automaticamente
 * al realizar la consulta de la base de datos.
 * \details descripcon detallada.
 * \param r : Argumento uno del tipo int.
 * \param , const char * strQ : Argumento uno del tipo ,int.
 * \return valor de retorno del tipo void.
 * \note nota sobre la funcion.
 * \warning mensaje de precaucion sobre la funcion.
 *
 *********************************************************************************/
void print_field_query(int r,int c, const char *strQ);

void print_emptly_query(const char *stley);



void print_field_error(int r,int c, const char *strQ);
void print_emptly_error(const char *strQ);
/* void print_emptly_event(const char *strQ); */
void print_field_bill(int r,int c, const char *strQ);
void print_field_totem(int r,int c, const char *strQ);

/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ End apis main version 7      ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (__main_version__ == 8)
/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ Begin apis main version 8    ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
TODO: main version 8
*/
/*-- solo para eclipse, es automatico en el proceso de compilacion
 * y lo podmeos agregar desde Project -> Properties -> Patha and Symbols {solapa} symbols */
/* #define REMOTO_CONNECT */



/*-- new line between commands*/
#define NEW_LINE_BETWEEN_CMD() /*\
	puts("")*/

#define VERSION_STRING()	"01v01d06"
#define AUTHOR_STRING() \
	"\033[0;35mJ.E.L"\
	"\e[0;32m - Jesus Emanuel Luccioni\t\n\e[0;32m"

#define AUTHOR_STRINGbrief() \
	" + Author : J.E.L (Jesus Emanuel Luccioni)\n"\
	" - meil: piero.jel@gmail.com\n"


/*-- En caso de necesitar imprimir el mensaje de error cunado retorna un valor menor a cero*/
#if 1
#define PCLOSE(Stream) pclose(Stream)
#else
#define PCLOSE(Stream)\
{\
	if(pclose(Stream) < 0)\
	{\
		PUTS_DEBUG("Error al cerrar el pipe");\
		return 1;\
	}\
	else\
	{\
		PUTS_DEBUG("Se cerro correctamente el PIPE");\
	}\
}
#endif





#if (defined(DEBUG_PRINT_DISABLE))
#define PRINT_STATUS_QUERY(Cond) {Cond;}
#else
#define PRINT_STATUS_QUERY(Cond)\
{\
	if(Cond)\
	{\
		puts("\n\t"SET_COLOR(FONT,RED)\
				   "EJECUCION FALLO.\n"SET_COLOR(FONT,RESET));\
    }\
	else\
	{\
		puts("\n\t"SET_COLOR(FONT,GREEN)\
				"EJECUCION SASTIFACTORIA..\n"SET_COLOR(FONT,RESET));\
	}\
}
#endif /* #if (defined(DEBUG_PRINT_DISABLE)) */

 /**
 * \typedef fx_optiont_pfT
 * \brief example de redifinicion puntero a funcion
 *  prototipo: unsigned int fx (unsigned int,unsigned int);
 * \note
 * \warning
 *
 */
 typedef int (*fx_optiont_pfT) (char *arg);
 /**
 * \typedef menu_t ;
 * \brief definimos el tipo de estructura
 * \ref vtchar
 * \ref vtint
 * \ref vtdouble
 * \note
 * \warning
 */
 typedef struct
 {
	 const char * leyend;
 }leyenda_sT;
 typedef struct
 {
     const char * opt ;     /**<@brief valor del tipo int */
     fx_optiont_pfT fxOption ;  /**<@brief valor del tipo double */
     /*leyenda_sT * pleyendList;*/
     const char *leyend;
     /*const char ** leyenda ;*/

 }menu_t;

/*  char * stdstring_find(const char *src,const char *target);*/
 unsigned char getCurrentDate(char *pbuff, size_t len);

 /**
  * ****************************************************************************//**
  * \fn int option_lg(char * arg   );
  * \brief descripcion breve.
  * \details descripcon detallada.
  * \param arg : Argumento uno del tipo puntero a char, string .
  * \return valor de retorno del tipo int.
  * \note nota sobre la funcion.
  * \warning mensaje de precaucion sobre la funcion.
  * \par example :
   <PRE>
   op = option_lg("on" );
   </PRE>
  *********************************************************************************/
 int option_lg(char * arg);
 /**
  * ****************************************************************************//**
  * \fn int option_usb(char * arg   );
  * \brief descripcion breve.
  * \details descripcon detallada.
  * \param arg : Argumento uno del tipo puntero a char, string .
  * \return valor de retorno del tipo int.
  * \note nota sobre la funcion.
  * \warning mensaje de precaucion sobre la funcion.
  * \par example :
   <PRE>
   op = option_usb("view" );
   </PRE>
  *********************************************************************************/
 int option_usb(char * arg);
 int option_error(char * arg);
 int option_event(char * arg);
 int option_bill(char * arg);
 int option_totem(char * arg);
 int option_ups(char * arg);
 int option_help(char * arg);
 int option_version(char *arg);
 int option_author(char *arg);


 fx_optiont_pfT get_funtionOption(menu_t *pmenu, char * option);

/*
 *
 * ──────────────────────────[ Begin section lg ]────────────────────────
 * definimos los string de opcion, leyenda y tambien la funcion para "lg"
 */
#define LEYEND_lg() \
		"\t--lg        : Visualiza los datos del LG\n"\
		"\t--lg on     : Habilita el LG (Base de Datos qTotem)\n"\
		"\t--lg off    : Deshabilita el LG (Base de Datos qTotem)\n"\
		"\t--lg log    : Visualiza el Log del Servidor del LG, a la fecha actual\n"

#define FUNCTION_lg() option_lg
#define OPTION_lg	"--lg"
/*
 * ────────────────────────────[ End section lg ]─────────────────────────
 */
/*
 *
 * ──────────────────────────[ Begin section usb ]────────────────────────
 * definimos los string de opcion, leyenda y tambien la funcion para "usb"
 */
 typedef struct{
	 const char * id;
	/* const char * brief;*/
	 const unsigned char en;
 }list_usb_sT;

 typedef struct{
	 const char * brief;
	 const unsigned char en;
 }list_usb_brief_sT;
#define LEYEND_usb() \
	"\t--usb       : Realiza el check de los dispositivos USB que deben estar enumerados.\n"\
    "\t--usb view  : Visualiza todos los dispositivos conectados a los diferentes HUB USB.\n"
 /*\
    "\t--usb rules : Visualiza el contenido del archivo rules para el LG.\n"\
    "\t--usb update : Actualiza el contenido del archivo rules para el LG.\n"*/

#define FUNCTION_usb() option_usb
#define OPTION_usb	"--usb"
 /*
  *
  * ────────────────────────────[ End section usb ]─────────────────────────
  *
  */
 /*
  *
  * ──────────────────────────[ Begin section error ]────────────────────────
  * definimos los string de opcion, leyenda y tambien la funcion para "error"
  */
  typedef struct{
 	 const char * id;
 	 const char * brief;
  }list_error_sT;

 #define LEYEND_error() \
     "\t--error     	: Visualiza los Errores desde la tabla dentro de Base de Datos \"qTotem\"\n"\
  	 "\t--error clean	: Limpia la tabla de Errores dentro de la Base de Datos \"qTotem\"\n"\
  	 "\t--error printer	: Verifica el estado de la impresora, \"PRINTER ID\"\n"\
  	 "\t--error stacker	: Verifica el estado del Stacker, \"Fuera de Lugar\"\n"\
  	 "\t--error posid	: Verifica si tenemos un error por POS ID, \"error F001\"\n"

 #define FUNCTION_error() option_error
 #define OPTION_error	"--error"
 /*
  *
  * ────────────────────────────[ End section error ]─────────────────────────
  *
  */
 /*
  *
  * ──────────────────────────[ Begin section event ]────────────────────────
  * definimos los string de opcion, leyenda y tambien la funcion para "event"
  */
  #define LEYEND_event() \
      "\t--event		: Visualiza Tabla de Eventos que esta dentro de Base de Datos \"qTotem\"\n"\
	  "\t--event clean	: Limpia la tabla de Eventos dentro de la Base de Datos \"qTotem\"\n"


  #define FUNCTION_event() option_event
  #define OPTION_event	"--event"
 /*
  *
  * ────────────────────────────[ End section event ]─────────────────────────
  *
  */
  /*
   *
   * ──────────────────────────[ Begin section bill ]────────────────────────
   * definimos los string de opcion, leyenda y tambien la funcion para "bill"
   */
   #define LEYEND_bill() \
     "\t--bill		: Visualiza La cantidad de Billetes en Stacker\n"


   #define FUNCTION_bill() option_bill
   #define OPTION_bill	"--bill"
  /*
   *
   * ────────────────────────────[ End section event ]─────────────────────────
   *
   */

  /*
   *
   * ──────────────────────────[ Begin section ups ]────────────────────────
   * definimos los string de opcion, leyenda y tambien la funcion para "bill"
   */
   #define LEYEND_ups() \
     "\t--ups		: Visualiza el Estado Actual de la UPS\n"

   #define FUNCTION_ups() option_ups
   #define OPTION_ups	"--ups"
 /*
  *
  * ────────────────────────────[ End section ups ]─────────────────────────
  *
  */
  /*
   *
   * ──────────────────────────[ Begin section totem ]────────────────────────
   * definimos los string de opcion, leyenda y tambien la funcion para "totem"
   */
   #define LEYEND_totem() \
		"\t--totem		: Visualiza el Estado Actual del totem\n"

   #define FUNCTION_totem() option_totem
   #define OPTION_totem	"--totem"
 /*
  *
  * ────────────────────────────[ End section totem ]─────────────────────────
  *
  */

 /*
  *
  * ──────────────────────────[ Begin section help ]────────────────────────
  * definimos los string de opcion, leyenda y tambien la funcion para "help"
  */
#define HEAD_help(nmbCmd)\
	printf(\
			"Mensaje de Ayuda, para el uso correcto del comando\n"\
			"Uso:\n\t %s { OPT1 [ARG1|ARG2|...] [OPT2 [ARG1|ARG2]] ...}\n\n",nmbCmd)
#define TAIL_help(nmbCmd)\
{\
	puts("Ejemplo de Uso:");\
	printf("\t %s --totem --error --event --bill --usb --ups \n",nmbCmd);\
    printf("\t %s --lg log --lg --error posid \n",nmbCmd);\
    printf("\t %s --bill --error stacker \n",nmbCmd);\
}

#define LEYEND_help() "\t--help       : Visualiza este mensaje de ayuda.\n"
#define FUNCTION_help() option_help
#define OPTION_help	"--help"
/*
 * ────────────────────────────[ End section help ]─────────────────────────
 */

 /*
  *
  * ──────────────────────────[ Begin section version ]────────────────────────
  * definimos los string de opcion, leyenda y tambien la funcion para "version"
  */
#define LEYEND_version() "\t--version       : Version de la aplicacion "VERSION_STRING()".\n"

#define FUNCTION_version() option_version
#define OPTION_version	"--version"

 /*
  *
  * ────────────────────────────[ End section version]─────────────────────────
  *
  */
 /*
  *
  * ──────────────────────────[ Begin section author ]────────────────────────
  * definimos los string de opcion, leyenda y tambien la funcion para "author"
  */
#define LEYEND_author() "\t--author       : "AUTHOR_STRING()"\n"

#define FUNCTION_author() option_author
#define OPTION_author	"--author"

 /*
  *
  * ────────────────────────────[ End section author]─────────────────────────
  *
  */


#define OPTION(Opt) OPTION_##Opt
#define LEYEND(Opt) LEYEND_##Opt()
#define FUNCTION(Opt) FUNCTION_##Opt()
/*-- fill macro function */
#define menu_FILL(Opt) {OPTION(Opt),FUNCTION(Opt),LEYEND(Opt)}
#define menu_TERMINATOR() {NULL}


#if ( defined(REMOTO_CONNECT))
#define CONN_INFO() \
		"user = postgres password = postgres \
	     hostaddr = 127.0.0.1 port = 5678 \
		 connect_timeout = 2\
		 dbname = "
#else/* #if (REMOTO_CONNECT == 1) */
#define CONN_INFO() \
		"user = postgres password = postgres \
	     hostaddr = 127.0.0.1 port = 5432 \
		 connect_timeout = 2\
		 dbname = "
#endif /*#if (REMOTO_CONNECT == 1)*/




  /**
   * \typedef pFproccessQuery_pfT
   * \brief redefinicion de un puntero a funcion el cual toma como
   * argumento el numero de fila 'row', columna 'col' y el estring
   * campo. El resultado de la consulta en el campo fila columna establecido.
   * \details descripcion detallada
   * \note prototipo de funcion "void function (int row,int col, const char *strFied);"
   * \warning mensaje de precaucion sobre esta redefinicion
   */
  typedef void (*pFproccessQuery_pfT) (int row,int col, const char *strFied);
  typedef void (*pFemptlyQuery_pfT) (const char *leyendQuery);

  typedef struct
  {
  	const char * query; /**<@brief string de la consulta */
  	const char * leyenda; /**<@brief descripcion de la consulta  */
  	pFproccessQuery_pfT proccessQuery; /**<@brief puntero a funcion que llama con el
  	el campo resultado de la consulta */
  	pFemptlyQuery_pfT emptlyQuery;/**<@brief puntero a funcion que llama cuando el resultado
  	de la query esta vacia */
  }query_sT;

  typedef struct
  {
  	const char * update; /**<@brief string de la consulta */
  	const char * leyenda; /**<@brief descripcion de la consulta  */
  }update_sT;

  /**
   *
   * ****************************************************************************//**
   * \fn int proccessListQuery(const char * connInfo   );
   * \brief descripcion breve.
   * \details descripcon detallada.
   * \param dbName : Nombre de la base de datos.
   * \param pListQuery : Lista de consultas.
   * \return valor de retorno del tipo int.
   * \note nota sobre la funcion.
   * \warning mensaje de precaucion sobre la funcion.
   * \par example :
    <PRE>
    if( proccessListQuery(arg_1))
    {
    	  ...success process
    }
    {
    	  ... failure process
    }
    </PRE>
   *********************************************************************************/
  int proccessQuery(const char *dbName, query_sT *pListQuery);
  int proccessUpdate(const char *dbName, update_sT *pListUpdate);
  int proccessQueryWhere(const char *dbName, query_sT *pListQuery, const char * const *strWhere);
  /**
   *
   * ****************************************************************************//**
   * \fn void print_field_query(int  r ,int c , const char * strQ);
   * \brief callback, no es llamada como una API. Es llamada automaticamente
   * al realizar la consulta de la base de datos.
   * \details descripcon detallada.
   * \param r : Argumento uno del tipo int.
   * \param , const char * strQ : Argumento uno del tipo ,int.
   * \return valor de retorno del tipo void.
   * \note nota sobre la funcion.
   * \warning mensaje de precaucion sobre la funcion.
   *
   *********************************************************************************/
  void print_field_query(int r,int c, const char *strQ);

  void print_emptly_query(const char *stley);


  void print_field_error(int r,int c, const char *strQ);
  void print_emptly_error(const char *strQ);
  /* void print_emptly_event(const char *strQ); */
  void print_field_bill(int r,int c, const char *strQ);
  void print_field_totem(int r,int c, const char *strQ);

/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ End apis main version 8      ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (__main_version__ == 9)
/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ Begin apis main version 9    ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
TODO: main version 9
*/


/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ End apis main version 9      ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#elif (__main_version__ == 10)
/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ Begin apis main version 10   ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
TODO: main version 10
*/


/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ End apis main version 10     ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
*
*/
#else
#warning "__main_version__ definido de forma incorrecta"

#endif

/*
 *
 *
 * ****************************************************************************************************
 *
 * ===========================[ End  APIs, macros , datos Declaration ]============================
 *
 * ***************************************************************---------*****************************
 *
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
