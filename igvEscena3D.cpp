//ME HUELE LA POLLA A MIERDA

#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"

// M�todos constructores -----------------------------------

// M�todos p�blicos ----------------------------------------

/**
 * M�todo para pintar los ejes coordenados llamando a funciones de OpenGL
 */

struct Transformaciones {
   float tx = 0, ty = 0, tz = 0; // traslación acumulada
   float rx = 0, ry = 0, rz = 0; // ángulos acumulados (grados)
   float s = 1; // escala acumulada
};
Transformaciones obj[3]; // una por objeto
int seleccionado = 0;

void igvEscena3D::pintar_ejes ()
{  GLfloat rojo[] = { 1,0,0,1.0 };
   GLfloat verde[] = { 0,1,0,1.0 };
   GLfloat azul[] = { 0,0,1,1.0 };

   glBegin(GL_LINES);
   glMaterialfv(GL_FRONT, GL_EMISSION, rojo);
   glVertex3f(1000, 0, 0);
   glVertex3f(-1000, 0, 0);

   glMaterialfv(GL_FRONT, GL_EMISSION, verde);
   glVertex3f(0, 1000, 0);
   glVertex3f(0, -1000, 0);

   glMaterialfv(GL_FRONT, GL_EMISSION, azul);
   glVertex3f(0, 0, 1000);
   glVertex3f(0, 0, -1000);
   glEnd();
}

void igvEscena3D::muñeco_nieve ()
{

   GLfloat rojo[] = { 1,0,0,1.0 };
   glMaterialfv(GL_FRONT, GL_EMISSION, rojo);

   glPushMatrix();
   glTranslatef (0, 0, 0);
   glutSolidSphere(1.0, 30, 30);
   glPopMatrix();

   glPushMatrix();
   glTranslatef (0, 1.5, 0);
   glutSolidSphere(1.0, 30, 30);
   glPopMatrix();

   glPushMatrix();
   glTranslatef (0, 3, 0);
   glutSolidSphere(1.0, 30, 30);
   glPopMatrix();

   glPushMatrix();
   glTranslatef (0, 3, 1);
   glutSolidCone(0.2,1.5, 20, 2);
   glPopMatrix();

   GLUquadricObj *cilindroDer;
   cilindroDer= gluNewQuadric ();
   gluQuadricDrawStyle (cilindroDer, GLU_LINE);
   glRotatef(90.0f, 0.0f, 1.0f, 0.0f); // Rota -90º en X para apuntar hacia +Y
   glTranslatef (0, 1.75, 0);
   glRotatef(20.0f, 1.0f, 0.0f, 0.0f); // Rota -90º en X para apuntar hacia +Y
   gluCylinder(cilindroDer, 0.05,0.05, 3, 300, 300);
   gluDeleteQuadric(cilindroDer);



   GLUquadricObj *cilindroIzq;
   cilindroIzq= gluNewQuadric ();
   gluQuadricDrawStyle (cilindroIzq, GLU_LINE);

   glRotatef(-180.0f, 0.0f, 1.0f, 0.0f);
   glRotatef(20.0f, 1.0f, 0.0f, 0.0f);

   gluCylinder(cilindroIzq, 0.05,0.05, 3, 300, 300);
   gluDeleteQuadric(cilindroIzq);



}



/**
 * M�todo con las llamadas OpenGL para visualizar la escena
 * @param escena Identificador del tipo de escena a dibujar
 * @pre Se asume que el valor del par�metro es correcto
 */
void igvEscena3D::visualizar ()
{  // borra la ventana y el Z-buffer
   glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

   //Luces
   GLfloat light0[] = { 10, 8, 9, 1 }; // point light source
   glLightfv ( GL_LIGHT0, GL_POSITION, light0 );
   glEnable ( GL_LIGHT0 );

   glPushMatrix (); // guarda la matriz de modelado

   // se pintan los ejes
   if ( ejes )
   {  pintar_ejes ();
   }

   // Escena seleccionada a trav�s del men� (clic bot�n derecho)
  /* if ( escena == EscenaA )
   {  renderEscenaA ();
   }
   else
   {  if ( escena == EscenaB )
      {  renderEscenaB ();
      }
      else
      {  if ( escena == EscenaC )
         {  renderEscenaC ();
         }
      }
   }*/

   muñeco_nieve();
   glPopMatrix (); // restaura la matriz de modelado
   glutSwapBuffers (); // se utiliza, en vez de glFlush(), para evitar el parpadeo
}

/**
 * Pinta la escena A llamando a las funciones de OpenGL
 */
/*void igvEscena3D::renderEscenaA ()
{  GLfloat color_pieza[] = { 0, 0.25, 0 };

   // TODO: Practica 2a. Parte A.
   glMaterialfv ( GL_FRONT, GL_EMISSION, color_pieza );

   glPushMatrix ();
   glutSolidCube ( 1 );
   glPopMatrix ();
}

/**
 * Pinta la escena B llamando a las funciones de OpenGL

void igvEscena3D::renderEscenaB ()
{  GLfloat color_pieza[] = { 0, 0, 0.5 };

   // TODO: Practica 2a. Parte B.
   glMaterialfv ( GL_FRONT, GL_EMISSION, color_pieza );

   glPushMatrix ();
   glutSolidCube ( 1 );
   glPopMatrix ();
}

/**
 * Pinta la escena C llamando a las funciones de OpenGL

void igvEscena3D::renderEscenaC ()
{  GLfloat color_pieza[] = { 0.5, 0, 0 };

   // TODO: Practica 2a. Parte C.
   glMaterialfv ( GL_FRONT, GL_EMISSION, color_pieza );

   glPushMatrix ();
   glutSolidCube ( 1 );
   glPopMatrix ();
}*/

/**
 * M�todo para consultar si hay que dibujar los ejes o no
 * @retval true Si hay que dibujar los ejes
 * @retval false Si no hay que dibujar los ejes
 */
bool igvEscena3D::get_ejes ()
{  return ejes;
}

/**
 * M�todo para activar o desactivar el dibujado de los ejes
 * @param _ejes Indica si hay que dibujar los ejes (true) o no (false)
 * @post El estado del objeto cambia en lo que respecta al dibujado de ejes,
 *       de acuerdo al valor pasado como par�metro
 */
void igvEscena3D::set_ejes ( bool _ejes )
{  ejes = _ejes;
}




