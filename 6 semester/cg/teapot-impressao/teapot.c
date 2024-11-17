#include <GL/glut.h>

// Função para desenhar os 4 teapots com cores sólidas
void desenharTeapots() {
    // Teapot 1 - Vermelho
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, 0.f);  // Posição do primeiro teapot
    glColor3f(1.0f, 0.0f, 0.0f);       // Cor vermelha
    glutSolidTeapot(0.4);
    glPopMatrix();

    // Teapot 2 - Verde
    glPushMatrix();
    glTranslatef(0.5f, 0.0f, 1.0f);   // Posição do segundo teapot
    glColor3f(0.0f, 1.0f, 0.0f);       // Cor verde
    glutSolidTeapot(0.8);
    glPopMatrix();

    // Teapot 3 - Azul
    glPushMatrix();
    glTranslatef(0.75f, 1.0f, -10.0f);  // Posição do terceiro teapot
    glColor3f(0.0f, 0.0f, 1.0f);        // Cor azul
    glutSolidTeapot(0.5);
    glPopMatrix();

    // Teapot 4 - Amarelo
    glPushMatrix();
    glTranslatef(1.0f, 0.0f, -10.0f);  // Posição do quarto teapot
    glColor3f(1.0f, 1.0f, 0.0f);       // Cor amarela
    glutSolidTeapot(0.8);
    glPopMatrix();
}

// Função de display para configurar a cena
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    // Configuração da câmera
    gluLookAt(0.0, 0.0, 1.0,  // Posição da câmera
              0.0, 0.0, 0.0,   // Ponto de referência
              0.0, 1.0, 0.0);  // Direção do "up"

    desenharTeapots();

    glutSwapBuffers();
}

// Função principal
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("4 Teapots com Cores Sólidas");

    glEnable(GL_DEPTH_TEST);  // Habilita o teste de profundidade para renderização 3D

    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

