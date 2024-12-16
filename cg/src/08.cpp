#include <GL/glut.h>
#include <vector>

struct Point {
    float x, y;
};

std::vector<Point> polygon = {
    {100, 100}, {200, 100}, {200, 200}, {100, 200}
};

void drawPolygon(const std::vector<Point>& points) {
    glBegin(GL_LINE_LOOP);
    for (const auto& point : points) {
        glVertex2f(point.x, point.y);
    }
    glEnd();
    glFlush();
}

std::vector<Point> translatePolygon(const std::vector<Point>& points, float tx, float ty) {
    std::vector<Point> translatedPolygon;
    for (const auto& point : points) {
        translatedPolygon.push_back({point.x + tx, point.y + ty});
    }
    return translatedPolygon;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    drawPolygon(polygon);

    // Translate the polygon by (tx, ty)
    float tx = 50;
    float ty = 50;
    std::vector<Point> translatedPolygon = translatePolygon(polygon, tx, ty);
    glColor3f(0.0, 0.0, 1.0);
    drawPolygon(translatedPolygon);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tarun Regmi - 2D Translation");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
