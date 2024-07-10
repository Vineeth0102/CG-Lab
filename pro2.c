#include <GL/glut.h>
// Function to initialize OpenGL settings
void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
    glMatrixMode(GL_PROJECTION);          // To operate on the Projection matrix
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);     // Set the coordinate system for the 2D scene
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.0f, 0.0f); // Red
    glVertex2f(0.0f, 0.5f);
    glColor3f(0.0f, 1.0f, 0.0f); // Green
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0f, 0.0f, 1.0f); // Blue
    glVertex2f(0.5f, -0.5f);
    glEnd();
    glFlush();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("2D Triangle");
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    initGL(); // Our own OpenGL initialization
    glutMainLoop();
    return 0;
}