/*
 
 SDL_imageFilter - bytes-image "filter" routines 
 (uses inline x86 MMX optimizations if available)
 
 LGPL (c) A. Schiffler

*/

#ifndef _SDL_imageFilter_h
#define _SDL_imageFilter_h

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

/* ------ Function Prototypes ------ */

#ifdef WIN32
#ifdef BUILD_DLL
#define DLLINTERFACE __declspec(dllexport)
#else
#define DLLINTERFACE 
	//__declspec(dllimport)
#endif
#else
#define DLLINTERFACE
#endif

/* Comments:                                                                           */
/*  1.) MMX functions work best if all data blocks are aligned on a 32 bytes boundary. */
/*  2.) Data that is not within an 8 byte boundary is processed using the C routine.   */
/*  3.) Convolution routines do not have C routines at this time.                      */

// Detect MMX capability in CPU
    DLLINTERFACE int SDL_imageFilterMMXdetect(void);

// Force use of MMX off (or turn possible use back on)
    DLLINTERFACE void SDL_imageFilterMMXoff(void);
    DLLINTERFACE void SDL_imageFilterMMXon(void);

//
// All routines return:
//   0   OK
//  -1   Error (internal error, parameter error)
//

//  SDL_imageFilterAdd: D = saturation255(S1 + S2)
    DLLINTERFACE int SDL_imageFilterAdd(unsigned char *Src1, unsigned char *Src2, unsigned char *Dest, int length);

//  SDL_imageFilterMean: D = S1/2 + S2/2
    DLLINTERFACE int SDL_imageFilterMean(unsigned char *Src1, unsigned char *Src2, unsigned char *Dest, int length);

//  SDL_imageFilterSub: D = saturation0(S1 - S2)
    DLLINTERFACE int SDL_imageFilterSub(unsigned char *Src1, unsigned char *Src2, unsigned char *Dest, int length);

//  SDL_imageFilterAbsDiff: D = | S1 - S2 |
    DLLINTERFACE int SDL_imageFilterAbsDiff(unsigned char *Src1, unsigned char *Src2, unsigned char *Dest, int length);

//  SDL_imageFilterMult: D = saturation(S1 * S2)
    DLLINTERFACE int SDL_imageFilterMult(unsigned char *Src1, unsigned char *Src2, unsigned char *Dest, int length);

//  SDL_imageFilterMultNor: D = S1 * S2   (non-MMX)
    DLLINTERFACE int SDL_imageFilterMultNor(unsigned char *Src1, unsigned char *Src2, unsigned char *Dest, int length);

//  SDL_imageFilterMultDivby2: D = saturation255(S1/2 * S2)
    DLLINTERFACE int SDL_imageFilterMultDivby2(unsigned char *Src1, unsigned char *Src2, unsigned char *Dest,
					       int length);

//  SDL_imageFilterMultDivby4: D = saturation255(S1/2 * S2/2)
    DLLINTERFACE int SDL_imageFilterMultDivby4(unsigned char *Src1, unsigned char *Src2, unsigned char *Dest,
					       int length);

//  SDL_imageFilterBitAnd: D = S1 & S2
    DLLINTERFACE int SDL_imageFilterBitAnd(unsigned char *Src1, unsigned char *Src2, unsigned char *Dest, int length);

//  SDL_imageFilterBitOr: D = S1 | S2
    DLLINTERFACE int SDL_imageFilterBitOr(unsigned char *Src1, unsigned char *Src2, unsigned char *Dest, int length);

//  SDL_imageFilterDiv: D = S1 / S2   (non-MMX)
    DLLINTERFACE int SDL_imageFilterDiv(unsigned char *Src1, unsigned char *Src2, unsigned char *Dest, int length);

//  SDL_imageFilterBitNegation: D = !S
    DLLINTERFACE int SDL_imageFilterBitNegation(unsigned char *Src1, unsigned char *Dest, int length);

//  SDL_imageFilterAddByte: D = saturation255(S + C)
    DLLINTERFACE int SDL_imageFilterAddByte(unsigned char *Src1, unsigned char *Dest, int length, unsigned char C);

//  SDL_imageFilterAddUint: D = saturation255(S + (uint)C)
    DLLINTERFACE int SDL_imageFilterAddUint(unsigned char *Src1, unsigned char *Dest, int length, unsigned int C);

//  SDL_imageFilterAddByteToHalf: D = saturation255(S/2 + C)
    DLLINTERFACE int SDL_imageFilterAddByteToHalf(unsigned char *Src1, unsigned char *Dest, int length,
						  unsigned char C);

//  SDL_imageFilterSubByte: D = saturation0(S - C)
    DLLINTERFACE int SDL_imageFilterSubByte(unsigned char *Src1, unsigned char *Dest, int length, unsigned char C);

//  SDL_imageFilterSubUint: D = saturation0(S - (uint)C)
    DLLINTERFACE int SDL_imageFilterSubUint(unsigned char *Src1, unsigned char *Dest, int length, unsigned int C);

//  SDL_imageFilterShiftRight: D = saturation0(S >> N)
    DLLINTERFACE int SDL_imageFilterShiftRight(unsigned char *Src1, unsigned char *Dest, int length, unsigned char N);

//  SDL_imageFilterShiftRightUint: D = saturation0((uint)S >> N)
    DLLINTERFACE int SDL_imageFilterShiftRightUint(unsigned char *Src1, unsigned char *Dest, int length, unsigned char N);

