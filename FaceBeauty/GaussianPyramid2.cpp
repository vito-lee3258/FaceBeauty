#include "GaussianPyramid2.h"

void CGaussianPyramid2::FillByteImage(BYTE *pInImage, BYTE *pOutImage, int nInWidth, int nInHeight, int nOutWidth, int nOutHeight, int nDim)
{
	int i, x, y;

	for (y = 0; y < nInHeight; y++)
	{
		BYTE *pInLine = pInImage + y*nInWidth*nDim;
		BYTE *pOutLine = pOutImage + y*nOutWidth*nDim;

		for (x = 0; x < nInWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				*(pOutLine++) = *(pInLine++);
			}
		}
		for (; x < nOutWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				pOutLine[i] = pOutLine[i - nDim];
			}
			pOutLine += nDim;
		}
	}
	for (; y < nOutHeight; y++)
	{
		BYTE *pInLine = pInImage + (nInHeight - 1)*nInWidth*nDim;
		BYTE *pOutLine = pOutImage + y*nOutWidth*nDim;

		for (x = 0; x < nInWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				*(pOutLine++) = *(pInLine++);
			}
		}
		for (; x < nOutWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				pOutLine[i] = pOutLine[i - nDim];
			}
			pOutLine += nDim;
		}
	}
}

void CGaussianPyramid2::FillShortImage(short *pInImage, short *pOutImage, int nInWidth, int nInHeight, int nOutWidth, int nOutHeight, int nDim)
{
	int i, x, y;

	for (y = 0; y < nInHeight; y++)
	{
		short *pInLine = pInImage + y*nInWidth*nDim;
		short *pOutLine = pOutImage + y*nOutWidth*nDim;

		for (x = 0; x < nInWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				*(pOutLine++) = *(pInLine++);
			}
		}
		for (; x < nOutWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				pOutLine[i] = pOutLine[i - nDim];
			}
			pOutLine += nDim;
		}
	}
	for (; y < nOutHeight; y++)
	{
		short *pInLine = pInImage + (nInHeight - 1)*nInWidth*nDim;
		short *pOutLine = pOutImage + y*nOutWidth*nDim;

		for (x = 0; x < nInWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				*(pOutLine++) = *(pInLine++);
			}
		}
		for (; x < nOutWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				pOutLine[i] = pOutLine[i - nDim];
			}
			pOutLine += nDim;
		}
	}
}

void CGaussianPyramid2::FillWordImage(WORD *pInImage, WORD *pOutImage, int nInWidth, int nInHeight, int nOutWidth, int nOutHeight, int nDim)
{
	int i, x, y;

	for (y = 0; y < nInHeight; y++)
	{
		WORD *pInLine = pInImage + y*nInWidth*nDim;
		WORD *pOutLine = pOutImage + y*nOutWidth*nDim;

		for (x = 0; x < nInWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				*(pOutLine++) = *(pInLine++);
			}
		}
		for (; x < nOutWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				pOutLine[i] = pOutLine[i - nDim];
			}
			pOutLine += nDim;
		}
	}
	for (; y < nOutHeight; y++)
	{
		WORD *pInLine = pInImage + (nInHeight - 1)*nInWidth*nDim;
		WORD *pOutLine = pOutImage + y*nOutWidth*nDim;

		for (x = 0; x < nInWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				*(pOutLine++) = *(pInLine++);
			}
		}
		for (; x < nOutWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				pOutLine[i] = pOutLine[i - nDim];
			}
			pOutLine += nDim;
		}
	}
}

void CGaussianPyramid2::HDownScaleByteLine(BYTE *pInLine, WORD *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	BYTE *pIn[5];
	
	pIn[0] = pIn[1] = pIn[2] = pInLine;
	pIn[3] = pIn[2] + nDim;
	pIn[4] = pIn[3] + nDim;

	for (x = 0; x < nWidth - 2; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i];
			Y += pIn[1][i] * 4;
			Y += pIn[2][i] * 6;
			Y += pIn[3][i] * 4;
			Y += pIn[4][i];

			pOutLine[i] = (WORD) Y;
		}
		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] = pIn[3];
		pIn[3] = pIn[4];
		pIn[4] += nDim;

		pOutLine += nDim * 5;
	}
	pIn[4] = pIn[3];
	for (; x < nWidth; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i];
			Y += pIn[1][i] * 4;
			Y += pIn[2][i] * 6;
			Y += pIn[3][i] * 4;
			Y += pIn[4][i];

			pOutLine[i] = (WORD)Y;
		}
		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] = pIn[3];
		pIn[3] = pIn[4];

		pOutLine += nDim * 5;
	}
}

void CGaussianPyramid2::HDownScaleByteLine(BYTE *pInLine, BYTE *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	BYTE *pIn[5];

	pIn[0] = pIn[1] = pIn[2] = pInLine;
	pIn[3] = pIn[2] + nDim;
	pIn[4] = pIn[3] + nDim;

	for (x = 0; x < nWidth - 2; x++)
	{
		if ((x & 1) == 0)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = pIn[0][i] + pIn[4][i];
				Y += (pIn[1][i] + pIn[3][i] )* 4;
				Y += pIn[2][i] * 6;
				Y >>= 4;

				pOutLine[i] = (BYTE)Y;
			}
			pOutLine += nDim;
		}

		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] = pIn[3];
		pIn[3] = pIn[4];
		pIn[4] += nDim;
	}
	pIn[4] = pIn[3];
	for (; x < nWidth; x++)
	{
		if ((x & 1) == 0)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = pIn[0][i] + pIn[4][i];
				Y += (pIn[1][i] + pIn[3][i]) * 4;
				Y += pIn[2][i] * 6;
				Y >>= 4;

				pOutLine[i] = (BYTE)Y;
			}
			pOutLine += nDim;
		}

		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] = pIn[3];
		pIn[3] = pIn[4];
	}
}

void CGaussianPyramid2::HDownScaleByteLine2(BYTE *pInLine, BYTE *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	BYTE *pIn[6];

	pIn[0] = pIn[1] = pIn[2] = pInLine;
	pIn[3] = pIn[2] + nDim;
	pIn[4] = pIn[3] + nDim;
	pIn[5] = pIn[4] + nDim;

	for (x = 0; x < nWidth - 3; x += 2)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 5;
			Y += (int)pIn[2][i] * 10;
			Y += (int)pIn[3][i] * 10;
			Y += (int)pIn[4][i] * 5;
			Y += (int)pIn[5][i];
			Y >>= 5;

			pOutLine[i] = (BYTE)Y;
		}
		pIn[0] = pIn[2];
		pIn[1] = pIn[3];
		pIn[2] = pIn[4];
		pIn[3] = pIn[5];
		pIn[4] += nDim * 2;
		pIn[5] += nDim * 2;

		pOutLine += nDim;
	}
	pIn[4] = pIn[2];
	pIn[5] = pIn[3];
	for (; x < nWidth; x += 2)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 5;
			Y += (int)pIn[2][i] * 10;
			Y += (int)pIn[3][i] * 10;
			Y += (int)pIn[4][i] * 5;
			Y += (int)pIn[5][i];
			Y >>= 5;

			pOutLine[i] = (BYTE)Y;
		}
		pIn[0] = pIn[2];
		pIn[1] = pIn[3];
		pIn[2] = pIn[4];
		pIn[3] = pIn[5];

		pOutLine += nDim;
	}
}

void CGaussianPyramid2::HDownScaleShortLine(short *pInLine, short *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	short *pIn[5];

	pIn[0] = pIn[1] = pIn[2] = pInLine;
	pIn[3] = pIn[2] + nDim;
	pIn[4] = pIn[3] + nDim;

	for (x = 0; x < nWidth - 2; x++)
	{
		if ((x & 1) == 0)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = pIn[0][i] + pIn[4][i];
				Y += (pIn[1][i] + pIn[3][i]) * 4;
				Y += pIn[2][i] * 6;
				Y /= 16;

				pOutLine[i] = (short)Y;
			}
			pOutLine += nDim;
		}

		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] = pIn[3];
		pIn[3] = pIn[4];
		pIn[4] += nDim;
	}
	pIn[4] = pIn[3];
	for (; x < nWidth; x++)
	{
		if ((x & 1) == 0)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = pIn[0][i] + pIn[4][i];
				Y += (pIn[1][i] + pIn[3][i]) * 4;
				Y += pIn[2][i] * 6;
				Y /= 16;

				pOutLine[i] = (short)Y;
			}
			pOutLine += nDim;
		}

		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] = pIn[3];
		pIn[3] = pIn[4];
	}
}

void CGaussianPyramid2::HDownScaleShortLine2(short *pInLine, short *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	short *pIn[6];

	pIn[0] = pIn[1] = pIn[2] = pInLine;
	pIn[3] = pIn[2] + nDim;
	pIn[4] = pIn[3] + nDim;
	pIn[5] = pIn[4] + nDim;

	for (x = 0; x < nWidth - 3; x += 2)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 5;
			Y += (int)pIn[2][i] * 10;
			Y += (int)pIn[3][i] * 10;
			Y += (int)pIn[4][i] * 5;
			Y += (int)pIn[5][i];
			Y /= 32;

			pOutLine[i] = (short)Y;
		}
		pIn[0] = pIn[2];
		pIn[1] = pIn[3];
		pIn[2] = pIn[4];
		pIn[3] = pIn[5];
		pIn[4] += nDim * 2;
		pIn[5] += nDim * 2;

		pOutLine += nDim;
	}
	pIn[4] = pIn[2];
	pIn[5] = pIn[3];
	for (; x < nWidth; x += 2)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 5;
			Y += (int)pIn[2][i] * 10;
			Y += (int)pIn[3][i] * 10;
			Y += (int)pIn[4][i] * 5;
			Y += (int)pIn[5][i];
			Y /= 32;

			pOutLine[i] = (short)Y;
		}
		pIn[0] = pIn[2];
		pIn[1] = pIn[3];
		pIn[2] = pIn[4];
		pIn[3] = pIn[5];

		pOutLine += nDim;
	}
}

void CGaussianPyramid2::HDownScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim)
{
	int y;
	
	BYTE *pInLine = pInImage;
	BYTE *pOutLine = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		HDownScaleByteLine(pInLine, pOutLine, nWidth, nDim);
		pInLine += nWidth*nDim;
		pOutLine += (nWidth >> 1)*nDim;
	}
}

void CGaussianPyramid2::HDownScaleByteImage2(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim)
{
	int y;

	BYTE *pInLine = pInImage;
	BYTE *pOutLine = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		HDownScaleByteLine2(pInLine, pOutLine, nWidth, nDim);
		pInLine += nWidth*nDim;
		pOutLine += (nWidth >> 1)*nDim;
	}
}

void CGaussianPyramid2::HUpScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim)
{
	int y;

	BYTE *pInLine = pInImage;
	BYTE *pOutLine = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		HUpScaleByteLine(pInLine, pOutLine, nWidth, nDim);
		pInLine += nWidth*nDim;
		pOutLine += (nWidth << 1)*nDim;
	}
}

void CGaussianPyramid2::HDownScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim)
{
	int y;

	short *pInLine = pInImage;
	short *pOutLine = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		HDownScaleShortLine(pInLine, pOutLine, nWidth, nDim);
		pInLine += nWidth*nDim;
		pOutLine += (nWidth >> 1)*nDim;
	}
}

void CGaussianPyramid2::HDownScaleShortImage2(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim)
{
	int y;

	short *pInLine = pInImage;
	short *pOutLine = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		HDownScaleShortLine2(pInLine, pOutLine, nWidth, nDim);
		pInLine += nWidth*nDim;
		pOutLine += (nWidth >> 1)*nDim;
	}
}

void CGaussianPyramid2::HUpScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim)
{
	int y;

	short *pInLine = pInImage;
	short *pOutLine = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		HUpScaleShortLine(pInLine, pOutLine, nWidth, nDim);
		pInLine += nWidth*nDim;
		pOutLine += (nWidth << 1)*nDim;
	}
}


void CGaussianPyramid2::VDownScaleByteLine(WORD *pInLines[], BYTE *pOutLine, int nWidth, int nDim, bool bDitheringEnable, int nE[])
{
	int i, x, Y;
	WORD *pIn[5];

	for (i = 0; i < 5; i++)
	{
		pIn[i] = pInLines[i];
	}

	for (x = 0; x < (nWidth >> 1); x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i];
			Y += pIn[1][i] * 4;
			Y += pIn[2][i] * 6;
			Y += pIn[3][i] * 4;
			Y += pIn[4][i];

			if (bDitheringEnable)
			{
				Y += nE[i];
				nE[i] = (Y & 255);
			}
			Y >>= 8;
			
			*(pOutLine++) = (BYTE)Y;
		}

		for (i = 0; i < 5; i++)
		{
			pIn[i] += 10 * nDim;
		}
	}
}

void CGaussianPyramid2::VDownScaleByteLine(BYTE *pInLines[], BYTE *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	BYTE *pIn[5];

	for (i = 0; i < 5; i++)
	{
		pIn[i] = pInLines[i];
	}

	for (x = 0; x < nWidth; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i] + pIn[4][i];
			Y += (pIn[1][i] + pIn[3][i]) * 4;
			Y += pIn[2][i] * 6;
			Y >>= 4;

			*(pOutLine++) = (BYTE)Y;
		}

		for (i = 0; i < 5; i++)
		{
			pIn[i] += nDim;
		}
	}
}

