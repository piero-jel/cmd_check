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
 * \file main.c
 * \brief bloque de comenteario para documentacion para describir este archivo de 
 * cabecera o header file. 
 * \version v01.01
 * \date   26 de feb. de 2017
 * \note none
 * \author JEL, Jesus Emanuel Luccioni
 * \li piero.jel@gmail.com
 * 
 *************************************************************************************/
/** @} doxygen end group definition */


/* **********************************************************************************************
 *
 * ===========================[ Begin include header file ]============================
 *
 * ********************************************************************************************** 
 * 
 */
#include <stdio.h> /* header file correspondiente a las libreria
estandar de entrada salida*/
#include <stdlib.h> /* header file correspondiente a las libreria
estandar para el uso de la funcion @ref exit() con sus 
macros @ref EXIT_FAIL y @ref EXIT_SUCCESS*/
#include <stdarg.h>
/*
#include <string.h>
#include <math.h>
*/
#include <typedef.h>
/*  
 * **********************************************************************************************
 *
 * ===========================[ End include header file ]============================
 *
 * *********************************************************************************************/


#ifndef __main_version__
/**
 * \def __main_version__
 * \brief Establecemos la Version para el main.
 * \li + 0, 
 * \li + 1, 
 * \li + 2,
 * \li + 3,  
 * \li + 4,
 * \li + 5, 
 * \li + 6, 
 * \li + 7, 
 * \li + 8, 
 * \li + 9, 
 * TODO: __main_version__
 */
#define __main_version__    8
#endif

#include <main.h>


/* 
 *
 * 
 * *********************************************************************************************
 *
 * ===========================[ Begin main Definition ]============================
 *
 * ********************************************************************************************
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
 *
 * *******************************************************************
 * @brief funcion principal 
 * @param argn numeros de Arguemtnos por defecto es '1' 
 * @param arg array de arguemento, arg[0] := path/appname
 * @return estado de la ejecucion
 *  + EXIT_SUCCESS : ejecucion finalizada de forma exitosa
 *  + EXIT_FAIL : ejecucion finalizada con error 
 * 
 *********************************************************************/
int main(int argn,char **arg)
{  
    PRINT_SIZE_LEYEND();
    PRINT_SIZE(char );    
    PRINT_SIZE(short int );    
    PRINT_SIZE(int );
    PRINT_SIZE(long int );
    PRINT_SIZE(long long int );
    PRINT_SIZE(float );
    PRINT_SIZE(double );
    PRINT_SIZE(long double );   
    unsigned int i;    
    printf("\t El Numero aleatorio de %u\n",get_random(5));
    for (i = 0 ; i < 10 ; i++)
    {
        printf("\tEl factorial de %u = %u\n",i,factorial(i));   
        printf("\tEl Numero aleatorio de %u = %u\n",i,get_random(0));   
    }
    exit(EXIT_SUCCESS);
}
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
#include <string.h>


menu_t menu_option[] = {
     {OPTION(lg),LEYEND(lg),FUNCTION(lg)}
    ,{OPTION(usb),LEYEND(usb),FUNCTION(usb)}
    ,{NULL}
};
/*
 *
 * *******************************************************************
 * @brief funcion principal 
 * @param argn numeros de Arguemtnos por defecto es '1' 
 * @param arg array de arguemento, arg[0] := path/appname
 * @return estado de la ejecucion
 *  + EXIT_SUCCESS : ejecucion finalizada de forma exitosa
 *  + EXIT_FAIL : ejecucion finalizada con error 
 * 
 *********************************************************************/
int main(int argn,char **arg)
{    
    int i;
    fx_optiont_pfT pfxOption;
    
    /*-- recorremos el array de argumentos
     * En la posicion 0, tenemos el path y nombre de la APP
     * */
    i = 1;
    while(i < argn)
    {
        /*printf("\t%d\t%s\n",i,*arg);
        *arg++;*/
        printf("\t%d\t%s\n",i,arg[i]);
        pfxOption = get_funtionOption(menu_option,arg[i]);
        if(pfxOption == NULL)
        {
        	printf("Parametro \"%s\" es incorrecto",arg[i]);
        	print_menu(menu_option);
        	exit(EXIT_SUCCESS);
        }
        /* En "pfxOption" tenemos le puntero a funcion a la operacion
         * debemos buscar el arguemtno si es que tiene
         * */
        i++;
        if(i == argn)
        {
        	/* Nos quedamos sin argumentos, llegamos al final*/
        	if((pfxOption)(NULL))
        	{
        		printf("Llamado incorrecto con los argumentos %s \n",arg[i-1]);
        	}
        	else
        	{
        		printf("Ejecucion sastifactoria de los Argumentos: %s\n",arg[i-1]);
        	}
        	exit(EXIT_SUCCESS);
        }
        /* comprobamos si el siguente argumento pertenece a otra accion */
        if(get_funtionOption(menu_option,arg[i]) == NULL)
        {
        	/* Es un argumento para la opcion anterior */
        	if((pfxOption)(arg[i]))
        	{
        		printf("Llamado incorrecto con los argumentos %s %s\n",arg[i-1],arg[i]);
        		print_menu(menu_option);
        		exit(EXIT_SUCCESS);
        	}
        	else
        	{
        		printf("Ejecucion sastifactoria de los Argumentos: %s %s\n",arg[i-1],arg[i]);
        	}
        }
        else
        {
        	/* debemos llamar a la opcion sin argumento */
        	i--;
        	if((pfxOption)(NULL))
        	{
        		printf("Llamado incorrecto con el argumento: %s\n",arg[i]);
        	}
        	else
        	{
        		printf("Ejecucion sastifactoria con elArgumentos: %s\n",arg[i]);
        	}
        }
        /*  tomamos un argumentos mas, incrementamos el index */
        i++;
    }
    exit(EXIT_SUCCESS);
}
/**
 *
 * ****************************************************************************//**
 * \fn fx_optiont_pfT get_funtionOption(menu_t *pmenu, char * option);
 * \brief Funcion para obtener el puntero a funcion de la Opcion pasada como
 * argumeto \ref option.
 * \param pmenu : Puntero a menu, sobre el cual tenemos definidos las
 * opciones que pueden ser llamadas y sobre la cual vamos a buscar.
 * \param option :  string con la opcion a buscar y sobre la cual obtendremos
 * el puntero a funcion.
 * \return devolveremos el puntero a funcion correspondiente a la opcion pasada
 * como \ref option.
 * 	En caso de devolver un NULL, quiere decir que la opcion no se encontro dentro
 * 	del menu o bien la opcion esta deshabilitada (ya con no tiene definida una
 * 	funcion a ejecutar).
 * \note
 * \warning
 * \par example :
<PRE>
  pfxOption = get_funtionOption(menu_option,arg[i]);
  if(pfxOption == NULL)
  {
	printf("Parametro \"%s\" es incorrecto",arg[i]);
	print_menu(menu_option);
	exit(EXIT_SUCCESS);
  }
</PRE>
 *********************************************************************************/
fx_optiont_pfT get_funtionOption(menu_t *pmenu, char * option)
{
    while(pmenu->opt != NULL)
    {
    	if(strcmp(pmenu->opt,option) == 0)
    	{
    		return pmenu->fxOption;
    	}
    	pmenu++;
    }
    return NULL;
}
/**
 *
 * ****************************************************************************//**
 * \fn void print_menu(menu_t *pmenu  );
 * \brief descripcion breve.
 * \details descripcon detallada.
 * \param *pmenu : Argumento uno del tipo menu_t.
 * \return valor de retorno del tipo void.
 * \note nota sobre la funcion.
 * \warning mensaje de precaucion sobre la funcion.
 * \par example :
  <PRE>
   print_menu(menu_options);
  </PRE>
 *********************************************************************************/
void print_menu(menu_t *pmenu)
{
	puts("");
    while(pmenu->opt != NULL)
    {
        printf("%s\n",pmenu->leyenda);
        pmenu++;        
    }
}
/*
 * ******************************************************************************
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
int option_lg(char * arg)
{
    if(arg == NULL)
    {
        puts("call: --lg\t\t :Sin argumentos, visualizamos los datos del LG");
        return 0;
    }
    if(strcmp("on",arg) == 0)
    {
    	puts("call: --lg on\t\t :Habilitamos el LG (Base de Datos)");
        return 0;
    }
    if(strcmp("off",arg) == 0)
    {
    	puts("call: --lg off\t\t :Deshabilitamos el LG (Base de Datos)");
        return 0;
    }
    if(strcmp("up",arg) == 0)
    {
    	puts("call: --lg up\t\t :Realiza la secuencia para habilitar el LG");
        return 0;
    }
    if(strcmp("down",arg) == 0)
    {
    	puts("call: --lg down\t\t :Realiza la secuencia para deshabilitar el LG");
        return 0;
    }
    return 1;
}


int fgetline(char *pbuff, int lenbuff, FILE* file)
{
	int i;
	int caracter;
	if((pbuff == NULL)||(lenbuff == 0)) return 0;
	i = 0;
	do{
		caracter = fgetc(file);
		if((caracter == '\n')||(caracter == EOF))break;
		*pbuff = (char) caracter;
		pbuff++;
		i++;
	}while(i < lenbuff);
	if(caracter == EOF)
	{
		return i;
	}
	else
	{
		*pbuff = '\n';
	}
	return i;
}


void check_usb(unsigned int st,list_usb_sT *plistUSB)
{
	unsigned int i,tmp;
	i = 0;
	while(plistUSB->id != NULL)
	{
		tmp = 0x01 << i;
		if(st & tmp)
		{
			printf(SET_COLOR(FONT,/*GREEN*/BLUE)\
					"\tDispostivo %s, conectado correctamente"\
					SET_COLOR(FONT,RESET)"\n"\
					,plistUSB->brief);
		}
		else
		{
			printf(SET_COLOR(FONT,RED)\
					"\tEl Dispostivo %s, no se encuentra conectado"\
					SET_COLOR(FONT,RESET)"\n"\
					,plistUSB->brief);
		}
		i++;
		plistUSB++;
	}
}

int get_status_usb(list_usb_sT *plistUSB, char *arg)
{
	int i;
	if(arg == NULL) return 0;
	i = 0;
	while(plistUSB->id != NULL)
	{
		if(strcmp(plistUSB->id,arg) == 0)
		{
			return i;
		}
		i++;
		plistUSB++;
	}
	return -1;
}
/*
 * ******************************************************************************
 * \fn int option_usb(char * arg   );
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
int option_usb(char * arg)
{
	/* usamos una pipe, para leer el comando */
	FILE *output;
	char buffer[16];
	static unsigned int status;
	int tmp;
	do{
		if(arg == NULL)
		{
			puts("call: --usb\t\t :Realizamos el check de los dispositivos USB necesarios.");
			output = popen("lsusb | cut -d \" \" -f 6", "r");/* comando "more", direccionamos*/
			if( output == NULL)
			{
				puts("Error no se puede abrir el proceso mediante pipe");
				return 1;
			}
			status = 0;
#if 1
			//while (fgets(buffer, sizeof(buffer), output) != NULL)
			/* 1d6b:0001 debemos considera el 10 caracter '\0'*/
			while (fgets(buffer, 10, output) != NULL)
			{
				tmp = get_status_usb(listDeviceUSB,buffer);
				if(tmp >= 0)
				{
					status |= (0x01 << tmp);
				}
				//printf("%s", buffer);
			}
			check_usb(status,listDeviceUSB);

#else
			while (fgetline(buffer, sizeof(buffer), output) != 0 )
							printf("%s", buffer);
#endif

			//return 0;
			break;
		}
		if(strcmp("view",arg) == 0)
		{
			puts("call: --usb view\t\t :Visualiza todos los dispositivos USB enumerados");
			return 0;
		}
		if(strcmp("rules",arg) == 0)
		{
			puts("call: --usb rules\t\t :Visualiza el archivo con las reglas para enumerar el LG");
			return 0;
		}
		if(strcmp("update",arg) == 0)
		{
			puts("call: --usb update\t\t :Actualiza el archivo con las reglas para enumerar el LG");
			return 0;
		}
		return 1;
	}while(0);
	if(pclose(output) < 0)
	{
		puts("Error al cerrar el pipe");
		return 1;
	}
	else
		puts("Se cerro correctamente el PIPE");
	return 0;
}

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
#include <libpq-fe.h>
/*
 *
 * *******************************************************************
 * @brief funcion principal 
 * @param argn numeros de Arguemtnos por defecto es '1' 
 * @param arg array de arguemento, arg[0] := path/appname
 * @return estado de la ejecucion
 *  + EXIT_SUCCESS : ejecucion finalizada de forma exitosa
 *  + EXIT_FAIL : ejecucion finalizada con error 
 * 
 *********************************************************************/
int main(int argn,char **arg)
{  
	PGconn * hdlDataBase;
	ConnStatusType Status;
	/*
	 * connection conexionDB("dbname = qTotem user = postgres password = postgres \
      hostaddr = 127.0.0.1 port = 5678");
	 */
	hdlDataBase = PQconnectdb("dbname = qTotem user = postgres password = postgres \
		      hostaddr = 127.0.0.1 port = 5678 connect_timeout = 2");
	/*if(hdlDataBase == NULL)
	{
		puts("No se puede establecer coneccion con la base de datos");
	}
	{
		puts("Coneccion sastifactoria");
	}*/
	Status = PQstatus(hdlDataBase);
	switch(Status)
	{
		case CONNECTION_OK:
			puts("Coneccion sastifactoria");
			break;
		case CONNECTION_BAD:
		case CONNECTION_STARTED: /* Waiting for connection to be made.  */
		case CONNECTION_MADE:			/* Connection OK; waiting to send. */
		case CONNECTION_AWAITING_RESPONSE:	/* Waiting for a response from the postmaster.        */
		case CONNECTION_AUTH_OK:			/* Received authentication; waiting for backend startup. */
		case CONNECTION_SETENV:			/* Negotiating environment. */
		case CONNECTION_SSL_STARTUP:		/* Negotiating SSL. */
		case CONNECTION_NEEDED:			/* Internal state: connect() needed */
		case CONNECTION_CHECK_WRITABLE:	/* Check if we could make a writable connection. */
		case CONNECTION_CONSUME:			/* Wait for any pending message and consume*/
			puts("No se puede establecer coneccion con la base de datos");

	}

	/*-- cerramos la coneccion y libreamos espacio, independiente si la coneccion fue
	 * o no sastifactoria. Ya que se reserva memroria para el objeto "hdlDataBase" */
	PQfinish(hdlDataBase);
	exit(EXIT_SUCCESS);
}

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
#include <libpq-fe.h>
/*
 *
 * *******************************************************************
 * @brief funcion principal 
 * @param argn numeros de Arguemtnos por defecto es '1' 
 * @param arg array de arguemento, arg[0] := path/appname
 * @return estado de la ejecucion
 *  + EXIT_SUCCESS : ejecucion finalizada de forma exitosa
 *  + EXIT_FAIL : ejecucion finalizada con error 
 * 
 *********************************************************************/
int main(int argn,char **arg)
{
	PGconn * hdlDataBase;
	PGresult *queryDB;
	PQprintOpt fmtPrintDB;
	fmtPrintDB.header = 0;
	fmtPrintDB.align = 1;
	fmtPrintDB.standard = 1;
	fmtPrintDB.html3 = 0;
	fmtPrintDB.expanded = 0;
	fmtPrintDB.pager = 0;
	fmtPrintDB.fieldSep = "|";
	fmtPrintDB.tableOpt= NULL;
	fmtPrintDB.caption = NULL;


	/*
	 * connection conexionDB("dbname = qTotem user = postgres password = postgres \
      hostaddr = 127.0.0.1 port = 5678");
	 */
	hdlDataBase = PQconnectdb("dbname = qTotem user = postgres password = postgres \
		      hostaddr = 127.0.0.1 port = 5678 connect_timeout = 2");
	/*-- consultamos el estado de la coneccion*/
	 /* Check to see that the backend connection was successfully made */
	if (PQstatus(hdlDataBase) != CONNECTION_OK)
	{
		printf("No se puede establecer coneccion con la base de datos: \"%s\"\n",PQdb(hdlDataBase));
		/*-- cerramos la coneccion y libreamos espacio, aunque la coneccion no sea sastifactoria.
		 *  Ya que se reserva memroria para el objeto "hdlDataBase" */
		PQfinish(hdlDataBase);
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("Coneccion sastifactoria, a la base de datos : \"%s\"\n",PQdb(hdlDataBase));
	}
	/**/
	queryDB = PQexec(hdlDataBase,"SELECT * FROM monitoreo_devices_fuera_servicio");
	if (PQresultStatus(queryDB) != PGRES_COMMAND_OK)
	{
		printf("command failed: %s", PQerrorMessage(hdlDataBase));
		PQclear(queryDB);
		PQfinish(hdlDataBase);
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("command success SELECT * FROM monitoreo_devices_fuera_servicio");
	}
	PQclear(queryDB);

	PQprint(stdout,queryDB,&fmtPrintDB);

	/*-- cerramos la coneccion y libreamos espacio, independiente si la coneccion fue
	 * o no sastifactoria. Ya que se reserva memroria para el objeto "hdlDataBase" */
	PQfinish(hdlDataBase);
	exit(EXIT_SUCCESS);
}

