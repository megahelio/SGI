#include "glut.h"
#include <stdio.h>
#include "cuadrado.h"

/******************************************************************/
/* Funcion de dibujado                                            */
/* Parametros: Ninguno                                            */
/* Salida: Ninguna                                                */
/******************************************************************/
void Dibuja(void)
{
	int i;
	float dec, des;
	/* Establece el color de borrado */
	glClearColor(1.0f, 0.0f, 0.0f, 0.0f);

	/* Borra el buffer de color */
	glClear(GL_COLOR_BUFFER_BIT);


	/* Crea un poligono 2D (cuadrado) */
	/*glBegin(GL_POLYGON);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(-0.5f, 0.5f);
	glVertex2f(0.5f, 0.5f);
	glVertex2f(0.5f, -0.5f);
	glEnd();

	glColor3f(0.0f, 0.0f, 1.0f);

	glBegin(GL_POLYGON);
	glVertex2f(0.0f, -0.5f);
	glVertex2f(-0.5f, 0.0f);
	glVertex2f(0.0f, 0.5f);
	glVertex2f(0.5f, -0.0f);
	glEnd();*/

	//centro
	//glBegin(GL_POLYGON);
	//glColor3f(1.0f, 1.0f, 1.0f);
	//glVertex2f(-0.5f, -0.5f);
	//glColor3f(1.0f, 1.0f, 0.0f);
	//glVertex2f(-0.5f, 0.5f);
	//glColor3f(1.0f, 1.0f, 0.0f);
	//glVertex2f(0.5f, 0.5f);
	//glColor3f(0.0f, 0.0f, 0.0f);
	//glVertex2f(0.5f, -0.5f);
	//glEnd();

	////esquina abajo izq
	//glColor3f(0.0f, 1.0f, 0.0f);
	//glBegin(GL_POLYGON);
	//glVertex2f(0.0f, -0.5f);
	//glVertex2f(-0.5f, 0.0f);
	//glVertex2f(-0.5f, -0.5f);
	//glEnd();

	////arriba izquierda
	//glColor3f(0.0f, 0.0f, 0.0f);
	//glBegin(GL_POLYGON);
	//glVertex2f(-0.5f, 0.0f);
	//glVertex2f(-0.5f, 0.5f);
	//glVertex2f(0.0f, 0.5f);
	//glEnd();

	////arriba der
	//glColor3f(1.0f, 1.0f, 0.0f);
	//glBegin(GL_POLYGON);
	//glVertex2f(0.5f, 0.0f);
	//glVertex2f(0.0f, 0.5f);
	//glVertex2f(0.5f, 0.5f);
	//glEnd();

	////
	//glColor3f(1.0f, 1.0f, 1.0f);
	//glBegin(GL_POLYGON);
	//glVertex2f(0.0f, -0.5f);
	//glVertex2f(0.5f, 0.0f);
	//glVertex2f(0.5f, -0.5f);
	//glEnd();


	/* Crea un poligono 2D (cuadrado) */
    dec = 0.1f;
	des = 0.0f;
	for (i = 0; i < 5; i++) {
		if(i%2){
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else {
			glColor3f(0.0f, 0.0f, 0.0f);
		}

		glBegin(GL_POLYGON);
		glVertex2f(-0.5f - des, -0.5f - des);
		glVertex2f(-0.5f - des, 0.5f - dec - des);
		glVertex2f(0.5f - des - dec, 0.5f - des - dec);
		glVertex2f(0.5f - des - dec, -0.5f - des);
		glEnd();
		dec += 0.2f;
		des += 0.1f;
	}



	/* Se asegura de que se ejecutan todas las ordenes */
	glFlush();
}


/******************************************************************************************/
/* Establece el area visible                                                              */
/* Parametros: int ancho --> Ancho del area visible                                       */
/*             int alto --> Alto del area visible                                         */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void TamanyoVentana(int ancho, int alto)
{
	glViewport(0, 0, ancho, alto);
}


/******************************************************************************************/
/* Inicia las propiedades de la vista                                                     */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaVista(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}


/******************************************************************************************/
/* Abre una ventana OpenGL                                                                */
/* Parametros: int numeroArgumentos --> El numero de argumentos en la llamada al programa */
/*             char ** listaArgumentos --> Vector de cadenas con cada argumento           */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void AbreVentana(int numeroArgumentos, char** listaArgumentos)
{
	glutInit(&numeroArgumentos, listaArgumentos);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(listaArgumentos[0]);
	glutDisplayFunc(Dibuja);
	glutReshapeFunc(TamanyoVentana);
	IniciaVista();
}


/******************************************************************************************/
/* Funcion principal                                                                      */
/* Parametros: int numeroArgumentos --> El numero de argumentos en la llamada al programa */
/*             char ** listaArgumentos --> Vector de cadenas con cada argumento           */
/* Salida: Un entero que se devuelve al sistema al acabar la ejecucion del programa       */
/******************************************************************************************/
int main(int numArgumentos, char** listaArgumentos)
{
	/* Crea la ventana de la aplicaci¢n */
	AbreVentana(numArgumentos, listaArgumentos);

	/* Establece el bucle principal de control de OpenGL */
	glutMainLoop();

	return (0);
}