void CGaussianPyramid2::VDownScaleByteLine2(BYTE *pInLines[], BYTE *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	BYTE *pIn[6];

	for (i = 0; i < 6; i++)
	{
		pIn[i] = pInLines[i];
	}

	for (x = 0; x < nWidth; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 5;
			Y += (int)pIn[2][i] * 10;
			Y += (int)pIn[3][i] * 10;
			Y += (int)pIn[4][i] * 5;
			Y += (int)pIn[5][i];
			Y >>= 5;

			*(pOutLine++) = (BYTE)Y;
		}

		for (i = 0; i < 6; i++)
		{
			pIn[i] += nDim;
		}
	}
}

void CGaussianPyramid2::VDownScaleShortLine(short *pInLines[], short *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	short *pIn[5];

	for (i = 0; i < 5; i++)
	{
		pIn[i] = pInLines[i];
	}

	for (x = 0; x < nWidth; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i] + pIn[4][i];
			Y += (pIn[1][i] + pIn[3][i]) * 4;
			Y += pIn[2][i] * 6;
			Y /= 16;

			*(pOutLine++) = (short)Y;
		}

		for (i = 0; i < 5; i++)
		{
			pIn[i] += nDim;
		}
	}
}

void CGaussianPyramid2::VDownScaleShortLine2(short *pInLines[], short *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	short *pIn[6];

	for (i = 0; i < 6; i++)
	{
		pIn[i] = pInLines[i];
	}

	for (x = 0; x < nWidth; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 5;
			Y += (int)pIn[2][i] * 10;
			Y += (int)pIn[3][i] * 10;
			Y += (int)pIn[4][i] * 5;
			Y += (int)pIn[5][i];
			Y /= 32;

			*(pOutLine++) = (short)Y;
		}

		for (i = 0; i < 6; i++)
		{
			pIn[i] += nDim;
		}
	}
}

void CGaussianPyramid2::VDownScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim)
{
	int y;
	BYTE *pInLines[5];

	pInLines[0] = pInLines[1] = pInLines[2] = pInImage;
	pInLines[3] = pInLines[2] + nWidth*nDim;
	pInLines[4] = pInLines[3] + nWidth*nDim;

	BYTE *pOutLine = pOutImage;
	for (y = 0; y < nHeight - 2; y++)
	{
		if ((y & 1) == 0)
		{
			VDownScaleByteLine(pInLines, pOutLine, nWidth, nDim);
			pOutLine += nWidth*nDim;
		}

		pInLines[0] = pInLines[1];
		pInLines[1] = pInLines[2];
		pInLines[2] = pInLines[3];
		pInLines[3] = pInLines[4];
		pInLines[4] += nWidth*nDim;
	}

	pInLines[4] = pInLines[3];
	for (; y < nHeight; y++)
	{
		if ((y & 1) == 0)
		{
			VDownScaleByteLine(pInLines, pOutLine, nWidth, nDim);
			pOutLine += nWidth*nDim;
		}

		pInLines[0] = pInLines[1];
		pInLines[1] = pInLines[2];
		pInLines[2] = pInLines[3];
		pInLines[3] = pInLines[4];
	}
}

void CGaussianPyramid2::VDownScaleByteImage2(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim)
{
	int y;
	BYTE *pInLines[6];

	pInLines[0] = pInLines[1] = pInLines[2] = pInImage;
	pInLines[3] = pInLines[2] + nWidth*nDim;
	pInLines[4] = pInLines[3] + nWidth*nDim;
	pInLines[5] = pInLines[4] + nWidth*nDim;

	BYTE *pOutLine = pOutImage;
	for (y = 0; y < nHeight - 3; y += 2)
	{
		VDownScaleByteLine2(pInLines, pOutLine, nWidth, nDim);
		pOutLine += nWidth*nDim;

		pInLines[0] = pInLines[2];
		pInLines[1] = pInLines[3];
		pInLines[2] = pInLines[4];
		pInLines[3] = pInLines[5];
		pInLines[4] += 2 * nWidth*nDim;
		pInLines[5] += 2 * nWidth*nDim;
	}

	pInLines[4] = pInLines[2];
	pInLines[5] = pInLines[3];
	for (; y < nHeight; y+=2)
	{
		VDownScaleByteLine2(pInLines, pOutLine, nWidth, nDim);
		pOutLine += nWidth*nDim;

		pInLines[0] = pInLines[2];
		pInLines[1] = pInLines[3];
		pInLines[2] = pInLines[4];
		pInLines[3] = pInLines[5];
	}
}

void CGaussianPyramid2::VUpScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim)
{
	int y;
	BYTE *pInLines[3];

	pInLines[0] = pInLines[1] = pInImage;
	pInLines[2] = pInLines[1] + nWidth*nDim;

	BYTE *pOutLine = pOutImage;
	for (y = 0; y < nHeight - 1; y++)
	{
		VUpScaleByteLine(pInLines, pOutLine, 0, nWidth, nDim);
		pOutLine += nWidth*nDim;

		VUpScaleByteLine(pInLines, pOutLine, 1, nWidth, nDim);
		pOutLine += nWidth*nDim;

		pInLines[0] = pInLines[1];
		pInLines[1] = pInLines[2];
		pInLines[2] += nWidth*nDim;
	}

	pInLines[2] = pInLines[1];
	VUpScaleByteLine(pInLines, pOutLine, 0, nWidth, nDim);
	pOutLine += nWidth*nDim;

	VUpScaleByteLine(pInLines, pOutLine, 1, nWidth, nDim);
	pOutLine += nWidth*nDim;
}

void CGaussianPyramid2::VUpScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim)
{
	int y;
	short *pInLines[3];

	pInLines[0] = pInLines[1] = pInImage;
	pInLines[2] = pInLines[1] + nWidth*nDim;

	short *pOutLine = pOutImage;
	for (y = 0; y < nHeight - 1; y++)
	{
		VUpScaleShortLine(pInLines, pOutLine, 0, nWidth, nDim);
		pOutLine += nWidth*nDim;

		VUpScaleShortLine(pInLines, pOutLine, 1, nWidth, nDim);
		pOutLine += nWidth*nDim;

		pInLines[0] = pInLines[1];
		pInLines[1] = pInLines[2];
		pInLines[2] += nWidth*nDim;
	}

	pInLines[2] = pInLines[1];
	VUpScaleShortLine(pInLines, pOutLine, 0, nWidth, nDim);
	pOutLine += nWidth*nDim;

	VUpScaleShortLine(pInLines, pOutLine, 1, nWidth, nDim);
	pOutLine += nWidth*nDim;
}

void CGaussianPyramid2::VDownScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim)
{
	int y;
	short *pInLines[5];

	pInLines[0] = pInLines[1] = pInLines[2] = pInImage;
	pInLines[3] = pInLines[2] + nWidth*nDim;
	pInLines[4] = pInLines[3] + nWidth*nDim;

	short *pOutLine = pOutImage;
	for (y = 0; y < nHeight - 2; y++)
	{
		if ((y & 1) == 0)
		{
			VDownScaleShortLine(pInLines, pOutLine, nWidth, nDim);
			pOutLine += nWidth*nDim;
		}

		pInLines[0] = pInLines[1];
		pInLines[1] = pInLines[2];
		pInLines[2] = pInLines[3];
		pInLines[3] = pInLines[4];
		pInLines[4] += nWidth*nDim;
	}

	pInLines[4] = pInLines[3];
	for (; y < nHeight; y++)
	{
		if ((y & 1) == 0)
		{
			VDownScaleShortLine(pInLines, pOutLine, nWidth, nDim);
			pOutLine += nWidth*nDim;
		}

		pInLines[0] = pInLines[1];
		pInLines[1] = pInLines[2];
		pInLines[2] = pInLines[3];
		pInLines[3] = pInLines[4];
	}
}

void CGaussianPyramid2::VDownScaleShortImage2(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim)
{
	int y;
	short *pInLines[6];

	pInLines[0] = pInLines[1] = pInLines[2] = pInImage;
	pInLines[3] = pInLines[2] + nWidth*nDim;
	pInLines[4] = pInLines[3] + nWidth*nDim;
	pInLines[5] = pInLines[4] + nWidth*nDim;

	short *pOutLine = pOutImage;
	for (y = 0; y < nHeight - 3; y += 2)
	{
		VDownScaleShortLine2(pInLines, pOutLine, nWidth, nDim);
		pOutLine += nWidth*nDim;

		pInLines[0] = pInLines[2];
		pInLines[1] = pInLines[3];
		pInLines[2] = pInLines[4];
		pInLines[3] = pInLines[5];
		pInLines[4] += 2 * nWidth*nDim;
		pInLines[5] += 2 * nWidth*nDim;
	}

	pInLines[4] = pInLines[2];
	pInLines[5] = pInLines[3];
	for (; y < nHeight; y += 2)
	{
		VDownScaleShortLine2(pInLines, pOutLine, nWidth, nDim);
		pOutLine += nWidth*nDim;

		pInLines[0] = pInLines[2];
		pInLines[1] = pInLines[3];
		pInLines[2] = pInLines[4];
		pInLines[3] = pInLines[5];
	}
}

bool CGaussianPyramid2::DownScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable)
{
	int i, y;
	WORD *pVLines[5];

	int *nE = new int[nDim];
	if (nE == NULL)return false;
	for (i = 0; i < nDim; i++)
	{
		nE[i] = 0;
	}

	WORD *pBuffer = new WORD[nWidth*nDim * 5];
	if (pBuffer == NULL)
	{
		delete[] nE;
		return false;
	}

	pVLines[0] = pVLines[1] = pVLines[2] = pBuffer;
	pVLines[3] = pVLines[2] + nDim;
	pVLines[4] = pVLines[3] + nDim;

	BYTE *pInLine = pInImage;
	HDownScaleByteLine(pInLine, pVLines[2], nWidth, nDim);
	pInLine += nWidth * nDim;
	HDownScaleByteLine(pInLine, pVLines[3], nWidth, nDim);
	pInLine += nWidth * nDim;

	BYTE *pOutLine = pOutImage;

	for (y = 0; y < 2; y++)
	{
		HDownScaleByteLine(pInLine, pVLines[4], nWidth, nDim);
		pInLine += nWidth * nDim;

		if ((y & 1) == 0)
		{
			VDownScaleByteLine(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
			pOutLine += (nWidth >> 1)*nDim;
		}

		for (i = 0; i < 4; i++)
		{
			pVLines[i] = pVLines[i + 1];
		}
		pVLines[4] += nDim;
	}

	for (; y < nHeight - 2; y++)
	{
		HDownScaleByteLine(pInLine, pVLines[4], nWidth, nDim);
		pInLine += nWidth * nDim;

		if ((y & 1) == 0)
		{
			VDownScaleByteLine(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
			pOutLine += (nWidth >> 1)*nDim;
		}

		WORD *pTemp = pVLines[0];
		for (i = 0; i < 4; i++)
		{
			pVLines[i] = pVLines[i + 1];
		}
		pVLines[4] = pTemp;
	}
	pVLines[4] = pVLines[3];
	for (; y < nHeight; y++)
	{
		if ((y & 1) == 0)
		{
			VDownScaleByteLine(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
			pOutLine += (nWidth >> 1)*nDim;
		}

		for (i = 0; i < 4; i++)
		{
			pVLines[i] = pVLines[i + 1];
		}
	}

	delete[] pBuffer;
	delete[] nE;
	return true;
}

bool CGaussianPyramid2::DownScaleByteImage2(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable)
{
	int i, y;
	int nPitch = (nWidth >> 1)*nDim;
	WORD *pVLines[6];

	int *nE = new int[nDim];
	if (nE == NULL)return false;
	for (i = 0; i < nDim; i++)
	{
		nE[i] = 0;
	}

	WORD *pBuffer = new WORD[nPitch * 6];
	if (pBuffer == NULL)
	{
		delete[] nE;
		return false;
	}

	pVLines[0] = pVLines[1] = pVLines[2] = pBuffer;
	pVLines[3] = pVLines[2] + nPitch;
	pVLines[4] = pVLines[3] + nPitch;
	pVLines[5] = pVLines[4] + nPitch;

	BYTE *pInLine = pInImage;
	HDownScaleByteLine2(pInLine, pVLines[2], nWidth, nDim);
	pInLine += nWidth * nDim;
	HDownScaleByteLine2(pInLine, pVLines[3], nWidth, nDim);
	pInLine += nWidth * nDim;

	BYTE *pOutLine = pOutImage;

	for (y = 0; y < 2; y += 2)
	{
		HDownScaleByteLine2(pInLine, pVLines[4], nWidth, nDim);
		pInLine += nWidth * nDim;
		HDownScaleByteLine2(pInLine, pVLines[5], nWidth, nDim);
		pInLine += nWidth * nDim;

		VDownScaleByteLine2(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += (nWidth >> 1)*nDim;

		pVLines[0] = pVLines[2];
		pVLines[1] = pVLines[3];
		pVLines[2] = pVLines[4];
		pVLines[3] = pVLines[5];
		pVLines[4] += nPitch * 2;
		pVLines[5] += nPitch * 2;
	}

	for (; y < nHeight - 3; y += 2)
	{
		HDownScaleByteLine2(pInLine, pVLines[4], nWidth, nDim);
		pInLine += nWidth * nDim;
		HDownScaleByteLine2(pInLine, pVLines[5], nWidth, nDim);
		pInLine += nWidth * nDim;

		VDownScaleByteLine2(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += (nWidth >> 1)*nDim;

		WORD *pTemp0 = pVLines[0];
		WORD *pTemp1 = pVLines[1];

		pVLines[0] = pVLines[2];
		pVLines[1] = pVLines[3];
		pVLines[2] = pVLines[4];
		pVLines[3] = pVLines[5];
		pVLines[4] = pTemp0;
		pVLines[5] = pTemp1;
	}

	pVLines[4] = pVLines[2];
	pVLines[5] = pVLines[3];
	for (; y < nHeight; y += 2)
	{
		VDownScaleByteLine2(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += (nWidth >> 1)*nDim;

		pVLines[0] = pVLines[2];
		pVLines[1] = pVLines[3];
		pVLines[2] = pVLines[4];
		pVLines[3] = pVLines[5];
	}

	delete[] pBuffer;
	delete[] nE;
	return true;
}

void CGaussianPyramid2::HDownScaleShortLine(short *pInLine, int *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	short *pIn[5];

	pIn[0] = pIn[1] = pIn[2] = pInLine;
	pIn[3] = pIn[2] + nDim;
	pIn[4] = pIn[3] + nDim;

	for (x = 0; x < nWidth - 2; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i];
			Y += pIn[1][i] * 4;
			Y += pIn[2][i] * 6;
			Y += pIn[3][i] * 4;
			Y += pIn[4][i];

			pOutLine[i] = Y;
		}
		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] = pIn[3];
		pIn[3] = pIn[4];
		pIn[4] += nDim;

		pOutLine += nDim * 5;
	}
	pIn[4] = pIn[3];
	for (; x < nWidth; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i];
			Y += pIn[1][i] * 4;
			Y += pIn[2][i] * 6;
			Y += pIn[3][i] * 4;
			Y += pIn[4][i];

			pOutLine[i] = Y;
		}
		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] = pIn[3];
		pIn[3] = pIn[4];

		pOutLine += nDim * 5;
	}
}

