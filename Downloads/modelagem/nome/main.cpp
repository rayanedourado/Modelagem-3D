#include<GL/freeglut.h>
#include<iostream>

GLfloat escala = 1.0f;
GLfloat escalaX = 1.0f;
GLfloat escalaY = 1.0f;
GLfloat posX = 0.0f;
GLfloat angulo = 0.0f;

void desenha(void);
void escutaTeclado(unsigned char tecla, GLint x, GLint y){

    switch(tecla) {
        case '+' : escalaX = escalaX + 0.5f;
            break;
        case '-':  escalaX = escalaX - 0.5f;
            break;
        case 'r' : escalaY = escalaY + 0.5f;
            break;
        case 'y' : escalaY = escalaY - 0.5f;
            break;
        case 'd':
            posX = posX + 0.5f;
            break;
        case 'e':
            posX = posX - 0.5f;
            break;
        case 'z':
            angulo = angulo + 5.0f;
            break;
        case 'x':
            angulo = angulo - 5.0f;
            break;
    }
    desenha();
}

void desenha(void) {
    glClear( GL_COLOR_BUFFER_BIT );

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-13, 13, -13, 13);

    glScalef(escalaX, escalaY, 0);
    glTranslatef(posX, 0.0f, 0.0f);
    glRotatef(angulo, 0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glBegin (GL_LINES);

        glVertex2f(-5.0, -2.0);
        glVertex2f(-5.0, 3.0);

        glVertex2f(-5.0, 3.0);
        glVertex2f(-3.0, 3.0);

        glVertex2f(-3.0, 3.0);
        glVertex2f(-3.0, 0.5);

        glVertex2f(-3.0, 0.5);
        glVertex2f(-5.0, 0.5);

        glVertex2f(-5.0, 0.5);
        glVertex2f(-3.0, -2.0);


        glVertex2f(-1.5, -2.0);
        glVertex2f(0.0, 3.0);

        glVertex2f(0.0, 3.0);
        glVertex2f(1.5, -2.0);

        glVertex2f(-0.75, 0.5);
        glVertex2f(0.75, 0.5);


        glVertex2f(3.0, 3.0);
        glVertex2f(4.0, 1.0);

        glVertex2f(5.0, 3.0);
        glVertex2f(4.0, 1.0);

        glVertex2f(4.0, 1.0);
        glVertex2f(4.0, -2.0);
    glEnd();

    glFlush();
}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(300,100);
    glutCreateWindow("Letras Glut");
    glutKeyboardFunc(escutaTeclado);
    glutDisplayFunc(desenha);
    glClearColor(1.0f, 0.41f, 0.71f, 1.0f);
    glutMainLoop();
    return 0;
}
