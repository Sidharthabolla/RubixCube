#ifndef _MODELER_GLOBALS_H
#define _MODELER_GLOBALS_H

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif

// This is a list of the controls for the SampleModel
// We'll use these constants to access the values 
// of the controls from the user interface.
enum SampleModelControls
{ 
	XPOS, YPOS, ZPOS, HEIGHT, XROTATEU, XROTATEM, XROTATEL, YROTATEL,YROTATEM,YROTATEU,ZROTATEL,ZROTATEM,ZROTATEU, NUMCONTROLS
};

// Colors
#define COLOR_RED		1.0f, 0.0f, 0.0f
#define COLOR_GREEN		0.0f, 1.0f, 0.0f
#define COLOR_BLUE		0.0f, 0.0f, 1.0f
#define COLOR_WHITE		2.0f, 2.0f, 2.0f
#define COLOR_ORANGE    2.0f, 0.7f, 0.0f
#define COLOR_YELLOW	2.0f, 2.0f, 0.0f
#define COLOR_BLACK		2.0f, 0.0f, 2.0f



// We'll be getting the instance of the application a lot; 
// might as well have it as a macro.
#define VAL(x) (ModelerApplication::Instance()->GetControlValue(x))

#endif