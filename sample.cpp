// The sample model.  You should build a file
// very similar to this for when you make your model.
#include "modelerview.h"
#include "modelerapp.h"
#include "modelerdraw.h"
#include <FL/gl.h>
#include <math.h>



#include "modelerglobals.h"

// To make a SampleModel, we inherit off of ModelerView
class SampleModel : public ModelerView 
{
public:
    SampleModel(int x, int y, int w, int h, char *label) 
        : ModelerView(x,y,w,h,label) { }

    virtual void draw();
};

double time = 0.0;

// We need to make a creator function, mostly because of
// nasty API stuff that we'd rather stay away from.
ModelerView* createSampleModel(int x, int y, int w, int h, char *label)
{ 
    return new SampleModel(x,y,w,h,label); 
}

// We are going to override (is that the right word?) the draw()
// method of ModelerView to draw out SampleModel
void SampleModel::draw()
{
    // This call takes care of a lot of the nasty projection 
    // matrix stuff.  Unless you want to fudge directly with the 
	// projection matrix, don't bother with this ...
    ModelerView::draw();

	if(ModelerApplication::Instance()->ModelerApplication::m_animating) time++;
	else time = 0;

		// draw the sample model
	setAmbientColor(.1f,.1f,.1f);
glPushMatrix();
			glTranslated(0,-1,0);
			glTranslated(VAL(XPOS), VAL(YPOS), VAL(ZPOS));
//TAB 1			
	//BOTTOM
	glPushMatrix();					
									
									glRotated(time *4, 0.0, 1.0, 0.0); glRotated(VAL(YROTATEL), 0.0, 1.0, 0.0);
									glTranslated(-1.5,0,0.5);		
	//box1	
									setDiffuseColor(COLOR_WHITE);
		glPushMatrix();
									glTranslated(0,1.5,-0.5);
									glRotated(VAL(XROTATEU), 1.0, 0.0, 0.0);
									glTranslated(0,-1.5,0.5);
									drawBox(1,1,1);				
			glPushMatrix();
				glPushMatrix();
									glTranslated(0.1,0.1,1);
									setDiffuseColor(COLOR_BLUE);
									glScaled(2,2,1);
									drawBox(0.4,0.4,0.1);
				glPopMatrix();
				glPushMatrix();
									glTranslated(0.1,-0.1,0.1);
									setDiffuseColor(COLOR_RED);
									drawBox(0.8,0.1,0.8);
				glPopMatrix();
				glPushMatrix();
									glTranslated(-0.1,0.1,0.1);
									setDiffuseColor(COLOR_YELLOW);
									drawBox(0.1,0.8,0.8);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

	//box2
	glPushMatrix();
									glTranslated(1,0,0);
									setDiffuseColor(COLOR_WHITE);
		glPushMatrix();
									glTranslated(0,1.5,-0.5);
									glRotated(VAL(XROTATEM), 1.0, 0.0, 0.0);
									glTranslated(0,-1.5,0.5);
									drawBox(1,1,1);
			glPushMatrix();
				glPushMatrix();
									glTranslated(0.1,0.1,1);
									setDiffuseColor(COLOR_BLUE);
									drawBox(0.8,0.8,0.1);
				glPopMatrix();
				glPushMatrix();
									glTranslated(0.1,-0.1,0.1);
									setDiffuseColor(COLOR_RED);
									drawBox(0.8,0.1,0.8);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	//box3
		glPushMatrix();
									glTranslated(1,0,0);
									setDiffuseColor(COLOR_WHITE);
			glPushMatrix();
									glTranslated(0,1.5,-0.5);
									glRotated(VAL(XROTATEL), 1.0, 0.0, 0.0);
									glTranslated(0,-1.5,0.5);
									drawBox(1,1,1);
				glPushMatrix();
									glTranslated(0.1,0.1,1);
									setDiffuseColor(COLOR_BLUE);
									drawBox(0.8,0.8,0.1);
				glPopMatrix();
				glPushMatrix();
									glTranslated(0.1,-0.1,0.1);
									setDiffuseColor(COLOR_RED);
									drawBox(0.8,0.1,0.8);
				glPopMatrix();
				glPushMatrix();
									glTranslated(1,0.1,0.1);
									setDiffuseColor(COLOR_BLACK);
									drawBox(0.1,0.8,0.8);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
glPopMatrix();
//MIDDLE
	glPushMatrix();
									glTranslated(0,1,0);
									glRotated(VAL(YROTATEM), 0.0, 1.0, 0.0);
									glTranslated(-1.5,0,0.5);
		glPushMatrix();
	//box1
									glTranslated(0,0,0);
									setDiffuseColor(COLOR_WHITE);
			glPushMatrix();
									glTranslated(0,0.5,-0.5);
									glRotated(VAL(XROTATEU), 1.0, 0.0, 0.0);
									glTranslated(0,-0.5,0.5);
									drawBox(1,1,1);
				glPushMatrix();
					glPushMatrix();
									glTranslated(0.1,0.1,1);
									setDiffuseColor(COLOR_BLUE);
									drawBox(0.8,0.8,0.1);
					glPopMatrix();
					glPushMatrix();
									glTranslated(-0.1,0.1,0.1);
									setDiffuseColor(COLOR_RED);
					glPopMatrix();
					glPushMatrix();
									glTranslated(-0.1,0.1,0.1);
									setDiffuseColor(COLOR_YELLOW);
									drawBox(0.1,0.8,0.8);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
	//box2
									glTranslated(1,0,0);
									setDiffuseColor(COLOR_WHITE);
			glPushMatrix();
									glTranslated(0,0.5,-0.5);
									glRotated(VAL(XROTATEM), 1.0, 0.0, 0.0);
									glTranslated(0,-0.5,0.5);
									drawBox(1,1,1);
				glPushMatrix();
									glTranslated(0.1,0.1,1);
									setDiffuseColor(COLOR_BLUE);
									drawBox(0.8,0.8,0.1);
				glPopMatrix();
			glPopMatrix();
	//box3
									glTranslated(1,0,0);
									setDiffuseColor(COLOR_WHITE);
			glPushMatrix();
									glTranslated(0,0.5,-0.5);
									glRotated(VAL(XROTATEL), 1.0, 0.0, 0.0);
									glTranslated(0,-0.5,0.5);
									drawBox(1,1,1);
				glPushMatrix();
					glPushMatrix();
									glTranslated(0.1,0.1,1);
									setDiffuseColor(COLOR_BLUE);
									drawBox(0.8,0.8,0.1);
					glPopMatrix();
					glPushMatrix();
									glTranslated(1,0.1,0.1);
									setDiffuseColor(COLOR_BLACK);
									drawBox(0.1,0.8,0.8);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
//UPPER
		glPushMatrix();
				glRotated(VAL(YROTATEU), 0.0, 1.0, 0.0);
				glTranslated(-1.5,2,0.5);
				glPushMatrix();
	//box1
					glTranslated(0,0,0);
					setDiffuseColor(COLOR_WHITE);
					glPushMatrix();
					glTranslated(0,-0.5,-0.5);
						glRotated(VAL(XROTATEU), 1.0, 0.0, 0.0);
						glTranslated(0,0.5,0.5);
							drawBox(1,1,1);
							glPushMatrix();
							glPushMatrix();
								glTranslated(0.1,0.1,1);
								setDiffuseColor(COLOR_BLUE);
								drawBox(0.8,0.8,0.1);
							glPopMatrix();
							glPushMatrix();
								glTranslated(0.1,1,0.1);
								setDiffuseColor(COLOR_ORANGE);
								drawBox(0.8,0.1,0.8);
							glPopMatrix();
							glPushMatrix();
								glTranslated(-0.1,0.1,0.1);
								setDiffuseColor(COLOR_YELLOW);
								drawBox(0.1,0.8,0.8);
							glPopMatrix();
						glPopMatrix();
						glPopMatrix();
	//box2
					glTranslated(1,0,0);
					setDiffuseColor(COLOR_WHITE);
					glPushMatrix();
					glTranslated(0,-0.5,-0.5);
						glRotated(VAL(XROTATEM), 1.0, 0.0, 0.0);
						glTranslated(0,0.5,0.5);
					drawBox(1,1,1);
					glPushMatrix();
						glPushMatrix();
							glTranslated(0.1,0.1,1);
							setDiffuseColor(COLOR_BLUE);
							drawBox(0.8,0.8,0.1);
						glPopMatrix();
						glPushMatrix();
							glTranslated(0.1,1,0.1);
							setDiffuseColor(COLOR_ORANGE);
							drawBox(0.8,0.1,0.8);
						glPopMatrix();
								glPopMatrix();
					glPopMatrix();
	//box3
					glTranslated(1,0,0);
					setDiffuseColor(COLOR_WHITE);
					glPushMatrix();
					glTranslated(0,-0.5,-0.5);
						glRotated(VAL(XROTATEL), 1.0, 0.0, 0.0);
						glTranslated(0,0.5,0.5);
					drawBox(1,1,1);
					glPushMatrix();
						glPushMatrix();
							glTranslated(0.1,0.1,1);
							setDiffuseColor(COLOR_BLUE);
							drawBox(0.8,0.8,0.1);
						glPopMatrix();
						glPushMatrix();
							glTranslated(0.1,1,0.1);
							setDiffuseColor(COLOR_ORANGE);
							drawBox(0.8,0.1,0.8);
						glPopMatrix();
						glPushMatrix();
							glTranslated(1,0.1,0.1);
							setDiffuseColor(COLOR_BLACK);
							drawBox(0.1,0.8,0.8);
						glPopMatrix();
					glPopMatrix();
							glPopMatrix();
				glPopMatrix();	
				glPopMatrix();
				glPopMatrix();
//TAB 2		
	//BOTTOM
	glPushMatrix();
	glTranslated(0,-1,-1);
	glPushMatrix();					
									glTranslated(0,0,1);
									glRotated(time *4, 0.0, 1.0, 0.0); glRotated(VAL(YROTATEL), 0.0, 1.0, 0.0);
									glTranslated(0,0,-1);
									glTranslated(-1.5,0,0.5);		
	//box1	
									setDiffuseColor(COLOR_WHITE);
		glPushMatrix();
									glTranslated(0,1.5,0.5);
									glRotated(VAL(XROTATEU), 1.0, 0.0, 0.0);
									glTranslated(0,-1.5,-0.5);
									drawBox(1,1,1);				
			glPushMatrix();
				glPushMatrix();
									glTranslated(0.1,0.1,1);
									setDiffuseColor(COLOR_BLUE);
									glScaled(2,2,1);
									drawBox(0.4,0.4,0.1);
				glPopMatrix();
				glPushMatrix();
									glTranslated(0.1,-0.1,0.1);
									setDiffuseColor(COLOR_RED);
									drawBox(0.8,0.1,0.8);
				glPopMatrix();
				glPushMatrix();
									glTranslated(-0.1,0.1,0.1);
									setDiffuseColor(COLOR_YELLOW);
									drawBox(0.1,0.8,0.8);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

	//box2
	glPushMatrix();
									glTranslated(1,0,0);
									setDiffuseColor(COLOR_WHITE);
		glPushMatrix();
									glTranslated(0,1.5,0.5);
									glRotated(VAL(XROTATEM), 1.0, 0.0, 0.0);
									glTranslated(0,-1.5,-0.5);
									drawBox(1,1,1);
			glPushMatrix();
				glPushMatrix();
									glTranslated(0.1,0.1,1);
									setDiffuseColor(COLOR_BLUE);
									drawBox(0.8,0.8,0.1);
				glPopMatrix();
				glPushMatrix();
									glTranslated(0.1,-0.1,0.1);
									setDiffuseColor(COLOR_RED);
									drawBox(0.8,0.1,0.8);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	//box3
		glPushMatrix();
									glTranslated(1,0,0);
									setDiffuseColor(COLOR_WHITE);
			glPushMatrix();
									glTranslated(0,1.5,0.5);
									glRotated(VAL(XROTATEL), 1.0, 0.0, 0.0);
									glTranslated(0,-1.5,-0.5);
									drawBox(1,1,1);
				glPushMatrix();
									glTranslated(0.1,0.1,1);
									setDiffuseColor(COLOR_BLUE);
									drawBox(0.8,0.8,0.1);
				glPopMatrix();
				glPushMatrix();
									glTranslated(0.1,-0.1,0.1);
									setDiffuseColor(COLOR_RED);
									drawBox(0.8,0.1,0.8);
				glPopMatrix();
				glPushMatrix();
									glTranslated(1,0.1,0.1);
									setDiffuseColor(COLOR_BLACK);
									drawBox(0.1,0.8,0.8);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
glPopMatrix();
//MIDDLE
	glPushMatrix();
									glTranslated(0,1,0);
									glTranslated(0,0,1);
									glRotated(VAL(YROTATEM), 0.0, 1.0, 0.0);
									glTranslated(0,0,-1);
									glTranslated(-1.5,0,0.5);
		glPushMatrix();
	//box1
									glTranslated(0,0,0);
									setDiffuseColor(COLOR_WHITE);
			glPushMatrix();
									glTranslated(0,0.5,0.5);
									glRotated(VAL(XROTATEU), 1.0, 0.0, 0.0);
									glTranslated(0,-0.5,-0.5);
									drawBox(1,1,1);
				glPushMatrix();
					glPushMatrix();
									glTranslated(0.1,0.1,1);
									setDiffuseColor(COLOR_BLUE);
									drawBox(0.8,0.8,0.1);
					glPopMatrix();
					glPushMatrix();
									glTranslated(-0.1,0.1,0.1);
									setDiffuseColor(COLOR_RED);
					glPopMatrix();
					glPushMatrix();
									glTranslated(-0.1,0.1,0.1);
									setDiffuseColor(COLOR_YELLOW);
									drawBox(0.1,0.8,0.8);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
	//box2
									glTranslated(1,0,0);
									setDiffuseColor(COLOR_WHITE);
			glPushMatrix();
									glTranslated(0,0.5,0.5);
									glRotated(VAL(XROTATEM), 1.0, 0.0, 0.0);
									glTranslated(0,-0.5,-0.5);
									drawBox(1,1,1);
				glPushMatrix();
									glTranslated(0.1,0.1,1);
									setDiffuseColor(COLOR_BLUE);
									drawBox(0.8,0.8,0.1);
				glPopMatrix();
			glPopMatrix();
	//box3
									glTranslated(1,0,0);
									setDiffuseColor(COLOR_WHITE);
			glPushMatrix();
									glTranslated(0,0.5,0.5);
									glRotated(VAL(XROTATEL), 1.0, 0.0, 0.0);
									glTranslated(0,-0.5,-0.5);
									drawBox(1,1,1);
				glPushMatrix();
					glPushMatrix();
									glTranslated(0.1,0.1,1);
									setDiffuseColor(COLOR_BLUE);
									drawBox(0.8,0.8,0.1);
					glPopMatrix();
					glPushMatrix();
									glTranslated(1,0.1,0.1);
									setDiffuseColor(COLOR_BLACK);
									drawBox(0.1,0.8,0.8);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
//UPPER
		glPushMatrix();
				glTranslated(0,0,1);
									glRotated(VAL(YROTATEU), 0.0, 1.0, 0.0);
									glTranslated(0,0,-1);
				glTranslated(-1.5,2,0.5);
				glPushMatrix();
	//box1
					glTranslated(0,0,0);
					setDiffuseColor(COLOR_WHITE);
					glPushMatrix();
					glTranslated(0,-0.5,0.5);
						glRotated(VAL(XROTATEU), 1.0, 0.0, 0.0);
						glTranslated(0,0.5,-0.5);
							drawBox(1,1,1);
							glPushMatrix();
							glPushMatrix();
								glTranslated(0.1,0.1,1);
								setDiffuseColor(COLOR_BLUE);
								drawBox(0.8,0.8,0.1);
							glPopMatrix();
							glPushMatrix();
								glTranslated(0.1,1,0.1);
								setDiffuseColor(COLOR_ORANGE);
								drawBox(0.8,0.1,0.8);
							glPopMatrix();
							glPushMatrix();
								glTranslated(-0.1,0.1,0.1);
								setDiffuseColor(COLOR_YELLOW);
								drawBox(0.1,0.8,0.8);
							glPopMatrix();
						glPopMatrix();
						glPopMatrix();
	//box2
					glTranslated(1,0,0);
					setDiffuseColor(COLOR_WHITE);
					glPushMatrix();
					glTranslated(0,-0.5,0.5);
						glRotated(VAL(XROTATEM), 1.0, 0.0, 0.0);
						glTranslated(0,0.5,-0.5);
					drawBox(1,1,1);
					glPushMatrix();
						glPushMatrix();
							glTranslated(0.1,0.1,1);
							setDiffuseColor(COLOR_BLUE);
							drawBox(0.8,0.8,0.1);
						glPopMatrix();
						glPushMatrix();
							glTranslated(0.1,1,0.1);
							setDiffuseColor(COLOR_ORANGE);
							drawBox(0.8,0.1,0.8);
						glPopMatrix();
								glPopMatrix();
					glPopMatrix();
	//box3
					glTranslated(1,0,0);
					setDiffuseColor(COLOR_WHITE);
					glPushMatrix();
					glTranslated(0,-0.5,0.5);
						glRotated(VAL(XROTATEL), 1.0, 0.0, 0.0);
						glTranslated(0,0.5,-0.5);
					drawBox(1,1,1);
					glPushMatrix();
						glPushMatrix();
							glTranslated(0.1,0.1,1);
							setDiffuseColor(COLOR_BLUE);
							drawBox(0.8,0.8,0.1);
						glPopMatrix();
						glPushMatrix();
							glTranslated(0.1,1,0.1);
							setDiffuseColor(COLOR_ORANGE);
							drawBox(0.8,0.1,0.8);
						glPopMatrix();
						glPushMatrix();
							glTranslated(1,0.1,0.1);
							setDiffuseColor(COLOR_BLACK);
							drawBox(0.1,0.8,0.8);
						glPopMatrix();
					glPopMatrix();
							glPopMatrix();
				glPopMatrix();	
				glPopMatrix();
				glPopMatrix();
				glPopMatrix();
//TAB 3			
	//BOTTOM
	glPushMatrix();
	glTranslated(0,-1,-2);
	glPushMatrix();
									glTranslated(0,0,2);
									glRotated(time *4, 0.0, 1.0, 0.0); glRotated(VAL(YROTATEL), 0.0, 1.0, 0.0);
									glTranslated(0,0,-2);
									glTranslated(-1.5,0,0.5);		
	//box1	
									setDiffuseColor(COLOR_WHITE);
		glPushMatrix();
									glTranslated(0,1.5,1.5);
									glRotated(VAL(XROTATEU), 1.0, 0.0, 0.0);
									glTranslated(0,-1.5,-1.5);
									drawBox(1,1,1);				
			glPushMatrix();
				glPushMatrix();
									glTranslated(0.1,0.1,-0.1);
									setDiffuseColor(COLOR_GREEN);
									glScaled(2,2,1);
									drawBox(0.4,0.4,0.1);
				glPopMatrix();
				glPushMatrix();
									glTranslated(0.1,-0.1,0.1);
									setDiffuseColor(COLOR_RED);
									drawBox(0.8,0.1,0.8);
				glPopMatrix();
				glPushMatrix();
									glTranslated(-0.1,0.1,0.1);
									setDiffuseColor(COLOR_YELLOW);
									drawBox(0.1,0.8,0.8);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();

	//box2
	glPushMatrix();
									glTranslated(1,0,0);
									setDiffuseColor(COLOR_WHITE);
		glPushMatrix();
									glTranslated(0,1.5,1.5);
									glRotated(VAL(XROTATEM), 1.0, 0.0, 0.0);
									glTranslated(0,-1.5,-1.5);
									drawBox(1,1,1);
			glPushMatrix();
				glPushMatrix();
									glTranslated(0.1,0.1,-0.1);
									setDiffuseColor(COLOR_GREEN);
									drawBox(0.8,0.8,0.1);
				glPopMatrix();
				glPushMatrix();
									glTranslated(0.1,-0.1,0.1);
									setDiffuseColor(COLOR_RED);
									drawBox(0.8,0.1,0.8);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	//box3
		glPushMatrix();
									glTranslated(1,0,0);
									setDiffuseColor(COLOR_WHITE);
			glPushMatrix();
									glTranslated(0,1.5,1.5);
									glRotated(VAL(XROTATEL), 1.0, 0.0, 0.0);
									glTranslated(0,-1.5,-1.5);
									drawBox(1,1,1);
				glPushMatrix();
									glTranslated(0.1,0.1,-0.1);
									setDiffuseColor(COLOR_GREEN);
									drawBox(0.8,0.8,0.1);
				glPopMatrix();
				glPushMatrix();
									glTranslated(0.1,-0.1,0.1);
									setDiffuseColor(COLOR_RED);
									drawBox(0.8,0.1,0.8);
				glPopMatrix();
				glPushMatrix();
									glTranslated(1,0.1,0.1);
									setDiffuseColor(COLOR_BLACK);
									drawBox(0.1,0.8,0.8);
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
glPopMatrix();
//MIDDLE
	glPushMatrix();
									glTranslated(0,1,0);
										glTranslated(0,0,2);
									glRotated(VAL(YROTATEM), 0.0, 1.0, 0.0);
									glTranslated(0,0,-2);
									glTranslated(-1.5,0,0.5);
		glPushMatrix();
	//box1
									glTranslated(0,0,0);
									setDiffuseColor(COLOR_WHITE);
			glPushMatrix();
									glTranslated(0,0.5,1.5);
									glRotated(VAL(XROTATEU), 1.0, 0.0, 0.0);
									glTranslated(0,-0.5,-1.5);
									drawBox(1,1,1);
				glPushMatrix();
					glPushMatrix();
									glTranslated(0.1,0.1,-0.1);
									setDiffuseColor(COLOR_GREEN);
									drawBox(0.8,0.8,0.1);
					glPopMatrix();
					glPushMatrix();
									glTranslated(-0.1,0.1,0.1);
									setDiffuseColor(COLOR_RED);
					glPopMatrix();
					glPushMatrix();
									glTranslated(-0.1,0.1,0.1);
									setDiffuseColor(COLOR_YELLOW);
									drawBox(0.1,0.8,0.8);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
	//box2
									glTranslated(1,0,0);
									setDiffuseColor(COLOR_WHITE);
			glPushMatrix();
									glTranslated(0,0.5,1.5);
									glRotated(VAL(XROTATEM), 1.0, 0.0, 0.0);
									glTranslated(0,-0.5,-1.5);
									drawBox(1,1,1);
				glPushMatrix();
									glTranslated(0.1,0.1,-0.1);
									setDiffuseColor(COLOR_GREEN);
									drawBox(0.8,0.8,0.1);
				glPopMatrix();
			glPopMatrix();
	//box3
									glTranslated(1,0,0);
									setDiffuseColor(COLOR_WHITE);
			glPushMatrix();
									glTranslated(0,0.5,1.5);
									glRotated(VAL(XROTATEL), 1.0, 0.0, 0.0);
									glTranslated(0,-0.5,-1.5);
									drawBox(1,1,1);
				glPushMatrix();
					glPushMatrix();
									glTranslated(0.1,0.1,-0.1);
									setDiffuseColor(COLOR_GREEN);
									drawBox(0.8,0.8,0.1);
					glPopMatrix();
					glPushMatrix();
									glTranslated(1,0.1,0.1);
									setDiffuseColor(COLOR_BLACK);
									drawBox(0.1,0.8,0.8);
					glPopMatrix();
				glPopMatrix();
			glPopMatrix();
		glPopMatrix();
	glPopMatrix();
//UPPER
		glPushMatrix();
					glTranslated(0,0,2);
									glRotated(VAL(YROTATEU), 0.0, 1.0, 0.0);
									glTranslated(0,0,-2);
				glTranslated(-1.5,2,0.5);
				glPushMatrix();
	//box1
					glTranslated(0,0,0);
					setDiffuseColor(COLOR_WHITE);
					glPushMatrix();
					glTranslated(0,-0.5,1.5);
						glRotated(VAL(XROTATEU), 1.0, 0.0, 0.0);
						glTranslated(0,0.5,-1.5);
							drawBox(1,1,1);
							glPushMatrix();
							glPushMatrix();
								glTranslated(0.1,0.1,-0.1);
								setDiffuseColor(COLOR_GREEN);
								drawBox(0.8,0.8,0.1);
							glPopMatrix();
							glPushMatrix();
								glTranslated(0.1,1,0.1);
								setDiffuseColor(COLOR_ORANGE);
								drawBox(0.8,0.1,0.8);
							glPopMatrix();
							glPushMatrix();
								glTranslated(-0.1,0.1,0.1);
								setDiffuseColor(COLOR_YELLOW);
								drawBox(0.1,0.8,0.8);
							glPopMatrix();
						glPopMatrix();
						glPopMatrix();
	//box2
					glTranslated(1,0,0);
					setDiffuseColor(COLOR_WHITE);
					glPushMatrix();
					glTranslated(0,-0.5,1.5);
						glRotated(VAL(XROTATEM), 1.0, 0.0, 0.0);
						glTranslated(0,0.5,-1.5);
					drawBox(1,1,1);
					glPushMatrix();
						glPushMatrix();
							glTranslated(0.1,0.1,-0.1);
							setDiffuseColor(COLOR_GREEN);
							drawBox(0.8,0.8,0.1);
						glPopMatrix();
						glPushMatrix();
							glTranslated(0.1,1,0.1);
							setDiffuseColor(COLOR_ORANGE);
							drawBox(0.8,0.1,0.8);
						glPopMatrix();
								glPopMatrix();
					glPopMatrix();
	//box3
					glTranslated(1,0,0);
					setDiffuseColor(COLOR_WHITE);
					glPushMatrix();
					glTranslated(0,-0.5,1.5);
						glRotated(VAL(XROTATEL), 1.0, 0.0, 0.0);
						glTranslated(0,0.5,-1.5);
					drawBox(1,1,1);
					glPushMatrix();
						glPushMatrix();
							glTranslated(0.1,0.1,-0.1);
							setDiffuseColor(COLOR_GREEN);
							drawBox(0.8,0.8,0.1);
						glPopMatrix();
						glPushMatrix();
							glTranslated(0.1,1,0.1);
							setDiffuseColor(COLOR_ORANGE);
							drawBox(0.8,0.1,0.8);
						glPopMatrix();
						glPushMatrix();
							glTranslated(1,0.1,0.1);
							setDiffuseColor(COLOR_BLACK);
							drawBox(0.1,0.8,0.8);
						glPopMatrix();
					glPopMatrix();
							glPopMatrix();
				glPopMatrix();	
				glPopMatrix();
				glPopMatrix();
				glPopMatrix();

				
}