void CGaussianPyramid2::VDownScaleShortLine(int *pInLines[], short *pOutLine, int nWidth, int nDim, bool bDitheringEnable, int nE[])
{
	int i, x, Y;
	int *pIn[5];

	for (i = 0; i < 5; i++)
	{
		pIn[i] = pInLines[i];
	}

	for (x = 0; x < (nWidth >> 1); x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i];
			Y += pIn[1][i] * 4;
			Y += pIn[2][i] * 6;
			Y += pIn[3][i] * 4;
			Y += pIn[4][i];

			if (bDitheringEnable)
			{
				Y += nE[i];
				nE[i] = Y - (Y / 256) * 256;
				Y /= 256;
			}
			else
			{
				Y /= 256;
			}

			*(pOutLine++) = (short)Y;
		}

		for (i = 0; i < 5; i++)
		{
			pIn[i] += 10 * nDim;
		}
	}
}

void CGaussianPyramid2::HDownScaleWordLine(WORD *pInLine, int *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	WORD *pIn[5];

	pIn[0] = pIn[1] = pIn[2] = pInLine;
	pIn[3] = pIn[2] + nDim;
	pIn[4] = pIn[3] + nDim;

	for (x = 0; x < nWidth - 2; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i];
			Y += pIn[1][i] * 4;
			Y += pIn[2][i] * 6;
			Y += pIn[3][i] * 4;
			Y += pIn[4][i];

			pOutLine[i] = Y;
		}
		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] = pIn[3];
		pIn[3] = pIn[4];
		pIn[4] += nDim;

		pOutLine += nDim * 5;
	}
	pIn[4] = pIn[3];
	for (; x < nWidth; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i];
			Y += pIn[1][i] * 4;
			Y += pIn[2][i] * 6;
			Y += pIn[3][i] * 4;
			Y += pIn[4][i];

			pOutLine[i] = Y;
		}
		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] = pIn[3];
		pIn[3] = pIn[4];

		pOutLine += nDim * 5;
	}
}

void CGaussianPyramid2::VDownScaleWordLine(int *pInLines[], WORD *pOutLine, int nWidth, int nDim, bool bDitheringEnable, int nE[])
{
	int i, x, Y;
	int *pIn[5];

	for (i = 0; i < 5; i++)
	{
		pIn[i] = pInLines[i];
	}

	for (x = 0; x < (nWidth >> 1); x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i];
			Y += pIn[1][i] * 4;
			Y += pIn[2][i] * 6;
			Y += pIn[3][i] * 4;
			Y += pIn[4][i];

			if (bDitheringEnable)
			{
				Y += nE[i];
				nE[i] = (Y & 255);
				Y >>= 8;
			}
			else
			{
				Y >>= 8;
			}

			*(pOutLine++) = (WORD)Y;
		}

		for (i = 0; i < 5; i++)
		{
			pIn[i] += 10 * nDim;
		}
	}
}

void CGaussianPyramid2::HDownScaleByteLine2(BYTE *pInLine, WORD *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	BYTE *pIn[6];

	pIn[0] = pIn[1] = pIn[2] = pInLine;
	pIn[3] = pIn[2] + nDim;
	pIn[4] = pIn[3] + nDim;
	pIn[5] = pIn[4] + nDim;

	for (x = 0; x < nWidth - 3; x += 2)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int) pIn[0][i];
			Y += (int) pIn[1][i] * 5;
			Y += (int) pIn[2][i] * 10;
			Y += (int) pIn[3][i] * 10;
			Y += (int) pIn[4][i] * 5;
			Y += (int) pIn[5][i];

			pOutLine[i] = (WORD)Y;
		}
		pIn[0] = pIn[2];
		pIn[1] = pIn[3];
		pIn[2] = pIn[4];
		pIn[3] = pIn[5];
		pIn[4] += nDim * 2;
		pIn[5] += nDim * 2;

		pOutLine += nDim;
	}
	pIn[4] = pIn[2];
	pIn[5] = pIn[3];
	for (; x < nWidth; x += 2)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 5;
			Y += (int)pIn[2][i] * 10;
			Y += (int)pIn[3][i] * 10;
			Y += (int)pIn[4][i] * 5;
			Y += (int)pIn[5][i];

			pOutLine[i] = (WORD)Y;
		}
		pIn[0] = pIn[2];
		pIn[1] = pIn[3];
		pIn[2] = pIn[4];
		pIn[3] = pIn[5];

		pOutLine += nDim;
	}
}

void CGaussianPyramid2::HDownScaleShortLine2(short *pInLine, int *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	short *pIn[6];

	pIn[0] = pIn[1] = pIn[2] = pInLine;
	pIn[3] = pIn[2] + nDim;
	pIn[4] = pIn[3] + nDim;
	pIn[5] = pIn[4] + nDim;

	for (x = 0; x < nWidth - 3; x += 2)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 5;
			Y += (int)pIn[2][i] * 10;
			Y += (int)pIn[3][i] * 10;
			Y += (int)pIn[4][i] * 5;
			Y += (int)pIn[5][i];

			pOutLine[i] = Y;
		}
		pIn[0] = pIn[2];
		pIn[1] = pIn[3];
		pIn[2] = pIn[4];
		pIn[3] = pIn[5];
		pIn[4] += nDim * 2;
		pIn[5] += nDim * 2;

		pOutLine += nDim;
	}
	pIn[4] = pIn[2];
	pIn[5] = pIn[3];
	for (; x < nWidth; x += 2)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 5;
			Y += (int)pIn[2][i] * 10;
			Y += (int)pIn[3][i] * 10;
			Y += (int)pIn[4][i] * 5;
			Y += (int)pIn[5][i];

			pOutLine[i] = Y;
		}
		pIn[0] = pIn[2];
		pIn[1] = pIn[3];
		pIn[2] = pIn[4];
		pIn[3] = pIn[5];

		pOutLine += nDim;
	}
}

void CGaussianPyramid2::HDownScaleWordLine2(WORD *pInLine, int *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	WORD *pIn[6];

	pIn[0] = pIn[1] = pIn[2] = pInLine;
	pIn[3] = pIn[2] + nDim;
	pIn[4] = pIn[3] + nDim;
	pIn[5] = pIn[4] + nDim;

	for (x = 0; x < nWidth - 3; x += 2)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 5;
			Y += (int)pIn[2][i] * 10;
			Y += (int)pIn[3][i] * 10;
			Y += (int)pIn[4][i] * 5;
			Y += (int)pIn[5][i];

			pOutLine[i] = Y;
		}
		pIn[0] = pIn[2];
		pIn[1] = pIn[3];
		pIn[2] = pIn[4];
		pIn[3] = pIn[5];
		pIn[4] += nDim * 2;
		pIn[5] += nDim * 2;

		pOutLine += nDim;
	}
	pIn[4] = pIn[2];
	pIn[5] = pIn[3];
	for (; x < nWidth; x += 2)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 5;
			Y += (int)pIn[2][i] * 10;
			Y += (int)pIn[3][i] * 10;
			Y += (int)pIn[4][i] * 5;
			Y += (int)pIn[5][i];

			pOutLine[i] = Y;
		}
		pIn[0] = pIn[2];
		pIn[1] = pIn[3];
		pIn[2] = pIn[4];
		pIn[3] = pIn[5];

		pOutLine += nDim;
	}
}

void CGaussianPyramid2::VDownScaleByteLine2(WORD *pInLines[], BYTE *pOutLine, int nWidth, int nDim, bool bDitheringEnable, int nE[])
{
	int i, x, Y;
	WORD *pIn[6];

	for (i = 0; i < 6; i++)
	{
		pIn[i] = pInLines[i];
	}

	for (x = 0; x < (nWidth >> 1); x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int) pIn[0][i];
			Y += (int) pIn[1][i] * 5;
			Y += (int) pIn[2][i] * 10;
			Y += (int) pIn[3][i] * 10;
			Y += (int) pIn[4][i] * 5;
			Y += (int) pIn[5][i];

			if (bDitheringEnable)
			{
				Y += nE[i];
				nE[i] = (Y & 1023);
			}
			Y >>= 10;

			*(pOutLine++) = (BYTE)Y;
		}

		for (i = 0; i < 6; i++)
		{
			pIn[i] += nDim;
		}
	}
}

void CGaussianPyramid2::VDownScaleShortLine2(int *pInLines[], short *pOutLine, int nWidth, int nDim, bool bDitheringEnable, int nE[])
{
	int i, x, Y;
	int *pIn[6];

	for (i = 0; i < 6; i++)
	{
		pIn[i] = pInLines[i];
	}

	for (x = 0; x < (nWidth >> 1); x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 5;
			Y += (int)pIn[2][i] * 10;
			Y += (int)pIn[3][i] * 10;
			Y += (int)pIn[4][i] * 5;
			Y += (int)pIn[5][i];

			if (bDitheringEnable)
			{
				Y += nE[i];
				nE[i] = Y - (Y / 1024) * 1024;
				Y /= 1024;
			}
			else
			{
				Y /= 1024;
			}

			*(pOutLine++) = (short)Y;
		}

		for (i = 0; i < 6; i++)
		{
			pIn[i] += nDim;
		}
	}
}

void CGaussianPyramid2::VDownScaleWordLine2(int *pInLines[], WORD *pOutLine, int nWidth, int nDim, bool bDitheringEnable, int nE[])
{
	int i, x, Y;
	int *pIn[6];

	for (i = 0; i < 6; i++)
	{
		pIn[i] = pInLines[i];
	}

	for (x = 0; x < (nWidth >> 1); x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 5;
			Y += (int)pIn[2][i] * 10;
			Y += (int)pIn[3][i] * 10;
			Y += (int)pIn[4][i] * 5;
			Y += (int)pIn[5][i];

			if (bDitheringEnable)
			{
				Y += nE[i];
				nE[i] = (Y & 1023);
			}
			Y >>= 10;

			*(pOutLine++) = (WORD)Y;
		}

		for (i = 0; i < 6; i++)
		{
			pIn[i] += nDim;
		}
	}
}