/*
┌────────────────────────────────────────────────────────────────────────────────────┐
│                                                                                    │
│                                                                                    │
│ ─────────────────────────[ End apis main version 3      ]────────────────────────  │
│                                                                                    │
│                                                                                    │
└────────────────────────────────────────────────────────────────────────────────────┘
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
#include <libpq-fe.h>


static void exit_nicely(PGconn *conn)
{
    PQfinish(conn);
    exit(1);
}
/*
 *
 * *******************************************************************
 * @brief funcion principal 
 * @param argn numeros de Arguemtnos por defecto es '1' 
 * @param arg array de arguemento, arg[0] := path/appname
 * @return estado de la ejecucion
 *  + EXIT_SUCCESS : ejecucion finalizada de forma exitosa
 *  + EXIT_FAIL : ejecucion finalizada con error 
 * 
 *********************************************************************/
int main(int argn,char **arg)
{   
	   const char *conninfo;
	    PGconn     *conn;
	    PGresult   *res;
	    int         nFields;
	    int         i,
	                j;

	    /*
	     * If the user supplies a parameter on the command line, use it as the
	     * conninfo string; otherwise default to setting dbname=postgres and using
	     * environment variables or defaults for all other connection parameters.
	     */
        conninfo = "dbname = qTotem \
        		    user = postgres password = postgres \
  		      		hostaddr = 127.0.0.1 port = 5678 \
        			connect_timeout = 2";

	    /* Make a connection to the database */
	    conn = PQconnectdb(conninfo);

	    /* Verifique que la conexión de backend se haya realizado correctamente */
	    if (PQstatus(conn) != CONNECTION_OK)
	    {
	        fprintf(stderr, "Connection to database failed: %s",
	                PQerrorMessage(conn));
	        exit_nicely(conn);
	    }

	    /* Establezca una ruta de búsqueda siempre segura, para que los
	     * usuarios malintencionados no puedan tomar el control. */
	    res = PQexec(conn,
	    		"SELECT pg_catalog.set_config('search_path', '', false)");

	    if (PQresultStatus(res) != PGRES_TUPLES_OK)
	    {
	        fprintf(stderr, "SET failed: %s", PQerrorMessage(conn));
	        PQclear(res);
	        exit_nicely(conn);
	    }

	    /*
	     * Debe siempre hacer un  PQclear sobre PGresult siempre que ya no sea necesario
	     * para evitar pérdidas de memoria
	     */
	    PQclear(res);

	    /*
	     * En nuestro caso de prueba implica el uso de un cursor, para lo cual debemos estar
	     *  dentro de un bloque de transacción. Podríamos hacer todo con un solo PQexec()
	     *  de la forma: "select * from pg_database"
	     *  pero eso es demasiado trivial para ser un buen ejemplo.
	     */

	    /* Start a transaction block */
	    res = PQexec(conn, "BEGIN");
	    if (PQresultStatus(res) != PGRES_COMMAND_OK)
	    {
	        fprintf(stderr, "BEGIN command failed: %s", PQerrorMessage(conn));
	        PQclear(res);
	        exit_nicely(conn);
	    }
	    PQclear(res);

	    /*
	     * Obtener filas de pg_database, el catálogo de bases de datos del sistema
	     */
	    res = PQexec(conn, "DECLARE myportal CURSOR FOR select * from pg_database");
	    if (PQresultStatus(res) != PGRES_COMMAND_OK)
	    {
	        fprintf(stderr, "DECLARE CURSOR failed: %s", PQerrorMessage(conn));
	        PQclear(res);
	        exit_nicely(conn);
	    }
	    PQclear(res);

	    res = PQexec(conn, "FETCH ALL in myportal");
	    if (PQresultStatus(res) != PGRES_TUPLES_OK)
	    {
	        fprintf(stderr, "FETCH ALL failed: %s", PQerrorMessage(conn));
	        PQclear(res);
	        exit_nicely(conn);
	    }

	    /* first, print out the attribute names */
	    nFields = PQnfields(res);
	    for (i = 0; i < nFields; i++)
	        printf("%-15s", PQfname(res, i));
	    printf("\n\n");

	    /* next, print out the rows */
	    for (i = 0; i < PQntuples(res); i++)
	    {
	        for (j = 0; j < nFields; j++)
	            printf("%-15s", PQgetvalue(res, i, j));
	        printf("\n");
	    }

	    PQclear(res);

	    /* close the portal ... we don't bother to check for errors ... */
	    res = PQexec(conn, "CLOSE myportal");
	    PQclear(res);

	    /* end the transaction */
	    res = PQexec(conn, "END");
	    PQclear(res);

	    /* close the connection to the database and cleanup */
	    PQfinish(conn);




    exit(EXIT_SUCCESS);
}
/*
┌────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                    │  
│                                                                                    │  
│ ─────────────────────────[ End apis main version 4      ]────────────────────────  │
│                                                                                    │
│                                                                                    │             
└────────────────────────────────────────────────────────────────────────────────────┘
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
#include <libpq-fe.h>



listQuery_sT listQuery_qTotem[] = {
		 {"select * from monitoreo_devices_fuera_servicio", "tablas de  errores"}
		/*,{"select * from monitoreo_devicesevents","tablas de  eventos",1}*/
		,{"select totem_habilitado from config","Tabla donde Habilita/Deshabilita el Totem"}
		,{"select * from monitoreo_devicesconfig","Tabla de Configuracion del Dispositivo"}
		,{"select sum(cantidad) from billetes","cantidad de Billetes en Stacker"}
		/*,{"select * from \"LogLgServer\" where date >= '2016-08-25'"}*/
		,{NULL}
};

listQuery_sT listQuery_bspa[] = {
		 {"select * from monitoreo_devices_fuera_servicio", "tablas de  errores"}
		/*,{"select * from monitoreo_devicesevents","tablas de  eventos",1}*/
		,{"select totem_habilitado from config","Tabla donde Habilita/Deshabilita el Totem"}
		,{"select * from monitoreo_devicesconfig","Tabla de Configuracion del Dispositivo"}
		,{"select sum(cantidad) from billetes","cantidad de Billetes en Stacker"}
		,{"select * from \"LogLgServer\" where date >= '2016-08-25'"}
		,{NULL}
};

static void exit_nicely(PGconn *conn)
{
    PQfinish(conn);
    exit(1);
}
/*
 *
 * *******************************************************************
 * @brief funcion principal 
 * @param argn numeros de Arguemtnos por defecto es '1' 
 * @param arg array de arguemento, arg[0] := path/appname
 * @return estado de la ejecucion
 *  + EXIT_SUCCESS : ejecucion finalizada de forma exitosa
 *  + EXIT_FAIL : ejecucion finalizada con error 
 * 
 *********************************************************************/    
int main(int argn,char **arg)
{
   const char *conninfo;
   PGconn     *conn;
   PGresult   *res;
   int rows, i;
   int ncols,j;
   listQuery_sT *pListQuery;


   /*
    * If the user supplies a parameter on the command line, use it as the
    * conninfo string; otherwise default to setting dbname=postgres and using
    * environment variables or defaults for all other connection parameters.
    */
   conninfo = "user = postgres password = postgres \
		       hostaddr = 127.0.0.1 port = 5678 \
	       	   connect_timeout = 2\
		       dbname = qTotem";

   /* Make a connection to the database */
   conn = PQconnectdb(conninfo);

   /* Verifique que la conexión de backend se haya realizado correctamente */
   if (PQstatus(conn) != CONNECTION_OK)
   {
	   fprintf(stderr, "Connection to database failed: %s",
			   PQerrorMessage(conn));
	   exit_nicely(conn);
   }
   /*-- preparamos para haer las consulta sobre qTotem*/
   pListQuery = &listQuery_qTotem[0];

   do{
	   /* Establezca una ruta de búsqueda siempre segura, para que los
		* usuarios malintencionados no puedan tomar el control. */
	   //res = PQexec(conn,"SELECT * FROM monitoreo_devices_fuera_servicio");
	   printf("Realizando la consulta: %s\n\n",pListQuery->leyenda);
	   res = PQexec(conn,pListQuery->query);

	   if (PQresultStatus(res) != PGRES_TUPLES_OK)
	   {
		   fprintf(stderr, "SET failed: %s", PQerrorMessage(conn));
		   PQclear(res);
		   exit_nicely(conn);
	   }
	   /*-- obtnemos el numero de Filas, del resultado de la consulta */
	   rows = PQntuples(res);
	   ncols = PQnfields(res);
	   for(i=0; i<rows; i++)
	   {
		   /*
				* PQgetvalue(resultQuery, nroFila, nroColumna)
				* */
		   for(j=0;j<ncols;j++)
		   {
			   printf("\t%s",PQgetvalue(res, i, j));
		   }
		   puts("");
		   /*printf("%s %s %s\n", PQgetvalue(res, i, 0),
				   PQgetvalue(res, i, 1), PQgetvalue(res, i, 2));*/
	   }
	   PQclear(res);
	   pListQuery++;
   }while(pListQuery->query != NULL);
   /*
    * Debe siempre hacer un  PQclear sobre PGresult siempre que ya no sea necesario
    * para evitar pérdidas de memoria
    */
   PQfinish(conn);
   exit(EXIT_SUCCESS);
}
/*
┌────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                    │  
│                                                                                    │  
│ ─────────────────────────[ End apis main version 5      ]────────────────────────  │
│                                                                                    │
│                                                                                    │             
└────────────────────────────────────────────────────────────────────────────────────┘
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
#include <libpq-fe.h>
#include <string.h>


query_sT listQuery_qTotem[] = {
		 /* CONSUTA										 | LEYENDA		| fx que Porcesa campos | fx query vacia */
		 {"select * from monitoreo_devices_fuera_servicio", "tablas de  errores",NULL,print_emptly_query}
		,{"select totem_habilitado from config","Tabla donde Habilita/Deshabilita el Totem",print_field_query,print_emptly_query}
		,{"select * from monitoreo_devicesconfig","Tabla de Configuracion del Dispositivo",NULL,print_emptly_query}
		,{"select sum(cantidad) from billetes","cantidad de Billetes en Stacker",print_field_query,print_emptly_query}
		,{NULL}
};

query_sT listQuery_bspa[] = {
		 {"select * from \"RelacionProductoServicio\"", "Tablas Relacion Producto",NULL,print_emptly_query}
		,{"select * from \"OpenOperations\" where \"FechaOperacion\" >= '2016-08-19'"," Operaciones Abiertas",NULL,print_emptly_query}
		,{"select * from \"LogLgServer\" where date >= '2016-08-25'"," Log del LG Server",NULL,print_emptly_query}
		,{NULL}
};




/*
 *
 * *******************************************************************
 * @brief funcion principal 
 * @param argn numeros de Arguemtnos por defecto es '1' 
 * @param arg array de arguemento, arg[0] := path/appname
 * @return estado de la ejecucion
 *  + EXIT_SUCCESS : ejecucion finalizada de forma exitosa
 *  + EXIT_FAIL : ejecucion finalizada con error 
 * 
 *********************************************************************/    
int main(int argn,char **arg)
{

   puts("\nListado de las consultas \"listQuery_qTotem\"");
   if(proccessListQuery("qTotem",listQuery_qTotem))
   {
	   puts("\n\tEJECUCION FALLO.\n");
   }
   else
   {
	   puts("\n\tEJECUCION SASTIFACTORIA.\n");
   }
   puts("\nListado de las consultas \"listQuery_bspa\"");
   if(proccessListQuery("bspa",listQuery_bspa))
   {
	   puts("\n\tEJECUCION FALLO.\n");
   }
   else
   {
	   puts("\n\tEJECUCION SASTIFACTORIA.\n");
   }
   exit(EXIT_SUCCESS);
}

void print_field_query(int r,int c, const char *strQ)
{
	printf("\tFila: %d\tColumna: %d\tCampo: %s\t",r,c,strQ);
}

void print_emptly_query(const char *stley)
{
	printf("\tConsulta sobre %s VACIA\n",stley);
}

int proccessListQuery(const char *dbName, query_sT *pListQuery)
{
	PGconn *conn; /* para la conexion con la base de datos*/
	PGresult *res;/* para almacenar el objeto resultado de la query */
	int rows, i;
	int ncols,j;
	char connInfo[128]= CONN_INFO();

	if(dbName == NULL )
	{
		puts("String connInfo Nulo");
		return 1;
	}
	if(pListQuery == NULL )
	{
		puts("Lista de consulta pListQuery Nulo");
		return 1;
	}
	strcat(connInfo,dbName);
	/* Make a connection to the database */
	conn = PQconnectdb(connInfo);
	/* Verifique que la conexión de backend se haya realizado correctamente */
	if (PQstatus(conn) != CONNECTION_OK)
	{
		fprintf(stderr, "Connection to database failed: %s",
				PQerrorMessage(conn));
		PQfinish(conn);
		return 1;
	}
	/*-- preparamos para haer las consulta sobre qTotem*/
	while(pListQuery->query != NULL)
	{
		/* Establezca una ruta de búsqueda siempre segura, para que los
		 * usuarios malintencionados no puedan tomar el control. */

		printf("Realizando la consulta: %s\n\n",pListQuery->leyenda);
		res = PQexec(conn,pListQuery->query);
		if (PQresultStatus(res) != PGRES_TUPLES_OK)
		{
			fprintf(stderr, "SET failed: %s", PQerrorMessage(conn));
			PQclear(res);
			PQfinish(conn);
			return 1;
		}
		/*-- obtnemos el numero de Filas, del resultado de la consulta */
		rows = PQntuples(res);
		ncols = PQnfields(res);
		if((rows == 0)&&(ncols == 0))
		{
			if((pListQuery->emptlyQuery != NULL)&&(pListQuery->leyenda != NULL))
			{
				(pListQuery->emptlyQuery)(pListQuery->leyenda);
			}
		}
		for(i=0; i<rows; i++)
		{
			/* PQgetvalue(resultQuery, nroFila, nroColumna) */
			for(j=0;j<ncols;j++)
			{
				if(pListQuery->proccessQuery == NULL)
				{
					printf("\t%s",PQgetvalue(res, i, j));
				}
				else
				{
					(pListQuery->proccessQuery)(i,j,PQgetvalue(res, i, j));
				}
			}
			if(pListQuery->proccessQuery == NULL) puts("");
		}
		PQclear(res);
		pListQuery++;
	}
	/*
	 * Debe siempre hacer un  PQclear sobre PGresult siempre que ya no sea necesario
	 * para evitar pérdidas de memoria
	 */
	PQfinish(conn);
	return 0;
}
/*
┌────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                    │  
│                                                                                    │  
│ ─────────────────────────[ End apis main version 6      ]────────────────────────  │
│                                                                                    │
│                                                                                    │             
└────────────────────────────────────────────────────────────────────────────────────┘
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
#include <libpq-fe.h>
#include <string.h>
/* #include <stdlib.h> */


#if 0
menu_t menu_option[] = {
     {OPTION(lg),LEYEND(lg),FUNCTION(lg)}
    ,{OPTION(usb),LEYEND(usb),FUNCTION(usb)}
     /**/
    ,{OPTION(help),LEYEND(help),FUNCTION(help)}
    ,{OPTION(version),LEYEND(version),FUNCTION(version)}
    ,{OPTION(author),LEYEND(author),FUNCTION(author)}
    ,{NULL}
};
#else
menu_t menu_option[] = {
		menu_FILL(lg)
		,menu_FILL(usb)
		,menu_FILL(error)
		,menu_FILL(event)
		,menu_FILL(bill)
		,menu_FILL(ups)
		,menu_FILL(totem)
		/**/
		,menu_FILL(help)
		,menu_FILL(version)
		,menu_FILL(author)
		/* terminador del Menu */
		,menu_TERMINATOR()
};

