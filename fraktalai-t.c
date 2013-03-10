#include <GL/glut.h>

int current = 1;
    
void draw_fractal(int num) {
    switch (num) {
        case 0:
            glRectf(-1, -1, -0.6, 1);
            glRectf(-1, -1, 1, -0.6);
        break;
        case 10:
            current = 0;
            glutPostRedisplay();
        break;
        default:
            glPushMatrix();
            if (num == current)
                    glColor3f(1.0, 0.0, 0.0);

            glTranslatef(-0.5, 0.5, 0);
            glScalef(-0.5, 0.5, 1);
            draw_fractal(num - 1);
            glPopMatrix();

            glPushMatrix();
            if (num == current)
                    glColor3f(0.0, 1.0, 0.0);

            glTranslatef(0.75, 0.75, 0);
            glRotatef(180, 0, 0, 1);
            glScalef(0.25, 0.25, 1);
            draw_fractal(num - 1);
            glPopMatrix();

            glPushMatrix();
            if (num == current)
                    glColor3f(0.0, 0.0, 1.0);

            glTranslatef(0.5, -0.5, 0);
            glRotatef(90, 0, 0, -1);
            glScalef(-0.5, 0.5, 0);
            draw_fractal(num - 1);
            glPopMatrix();

            glPushMatrix();
            if (num == current)
                    glColor3f(1.0, 1.0, 1.0);

            glTranslatef(-0.5, -0.5, 0);
            glScalef(0.5, 0.5, 1);
            draw_fractal(num - 1);
            glPopMatrix();
            break;
    }
}

void draw() {
        glClear(GL_COLOR_BUFFER_BIT);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        draw_fractal(current);

        glutSwapBuffers();
}

void resize(int w, int h) {
        glViewport(0, 0, w, h);
        draw();
}

void keyboard(unsigned char c, int x, int y) {
        current++;
        draw();
}

void init() {
        glutReshapeFunc(resize);
        glutKeyboardFunc(keyboard);
        glClear(GL_COLOR_BUFFER_BIT);

        draw();
}

int main(int argc, char** argv) {
        glutInit(&argc, argv);

        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(600, 600);
        glutInitWindowPosition(0, 0);
        glutCreateWindow("KG 2. Egidijus Lukauskas: 374");

        glutDisplayFunc(init);

        glutMainLoop();
        return 0;
}