bool CGaussianPyramid2::DownScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable)
{
	int i, y;
	int *pVLines[5];

	int *nE = new int[nDim];
	if (nE == NULL)return false;
	for (i = 0; i < nDim; i++)
	{
		nE[i] = 0;
	}

	int *pBuffer = new int[nWidth*nDim * 5];
	if (pBuffer == NULL)
	{
		delete[] nE;
		return false;
	}

	pVLines[0] = pVLines[1] = pVLines[2] = pBuffer;
	pVLines[3] = pVLines[2] + nDim;
	pVLines[4] = pVLines[3] + nDim;

	short *pInLine = pInImage;
	HDownScaleShortLine(pInLine, pVLines[2], nWidth, nDim);
	pInLine += nWidth * nDim;
	HDownScaleShortLine(pInLine, pVLines[3], nWidth, nDim);
	pInLine += nWidth * nDim;

	short *pOutLine = pOutImage;

	for (y = 0; y < 2; y++)
	{
		HDownScaleShortLine(pInLine, pVLines[4], nWidth, nDim);
		pInLine += nWidth * nDim;

		if ((y & 1) == 0)
		{
			VDownScaleShortLine(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
			pOutLine += (nWidth >> 1)*nDim;
		}

		for (i = 0; i < 4; i++)
		{
			pVLines[i] = pVLines[i + 1];
		}
		pVLines[4] += nDim;
	}

	for (; y < nHeight - 2; y++)
	{
		HDownScaleShortLine(pInLine, pVLines[4], nWidth, nDim);
		pInLine += nWidth * nDim;

		if ((y & 1) == 0)
		{
			VDownScaleShortLine(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
			pOutLine += (nWidth >> 1)*nDim;
		}

		int *pTemp = pVLines[0];
		for (i = 0; i < 4; i++)
		{
			pVLines[i] = pVLines[i + 1];
		}
		pVLines[4] = pTemp;
	}
	pVLines[4] = pVLines[3];
	for (; y < nHeight; y++)
	{
		if ((y & 1) == 0)
		{
			VDownScaleShortLine(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
			pOutLine += (nWidth >> 1)*nDim;
		}

		for (i = 0; i < 4; i++)
		{
			pVLines[i] = pVLines[i + 1];
		}
	}

	delete[] pBuffer;
	delete[] nE;
	return true;
}

bool CGaussianPyramid2::DownScaleShortImage2(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable)
{
	int i, y;
	int nPitch = (nWidth >> 1)*nDim;
	int *pVLines[6];

	int *nE = new int[nDim];
	if (nE == NULL)return false;
	for (i = 0; i < nDim; i++)
	{
		nE[i] = 0;
	}

	int *pBuffer = new int[nPitch * 6];
	if (pBuffer == NULL)
	{
		delete[] nE;
		return false;
	}

	pVLines[0] = pVLines[1] = pVLines[2] = pBuffer;
	pVLines[3] = pVLines[2] + nPitch;
	pVLines[4] = pVLines[3] + nPitch;
	pVLines[5] = pVLines[4] + nPitch;

	short *pInLine = pInImage;
	HDownScaleShortLine2(pInLine, pVLines[2], nWidth, nDim);
	pInLine += nWidth * nDim;
	HDownScaleShortLine2(pInLine, pVLines[3], nWidth, nDim);
	pInLine += nWidth * nDim;

	short *pOutLine = pOutImage;

	for (y = 0; y < 2; y += 2)
	{
		HDownScaleShortLine2(pInLine, pVLines[4], nWidth, nDim);
		pInLine += nWidth * nDim;
		HDownScaleShortLine2(pInLine, pVLines[5], nWidth, nDim);
		pInLine += nWidth * nDim;

		VDownScaleShortLine2(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += (nWidth >> 1)*nDim;

		pVLines[0] = pVLines[2];
		pVLines[1] = pVLines[3];
		pVLines[2] = pVLines[4];
		pVLines[3] = pVLines[5];
		pVLines[4] += nPitch * 2;
		pVLines[5] += nPitch * 2;
	}

	for (; y < nHeight - 3; y += 2)
	{
		HDownScaleShortLine2(pInLine, pVLines[4], nWidth, nDim);
		pInLine += nWidth * nDim;
		HDownScaleShortLine2(pInLine, pVLines[5], nWidth, nDim);
		pInLine += nWidth * nDim;

		VDownScaleShortLine2(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += (nWidth >> 1)*nDim;

		int *pTemp0 = pVLines[0];
		int *pTemp1 = pVLines[1];

		pVLines[0] = pVLines[2];
		pVLines[1] = pVLines[3];
		pVLines[2] = pVLines[4];
		pVLines[3] = pVLines[5];
		pVLines[4] = pTemp0;
		pVLines[5] = pTemp1;
	}

	pVLines[4] = pVLines[2];
	pVLines[5] = pVLines[3];
	for (; y < nHeight; y += 2)
	{
		VDownScaleShortLine2(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += (nWidth >> 1)*nDim;

		pVLines[0] = pVLines[2];
		pVLines[1] = pVLines[3];
		pVLines[2] = pVLines[4];
		pVLines[3] = pVLines[5];
	}

	delete[] pBuffer;
	delete[] nE;
	return true;
}

bool CGaussianPyramid2::DownScaleWordImage(WORD *pInImage, WORD *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable)
{
	int i, y;
	int *pVLines[5];

	int *nE = new int[nDim];
	if (nE == NULL)return false;
	for (i = 0; i < nDim; i++)
	{
		nE[i] = 0;
	}

	int *pBuffer = new int[nWidth*nDim * 5];
	if (pBuffer == NULL)
	{
		delete[] nE;
		return false;
	}

	pVLines[0] = pVLines[1] = pVLines[2] = pBuffer;
	pVLines[3] = pVLines[2] + nDim;
	pVLines[4] = pVLines[3] + nDim;

	WORD *pInLine = pInImage;
	HDownScaleWordLine(pInLine, pVLines[2], nWidth, nDim);
	pInLine += nWidth * nDim;
	HDownScaleWordLine(pInLine, pVLines[3], nWidth, nDim);
	pInLine += nWidth * nDim;

	WORD *pOutLine = pOutImage;

	for (y = 0; y < 2; y++)
	{
		HDownScaleWordLine(pInLine, pVLines[4], nWidth, nDim);
		pInLine += nWidth * nDim;

		if ((y & 1) == 0)
		{
			VDownScaleWordLine(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
			pOutLine += (nWidth >> 1)*nDim;
		}

		for (i = 0; i < 4; i++)
		{
			pVLines[i] = pVLines[i + 1];
		}
		pVLines[4] += nDim;
	}

	for (; y < nHeight - 2; y++)
	{
		HDownScaleWordLine(pInLine, pVLines[4], nWidth, nDim);
		pInLine += nWidth * nDim;

		if ((y & 1) == 0)
		{
			VDownScaleWordLine(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
			pOutLine += (nWidth >> 1)*nDim;
		}

		int *pTemp = pVLines[0];
		for (i = 0; i < 4; i++)
		{
			pVLines[i] = pVLines[i + 1];
		}
		pVLines[4] = pTemp;
	}
	pVLines[4] = pVLines[3];
	for (; y < nHeight; y++)
	{
		if ((y & 1) == 0)
		{
			VDownScaleWordLine(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
			pOutLine += (nWidth >> 1)*nDim;
		}

		for (i = 0; i < 4; i++)
		{
			pVLines[i] = pVLines[i + 1];
		}
	}

	delete[] pBuffer;
	delete[] nE;
	return true;
}

bool CGaussianPyramid2::DownScaleWordImage2(WORD *pInImage, WORD *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable)
{
	int i, y;
	int nPitch = (nWidth >> 1)*nDim;
	int *pVLines[6];

	int *nE = new int[nDim];
	if (nE == NULL)return false;
	for (i = 0; i < nDim; i++)
	{
		nE[i] = 0;
	}

	int *pBuffer = new int[nPitch * 6];
	if (pBuffer == NULL)
	{
		delete[] nE;
		return false;
	}

	pVLines[0] = pVLines[1] = pVLines[2] = pBuffer;
	pVLines[3] = pVLines[2] + nPitch;
	pVLines[4] = pVLines[3] + nPitch;
	pVLines[5] = pVLines[4] + nPitch;

	WORD *pInLine = pInImage;
	HDownScaleWordLine2(pInLine, pVLines[2], nWidth, nDim);
	pInLine += nWidth * nDim;
	HDownScaleWordLine2(pInLine, pVLines[3], nWidth, nDim);
	pInLine += nWidth * nDim;

	WORD *pOutLine = pOutImage;

	for (y = 0; y < 2; y += 2)
	{
		HDownScaleWordLine2(pInLine, pVLines[4], nWidth, nDim);
		pInLine += nWidth * nDim;
		HDownScaleWordLine2(pInLine, pVLines[5], nWidth, nDim);
		pInLine += nWidth * nDim;

		VDownScaleWordLine2(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += (nWidth >> 1)*nDim;

		pVLines[0] = pVLines[2];
		pVLines[1] = pVLines[3];
		pVLines[2] = pVLines[4];
		pVLines[3] = pVLines[5];
		pVLines[4] += nPitch * 2;
		pVLines[5] += nPitch * 2;
	}

	for (; y < nHeight - 3; y += 2)
	{
		HDownScaleWordLine2(pInLine, pVLines[4], nWidth, nDim);
		pInLine += nWidth * nDim;
		HDownScaleWordLine2(pInLine, pVLines[5], nWidth, nDim);
		pInLine += nWidth * nDim;

		VDownScaleWordLine2(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += (nWidth >> 1)*nDim;

		int *pTemp0 = pVLines[0];
		int *pTemp1 = pVLines[1];

		pVLines[0] = pVLines[2];
		pVLines[1] = pVLines[3];
		pVLines[2] = pVLines[4];
		pVLines[3] = pVLines[5];
		pVLines[4] = pTemp0;
		pVLines[5] = pTemp1;
	}

	pVLines[4] = pVLines[2];
	pVLines[5] = pVLines[3];
	for (; y < nHeight; y += 2)
	{
		VDownScaleWordLine2(pVLines, pOutLine, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += (nWidth >> 1)*nDim;

		pVLines[0] = pVLines[2];
		pVLines[1] = pVLines[3];
		pVLines[2] = pVLines[4];
		pVLines[3] = pVLines[5];
	}

	delete[] pBuffer;
	delete[] nE;
	return true;
}

void CGaussianPyramid2::HUpScaleByteLine(BYTE *pInLine, WORD *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	BYTE *pIn[3];

	pIn[0] = pIn[1] = pInLine;
	pIn[2] = pIn[1] + nDim;

	for (x = 0; x < nWidth - 1; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i];
			Y += pIn[1][i] * 6;
			Y += pIn[2][i];
			Y >>= 2;

			pOutLine[i] = (WORD)Y;
		}
		pOutLine += nDim;
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[1][i];
			Y += pIn[2][i];

			pOutLine[i] = (WORD)Y;
		}
		pOutLine += nDim;

		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] += nDim;
	}
	pIn[2] = pIn[1];
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i];
			Y += pIn[1][i] * 6;
			Y += pIn[2][i];
			Y >>= 2;

			pOutLine[i] = (WORD)Y;
		}
		pOutLine += nDim;
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[1][i];
			Y += pIn[2][i];

			pOutLine[i] = (WORD)Y;
		}
		pOutLine += nDim;
	}
}

void CGaussianPyramid2::HUpScaleByteLine2(BYTE *pInLine, WORD *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	BYTE *pIn[2];

	pIn[0] = pIn[1] = pInLine;

	for (x = 0; x < nWidth - 1; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 3;
			pOutLine[i] = (WORD)Y;
		}
		pOutLine += nDim;
		pIn[0] = pIn[1];
		pIn[1] += nDim;

		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i] * 3;
			Y += (int)pIn[1][i];
			pOutLine[i] = (WORD)Y;
		}
		pOutLine += nDim;
	}
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 3;
			pOutLine[i] = (WORD)Y;
		}
		pOutLine += nDim;
		pIn[0] = pIn[1];

		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i] * 3;
			Y += (int)pIn[1][i];
			pOutLine[i] = (WORD)Y;
		}
		pOutLine += nDim;
	}
}

void CGaussianPyramid2::HUpScaleShortLine2(short *pInLine, int *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	short *pIn[2];

	pIn[0] = pIn[1] = pInLine;

	for (x = 0; x < nWidth - 1; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 3;
			pOutLine[i] = Y;
		}
		pOutLine += nDim;
		pIn[0] = pIn[1];
		pIn[1] += nDim;

		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i] * 3;
			Y += (int)pIn[1][i];
			pOutLine[i] = Y;
		}
		pOutLine += nDim;
	}
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 3;
			pOutLine[i] = Y;
		}
		pOutLine += nDim;
		pIn[0] = pIn[1];

		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i] * 3;
			Y += (int)pIn[1][i];
			pOutLine[i] = Y;
		}
		pOutLine += nDim;
	}
}

void CGaussianPyramid2::HUpScaleWordLine2(WORD *pInLine, int *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	WORD *pIn[2];

	pIn[0] = pIn[1] = pInLine;

	for (x = 0; x < nWidth - 1; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 3;
			pOutLine[i] = Y;
		}
		pOutLine += nDim;
		pIn[0] = pIn[1];
		pIn[1] += nDim;

		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i] * 3;
			Y += (int)pIn[1][i];
			pOutLine[i] = Y;
		}
		pOutLine += nDim;
	}
	{
		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i];
			Y += (int)pIn[1][i] * 3;
			pOutLine[i] = Y;
		}
		pOutLine += nDim;
		pIn[0] = pIn[1];

		for (i = 0; i < nDim; i++)
		{
			Y = (int)pIn[0][i] * 3;
			Y += (int)pIn[1][i];
			pOutLine[i] = Y;
		}
		pOutLine += nDim;
	}
}