#endif


char *ptrNmbCmd;
/*
 *
 * *******************************************************************
 * @brief funcion principal 
 * @param argn numeros de Arguemtnos por defecto es '1' 
 * @param arg array de arguemento, arg[0] := path/appname
 * @return estado de la ejecucion
 *  + EXIT_SUCCESS : ejecucion finalizada de forma exitosa
 *  + EXIT_FAIL : ejecucion finalizada con error 
 * 
 *********************************************************************/
int main(int argn,char **arg)
{

	int i;
	fx_optiont_pfT pfxOption;

	/*-- recorremos el array de argumentos
	 * En la posicion 0, tenemos el path y nombre de la APP
	 * */

	ptrNmbCmd = arg[0];
	/* printf("\t\t%s\n\n",ptrNmbCmd);*/
	if(argn > 1)
	{
		i = 1;
	}
	else
	{
#if 0
		puts(SET_COLOR(FONT,RED)"\tNo se Ingresaron Argumentos\n\tVisualizando el mensaje de Ayuda:"\
							SET_COLOR(FONT,RESET));
		option_help(NULL);
#else
		puts(SET_COLOR(FONT,RED)"\tNo se Ingresaron Argumentos, Secuencia por defecto"SET_COLOR(FONT,RESET));
		option_totem(NULL);
		option_error(NULL);
		option_event(NULL);
		option_bill(NULL);
		option_usb(NULL);
		option_ups(NULL);
#endif
		/*-- no debemos saltar al label main_exit*/
		exit(EXIT_SUCCESS);
	}

	while(i < argn)
	{
		/*printf("\t%d\t%s\n",i,*arg);
		 *arg++;*/
		PRINTF_DEBUG("\t%d\t%s\n",i,arg[i]);
		pfxOption = get_funtionOption(menu_option,arg[i]);
		if(pfxOption == NULL)
		{
			printf("Parametro\t"SET_COLOR(FONT,RED)"\"%s\""\
					SET_COLOR(FONT,RESET)"\tes incorrecto\n",arg[i]);
			puts(SET_COLOR(FONT,BLUE)"Visualizando el mensaje de Ayuda:"\
								SET_COLOR(FONT,RESET));
			/*print_menu(menu_option);*/
			option_help(NULL);

			/*exit(EXIT_SUCCESS);*/
			goto main_exit;
		}
		/* En "pfxOption" tenemos le puntero a funcion a la operacion
		 * debemos buscar el arguemtno si es que tiene
		 * */
		i++;
		if(i == argn)
		{
			/* Nos quedamos sin argumentos, llegamos al final*/
			if((pfxOption)(NULL))
			{
				/*printf("Llamado incorrecto con los argumentos %s \n",arg[i-1]);*/
				printf("Llamado incorrecto: "SET_COLOR(FONT,RED)\
						"%s\n"\
						SET_COLOR(FONT,RESET),arg[i-1]);
				option_help(NULL);
			}
			else
			{
				PRINTF_DEBUG("Ejecucion sastifactoria de los Argumentos: %s\n",arg[i-1]);
			}
			goto main_exit;
			/* exit(EXIT_SUCCESS); */
		}
		/* comprobamos si el siguente argumento pertenece a otra accion */
		if(get_funtionOption(menu_option,arg[i]) == NULL)
		{
			/* Es un argumento para la opcion anterior */
			if((pfxOption)(arg[i]))
			{
				printf("Llamado incorrecto: "SET_COLOR(FONT,RED)\
						"%s %s\n"\
						SET_COLOR(FONT,RESET),arg[i-1],arg[i]);
				option_help(NULL);
				/*print_menu(menu_option);*/
				goto main_exit;
				/* //exit(EXIT_SUCCESS); */
			}
			else
			{
				PRINTF_DEBUG("Ejecucion sastifactoria de los Argumentos: %s %s\n",arg[i-1],arg[i]);
			}
		}
		else
		{
			/* debemos llamar a la opcion sin argumento */
			i--;
			if((pfxOption)(NULL))
			{
				/*printf("Llamado incorrecto con el argumento: %s\n",arg[i]);*/
				printf("Llamado incorrecto: "SET_COLOR(FONT,RED)\
						"%s \n"\
						SET_COLOR(FONT,RESET),arg[i]);
				option_help(NULL);
			}
			else
			{
				PRINTF_DEBUG("Ejecucion sastifactoria con el Argumento: %s\n",arg[i]);
			}
		}
		/*  tomamos un argumentos mas, incrementamos el index */
		i++;
	}



#if 0

   puts("\nListado de las consultas \"listQuery_qTotem\"");
   if(proccessListQuery("qTotem",listQuery_qTotem))
   {
	   puts("\n\tEJECUCION FALLO.\n");
   }
   else
   {
	   puts("\n\tEJECUCION SASTIFACTORIA.\n");
   }
   puts("\nListado de las consultas \"listQuery_bspa\"");
   if(proccessListQuery("bspa",listQuery_bspa))
   {
	   puts("\n\tEJECUCION FALLO.\n");
   }
   else
   {
	   puts("\n\tEJECUCION SASTIFACTORIA.\n");
   }
#endif
main_exit:
   option_author("AUTHOR");
   exit(EXIT_SUCCESS);
}


/**
 *
 * ****************************************************************************//**
 * \fn fx_optiont_pfT get_funtionOption(menu_t *pmenu, char * option);
 * \brief Funcion para obtener el puntero a funcion de la Opcion pasada como
 * argumeto \ref option.
 * \param pmenu : Puntero a menu, sobre el cual tenemos definidos las
 * opciones que pueden ser llamadas y sobre la cual vamos a buscar.
 * \param option :  string con la opcion a buscar y sobre la cual obtendremos
 * el puntero a funcion.
 * \return devolveremos el puntero a funcion correspondiente a la opcion pasada
 * como \ref option.
 * 	En caso de devolver un NULL, quiere decir que la opcion no se encontro dentro
 * 	del menu o bien la opcion esta deshabilitada (ya con no tiene definida una
 * 	funcion a ejecutar).
 * \note
 * \warning
 * \par example :
<PRE>
  pfxOption = get_funtionOption(menu_option,arg[i]);
  if(pfxOption == NULL)
  {
	printf("Parametro \"%s\" es incorrecto",arg[i]);
	print_menu(menu_option);
	exit(EXIT_SUCCESS);
  }
</PRE>
 *********************************************************************************/
fx_optiont_pfT get_funtionOption(menu_t *pmenu, char * option)
{
    while(pmenu->opt != NULL)
    {
    	if(strcmp(pmenu->opt,option) == 0)
    	{
    		return pmenu->fxOption;
    	}
    	pmenu++;
    }
    return NULL;
}
/**
 *
 * ****************************************************************************//**
 * \fn void print_menu(menu_t *pmenu  );
 * \brief descripcion breve.
 * \details descripcon detallada.
 * \param *pmenu : Argumento uno del tipo menu_t.
 * \return valor de retorno del tipo void.
 * \note nota sobre la funcion.
 * \warning mensaje de precaucion sobre la funcion.
 * \par example :
  <PRE>
   print_menu(menu_options);
  </PRE>
 *********************************************************************************/
/*void print_menu(menu_t *pmenu)
{
	puts("");
    while(pmenu->opt != NULL)
    {
        printf("%s\n",pmenu->leyenda);
        pmenu++;
    }

}*/



/* Consultas sobre el LG */
void proccQuery_lgcheck_0(int row,int col, const char *strFied)
{
	static unsigned char st = 0;
	if(st == 1)
	{
		/* Puerto Configuracin TAS*/
		printf("\t"SET_COLOR(FONT,BLUE)"Puerto Configurado para el LG: "SET_COLOR(FONT,GREEN)"%s\n"\
				SET_COLOR(FONT,RESET),strFied);
		st = 2;
		return;
	}
	if(st == 2)
	{
		/* Puerto Configuracin TAS*/
		printf("\t"SET_COLOR(FONT,BLUE)"PDS Asignado al Equipo: "SET_COLOR(FONT,GREEN)"%s\n"\
				SET_COLOR(FONT,RESET),strFied);
		st = 0;
		return;
	}
	switch(col)
	{
	case 0:/* Numero TAS*/
		printf("\n\t"SET_COLOR(FONT,BLUE)"Nro de TAS: "SET_COLOR(FONT,GREEN)"%s\n"\
				SET_COLOR(FONT,RESET),strFied);
		return;
	case 1:/* POS ID*/
		printf("\t"SET_COLOR(FONT,BLUE)"POS ID: "SET_COLOR(FONT,GREEN)"%s\n"\
				SET_COLOR(FONT,RESET),strFied);
		return;
	case 2:/* N° Serie LG*/
		printf("\t"SET_COLOR(FONT,BLUE)"Nro de Serie LG: "SET_COLOR(FONT,GREEN)"%s\n"\
				SET_COLOR(FONT,RESET),strFied);
		return;
	case 3:/* N° Serie SAM*/
		printf("\t"SET_COLOR(FONT,BLUE)"Nro de Serie SAM: "SET_COLOR(FONT,GREEN)"%s\n"\
				SET_COLOR(FONT,RESET),strFied);
		return;
	case 4:/* N° Pin SAM*/
		printf("\t"SET_COLOR(FONT,BLUE)"PIN de SAM: "SET_COLOR(FONT,GREEN)"%s\n"\
				SET_COLOR(FONT,RESET),strFied);
		st = 1;
		return;
	default:
		PUTS_DEBUG("\n\t"\
				SET_COLOR(FONT,RED)\
				"col Incorrecto.\n"\
				SET_COLOR(FONT,RESET)\
		);
		return;
	}
}



#if 0
query_sT listQuery_qTotem[] = {
		 /* CONSUTA										 | LEYENDA		| fx que Porcesa campos | fx query vacia */
		 {"select * from monitoreo_devices_fuera_servicio", "tablas de  errores",NULL,print_emptly_query}
		,{"select totem_habilitado from config","Tabla donde Habilita/Deshabilita el Totem",print_field_query,print_emptly_query}
		,{"select * from monitoreo_devicesconfig","Tabla de Configuracion del Dispositivo",NULL,print_emptly_query}
		,{"select sum(cantidad) from billetes","cantidad de Billetes en Stacker",print_field_query,print_emptly_query}
		,{NULL}
};

query_sT listQuery_bspa[] = {
		 {"select * from \"RelacionProductoServicio\"", "Tablas Relacion Producto",NULL,print_emptly_query}
		,{"select * from \"OpenOperations\" where \"FechaOperacion\" >= '2016-08-19'"," Operaciones Abiertas",NULL,print_emptly_query}
		,{"select * from \"LogLgServer\" where date >= '2016-08-25'"," Log del LG Server",NULL,print_emptly_query}
		,{NULL}
};
#endif

void print_emptly_PDS(const char *stley)
{
	puts(" "SET_COLOR(FONT,RED)\
			"\tSin PDS (Punto de Servicio) Asignado Actualmente"SET_COLOR(FONT,RESET));
}
/*
 'select dispositivos_fisico_id,posid,lgid,samid,sam_pin from config;' | psql qTotem"
 'select puerto_serie_lg from config;' | psql qTotem"
 'select \"puntoservicioid\" from \"DevicesBspa\";' | psql bspa"
 Para esteblecer la cantidad de billetes:
update billetes set cantidad='50' where parametro='2';
update billetes set cantidad='10' where parametro='1';

 */
void printEmptly_listQuery_lgcheck3(const char *pstr)
{
	char buff[32];
	getCurrentDate(buff,sizeof(buff));
	printf("\tNo se reportan transacciones en el LOG del LG SERVER, para la Fecha: "SET_COLOR(FONT,RED)\
				"%s"SET_COLOR(FONT,RESET)"\n",buff);
}
query_sT listQuery_lgcheck[] = {
 /* CONSUTA										 | LEYENDA		| fx que Porcesa campos | fx query vacia */
 {"select dispositivos_fisico_id,posid,lgid,samid,sam_pin from config", "Datos de Configuracion del LG" /* --lg		[0]*/\
   ,proccQuery_lgcheck_0,print_emptly_query}
 ,{"select puerto_serie_lg from config",NULL/*"Puerto Configurado para el LG"*/,\
		 proccQuery_lgcheck_0/*NULL*/,print_emptly_query}		/* --lg	"port" [1]*/
 ,{"select \"puntoservicioid\" from \"DevicesBspa\"",NULL/*"PDS Asignado al Equipo" */,\
		 proccQuery_lgcheck_0/*NULL*/,print_emptly_PDS}  /* --lg		[2]*/
 ,{"select * from \"LogLgServer\" where date >= $1","Log del LG Server",NULL,printEmptly_listQuery_lgcheck3}  		/* --lg	log	[3]*/
};

update_sT listUpdate_lg[] = {
 {"UPDATE config SET puerto_serie_lg='/dev/ttyLG'","Habilitamos el Puerto para el LG"}		 /* --lg	on	[0]*/
 ,{"UPDATE config SET puerto_serie_lg='/dev/ttyLGNO'","Deshabilitamos el Puerto para el LG"} /* --lg	off	[1]*/
};


/*
 * ******************************************************************************
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
int option_lg(char * arg)
{
	static int i;
	/*FILE *output;*/
	static char buff[32];
	const char *paramValues[1];
    if(arg == NULL)
    {
    	i = 0;
    	PUTS_DEBUG("call: --lg\t\t :Sin argumentos, visualizamos los datos del LG");
    	PUTS_DEBUG("\nLlamado \"proccessQuery(\"qTotem\",&listQuery_lgcheck[i])\"");
    	do{
    		/*-- consulta Cero y Uno */
    		PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_lgcheck[i]));
			i++;
    	}while(i<2);
    	/*-- consulta Dos */
    	PRINT_STATUS_QUERY(proccessQuery("bspa",&listQuery_lgcheck[i]));
    	NEW_LINE_BETWEEN_CMD();
    	puts("");
        return 0;
    }
    if(strcmp("on",arg) == 0)
    {
    	PUTS_DEBUG("call: --lg on\t\t :Habilitamos el LG (Base de Datos)");
    	/*-- visualizamos el estado actual del Puerto */
    	PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_lgcheck[1]));
    	/*-- Habilitmamos el Puerto del LG */
    	PRINT_STATUS_QUERY(proccessUpdate("qTotem",&listUpdate_lg[0]));
		/*-- visualizamos el estado actual del Puerto */
		PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_lgcheck[1]));
		NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    if(strcmp("off",arg) == 0)
    {
    	PUTS_DEBUG("call: --lg off\t\t :Deshabilitamos el LG (Base de Datos)");
    	/*-- visualizamos el estado actual del Puerto */
    	PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_lgcheck[1]));
    	/*-- Habilitmamos el Puerto del LG */
    	PRINT_STATUS_QUERY(proccessUpdate("qTotem",&listUpdate_lg[1]));
		/*-- visualizamos el estado actual del Puerto */
		PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_lgcheck[1]));
		NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    if(strcmp("log",arg) == 0)
    {
#if 0
    	output = popen("date +\"%Y-%m-%d\"", "r");/* comando "more", direccionamos*/
    	if( output == NULL)
    	{
    		PUTS_DEBUG("Error no se puede abrir el proceso mediante pipe");
    		return 1;
    	}
    	fgets(buff, sizeof(buff), output);
#endif
    	if(getCurrentDate(buff,sizeof(buff))) return 1;
    	/*printf("\n\t\t Fecha Actual es\t: %s",buff); */
    	PUTS_DEBUG("call: --lg log\t\t :Obtenemso el Log del LG server");
    	/*snprintf(buff, sizeof(buff), "%s","2016-08-25"); */
    	paramValues[0] = buff;
    	PRINT_STATUS_QUERY(proccessQueryWhere("bspa",&listQuery_lgcheck[3],paramValues));
    	/* PRINT_STATUS_QUERY(proccessQueryWhere("bspa",&listQuery_lgcheck[3],"2016-08-25"));*/
    	NEW_LINE_BETWEEN_CMD();
        return 0;
    }
