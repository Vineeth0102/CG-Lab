#include <GL/glut.h>
#include <math.h>
// Angle for rotation
float angle = 0.0;
// Position for translation
float posX = -0.8, posY = 0.0;
// Speed for translation
float speedX = 0.01;
void init()
{
    // Set the background color
    glClearColor(0.0, 0.0, 0.0, 1.0);
}
void display()
{
    // Clear the screen
    glClear(GL_COLOR_BUFFER_BIT);
    // Save the current matrix
    glPushMatrix();
    // Move and draw the triangle
    glTranslatef(posX, posY, 0.0);
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.1, -0.1);
    glVertex2f(0.1, -0.1);
    glVertex2f(0.0, 0.1);
    glEnd();
    // Restore the previous matrix
    glPopMatrix();
    // Save the current matrix
    glPushMatrix();
    // Rotate and draw the square
    glTranslatef(0.5, 0.0, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(-0.1, -0.1);

    glVertex2f(0.1, -0.1);
    glVertex2f(0.1, 0.1);
    glVertex2f(-0.1, 0.1);
    glEnd();
    // Restore the previous matrix
    glPopMatrix();
    // Swap the buffers to display the scene
    glutSwapBuffers();
}
void update(int value)
{
    // Update the rotation angle
    angle += 2.0;
    if (angle > 360)
    {
        angle -= 360;
    }
    // Update the position for translation
    posX += speedX;
    if (posX > 0.8 || posX < -0.8)
    {
        speedX = -speedX;
    }
    // Redraw the scene
    glutPostRedisplay();
    // Call update again after 16 milliseconds
    glutTimerFunc(16, update, 0);
}
int main(int argc, char **argv)
{
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    // Create the window
    glutCreateWindow("Simple Animation");
    // Initialize OpenGL
    init();

    // Set the display function
    glutDisplayFunc(display);
    // Set the update function
    glutTimerFunc(16, update, 0);
    // Start the main loop
    glutMainLoop();
    return 0;
}