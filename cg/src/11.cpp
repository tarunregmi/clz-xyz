#include <GL/glut.h>
#include <iostream>

struct Point {
    float x, y;
};

// Define the clip window (x_min, y_min, x_max, y_max)
const float x_min = 100, y_min = 100, x_max = 400, y_max = 400;

// Define the outcode values
#define INSIDE 0  // 0000
#define LEFT 1    // 0001
#define RIGHT 2   // 0010
#define BOTTOM 4  // 0100
#define TOP 8     // 1000

// Function to compute the outcode for a point
int computeOutcode(Point p) {
    int outcode = INSIDE;

    if (p.x < x_min) outcode |= LEFT;
    else if (p.x > x_max) outcode |= RIGHT;
    if (p.y < y_min) outcode |= BOTTOM;
    else if (p.y > y_max) outcode |= TOP;

    return outcode;
}

// Function to implement the Cohen-Sutherland Line Clipping algorithm
void cohenSutherlandClip(Point p1, Point p2) {
    int outcode1 = computeOutcode(p1);
    int outcode2 = computeOutcode(p2);
    bool accept = false;

    while (true) {
        if ((outcode1 == 0) && (outcode2 == 0)) {
            accept = true;
            break;
        } else if (outcode1 & outcode2) {
            break;
        } else {
            int outcodeOut;
            float x, y;

            if (outcode1 != 0)  outcodeOut = outcode1;
            else outcodeOut = outcode2;

            if (outcodeOut & TOP) {
                x = p1.x + (p2.x - p1.x) * (y_max - p1.y) / (p2.y - p1.y);
                y = y_max;
            } else if (outcodeOut & BOTTOM) {
                x = p1.x + (p2.x - p1.x) * (y_min - p1.y) / (p2.y - p1.y);
                y = y_min;
            } else if (outcodeOut & RIGHT) {
                y = p1.y + (p2.y - p1.y) * (x_max - p1.x) / (p2.x - p1.x);
                x = x_max;
            } else if (outcodeOut & LEFT) {
                y = p1.y + (p2.y - p1.y) * (x_min - p1.x) / (p2.x - p1.x);
                x = x_min;
            }

            if (outcodeOut == outcode1) {
                p1.x = x;
                p1.y = y;
                outcode1 = computeOutcode(p1);
            } else {
                p2.x = x;
                p2.y = y;
                outcode2 = computeOutcode(p2);
            }
        }
    }

    if (accept) {
        glBegin(GL_LINES);
        glVertex2f(p1.x, p1.y);
        glVertex2f(p2.x, p2.y);
        glEnd();
        glFlush();
    }
}

void drawClipWindow() {
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(x_min, y_min);
    glVertex2f(x_max, y_min);
    glVertex2f(x_max, y_max);
    glVertex2f(x_min, y_max);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawClipWindow();
    Point p1 = {50, 50};
    Point p2 = {450, 450};
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
    glEnd();
    cohenSutherlandClip(p1, p2);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tarun Regmi - Cohen-Sutherland Line Clipping");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
