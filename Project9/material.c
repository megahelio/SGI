/*************************************************************************/
/*                                                                       */
/*   material.c                                                          */
/*   Rev. 2.0  01/01/2002   AUTORES: O. Belmonte, M. Chover, J. Ribelles */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/

#include "glut.h"


/********************** RUTINA DE INICIO **************************************************/
/******************************************************************************************/
/* Inicia OpenGL para poder definir las propiedades de los materiales                     */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaMaterial(void)
{
	/* Se modificara las propiedades de color de material ambiente y difusa */
	glColorMaterial(GL_FRONT,GL_DIFFUSE); //Solo difuse con glColor

	/* Se permite el cambio de la propiedad de material con glColor */
	glEnable(GL_COLOR_MATERIAL);
}

/*********************** DEFINICION DE MATERIALES *****************************************/
/******************************************************************************************/
/* Define las propiedades del material cobre                                              */
/* Parametros: Ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void Cobre (void) {
//	Cobre
// 0.33 0.26 0.23  Ambiente
// 0.50 0.11 0.00  difuso
// 0.95 0.73 0.00  Especular
// 93  Brillo
 
	GLfloat material_Ka[]={0.33,0.26,0.23,1.0};
	GLfloat material_Kd[]={0.5,0.11,0.0,1.0};
	GLfloat material_Ks[]={0.95,0.73,0.0,1.0};
	GLfloat material_Se[]={93.0};

	glMaterialfv(GL_FRONT,GL_AMBIENT,material_Ka);
	//glMaterialfv(GL_FRONT,GL_DIFFUSE,material_Kd);
	glColor3fv(material_Kd);
	glMaterialfv(GL_FRONT,GL_SPECULAR,material_Ks);
	glMaterialfv(GL_FRONT,GL_SHININESS,material_Se);
	

}
void Oro() {
	
}
