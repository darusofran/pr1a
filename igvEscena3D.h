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
class igvEscena3D
{  public:




   private:
      // Atributos
      bool ejes  = true;   ///< Indica si hay que dibujar los ejes coordenados o no
      int objetoSeleccionado = 1;
      // TODO: Declarar atributos para manejar las transformaciones para las escenas B y C

   public:
      // Constructores por defecto y destructor
      /// Constructor por defecto
      igvEscena3D() = default;
      /// Destructor
      ~igvEscena3D() = default;

      // M�todos
      // m�todo con las llamadas OpenGL para visualizar la escena
      void visualizar ();

      bool get_ejes();
      void set_ejes(bool _ejes);

      int get_objeto_seleccionado() const { return objetoSeleccionado; }
      void set_objeto_seleccionado(int obj) { objetoSeleccionado = obj; }


   private:


      void pintar_ejes ();
      void muñeco_nieve ();

};

#endif   // __IGVESCENA3D