//  SDL_imageFilterMultByByte: D = saturation255(S * C)
    DLLINTERFACE int SDL_imageFilterMultByByte(unsigned char *Src1, unsigned char *Dest, int length, unsigned char C);

//  SDL_imageFilterShiftRightAndMultByByte: D = saturation255((S >> N) * C)
    DLLINTERFACE int SDL_imageFilterShiftRightAndMultByByte(unsigned char *Src1, unsigned char *Dest, int length,
							    unsigned char N, unsigned char C);

//  SDL_imageFilterShiftLeftByte: D = (S << N)
    DLLINTERFACE int SDL_imageFilterShiftLeftByte(unsigned char *Src1, unsigned char *Dest, int length,
						  unsigned char N);

//  SDL_imageFilterShiftLeftUint: D = ((uint)S << N)
    DLLINTERFACE int SDL_imageFilterShiftLeftUint(unsigned char *Src1, unsigned char *Dest, int length,
						  unsigned char N);

//  SDL_imageFilterShiftLeft: D = saturation255(S << N)
    DLLINTERFACE int SDL_imageFilterShiftLeft(unsigned char *Src1, unsigned char *Dest, int length, unsigned char N);

//  SDL_imageFilterBinarizeUsingThreshold: D = S >= T ? 255:0
    DLLINTERFACE int SDL_imageFilterBinarizeUsingThreshold(unsigned char *Src1, unsigned char *Dest, int length,
							   unsigned char T);

//  SDL_imageFilterClipToRange: D = (S >= Tmin) & (S <= Tmax) 255:0
    DLLINTERFACE int SDL_imageFilterClipToRange(unsigned char *Src1, unsigned char *Dest, int length,
						unsigned char Tmin, unsigned char Tmax);

//  SDL_imageFilterNormalizeLinear: D = saturation255((Nmax - Nmin)/(Cmax - Cmin)*(S - Cmin) + Nmin)
    DLLINTERFACE int SDL_imageFilterNormalizeLinear(unsigned char *Src1, unsigned char *Dest, int length, int Cmin,
						    int Cmax, int Nmin, int Nmax);

/* !!! NO C-ROUTINE FOR THESE FUNCTIONS YET !!! */

//  SDL_imageFilterConvolveKernel3x3Divide: Dij = saturation0and255( ... )
    DLLINTERFACE int SDL_imageFilterConvolveKernel3x3Divide(unsigned char *Src, unsigned char *Dest, int rows,
							    int columns, signed short *Kernel, unsigned char Divisor);

//  SDL_imageFilterConvolveKernel5x5Divide: Dij = saturation0and255( ... )
    DLLINTERFACE int SDL_imageFilterConvolveKernel5x5Divide(unsigned char *Src, unsigned char *Dest, int rows,
							    int columns, signed short *Kernel, unsigned char Divisor);

//  SDL_imageFilterConvolveKernel7x7Divide: Dij = saturation0and255( ... )
    DLLINTERFACE int SDL_imageFilterConvolveKernel7x7Divide(unsigned char *Src, unsigned char *Dest, int rows,
							    int columns, signed short *Kernel, unsigned char Divisor);

//  SDL_imageFilterConvolveKernel9x9Divide: Dij = saturation0and255( ... )
    DLLINTERFACE int SDL_imageFilterConvolveKernel9x9Divide(unsigned char *Src, unsigned char *Dest, int rows,
							    int columns, signed short *Kernel, unsigned char Divisor);

//  SDL_imageFilterConvolveKernel3x3ShiftRight: Dij = saturation0and255( ... )
    DLLINTERFACE int SDL_imageFilterConvolveKernel3x3ShiftRight(unsigned char *Src, unsigned char *Dest, int rows,
								int columns, signed short *Kernel,
								unsigned char NRightShift);

//  SDL_imageFilterConvolveKernel5x5ShiftRight: Dij = saturation0and255( ... )
    DLLINTERFACE int SDL_imageFilterConvolveKernel5x5ShiftRight(unsigned char *Src, unsigned char *Dest, int rows,
								int columns, signed short *Kernel,
								unsigned char NRightShift);

//  SDL_imageFilterConvolveKernel7x7ShiftRight: Dij = saturation0and255( ... )
    DLLINTERFACE int SDL_imageFilterConvolveKernel7x7ShiftRight(unsigned char *Src, unsigned char *Dest, int rows,
								int columns, signed short *Kernel,
								unsigned char NRightShift);

//  SDL_imageFilterConvolveKernel9x9ShiftRight: Dij = saturation0and255( ... )
    DLLINTERFACE int SDL_imageFilterConvolveKernel9x9ShiftRight(unsigned char *Src, unsigned char *Dest, int rows,
								int columns, signed short *Kernel,
								unsigned char NRightShift);

//  SDL_imageFilterSobelX: Dij = saturation255( ... )
    DLLINTERFACE int SDL_imageFilterSobelX(unsigned char *Src, unsigned char *Dest, int rows, int columns);

//  SDL_imageFilterSobelXShiftRight: Dij = saturation255( ... )
    DLLINTERFACE int SDL_imageFilterSobelXShiftRight(unsigned char *Src, unsigned char *Dest, int rows, int columns,
						     unsigned char NRightShift);

// Align/restore stack to 32 byte boundary -- Functionality untested! --
    DLLINTERFACE void SDL_imageFilterAlignStack(void);
    DLLINTERFACE void SDL_imageFilterRestoreStack(void);

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
};
#endif

#endif				/* _SDL_imageFilter_h */
