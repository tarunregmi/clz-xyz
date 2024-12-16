#include <GL/glut.h>

void Midpoint_Ellipse(int xc, int yc, int rx, int ry) {
    float dx, dy, d1, d2;
    int x = 0;
    int y = ry;

    // Initial decision parameter of region 1
    d1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    glBegin(GL_POINTS);
    // Region 1
    while (dx < dy) {
        // Plot the 4 symmetric points
        glVertex2f((xc + x) / 100.0, (yc + y) / 100.0);
        glVertex2f((xc - x) / 100.0, (yc + y) / 100.0);
        glVertex2f((xc + x) / 100.0, (yc - y) / 100.0);
        glVertex2f((xc - x) / 100.0, (yc - y) / 100.0);

        if (d1 < 0) {
            x++;
            dx += 2 * ry * ry;
            d1 += dx + (ry * ry);
        } else {
            x++;
            y--;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d1 += dx - dy + (ry * ry);
        }
    }

    // Initial decision parameter of region 2
    d2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
    // Region 2
    while (y >= 0) {
        // Plot the 4 symmetric points
        glVertex2f((xc + x) / 100.0, (yc + y) / 100.0);
        glVertex2f((xc - x) / 100.0, (yc + y) / 100.0);
        glVertex2f((xc + x) / 100.0, (yc - y) / 100.0);
        glVertex2f((xc - x) / 100.0, (yc - y) / 100.0);

        if (d2 > 0) {
            y--;
            dy -= 2 * rx * rx;
            d2 += (rx * rx) - dy;
        } else {
            y--;
            x++;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            d2 += dx - dy + (rx * rx);
        }
    }
    glEnd();
    glFlush();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    Midpoint_Ellipse(0, 0, 60, 40);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tarun Regmi - Midpoint Ellipse Algorithm");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