void CGaussianPyramid2::HUpScaleByteLine(BYTE *pInLine, BYTE *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	BYTE *pIn[3];

	pIn[0] = pIn[1] = pInLine;
	pIn[2] = pIn[1] + nDim;

	for (x = 0; x < nWidth - 1; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i] + pIn[2][i];
			Y += pIn[1][i] * 6;
			Y >>= 3;

			pOutLine[i] = (BYTE)Y;
		}
		pOutLine += nDim;
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[1][i] + pIn[2][i];
			Y >>= 1;

			pOutLine[i] = (BYTE)Y;
		}
		pOutLine += nDim;

		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] += nDim;
	}
	pIn[2] = pIn[1];
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i] + pIn[2][i];
			Y += pIn[1][i] * 6;
			Y >>= 3;

			pOutLine[i] = (BYTE)Y;
		}
		pOutLine += nDim;
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[1][i] + pIn[2][i];
			Y >>= 1;

			pOutLine[i] = (BYTE)Y;
		}
		pOutLine += nDim;
	}
}

void CGaussianPyramid2::HUpScaleShortLine(short *pInLine, short *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	short *pIn[3];

	pIn[0] = pIn[1] = pInLine;
	pIn[2] = pIn[1] + nDim;

	for (x = 0; x < nWidth - 1; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i] + pIn[2][i];
			Y += pIn[1][i] * 6;
			Y /= 8;

			pOutLine[i] = (short)Y;
		}
		pOutLine += nDim;
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[1][i] + pIn[2][i];
			Y /= 2;

			pOutLine[i] = (short)Y;
		}
		pOutLine += nDim;

		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] += nDim;
	}
	pIn[2] = pIn[1];
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i] + pIn[2][i];
			Y += pIn[1][i] * 6;
			Y /= 8;

			pOutLine[i] = (short)Y;
		}
		pOutLine += nDim;
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[1][i] + pIn[2][i];
			Y /= 2;

			pOutLine[i] = (short)Y;
		}
		pOutLine += nDim;
	}
}

void CGaussianPyramid2::VUpScaleByteLine(WORD *pInLines[], BYTE *pOutLine, int bYFlag, int nWidth, int nDim, bool bDitheringEnable, int nE[])
{
	int i, x, Y;
	WORD *pIn[3];

	for (i = 0; i < 3; i++)
	{
		pIn[i] = pInLines[i];
	}

	if (bYFlag == 0)
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = pIn[0][i];
				Y += pIn[1][i] * 6;
				Y += pIn[2][i];
				Y >>= 2;

				if (bDitheringEnable)
				{
					Y += nE[i];
					nE[i] = (Y & 3);
				}
				Y >>= 2;

				*(pOutLine++) = (BYTE)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
			pIn[2] += nDim;
		}
	}
	else
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = pIn[1][i];
				Y += pIn[2][i];

				if (bDitheringEnable)
				{
					Y += nE[i];
					nE[i] = (Y & 3);
				}
				Y >>= 2;

				*(pOutLine++) = (BYTE)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
			pIn[2] += nDim;
		}
	}
}

void CGaussianPyramid2::VUpScaleByteLine2(WORD *pInLines[], BYTE *pOutLine, int bYFlag, int nWidth, int nDim, bool bDitheringEnable, int nE[])
{
	int i, x, Y;
	WORD *pIn[2];

	for (i = 0; i < 2; i++)
	{
		pIn[i] = pInLines[i];
	}

	if (bYFlag == 0)
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = (int) pIn[0][i];
				Y += (int) pIn[1][i] * 3;

				if (bDitheringEnable)
				{
					Y += nE[i];
					nE[i] = (Y & 15);
				}
				Y >>= 4;

				*(pOutLine++) = (BYTE)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
		}
	}
	else
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = (int)pIn[0][i] * 3;
				Y += (int)pIn[1][i];

				if (bDitheringEnable)
				{
					Y += nE[i];
					nE[i] = (Y & 15);
				}
				Y >>= 4;

				*(pOutLine++) = (BYTE)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
		}
	}
}

void CGaussianPyramid2::VUpScaleShortLine2(int *pInLines[], short *pOutLine, int bYFlag, int nWidth, int nDim, bool bDitheringEnable, int nE[])
{
	int i, x, Y;
	int *pIn[2];

	for (i = 0; i < 2; i++)
	{
		pIn[i] = pInLines[i];
	}

	if (bYFlag == 0)
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = (int)pIn[0][i];
				Y += (int)pIn[1][i] * 3;

				if (bDitheringEnable)
				{
					Y += nE[i];
					nE[i] = Y - (Y / 16) * 16;
				}
				Y /= 16;

				*(pOutLine++) = (short)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
		}
	}
	else
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = (int)pIn[0][i] * 3;
				Y += (int)pIn[1][i];

				if (bDitheringEnable)
				{
					Y += nE[i];
					nE[i] = Y - (Y / 16) * 16;
				}
				Y /= 16;

				*(pOutLine++) = (short)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
		}
	}
}

void CGaussianPyramid2::VUpScaleWordLine2(int *pInLines[], WORD *pOutLine, int bYFlag, int nWidth, int nDim, bool bDitheringEnable, int nE[])
{
	int i, x, Y;
	int *pIn[2];

	for (i = 0; i < 2; i++)
	{
		pIn[i] = pInLines[i];
	}

	if (bYFlag == 0)
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = (int)pIn[0][i];
				Y += (int)pIn[1][i] * 3;

				if (bDitheringEnable)
				{
					Y += nE[i];
					nE[i] = (Y & 15);
				}
				Y >>= 4;

				*(pOutLine++) = (WORD)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
		}
	}
	else
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = (int)pIn[0][i] * 3;
				Y += (int)pIn[1][i];

				if (bDitheringEnable)
				{
					Y += nE[i];
					nE[i] = (Y & 15);
				}
				Y >>= 4;

				*(pOutLine++) = (WORD)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
		}
	}
}

void CGaussianPyramid2::VUpScaleByteLine(BYTE *pInLines[], BYTE *pOutLine, int bYFlag, int nWidth, int nDim)
{
	int i, x, Y;
	BYTE *pIn[3];

	for (i = 0; i < 3; i++)
	{
		pIn[i] = pInLines[i];
	}

	if (bYFlag == 0)
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = pIn[0][i];
				Y += pIn[1][i] * 6;
				Y += pIn[2][i];
				Y >>= 3;

				*(pOutLine++) = (BYTE)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
			pIn[2] += nDim;
		}
	}
	else
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = pIn[1][i];
				Y += pIn[2][i];
				Y >>= 1;

				*(pOutLine++) = (BYTE)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
			pIn[2] += nDim;
		}
	}
}

void CGaussianPyramid2::VUpScaleShortLine(short *pInLines[], short *pOutLine, int bYFlag, int nWidth, int nDim)
{
	int i, x, Y;
	short *pIn[3];

	for (i = 0; i < 3; i++)
	{
		pIn[i] = pInLines[i];
	}

	if (bYFlag == 0)
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = pIn[0][i];
				Y += pIn[1][i] * 6;
				Y += pIn[2][i];
				Y /= 8;

				*(pOutLine++) = (short)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
			pIn[2] += nDim;
		}
	}
	else
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = pIn[1][i];
				Y += pIn[2][i];
				Y /= 2;

				*(pOutLine++) = (short)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
			pIn[2] += nDim;
		}
	}
}

