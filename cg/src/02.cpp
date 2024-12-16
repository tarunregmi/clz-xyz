#include <GL/glut.h>
#include <cmath>

void Bresenham_Line(int x1, int y1, int x2, int y2) {
    int dx = std::abs(x2 - x1);
    int dy = std::abs(y2 - y1);
    int sx = (x2 > x1) ? 1 : -1;
    int sy = (y2 > y1) ? 1 : -1;
    bool steep = dy > dx;
    if (steep) std::swap(dx, dy);
    int err = 2 * dy - dx;
    int x = x1;
    int y = y1;

    glBegin(GL_POINTS);
    for (int i = 0; i <= dx; i++) {
        if (steep) glVertex2f((float)y / 100, (float)x / 100);
        elseglVertex2f((float)x / 100, (float)y / 100);

        while (err >= 0) {
            y += sy;
            err -= 2 * dx;
        }
        x += sx;
        err += 2 * dy;
    }
    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    Bresenham_Line(-80, -80, 80, 50);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tarun Regmi - Bresenham's Line Drawing Algorithm");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
