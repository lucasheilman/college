#include<iostream>
#include<fstream>
using namespace std;
#ifdef MACOSX
#include<GLUT/glut.h>
#else
#include<GL/glut.h>
#endif
#include<math.h>
#include<stdlib.h>
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"

Shape *userShape[10000];
int numUserShapes = 0;
int  numColorButtons;
Shape ** colorButtonForeground;
Shape ** colorButtonBackground;
Shape * currentColorButton;
Color currentColor;

bool mouseIsDragging = false;

int WIDTH = 720;  // width of the user window (640 + 80)
int HEIGHT = 540;  // height of the user window (480 + 60)
char programName[] = "proto-draw";

enum ModeType{CIRCLE,RECTANGLE};
ModeType currentMode = CIRCLE;

void handleColorButtonPress(int x, int y)
{
  // figure out if we have pressed a color button
  int i;
  for ( i = 0; i < numColorButtons; ++i )
    if ( colorButtonBackground[i]->containsPoint(x,y) ) break;

  // if a button was pressed, show which one
  if ( i < numColorButtons ) {
    if ( currentColorButton ){
      Color co1;
      co1.red = 128;
      co1.green = 128;
      co1.blue = 128;
      currentColorButton->setColor(co1);
    }
    currentColorButton = colorButtonBackground[i];
    Color co2;
    co2.red = 255;
    co2.green = 0;
    co2.blue = 0;
    currentColorButton->setColor(co2);
    // change the current color
    currentColor = colorButtonForeground[i]->getColor();
  }
}

void loadColorButtons(const char * filename){
  ifstream g(filename);
  if (! g.good()){
    cerr << "BAD" << endl;
  }
  g >> numColorButtons;
  numColorButtons = numColorButtons/2;
  colorButtonBackground = new Shape*[numColorButtons];
  colorButtonForeground = new Shape*[numColorButtons];
  for(int i = 0; i < numColorButtons; i++){
    char shape[64];
    g >> shape;
    colorButtonBackground[i] = new Rectangle(g);
    char shape2[64];
    g >> shape2;
    colorButtonForeground[i] = new Rectangle(g);
    }
  cout << "it loaded this many shapes: " << numColorButtons << endl;
  g.close();
}
  
void drawWindow()
{
  // clear the buffer
  glClear(GL_COLOR_BUFFER_BIT);
  for(int i = 0; i < numUserShapes; i++){
    userShape[i]->draw();
  }
  for(int a = 0; a < numColorButtons; a++){
    colorButtonBackground[a]->draw();
    colorButtonForeground[a]->draw();
  }
  // draw stuff

  // tell the graphics card that we're done-- go ahead and draw!
  //   (technically, we are switching between two color buffers...)
  glutSwapBuffers();
}

// process keyboard events
void keyboard( unsigned char c, int x, int y )
{
  int win = glutGetWindow();
  switch(c) {
    case 'c':
      currentMode = CIRCLE;
      cout << "changing to circle mode." << endl;
      break;
    case 'r':
      currentMode = RECTANGLE;
      cout << "changing to rectangle mode." << endl;
      break;
    case 'q':
    case 'Q':
    case 27:
      // get rid of the window (as part of shutting down)
      glutDestroyWindow(win);
      exit(0);
      break;
    default:
      break;
  }
  glutPostRedisplay();
}

// the reshape function handles the case where the user changes the size
//   of the window.  We need to fix the coordinate
//   system, so that the drawing area is still the unit square.
void reshape(int w, int h)
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);
   WIDTH = w;  HEIGHT = h;
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(0., WIDTH-1, HEIGHT-1, 0., -1.0, 1.0);
}

// the mouse function is called when a mouse button is pressed down or released
void mouse(int button, int state, int x, int y)
{
  if ( GLUT_LEFT_BUTTON == button ) {
    if ( GLUT_DOWN == state ) {
      mouseIsDragging = true;
      handleColorButtonPress(x,y);
      // the user just pressed down on the mouse-- do something
      if (currentMode == RECTANGLE){
	Rectangle *r;
	r = new Rectangle;
	userShape[numUserShapes] = r;
      }
      else if(currentMode == CIRCLE) {
	Circle *c;
	c = new Circle;
	userShape[numUserShapes] = c;
      }
      userShape[numUserShapes]->setColor(currentColor);
      userShape[numUserShapes]->setPosition(x,y);
      numUserShapes++;
      //userShape[numUserShapes]->display();
    }
    else {
      // the user just let go the mouse-- do something
      if (numUserShapes>0)
	userShape[numUserShapes-1]->update(x,y);
      mouseIsDragging = false;
    }
  } else if ( GLUT_RIGHT_BUTTON == button ) {
  }
  glutPostRedisplay();
}
// the mouse_motion function is called when the mouse is being dragged,
//   and gives the current location of the mouse
void mouse_motion(int x,int y)
{
  if (numUserShapes>0)
    userShape[numUserShapes-1]->update(x,y);
  // the mouse button is pressed, and the mouse is moving....
  glutPostRedisplay();
}

// the init function sets up the graphics card to draw properly
void init(void)
{
  // clear the window to black
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);

  // set up the coordinate system:  number of pixels along x and y
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0., WIDTH-1, HEIGHT-1, 0., -1.0, 1.0);

  // welcome message
  cout << "Welcome to " << programName << "." << endl;
}


// init_gl_window is the function that starts the ball rolling, in
//  terms of getting everything set up and passing control over to the
//  glut library for event handling.  It needs to tell the glut library
//  about all the essential functions:  what function to call if the
//  window changes shape, what to do to redraw, handle the keyboard,
//  etc.
void init_gl_window()
{
  char *argv[] = {programName};
  int argc = sizeof(argv) / sizeof(argv[0]);
  glutInit(&argc, argv);
  glutInitDisplayMode( GLUT_RGB | GLUT_DOUBLE );
  glutInitWindowSize(WIDTH,HEIGHT);
  glutInitWindowPosition(100,100);
  glutCreateWindow(programName);
  init();

  glutDisplayFunc(drawWindow);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard);
  glutMouseFunc(mouse);
  glutMotionFunc(mouse_motion);
  glutMainLoop();
}

int main()
{
  loadColorButtons("colorButtons.txt");
  init_gl_window();
}