#if 0
    if(strcmp("down",arg) == 0)
    {
    	PUTS_DEBUG("call: --lg down\t\t :Realiza la secuencia para deshabilitar el LG");
        return 0;
    }
#endif
    return 1;
}

query_sT listQuery_err_ev[] = {
 /* CONSUTA										 | LEYENDA		| fx que Porcesa campos | fx query vacia */
/* [0] */ {"select * from monitoreo_devices_fuera_servicio", "Errores del Equipo:",print_field_error,print_emptly_error}			/* --error		[0]*/\
/* [1] */,{"select * from monitoreo_devicesevents","Eventos del Equipo:",NULL,print_emptly_error/*print_emptly_event*/}		/* --event      [1]*/
/* [2] */,{"select sum(cantidad) from billetes",NULL/*"Cantidad de Billetes En Stacker"*/\
		 ,print_field_bill,print_emptly_query}					/* --bill       [2]*/
/* [3] */,{"select max_billetes_stacker from config ",NULL/*"Cantidad Maxima de Billetes Establecidos para El Stacker"*/\
		 ,print_field_bill,print_emptly_query}
/* [4] */,{"select totem_habilitado from config","Estado del totem"\
 		 ,print_field_totem,NULL}
};
update_sT listUpdate_err_ev[] = {
  {"delete from monitoreo_devices_fuera_servicio","Borrando la Tabla de Errores"}		/* --error	clean [0]*/
 ,{"delete from monitoreo_devicesevents","Borrando la Tabla de Eventos"} 				/* --event clean [1]*/
};

int option_error(char * arg)
{
	/* usamos una pipe, para leer el comando */
	FILE *output;
	char buffer[32];
	static unsigned int nline=0;
    if(arg == NULL)
    {
    	PUTS_DEBUG("call: --error\t\t :Sin argumentos, visualizamos la tabla de Errores");
    	PUTS_DEBUG("\nLlamado \"proccessQuery(\"qTotem\",&listQuery_err_ev[0])\"");
    	/*-- consulta Cero y Uno */
    	PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_err_ev[0]));
    	NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    if(strcmp("clean",arg) == 0)
    {
    	PUTS_DEBUG("call: --error clean\t\t :Borrando la Tabla de Errores");
    	/*-- Borramos la TAbla de Errores */
    	PRINT_STATUS_QUERY(proccessUpdate("qTotem",&listUpdate_err_ev[0]));
    	NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    if(strcmp("printer",arg) == 0)
    {
    	PUTS_DEBUG("call: --error printer\t\t :Busqueda de Error de la impresora");
    	/*-- usamos una pipe */
#if(defined(REMOTO_CONNECT))
    	output = popen("cat /home/jel/Escritorio/temporal | grep \"ERROR DE CONFIGURACION MONITOREO: OBTENER LA IDENTIFICACION DE LA PRINTER\"", "r");
#else
		output = popen("tail -n10000 /home/c_tallion/qTotem/totem.log | grep \"ERROR DE CONFIGURACION MONITOREO: OBTENER LA IDENTIFICACION DE LA PRINTER\"", "r");/* comando "more", direccionamos*/
#endif
		if(fgets(buffer, sizeof(buffer), output) == NULL)
		{
			puts(SET_COLOR(FONT,GREEN)\
					"\tNo se detecta Error en Impresora"\
					SET_COLOR(FONT,RESET));
		}
		else
		{
			puts(SET_COLOR(FONT,RED)"\tError al Obtner el Printer ID, "\
					SET_COLOR(FONT,RED)"falla en mecanismo o placa logica de la Impresora"\
					SET_COLOR(FONT,RESET));
		}
		NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    if(strcmp("stacker",arg) == 0)
    {
    	PUTS_DEBUG("call: --stacker printer\t\t :Busqueda de Error de la impresora");
    	/*-- usamos una pipe */
#if(defined(REMOTO_CONNECT))
    	output = popen("cat /home/jel/Escritorio/temporal | grep \"STACKER FUERA DE LUGAR\"", "r");
#else
		output = popen("tail -n10000 /home/c_tallion/qTotem/totem.log | grep \"STACKER FUERA DE LUGAR\"", "r");/* comando "more", direccionamos*/
#endif
		nline = 0;
		while(fgets(buffer, sizeof(buffer), output) != NULL) nline ++;
		if(nline > 5)
		{
			puts(SET_COLOR(FONT,RED)"\tSTACKER FUERA DE LUGAR"SET_COLOR(FONT,RESET));

		}
		else
		{
			puts(SET_COLOR(FONT,GREEN)"\tNo se detecta Error con el STACKER"\
					SET_COLOR(FONT,RESET));
		}
		NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    if(strcmp("posid",arg) == 0)
    {
    	PUTS_DEBUG("call: --error posid\t\t :Busqueda de Error de la impresora");
    	/*-- usamos una pipe */
#if(defined(REMOTO_CONNECT))
    	output = popen("cat /home/jel/Escritorio/temporal | grep \"ERROR POS ID\"", "r");
#else
		output = popen("tail -n10000 /home/c_tallion/qTotem/totem.log | grep \"ERROR POS ID\"", "r");
#endif
		/**
		 * */
		if(fgets(buffer, sizeof(buffer), output) != NULL)
		{
			puts(SET_COLOR(FONT,RED)"\tError reportado por LG, POS ID incorrecto f001"SET_COLOR(FONT,RESET));
		}
		else
		{
			puts(SET_COLOR(FONT,GREEN)"\tNo se detecta Error de POS ID"\
					SET_COLOR(FONT,RESET));
		}
		NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    /*-- Opcion pasada es incorrecta */
    PUTS_DEBUG(SET_COLOR(FONT,RED)"Opcion/Argumento pasado es incorrecto\n"SET_COLOR(FONT,RESET));
	return 1;
}




int option_event(char * arg)
{
    if(arg == NULL)
    {
    	PUTS_DEBUG("call: --event\t\t :Sin argumentos, visualizamos la tabla de Eventos");
    	PUTS_DEBUG("\nLlamado \"proccessQuery(\"qTotem\",&listQuery_err_ev[1])\"");
    	/*-- consulta Cero y Uno */
    	PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_err_ev[1]));
    	NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    if(strcmp("clean",arg) == 0)
    {
    	PUTS_DEBUG("call: --event clean\t\t :Borrando la Tabla de Eventos");
    	/*-- Borramos la TAbla de Errores */
    	PRINT_STATUS_QUERY(proccessUpdate("qTotem",&listUpdate_err_ev[1]));
    	NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    /*-- Opcion pasada es incorrecta */
    PUTS_DEBUG(SET_COLOR(FONT,RED)"Opcion/Argumento pasado es incorrecto\n"SET_COLOR(FONT,RESET));
    return 1;
}

/*
su -l postgres -c "echo 'select totem_habilitado from config;'|psql qTotem"

 */
int option_totem(char * arg)
{
    if(arg != NULL) return 1;
    PUTS_DEBUG("call: --status\t :estado de la aplicacion");
    PUTS_DEBUG("\nLlamado \"proccessQuery(\"qTotem\",&listQuery_err_ev[4])\"");
    /*-- consulta Cero y Uno */
    PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_err_ev[4]));
    return 0;


}

int option_bill(char * arg)
{
    if(arg != NULL) return 1;
    PUTS_DEBUG("call: --bill\t\t :Sin argumentos, visualizamos la cantidad de billetes en Stacker");
    PUTS_DEBUG("\nLlamado \"proccessQuery(\"qTotem\",&listQuery_err_ev[0])\"");
    /*
     * 1 - Primero consultamos la cantidad maxima de Billetes Establecida para el Stacker
     * 2 - Segundo consultamos la cantidad de billetes
     * */
    PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_err_ev[3]));
    PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_err_ev[2]));
    NEW_LINE_BETWEEN_CMD();
    return 0;
}





list_error_sT  listErrores[]={
   {"E010009","TAS Habilitada"}
  ,{"E010201","Inconsistencias con el Switch"}
  ,{"E010121","Error de BO (Respuesta del estilo Abakpn...)"}
  ,{"E010120","Error de Time Out de servicion contra BO"}
  ,{"E010006","Logue de Usuario para abrir la cerradura, TRUE si es recaudador."}
  ,{"E010301","Inicio de Apertura Forzada de Cerradura."}
  ,{"E010302","Fin de Apertura Forzada de Cerradura."}
  ,{"E010006","Login de Usuario Recaudador, para abrir CEM, TRUE."}
  ,{"E010101","Estado INICIANDO."}
  ,{"E010102","Estado DESCONECTADO."}
  ,{"E010103","Estado LOGIN."}
  ,{"E010110","Estado IDENTIFICANDO."}
  ,{"E010111","Estado INICIALIZANDO."}
  ,{"E010112","Estado DIFUNDIENDO."}
  ,{"E010113","Estado ABRIENDO TURNO."}
  ,{"E010114","Estado CERRANDO TURNO."}
  ,{"E010115","Estado ENVIANDO TRANSACCIONES."}
  ,{"E010116","Estado SOLICITANDO CREDITO."}
  ,{NULL}
};




const char * get_id_error(list_error_sT *plistError, const char *arg)
{
	int i;
	if(arg == NULL) return NULL;
	i = 0;
	while(plistError->id != NULL)
	{
		if(strcmp(plistError->id,arg) == 0)
		{
			return plistError->brief;
		}
		i++;
		plistError++;
	}
	return (const char *) "Error No Identificado, intente con el Argumento \"--error clean\"";
}

void print_field_error(int r,int c, const char *strQ)
{
	if(c == 1)
	{
		printf("\tNro: "SET_COLOR(FONT,RED)"%s - %s"SET_COLOR(FONT,RESET)"\n"\
				,strQ,get_id_error(listErrores,strQ));
	}

}

void print_emptly_error(const char *strQ)
{
	/*puts(SET_COLOR(FONT,GREEN)": Equipo Sin Errores Reportados"SET_COLOR(FONT,RESET));*/
	/*printf(SET_COLOR(FONT,GREEN)" %s VACIA"SET_COLOR(FONT,RESET),strQ);*/
	puts(SET_COLOR(FONT,GREEN)"VACIA"SET_COLOR(FONT,RESET));
}
/*void print_emptly_event(const char *strQ)
{
	puts(SET_COLOR(FONT,GREEN)": Equipo sin Eventos Reportados"SET_COLOR(FONT,RESET));
}*/


void print_field_bill(int r,int c, const char *strQ)
{
	static unsigned char status = 0;
	static unsigned int maxBill,nroBill;
	float tmp;
	if((r != 0)&&(c != 0)) return;
	switch(status)
	{
		default:
		case 0:
			/*
			 * traslate string to integer or float
			 * 	>> int atoi(const char *nptr);
			 * 	>> long atol(const char *nptr);
			 * 	>> long long atoll(const char *nptr);
			 *
			 *	>> double atof(const char *nptr);
			 * 	>> atoi(3), atol(3), strfromd(3), strtod(3), strtol(3), strtoul(3)
			 *
			 *
			 * */
			maxBill = atoi(strQ);
			if(maxBill == 0) maxBill = 900;
			status = 1;
			return;
		case 1:
			nroBill = atoi(strQ);
			status = 0;
			break;
	}
/**
 * */
#if 0
	printf(SET_COLOR(FONT,BLUE)"\tCantidad de Billetes en Stacker: "SET_COLOR(FONT,GREEN)"%d\t"\
			SET_COLOR(FONT,BLUE)"\tCapacidad Ocupada del Stacker: "SET_COLOR(FONT,GREEN)"%0.2f [%]"\
			SET_COLOR(FONT,RESET)"\n",nroBill,tmp);
#endif
#if 0
	tmp = ((100.00 * nroBill)/maxBill);
	printf(SET_COLOR(FONT,BLUE)"\tCantidad de Billetes en Stacker: "SET_COLOR(FONT,GREEN)"%d"\
				SET_COLOR(FONT,RESET),nroBill);

		printf(SET_COLOR(FONT,BLUE)"\tCapacidad Ocupada del Stacker: "SET_COLOR(FONT,GREEN)"%0.2f [ %c ] "\
				SET_COLOR(FONT,RESET)"\n",tmp,37);

#else
	tmp = (((maxBill - nroBill)*100.0)/maxBill);
	printf(SET_COLOR(FONT,BLUE)"\tBilletes en Stacker: "SET_COLOR(FONT,GREEN)"%d\t"\
			SET_COLOR(FONT,RESET),nroBill);

	printf(SET_COLOR(FONT,BLUE)"\tDisponibilidad del Stacker: "SET_COLOR(FONT,GREEN)"%0.2f [ %c ] "\
			SET_COLOR(FONT,RESET)"\n",tmp,37);
#endif



}


void print_field_totem(int r,int c, const char *strQ)
{
	if(strcmp("t",strQ) == 0)
	{
		puts(SET_COLOR(FONT,GREEN)"TOTEM HABILITADO"SET_COLOR(FONT,GREEN)\
					SET_COLOR(FONT,RESET));
	}
	else
	{
		puts(SET_COLOR(FONT,RED)"TOTEM DESHABILITADO"SET_COLOR(FONT,GREEN)\
							SET_COLOR(FONT,RESET));
	}


}



list_usb_brief_sT listBriefUSB[]={
		  {"Impresora",0}
		 ,{"UPS",1}
		 ,{"LG",2}
		 ,{"Placa Distribuidora",3}
		 ,{"Monitor Touch",4}
		 ,{NULL}
};

list_usb_brief_sT listBriefUSBview[]={
		  {"Impresora \"Coustom TG2460\"",0}
		 ,{"UPS \"Lyonn CTB-800A\"",1}
		 ,{"LG, modelo \"Integresys\"",2}
		 ,{"LG, modelo \"Abakon\"",2}
		 ,{"\"Placa Distribuidora\"",3}
		 ,{"Monitor Tactil, modelo \"Avdo Atouch 190\"",4}
		 ,{"Monitor Tactil, modelo \"NUEVO etapa 1\"",4}
		 ,{NULL}
};

list_usb_sT listIdEnUSB[]={
		  {"0dd4:01a7"/*,"Impresora \"Coustom TG2460\""*/,0}
		 ,{"0665:5161"/*,"UPS \"Lyonn CTB-800A\""*/,1}
		 ,{"10c4:8855"/*,"LG, modelo \"Integresys\""*/,2}
		 ,{"10c4:ea60"/*,"LG, modelo \"Abakon\""*/,2}
		 ,{"04d8:000a"/*,"\"Placa Distribuidora\""*/,3}
		 ,{"24b8:0001"/*,"Monitor Tactil, modelo \"Avdo Atouch 190\""*/,4}
		 ,{"14e1:6000"/*,"Monitor Tactil, modelo \"NUEVO etapa 1\""*/,4}
		 ,{NULL}
};
list_usb_sT listIdEnUSBview[]={
		  {"0dd4:01a7"/*,"Impresora \"Coustom TG2460\""*/,0}
		 ,{"0665:5161"/*,"UPS \"Lyonn CTB-800A\""*/,1}
		 ,{"10c4:8855"/*,"LG, modelo \"Integresys\""*/,2}
		 ,{"10c4:ea60"/*,"LG, modelo \"Abakon\""*/,3}
		 ,{"04d8:000a"/*,"\"Placa Distribuidora\""*/,4}
		 ,{"24b8:0001"/*,"Monitor Tactil, modelo \"Avdo Atouch 190\""*/,5}
		 ,{"14e1:6000"/*,"Monitor Tactil, modelo \"NUEVO etapa 1\""*/,6}
		 ,{NULL}
};


#if 0
void check_usb(unsigned int st,list_usb_sT *plistUSB)
{
	unsigned int /*i,*/tmp;
	/*i = 0;*/
	while(plistUSB->id != NULL)
	{
		/* tmp = 0x01 << i;*/
		tmp = 0x01 << plistUSB->en;
		if(st & tmp)
		{
			printf(SET_COLOR(FONT,/*GREEN*/BLUE)\
					"\tDispostivo %s, conectado correctamente"\
					SET_COLOR(FONT,RESET)"\n"\
					,plistUSB->id);
		}
		else
		{
			printf(SET_COLOR(FONT,RED)\
					"\tEl Dispostivo %s, no se encuentra conectado"\
					SET_COLOR(FONT,RESET)"\n"\
					,plistUSB->id);
		}
		/*i++;*/
		plistUSB++;
	}
}
#endif