bool CGaussianPyramid2::UpScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable)
{
	int i, y;
	int *nE = new int[nDim];
	if (nE == NULL)return false;

	for (i = 0; i < nDim; i++)
	{
		nE[i] = 0;
	}

	WORD *pBuffer = new WORD[nWidth * 6 * nDim];
	if (pBuffer == NULL)
	{
		delete[] nE;
		return false;
	}

	WORD *pVLines[3];
	pVLines[0] = pVLines[1] = pBuffer;
	pVLines[2] = pVLines[1] + nWidth * 2 * nDim;

	BYTE *pInLine = pInImage;

	HUpScaleByteLine(pInLine, pVLines[1], nWidth, nDim);
	pInLine += nWidth*nDim;

	BYTE *pOutLine = pOutImage;
	for (y = 0; y < 1; y++)
	{
		HUpScaleByteLine(pInLine, pVLines[2], nWidth, nDim);
		pInLine += nWidth*nDim;

		VUpScaleByteLine(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;

		VUpScaleByteLine(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;

		pVLines[0] = pVLines[1];
		pVLines[1] = pVLines[2];
		pVLines[2] += nWidth * 2 * nDim;
	}
	for (; y < nHeight - 1; y++)
	{
		HUpScaleByteLine(pInLine, pVLines[2], nWidth, nDim);
		pInLine += nWidth*nDim;

		VUpScaleByteLine(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;

		VUpScaleByteLine(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;

		WORD *pTemp = pVLines[0];
		pVLines[0] = pVLines[1];
		pVLines[1] = pVLines[2];
		pVLines[2] = pTemp;
	}
	pVLines[2] = pVLines[1];
	{
		VUpScaleByteLine(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;

		VUpScaleByteLine(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;
	}

	delete[] nE;
	delete[] pBuffer;
	return true;
}

bool CGaussianPyramid2::UpScaleByteImage2(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable)
{
	int i, y;
	int *nE = new int[nDim];
	if (nE == NULL)return false;
	int nPitch = nWidth * 2 * nDim;

	for (i = 0; i < nDim; i++)
	{
		nE[i] = 0;
	}

	WORD *pBuffer = new WORD[nPitch * 2];
	if (pBuffer == NULL)
	{
		delete[] nE;
		return false;
	}

	WORD *pVLines[2];
	pVLines[0] = pVLines[1] = pBuffer;

	BYTE *pInLine = pInImage;
	HUpScaleByteLine2(pInLine, pVLines[1], nWidth, nDim);
	pInLine += nWidth*nDim;

	BYTE *pOutLine = pOutImage;
	for (y = 0; y < 1; y++)
	{
		VUpScaleByteLine2(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;

		pVLines[0] = pVLines[1];
		pVLines[1] += nPitch;
		HUpScaleByteLine2(pInLine, pVLines[1], nWidth, nDim);
		pInLine += nWidth*nDim;

		VUpScaleByteLine2(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;
	}
	for (; y < nHeight - 1; y++)
	{
		VUpScaleByteLine2(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;

		WORD *pTemp = pVLines[0];
		pVLines[0] = pVLines[1];
		pVLines[1] = pTemp;
		HUpScaleByteLine2(pInLine, pVLines[1], nWidth, nDim);
		pInLine += nWidth*nDim;

		VUpScaleByteLine2(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;
	}
	{
		VUpScaleByteLine2(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;

		pVLines[0] = pVLines[1];

		VUpScaleByteLine2(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;
	}

	delete[] nE;
	delete[] pBuffer;
	return true;
}

bool CGaussianPyramid2::UpScaleShortImage2(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable)
{
	int i, y;
	int *nE = new int[nDim];
	if (nE == NULL)return false;
	int nPitch = nWidth * 2 * nDim;

	for (i = 0; i < nDim; i++)
	{
		nE[i] = 0;
	}

	int *pBuffer = new int[nPitch * 2];
	if (pBuffer == NULL)
	{
		delete[] nE;
		return false;
	}

	int *pVLines[2];
	pVLines[0] = pVLines[1] = pBuffer;

	short *pInLine = pInImage;
	HUpScaleShortLine2(pInLine, pVLines[1], nWidth, nDim);
	pInLine += nWidth*nDim;

	short *pOutLine = pOutImage;
	for (y = 0; y < 1; y++)
	{
		VUpScaleShortLine2(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;

		pVLines[0] = pVLines[1];
		pVLines[1] += nPitch;
		HUpScaleShortLine2(pInLine, pVLines[1], nWidth, nDim);
		pInLine += nWidth*nDim;

		VUpScaleShortLine2(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;
	}
	for (; y < nHeight - 1; y++)
	{
		VUpScaleShortLine2(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;

		int *pTemp = pVLines[0];
		pVLines[0] = pVLines[1];
		pVLines[1] = pTemp;
		HUpScaleShortLine2(pInLine, pVLines[1], nWidth, nDim);
		pInLine += nWidth*nDim;

		VUpScaleShortLine2(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;
	}
	{
		VUpScaleShortLine2(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;

		pVLines[0] = pVLines[1];

		VUpScaleShortLine2(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;
	}

	delete[] nE;
	delete[] pBuffer;
	return true;
}

bool CGaussianPyramid2::UpScaleWordImage2(WORD *pInImage, WORD *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable)
{
	int i, y;
	int *nE = new int[nDim];
	if (nE == NULL)return false;
	int nPitch = nWidth * 2 * nDim;

	for (i = 0; i < nDim; i++)
	{
		nE[i] = 0;
	}

	int *pBuffer = new int[nPitch * 2];
	if (pBuffer == NULL)
	{
		delete[] nE;
		return false;
	}

	int *pVLines[2];
	pVLines[0] = pVLines[1] = pBuffer;

	WORD *pInLine = pInImage;
	HUpScaleWordLine2(pInLine, pVLines[1], nWidth, nDim);
	pInLine += nWidth*nDim;

	WORD *pOutLine = pOutImage;
	for (y = 0; y < 1; y++)
	{
		VUpScaleWordLine2(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;

		pVLines[0] = pVLines[1];
		pVLines[1] += nPitch;
		HUpScaleWordLine2(pInLine, pVLines[1], nWidth, nDim);
		pInLine += nWidth*nDim;

		VUpScaleWordLine2(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;
	}
	for (; y < nHeight - 1; y++)
	{
		VUpScaleWordLine2(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;

		int *pTemp = pVLines[0];
		pVLines[0] = pVLines[1];
		pVLines[1] = pTemp;
		HUpScaleWordLine2(pInLine, pVLines[1], nWidth, nDim);
		pInLine += nWidth*nDim;

		VUpScaleWordLine2(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;
	}
	{
		VUpScaleWordLine2(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;

		pVLines[0] = pVLines[1];

		VUpScaleWordLine2(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nPitch;
	}

	delete[] nE;
	delete[] pBuffer;
	return true;
}

void CGaussianPyramid2::HUpScaleShortLine(short *pInLine, int *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	short *pIn[3];

	pIn[0] = pIn[1] = pInLine;
	pIn[2] = pIn[1] + nDim;

	for (x = 0; x < nWidth - 1; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i];
			Y += pIn[1][i] * 6;
			Y += pIn[2][i];
			Y /= 4;

			pOutLine[i] = Y;
		}
		pOutLine += nDim;
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[1][i];
			Y += pIn[2][i];

			pOutLine[i] = Y;
		}
		pOutLine += nDim;

		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] += nDim;
	}
	pIn[2] = pIn[1];
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i];
			Y += pIn[1][i] * 6;
			Y += pIn[2][i];
			Y /= 4;

			pOutLine[i] = Y;
		}
		pOutLine += nDim;
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[1][i];
			Y += pIn[2][i];

			pOutLine[i] = Y;
		}
		pOutLine += nDim;
	}
}

void CGaussianPyramid2::VUpScaleShortLine(int *pInLines[], short *pOutLine, int bYFlag, int nWidth, int nDim, bool bDitheringEnable, int nE[])
{
	int i, x, Y;
	int *pIn[3];

	for (i = 0; i < 3; i++)
	{
		pIn[i] = pInLines[i];
	}

	if (bYFlag == 0)
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = pIn[0][i];
				Y += pIn[1][i] * 6;
				Y += pIn[2][i];
				Y /= 4;

				if (bDitheringEnable)
				{
					Y += nE[i];
					nE[i] = Y - (Y / 4) * 4;
				}
				Y /= 4;

				*(pOutLine++) = (short)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
			pIn[2] += nDim;
		}
	}
	else
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = pIn[1][i];
				Y += pIn[2][i];

				if (bDitheringEnable)
				{
					Y += nE[i];
					nE[i] = Y - (Y / 4) * 4;
				}
				Y /= 4;

				*(pOutLine++) = (short)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
			pIn[2] += nDim;
		}
	}
}

bool CGaussianPyramid2::UpScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable)
{
	int i, y;
	int *nE = NULL;

	int *pBuffer = new int[nWidth * 6 * nDim + nDim];
	if (pBuffer == NULL)
	{
		return false;
	}
	nE = pBuffer + nWidth * 6 * nDim;
	for (i = 0; i < nDim; i++)
	{
		nE[i] = 0;
	}

	int *pVLines[3];
	pVLines[0] = pVLines[1] = pBuffer;
	pVLines[2] = pVLines[1] + nWidth * 2 * nDim;

	short *pInLine = pInImage;

	HUpScaleShortLine(pInLine, pVLines[1], nWidth, nDim);
	pInLine += nWidth*nDim;

	short *pOutLine = pOutImage;
	for (y = 0; y < 1; y++)
	{
		HUpScaleShortLine(pInLine, pVLines[2], nWidth, nDim);
		pInLine += nWidth*nDim;

		VUpScaleShortLine(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;

		VUpScaleShortLine(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;

		pVLines[0] = pVLines[1];
		pVLines[1] = pVLines[2];
		pVLines[2] += nWidth * 2 * nDim;
	}
	for (; y < nHeight - 1; y++)
	{
		HUpScaleShortLine(pInLine, pVLines[2], nWidth, nDim);
		pInLine += nWidth*nDim;

		VUpScaleShortLine(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;

		VUpScaleShortLine(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;

		int *pTemp = pVLines[0];
		pVLines[0] = pVLines[1];
		pVLines[1] = pVLines[2];
		pVLines[2] = pTemp;
	}
	pVLines[2] = pVLines[1];
	{
		VUpScaleShortLine(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;

		VUpScaleShortLine(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;
	}

	delete[] pBuffer;
	return true;
}

void CGaussianPyramid2::HUpScaleWordLine(WORD *pInLine, int *pOutLine, int nWidth, int nDim)
{
	int i, x, Y;
	WORD *pIn[3];

	pIn[0] = pIn[1] = pInLine;
	pIn[2] = pIn[1] + nDim;

	for (x = 0; x < nWidth - 1; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i];
			Y += pIn[1][i] * 6;
			Y += pIn[2][i];
			Y >>= 2;

			pOutLine[i] = Y;
		}
		pOutLine += nDim;
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[1][i];
			Y += pIn[2][i];

			pOutLine[i] = Y;
		}
		pOutLine += nDim;

		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] += nDim;
	}
	pIn[2] = pIn[1];
	{
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[0][i];
			Y += pIn[1][i] * 6;
			Y += pIn[2][i];
			Y >>= 2;

			pOutLine[i] = Y;
		}
		pOutLine += nDim;
		for (i = 0; i < nDim; i++)
		{
			Y = pIn[1][i];
			Y += pIn[2][i];

			pOutLine[i] = Y;
		}
		pOutLine += nDim;
	}
}

void CGaussianPyramid2::VUpScaleWordLine(int *pInLines[], WORD *pOutLine, int bYFlag, int nWidth, int nDim, bool bDitheringEnable, int nE[])
{
	int i, x, Y;
	int *pIn[3];

	for (i = 0; i < 3; i++)
	{
		pIn[i] = pInLines[i];
	}

	if (bYFlag == 0)
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = pIn[0][i];
				Y += pIn[1][i] * 6;
				Y += pIn[2][i];
				Y >>= 2;

				if (bDitheringEnable)
				{
					Y += nE[i];
					nE[i] = Y & 3;
				}
				Y >>= 2;

				*(pOutLine++) = (WORD)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
			pIn[2] += nDim;
		}
	}
	else
	{
		for (x = 0; x < nWidth * 2; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = pIn[1][i];
				Y += pIn[2][i];

				if (bDitheringEnable)
				{
					Y += nE[i];
					nE[i] = Y&3;
				}
				Y >>= 2;

				*(pOutLine++) = (WORD)Y;
			}

			pIn[0] += nDim;
			pIn[1] += nDim;
			pIn[2] += nDim;
		}
	}
}

bool CGaussianPyramid2::UpScaleWordImage(WORD *pInImage, WORD *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable)
{
	int i, y;
	int *nE = NULL;

	int *pBuffer = new int[nWidth * 6 * nDim + nDim];
	if (pBuffer == NULL)
	{
		return false;
	}
	nE = pBuffer + nWidth * 6 * nDim;
	for (i = 0; i < nDim; i++)
	{
		nE[i] = 0;
	}

	int *pVLines[3];
	pVLines[0] = pVLines[1] = pBuffer;
	pVLines[2] = pVLines[1] + nWidth * 2 * nDim;

	WORD *pInLine = pInImage;

	HUpScaleWordLine(pInLine, pVLines[1], nWidth, nDim);
	pInLine += nWidth*nDim;

	WORD *pOutLine = pOutImage;
	for (y = 0; y < 1; y++)
	{
		HUpScaleWordLine(pInLine, pVLines[2], nWidth, nDim);
		pInLine += nWidth*nDim;

		VUpScaleWordLine(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;

		VUpScaleWordLine(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;

		pVLines[0] = pVLines[1];
		pVLines[1] = pVLines[2];
		pVLines[2] += nWidth * 2 * nDim;
	}
	for (; y < nHeight - 1; y++)
	{
		HUpScaleWordLine(pInLine, pVLines[2], nWidth, nDim);
		pInLine += nWidth*nDim;

		VUpScaleWordLine(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;

		VUpScaleWordLine(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;

		int *pTemp = pVLines[0];
		pVLines[0] = pVLines[1];
		pVLines[1] = pVLines[2];
		pVLines[2] = pTemp;
	}
	pVLines[2] = pVLines[1];
	{
		VUpScaleWordLine(pVLines, pOutLine, 0, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;

		VUpScaleWordLine(pVLines, pOutLine, 1, nWidth, nDim, bDitheringEnable, nE);
		pOutLine += nWidth * 2 * nDim;
	}

	delete[] pBuffer;
	return true;
}

void CGaussianPyramid2::SubtractByteEdge(BYTE *pInImage0, BYTE *pInImage1, short *pOutImage, int nWidth, int nHeight, int nDim)
{
	int i, x, y, Y;
	
	BYTE *pIn0 = pInImage0;
	BYTE *pIn1 = pInImage1;
	short *pOut = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		for (x = 0; x < nWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = *(pIn0++);
				Y -= *(pIn1++);
				*(pOut++) = (short)Y;
			}
		}
	}
}

void CGaussianPyramid2::SubtractShortEdge(short *pInImage0, short *pInImage1, short *pOutImage, int nWidth, int nHeight, int nDim)
{
	int i, x, y, Y;

	short *pIn0 = pInImage0;
	short *pIn1 = pInImage1;
	short *pOut = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		for (x = 0; x < nWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = *(pIn0++);
				Y -= *(pIn1++);
				*(pOut++) = (short)Y;
			}
		}
	}
}

void CGaussianPyramid2::SubtractWordEdge(WORD *pInImage0, WORD *pInImage1, short *pOutImage, int nWidth, int nHeight, int nDim)
{
	int i, x, y, Y;

	WORD *pIn0 = pInImage0;
	WORD *pIn1 = pInImage1;
	short *pOut = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		for (x = 0; x < nWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = *(pIn0++);
				Y -= *(pIn1++);
				if (Y < -32768)Y = -32768;	if (Y > 32767)Y = 32767;

				*(pOut++) = (short)Y;
			}
		}
	}
}

void CGaussianPyramid2::AddBackByteEdge(BYTE *pInImage, short *pEdgeImage, BYTE *pOutImage, int nWidth, int nHeight, int nEdgeWidth, int nEdgeHeight, int nDim)
{
	int i, x, y, Y;

	BYTE *pIn = pInImage;
	BYTE *pOut = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		short *pE = pEdgeImage + y*nEdgeWidth*nDim;
		for (x = 0; x < nWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = *(pIn++);
				Y += *(pE++);
				if (Y < 0)Y = 0;	if (Y > 255)Y = 255;
				*(pOut++) = (BYTE)Y;
			}
		}
	}
}

void CGaussianPyramid2::AddBackShortEdge(short *pInImage, short *pEdgeImage, short *pOutImage, int nWidth, int nHeight, int nEdgeWidth, int nEdgeHeight, int nDim)
{
	int i, x, y, Y;

	short *pIn = pInImage;
	short *pOut = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		short *pE = pEdgeImage + y*nEdgeWidth*nDim;
		for (x = 0; x < nWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = *(pIn++);
				Y += *(pE++);
				*(pOut++) = (short)Y;
			}
		}
	}
}

void CGaussianPyramid2::AddBackWordEdge(WORD *pInImage, short *pEdgeImage, WORD *pOutImage, int nWidth, int nHeight, int nEdgeWidth, int nEdgeHeight, int nDim)
{
	int i, x, y, Y;

	WORD *pIn = pInImage;
	WORD *pOut = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		short *pE = pEdgeImage + y*nEdgeWidth*nDim;
		for (x = 0; x < nWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = *(pIn++);
				Y += *(pE++);
				if (Y < 0)Y = 0;	if (Y > 65535)Y = 65535;
				*(pOut++) = (WORD)Y;
			}
		}
	}
}

void CGaussianPyramid2::SimpleHDownScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, int nS)
{
	int i, j, x, y, Y;

	BYTE *pIn = pInImage;
	BYTE *pOut = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		for (x = 0; x < (nWidth >> nS); x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = 0;
				for (j = 0; j < (1 << nS); j++)
				{
					Y += pIn[i + j*nDim];
				}
				Y >>= nS;
				*(pOut++) = (BYTE)Y;
			}
			pIn += (nDim << nS);
		}
	}
}

