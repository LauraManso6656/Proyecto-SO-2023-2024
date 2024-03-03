#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
	
	// conector para acceder al servidor de base de datos
	MYSQL *conn;
	int err;
	
	MYSQL_RES *resultado;
	MYSQL_ROW row;
	int cont;
	char jugador [10];
	char consulta [80];
	
	//Creamos conexi�n al servidor MYSQL
	conn=mysql_init(NULL);
	if(conn==NULL){
		printf("Error al crear la conexi�n:%u%s\n", mysql_errno(conn), mysql_error(conn));
		exit(1);
		
	}
	//inicializar conexi�n, indicando las claves de acceso
	conn=mysql_real_connect(conn, "localhost", "usuario", "pass", BaseDatos, 0, NULL,0);
	if(conn==NULL)
	{
		printf("Error al inicializar conexxi�n:%u%s\n", mysql_errno(conn),mysql_error(conn));
		exit(1);
	}
	
	resultado=mysql_store_result(conn);
	
	//buscamos el jugador con mas puntos
	
	err= mysql_query(conn, "SELECT * FROM jugadores");
	if (err!=0){
		printf("Error al consultar datos de la base %u %s \n",
			   mysql_errno(conn), mysql_error(conn));
		exit (1);
		
	}
	resultado=mysql_store_result(conn);
	
	
	printf("Dame el nombre del ganador\n");
	scanf("%s", jugador);
	strcpy(consulta, "SELECT jugadores.usuario FROM jugadores, partidas, participaciones WHERE participaciones.puntos=(SELECT MAX(participaciones.puntos) FROM participaciones) AND jugadores.id=participaciones.idJ");
	// hacer consulta
	err=mysql_query(conn, consulta);
	if (err!=0) {
		printf ("Error al consultar datos de la base %u %s\n",
				mysql_errno(conn), mysql_error(conn));
		exit (1);
	}
	//recoger resultado consulta
	resultado = mysql_store_result (conn); 
	row = mysql_fetch_row (resultado);
	if (row == NULL){
		printf ("No se han obtenido datos en la consulta\n");
	}
	else{
		// El resultado debe ser una matriz con una sola fila
		// y una columna que contiene el nombre
		printf("El ganador es: %d\n", row [0]);
		
	}
	// cerrar la conexion con el servidor MYSQL 
	mysql_close (conn);
	exit(0);
	
	
	

}

