#include <GL/glut.h>
#include <vector>
#include <algorithm>

struct Edge {
    int yMax;
    float xOfYMin;
    float slopeInverse;
};

std::vector<Edge> edgeTable[500];

void initEdgeTable() {
    for (int i = 0; i < 500; ++i) edgeTable[i].clear();
}

void insertEdge(int yMin, int yMax, float x, float slopeInverse) {
    if (yMin < 500) {
        Edge newEdge = { yMax, x, slopeInverse };
        edgeTable[yMin].push_back(newEdge);
    }
}

void createEdgeTable(std::vector<std::pair<int, int>> vertices) {
    int n = vertices.size();
    for (int i = 0; i < n; ++i) {
        int x1 = vertices[i].first;
        int y1 = vertices[i].second;
        int x2 = vertices[(i + 1) % n].first;
        int y2 = vertices[(i + 1) % n].second;

        if (y1 == y2) continue;

        if (y1 > y2) {
            std::swap(x1, x2);
            std::swap(y1, y2);
        }

        float slopeInverse = (x2 - x1) / (float)(y2 - y1);
        insertEdge(y1, y2, x1, slopeInverse);
    }
}

void drawScanLinePolygon(std::vector<std::pair<int, int>> vertices) {
    initEdgeTable();
    createEdgeTable(vertices);

    std::vector<Edge> activeEdgeTable;

    for (int y = 0; y < 500; ++y) {
        for (Edge &edge : edgeTable[y]) {
            activeEdgeTable.push_back(edge);
        }

        activeEdgeTable.erase(std::remove_if(activeEdgeTable.begin(), activeEdgeTable.end(),
            [y](Edge &edge) { return edge.yMax <= y; }), activeEdgeTable.end());

        std::sort(activeEdgeTable.begin(), activeEdgeTable.end(),
            [](Edge &e1, Edge &e2) { return e1.xOfYMin < e2.xOfYMin; });

        glBegin(GL_LINES);
        for (size_t i = 0; i < activeEdgeTable.size(); i += 2) {
            if (i + 1 < activeEdgeTable.size()) {
                glVertex2i((int)activeEdgeTable[i].xOfYMin, y);
                glVertex2i((int)activeEdgeTable[i + 1].xOfYMin, y);
            }
        }
        glEnd();
        glFlush();

        for (Edge &edge : activeEdgeTable) {
            edge.xOfYMin += edge.slopeInverse;
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);

    std::vector<std::pair<int, int>> vertices = {
        {100, 100}, {200, 300}, {300, 100}, {250, 150}
    };

    drawScanLinePolygon(vertices);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tarun Regmi - Scan Line Polygon Filling Algorithm");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(0, 500, 0, 500);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
