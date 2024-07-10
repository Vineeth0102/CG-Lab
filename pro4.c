#include <GL/glut.h>
#include <math.h>

// Initial size of the window
int width = 800, height = 600;

// Transformation parameters
float tx = 0.0f, ty = 0.0f; // Translation
float sx = 1.0f, sy = 1.0f; // Scaling
float angle = 0.0f;         // Rotation angle in degrees

// Function prototypes
void display();
void reshape(int w, int h);
void keyboard(unsigned char key, int x, int y);
void drawSquare();

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutCreateWindow("2D Transformations using OpenGL");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
    return 0;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    // Apply transformations
    glTranslatef(tx, ty, 0.0f);
    glScalef(sx, sy, 1.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);

    // Draw the square
    drawSquare();

    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400.0, 400.0, -300.0, 300.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        ty += 10.0f;
        break; // Move up
    case 's':
        ty -= 10.0f;
        break; // Move down
    case 'a':
        tx -= 10.0f;
        break; // Move left
    case 'd':
        tx += 10.0f;
        break; // Move right
    case '+':
        sx += 0.1f;
        sy += 0.1f;
        break; // Scale up
    case '-':
        sx -= 0.1f;
        sy -= 0.1f;
        break; // Scale down
    case 'r':
        angle += 10.0f;
        break; // Rotate clockwise
    case 'l':
        angle -= 10.0f;
        break; // Rotate counterclockwise
    case 27:
        exit(0); // ESC key to exit
    }
    glutPostRedisplay();
}

void drawSquare()
{
    glBegin(GL_QUADS);
    glVertex2f(-50.0f, -50.0f);
    glVertex2f(50.0f, -50.0f);
    glVertex2f(50.0f, 50.0f);
    glVertex2f(-50.0f, 50.0f);
    glEnd();
}