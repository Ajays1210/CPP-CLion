#include <iostream>
#include <GL/gl.h>
#include <GL/freeglut.h>
#include <GLFW/glfw3.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    // Initialize GLUT
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Hello freeglut");

    // Register display callback function
    glutDisplayFunc(display);

    // Enter the GLUT event processing loop
    glutMainLoop();

    return 0;
}