void CGaussianPyramid2::SimpleHUpScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, int nS)
{
	int i, j, k, x, y, Y, Y0, Y1;
	int N1 = (1 << (nS - 1));
	int N2 = (1 << nS);
	int N3 = (1 << (nS + 1));

	for (y = 0; y < nHeight; y++)
	{
		BYTE *pIn = pInImage + y*nWidth*nDim;
		BYTE *pOut = pOutImage + y*(nWidth << nS)*nDim;
		BYTE *pPrev = pIn;
		for (x = 0; x < nWidth; x++)
		{
			for (j = N1, k = 2 * j + 1; j < N2; j++, k += 2)
			{
				for (i = 0; i < nDim; i++)
				{
					Y0 = pPrev[i];
					Y1 = pIn[i];
					Y = (Y0*(N3 - k) + Y1*k) >> (nS + 1);
					*(pOut++) = (BYTE)Y;
				}
			}
			pPrev = pIn;
			if (x < nWidth - 1)
			{
				pIn += nDim;
			}
			for (j = 0, k = 2 * j + 1; j < N1; j++, k += 2)
			{
				for (i = 0; i < nDim; i++)
				{
					Y0 = pPrev[i];
					Y1 = pIn[i];
					Y = (Y0*(N3 - k) + Y1*k) >> (nS + 1);
					*(pOut++) = (BYTE)Y;
				}
			}
		}
	}
}

void CGaussianPyramid2::SimpleHUpScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, int nS)
{
	int i, j, k, x, y, Y, Y0, Y1;
	int N1 = (1 << (nS - 1));
	int N2 = (1 << nS);
	int N3 = (1 << (nS + 1));

	short *pIn = pInImage;
	short *pOut = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		short *pIn = pInImage + y*nWidth*nDim;
		short *pOut = pOutImage + y*(nWidth << nS)*nDim;
		short *pPrev = pIn;
		for (x = 0; x < nWidth; x++)
		{
			for (j = N1, k = 2 * j + 1; j < N2; j++, k += 2)
			{
				for (i = 0; i < nDim; i++)
				{
					Y0 = pPrev[i];
					Y1 = pIn[i];
					Y = (Y0*(N3 - k) + Y1*k) / N3;
					*(pOut++) = (short)Y;
				}
			}
			pPrev = pIn;
			if (x < nWidth - 1)
			{
				pIn += nDim;
			}
			for (j = 0, k = 2 * j + 1; j < N1; j++, k += 2)
			{
				for (i = 0; i < nDim; i++)
				{
					Y0 = pPrev[i];
					Y1 = pIn[i];
					Y = (Y0*(N3 - k) + Y1*k) / N3;
					*(pOut++) = (short)Y;
				}
			}
		}
	}
}

void CGaussianPyramid2::SimpleHDownScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, int nS)
{
	int i, j, x, y, Y;

	short *pIn = pInImage;
	short *pOut = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		for (x = 0; x < (nWidth >> nS); x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = 0;
				for (j = 0; j < (1 << nS); j++)
				{
					Y += pIn[i + j*nDim];
				}
				Y >>= nS;
				*(pOut++) = (short)Y;
			}
			pIn += (nDim << nS);
		}
	}
}

void CGaussianPyramid2::SimpleVDownScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, int nS)
{
	int i, j, x, y, Y;

	BYTE *pOut = pOutImage;
	for (y = 0; y < (nHeight >> nS); y++)
	{
		BYTE *pIn = pInImage + (y << nS)*nWidth*nDim;
		for (x = 0; x < nWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = 0;
				for (j = 0; j < (1 << nS); j++)
				{
					Y += pIn[j*nWidth*nDim + i];
				}
				Y >>= nS;
				*(pOut++) = (BYTE)Y;
			}
			pIn += nDim;
		}
	}
}

void CGaussianPyramid2::SimpleVUpScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, int nS)
{
	int i, j, k, x, y, Y, Y1, Y0;
	int N1 = (1 << (nS - 1));
	int N2 = (1 << nS);
	int N3 = (1 << (nS + 1));

	BYTE *pInLine = pInImage;
	BYTE *pPrevLine = pInLine;
	BYTE *pOut = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		for (j = N1, k = 2 * j + 1; j < N2; j++, k += 2)
		{
			BYTE *pIn = pInLine;
			BYTE *pPrev = pPrevLine;
			for (x = 0; x < nWidth; x++)
			{
				for (i = 0; i < nDim; i++)
				{
					Y0 = *(pPrev++);
					Y1 = *(pIn++);
					Y = (Y0*(N3 - k) + Y1*k) >> (nS + 1);
					*(pOut++) = (BYTE)Y;
				}
			}
		}
		pPrevLine = pInLine;
		if (y < nHeight - 1)
		{
			pInLine += nWidth*nDim;
		}
		for (j = 0, k = 2 * j + 1; j < N1; j++, k += 2)
		{
			BYTE *pIn = pInLine;
			BYTE *pPrev = pPrevLine;
			for (x = 0; x < nWidth; x++)
			{
				for (i = 0; i < nDim; i++)
				{
					Y0 = *(pPrev++);
					Y1 = *(pIn++);
					Y = (Y0*(N3 - k) + Y1*k) >> (nS + 1);
					*(pOut++) = (BYTE)Y;
				}
			}
		}
	}
}

void CGaussianPyramid2::SimpleVUpScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, int nS)
{
	int i, j, k, x, y, Y, Y1, Y0;
	int N1 = (1 << (nS - 1));
	int N2 = (1 << nS);
	int N3 = (1 << (nS + 1));

	short *pInLine = pInImage;
	short *pPrevLine = pInLine;
	short *pOut = pOutImage;
	for (y = 0; y < nHeight; y++)
	{
		for (j = N1, k = 2 * j + 1; j < N2; j++, k += 2)
		{
			short *pIn = pInLine;
			short *pPrev = pPrevLine;
			for (x = 0; x < nWidth; x++)
			{
				for (i = 0; i < nDim; i++)
				{
					Y0 = *(pPrev++);
					Y1 = *(pIn++);
					Y = (Y0*(N3 - k) + Y1*k) / N3;
					*(pOut++) = (short)Y;
				}
			}
		}
		pPrevLine = pInLine;
		if (y < nHeight - 1)
		{
			pInLine += nWidth*nDim;
		}
		for (j = 0, k = 2 * j + 1; j < N1; j++, k += 2)
		{
			short *pIn = pInLine;
			short *pPrev = pPrevLine;
			for (x = 0; x < nWidth; x++)
			{
				for (i = 0; i < nDim; i++)
				{
					Y0 = *(pPrev++);
					Y1 = *(pIn++);
					Y = (Y0*(N3 - k) + Y1*k) / N3;
					*(pOut++) = (short)Y;
				}
			}
		}
	}
}

void CGaussianPyramid2::SimpleVDownScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, int nS)
{
	int i, j, x, y, Y;

	short *pOut = pOutImage;
	for (y = 0; y < (nHeight >> nS); y++)
	{
		short *pIn = pInImage + (y << nS)*nWidth*nDim;
		for (x = 0; x < nWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = 0;
				for (j = 0; j < (1 << nS); j++)
				{
					Y += pIn[j*nWidth*nDim + i];
				}
				Y >>= nS;
				*(pOut++) = (short)Y;
			}
			pIn += nDim;
		}
	}
}

void CGaussianPyramid2::SimpleHVDownScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, int nS)
{
	int i, j, k, x, y, Y;

	BYTE *pOut = pOutImage;
	for (y = 0; y < (nHeight >> nS); y++)
	{
		BYTE *pIn = pInImage + (y << nS)*nWidth*nDim;
		for (x = 0; x < (nWidth >> nS); x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = 0;
				for (j = 0; j < (1 << nS); j++)
				{
					for (k = 0; k < (1 << nS); k++)
					{
						Y += pIn[i + (j*nWidth + k)*nDim];
					}
				}
				Y >>= (2 * nS);
				*(pOut++) = (BYTE)Y;
			}
			pIn += (nDim << nS);
		}
	}
}

void CGaussianPyramid2::SimpleHVDownScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, int nS)
{
	int i, j, k, x, y, Y;

	short *pOut = pOutImage;
	for (y = 0; y < (nHeight >> nS); y++)
	{
		short *pIn = pInImage + (y << nS)*nWidth*nDim;
		for (x = 0; x < (nWidth >> nS); x++)
		{
			for (i = 0; i < nDim; i++)
			{
				Y = 0;
				for (j = 0; j < (1 << nS); j++)
				{
					for (k = 0; k < (1 << nS); k++)
					{
						Y += pIn[i + (j*nWidth + k)*nDim];
					}
				}
				Y >>= (2 * nS);
				*(pOut++) = (short)Y;
			}
			pIn += (nDim << nS);
		}
	}
}

bool CGaussianPyramid2::SimpleHVDownScaleImage(CYUV420Image *pInImage, CRGBYUVImage *pOutImage)
{
	int x, y, Y;
	int nWidth = pInImage->GetWidth();
	int nHeight = pInImage->GetHeight();

	if (!pOutImage->Create(nWidth / 2, nHeight / 2))return false;
	
	for (y = 0; y < nHeight / 2; y++)
	{
		BYTE *pIn0 = pInImage->GetYLine(y * 2);
		BYTE *pIn1 = pInImage->GetYLine(y * 2 + 1);
		BYTE *pOut = pOutImage->GetImageLine(y);
		BYTE *pUV = pInImage->GetUVLine(y * 2);
		for (x = 0; x < nWidth / 2; x++)
		{
			Y = *(pIn0++);
			Y += *(pIn0++);
			Y += *(pIn1++);
			Y += *(pIn1++);
			Y >>= 2;

			pOut[0] = (BYTE)Y;
			pOut[1] = *(pUV++);
			pOut[2] = *(pUV++);

			pOut += 3;
 		}
	}

	return true;
}

bool CGaussianPyramid2::SimpleHVUpScaleImage(CRGBYUVImage *pInImage, CYUV420Image *pOutImage)
{
	int x, y;
	int nWidth = pInImage->GetWidth();
	int nHeight = pInImage->GetHeight();
	CGrayImage YImage, TempImage;

	if (!YImage.Create(nWidth, nHeight))return false;
	if (!pOutImage->Create(nWidth << 1, nHeight << 1))return false;

	for (y = 0; y < nHeight; y++)
	{
		BYTE *pYUV = pInImage->GetImageLine(y);
		BYTE *pY = YImage.GetImageLine(y);
		BYTE *pUV = pOutImage->GetUVLine(y * 2);
		for (x = 0; x < nWidth; x++)
		{
			*(pY++) = *(pYUV++);
			*(pUV++) = *(pYUV++);
			*(pUV++) = *(pYUV++);
		}
	}

	if (!SimpleHUpScaleImage(&YImage, &TempImage))return false;

	SimpleVUpScaleByteImage(TempImage.GetImageData(), pOutImage->GetYImage(), nWidth << 1, nHeight, 1, 1);

	return true;
}

void CGaussianPyramid2::HBicubicUpScale2ByteLine(BYTE *pInLine, BYTE *pOutLine, int nWidth, int nDim)
{
	int i, j, x, iY[4], oY;
	BYTE *pIn[4];

	pIn[0] = pIn[1] = pIn[2] = pInLine;
	pIn[3] = pIn[2] + nDim;

	for (x = 0; x < nWidth - 2; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			for (j = 0; j < 4; j++)
			{
				iY[j] = pIn[j][i];
			}
			oY = (-iY[0] * 5 + iY[1] * 35 + iY[2] * 105 - iY[3] * 7) / 128;
			if (oY < 0)oY = 0;	if (oY > 255)oY = 255;
			//if (oY > iY[1] && oY > iY[2])
			//{
			//	oY = MAX2(iY[1], iY[2]);
			//}
			//else if (oY < iY[1] && oY < iY[2])
			//{
			//	oY = MIN2(iY[1], iY[2]);
			//}

			*(pOutLine++) = (BYTE)oY;
		}
		pIn[0] = pIn[1];
		pIn[1] = pIn[2]; 
		pIn[2] = pIn[3];
		pIn[3] += nDim;

		for (i = 0; i < nDim; i++)
		{
			for (j = 0; j < 4; j++)
			{
				iY[j] = pIn[j][i];
			}
			oY = (-iY[3] * 5 + iY[2] * 35 + iY[1] * 105 - iY[0] * 7) / 128;
			if (oY < 0)oY = 0;			if (oY > 255)oY = 255;
			//if (oY > iY[1] && oY > iY[2])
			//{
			//	oY = MAX2(iY[1], iY[2]);
			//}
			//else if (oY < iY[1] && oY < iY[2])
			//{
			//	oY = MIN2(iY[1], iY[2]);
			//}

			*(pOutLine++) = (BYTE)oY;
		}
	}

	for (; x < nWidth; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			for (j = 0; j < 4; j++)
			{
				iY[j] = pIn[j][i];
			}
			oY = (-iY[0] * 5 + iY[1] * 35 + iY[2] * 105 - iY[3] * 7) / 128;
			if (oY < 0)oY = 0;			if (oY > 255)oY = 255;
			//if (oY > iY[1] && oY > iY[2])
			//{
			//	oY = MAX2(iY[1], iY[2]);
			//}
			//else if (oY < iY[1] && oY < iY[2])
			//{
			//	oY = MIN2(iY[1], iY[2]);
			//}

			*(pOutLine++) = (BYTE)oY;
		}
		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] = pIn[3];

		for (i = 0; i < nDim; i++)
		{
			for (j = 0; j < 4; j++)
			{
				iY[j] = pIn[j][i];
			}
			oY = (-iY[3] * 5 + iY[2] * 35 + iY[1] * 105 - iY[0] * 7) / 128;
			if (oY < 0)oY = 0;			if (oY > 255)oY = 255;
			//if (oY > iY[1] && oY > iY[2])
			//{
			//	oY = MAX2(iY[1], iY[2]);
			//}
			//else if (oY < iY[1] && oY < iY[2])
			//{
			//	oY = MIN2(iY[1], iY[2]);
			//}

			*(pOutLine++) = (BYTE)oY;
		}
	}
}

