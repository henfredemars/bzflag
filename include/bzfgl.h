/* bzflag
 * Copyright (c) 1993 - 2003 Tim Riker
 *
 * This package is free software;  you can redistribute it and/or
 * modify it under the terms of the license found in the file
 * named COPYING that should have accompanied this file.
 *
 * THIS PACKAGE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED
 * WARRANTIES OF MERCHANTIBILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 */

#ifndef __BZFGL_H__
#define __BZFGL_H__

/** this file contains headers necessary for opengl */

#ifdef _WIN32
/* windows wants to include winsock but we can't allow that.  we
 * include winsock2.h (in network.h) and the two don't play together.
 */
#  define _WINSOCKAPI_
/* including windows.h slows down compiles a *lot*.  should
 * replace this with only the necessary definitions.
 */
#  include <windows.h>
#endif // _WIN32

#ifdef __APPLE__
#  include <OpenGL/OpenGL.h>
#  include <OpenGL/gl.h>
#  include <OpenGL/glu.h>
#else
#  include <GL/gl.h>
#  include <GL/glu.h>
#endif

/* These will track glBegin/End pairs to make sure that they match */
#if DEBUG
int __beginendCount=0;
#define glBegin(_value) {\
  if (__beginendCount==0) { \
    __beginendCount++;\
  } else {\
    fprintf(stderr, "ERROR: glBegin called on %s:%d without calling glEnd before\n", __FILE__, __LINE__); \
    assert(__beginendCount==0 && "glBegin called without glEnd"); \
  } \
  glBegin(_value);\
}
#define glEnd(_value) {\
  if (__beginendCount==0) { \
    fprintf(stderr, "ERROR: glEnd called on %s:%d without calling glBegin before\n", __FILE__, __LINE__); \
    assert(__beginendCount!=0 && "glEnd called without glBegin"); \
  } else {\
    __beginendCount--;\
  } \
  glEnd(_value);\
}
#endif


#endif /* __BZFGL_H__ */

// Local Variables: ***
// mode: C++ ***
// tab-width: 8 ***
// c-basic-offset: 2 ***
// indent-tabs-mode: t ***
// End: ***
// ex: shiftwidth=2 tabstop=8