void check_usb_brief(unsigned int st,list_usb_brief_sT *plistUSB)
{
	unsigned int tmp;

	while(plistUSB->brief != NULL)
	{
		tmp = 0x01 << plistUSB->en;
		if(st & tmp)
		{
			printf(SET_COLOR(FONT,BLUE)"\tDISPOSITIVO: "\
					SET_COLOR(FONT,GREEN)"%s, CONECTADO"\
					SET_COLOR(FONT,RESET)"\n"\
					,plistUSB->brief);
		}
		else
		{
			printf(SET_COLOR(FONT,BLUE)"\tDISPOSITIVO: "\
					SET_COLOR(FONT,RED)"%s, NO CONECTADO"\
					SET_COLOR(FONT,RESET)"\n"\
					,plistUSB->brief);
		}
		plistUSB++;
	}
}

int get_status_usb(list_usb_sT *plistUSB, char *arg)
{
	/*int i;*/
	if(arg == NULL) return 0;
	/*i = 0;*/
	while(plistUSB->id != NULL)
	{
		if(strcmp(plistUSB->id,arg) == 0)
		{
			/*return i;*/
			return plistUSB->en;
		}
		/*i++;*/
		plistUSB++;
	}
	return -1;
}

/*
 * ******************************************************************************
 * \fn int option_usb(char * arg   );
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
int option_usb(char * arg)
{
	/* usamos una pipe, para leer el comando */
	FILE *output;
	char buffer[16];
	static unsigned int status;
	int tmp;
	do{
		if(arg == NULL)
		{
			PUTS_DEBUG("call: --usb\t\t :Realizamos el check de los dispositivos USB necesarios.");
			output = popen("lsusb | cut -d \" \" -f 6", "r");/* comando "lsusb", direccionamos*/
			if( output == NULL)
			{
				PUTS_DEBUG("Error no se puede abrir el proceso mediante pipe");
				return 1;
			}
			status = 0;
			while (fgets(buffer, 10, output) != NULL)
			{
				tmp = get_status_usb(/*listDeviceUSB*/listIdEnUSB,buffer);
				if(tmp >= 0)
				{
					status |= (0x01 << tmp);
				}
				/*printf("%s", buffer);*/
			}
			/* FIXME cambiar esta funcion
			 * */
			check_usb_brief(status,listBriefUSB);
			break;
		}
		if(strcmp("view",arg) == 0)
		{
			PUTS_DEBUG("call: --usb view\t\t :Realizamos el check de los dispositivos USB necesarios.");
			output = popen("lsusb | cut -d \" \" -f 6", "r");/* comando "lsusb", direccionamos*/
			if( output == NULL)
			{
				PUTS_DEBUG("Error no se puede abrir el proceso mediante pipe");
				return 1;
			}
			status = 0;
			while (fgets(buffer, 10, output) != NULL)
			{
				tmp = get_status_usb(/*listDeviceUSB*/listIdEnUSBview,buffer);
				if(tmp >= 0)
				{
					status |= (0x01 << tmp);
				}
				/*printf("%s", buffer);*/
			}

			check_usb_brief(status,listBriefUSBview);
			/*check_usb(status,listDeviceUSB);*/
			break;
		}
#if 0
		if(strcmp("rules",arg) == 0)
		{
			PUTS_DEBUG("call: --usb rules\t\t :Visualiza el archivo con las reglas para enumerar el LG");
			puts(SET_COLOR(FONT,BLUE)"\tOpcion \"rules\" No Disponible en esta version"SET_COLOR(FONT,RESET));
			return 0;
		}
		if(strcmp("update",arg) == 0)
		{
			PUTS_DEBUG("call: --usb update\t\t :Actualiza el archivo con las reglas para enumerar el LG");
			puts(SET_COLOR(FONT,BLUE)"\tOpcion \"update\" No Disponible en esta version"SET_COLOR(FONT,RESET));
			return 0;
		}
#endif
		return 1;
	}while(0);
	puts("");
	PCLOSE(output);
	NEW_LINE_BETWEEN_CMD();
	return 0;

}

int option_ups(char * arg)
{
	/* usamos una pipe, para leer el comando */
	FILE *output;
	char buffer[32];

	if(arg != NULL) return 1;
	/**/
	PUTS_DEBUG("call: --ups\t\t :Realizamos el check de la UPS.");
	/*
	 * */
	/* output = popen("upsc apc | grep -e\"driver.version:\" -e\"battery.voltage\" -e\"battery.charge\" -e\"input.voltage\" -e\"output.current\"", "r"); */
#if(defined(REMOTO_CONNECT))
	output = popen("cat /home/jel/Escritorio/temporal | grep -e\"battery.voltage:\" -e\"input.voltage:\" -e\"output.current.nominal:\"", "r");
#else
	output = popen("upsc apc | grep -e\"battery.voltage:\" -e\"input.voltage:\" -e\"output.current\"", "r");/* comando "more", direccionamos*/
#endif
	if( output == NULL)
	{
		puts("Error");
		PUTS_DEBUG("Error no se puede abrir el proceso mediante pipe");
		return 1;
	}
	while (fgets(buffer, sizeof(buffer), output) != NULL)
	{
		printf(SET_COLOR(FONT,BLUE)"%s"SET_COLOR(FONT,RESET), buffer);
	}
	PCLOSE(output);
	return 0;
}




int option_help(char * arg)
{
	if(arg != NULL) return 1;
	/*-- definimos un puntero y lo inicializamos */
	menu_t *pmenu = menu_option;
	HEAD_help(ptrNmbCmd);
    while(pmenu->opt != NULL)
    {
    	printf("OPCION : "SET_COLOR(FONT,BLUE)"\"%s\""\
    			SET_COLOR(FONT,RESET),pmenu->opt);

    	printf("\nUso y Argumentos:\n"SET_COLOR(FONT,GREEN)"%s\n"\
    				SET_COLOR(FONT,RESET),pmenu->leyend);
        pmenu++;
    }
    TAIL_help(ptrNmbCmd);
	return 0;
}

int option_version(char *arg)
{
	if(arg != NULL) return 1;
	PRINTF_DEBUG("Comando : "SET_COLOR(FONT,BLUE)"%s\n"\
	    			,OPTION(version));
	puts("\t"SET_COLOR(FONT,GREEN)"Version de la aplicacion "VERSION_STRING()\
			SET_COLOR(FONT,RESET));
	return 0;
}

int option_author(char *arg)
{
	if(arg != NULL)
	{
		if(strcmp("AUTHOR",arg) == 0)
		{
			printf(SET_COLOR(FONT,CYAN)"\n\n%s\n"\
						SET_COLOR(FONT,RESET),AUTHOR_STRINGbrief());
			return 0;
		}
		else return 1;
	}
	PRINTF_DEBUG("Comando : "SET_COLOR(FONT,BLUE)"%s\n"\
	    			,OPTION(author));
	puts("\t"SET_COLOR(FONT,GREEN)"Autor de la Aplicacion: "AUTHOR_STRING()\
			SET_COLOR(FONT,RESET));
return 0;
}



void print_field_query(int r,int c, const char *strQ)
{
	printf("\tFila: %d\tColumna: %d\tCampo: %s\t",r,c,strQ);
}

void print_emptly_query(const char *stley)
{
	printf("\tConsulta: "SET_COLOR(FONT,RED)\
			"%s"SET_COLOR(FONT,RESET)"  VACIA\n",stley);
}



int proccessQuery(const char *dbName, query_sT *pListQuery)
{
	PGconn *conn; /* para la conexion con la base de datos*/
	PGresult *res;/* para almacenar el objeto resultado de la query */
	int rows, i;
	int ncols,j;
	char connInfo[128]= CONN_INFO();

	if(dbName == NULL )
	{
		PUTS_DEBUG("String connInfo Nulo");
		return 1;
	}
	if(pListQuery == NULL )
	{
		PUTS_DEBUG("Lista de consulta pListQuery Nulo");
		return 1;
	}
	strcat(connInfo,dbName);
	/* Make a connection to the database */
	conn = PQconnectdb(connInfo);
	/* Verifique que la conexión de backend se haya realizado correctamente */
	if (PQstatus(conn) != CONNECTION_OK)
	{
		fprintf(stderr, "Connection to database failed: %s",
				PQerrorMessage(conn));
		PQfinish(conn);
		return 1;
	}
	/*-- preparamos para hacer las consulta sobre */
	if(pListQuery->query != NULL)
	{
		/* Establezca una ruta de búsqueda siempre segura, para que los
		 * usuarios malintencionados no puedan tomar el control. */

		if(pListQuery->leyenda != NULL ) /* Si la leyenda es distinta de NULL, imprimimos la misma */
		{
			printf(SET_COLOR(FONT,BLUE)"\t%s\t"SET_COLOR(FONT,RESET)\
				,pListQuery->leyenda);
		}
		res = PQexec(conn,pListQuery->query);
		if (PQresultStatus(res) != PGRES_TUPLES_OK)
		{
			fprintf(stderr, "SET failed: %s", PQerrorMessage(conn));
			PQclear(res);
			PQfinish(conn);
			return 1;
		}
		/*-- obtemos el numero de Filas, del resultado de la consulta */
		rows = PQntuples(res);
		ncols = PQnfields(res);
		if(rows == 0)
		{
			if((pListQuery->emptlyQuery != NULL))
			{
				if((pListQuery->leyenda != NULL))
				{
					(pListQuery->emptlyQuery)(pListQuery->leyenda);
					/*(pListQuery->emptlyQuery)(pListQuery->query);*/
				}
				else
					(pListQuery->emptlyQuery)(NULL);
			}
		}
		if((rows >= 1)&&(ncols < 1))
		{
			puts("");
		}
		/*if((rows !=1)&&(ncols !=1))
		{
			puts("");
		}
		if((rows == 1)&&(ncols !=1))
		{
			puts("");
		}*/
		for(i=0; i<rows; i++)
		{
			/* PQgetvalue(resultQuery, nroFila, nroColumna) */
			for(j=0;j<ncols;j++)
			{
				if(pListQuery->proccessQuery == NULL)
				{
					printf("\t%s",PQgetvalue(res, i, j));
				}
				else
				{
					(pListQuery->proccessQuery)(i,j,PQgetvalue(res, i, j));
				}
			}
			if(pListQuery->proccessQuery == NULL) puts("");
		}
	}
	/*
	 * Debe siempre hacer un  PQclear sobre PGresult siempre que ya no sea necesario
	 * para evitar pérdidas de memoria
	 */
	/*-- es aconsejable limpiar antes de salir */
	PQclear(res);
	PQfinish(conn);
	return 0;
}

int proccessUpdate(const char *dbName, update_sT *pListUpdate)
{
	PGconn *conn; /* para la conexion con la base de datos*/
	PGresult *res;/* para almacenar el objeto resultado de la query */
	char connInfo[128]= CONN_INFO();

	if(dbName == NULL )
	{
		PUTS_DEBUG("String connInfo Nulo");
		return 1;
	}
	if(pListUpdate == NULL )
	{
		PUTS_DEBUG("Lista de consulta pListQuery Nulo");
		return 1;
	}
	/*-- armamos el string para establecer la conexion*/
	strcat(connInfo,dbName);
	/* Make a connection to the database */
	conn = PQconnectdb(connInfo);
	/* Verifique que la conexión de backend se haya realizado correctamente */
	if (PQstatus(conn) != CONNECTION_OK)
	{
		fprintf(stderr, "Connection to database failed: %s",
				PQerrorMessage(conn));
		PQfinish(conn);
		return 1;
	}
	/*-- preparamos para haer las actualizacion */
	if(pListUpdate->update != NULL)
	{
		/* Indicamos el Inicio de un Bloque de Actualizacion */
		res = PQexec(conn,"BEGIN");
		if (PQresultStatus(res) != PGRES_COMMAND_OK)
		{
			fprintf(stderr, "BEGIN BLOCK failed: %s", PQerrorMessage(conn));
			PQclear(res);
			PQfinish(conn);
			return 1;
		}
		PQclear(res);
		/*-- Realizamos la Actualizacion del campo especificado */
		if(pListUpdate->leyenda != NULL)/* Imprimimos la leyenda, si esta no es null */
		{
			printf(SET_COLOR(FONT,BLUE)"\t%s\t"SET_COLOR(FONT,RESET)\
				,pListUpdate->leyenda);
		}
		res = PQexec(conn,pListUpdate->update);
		if (PQresultStatus(res) != PGRES_COMMAND_OK)
		{
			fprintf(stderr, "UPDATE/INSERT failed: %s", PQerrorMessage(conn));
			PQclear(res);
			PQfinish(conn);
			return 1;
		}
		puts("");
		/* Realizamos el commit del blocke de actualizacion */
		res = PQexec(conn, "COMMIT");
		if (PQresultStatus(res) != PGRES_COMMAND_OK)
		{
			fprintf(stderr, "COMMIT BLOCK failed: %s", PQerrorMessage(conn));
			PQclear(res);
			PQfinish(conn);
			return 1;
		}
	}
	/*
	 * Debe siempre hacer un  PQclear sobre PGresult siempre que ya no sea necesario
	 * para evitar pérdidas de memoria
	 */
	PQclear(res);
	PQfinish(conn);
	return 0;
}


int proccessQueryWhere(const char *dbName, query_sT *pListQuery, const char * const *strWhere)
{
	PGconn *conn; /* para la conexion con la base de datos*/
	PGresult *res;/* para almacenar el objeto resultado de la query */
	int rows, i;
	int ncols,j;
	char connInfo[128]= CONN_INFO();

	if(dbName == NULL )
	{
		PUTS_DEBUG("String connInfo Nulo");
		return 1;
	}
	if(pListQuery == NULL )
	{
		PUTS_DEBUG("Lista de consulta pListQuery Nulo");
		return 1;
	}
	strcat(connInfo,dbName);
	/* Make a connection to the database */
	conn = PQconnectdb(connInfo);
	/* Verifique que la conexión de backend se haya realizado correctamente */
	if (PQstatus(conn) != CONNECTION_OK)
	{
		fprintf(stderr, "Connection to database failed: %s",
				PQerrorMessage(conn));
		PQfinish(conn);
		return 1;
	}
	/*-- preparamos para hacer las consulta sobre */
	if(pListQuery->query != NULL)
	{
		/* Establezca una ruta de búsqueda siempre segura, para que los
		 * usuarios malintencionados no puedan tomar el control. */
		if(pListQuery->leyenda != NULL) /* Imprimimos la leyenda, si la misma no es null */
		{
			printf(SET_COLOR(FONT,CYAN)"\t%s\t"SET_COLOR(FONT,RESET)\
				,pListQuery->leyenda);
		}
		/*res = PQexec(conn,pListQuery->query);*/
		res = PQexecParams(conn, pListQuery->query
				, 1 /* N° de parametros a actualizar en la query */
				, NULL /* Tipos de Parametros, todos los paremetros '1' del mismo tipo */
				, strWhere /* Valor actual del Parametro, un string pra este caso */
		        , NULL /* Longitud del parametro Binario, NULL para uso de String*/
				, NULL /* Formato del Parametro, NULL para String  */
				, 0    /* Formato del Resultado , '0' resultado en formato String */
				);
		if (PQresultStatus(res) != PGRES_TUPLES_OK)
		{
			fprintf(stderr, "SELECT with WHERE failed: %s", PQerrorMessage(conn));
			PQclear(res);
			PQfinish(conn);
			return 1;
		}
		/*-- obtnemos el numero de Filas, del resultado de la consulta */
		rows = PQntuples(res);
		ncols = PQnfields(res);
		if(rows == 0)
		{
			if((pListQuery->emptlyQuery != NULL))
			{
				if((pListQuery->leyenda != NULL))
				{
					(pListQuery->emptlyQuery)(pListQuery->leyenda);
					/*(pListQuery->emptlyQuery)(pListQuery->query);*/
				}
				else
					(pListQuery->emptlyQuery)(NULL);
			}
		}
		if((rows !=1)&&(ncols !=1))
		{
			puts("");
		}
		for(i=0; i<rows; i++)
		{
			/* PQgetvalue(resultQuery, nroFila, nroColumna) */

			for(j=0;j<ncols;j++)
			{
				if(pListQuery->proccessQuery == NULL)
				{
					printf("\t%s",PQgetvalue(res, i, j));
				}
				else
				{
					(pListQuery->proccessQuery)(i,j,PQgetvalue(res, i, j));
				}
			}
			if(pListQuery->proccessQuery == NULL) puts("");
		}
	}
	/*
	 * Debe siempre hacer un  PQclear sobre PGresult siempre que ya no sea necesario
	 * para evitar pérdidas de memoria
	 */
	/*-- es aconsejable limpiar antes de salir */
	PQclear(res);
	PQfinish(conn);
	return 0;
}

