#include "cone.h"
#include <GL/freeglut_std.h>

void desenha_cone() {

  glLineWidth(1);

  /// função desenha um cone
  glutSolidCone(1, 2, 20, 10);

  glLineWidth(1);

  glColor3f(0.0, 0.0, 0.0);
  glutWireCone(1, 2, 20, 10);
}
