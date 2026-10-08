#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif   // defined(__APPLE__) && defined(__MACH__)

/**
 * Los objetos de esta clase representan escenas 3D para su visualizaci�n
 */

struct Transformaciones {
   float tx = 0.0, ty = 0.0, tz = 0.0;
   float rx = 0.0, ry = 0.0, rz = 0.0;
   float s = 1.0;
};

class igvEscena3D
{  public:




   private:
      // Atributos
      bool ejes  = true;   ///< Indica si hay que dibujar los ejes coordenados o no

      // TODO: Declarar atributos para manejar las transformaciones para las escenas B y C

   public:
      // Constructores por defecto y destructor
      /// Constructor por defecto
      igvEscena3D() = default;
      /// Destructor
      ~igvEscena3D() = default;

   Transformaciones objeto[3];
   int seleccionado = 0;



      // M�todos
      // m�todo con las llamadas OpenGL para visualizar la escena
      void visualizar ();
      /*void visualizar1 ();*/

      bool get_ejes();
      void set_ejes(bool _ejes);




   private:


      void pintar_ejes ();
      void muñeco_nieve ();
      void mesita();
      void adaptador();

};

#endif   // __IGVESCENA3D
