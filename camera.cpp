#include <windows.h>
#include <Fl/gl.h>
#include <gl/glu.h>
#include "modelerview.h"
#include "camera.h"

#pragma warning(push)
#pragma warning(disable : 4244)

#ifndef M_PI
#define M_PI 3.141592653589793238462643383279502
#endif 

const float kMouseRotationSensitivity		= 1.0f/90.0f;
const float kMouseTranslationXSensitivity	= 0.03f;
const float kMouseTranslationYSensitivity	= 0.03f;
const float kMouseZoomSensitivity			= 0.08f;

void MakeDiagonal(Mat4f &m, float k)
{
	register int i,j;

	for (i=0; i<4; i++)
		for (j=0; j<4; j++)
			m[i][j] = (i==j) ? k : 0.0f;
}

void MakeHScale(Mat4f &m, const Vec3f &s)	
{
	MakeDiagonal(m,1.0f);
	m[0][0] = s[0]; m[1][1] = s[1];	m[2][2] = s[2];
}

void MakeHTrans(Mat4f &m, const Vec3f &s)
{
	MakeDiagonal(m,1.0f);
	m[0][3] = s[0]; m[1][3] = s[1]; m[2][3] = s[2];
}

void MakeHRotX(Mat4f &m, float theta)
{
	MakeDiagonal(m,1.0f);
	float cosTheta = cos(theta);
	float sinTheta = sin(theta);
	m[1][1] = cosTheta;
	m[1][2] = -sinTheta;
	m[2][1] = sinTheta;
	m[2][2] = cosTheta;
}

void MakeHRotY(Mat4f &m, float theta)
{
	MakeDiagonal(m,1.0f);
	float cosTheta = cos(theta);
	float sinTheta = sin(theta);
	m[0][0] = cosTheta;
	m[2][0] = -sinTheta;
	m[0][2] = sinTheta;
	m[2][2] = cosTheta;
}

void MakeHRotZ(Mat4f &m, float theta)
{
	MakeDiagonal(m,1.0f);
	float cosTheta = cos(theta);
	float sinTheta = sin(theta);
	m[0][0] = cosTheta;
	m[0][1] = -sinTheta;
	m[1][0] = sinTheta;
	m[1][1] = cosTheta;
}


void Camera::calculateViewingTransformParameters() 
{
	Mat4f dollyXform;
	Mat4f azimXform;
	Mat4f elevXform;
	Mat4f twistXform;
	Mat4f originXform;

	Vec3f upVector;

	MakeHTrans(dollyXform, Vec3f(0,0,mDolly));
	MakeHRotY(azimXform, mAzimuth);
	MakeHRotX(elevXform, mElevation);
	MakeDiagonal(twistXform, 1.0f);
	MakeHTrans(originXform, mLookAt);
	
	mPosition = Vec3f(0,0,0);
	// grouped for (mat4 * vec3) ops instead of (mat4 * mat4) ops
	mPosition = originXform * (azimXform * (elevXform * (dollyXform * mPosition)));

	if ( fmod((double)mElevation, 2.0*M_PI) < 3*M_PI/2 && fmod((double)mElevation, 2.0*M_PI) > M_PI/2 )
		mUpVector= Vec3f(0,-1,0);
	else
		mUpVector= Vec3f(0,1,0);

	mDirtyTransform = false;
}

Camera::Camera() 
{
	mElevation = mAzimuth = mTwist = 0.0f;
	mDolly = -20.0f;
	mElevation = 0.2f;
	mAzimuth = (float)M_PI;

	mLookAt = Vec3f( 0, 0, 0 );
	mCurrentMouseAction = kActionNone;

	calculateViewingTransformParameters();
}

void Camera::clickMouse( MouseAction_t action, int x, int y )
{
	mCurrentMouseAction = action;
	mLastMousePosition[0] = x;
	mLastMousePosition[1] = y;
}

void Camera::dragMouse( int x, int y )
{
	Vec3f mouseDelta   = Vec3f(x,y,0.0f) - mLastMousePosition;
	mLastMousePosition = Vec3f(x,y,0.0f);

	switch(mCurrentMouseAction)
	{
	case kActionTranslate:
		{
			calculateViewingTransformParameters();

			double xTrack =  -mouseDelta[0] * kMouseTranslationXSensitivity;
			double yTrack =  mouseDelta[1] * kMouseTranslationYSensitivity;

			Vec3f transXAxis = mUpVector ^ (mPosition - mLookAt);
			transXAxis /= sqrt((transXAxis*transXAxis));
			Vec3f transYAxis = (mPosition - mLookAt) ^ transXAxis;
			transYAxis /= sqrt((transYAxis*transYAxis));

			setLookAt(getLookAt() + transXAxis*xTrack + transYAxis*yTrack);
			
			break;
		}
	case kActionRotate:
		{
			float dAzimuth		=   -mouseDelta[0] * kMouseRotationSensitivity;
			float dElevation	=   mouseDelta[1] * kMouseRotationSensitivity;
			
			setAzimuth(getAzimuth() + dAzimuth);
			setElevation(getElevation() + dElevation);
			
			break;
		}
	case kActionZoom:
		{
			float dDolly = -mouseDelta[1] * kMouseZoomSensitivity;
			setDolly(getDolly() + dDolly);
			break;
		}
	case kActionTwist:
		// Not implemented
	default:
		break;
	}

}

void Camera::releaseMouse( int x, int y )
{
	mCurrentMouseAction = kActionNone;
}


void Camera::applyViewingTransform() {
	if( mDirtyTransform )
		calculateViewingTransformParameters();

	// Place the camera at mPosition, aim the camera at
	// mLookAt, and twist the camera such that mUpVector is up
	lookAt(	mPosition, mLookAt, mUpVector);
}

void Camera::lookAt(Vec3f eye, Vec3f at, Vec3f up) {

	// construct vector pointing from eye to center
	Vec3f f = Vec3f(at[0] - eye[0], at[1] - eye[1], at[2] - eye[2]);
	f.normalize();

	// construct side vector (that is perp to facing vector and world's up vector)
	Vec3f s = CrossProductf(f, up);
	s.normalize();

	// construct the up (relative to eye) vector. 
	Vec3f u = CrossProductf(s, f);

	// create rotation matrix
	GLfloat Mfloat[16] = { s[0], u[0], -f[0], 0, s[1], u[1], -f[1], 0, s[2], u[2], -f[2], 0, 0, 0, 0, 1 };
	GLfloat * p_M = Mfloat;

	// make the transformations that gluLookAt() does
	glMultMatrixf(p_M);
	glTranslatef(-eye[0], -eye[1], -eye[2]);
}

Vec3f Camera::CrossProductf(Vec3f b, Vec3f c) {

	Vec3f a = Vec3f(0, 0, 0);

	a[0] = b[1] * c[2] - c[1] * b[2];
	a[1] = b[2] * c[0] - c[2] * b[0];
	a[2] = b[0] * c[1] - c[0] * b[1];

	return a;
}
#pragma warning(pop)