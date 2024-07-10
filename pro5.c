#include <GL/glut.h>
#include <math.h>

// Vertex coordinates of the cube
GLfloat vertices[] = {
    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f, 0.5f, -0.5f,
    -0.5f, 0.5f, -0.5f,
    -0.5f, -0.5f, 0.5f,
    0.5f, -0.5f, 0.5f,
    0.5f, 0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f};

// Indices for the cube's faces (using quads)
GLubyte indices[] = {
    0, 1, 2, 3,
    3, 2, 6, 7,
    1, 0, 4, 5,
    2, 1, 5, 6,
    0, 3, 7, 4,
    7, 6, 5, 4};

// Colors for each vertex of the cube (R, G, B, A)
GLfloat colors[] = {
    1.0f, 0.0f, 0.0f, 1.0f,
    1.0f, 1.0f, 0.0f, 1.0f,
    0.0f, 1.0f, 0.0f, 1.0f,
    0.0f, 0.0f, 1.0f, 1.0f,
    1.0f, 0.0f, 1.0f, 1.0f,
    1.0f, 1.0f, 1.0f, 1.0f,
    0.0f, 1.0f, 1.0f, 1.0f,
    0.5f, 0.5f, 0.5f, 1.0f};

// Transformation variables
GLfloat tx = 0.0f;
GLfloat ty = 0.0f;
GLfloat tz = 0.0f;
GLfloat angleX = 0.0f;
GLfloat angleY = 0.0f;
GLfloat angleZ = 0.0f;
GLfloat sx = 1.0f;
GLfloat sy = 1.0f;
GLfloat sz = 1.0f;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPushMatrix();

    glTranslatef(tx, ty, tz);
    glRotatef(angleX, 1.0f, 0.0f, 0.0f);
    glRotatef(angleY, 0.0f, 1.0f, 0.0f);
    glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
    glScalef(sx, sy, sz);

    glBegin(GL_QUADS);
    for (int i = 0; i < 6; ++i)
    {
        // Assign color to each vertex of the quad
        glColor4fv(&colors[i * 4]);
        // Draw the quad using indices
        for (int j = 0; j < 4; ++j)
        {
            glVertex3fv(&vertices[indices[i * 4 + j] * 3]);
        }
    }
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        ty += 0.1f; // Move up
        break;
    case 's':
        ty -= 0.1f; // Move down
        break;
    case 'a':
        tx -= 0.1f; // Move left
        break;
    case 'd':
        tx += 0.1f; // Move right
        break;
    case 'q':
        angleY += 5.0f; // Rotate around Y-axis
        break;
    case 'e':
        angleY -= 5.0f; // Rotate around Y-axis
        break;
    case 'z':
        sx += 0.1f; // Scale on X-axis
        break;
    case 'x':
        sx -= 0.1f; // Scale on X-axis
        break;
    case 'c':
        sy += 0.1f; // Scale on Y-axis
        break;
    case 'v':
        sy -= 0.1f; // Scale on Y-axis
        break;
    case 'i':
        tz -= 0.1f; // Move closer
        break;
    case 'o':
        tz += 0.1f; // Move farther
        break;
    case 'u':
        angleX += 5.0f; // Rotate around X-axis
        break;
    case 'j':
        angleX -= 5.0f; // Rotate around X-axis
        break;
    case 'k':
        angleZ += 5.0f; // Rotate around Z-axis
        break;
    case 'l':
        angleZ -= 5.0f; // Rotate around Z-axis
        break;
    case 27:
        exit(0); // Exit the program
        break;
    }
    glutPostRedisplay();
}

void init()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glViewport(0, 0, 500, 500);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, 1.0f, 1.0f, 100.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3D Cube");

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);

    init();

    glutMainLoop();

    return 0;
}