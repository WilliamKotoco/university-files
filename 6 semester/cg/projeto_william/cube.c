#include "cube.h"
#include <GL/gl.h>

void desenha_cubo() {

  /// especifica a largura da linha
  glLineWidth(1);

  /// função do glut que renderiza um cubo sólido
  glutSolidCube(1);

  glLineWidth(1);

  /// muda a cor do fio do cubo para preto
  glColor3f(0, 0, 0);
  /// desenha as linhas do cubo
  glutWireCube(1);
}