int main()
{
	// Initialize the controls
	// Constructor is ModelerControl(name, minimumvalue, maximumvalue, 
	// stepsize, defaultvalue)
    ModelerControl controls[NUMCONTROLS];
    controls[XPOS] = ModelerControl("X Position", -5, 5, 0.1f, 0);
    controls[YPOS] = ModelerControl("Y Position", 0, 5, 0.1f, 0);
    controls[ZPOS] = ModelerControl("Z Position", -5, 5, 0.1f, 0);
    controls[HEIGHT] = ModelerControl("Height", 1, 2.5, 0.1f, 1);
	controls[XROTATEL] = ModelerControl("Rotate 1", -180, 180, 2, 0);
	controls[XROTATEM] = ModelerControl("Rotate 2", -180, 180, 2, 0);
	controls[XROTATEU] = ModelerControl("Rotate 3", -180, 180, 2, 0);
	controls[YROTATEL] = ModelerControl("Rotate Lower", -180, 180, 2, 0);
	controls[YROTATEM] = ModelerControl("Rotate Middle", -180, 180, 2, 0);
	controls[YROTATEU] = ModelerControl("Rotate Upper", -180, 180, 2, 0);
    ModelerApplication::Instance()->Init(&createSampleModel, controls, NUMCONTROLS);
    return ModelerApplication::Instance()->Run();
}