unsigned char getCurrentDate(char *pbuff, size_t len)
{
	 FILE * file2pipe;
	 if(pbuff == NULL) return 1;
	 file2pipe = popen("date +\"%Y-%m-%d\"", "r");/* comando "more", direccionamos*/
	 if( file2pipe == NULL)
	 {
		 PUTS_DEBUG(SET_COLOR(FONT,RED)\
				 "Error \"getCurrentDate()\" no se puede abrir el proceso mediante pipe"\
				 SET_COLOR(FONT,RESET));
		 PCLOSE(file2pipe);
		 return 1;
	 }
	 fgets(pbuff, len, file2pipe);
	 PCLOSE(file2pipe);
	 return 0;
}


/**
 *
 * */
#if 0
char * stdstring_find(const char *src,const char *target)
{
  /*-- chequeamos que los String sean validos*/
  if((src == NULL)||(target == NULL)) return NULL;
  /*-- chequeamos si el string TARGET no esta vacio */
  if(*src == '\0') return NULL;
  while(*src != '\0')
  {
    if(*src == *target)
    {
        if(*(++src) == '\0')
        {
          return (++src);
        }
    }
    src++;
  }
  return NULL;
}
#endif

/*
┌────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                    │  
│                                                                                    │  
│ ─────────────────────────[ End apis main version 7      ]────────────────────────  │
│                                                                                    │
│                                                                                    │             
└────────────────────────────────────────────────────────────────────────────────────┘
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
#include <libpq-fe.h>
#include <string.h>

menu_t menu_option[] = {
		menu_FILL(lg)
		,menu_FILL(usb)
		,menu_FILL(error)
		,menu_FILL(event)
		,menu_FILL(bill)
		,menu_FILL(ups)
		,menu_FILL(totem)
		/**/
		,menu_FILL(help)
		,menu_FILL(version)
		,menu_FILL(author)
		/* terminador del Menu */
		,menu_TERMINATOR()
};

char *ptrNmbCmd;

/*
 *
 * *******************************************************************
 * @brief funcion principal 
 * @param argn numeros de Arguemtnos por defecto es '1' 
 * @param arg array de arguemento, arg[0] := path/appname
 * @return estado de la ejecucion
 *  + EXIT_SUCCESS : ejecucion finalizada de forma exitosa
 *  + EXIT_FAIL : ejecucion finalizada con error 
 * 
 *********************************************************************/
int main(int argn,char **arg)
{

	int i;
	fx_optiont_pfT pfxOption;

	/*-- recorremos el array de argumentos
	 * En la posicion 0, tenemos el path y nombre de la APP
	 * */

	ptrNmbCmd = arg[0];
	/* printf("\t\t%s\n\n",ptrNmbCmd);*/
	if(argn > 1)
	{
		i = 1;
	}
	else
	{
		puts(SET_COLOR(FONT,RED)"\tNo se Ingresaron Argumentos, Secuencia por defecto"SET_COLOR(FONT,RESET));
		option_totem(NULL);
		option_error(NULL);
		option_event(NULL);
		option_bill(NULL);
		option_usb(NULL);
		option_ups(NULL);

		/*-- no debemos saltar al label main_exit*/
		exit(EXIT_SUCCESS);
	}

	while(i < argn)
	{
		/*printf("\t%d\t%s\n",i,*arg);
		 *arg++;*/
		PRINTF_DEBUG("\t%d\t%s\n",i,arg[i]);
		pfxOption = get_funtionOption(menu_option,arg[i]);
		if(pfxOption == NULL)
		{
			printf("Parametro\t"SET_COLOR(FONT,RED)"\"%s\""\
					SET_COLOR(FONT,RESET)"\tes incorrecto\n",arg[i]);
			puts(SET_COLOR(FONT,BLUE)"Visualizando el mensaje de Ayuda:"\
								SET_COLOR(FONT,RESET));
			/*print_menu(menu_option);*/
			option_help(NULL);

			/*exit(EXIT_SUCCESS);*/
			goto main_exit;
		}
		/* En "pfxOption" tenemos le puntero a funcion a la operacion
		 * debemos buscar el arguemtno si es que tiene
		 * */
		i++;
		if(i == argn)
		{
			/* Nos quedamos sin argumentos, llegamos al final*/
			if((pfxOption)(NULL))
			{
				/*printf("Llamado incorrecto con los argumentos %s \n",arg[i-1]);*/
				printf("Llamado incorrecto: "SET_COLOR(FONT,RED)\
						"%s\n"\
						SET_COLOR(FONT,RESET),arg[i-1]);
				option_help(NULL);
			}
			else
			{
				PRINTF_DEBUG("Ejecucion sastifactoria de los Argumentos: %s\n",arg[i-1]);
			}
			goto main_exit;
			/* exit(EXIT_SUCCESS); */
		}
		/* comprobamos si el siguente argumento pertenece a otra accion */
		if(get_funtionOption(menu_option,arg[i]) == NULL)
		{
			/* Es un argumento para la opcion anterior */
			if((pfxOption)(arg[i]))
			{
				printf("Llamado incorrecto: "SET_COLOR(FONT,RED)\
						"%s %s\n"\
						SET_COLOR(FONT,RESET),arg[i-1],arg[i]);
				option_help(NULL);
				/*print_menu(menu_option);*/
				goto main_exit;
				/* //exit(EXIT_SUCCESS); */
			}
			else
			{
				PRINTF_DEBUG("Ejecucion sastifactoria de los Argumentos: %s %s\n",arg[i-1],arg[i]);
			}
		}
		else
		{
			/* debemos llamar a la opcion sin argumento */
			i--;
			if((pfxOption)(NULL))
			{
				/*printf("Llamado incorrecto con el argumento: %s\n",arg[i]);*/
				printf("Llamado incorrecto: "SET_COLOR(FONT,RED)\
						"%s \n"\
						SET_COLOR(FONT,RESET),arg[i]);
				option_help(NULL);
			}
			else
			{
				PRINTF_DEBUG("Ejecucion sastifactoria con el Argumento: %s\n",arg[i]);
			}
		}
		/*  tomamos un argumentos mas, incrementamos el index */
		i++;
	}

main_exit:
   option_author("AUTHOR");
   exit(EXIT_SUCCESS);
}


/**
 *
 * ****************************************************************************//**
 * \fn fx_optiont_pfT get_funtionOption(menu_t *pmenu, char * option);
 * \brief Funcion para obtener el puntero a funcion de la Opcion pasada como
 * argumeto \ref option.
 * \param pmenu : Puntero a menu, sobre el cual tenemos definidos las
 * opciones que pueden ser llamadas y sobre la cual vamos a buscar.
 * \param option :  string con la opcion a buscar y sobre la cual obtendremos
 * el puntero a funcion.
 * \return devolveremos el puntero a funcion correspondiente a la opcion pasada
 * como \ref option.
 * 	En caso de devolver un NULL, quiere decir que la opcion no se encontro dentro
 * 	del menu o bien la opcion esta deshabilitada (ya con no tiene definida una
 * 	funcion a ejecutar).
 * \note
 * \warning
 * \par example :
<PRE>
  pfxOption = get_funtionOption(menu_option,arg[i]);
  if(pfxOption == NULL)
  {
	printf("Parametro \"%s\" es incorrecto",arg[i]);
	print_menu(menu_option);
	exit(EXIT_SUCCESS);
  }
</PRE>
 *********************************************************************************/
fx_optiont_pfT get_funtionOption(menu_t *pmenu, char * option)
{
    while(pmenu->opt != NULL)
    {
    	if(strcmp(pmenu->opt,option) == 0)
    	{
    		return pmenu->fxOption;
    	}
    	pmenu++;
    }
    return NULL;
}

/* Consultas sobre el LG */
void proccQuery_lgcheck_0(int row,int col, const char *strFied)
{
	static unsigned char st = 0;
	if(st == 1)
	{
		/* Puerto Configuracin TAS*/
		printf("\t"SET_COLOR(FONT,BLUE)"Puerto Configurado para el LG: "SET_COLOR(FONT,GREEN)"%s\n"\
				SET_COLOR(FONT,RESET),strFied);
		st = 2;
		return;
	}
	if(st == 2)
	{
		/* Puerto Configuracin TAS*/
		printf("\t"SET_COLOR(FONT,BLUE)"PDS Asignado al Equipo: "SET_COLOR(FONT,GREEN)"%s\n"\
				SET_COLOR(FONT,RESET),strFied);
		st = 0;
		return;
	}
	switch(col)
	{
	case 0:/* Numero TAS*/
		printf("\n\t"SET_COLOR(FONT,BLUE)"Nro de TAS: "SET_COLOR(FONT,GREEN)"%s\n"\
				SET_COLOR(FONT,RESET),strFied);
		return;
	case 1:/* POS ID*/
		printf("\t"SET_COLOR(FONT,BLUE)"POS ID: "SET_COLOR(FONT,GREEN)"%s\n"\
				SET_COLOR(FONT,RESET),strFied);
		return;
	case 2:/* N° Serie LG*/
		printf("\t"SET_COLOR(FONT,BLUE)"Nro de Serie LG: "SET_COLOR(FONT,GREEN)"%s\n"\
				SET_COLOR(FONT,RESET),strFied);
		return;
	case 3:/* N° Serie SAM*/
		printf("\t"SET_COLOR(FONT,BLUE)"Nro de Serie SAM: "SET_COLOR(FONT,GREEN)"%s\n"\
				SET_COLOR(FONT,RESET),strFied);
		return;
	case 4:/* N° Pin SAM*/
		printf("\t"SET_COLOR(FONT,BLUE)"PIN de SAM: "SET_COLOR(FONT,GREEN)"%s\n"\
				SET_COLOR(FONT,RESET),strFied);
		st = 1;
		return;
	default:
		PUTS_DEBUG("\n\t"\
				SET_COLOR(FONT,RED)\
				"col Incorrecto.\n"\
				SET_COLOR(FONT,RESET)\
		);
		return;
	}
}



void print_emptly_PDS(const char *stley)
{
	puts(" "SET_COLOR(FONT,RED)\
			"\tSin PDS (Punto de Servicio) Asignado Actualmente"SET_COLOR(FONT,RESET));
}
/*
 'select dispositivos_fisico_id,posid,lgid,samid,sam_pin from config;' | psql qTotem"
 'select puerto_serie_lg from config;' | psql qTotem"
 'select \"puntoservicioid\" from \"DevicesBspa\";' | psql bspa"
 Para esteblecer la cantidad de billetes:
update billetes set cantidad='50' where parametro='2';
update billetes set cantidad='10' where parametro='1';

 */
void printEmptly_listQuery_lgcheck3(const char *pstr)
{
	char buff[32];
	getCurrentDate(buff,sizeof(buff));
	printf("\tNo se reportan transacciones en el LOG del LG SERVER, para la Fecha: "SET_COLOR(FONT,RED)\
				"%s"SET_COLOR(FONT,RESET)"\n",buff);
}
query_sT listQuery_lgcheck[] = {
 /* CONSUTA										 | LEYENDA		| fx que Porcesa campos | fx query vacia */
 {"select dispositivos_fisico_id,posid,lgid,samid,sam_pin from config", "Datos de Configuracion del LG" /* --lg		[0]*/\
   ,proccQuery_lgcheck_0,print_emptly_query}
 ,{"select puerto_serie_lg from config",NULL/*"Puerto Configurado para el LG"*/,\
		 proccQuery_lgcheck_0/*NULL*/,print_emptly_query}		/* --lg	"port" [1]*/
 ,{"select \"puntoservicioid\" from \"DevicesBspa\"",NULL/*"PDS Asignado al Equipo" */,\
		 proccQuery_lgcheck_0/*NULL*/,print_emptly_PDS}  /* --lg		[2]*/
 ,{"select * from \"LogLgServer\" where date >= $1","Log del LG Server",NULL,printEmptly_listQuery_lgcheck3}  		/* --lg	log	[3]*/
};

update_sT listUpdate_lg[] = {
 {"UPDATE config SET puerto_serie_lg='/dev/ttyLG'","Habilitamos el Puerto para el LG"}		 /* --lg	on	[0]*/
 ,{"UPDATE config SET puerto_serie_lg='/dev/ttyLGNO'","Deshabilitamos el Puerto para el LG"} /* --lg	off	[1]*/
};


/*
 * ******************************************************************************
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
int option_lg(char * arg)
{
	static int i;
	/*FILE *output;*/
	static char buff[32];
	const char *paramValues[1];
    if(arg == NULL)
    {
    	i = 0;
    	PUTS_DEBUG("call: --lg\t\t :Sin argumentos, visualizamos los datos del LG");
    	PUTS_DEBUG("\nLlamado \"proccessQuery(\"qTotem\",&listQuery_lgcheck[i])\"");
    	do{
    		/*-- consulta Cero y Uno */
    		PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_lgcheck[i]));
			i++;
    	}while(i<2);
    	/*-- consulta Dos */
    	PRINT_STATUS_QUERY(proccessQuery("bspa",&listQuery_lgcheck[i]));
    	NEW_LINE_BETWEEN_CMD();
    	puts("");
        return 0;
    }
    if(strcmp("on",arg) == 0)
    {
    	PUTS_DEBUG("call: --lg on\t\t :Habilitamos el LG (Base de Datos)");
    	/*-- visualizamos el estado actual del Puerto */
    	PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_lgcheck[1]));
    	/*-- Habilitmamos el Puerto del LG */
    	PRINT_STATUS_QUERY(proccessUpdate("qTotem",&listUpdate_lg[0]));
		/*-- visualizamos el estado actual del Puerto */
		PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_lgcheck[1]));
		NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    if(strcmp("off",arg) == 0)
    {
    	PUTS_DEBUG("call: --lg off\t\t :Deshabilitamos el LG (Base de Datos)");
    	/*-- visualizamos el estado actual del Puerto */
    	PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_lgcheck[1]));
    	/*-- Habilitmamos el Puerto del LG */
    	PRINT_STATUS_QUERY(proccessUpdate("qTotem",&listUpdate_lg[1]));
		/*-- visualizamos el estado actual del Puerto */
		PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_lgcheck[1]));
		NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    if(strcmp("log",arg) == 0)
    {
    	if(getCurrentDate(buff,sizeof(buff))) return 1;
    	/*printf("\n\t\t Fecha Actual es\t: %s",buff); */
    	PUTS_DEBUG("call: --lg log\t\t :Obtenemso el Log del LG server");
    	/*snprintf(buff, sizeof(buff), "%s","2016-08-25"); */
    	paramValues[0] = buff;
    	PRINT_STATUS_QUERY(proccessQueryWhere("bspa",&listQuery_lgcheck[3],paramValues));
    	/* PRINT_STATUS_QUERY(proccessQueryWhere("bspa",&listQuery_lgcheck[3],"2016-08-25"));*/
    	NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    return 1;
}

query_sT listQuery_err_ev[] = {
 /* CONSUTA										 | LEYENDA		| fx que Porcesa campos | fx query vacia */
/* [0] */ {"select * from monitoreo_devices_fuera_servicio", "Errores del Equipo:",print_field_error,print_emptly_error}			/* --error		[0]*/\
/* [1] */,{"select * from monitoreo_devicesevents","Eventos del Equipo:",NULL,print_emptly_error/*print_emptly_event*/}		/* --event      [1]*/
/* [2] */,{"select sum(cantidad) from billetes",NULL/*"Cantidad de Billetes En Stacker"*/\
		 ,print_field_bill,print_emptly_query}					/* --bill       [2]*/
/* [3] */,{"select max_billetes_stacker from config ",NULL/*"Cantidad Maxima de Billetes Establecidos para El Stacker"*/\
		 ,print_field_bill,print_emptly_query}
/* [4] */,{"select totem_habilitado from config","Estado del totem"\
 		 ,print_field_totem,NULL}
};
update_sT listUpdate_err_ev[] = {
  {"delete from monitoreo_devices_fuera_servicio","Borrando la Tabla de Errores"}		/* --error	clean [0]*/
 ,{"delete from monitoreo_devicesevents","Borrando la Tabla de Eventos"} 				/* --event clean [1]*/
};

