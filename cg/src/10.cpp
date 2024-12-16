#include <GL/glut.h>
#include <vector>
#include <cmath>

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

std::vector<Point> rotatePolygon(const std::vector<Point>& points, float angle) {
    float radians = angle * M_PI / 180.0f;
    std::vector<Point> rotatedPolygon;
    
    for (const auto& point : points) {
        float xNew = point.x * cos(radians) - point.y * sin(radians);
        float yNew = point.x * sin(radians) + point.y * cos(radians);
        rotatedPolygon.push_back({xNew, yNew});
    }
    
    return rotatedPolygon;
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    drawPolygon(polygon);
    float angle = 45.0f;
    std::vector<Point> rotatedPolygon = rotatePolygon(polygon, angle);
    glColor3f(0.0, 0.0, 1.0);
    drawPolygon(rotatedPolygon);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tarun Regmi - 2D Rotation");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
