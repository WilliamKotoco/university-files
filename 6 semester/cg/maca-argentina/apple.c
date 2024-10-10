#include <GL/gl.h>
#include <GL/glext.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

// Variáveis para controle da iluminação e rotação da cena
GLfloat light_pos[] = {1.0, 1.0, 1.0, 0.0};     // Posição da luz
GLfloat light_ambient[] = {0.2, 0.2, 0.2, 1.0}; // Luz ambiente
GLfloat light_diffuse[] = {0.8, 0.8, 0.8, 1.0}; // Luz difusa
// GLfloat light_specular[] = {1.0, 1.0, 1.0, 1.0}; // Luz especular
GLfloat light_specular[] = {0, 0, 0, 1.0}; // Luz especular
GLuint texture;                            // Identificador da textura da maçã
GLuint texture_maca2;
GLuint flagTexture; // Identificador da textura da bandeira

// Função para carregar a textura
void loadTexture(const char *filename, GLuint *textureID) {
  int width, height, nrChannels;
  unsigned char *data = stbi_load(filename, &width, &height, &nrChannels, 0);

  if (data) {
    GLenum format;
    if (nrChannels == 1)
      format = GL_RED;
    else if (nrChannels == 3)
      format = GL_RGB;
    else if (nrChannels == 4)
      format = GL_RGBA;
    else {
      printf("Formato de imagem não suportado: %d canais\n", nrChannels);
      stbi_image_free(data);
      return;
    }

    glGenTextures(1, textureID);
    glBindTexture(GL_TEXTURE_2D, *textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format,
                 GL_UNSIGNED_BYTE, data);

    // Parâmetros da textura
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    printf("Textura carregada com sucesso: %s (%d x %d)\n", filename, width,
           height);
  } else {
    printf("Falha ao carregar a textura: %s\n", filename);
  }
  stbi_image_free(data); // Libera a memória
}

// Função para desenhar o caule da maçã
void drawStem() {
  glColor3f(0.4, 0.2, 0.0); // Cor do caule
  glPushMatrix();
  glTranslatef(0.0, 0.6, 0.0);   // Posição do caule
  glRotatef(-90, 1.0, 0.0, 0.0); // Rotacionar para a orientação correta
  GLUquadric *quad = gluNewQuadric();
  gluCylinder(quad, 0.05, 0.05, 0.3, 30, 30); // Desenha um cilindro como caule
  gluDeleteQuadric(quad);
  glPopMatrix();
}

// Função para desenhar uma maçã em formato mais realista
void drawApple(GLint texture_) {
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, texture_);
  glPushMatrix();

  // Desenha uma maçã com formato mais realista usando uma malha
  glColor3f(1.0, 1.0, 1.0); // Define a cor como branca para usar a textura
  GLUquadric *quad = gluNewQuadric();
  gluQuadricTexture(quad, GL_TRUE); // Habilitar textura na quadric

  // Formato mais achatado
  glScalef(0.8, 0.9, 0.8);      // achatamento para simular a maçã
  gluSphere(quad, 0.6, 50, 50); // Desenha uma esfera texturizada como maçã

  gluDeleteQuadric(quad);

  glPopMatrix();
}

// Função para desenhar a bandeira da Argentina
// Função para desenhar a bandeira da Argentina
void drawFlag() {
  glEnable(GL_TEXTURE_2D);
  glBindTexture(GL_TEXTURE_2D, flagTexture); // Use a textura da bandeira

  glPushMatrix();
  glTranslatef(0.0, 0.0, -1.5); // Posição da bandeira em relação à maçã
  glScalef(2.0, 1.0, 1.0);      // Escala para tornar a bandeira mais visível
  glBegin(GL_QUADS);
  glTexCoord2f(0.0, 0.0);
  glVertex3f(-1.0, 0.5, 0.0); // Canto inferior esquerdo
  glTexCoord2f(1.0, 0.0);
  glVertex3f(1.0, 0.5, 0.0); // Canto inferior direito
  glTexCoord2f(1.0, 1.0);
  glVertex3f(1.0, -0.5, 0.0); // Canto superior direito
  glTexCoord2f(0.0, 1.0);
  glVertex3f(-1.0, -0.5, 0.0); // Canto superior esquerdo
  glEnd();

  glPopMatrix();
}

// Atualize a função display para incluir a bandeira
void display() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  gluLookAt(0.0, 1.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0); // Posiciona a câmera

  glRotatef(30, 1.0, 0.0, 0.0); // Rotaciona a cena para visualizar melhor
  glRotatef(45, 0.0, 1.0, 0.0); // Rotaciona a maçã

  glTranslatef(0.3, 0.5, 0);
  drawApple(texture); // Desenha a maçã

  glTranslatef(-1, -0.5, 0);
  drawApple(texture_maca2);
  glutSwapBuffers();
}

// Função de inicialização
void init() {
  glClearColor(0.0, 0.0, 0.0, 0.0); // Fundo preto
  glEnable(GL_DEPTH_TEST);          // Habilita o teste de profundidade

  // Configuração da iluminação
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);

  glEnable(GL_COLOR_MATERIAL);
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

  loadTexture("obsidiana.jpg", &texture);     // Carregar textura da maçã
  loadTexture("madeira.jpg", &texture_maca2); // Carregar textura da maçã 2
}

// Função de redimensionamento da janela
void reshape(int w, int h) {
  glViewport(0, 0, (GLsizei)w, (GLsizei)h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0, (GLfloat)w / (GLfloat)h, 1.0, 20.0);
  glMatrixMode(GL_MODELVIEW);
}

// Função principal
int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Maçã Hiper-Realista e Bandeira da Argentina");

  init(); // Inicializar configurações

  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();

  return 0;
}
