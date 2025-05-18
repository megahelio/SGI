/*************************************************************************/
/*                                                                       */
/*   modelado.c                                                          */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/

#include "glut.h"
#include "glig.h"
#include "material.h"
#include "modelado.h"

/********************* ESCENA ILUMINACION ****************/

/******************************************************************************************/
/* Define un arco de la escena                                                            */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void ArcoSolid (void)
{
	glPushMatrix();
		glTranslatef(0.75,0.0,0.0);
		glScalef(0.2,1.0,0.2);
		igSolidRulo(10,5);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(-0.75,0.0,0.0);
		glScalef(0.2,1.0,0.2);
		igSolidRulo(10,5);
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0,1.0,0.0);
		glRotatef(90,0.0,0.0,1.0);
		glScalef(0.05,2.3,0.5);
		igSolidCube();
	glPopMatrix();
	glPushMatrix();
		glTranslatef(0.0,-0.98,0.0);
		glRotatef(90,0.0,0.0,1.0);
		glScalef(0.05,2.3,0.5);
		igSolidCube();
	glPopMatrix();
}

/******************************************************************************************/
/* Define los arcos de la escena                                                          */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void ArcosSolid (void)
{
	int i;

	glScalef(0.9,0.9,0.9);
	for(i=0;i<12;i++){
		glPushMatrix();
			glRotatef(i*360/12,0.0,1.0,0.0);
			glTranslatef(0.0,0.0,-2.0);
			glScalef(0.5,0.5,0.5);
			ArcoSolid();
		glPopMatrix();
	}
}

/******************************************************************************************/
/* Define el suelo de la escena                                                           */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void SueloSolid(void)
{
    glPushMatrix();
		glTranslatef(0.0,-0.5,0.0);
		glRotatef(360/48.0,0.0,1.0,0.0);
		glScalef(2.1,0.005,2.1);
		igSolidSemiSphere(10,50);
    glPopMatrix();
}

/******************************************************************************************/
/* Crea la display list para la escena                                                    */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void CreaEscenaIluminacion(void)
{
	escena = glGenLists (1);

	if (escena != 0)
	{
		glNewList (escena, GL_COMPILE);
		glPushMatrix();
			Cobre();
			//glColor3f(0.5, 0.5, 0.25);
			ArcosSolid();
			glColor3f(0.25,0.5,0.5);
			SueloSolid();
			//glColor3f (0.5f, 0.11f, 0.0f);
			glColor3f (0.0f, 0.0f, 1.0f);
			glScalef(0.5,0.5,0.5);	
			igSolidSphere(20,10);
		glPopMatrix();
		glEndList ();
	}
}