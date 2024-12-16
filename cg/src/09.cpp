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

std::vector<Point> scalePolygon(const std::vector<Point>& points, float sx, float sy) {
    std::vector<Point> scaledPolygon;
    for (const auto& point : points) {
        scaledPolygon.push_back({point.x * sx, point.y * sy});
    }
    return scaledPolygon;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    drawPolygon(polygon);

    // Scale the polygon by (sx, sy)
    float sx = 1.5;
    float sy = 1.5;
    std::vector<Point> scaledPolygon = scalePolygon(polygon, sx, sy);
    glColor3f(0.0, 0.0, 1.0);
    drawPolygon(scaledPolygon);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2D Scaling");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
