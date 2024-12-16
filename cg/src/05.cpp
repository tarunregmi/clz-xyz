#include <GL/glut.h>

void setPixel(int x, int y, float r, float g, float b) {
    glBegin(GL_POINTS);
    glColor3f(r, g, b);
    glVertex2i(x, y);
    glEnd();
    glFlush();
}

void getPixelColor(int x, int y, float color[3]) {
    glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, color);
}

void BoundaryFill(int x, int y, float fillColor[3], float boundaryColor[3]) {
    float currentColor[3];
    getPixelColor(x, y, currentColor);

    if ((currentColor[0] != boundaryColor[0] || currentColor[1] != boundaryColor[1] || currentColor[2] != boundaryColor[2]) &&
        (currentColor[0] != fillColor[0] || currentColor[1] != fillColor[1] || currentColor[2] != fillColor[2])) {
        setPixel(x, y, fillColor[0], fillColor[1], fillColor[2]);
        BoundaryFill(x + 1, y, fillColor, boundaryColor);
        BoundaryFill(x - 1, y, fillColor, boundaryColor);
        BoundaryFill(x, y + 1, fillColor, boundaryColor);
        BoundaryFill(x, y - 1, fillColor, boundaryColor);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);

    // Draw a simple polygon (e.g., square)
    glBegin(GL_LINE_LOOP);
    glVertex2i(100, 100);
    glVertex2i(200, 100);
    glVertex2i(200, 200);
    glVertex2i(100, 200);
    glEnd();
    glFlush();

    float fillColor[3] = {0.0, 1.0, 0.0};
    float boundaryColor[3] = {1.0, 0.0, 0.0};
    BoundaryFill(150, 150, fillColor, boundaryColor);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tarun Regmi - Boundary Fill Algorithm");
    gluOrtho2D(0, 500, 0, 500);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