int option_error(char * arg)
{
	/* usamos una pipe, para leer el comando */
	FILE *output;
	char buffer[32];
	static unsigned int nline=0;
    if(arg == NULL)
    {
    	PUTS_DEBUG("call: --error\t\t :Sin argumentos, visualizamos la tabla de Errores");
    	PUTS_DEBUG("\nLlamado \"proccessQuery(\"qTotem\",&listQuery_err_ev[0])\"");
    	/*-- consulta Cero y Uno */
    	PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_err_ev[0]));
    	NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    if(strcmp("clean",arg) == 0)
    {
    	PUTS_DEBUG("call: --error clean\t\t :Borrando la Tabla de Errores");
    	/*-- Borramos la TAbla de Errores */
    	PRINT_STATUS_QUERY(proccessUpdate("qTotem",&listUpdate_err_ev[0]));
    	NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    if(strcmp("printer",arg) == 0)
    {
    	PUTS_DEBUG("call: --error printer\t\t :Busqueda de Error de la impresora");
    	/*-- usamos una pipe */
#if(defined(REMOTO_CONNECT))
    	output = popen("cat /home/jel/Escritorio/temporal | grep \"ERROR DE CONFIGURACION MONITOREO: OBTENER LA IDENTIFICACION DE LA PRINTER\"", "r");
#else
		output = popen("tail -n10000 /home/c_tallion/qTotem/totem.log | grep \"ERROR DE CONFIGURACION MONITOREO: OBTENER LA IDENTIFICACION DE LA PRINTER\"", "r");/* comando "more", direccionamos*/
#endif
		if(fgets(buffer, sizeof(buffer), output) == NULL)
		{
			puts(SET_COLOR(FONT,GREEN)\
					"\tNo se detecta Error en Impresora"\
					SET_COLOR(FONT,RESET));
		}
		else
		{
			puts(SET_COLOR(FONT,RED)"\tError al Obtner el Printer ID, "\
					SET_COLOR(FONT,RED)"falla en mecanismo o placa logica de la Impresora"\
					SET_COLOR(FONT,RESET));
		}
		NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    if(strcmp("stacker",arg) == 0)
    {
    	PUTS_DEBUG("call: --stacker printer\t\t :Busqueda de Error de la impresora");
    	/*-- usamos una pipe */
#if(defined(REMOTO_CONNECT))
    	output = popen("cat /home/jel/Escritorio/temporal | grep \"STACKER FUERA DE LUGAR\"", "r");
#else
		output = popen("tail -n10000 /home/c_tallion/qTotem/totem.log | grep \"STACKER FUERA DE LUGAR\"", "r");/* comando "more", direccionamos*/
#endif
		nline = 0;
		while(fgets(buffer, sizeof(buffer), output) != NULL) nline ++;
		if(nline > 5)
		{
			puts(SET_COLOR(FONT,RED)"\tSTACKER FUERA DE LUGAR"SET_COLOR(FONT,RESET));

		}
		else
		{
			puts(SET_COLOR(FONT,GREEN)"\tNo se detecta Error con el STACKER"\
					SET_COLOR(FONT,RESET));
		}
		NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    if(strcmp("posid",arg) == 0)
    {
    	PUTS_DEBUG("call: --error posid\t\t :Busqueda de Error de la impresora");
    	/*-- usamos una pipe */
#if(defined(REMOTO_CONNECT))
    	output = popen("cat /home/jel/Escritorio/temporal | grep \"ERROR POS ID\"", "r");
#else
		output = popen("tail -n10000 /home/c_tallion/qTotem/totem.log | grep \"ERROR POS ID\"", "r");
#endif
		/**
		 * */
		if(fgets(buffer, sizeof(buffer), output) != NULL)
		{
			puts(SET_COLOR(FONT,RED)"\tError reportado por LG, POS ID incorrecto f001"SET_COLOR(FONT,RESET));
		}
		else
		{
			puts(SET_COLOR(FONT,GREEN)"\tNo se detecta Error de POS ID"\
					SET_COLOR(FONT,RESET));
		}
		NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    /*-- Opcion pasada es incorrecta */
    PUTS_DEBUG(SET_COLOR(FONT,RED)"Opcion/Argumento pasado es incorrecto\n"SET_COLOR(FONT,RESET));
	return 1;
}


int option_event(char * arg)
{
    if(arg == NULL)
    {
    	PUTS_DEBUG("call: --event\t\t :Sin argumentos, visualizamos la tabla de Eventos");
    	PUTS_DEBUG("\nLlamado \"proccessQuery(\"qTotem\",&listQuery_err_ev[1])\"");
    	/*-- consulta Cero y Uno */
    	PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_err_ev[1]));
    	NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    if(strcmp("clean",arg) == 0)
    {
    	PUTS_DEBUG("call: --event clean\t\t :Borrando la Tabla de Eventos");
    	/*-- Borramos la TAbla de Errores */
    	PRINT_STATUS_QUERY(proccessUpdate("qTotem",&listUpdate_err_ev[1]));
    	NEW_LINE_BETWEEN_CMD();
        return 0;
    }
    /*-- Opcion pasada es incorrecta */
    PUTS_DEBUG(SET_COLOR(FONT,RED)"Opcion/Argumento pasado es incorrecto\n"SET_COLOR(FONT,RESET));
    return 1;
}

/*
su -l postgres -c "echo 'select totem_habilitado from config;'|psql qTotem"

 */
int option_totem(char * arg)
{
    if(arg != NULL) return 1;
    PUTS_DEBUG("call: --status\t :estado de la aplicacion");
    PUTS_DEBUG("\nLlamado \"proccessQuery(\"qTotem\",&listQuery_err_ev[4])\"");
    /*-- consulta Cero y Uno */
    PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_err_ev[4]));
    return 0;


}

int option_bill(char * arg)
{
    if(arg != NULL) return 1;
    PUTS_DEBUG("call: --bill\t\t :Sin argumentos, visualizamos la cantidad de billetes en Stacker");
    PUTS_DEBUG("\nLlamado \"proccessQuery(\"qTotem\",&listQuery_err_ev[0])\"");
    /*
     * 1 - Primero consultamos la cantidad maxima de Billetes Establecida para el Stacker
     * 2 - Segundo consultamos la cantidad de billetes
     * */
    PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_err_ev[3]));
    PRINT_STATUS_QUERY(proccessQuery("qTotem",&listQuery_err_ev[2]));
    NEW_LINE_BETWEEN_CMD();
    return 0;
}





list_error_sT  listErrores[]={
   {"E010009","TAS Habilitada"}
  ,{"E010201","Inconsistencias con el Switch"}
  ,{"E010121","Error de BO (Respuesta del estilo Abakpn...)"}
  ,{"E010120","Error de Time Out de servicion contra BO"}
  ,{"E010006","Logue de Usuario para abrir la cerradura, TRUE si es recaudador."}
  ,{"E010301","Inicio de Apertura Forzada de Cerradura."}
  ,{"E010302","Fin de Apertura Forzada de Cerradura."}
  ,{"E010006","Login de Usuario Recaudador, para abrir CEM, TRUE."}
  ,{"E010101","Estado INICIANDO."}
  ,{"E010102","Estado DESCONECTADO."}
  ,{"E010103","Estado LOGIN."}
  ,{"E010110","Estado IDENTIFICANDO."}
  ,{"E010111","Estado INICIALIZANDO."}
  ,{"E010112","Estado DIFUNDIENDO."}
  ,{"E010113","Estado ABRIENDO TURNO."}
  ,{"E010114","Estado CERRANDO TURNO."}
  ,{"E010115","Estado ENVIANDO TRANSACCIONES."}
  ,{"E010116","Estado SOLICITANDO CREDITO."}
  ,{NULL}
};




const char * get_id_error(list_error_sT *plistError, const char *arg)
{
	int i;
	if(arg == NULL) return NULL;
	i = 0;
	while(plistError->id != NULL)
	{
		if(strcmp(plistError->id,arg) == 0)
		{
			return plistError->brief;
		}
		i++;
		plistError++;
	}
	return (const char *) "Error No Identificado, intente con el Argumento \"--error clean\"";
}

void print_field_error(int r,int c, const char *strQ)
{
	if(c == 1)
	{
		printf("\tNro: "SET_COLOR(FONT,RED)"%s - %s"SET_COLOR(FONT,RESET)"\n"\
				,strQ,get_id_error(listErrores,strQ));
	}

}

void print_emptly_error(const char *strQ)
{
	/*puts(SET_COLOR(FONT,GREEN)": Equipo Sin Errores Reportados"SET_COLOR(FONT,RESET));*/
	/*printf(SET_COLOR(FONT,GREEN)" %s VACIA"SET_COLOR(FONT,RESET),strQ);*/
	puts(SET_COLOR(FONT,GREEN)"VACIA"SET_COLOR(FONT,RESET));
}


void print_field_bill(int r,int c, const char *strQ)
{
	static unsigned char status = 0;
	static unsigned int maxBill,nroBill;
	float tmp;
	if((r != 0)&&(c != 0)) return;
	switch(status)
	{
		default:
		case 0:
			/*
			 * traslate string to integer or float
			 * 	>> int atoi(const char *nptr);
			 * 	>> long atol(const char *nptr);
			 * 	>> long long atoll(const char *nptr);
			 *
			 *	>> double atof(const char *nptr);
			 * 	>> atoi(3), atol(3), strfromd(3), strtod(3), strtol(3), strtoul(3)
			 *
			 *
			 * */
			maxBill = atoi(strQ);
			if(maxBill == 0) maxBill = 900;
			status = 1;
			return;
		case 1:
			nroBill = atoi(strQ);
			status = 0;
			break;
	}


	tmp = (((maxBill - nroBill)*100.0)/maxBill);
	printf(SET_COLOR(FONT,BLUE)"\tBilletes en Stacker: "SET_COLOR(FONT,GREEN)"%d\t"\
			SET_COLOR(FONT,RESET),nroBill);

	printf(SET_COLOR(FONT,BLUE)"\tDisponibilidad del Stacker: "SET_COLOR(FONT,GREEN)"%0.2f [ %c ] "\
			SET_COLOR(FONT,RESET)"\n",tmp,37);

}


void print_field_totem(int r,int c, const char *strQ)
{
	if(strcmp("t",strQ) == 0)
	{
		puts(SET_COLOR(FONT,GREEN)"TOTEM HABILITADO"SET_COLOR(FONT,GREEN)\
					SET_COLOR(FONT,RESET));
	}
	else
	{
		puts(SET_COLOR(FONT,RED)"TOTEM DESHABILITADO"SET_COLOR(FONT,GREEN)\
							SET_COLOR(FONT,RESET));
	}


}



list_usb_brief_sT listBriefUSB[]={
		  {"Impresora",0}
		 ,{"UPS",1}
		 ,{"LG",2}
		 ,{"Placa Distribuidora",3}
		 ,{"Monitor Touch",4}
		 ,{NULL}
};

list_usb_brief_sT listBriefUSBview[]={
		  {"Impresora \"Coustom TG2460\"",0}
		 ,{"UPS \"Lyonn CTB-800A\"",1}
		 ,{"LG, modelo \"Integresys\"",2}
		 ,{"LG, modelo \"Abakon\"",3}
		 ,{"\"Placa Distribuidora\"",4}
		 ,{"Monitor Tactil, modelo \"Avdo Atouch 190\"",5}
		 ,{"Monitor Tactil, modelo \"NUEVO etapa 1\"",6}
		 ,{NULL}
};

list_usb_sT listIdEnUSB[]={
		  {"0dd4:01a7"/*,"Impresora \"Coustom TG2460\""*/,0}
		 ,{"0665:5161"/*,"UPS \"Lyonn CTB-800A\""*/,1}
		 ,{"10c4:8855"/*,"LG, modelo \"Integresys\""*/,2}
		 ,{"10c4:ea60"/*,"LG, modelo \"Abakon\""*/,2}
		 ,{"04d8:000a"/*,"\"Placa Distribuidora\""*/,3}
		 ,{"24b8:0001"/*,"Monitor Tactil, modelo \"Avdo Atouch 190\""*/,4}
		 ,{"14e1:6000"/*,"Monitor Tactil, modelo \"NUEVO etapa 1\""*/,4}
		 ,{NULL}
};
list_usb_sT listIdEnUSBview[]={
		  {"0dd4:01a7"/*,"Impresora \"Coustom TG2460\""*/,0}
		 ,{"0665:5161"/*,"UPS \"Lyonn CTB-800A\""*/,1}
		 ,{"10c4:8855"/*,"LG, modelo \"Integresys\""*/,2}
		 ,{"10c4:ea60"/*,"LG, modelo \"Abakon\""*/,3}
		 ,{"04d8:000a"/*,"\"Placa Distribuidora\""*/,4}
		 ,{"24b8:0001"/*,"Monitor Tactil, modelo \"Avdo Atouch 190\""*/,5}
		 ,{"14e1:6000"/*,"Monitor Tactil, modelo \"NUEVO etapa 1\""*/,6}
		 ,{NULL}
};



void check_usb_brief(unsigned int st,list_usb_brief_sT *plistUSB)
{
	unsigned int tmp;

	while(plistUSB->brief != NULL)
	{
		tmp = 0x01 << plistUSB->en;
		if(st & tmp)
		{
			printf(SET_COLOR(FONT,BLUE)"\tDISPOSITIVO: "\
					SET_COLOR(FONT,GREEN)"%s, CONECTADO"\
					SET_COLOR(FONT,RESET)"\n"\
					,plistUSB->brief);
		}
		else
		{
			printf(SET_COLOR(FONT,BLUE)"\tDISPOSITIVO: "\
					SET_COLOR(FONT,RED)"%s, NO CONECTADO"\
					SET_COLOR(FONT,RESET)"\n"\
					,plistUSB->brief);
		}
		plistUSB++;
	}
}

int get_status_usb(list_usb_sT *plistUSB, char *arg)
{
	/*int i;*/
	if(arg == NULL) return 0;
	/*i = 0;*/
	while(plistUSB->id != NULL)
	{
		if(strcmp(plistUSB->id,arg) == 0)
		{
			/*return i;*/
			return plistUSB->en;
		}
		/*i++;*/
		plistUSB++;
	}
	return -1;
}

/*
 * ******************************************************************************
 * \fn int option_usb(char * arg   );
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
int option_usb(char * arg)
{
	/* usamos una pipe, para leer el comando */
	FILE *output;
	char buffer[16];
	static unsigned int status;
	int tmp;
	do{
		if(arg == NULL)
		{
			PUTS_DEBUG("call: --usb\t\t :Realizamos el check de los dispositivos USB necesarios.");
			output = popen("lsusb | cut -d \" \" -f 6", "r");/* comando "lsusb", direccionamos*/
			if( output == NULL)
			{
				PUTS_DEBUG("Error no se puede abrir el proceso mediante pipe");
				return 1;
			}
			status = 0;
			while (fgets(buffer, 10, output) != NULL)
			{
				tmp = get_status_usb(/*listDeviceUSB*/listIdEnUSB,buffer);
				if(tmp >= 0)
				{
					status |= (0x01 << tmp);
				}
			}
			/* FIXME cambiar esta funcion
			 * */
			check_usb_brief(status,listBriefUSB);
			break;
		}
		if(strcmp("view",arg) == 0)
		{
			PUTS_DEBUG("call: --usb view\t\t :Realizamos el check de los dispositivos USB necesarios.");
			output = popen("lsusb | cut -d \" \" -f 6", "r");/* comando "lsusb", direccionamos*/
			if( output == NULL)
			{
				PUTS_DEBUG("Error no se puede abrir el proceso mediante pipe");
				return 1;
			}
			status = 0;
			while (fgets(buffer, 10, output) != NULL)
			{
				tmp = get_status_usb(/*listDeviceUSB*/listIdEnUSBview,buffer);
				if(tmp >= 0)
				{
					status |= (0x01 << tmp);
				}
			}

			check_usb_brief(status,listBriefUSBview);
			break;
		}
		return 1;
	}while(0);
	puts("");
	PCLOSE(output);
	NEW_LINE_BETWEEN_CMD();
	return 0;

}

