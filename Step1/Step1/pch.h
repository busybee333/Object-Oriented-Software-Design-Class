/**
* \file pch.h
*
* \author Romi Yun
*
* A short description of the module
* this header contains or describes.
*
* Here you will add any additional detail that is needed to made the
* description readable to others who may work on your program.
*/

#ifndef PCH_H
#define PCH_H


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifdef _DEBUG
#ifndef DBG_NEW
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif
#endif  // _DEBUG

#endif //PCH_H
