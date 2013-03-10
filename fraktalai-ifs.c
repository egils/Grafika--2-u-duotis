   
    #include <GL/glut.h>
          
    int current = 1;
     
    struct table {
            double a, b, c, d, e, f;
            int p;
            float r, z, m;
    };
     
/*
    static struct table tables[] = {
        {-0.5,   0.0,  0.0,  0.5, -0.5, 0.5, 4, 1.0, 0.0, 0.0 },
        {-0.25, 0.0, 0.0, -0.25, 0.75, 0.75, 1, 0.0, 1.0, 0.0 },
        {0.0,   -0.5, 0.5,  0.0, 0.5, -0.5,  4, 0.0, 0.0, 1.0 },
        {-0.5, -0.0, 0.0,  0.5, -0.5, -0.5,  4, 1.0, 1.0, 0.0}
    };
*/
    static struct table tables[] = {
        {-0.5,  0.0,  0.0,  0.5,  0.5,  0.5, 4, 1, 0, 0},
        {-0.25,  0.0,  0.0, -0.25,  1.0,  1.0, 1, 0, 1, 0 },
        { 0.0,  0.5,  0.5,  0.0,  0.5,  0.0, 4, 0, 0 ,1 },
        { 0.5,  0.0,  0.0,  0.5,  0.0,  0.0, 4, 1, 1, 1 }
    };
     
    static double xx = 0.0;
    static double yy = 0.0;
     
    static double maxX = 0.0;
    static double minX = 0.0;
    static double maxY = 0.0;
    static double minY = 0.0;
     
    static int points = 0;
     
    struct table get_table() {
        
        int r = rand() % 13;
        int sum = 0;
        int x = 0;
        for (; x < 4; x++) {
            sum += tables[x].p;
            if (sum > r) {
                return tables[x];
            }
        }

        return tables[0];
    }
     
    void draw_points() {
            struct table v = get_table();
     
            double x = xx * v.a + yy * v.b + v.e;
            double y = xx * v.c + yy * v.d + v.f;
     
            xx = x;
            yy = y;
     
            if (x > maxX) maxX = x;
            if (x < minX) minX = x;
            if (y > maxY) maxY = y;
            if (y < minY) minY = y;
     
            double dx = maxX - minX;
            double dy = maxY - minY;
     
            double k = dx > dy ? dx : dy;
     
            double realX = x / k * 2 - 1;
            double realY = y / k * 2 - 1;
     
            if (points > 300) {
                    glColor3f(v.r, v.z, v.m);
                    glVertex2f(realX, realY);
            }
    }
     
    void draw() {
            int n = points + 500;
            glBegin(GL_POINTS);
            for (; points < n; points++)
                    draw_points();
            glEnd();
            glFinish();
    }
     
    void resize(int w, int h) {
            glViewport(0, 0, w, h);
    }
     
    void keyboard(unsigned char c, int x, int y) {
            current++;
            draw();
    }
     
    void init() {
            glutReshapeFunc(resize);
            glutKeyboardFunc(keyboard);
            glClear(GL_COLOR_BUFFER_BIT);
            draw();
    }
     
    int main(int argc, char** argv) {
            glutInit(&argc, argv);

            glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
            glutInitWindowSize(600, 600);
            glutInitWindowPosition(0, 0);
            glutCreateWindow("KG 2. Egidijus Lukauskas: 374");
     
            glutDisplayFunc(init);
     
            glutMainLoop();
            return 0;
    }