int option_ups(char * arg)
{
	/* usamos una pipe, para leer el comando */
	FILE *output;
	char buffer[32];

	if(arg != NULL) return 1;
	/**/
	PUTS_DEBUG("call: --ups\t\t :Realizamos el check de la UPS.");
	/*
	 * */
	/* output = popen("upsc apc | grep -e\"driver.version:\" -e\"battery.voltage\" -e\"battery.charge\" -e\"input.voltage\" -e\"output.current\"", "r"); */
#if(defined(REMOTO_CONNECT))
	output = popen("cat /home/jel/Escritorio/temporal | grep -e\"battery.voltage:\" -e\"input.voltage:\" -e\"output.current.nominal:\"", "r");
#else
	output = popen("upsc apc | grep -e\"battery.voltage:\" -e\"input.voltage:\" -e\"output.current\"", "r");/* comando "more", direccionamos*/
#endif
	if( output == NULL)
	{
		puts("Error");
		PUTS_DEBUG("Error no se puede abrir el proceso mediante pipe");
		return 1;
	}
	while (fgets(buffer, sizeof(buffer), output) != NULL)
	{
		printf(SET_COLOR(FONT,BLUE)"%s"SET_COLOR(FONT,RESET), buffer);
	}
	PCLOSE(output);
	return 0;
}




int option_help(char * arg)
{
	if(arg != NULL) return 1;
	/*-- definimos un puntero y lo inicializamos */
	menu_t *pmenu = menu_option;
	HEAD_help(ptrNmbCmd);
    while(pmenu->opt != NULL)
    {
    	printf("OPCION : "SET_COLOR(FONT,BLUE)"\"%s\""\
    			SET_COLOR(FONT,RESET),pmenu->opt);

    	printf("\nUso y Argumentos:\n"SET_COLOR(FONT,GREEN)"%s\n"\
    				SET_COLOR(FONT,RESET),pmenu->leyend);
        pmenu++;
    }
    TAIL_help(ptrNmbCmd);
	return 0;
}

int option_version(char *arg)
{
	if(arg != NULL) return 1;
	PRINTF_DEBUG("Comando : "SET_COLOR(FONT,BLUE)"%s\n"\
	    			,OPTION(version));
	puts("\t"SET_COLOR(FONT,GREEN)"Version de la aplicacion "VERSION_STRING()\
			SET_COLOR(FONT,RESET));
	return 0;
}

int option_author(char *arg)
{
	if(arg != NULL)
	{
		if(strcmp("AUTHOR",arg) == 0)
		{
			printf(SET_COLOR(FONT,CYAN)"\n\n%s\n"\
						SET_COLOR(FONT,RESET),AUTHOR_STRINGbrief());
			return 0;
		}
		else return 1;
	}
	PRINTF_DEBUG("Comando : "SET_COLOR(FONT,BLUE)"%s\n"\
	    			,OPTION(author));
	puts("\t"SET_COLOR(FONT,GREEN)"Autor de la Aplicacion: "AUTHOR_STRING()\
			SET_COLOR(FONT,RESET));
return 0;
}



void print_field_query(int r,int c, const char *strQ)
{
	printf("\tFila: %d\tColumna: %d\tCampo: %s\t",r,c,strQ);
}

void print_emptly_query(const char *stley)
{
	printf("\tConsulta: "SET_COLOR(FONT,RED)\
			"%s"SET_COLOR(FONT,RESET)"  VACIA\n",stley);
}



int proccessQuery(const char *dbName, query_sT *pListQuery)
{
	PGconn *conn; /* para la conexion con la base de datos*/
	PGresult *res;/* para almacenar el objeto resultado de la query */
	int rows, i;
	int ncols,j;
	char connInfo[128]= CONN_INFO();

	if(dbName == NULL )
	{
		PUTS_DEBUG("String connInfo Nulo");
		return 1;
	}
	if(pListQuery == NULL )
	{
		PUTS_DEBUG("Lista de consulta pListQuery Nulo");
		return 1;
	}
	strcat(connInfo,dbName);
	/* Make a connection to the database */
	conn = PQconnectdb(connInfo);
	/* Verifique que la conexión de backend se haya realizado correctamente */
	if (PQstatus(conn) != CONNECTION_OK)
	{
		fprintf(stderr, "Connection to database failed: %s",
				PQerrorMessage(conn));
		PQfinish(conn);
		return 1;
	}
	/*-- preparamos para hacer las consulta sobre */
	if(pListQuery->query != NULL)
	{
		/* Establezca una ruta de búsqueda siempre segura, para que los
		 * usuarios malintencionados no puedan tomar el control. */

		if(pListQuery->leyenda != NULL ) /* Si la leyenda es distinta de NULL, imprimimos la misma */
		{
			printf(SET_COLOR(FONT,BLUE)"\t%s\t"SET_COLOR(FONT,RESET)\
				,pListQuery->leyenda);
		}
		res = PQexec(conn,pListQuery->query);
		if (PQresultStatus(res) != PGRES_TUPLES_OK)
		{
			fprintf(stderr, "SET failed: %s", PQerrorMessage(conn));
			PQclear(res);
			PQfinish(conn);
			return 1;
		}
		/*-- obtemos el numero de Filas, del resultado de la consulta */
		rows = PQntuples(res);
		ncols = PQnfields(res);
		if(rows == 0)
		{
			if((pListQuery->emptlyQuery != NULL))
			{
				if((pListQuery->leyenda != NULL))
				{
					(pListQuery->emptlyQuery)(pListQuery->leyenda);
				}
				else
					(pListQuery->emptlyQuery)(NULL);
			}
		}
		if((rows >= 1)&&(ncols < 1))
		{
			puts("");
		}
		for(i=0; i<rows; i++)
		{
			/* PQgetvalue(resultQuery, nroFila, nroColumna) */
			for(j=0;j<ncols;j++)
			{
				if(pListQuery->proccessQuery == NULL)
				{
					printf("\t%s",PQgetvalue(res, i, j));
				}
				else
				{
					(pListQuery->proccessQuery)(i,j,PQgetvalue(res, i, j));
				}
			}
			if(pListQuery->proccessQuery == NULL) puts("");
		}
	}
	/*
	 * Debe siempre hacer un  PQclear sobre PGresult siempre que ya no sea necesario
	 * para evitar pérdidas de memoria
	 */
	/*-- es aconsejable limpiar antes de salir */
	PQclear(res);
	PQfinish(conn);
	return 0;
}

int proccessUpdate(const char *dbName, update_sT *pListUpdate)
{
	PGconn *conn; /* para la conexion con la base de datos*/
	PGresult *res;/* para almacenar el objeto resultado de la query */
	char connInfo[128]= CONN_INFO();

	if(dbName == NULL )
	{
		PUTS_DEBUG("String connInfo Nulo");
		return 1;
	}
	if(pListUpdate == NULL )
	{
		PUTS_DEBUG("Lista de consulta pListQuery Nulo");
		return 1;
	}
	/*-- armamos el string para establecer la conexion*/
	strcat(connInfo,dbName);
	/* Make a connection to the database */
	conn = PQconnectdb(connInfo);
	/* Verifique que la conexión de backend se haya realizado correctamente */
	if (PQstatus(conn) != CONNECTION_OK)
	{
		fprintf(stderr, "Connection to database failed: %s",
				PQerrorMessage(conn));
		PQfinish(conn);
		return 1;
	}
	/*-- preparamos para haer las actualizacion */
	if(pListUpdate->update != NULL)
	{
		/* Indicamos el Inicio de un Bloque de Actualizacion */
		res = PQexec(conn,"BEGIN");
		if (PQresultStatus(res) != PGRES_COMMAND_OK)
		{
			fprintf(stderr, "BEGIN BLOCK failed: %s", PQerrorMessage(conn));
			PQclear(res);
			PQfinish(conn);
			return 1;
		}
		PQclear(res);
		/*-- Realizamos la Actualizacion del campo especificado */
		if(pListUpdate->leyenda != NULL)/* Imprimimos la leyenda, si esta no es null */
		{
			printf(SET_COLOR(FONT,BLUE)"\t%s\t"SET_COLOR(FONT,RESET)\
				,pListUpdate->leyenda);
		}
		res = PQexec(conn,pListUpdate->update);
		if (PQresultStatus(res) != PGRES_COMMAND_OK)
		{
			fprintf(stderr, "UPDATE/INSERT failed: %s", PQerrorMessage(conn));
			PQclear(res);
			PQfinish(conn);
			return 1;
		}
		puts("");
		/* Realizamos el commit del blocke de actualizacion */
		res = PQexec(conn, "COMMIT");
		if (PQresultStatus(res) != PGRES_COMMAND_OK)
		{
			fprintf(stderr, "COMMIT BLOCK failed: %s", PQerrorMessage(conn));
			PQclear(res);
			PQfinish(conn);
			return 1;
		}
	}
	/*
	 * Debe siempre hacer un  PQclear sobre PGresult siempre que ya no sea necesario
	 * para evitar pérdidas de memoria
	 */
	PQclear(res);
	PQfinish(conn);
	return 0;
}


int proccessQueryWhere(const char *dbName, query_sT *pListQuery, const char * const *strWhere)
{
	PGconn *conn; /* para la conexion con la base de datos*/
	PGresult *res;/* para almacenar el objeto resultado de la query */
	int rows, i;
	int ncols,j;
	char connInfo[128]= CONN_INFO();

	if(dbName == NULL )
	{
		PUTS_DEBUG("String connInfo Nulo");
		return 1;
	}
	if(pListQuery == NULL )
	{
		PUTS_DEBUG("Lista de consulta pListQuery Nulo");
		return 1;
	}
	strcat(connInfo,dbName);
	/* Make a connection to the database */
	conn = PQconnectdb(connInfo);
	/* Verifique que la conexión de backend se haya realizado correctamente */
	if (PQstatus(conn) != CONNECTION_OK)
	{
		fprintf(stderr, "Connection to database failed: %s",
				PQerrorMessage(conn));
		PQfinish(conn);
		return 1;
	}
	/*-- preparamos para hacer las consulta sobre */
	if(pListQuery->query != NULL)
	{
		/* Establezca una ruta de búsqueda siempre segura, para que los
		 * usuarios malintencionados no puedan tomar el control. */
		if(pListQuery->leyenda != NULL) /* Imprimimos la leyenda, si la misma no es null */
		{
			printf(SET_COLOR(FONT,CYAN)"\t%s\t"SET_COLOR(FONT,RESET)\
				,pListQuery->leyenda);
		}
		/*res = PQexec(conn,pListQuery->query);*/
		res = PQexecParams(conn, pListQuery->query
				, 1 /* N° de parametros a actualizar en la query */
				, NULL /* Tipos de Parametros, todos los paremetros '1' del mismo tipo */
				, strWhere /* Valor actual del Parametro, un string pra este caso */
		        , NULL /* Longitud del parametro Binario, NULL para uso de String*/
				, NULL /* Formato del Parametro, NULL para String  */
				, 0    /* Formato del Resultado , '0' resultado en formato String */
				);
		if (PQresultStatus(res) != PGRES_TUPLES_OK)
		{
			fprintf(stderr, "SELECT with WHERE failed: %s", PQerrorMessage(conn));
			PQclear(res);
			PQfinish(conn);
			return 1;
		}
		/*-- obtnemos el numero de Filas, del resultado de la consulta */
		rows = PQntuples(res);
		ncols = PQnfields(res);
		if(rows == 0)
		{
			if((pListQuery->emptlyQuery != NULL))
			{
				if((pListQuery->leyenda != NULL))
				{
					(pListQuery->emptlyQuery)(pListQuery->leyenda);
					/*(pListQuery->emptlyQuery)(pListQuery->query);*/
				}
				else
					(pListQuery->emptlyQuery)(NULL);
			}
		}
		if((rows !=1)&&(ncols !=1))
		{
			puts("");
		}
		for(i=0; i<rows; i++)
		{
			/* PQgetvalue(resultQuery, nroFila, nroColumna) */

			for(j=0;j<ncols;j++)
			{
				if(pListQuery->proccessQuery == NULL)
				{
					printf("\t%s",PQgetvalue(res, i, j));
				}
				else
				{
					(pListQuery->proccessQuery)(i,j,PQgetvalue(res, i, j));
				}
			}
			if(pListQuery->proccessQuery == NULL) puts("");
		}
	}
	/*
	 * Debe siempre hacer un  PQclear sobre PGresult siempre que ya no sea necesario
	 * para evitar pérdidas de memoria
	 */
	/*-- es aconsejable limpiar antes de salir */
	PQclear(res);
	PQfinish(conn);
	return 0;
}

unsigned char getCurrentDate(char *pbuff, size_t len)
{
	 FILE * file2pipe;
	 if(pbuff == NULL) return 1;
	 file2pipe = popen("date +\"%Y-%m-%d\"", "r");/* comando "more", direccionamos*/
	 if( file2pipe == NULL)
	 {
		 PUTS_DEBUG(SET_COLOR(FONT,RED)\
				 "Error \"getCurrentDate()\" no se puede abrir el proceso mediante pipe"\
				 SET_COLOR(FONT,RESET));
		 PCLOSE(file2pipe);
		 return 1;
	 }
	 fgets(pbuff, len, file2pipe);
	 PCLOSE(file2pipe);
	 return 0;
}



/*
┌────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                    │  
│                                                                                    │  
│ ─────────────────────────[ End apis main version 8      ]────────────────────────  │
│                                                                                    │
│                                                                                    │             
└────────────────────────────────────────────────────────────────────────────────────┘
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
 *
 * *******************************************************************
 * @brief funcion principal 
 * @param argn numeros de Arguemtnos por defecto es '1' 
 * @param arg array de arguemento, arg[0] := path/appname
 * @return estado de la ejecucion
 *  + EXIT_SUCCESS : ejecucion finalizada de forma exitosa
 *  + EXIT_FAIL : ejecucion finalizada con error 
 * 
 *********************************************************************/
int main(int argn,char **arg)
{       
    exit(EXIT_SUCCESS);    
}
/*
┌────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                    │  
│                                                                                    │  
│ ─────────────────────────[ End apis main version 9      ]────────────────────────  │
│                                                                                    │
│                                                                                    │             
└────────────────────────────────────────────────────────────────────────────────────┘
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
 *
 * *******************************************************************
 * @brief funcion principal 
 * @param argn numeros de Arguemtnos por defecto es '1' 
 * @param arg array de arguemento, arg[0] := path/appname
 * @return estado de la ejecucion
 *  + EXIT_SUCCESS : ejecucion finalizada de forma exitosa
 *  + EXIT_FAIL : ejecucion finalizada con error 
 * 
 *********************************************************************/
int main(int argn,char **arg)
{       
    exit(EXIT_SUCCESS);    
}
/*
┌────────────────────────────────────────────────────────────────────────────────────┐           
│                                                                                    │  
│                                                                                    │  
│ ─────────────────────────[ End apis main version 10     ]────────────────────────  │
│                                                                                    │
│                                                                                    │             
└────────────────────────────────────────────────────────────────────────────────────┘
*/

#elif (__main_version__ == 11)


#warning "Version no definida aun"
#else /* #if (__main_version__ == 1) */
#warning "__main_version__ mal definido"
#endif /* #if (__main_version__ == 1) */
/*
 * 
 * *********************************************************************************************
 *
 * ===========================[ End main Definition ]============================
 *
 * ********************************************************************************************
 * 
 */

/* 
 * 
 * *********************************************************************************************
 *
 * ===========================[ Begin APIs Declaration ]============================
 *
 * ******************************************************************************************** 
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
* *******************************************************************
* @brief descripcion breve
* @param arg1: descripcion breve arg 1 
* should be 
* @param arg2: array de arguemento
* should be 
* @return 
*  
* @note
*********************************************************************/
void keyboard_getline(const char * format, ...)
{
    va_list arp;
    va_start(arp, format);
    fflush(stdin);
    fflush(stdout);
    /*-- flags para vscanf CCFLAGS = -Wall -m64 -Iinclude */
    vscanf(format,arp);
    getchar();
    va_end(arp);
}
/*
*
* *******************************************************************
* @brief descripcion breve
* @param arg1: descripcion breve arg 1 
* should be 
* @param arg2: array de arguemento
* should be 
* @return 
*  
* @note
*********************************************************************/
void console_printf(const char * format, ... )
{
    va_list arp;
    va_start(arp, format);
    vprintf(format,arp);
    fflush(stdout);
    va_end(arp);     
}

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
 * ===========================[ End APIs Definitions ]============================
 *
 * ******************************************************************************************** 
 * 
 * 
 */
