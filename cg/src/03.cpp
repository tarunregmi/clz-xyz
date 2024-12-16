#include <GL/glut.h>

void Midpoint_Circle(int xc, int yc, int r) {
    int x = 0;
    int y = r;
    int d = 1 - r;

    glBegin(GL_POINTS);
    while (x <= y) {
        // Plot the 8 symmetric points
        glVertex2f((xc + x) / 100.0, (yc + y) / 100.0);
        glVertex2f((xc - x) / 100.0, (yc + y) / 100.0);
        glVertex2f((xc + x) / 100.0, (yc - y) / 100.0);
        glVertex2f((xc - x) / 100.0, (yc - y) / 100.0);
        glVertex2f((xc + y) / 100.0, (yc + x) / 100.0);
        glVertex2f((xc - y) / 100.0, (yc + x) / 100.0);
        glVertex2f((xc + y) / 100.0, (yc - x) / 100.0);
        glVertex2f((xc - y) / 100.0, (yc - x) / 100.0);

        if (d < 0) {
            d += 2 * x + 3;
        } else {
            d += 2 * (x - y) + 5;
            y--;
        }
        x++;
    }
    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    Midpoint_Circle(0, 0, 50);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tarun Regmi - Midpoint Circle Algorithm");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