void CGaussianPyramid2::HBicubicUpScale2ShortLine(short *pInLine, short *pOutLine, int nWidth, int nDim, int nMin, int nMax)
{
	int i, j, x, iY[4], oY;
	short *pIn[4];

	pIn[0] = pIn[1] = pIn[2] = pInLine;
	pIn[3] = pIn[2] + nDim;

	for (x = 0; x < nWidth - 2; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			for (j = 0; j < 4; j++)
			{
				iY[j] = pIn[j][i];
			}
			oY = (-iY[0] * 5 + iY[1] * 35 + iY[2] * 105 - iY[3] * 7) / 128;
			if (oY < nMin)oY = nMin;	if (oY > nMax)oY = nMax;
			//if (oY > iY[1] && oY > iY[2])
			//{
			//	oY = MAX2(iY[1], iY[2]);
			//}
			//else if (oY < iY[1] && oY < iY[2])
			//{
			//	oY = MIN2(iY[1], iY[2]);
			//}

			*(pOutLine++) = (short)oY;
		}
		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] = pIn[3];
		pIn[3] += nDim;

		for (i = 0; i < nDim; i++)
		{
			for (j = 0; j < 4; j++)
			{
				iY[j] = pIn[j][i];
			}
			oY = (-iY[3] * 5 + iY[2] * 35 + iY[1] * 105 - iY[0] * 7) / 128;
			if (oY < nMin)oY = nMin;	if (oY > nMax)oY = nMax;
			//if (oY > iY[1] && oY > iY[2])
			//{
			//	oY = MAX2(iY[1], iY[2]);
			//}
			//else if (oY < iY[1] && oY < iY[2])
			//{
			//	oY = MIN2(iY[1], iY[2]);
			//}

			*(pOutLine++) = (short)oY;
		}
	}

	for (; x < nWidth; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			for (j = 0; j < 4; j++)
			{
				iY[j] = pIn[j][i];
			}
			oY = (-iY[0] * 5 + iY[1] * 35 + iY[2] * 105 - iY[3] * 7) / 128;
			if (oY < nMin)oY = nMin;	if (oY > nMax)oY = nMax;
			//if (oY > iY[1] && oY > iY[2])
			//{
			//	oY = MAX2(iY[1], iY[2]);
			//}
			//else if (oY < iY[1] && oY < iY[2])
			//{
			//	oY = MIN2(iY[1], iY[2]);
			//}

			*(pOutLine++) = (short)oY;
		}
		pIn[0] = pIn[1];
		pIn[1] = pIn[2];
		pIn[2] = pIn[3];

		for (i = 0; i < nDim; i++)
		{
			for (j = 0; j < 4; j++)
			{
				iY[j] = pIn[j][i];
			}
			oY = (-iY[3] * 5 + iY[2] * 35 + iY[1] * 105 - iY[0] * 7) / 128;
			if (oY < nMin)oY = nMin;	if (oY > nMax)oY = nMax;
			//if (oY > iY[1] && oY > iY[2])
			//{
			//	oY = MAX2(iY[1], iY[2]);
			//}
			//else if (oY < iY[1] && oY < iY[2])
			//{
			//	oY = MIN2(iY[1], iY[2]);
			//}

			*(pOutLine++) = (short)oY;
		}
	}
}

void CGaussianPyramid2::VBicubicUpScale2ByteLine(BYTE *pInLines[], BYTE *pOutLine, int nWidth, int nDim, int bYFlag)
{
	int i, j, x, iY[4], oY;
	BYTE *pIn[4];

	for (j = 0; j < 4; j++)
	{
		pIn[j] = pInLines[j];
	}

	if (bYFlag == 0)
	{
		for (x = 0; x < nWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				for (j = 0; j < 4; j++)
				{
					iY[j] = pIn[j][i];
				}
				oY = (-iY[0] * 5 + iY[1] * 35 + iY[2] * 105 - iY[3] * 7) / 128;
				if (oY < 0)oY = 0;	if (oY > 255)oY = 255;
				//if (oY > iY[1] && oY > iY[2])
				//{
				//	oY = MAX2(iY[1], iY[2]);
				//}
				//else if (oY < iY[1] && oY < iY[2])
				//{
				//	oY = MIN2(iY[1], iY[2]);
				//}

				*(pOutLine++) = (BYTE)oY;
			}
			for (j = 0; j < 4; j++)
			{
				pIn[j] += nDim;
			}
		}
	}
	else
	{
		for (x = 0; x < nWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				for (j = 0; j < 4; j++)
				{
					iY[j] = pIn[j][i];
				}
				oY = (-iY[3] * 5 + iY[2] * 35 + iY[1] * 105 - iY[0] * 7) / 128;
				if (oY < 0)oY = 0;	if (oY > 255)oY = 255;
				//if (oY > iY[1] && oY > iY[2])
				//{
				//	oY = MAX2(iY[1], iY[2]);
				//}
				//else if (oY < iY[1] && oY < iY[2])
				//{
				//	oY = MIN2(iY[1], iY[2]);
				//}

				*(pOutLine++) = (BYTE)oY;
			}
			for (j = 0; j < 4; j++)
			{
				pIn[j] += nDim;
			}
		}
	}
}

void CGaussianPyramid2::VBicubicUpScale2ShortLine(short *pInLines[], short *pOutLine, int nWidth, int nDim, int nMin, int nMax, int bYFlag)
{
	int i, j, x, iY[4], oY;
	short *pIn[4];

	for (j = 0; j < 4; j++)
	{
		pIn[j] = pInLines[j];
	}

	if (bYFlag == 0)
	{
		for (x = 0; x < nWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				for (j = 0; j < 4; j++)
				{
					iY[j] = pIn[j][i];
				}
				oY = (-iY[0] * 5 + iY[1] * 35 + iY[2] * 105 - iY[3] * 7) / 128;
				if (oY < nMin)oY = nMin;	if (oY > nMax)oY = nMax;
				//if (oY > iY[1] && oY > iY[2])
				//{
				//	oY = MAX2(iY[1], iY[2]);
				//}
				//else if (oY < iY[1] && oY < iY[2])
				//{
				//	oY = MIN2(iY[1], iY[2]);
				//}

				*(pOutLine++) = (short)oY;
			}
			for (j = 0; j < 4; j++)
			{
				pIn[j] += nDim;
			}
		}
	}
	else
	{
		for (x = 0; x < nWidth; x++)
		{
			for (i = 0; i < nDim; i++)
			{
				for (j = 0; j < 4; j++)
				{
					iY[j] = pIn[j][i];
				}
				oY = (-iY[3] * 5 + iY[2] * 35 + iY[1] * 105 - iY[0] * 7) / 128;
				if (oY < nMin)oY = nMin;	if (oY > nMax)oY = nMax;
				//if (oY > iY[1] && oY > iY[2])
				//{
				//	oY = MAX2(iY[1], iY[2]);
				//}
				//else if (oY < iY[1] && oY < iY[2])
				//{
				//	oY = MIN2(iY[1], iY[2]);
				//}

				*(pOutLine++) = (short)oY;
			}
			for (j = 0; j < 4; j++)
			{
				pIn[j] += nDim;
			}
		}
	}
}

bool CGaussianPyramid2::BicubicUpScale2ByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim)
{
	int y;
	BYTE *pHLines[4];
	int nInPitch = nWidth*nDim;
	int nOutPitch = 2 * nWidth*nDim;
	BYTE *pBuffer = new BYTE[nOutPitch * 4];
	if (pBuffer == NULL)return false;

	pHLines[0] = pHLines[1] = pHLines[2] = pBuffer;
	pHLines[3] = pHLines[2] + nOutPitch;

	BYTE *pInLine = pInImage;
	BYTE *pOutLine = pOutImage;

	HBicubicUpScale2ByteLine(pInLine, pHLines[2], nWidth, nDim);
	pInLine += nInPitch;
	HBicubicUpScale2ByteLine(pInLine, pHLines[3], nWidth, nDim);
	pInLine += nInPitch;

	for (y = 0; y < 2; y++)
	{
		VBicubicUpScale2ByteLine(pHLines, pOutLine, nWidth * 2, nDim, 0);
		pOutLine += nOutPitch;

		pHLines[0] = pHLines[1];
		pHLines[1] = pHLines[2];
		pHLines[2] = pHLines[3];
		pHLines[3] += nOutPitch;

		HBicubicUpScale2ByteLine(pInLine, pHLines[3], nWidth, nDim);
		pInLine += nInPitch;
		VBicubicUpScale2ByteLine(pHLines, pOutLine, nWidth * 2, nDim, 1);
		pOutLine += nOutPitch;
	}
	for (; y < nHeight - 2; y++)
	{
		VBicubicUpScale2ByteLine(pHLines, pOutLine, nWidth * 2, nDim, 0);
		pOutLine += nOutPitch;

		BYTE *pTemp = pHLines[0];
		pHLines[0] = pHLines[1];
		pHLines[1] = pHLines[2];
		pHLines[2] = pHLines[3];
		pHLines[3] = pTemp;

		HBicubicUpScale2ByteLine(pInLine, pHLines[3], nWidth, nDim);
		pInLine += nInPitch;
		VBicubicUpScale2ByteLine(pHLines, pOutLine, nWidth * 2, nDim, 1);
		pOutLine += nOutPitch;
	}
	for (; y < nHeight; y++)
	{
		VBicubicUpScale2ByteLine(pHLines, pOutLine, nWidth * 2, nDim, 0);
		pOutLine += nOutPitch;

		pHLines[0] = pHLines[1];
		pHLines[1] = pHLines[2];
		pHLines[2] = pHLines[3];

		VBicubicUpScale2ByteLine(pHLines, pOutLine, nWidth * 2, nDim, 1);
		pOutLine += nOutPitch;
	}

	delete[] pBuffer;
	return true;
}

bool CGaussianPyramid2::BicubicUpScale2ShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, int nMin, int nMax)
{
	int y;
	short *pHLines[4];
	int nInPitch = nWidth*nDim;
	int nOutPitch = 2 * nWidth*nDim;
	short *pBuffer = new short[nOutPitch * 4];
	if (pBuffer == NULL)return false;

	pHLines[0] = pHLines[1] = pHLines[2] = pBuffer;
	pHLines[3] = pHLines[2] + nOutPitch;

	short *pInLine = pInImage;
	short *pOutLine = pOutImage;

	HBicubicUpScale2ShortLine(pInLine, pHLines[2], nWidth, nDim, nMin, nMax);
	pInLine += nInPitch;
	HBicubicUpScale2ShortLine(pInLine, pHLines[3], nWidth, nDim, nMin, nMax);
	pInLine += nInPitch;

	for (y = 0; y < 2; y++)
	{
		VBicubicUpScale2ShortLine(pHLines, pOutLine, nWidth * 2, nDim, nMin, nMax, 0);
		pOutLine += nOutPitch;

		pHLines[0] = pHLines[1];
		pHLines[1] = pHLines[2];
		pHLines[2] = pHLines[3];
		pHLines[3] += nOutPitch;

		HBicubicUpScale2ShortLine(pInLine, pHLines[3], nWidth, nDim, nMin, nMax);
		pInLine += nInPitch;
		VBicubicUpScale2ShortLine(pHLines, pOutLine, nWidth * 2, nDim, nMin, nMax, 1);
		pOutLine += nOutPitch;
	}
	for (; y < nHeight - 2; y++)
	{
		VBicubicUpScale2ShortLine(pHLines, pOutLine, nWidth * 2, nDim, nMin, nMax, 0);
		pOutLine += nOutPitch;

		short *pTemp = pHLines[0];
		pHLines[0] = pHLines[1];
		pHLines[1] = pHLines[2];
		pHLines[2] = pHLines[3];
		pHLines[3] = pTemp;

		HBicubicUpScale2ShortLine(pInLine, pHLines[3], nWidth, nDim, nMin, nMax);
		pInLine += nInPitch;
		VBicubicUpScale2ShortLine(pHLines, pOutLine, nWidth * 2, nDim, nMin, nMax, 1);
		pOutLine += nOutPitch;
	}
	for (; y < nHeight; y++)
	{
		VBicubicUpScale2ShortLine(pHLines, pOutLine, nWidth * 2, nDim, nMin, nMax, 0);
		pOutLine += nOutPitch;

		pHLines[0] = pHLines[1];
		pHLines[1] = pHLines[2];
		pHLines[2] = pHLines[3];

		VBicubicUpScale2ShortLine(pHLines, pOutLine, nWidth * 2, nDim, nMin, nMax, 1);
		pOutLine += nOutPitch;
	}

	delete[] pBuffer;
	return true;
}
