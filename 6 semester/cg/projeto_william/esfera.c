#include "esfera.h"
#include <GL/freeglut_std.h>
#include <GL/gl.h>

void desenha_esfera() {

  /// desenha a esfera (a cor foi definida na função chamadora)
  glutSolidSphere(0.4, 20, 20);
  /// largura da linha do cone
  glLineWidth(1);

  /// define a cor das linhas da esfera
  glColor3f(0.0, 0.0, 0.0);

  /// desenha as linhas da esfera
  glutWireSphere(0.4, 20, 20);
}
