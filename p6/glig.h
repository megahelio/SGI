/*************************************************************************/
/*                                                                       */
/*                 glig.h LIBRERIA DE MODELADO GEOMETRICO	             */
/*                                                                       */
/*   Rev. 3.0  01/09/2012   Universidad Jaume I de Castell�n             */
/*                                                                       */
/*************************************************************************/



#ifndef GLIG_H
#define GLIG_H


/* Devuelve la coordenada x de un punto en R3 a partir de un punto (u,v) */
float xSuperQuadric(float u, float v, float R, float s1, float s2);

/* Devuelve la coordenada y de un punto en R3 a partir de un punto (u,v) */
float ySuperQuadric(float u, float v, float R, float s1, float s2);

/* Devuelve la coordenada z de un punto en R3 a partir de un punto (u,v) */
float zSuperQuadric(float u, float v, float R, float s1, float s2);

void igCreateQuadricObject(int pu, int pv, float uMax, float vMax, float R, float s1, float s2);

void igWireSphere(int pu, int pv); /* s1 y s2 a 1 */
void igWireRulo(int pu, int pv); /* s1= 0.5, s2= 1 */
void igWireDado(int pu, int pv); /* s1= 0.5, s2 =0.5 */
void igWireSemiSphere(int pu, int pv); /* s1 y s2 a 1, uMax= 1, vMax= 0.5 */
void igWireCubo(void);
void igWireCone(int pu, int pv);
#endif