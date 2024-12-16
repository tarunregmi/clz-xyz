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

void FloodFill(int x, int y, float fillColor[3], float oldColor[3]) {
    float currentColor[3];
    getPixelColor(x, y, currentColor);

    if ((currentColor[0] == oldColor[0] && currentColor[1] == oldColor[1] && currentColor[2] == oldColor[2]) &&
        (currentColor[0] != fillColor[0] || currentColor[1] != fillColor[1] || currentColor[2] != fillColor[2])) {
        setPixel(x, y, fillColor[0], fillColor[1], fillColor[2]);
        FloodFill(x + 1, y, fillColor, oldColor);
        FloodFill(x - 1, y, fillColor, oldColor);
        FloodFill(x, y + 1, fillColor, oldColor);
        FloodFill(x, y - 1, fillColor, oldColor);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(150, 150);
    glVertex2i(300, 150);
    glVertex2i(225, 300);
    glEnd();
    glFlush();

    float fillColor[3] = {1.0, 0.0, 0.0};
    float oldColor[3] = {1.0, 1.0, 1.0};
    FloodFill(200, 200, fillColor, oldColor);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tarun Regmi - Flood Fill Algorithm");
    gluOrtho2D(0, 500, 0, 500);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
