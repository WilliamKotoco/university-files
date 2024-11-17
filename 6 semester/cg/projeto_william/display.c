// **********************************************************************
//	Hierarquia3D.cpp
// **********************************************************************
// PUCRS/Escola PolitÃ©cnica
// COMPUTAÃ‡ÃƒO GRÃFICA
//
// Programa basico para criar aplicacoes 2D em OpenGL
//
// Marcio Sarroglia Pinho
// pinho@pucrs.br
// **********************************************************************

// Para uso no Xcode:
// Abra o menu Product -> Scheme -> Edit Scheme -> Use custom working directory
// Selecione a pasta onde voce descompactou o ZIP que continha este arquivo.

#include "cone.h"
#include "cube.h"
#include "esfera.h"
#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>

#ifdef WIN32
#include <glut.h>
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#endif

#ifdef __linux__

#endif
/// importa arquivos para desenho dos objetos
GLfloat AspectRatio;
GLfloat AngY;
int fazCalculoPonto;

GLfloat AnguloDeVisao;
GLfloat Obs[3];
GLfloat Alvo[3];

// **********************************************************************
//  void init(void)
//		Inicializa os parÃ¢metros globais de OpenGL e do cenÃ¡rio
//
// **********************************************************************
void init(void) {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Fundo de tela preto

  glShadeModel(GL_FLAT);
  // glColorMaterial ( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  Obs[0] = 0;
  Obs[1] = 3;
  Obs[2] = 3;
  Alvo[0] = 0;
  Alvo[1] = 0;
  Alvo[2] = -1;
  AnguloDeVisao = 70;
  AngY = 0;
  fazCalculoPonto = 0;
}

// **********************************************************************
//  void PosicUser()
//		Faz o posicinamento do observador no cenÃ¡rio.
//
// **********************************************************************
void PosicUser() {
  // Set the clipping volume
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(AnguloDeVisao, AspectRatio, 0.01, 200);

  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  gluLookAt(Obs[0], Obs[1], Obs[2], Alvo[0], Alvo[1], Alvo[2], 0.0f, 1.0f,
            0.0f);
}

// **********************************************************************
//  void reshape( int w, int h )
//		trata o redimensionamento da janela OpenGL
//
// **********************************************************************
void reshape(int w, int h) {

  // Prevent a divide by zero, when window is too short
  // (you cant make a window of zero width).
  if (h == 0)
    h = 1;

  // Ajusta a relaÃ§Ã£o entre largura e altura para evitar distorÃ§Ã£o na
  // imagem. Veja funÃ§Ã£o "PosicUser".
  AspectRatio = 1.0f * 800 / 600;

  // Reset the coordinate system before modifying
  glMatrixMode(GL_PROJECTION);
  // glLoadIdentity();
  //  Set the viewport to be the entire window
  //glViewport(0, 0, w, h);

  PosicUser();
}

// **********************************************************************
//  void DesenhaCenario(bool desenha)
//    Por enquanto apenas exibe o cenÃ¡rio e nÃ£o utiliza o parÃ¢metro
// 'desenha'.
// **********************************************************************
void DesenhaCenario(int desenha) {
  glPushMatrix();
  glTranslatef(-1.0f, 0.0f, -1.0f);
  glRotatef(AngY, 0, 0, 1);
  glColor3f(1, 0, 0);
  desenha_cubo();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(1.0f, 0.0f, -1.0f);
  glRotatef(AngY, 1, 1, 1);
  glColor3f(0, 1, 0);
  desenha_cone();
  glPopMatrix();

  glPushMatrix();
  glTranslatef(0.0f, 1.0f, 1.5f);
  glRotatef(AngY, 1, 0, 0);
  glColor3f(0, 0, 1);
  desenha_esfera();
  glPopMatrix();
}

// **********************************************************************
//  void display( void )
//
// **********************************************************************
void display(void) {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  PosicUser();
  DesenhaCenario(1);

  glutSwapBuffers();
}

// **********************************************************************
//  void keyboard ( unsigned char key, int x, int y )
//
//
// **********************************************************************
void keyboard(unsigned char key, int x, int y) {
  switch (key) {
  case 27:   // Termina o programa qdo
    exit(0); // a tecla ESC for pressionada
    break;
  case ' ':
    fazCalculoPonto = 0;
    break;
  /// faz a rotação em um eixo de 5 em 5
  case 'a':
  case 'A':
    AngY += 5;
    break;
  default:
    break;
  }
}

// **********************************************************************
//  void arrow_keys ( int a_keys, int x, int y )
// **********************************************************************
void arrow_keys(int a_keys, int x, int y) {
  switch (a_keys) {
    /// setinha para cima coloca em tela cheia
  case GLUT_KEY_UP:
    glutFullScreen(); //
    break;

  /// setinha para muda o tamanho para 700 e 500
  case GLUT_KEY_DOWN:
    glutInitWindowSize(700, 500);
    break;
  default:
    break;
  }
}

// **********************************************************************
//  void main ( int argc, char** argv )
// **********************************************************************
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(
      GLUT_DOUBLE | GLUT_DEPTH |
      GLUT_RGB); // | GLUT_STEREO);// | GLUT_DOUBLE | GLUT_RGBA );
  // glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH | GLUT_STEREO);// | GLUT_DOUBLE
  // | GLUT_RGBA );

  glutInitWindowPosition(0, 0);
  glutInitWindowSize(700, 500);
  glutCreateWindow("ComputaÃ§Ã£o GrÃ¡fica - TransformaÃ§Ãµes HierÃ¡rquicas 3D");

  init();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutSpecialFunc(arrow_keys);
  glutIdleFunc(display);

  glutMainLoop();
  return 0;
}
