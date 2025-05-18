/*************************************************************************/
/*                                                                       */
/*   luces.c		                                                     */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/

#include "glut.h"


/********************** RUTINA DE INICIO *************************/
/******************************************************************************************/
/* Inicia los parametros de iluminacion de OpenGL                                         */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaLuces(void)
{	
	GLfloat lmodel_ambient [] = {0.4f, 0.4f, 0.4f, 1.0f};

	/* Par�metros del modelo de iluminaci�n */

	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	
	/* Activa la iluminaci�n de la escena */

	glEnable(GL_LIGHTING);	
	glEnable(GL_NORMALIZE);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_FOG);

}


/*********************** DEFINICION DE LUCES ****************************/

/******************************************************************************************/
/* Define y activa la luz 0                                                               */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Luz0 (void)
{
	float luz0_posicion[] = {0.0f, 1.0f, 1.0f, 0.0f};
	float luz0_ambiente[] = {0.2f, 0.2f, 0.2f, 1.0f};
	float luz0_difusa[] = {0.5f, 0.5f, 0.5f, 1.0f};
	float luz0_especular[] = {0.6f, 0.6f, 0.6f, 1.0f};

	glLightfv (GL_LIGHT0, GL_POSITION, luz0_posicion);
	glLightfv (GL_LIGHT0, GL_AMBIENT, luz0_ambiente);
	glLightfv (GL_LIGHT0, GL_DIFFUSE, luz0_difusa);
	glLightfv (GL_LIGHT0, GL_SPECULAR, luz0_especular);
	glEnable(GL_LIGHT0);
	
}

/******************************************************************************************/
/* Define y activa la luz 1                                                               */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Luz1 (void)
{
	float luz1_posicion[] = { 0.0f, 2.0f, 0.0f, 1.0f };
	float luz1_ambiente[] = { 0.2f, 0.4f, 0.2f, 1.0f };
	float luz1_difusa[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	float luz1_especular[] = { 0.6f, 0.6f, 0.6f, 1.0f };

	glLightfv(GL_LIGHT1, GL_POSITION, luz1_posicion);
	glLightfv(GL_LIGHT1, GL_AMBIENT, luz1_ambiente);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, luz1_difusa);
	glLightfv(GL_LIGHT1, GL_SPECULAR, luz1_especular);
	//glEnable(GL_LIGHT1);
}

/******************************************************************************************/
/* Define y activa la luz 2                                                               */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Luz2 (void)
{
	float luz2_posicion[] = { 0.0f, 2.0f, 0.0f, 1.0f };
	float luz2_ambiente[] = { 0.2f, 0.4f, 0.2f, 1.0f };
	float luz2_difusa[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	float luz2_especular[] = { 0.6f, 0.6f, 0.6f, 1.0f };

	glLightfv(GL_LIGHT1, GL_POSITION, luz2_posicion);
	glLightfv(GL_LIGHT1, GL_AMBIENT, luz2_ambiente);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, luz2_difusa);
	glLightfv(GL_LIGHT1, GL_SPECULAR, luz2_especular);
	glEnable(GL_LIGHT2);
}

/******************************************************************************************/
/* Define y activa la niebla                                                              */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Niebla (void)
{
	GLfloat color_de_niebla[4] = { 1.0f, 1.0f, 1.0f, 0.5f };
	
	glFogi(GL_FOG_MODE, GL_EXP);
	
	
	glFogf(GL_FOG_DENSITY, 0.05);  // No necesario para GL_LINEAR
	glFogf(GL_FOG_START, 1.0f);
	glFogf(GL_FOG_END, 10.0f);

	glFogfv(GL_FOG_COLOR, color_de_niebla);

	glEnable(GL_FOG);
	
}
