/*************************************************************************/
/*                                                                       */
/*                 glig.c LIBRERIA DE MODELADO GEOMETRICO	             */
/*                                                                       */
/*   Rev. 3.0  01/09/2012   Universidad Jaume I de Castellón             */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/
#include "glut.h"
#include <math.h>
#include <stdio.h>
#include "glig.h"

#define PI 3.1415926535897932
#define ALFA (0.5-v)*PI
#define BETA 2*PI*u

/************************* FUNCIONES BASICAS **********************************************/
/******************************************************************************************/
/* Devuelve la coordenada x de un punto en R3 a partir de un punto (u,v)                  */
/*   de un espacio parametrico en R2                                                      */
/* Parametros: float u --> Primera coordenada de un punto en R2                           */
/*             float v --> Segunda coordenada de un punto en R2                           */
/*             float R --> Radio de la esfera envolvente                                  */
/*             float s1 --> Numero de divisiones en u                                     */
/*             float s2 --> Numero de divisiones en v                                     */
/* Salida: La coordenada x de un punto en R3                                              */
/******************************************************************************************/
float xSuperQuadric (float u, float v, float R, float s1, float s2)
{
	float cosalfa, cosbeta, powcosalfa, powcosbeta;

	cosalfa = (float)cos(ALFA);
	cosbeta = (float)cos(BETA);

	if(cosalfa > 0.0)
		powcosalfa = (float)pow(cosalfa,s1);
	else
		powcosalfa =(float) - pow(- cosalfa,s1);

	if(cosbeta > 0.0)
		powcosbeta = (float)pow(cosbeta,s2);
	else
		powcosbeta = (float) - pow(- cosbeta,s2);

	return (R*powcosalfa*powcosbeta);

}


/******************************************************************************************/
/* Devuelve la coordenada y de un punto en R3 a partir de un punto (u,v)                  */
/*   de un espacio parametrico en R2                                                      */
/* Parametros: float u --> Primera coordenada de un punto en R2                           */
/*             float v --> Segunda coordenada de un punto en R2                           */
/*             float R --> Radio de la esfera envolvente                                  */
/*             float s1 --> Numero de divisiones en u                                     */
/*             float s2 --> Numero de divisiones en v                                     */
/* Salida: La coordenada y de un punto en R3                                              */
/******************************************************************************************/
float ySuperQuadric (float u, float v, float R, float s1, float s2)
{
	float sinalfa, powsinalfa;

	sinalfa = (float)sin(ALFA);

	if(sinalfa > 0.0)
		powsinalfa = (float)pow(sinalfa,s1);
	else
		powsinalfa = (float)- pow(- sinalfa,s1);

	return (R*powsinalfa);
}


/******************************************************************************************/
/* Devuelve la coordenada de un punto en R3 a partir de un punto (u,v)                    */
/*   de un espacio parametrico en R2                                                      */
/* Parametros: float u --> Primera coordenada de un punto en R2                           */
/*             float v --> Segunda coordenada de un punto en R2                           */
/*             float R --> Radio de la esfera envolvente                                  */
/*             float s1 --> Numero de divisiones en u                                     */
/*             float s2 --> Numero de divisiones en v                                     */
/* Salida: La coordenada z de un punto en R3                                              */
/******************************************************************************************/
float zSuperQuadric(float u, float v, float R, float s1, float s2)
{
	float cosalfa, sinbeta, powcosalfa, powsinbeta;

	cosalfa = (float)cos(ALFA);
	sinbeta=(float)sin(BETA);

	if(cosalfa > 0.0)
		powcosalfa = (float)pow(cosalfa,s1);
	else
		powcosalfa=(float) - pow(- cosalfa,s1);

	if(sinbeta > 0.0)
		powsinbeta = (float)pow(sinbeta,s2);
	else
		powsinbeta = (float) - pow(- sinbeta,s2);

	return(R*powcosalfa*powsinbeta);
}

/********************** RUTINA DE DIBUJO *********************************/

void igCreateQuadricObject(int pu, int pv, float uMax, float vMax, float R, float s1, float s2)

{
	float u, v, inc_u, inc_v;
	float x, y, z;
	int   i, j;
	

	v = 0.0f;
	u = 0.0f;
	inc_u = uMax / pu;/* pu es el numero de divisiones en u */
	inc_v = vMax / pv;/* pv es el numero de divisiones en v */

	
	for (j = 0; j <= pv; j++)
	{
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <=  pu; i++)
		{
			x = xSuperQuadric(u, v, R, s1, s2);
			y = ySuperQuadric(u, v, R, s1, s2);
			z = zSuperQuadric(u, v, R, s1, s2);
			glVertex3f(x, y, z);
			u = u + inc_u ;
		}
		u = 0;
		v = v + inc_v;
		glEnd();
	}
	v = 0.0f;
	u = 0.0f;
	for (j = 0; j <= pv; j++)
	{
		glBegin(GL_LINE_STRIP);
		for (i = 0; i <= pu; i++)
		{
			x = xSuperQuadric(u, v, R, s1, s2);
			y = ySuperQuadric(u, v, R, s1, s2);
			z = zSuperQuadric(u, v, R, s1, s2);
			glVertex3f(x, y, z);
			v = v + inc_v;
		}
		v = 0;
		u = u + inc_u;
		glEnd();
	}

}


void igWireSphere(int pu, int pv) {
	igCreateQuadricObject(pu, pv, 1.0, 1.0, 1.0, 1.0, 1.0);
}/* s1 y s2 a 1 */
void igWireRulo(int pu, int pv) {
	igCreateQuadricObject(pu, pv, 1.0, 1.0, 1.0, 0.5, 1.0);
}/* s1= 0.5, s2= 1 */
void igWireDado(int pu, int pv) {
	igCreateQuadricObject(pu, pv, 1.0, 1.0, 1.0, 0.5, 0.5);
}/* s1= 0.5, s2 =0.5 */
void igWireSemiSphere(int pu, int pv) {
	igCreateQuadricObject(pu, pv, 1.0, 0.5, 1.0, 1.0, 1.0);
}	/* s1 y s2 a 1, uMax= 1, vMax= 0.5 */
void igWireCubo(void) {
	float u = 0.5;
	float p0[3] = { u, u, u },
		p1[3] = { u, -u, u },
		p2[3] = { -u, -u, u },
		p3[3] = { -u, u, u },
		p4[3] = { u, u, u },
		p5[3] = { u, u, -u },
		p6[3] = { u, -u, -u },
		p7[3] = { -u, -u, -u },
		p8[3] = { -u, u, -u },
		p9[3] = { u, u, -u };

	float* list[10] = {p0,p1,p2,p3,p4,p5,p6,p7,p8,p9};
	glBegin(GL_LINE_STRIP);
	for (int i=0; i<10 ; i++)
	{
		glVertex3fv(list[i]);
	}
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(list[1]);
	glVertex3fv(list[6]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(list[2]);
	glVertex3fv(list[7]);
	glEnd();
	glBegin(GL_LINE_STRIP);
	glVertex3fv(list[3]);
	glVertex3fv(list[8]);
	glEnd();

}
