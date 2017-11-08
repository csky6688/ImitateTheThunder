
//#include "stdafx.h"

//typedef DWORD COLOR

#define GetRValue(rgb)      (LOBYTE(rgb))
#define GetGValue(rgb)      (LOBYTE(((WORD)(rgb)) >> 8))
#define GetBValue(rgb)      (LOBYTE((rgb)>>16))

#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))


#define GetBValueOfARGB(argb) (LOBYTE(argb))
#define GetGValueOfARGB(argb) (LOBYTE(((WORD)(argb)) >> 8)) 
#define GetRValueOfARGB(argb) (LOBYTE(argb >> 16))
#define GetAValueOfARGB(argb) (LOBYTE(((WORD)(argb >> 16)) >> 8))


#define ARGB(a,r,g,b)  (DWORD)a << 24 | RGB(b,g,r)


#define SetRValue(rgb,r)  RGB(r,GetGValue(rgb),GetBValue(rgb))
#define SetGValue(rgb,g)  RGB(GetRValue(rgb),g,GetBValue(rgb))
#define SetBValue(rgb,b)  RGB(GetRValue(rgb),GetGValue(rgb),b)


#define SetAValueOfARGB(argb,a)\
	 ARGB(\
		a, \
		GetRValueOfARGB(argb),\
		GetGValueOfARGB(argb),\
		GetBValueOfARGB(argb))

#define SetRValueOfARGB(argb,r)\
	 ARGB(\
		GetAValueOfARGB(argb), \
		r,\
		GetGValueOfARGB(argb),\
		GetBValueOfARGB(argb))

#define SetGValueOfARGB(argb,g)\
	  ARGB(\
		GetAValueOfARGB(argb), \
		GetRValueOfARGB(argb),\
		g,\
		GetBValueOfARGB(argb))

#define SetBValueOfARGB(argb,b)\
	  ARGB(\
		GetAValueOfARGB(argb), \
		GetRValueOfARGB(argb),\
		GetGValueOfARGB(argb),\
		b)



