/*************************************************************************/
/*                                                                       */
/*   modelado.c                                                          */
/*   27/10/03  AUTORES: C.Rebollo                                        */
/*                                                                       */
/*************************************************************************/

/***************** INCLUDES DE LAS LIBRERIAS NECESARIAS ******************/
#include "glig.h"
#include "modelado.h"


/******************************************************************************************/
/* Crea los distintos objetos. En este caso iun abeto, si tuviese mas objetos, los pòndría*/
/* a continuación.                                                                        */
/* Parametros: ninguno                                                                    */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/
void IniciaDisplayLists (void)
{
    CreaAbeto ();
	CreaEscalera();

}

/******************************************************************************************/
/* Crea una display list para dibujar un abeto                                            */
/* Parametros: ninguno */
/* Salida: Ninguna                                                                        */
/******************************************************************************************/

void CreaEscalera(void)
{
	escalera = glGenLists(1);
	if (escalera != 0) /* Cero no es un identificador valido para una display list */
	{
		glNewList(escalera, GL_COMPILE);
		glScalef(0.2, 2.0, 0.2);
		igWireCubo();

		glEndList();
	}
}


void CreaAbeto (void)
{
     abeto=glGenLists(1);  
	if (abeto !=0) /* Cero no es un identificador valido para una display list */
		{  
	  			glNewList(abeto, GL_COMPILE);  
				 /*  Código para dibujar el abeto */
				 /*  Primero dibujo la copa */
				glPushMatrix();
					glScalef(0.75, 1.0, 0.75);
					igWireCone(10, 10);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(0.0, 0.25, 0.0);
					glScalef(0.75 * 0.75, 1.0, 0.75 * 0.75);
					igWireCone(10, 10);
				glPopMatrix();

				glPushMatrix();
					glTranslatef(0.0, 0.5, 0.0);
					glScalef(0.75*0.75*0.75, 1.0, 0.75*0.75 * 0.75);
					igWireCone(10, 10);
				glPopMatrix();

				glPushMatrix();
					glScalef(0.1, 1.0, 0.1);
					igWireRulo(10, 10);
				glPopMatrix();
	   			
				glEndList ();  
 			}  
}


void Arco(void)
{
	abeto = glGenLists(1);
	if (abeto != 0) /* Cero no es un identificador valido para una display list */
	{
		glNewList(abeto, GL_COMPILE);


		glEndList();
	}
}


