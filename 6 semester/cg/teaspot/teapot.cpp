#include <GL/glut.h>
#include <SOIL/SOIL.h>
#include <iostream>

GLuint texture;

void drawText(const char* text, float x, float y) {
    glRasterPos2f(x, y);
    while (*text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *text++);
    }
}

GLuint loadTexture(const char* filename) {
    GLuint textureID;
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);

    // Carrega a imagem com SOIL
    int width, height;
    unsigned char* image = SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGB);
    if (!image) {
        std::cerr << "Erro ao carregar a imagem: " << filename << std::endl;
        return 0;
    }

    // Define a textura no OpenGL
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
    SOIL_free_image_data(image);

    // Configura os parâmetros da textura
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return textureID;
}

void drawTransformedTeapot(float tx, float ty, float sx, float sy, float angle, const char* label) {
    drawText(label, tx, ty + 0.6f);

    glPushMatrix();
    glTranslatef(tx, ty, 0.0f);
    glScalef(sx, sy, 1.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, texture);  // Aplica a textura
    glutSolidTeapot(0.6);                   // Teapot com textura
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (texture == 0) {
        std::cerr << "Erro: textura não carregada corretamente.\n";
        return;
    }

    // Teapot original
    glColor3f(1.0f, 1.0f, 1.0f);
    drawText("Original", 0.0f, 2.0f);
    glPushMatrix();
    glTranslatef(0.0f, 1.5f, 0.0f);
    glScalef(0.5f, 0.5f, 1.0f);
    glBindTexture(GL_TEXTURE_2D, texture);
    glutSolidTeapot(0.6);
    glPopMatrix();

    float yPosition = -0.8f;

    // Teapot com rotação
    glColor3f(1.0f, 0.0f, 0.0f);
    drawTransformedTeapot(-1.5f, yPosition, 0.5f, 0.5f, 45.0f, "Rotacao");

    // Teapot com translação
    glColor3f(0.0f, 1.0f, 0.0f);
    drawTransformedTeapot(-0.6f, yPosition - 1.0f, 0.5f, 0.5f, 0.0f, "Translacao");

    // Teapot com cisalhamento
    glPushMatrix();
    glTranslatef(0.5f, yPosition, 0.0f);
    GLfloat shearMatrix[] = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.5f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f
    };
    glMultMatrixf(shearMatrix);
    glScalef(0.6f, 0.6f, 1.0f);
    glColor3f(0.0f, 0.0f, 1.0f);
    drawText("Cisalhamento", -0.5f, yPosition + 2.0f);
    glBindTexture(GL_TEXTURE_2D, texture);
    glutSolidTeapot(0.6);
    glPopMatrix();

    // Teapot com reflexão
    glColor3f(1.0f, 1.0f, 0.0f);
    drawTransformedTeapot(1.5f, yPosition, 0.5f, -0.5f, 0.0f, "Reflexao");

    glFlush();
    glutSwapBuffers();
}

void init() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);

    // Carrega a textura e verifica erros
    texture = loadTexture("obsidiana.jpg");
    if (texture == 0) {
        std::cerr << "Erro ao carregar a textura 'obsidiana.jpg'. Verifique o caminho e o formato do arquivo.\n";
    }

    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0, 1.0, 1.0, 10.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Teapots with Transformations and Labels");

    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

