#include <GL/glut.h>
#include <math.h>

void drawCircle(float x, float y, float radius) {
  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(x, y); // Centro do círculo

  for (int i = 0; i <= 100; i++) {
    float angle = 2.0f * 3.1415926f * (float)i / (float)100; // ângulo
    float dx = radius * cosf(angle);
    float dy = radius * sinf(angle);
    glVertex2f(x + dx, y + dy); // ponto
  }
  glEnd();
}

void drawLine(float x1, float y1, float x2, float y2) {
  glBegin(GL_LINES);
  glVertex2f(x1, y1);
  glVertex2f(x2, y2);
  glEnd();
}

void drawHelloKitty() {
  glColor3f(1.0f, 1.0f, 1.0f);  // Branco
  drawCircle(0.0f, 0.0f, 0.5f); // Cabeça

  // Olhos
  glColor3f(0.0f, 0.0f, 0.0f);     // Preto
  drawCircle(-0.15f, 0.1f, 0.05f); // Olho esquerdo
  drawCircle(0.15f, 0.1f, 0.05f);  // Olho direito

  // Nariz
  glColor3f(1.0f, 0.8f, 0.0f);   // Amarelo
  drawCircle(0.0f, 0.0f, 0.05f); // Nariz

  // Orelhas
  glColor3f(1.0f, 1.0f, 1.0f); // Branco
  glBegin(GL_TRIANGLES);

  // Orelha esquerda
  glVertex2f(-0.5f, 0.2f); // topo
  glVertex2f(-0.4f, 0.7f); // esquerda
  glVertex2f(-0.2f, 0.5f); // direita

  // Orelha direita
  glVertex2f(0.5f, 0.2f);
  glVertex2f(0.4f, 0.7f);
  glVertex2f(0.2f, 0.5f);
  glEnd();

  // Bigodes
  glColor3f(0.0f, 0.0f, 0.0f); // Preto

  // Esquerda
  drawLine(-0.3f, -0.1f, -0.6f, -0.05f); // de baixo
  drawLine(-0.3f, 0.0f, -0.6f, 0.05f);   // do meio
  drawLine(-0.3f, 0.1f, -0.6f, 0.15f);   // de cima

  // Direita
  drawLine(0.3f, -0.1f, 0.6f, -0.05f);
  drawLine(0.3f, 0.0f, 0.6f, 0.05f);
  drawLine(0.3f, 0.1f, 0.6f, 0.15f);

  // Laço
  glColor3f(1.0f, 0.0f, 0.0f);    // Vermelho
  drawCircle(0.15f, 0.5f, 0.05f); // Nariz
  glBegin(GL_TRIANGLES);
  glVertex2f(0.05f, 0.7f); // topo
  glVertex2f(0.05f, 0.3f); // esq
  glVertex2f(0.15f, 0.5f); // dir

  glVertex2f(0.25f, 0.7f);
  glVertex2f(0.15f, 0.5f);
  glVertex2f(0.25f, 0.3f);
  glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawHelloKitty();
  glFlush();
}

void init() {
  glClearColor(0.98, 0.776, 0.812, 1.0);
  glColor3f(0.0f, 0.0f, 0.0f); // Preto
  glPointSize(1.0);
  glLineWidth(2.0);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Hello Kitty in GLUT");
  init();
  glutDisplayFunc(display);
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  glutMainLoop();
  return 0;
}
