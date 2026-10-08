#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"



// M�todos constructores -----------------------------------

// M�todos p�blicos ----------------------------------------

/**
 * M�todo para pintar los ejes coordenados llamando a funciones de OpenGL
 */



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

void igvEscena3D::mesita()
{

    GLfloat marron[] = { 0.45, 0.20, 0.05, 1.0 };
    glMaterialfv(GL_FRONT, GL_EMISSION, marron);

    // Tablero circular
    GLUquadricObj *tablero;
    tablero = gluNewQuadric();

    glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    gluCylinder(tablero, 3.0, 3.0, 0.5, 40, 10);

    glPushMatrix();
    glRotatef(180.0, 1.0, 0.0, 0.0);
    gluDisk(tablero, 0.0, 3.0, 40, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.5);
    gluDisk(tablero, 0.0, 3.0, 40, 1);
    glPopMatrix();
    glPopMatrix();

    gluDeleteQuadric(tablero);

    // PATA CENTRAL

    GLfloat marronOscuro[] = { 0.25, 0.10, 0.03, 1.0 };
    glMaterialfv(GL_FRONT, GL_EMISSION, marronOscuro);

    GLUquadricObj *pata;
    pata = gluNewQuadric();

    glPushMatrix();
    glTranslatef(0, -3.0, 0);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(pata, 0.7, 0.9, 3.0, 30, 10);
    glPopMatrix();

    gluDeleteQuadric(pata);

    // BASE DE LA MESA

    glPushMatrix();
    glTranslatef(0, -3.1, 0);
    glScalef(1.8, 0.35, 1.8);
    glutSolidSphere(1.0, 30, 20);
    glPopMatrix();

    // FLORERO

    GLfloat florero[] = { 0.2, 0.55, 0.65, 1.0 };
    glMaterialfv(GL_FRONT, GL_EMISSION, florero);

    GLUquadricObj *vaso;
    vaso = gluNewQuadric();

    glPushMatrix();
    glTranslatef(0, 0.0, 0);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(vaso, 0.65, 0.45, 1.2, 30, 10);
    glPopMatrix();

    gluDeleteQuadric(vaso);

    glPushMatrix();
    glTranslatef(0, 1.2, 0);
    glutSolidTorus(0.10, 0.65, 20, 30);
    glPopMatrix();

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


void igvEscena3D::adaptador()
{

    GLfloat negro[] = { 0.05, 0.05, 0.05, 1.0 };
    glMaterialfv(GL_FRONT, GL_EMISSION, negro);

    glPushMatrix();
    glScalef(3.6, 3.2, 2.4);
    glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, 2.15, 0);
    glScalef(2.4, 1.4, 1.8);
    glutSolidCube(1);
    glPopMatrix();

    // PATILLA IZQUIERDA

    glPushMatrix();
    glTranslatef(-0.7, 3.45, 0);
    glScalef(0.35, 1.1, 0.35);
    glutSolidCube(1);
    glPopMatrix();

    // PATILLA DERECHA

    glPushMatrix();
    glTranslatef(0.7, 3.45, 0);
    glScalef(0.35, 1.1, 0.35);
    glutSolidCube(1);
    glPopMatrix();

    // PUNTAS METÁLICAS DE LAS PATILLAS

    GLfloat metal[] = { 0.45, 0.45, 0.45, 1.0 };
    glMaterialfv(GL_FRONT, GL_EMISSION, metal);

    GLUquadricObj *puntaIzq;
    puntaIzq = gluNewQuadric();

    glPushMatrix();
    glTranslatef(-0.7, 4.0, 0);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(puntaIzq, 0.22, 0.22, 0.5, 20, 10);
    glPopMatrix();

    gluDeleteQuadric(puntaIzq);

    GLUquadricObj *puntaDer;
    puntaDer = gluNewQuadric();

    glPushMatrix();
    glTranslatef(0.7, 4.0, 0);
    glRotatef(-90, 1, 0, 0);
    gluCylinder(puntaDer, 0.22, 0.22, 0.5, 20, 10);
    glPopMatrix();

    gluDeleteQuadric(puntaDer);
}



/**
 * M�todo con las llamadas OpenGL para visualizar la escena
 * @param escena Identificador del tipo de escena a dibujar
 * @pre Se asume que el valor del par�metro es correcto
 */

/*void igvEscena3D::visualizar1 ()
{  // borra la ventana y el Z-buffer
   glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

   //Luces
   GLfloat light0[] = { 10, 8, 9, 1 }; // point light source
   glLightfv ( GL_LIGHT0, GL_POSITION, light0 );
   glEnable ( GL_LIGHT0 );
   glPushMatrix ();
   glTranslatef(objeto[seleccionado].tx,objeto[seleccionado].ty,objeto[seleccionado].tz);
   silla();
   glPopMatrix();

   glutSwapBuffers (); // se utiliza, en vez de glFlush(), para evitar el parpadeo
}*/

void igvEscena3D::visualizar ()
{
   //Luces
   GLfloat light0[] = { 10, 8, 9, 1 }; // point light source
   glLightfv ( GL_LIGHT0, GL_POSITION, light0 );
   glEnable ( GL_LIGHT0 );

   // guarda la matriz de modelado

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


   glPushMatrix ();
   glTranslatef(objeto[0].tx, objeto[0].ty, objeto[0].tz);
   glRotatef(objeto[0].rx,1,0,0);
   glRotatef(objeto[0].ry,0,1,0);
   glRotatef(objeto[0].rz,0,0,1);
   glScalef(objeto[0].s,objeto[0].s,objeto[0].s);
   muñeco_nieve();
   glPopMatrix();

   glPushMatrix ();
   glTranslatef(objeto[1].tx, objeto[1].ty, objeto[1].tz);
   glRotatef(objeto[1].rx,1,0,0);
   glRotatef(objeto[1].ry,0,1,0);
   glRotatef(objeto[1].rz,0,0,1);
   glScalef(objeto[1].s,objeto[1].s,objeto[1].s);
   mesita();
   glPopMatrix();

   glPushMatrix ();
   glTranslatef(objeto[2].tx, objeto[2].ty, objeto[2].tz);
   glRotatef(objeto[2].rx,1,0,0);
   glRotatef(objeto[2].ry,0,1,0);
   glRotatef(objeto[2].rz,0,0,1);
   glScalef(objeto[2].s,objeto[2].s,objeto[2].s);
   adaptador();
   glPopMatrix();


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




