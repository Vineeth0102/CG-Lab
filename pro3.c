#include <GL/glut.h> 
#include <math.h> 
 
float red = 1.0f; 
float green = 0.0f; 
float blue = 0.0f; 
 
void initGL() { 
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
    glMatrixMode(GL_PROJECTION); 
    gluPerspective(45.0f, 1.0f, 1.0f, 100.0f); // Perspective projection for 3D view 
    glMatrixMode(GL_MODELVIEW); 
    gluLookAt(1.0f, 1.0f, 3.0f,    // Eye position (slightly to the right and above the object) 
              0.0f, 0.0f, 0.0f,    // Look-at position (centered at the object) 
              0.0f, 1.0f, 0.0f);   // Up vector (positive Y-axis) 
} 
 
void display() { 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Add GL_DEPTH_BUFFER_BIT for depth testing 
 
    glPushMatrix(); 
 
    glBegin(GL_TRIANGLES); 
    glColor3f(red, green, blue); 
    // Front face 
    glVertex3f(0.0f, 0.5f, 0.0f); 
    glVertex3f(-0.5f, -0.5f, 0.5f); 
    glVertex3f(0.5f, -0.5f, 0.5f); 
    // Right face 
    glVertex3f(0.0f, 0.5f, 0.0f); 
    glVertex3f(0.5f, -0.5f, 0.5f); 
    glVertex3f(0.5f, -0.5f, -0.5f); 
    // Back face 
    glVertex3f(0.0f, 0.5f, 0.0f); 
    glVertex3f(0.5f, -0.5f, -0.5f); 
    glVertex3f(-0.5f, -0.5f, -0.5f); 
    // Left face 
    glVertex3f(0.0f, 0.5f, 0.0f); 
    glVertex3f(-0.5f, -0.5f, -0.5f); 
    glVertex3f(-0.5f, -0.5f, 0.5f); 
    glEnd(); 
 
    glPopMatrix(); 
    glutSwapBuffers(); // Use double buffering for smoother animation 
} 
 
void menu(int option) { 
    switch (option) { 
        case 1: 
            red = 1.0f; 
            green = 0.0f; 
            blue = 0.0f; 
            break; 
        case 2: 
            red = 0.0f; 
            green = 1.0f; 
            blue = 0.0f; 
            break; 
        case 3: 
            red = 0.0f; 
            green = 0.0f; 
            blue = 1.0f; 
            break; 
        case 4: 
            red = 1.0f; 
            green = 1.0f; 
            blue = 0.0f; 
            break; 
        case 5: 
            red = 1.0f; 
            green = 0.0f; 
            blue = 1.0f; 
            break; 
        case 6: 
            red = 0.0f; 
            green = 1.0f; 
            blue = 1.0f; 
            break; 
    } 
    glutPostRedisplay(); 
} 
 
 
int main(int argc, char** argv) { 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Enable double buffering and depth testing 
    glutCreateWindow("3D Tetrahedron_4MT21CS138"); 
    glutInitWindowSize(640, 480); 
    glutInitWindowPosition(50, 50); 
    glutDisplayFunc(display); 
    initGL(); 
    glutCreateMenu(menu); 
    glutAddMenuEntry("Red", 1); 
    glutAddMenuEntry("Green", 2); 
    glutAddMenuEntry("Blue", 3); 
    glutAddMenuEntry("Yellow", 4); 
    glutAddMenuEntry("Magenta", 5); 
    glutAddMenuEntry("Cyan", 6); 
 
    glutAttachMenu(GLUT_RIGHT_BUTTON); 
 
    glutMainLoop(); 
 
    return 0; 
} 
