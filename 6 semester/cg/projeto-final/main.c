#include <GL/gl.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <GL/glut.h>
#include <math.h>

GLuint baseballTexture, appleTexture;

// Função para carregar textura usando stb_image
GLuint loadTexture(const char *filename) {
  int width, height, channels;
  unsigned char *data = stbi_load(filename, &width, &height, &channels, 0);
  if (!data) {
    printf("Erro ao carregar a textura: %s\n", filename);
    return 0;
  }

  GLuint texture;
  glGenTextures(1, &texture);
  glBindTexture(GL_TEXTURE_2D, texture);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  GLenum format = (channels == 4) ? GL_RGBA : GL_RGB;
  glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
               GL_UNSIGNED_BYTE, data);

  stbi_image_free(data);
  return texture;
}

void drawSphere(float radius, int slices, int stacks) {
  for (int i = 0; i <= stacks; ++i) {
    float theta1 = i * M_PI / stacks;
    float theta2 = (i + 1) * M_PI / stacks;

    glBegin(GL_TRIANGLE_STRIP);
    for (int j = 0; j <= slices; ++j) {
      float phi = j * 2 * M_PI / slices;

      float x1 = radius * sinf(theta1) * cosf(phi);
      float y1 = radius * cosf(theta1);
      float z1 = radius * sinf(theta1) * sinf(phi);
      float u1 = (float)j / slices;
      float v1 = (float)i / stacks;

      float x2 = radius * sinf(theta2) * cosf(phi);
      float y2 = radius * cosf(theta2);
      float z2 = radius * sinf(theta2) * sinf(phi);
      float u2 = (float)j / slices;
      float v2 = (float)(i + 1) / stacks;

      glTexCoord2f(u1, v1);
      glVertex3f(x1, y1, z1);

      glTexCoord2f(u2, v2);
      glVertex3f(x2, y2, z2);
    }
    glEnd();
  }
}

void drawCaule() {
  glColor3f(0.0, 0.8, 0.2); // caule verde claro
  glPushMatrix();
  glTranslatef(1.5, -0.5, 0.0);
  glRotatef(-90, 1.0, 0.0, 0.0); // Rotacionar para a orientação correta
  GLUquadric *quad = gluNewQuadric();
  gluCylinder(quad, 0.05, 0.05, 0.3, 30, 30); // Desenha um cilindro como caule
  gluDeleteQuadric(quad);
  glPopMatrix();
}

void init() {
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_TEXTURE_2D);

  // Carrega as texturas
  baseballTexture = loadTexture("baseball.jpg");
  appleTexture = loadTexture("gold.jpg");

  glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  glTranslatef(0.0f, 0.0f, -5.0f);
  glRotatef(20, 1.0f, 0.0f, 0.0f);

  // esfera normal
  glPushMatrix();
  glTranslatef(-1.5, 1.0, 0.0);
  glColor3f(0.0, 0.0, 1.0);
  glDisable(GL_TEXTURE_2D);
  drawSphere(0.5, 30, 30);
  glEnable(GL_TEXTURE_2D);
  glPopMatrix();

  // esfera wireframe
  glPushMatrix();
  glTranslatef(1.5, 1.0, 0.0);
  glColor3f(0.0, 0.5, 1.0); // cor verde azulado
  glutWireSphere(0.5, 30, 30);
  glPopMatrix();

  // bola de baseball com a textura aplicada
  glPushMatrix();
  glTranslatef(-1.5, -1.0, 0.0);
  glBindTexture(GL_TEXTURE_2D, baseballTexture);
  glColor3f(1.0, 1.0, 1.0);
  drawSphere(0.5, 30, 30);
  glPopMatrix();

  // maçã dourada do minecraft
  glPushMatrix();
  glTranslatef(1.5, -1.0, 0.0);
  glBindTexture(GL_TEXTURE_2D, appleTexture);
  glColor3f(1.0, 1.0, 1.0);
  drawSphere(0.5, 30, 30);
  glPopMatrix();

  // funcao para desenhar o caule da maça
  drawCaule();
  glutSwapBuffers();
}

void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, (double)w / (double)h, 1.0, 10.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Cenário com Esferas e Texturas");

  init();

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return 0;
}
