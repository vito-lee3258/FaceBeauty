#include "SmoothFilter.h"

void CSmoothFilter::HSmoothFilterLine(BYTE *pInLine, WORD *pOutLine, int nWidth, int nPitch, int nDim)
{
	int i, j, x;
	WORD In[3][5];

	for (i = 0; i < nDim; i++)
	{
		In[i][0] = In[i][1] = In[i][2] = *(pInLine++);
	}
	for (i = 0; i < nDim; i++)
	{
		In[i][3] = *(pInLine++);
	}

	for (x = 0; x < nWidth - 2; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			In[i][4] = *(pInLine++);

			pOutLine[i] = (In[i][0] + In[i][4]);
			pOutLine[i] += (In[i][1] + In[i][3]) * 4;
			pOutLine[i] += In[i][2] * 6;

			for (j = 0; j < 4; j++)
			{
				In[i][j] = In[i][j + 1];
			}
		}
		pOutLine += nPitch;
	}
	for (; x < nWidth; x++)
	{
		for (i = 0; i < nDim; i++)
		{
			pOutLine[i] = (In[i][0] + In[i][4]);
			pOutLine[i] += (In[i][1] + In[i][3]) * 4;
			pOutLine[i] += In[i][2] * 6;

			for (j = 0; j < 4; j++)
			{
				In[i][j] = In[i][j + 1];
			}
		}
		pOutLine += nPitch;
	}
}

void CSmoothFilter::VSmoothFilterLine(WORD *pInLines[], BYTE *pOutLine, int nE[], int nWidth, int nPitch, int nDim, bool bDitheringEnable)
{
	int i, j, x;
	WORD In[3][5], Out[3];
	WORD *pIn[5];

	for (j = 0; j < 5; j++)
	{
		pIn[j] = pInLines[j];
	}

	for (x = 0; x < nWidth; x++)
	{
		for (j = 0; j < 5; j++)
		{
			for (i = 0; i < nDim; i++)
			{
				In[i][j] = pIn[j][i];
			}
			pIn[j] += nPitch;
		}

		for (i = 0; i < nDim; i++)
		{
			Out[i] = (In[i][0] + In[i][4]);
			Out[i] += (In[i][1] + In[i][3]) * 4;
			Out[i] += In[i][2] * 6;

			if (bDitheringEnable)
			{
				Out[i] += nE[i];
				nE[i] = (Out[i] & 255);
			}
			else
			{
				Out[i] += 128;
			}
			Out[i] >>= 8;

			*(pOutLine++) = (BYTE)Out[i];
		}
	}
}

bool CSmoothFilter::SmoothYUVImage(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage, bool bDitheringEnable)
{
	int i, y;
	int nWidth = pInImage->GetWidth();
	int nHeight = pInImage->GetHeight();
	int nE[3];
	WORD *pHLines[5];

	if (pOutImage->GetWidth() != nWidth || pOutImage->GetHeight() != nHeight)
	{
		if (!pOutImage->Create(nWidth, nHeight))return false;
	}

	WORD *pBuffer = new WORD[nWidth * 15];
	if (pBuffer == NULL)return false;

	pHLines[0] = pHLines[1] = pHLines[2] = pBuffer;
	pHLines[3] = pHLines[2] + 3;
	pHLines[4] = pHLines[3] + 3;

	BYTE *pInLine = pInImage->GetImageData();
	HSmoothFilterLine(pInLine, pHLines[2], nWidth, 15, 3);
	pInLine += nWidth * 3;
	HSmoothFilterLine(pInLine, pHLines[3], nWidth, 15, 3);
	pInLine += nWidth * 3;

	nE[0] = nE[1] = nE[2] = 0;
	for (y = 0; y < 2; y++)
	{
		HSmoothFilterLine(pInLine, pHLines[4], nWidth, 15, 3);
		pInLine += nWidth * 3;

		BYTE *pOutLine = pOutImage->GetImageLine(y);
		VSmoothFilterLine(pHLines, pOutLine, nE, nWidth, 15, 3, bDitheringEnable);

		for (i = 0; i < 4; i++)
		{
			pHLines[i] = pHLines[i + 1];
		}
		pHLines[4] += 3;
	}
	for (; y < nHeight - 2; y++)
	{
		HSmoothFilterLine(pInLine, pHLines[4], nWidth, 15, 3);
		pInLine += nWidth * 3;

		BYTE *pOutLine = pOutImage->GetImageLine(y);
		VSmoothFilterLine(pHLines, pOutLine, nE, nWidth, 15, 3, bDitheringEnable);

		WORD *pTemp = pHLines[0];
		for (i = 0; i < 4; i++)
		{
			pHLines[i] = pHLines[i + 1];
		}
		pHLines[4] = pTemp;
	}
	pHLines[4] = pHLines[3];
	for (; y < nHeight; y++)
	{
		BYTE *pOutLine = pOutImage->GetImageLine(y);
		VSmoothFilterLine(pHLines, pOutLine, nE, nWidth, 15, 3, bDitheringEnable);

		for (i = 0; i < 4; i++)
		{
			pHLines[i] = pHLines[i + 1];
		}
	}

	delete[] pBuffer;
	return true;
}

bool CSmoothFilter::SmoothYImage(CGrayImage *pInImage, CGrayImage *pOutImage, bool bDitheringEnable)
{
	int i, y;
	int nWidth = pInImage->GetWidth();
	int nHeight = pInImage->GetHeight();
	int nE;
	WORD *pHLines[5];

	if (pOutImage->GetWidth() != nWidth || pOutImage->GetHeight() != nHeight)
	{
		if (!pOutImage->Create(nWidth, nHeight))return false;
	}

	WORD *pBuffer = new WORD[nWidth * 5];
	if (pBuffer == NULL)return false;

	pHLines[0] = pHLines[1] = pHLines[2] = pBuffer;
	pHLines[3] = pHLines[2] + 1;
	pHLines[4] = pHLines[3] + 1;

	BYTE *pInLine = pInImage->GetImageData();
	HSmoothFilterLine(pInLine, pHLines[2], nWidth, 5, 1);
	pInLine += nWidth;
	HSmoothFilterLine(pInLine, pHLines[3], nWidth, 5, 1);
	pInLine += nWidth;

	nE = 0;
	for (y = 0; y < 2; y++)
	{
		HSmoothFilterLine(pInLine, pHLines[4], nWidth, 5, 1);
		pInLine += nWidth;

		BYTE *pOutLine = pOutImage->GetImageLine(y);
		VSmoothFilterLine(pHLines, pOutLine, &nE, nWidth, 5, 1, bDitheringEnable);

		for (i = 0; i < 4; i++)
		{
			pHLines[i] = pHLines[i + 1];
		}
		pHLines[4] += 1;
	}
	for (; y < nHeight - 2; y++)
	{
		HSmoothFilterLine(pInLine, pHLines[4], nWidth, 5, 1);
		pInLine += nWidth;

		BYTE *pOutLine = pOutImage->GetImageLine(y);
		VSmoothFilterLine(pHLines, pOutLine, &nE, nWidth, 5, 1, bDitheringEnable);

		WORD *pTemp = pHLines[0];
		for (i = 0; i < 4; i++)
		{
			pHLines[i] = pHLines[i + 1];
		}
		pHLines[4] = pTemp;
	}
	pHLines[4] = pHLines[3];
	for (; y < nHeight; y++)
	{
		BYTE *pOutLine = pOutImage->GetImageLine(y);
		VSmoothFilterLine(pHLines, pOutLine, &nE, nWidth, 5, 1, bDitheringEnable);

		for (i = 0; i < 4; i++)
		{
			pHLines[i] = pHLines[i + 1];
		}
	}

	delete[] pBuffer;
	return true;
}

void CSmoothFilter::FastLocalStatistics(CRGBYUVImage* pIn, CGrayImage* pSkinMask, int nRadius, int nFilterSigma, int nAddNoisePer)
{
	m_nAddNoisePercent = nAddNoisePer;

	int nD = pIn->GetDim();
	int nWidth = pIn->GetWidth();
	int nHeight = pIn->GetHeight();
	int nWinSize = 2 * nRadius + 1;

	int** pLines = new int *[nWinSize];
	int** pVarLines = new int *[nWinSize];
	for (int i = 0; i < nWinSize; i++)
	{
		pLines[i] = new int[nWidth * nD];
		pVarLines[i] = new int[nWidth * nD];
	}

	// top board process.
	TopBoardProcess(pIn, pSkinMask, pLines, pVarLines, nRadius);

	// main loop.
	LocalStatisticsFilter(pIn, pSkinMask, pLines, pVarLines, nRadius, nFilterSigma);

	// bottom line use mirr board type.
	BottomBoardProcess(pIn, pSkinMask, pLines, pVarLines, nRadius, nFilterSigma);

	for (int k = 0; k < nWinSize; k++)
	{
		delete[] pLines[k];
		delete[] pVarLines[k];
	}
	delete[] pLines;
	delete[] pVarLines;
}

void CSmoothFilter::BoxFilter(CGrayImage* pIn, int nRadius)
{
	int nWidth = pIn->GetWidth();
	int nHeight = pIn->GetHeight();
	int nWinSize = 2 * nRadius + 1;

	// pStart board process.
	int **pSumLine = new int*[nRadius + 1];
	for (int y = 0; y <= nRadius; y++)
	{
		pSumLine[y] = new int[nWidth];
		BoxFilterLine(pIn->GetImageLine(y), pSumLine[y], nWidth, nRadius);
	}

	// change order, board type use mirror.
	int **pLines = new int *[nWinSize];
	for (int i = 0; i < nRadius; i++)
	{
		pLines[i] = new int[nWidth];
		memcpy(pLines[i], pSumLine[nRadius - 1 - i], sizeof(int) * nWidth);
	}

	for (int i = nRadius, k = 0; i < nWinSize; i++, k++)
	{
		pLines[i] = new int[nWidth];
		memcpy(pLines[i], pSumLine[k], sizeof(int) * nWidth);
	}

	int dy = 0;
	int Size = nWinSize * nWinSize;
	for (int y = 0; y < nHeight - nRadius; y++)
	{
		BYTE* pInLine = pIn->GetImageLine(y);
		for (int x = 0; x < nWidth; x++)
		{
			unsigned int Sum = 0;
			{
				for (dy = 0; dy < nWinSize; dy++)
				{
					Sum += (pLines[dy][x]);
				}
				if (Sum != 0)// if sum =0, means all data in the window is zero.
				{
					int Mean = Sum / Size;
					pInLine[x] = Clip(Mean);
				}
			}
		}
		for (dy = 0; dy < nWinSize - 1; dy++)
		{
			memcpy(pLines[dy], pLines[dy + 1], (nWidth) * sizeof(int));
		}
		BoxFilterLine(pIn->GetImageLine(y + (nRadius + 1)),pLines[nWinSize - 1], nWidth, nRadius);
	}

	// bottom line use mirr board type.
	for (int i = 0; i < nRadius; i++)
	{
		memcpy(pSumLine[i], pLines[nWinSize - 1 - i], sizeof(int) * nWidth);
	}

	int n = 0;
	for (int y = nHeight - nRadius; y < nHeight; y++)
	{
		BYTE* pInLine = pIn->GetImageLine(y);
		for (int x = 0; x < nWidth; x++)
		{
			unsigned int Sum = 0;
			unsigned int Sum2 = 0;
			{
				for (dy = 0; dy < nWinSize; dy++)
				{
					Sum += (pLines[dy][x]);
				}
				if (Sum != 0)// if sum =0, means all data in the window is zero.
				{
					int Mean = Sum / Size;
					pInLine[x] = Clip(Mean);
				}
			}
		}
		for (dy = 0; dy < nWinSize - 1; dy++)
		{
			memcpy(pLines[dy], pLines[dy + 1], (nWidth) * sizeof(int));
		}
		memcpy(pLines[nWinSize - 1], pSumLine[n], (nWidth) * sizeof(int));
		n++;
	}

	for (int k = 0; k < nRadius + 1; k++)
	{
		delete[] pSumLine[k];
	}
	delete[] pSumLine;

	for (int k = 0; k < nWinSize; k++)
	{
		delete[] pLines[k];
	}
	delete[] pLines;
}

void CSmoothFilter::BoxFilterLine(BYTE* pInLine, int* pOutLine, int nWidth, int nRadius)
{
	int x, dx;
	BYTE* pLine = new BYTE[nWidth + 2 * nRadius];
	BYTE* pStart = new BYTE[nRadius];
	BYTE* pEnd = new BYTE[nRadius];

	// image board type select.
	for (int i = 0; i < nRadius; i++)
	{
		pStart[i] = pInLine[nRadius - i];
		pEnd[i] = pInLine[nWidth - 1 - i];
	}

	memcpy(pLine, pStart, nRadius);
	memcpy(pLine + nRadius, pInLine, nWidth);
	memcpy(pLine + nRadius + nWidth, pEnd, nRadius);

	int k = 0;
	for (x = nRadius; x < nWidth + nRadius; x++)
	{
		int sum = 0;
		for (dx = -nRadius; dx <= nRadius; dx++)
		{
			{
				sum += ((int)pLine[x + dx]);
			}
		}
		pOutLine[k] = sum;
		k++;
	}

	delete pLine;
	delete pStart;
	delete pEnd;
}

void CSmoothFilter::GaussSmooth(CRGBYUVImage* pIn, int nSigma)
{
	int nD = pIn->GetDim();
	int nWidth = pIn->GetWidth();
	int nHeight = pIn->GetHeight();

	float fSigma = nSigma / 256.0;
	GetGaussKernel(fSigma);

	printf("gaussian kernel len=%d\n", m_nKernelLen);
	if (bSaveDebug)
	{
		for (int i = 0; i < m_nKernelLen; i++)
			printf("%d\n", m_pFilter[i]);
	}

	if (m_pFilter == nullptr)
	{
		printf("ERROR:gaussian kernel is empty!!!\n");
		return;
	}

	int** pLines = new int *[m_nKernelLen];
	for (int i = 0; i < m_nKernelLen; i++)
	{
		pLines[i] = new int[nWidth * nD];
	}

	// top board process.
	GaussTopBoardProcess(pIn, pLines);

	// main loop.
	GaussFilter(pIn, pLines, pIn->GetDim());

	// bottom line use mirr board type.
	GaussBottomBoardProcess(pIn, pLines);

	for (int k = 0; k < m_nKernelLen; k++)
	{
		delete[] pLines[k];
	}
	delete[] pLines;
}

int CSmoothFilter::GenConvolveMatrix(double radius, double **cmatrix_p)
{
	double *cmatrix;
	double  std_dev;
	double  sum;
	int     matrix_length;
	int     i, j;

	/* we want to generate a matrix that goes out a certain radius
	* from the center, so we have to go out ceil(rad-0.5) pixels,
	* including the center pixel.  Of course, that's only in one direction,
	* so we have to go the same amount in the other direction, but not count
	* the center pixel again.  So we double the previous result and subtract
	* one.
	* The radius parameter that is passed to this function is used as
	* the standard deviation, and the radius of effect is the
	* standard deviation * 2.  It's a little confusing.
	*/
	radius = fabs(radius) + 1.0;

	std_dev = radius;
	radius = std_dev * 2;

	/* go out 'radius' in each direction */
	matrix_length = 2 * ceil(radius - 0.5) + 1;
	if (matrix_length <= 0)
		matrix_length = 1;

	*cmatrix_p = new double[matrix_length];
	cmatrix = *cmatrix_p;

	/*  Now we fill the matrix by doing a numeric integration approximation
	* from -2*std_dev to 2*std_dev, sampling 50 points per pixel.
	* We do the bottom half, mirror it to the top half, then compute the
	* center point.  Otherwise asymmetric quantization errors will occur.
	*  The formula to integrate is e^-(x^2/2s^2).
	*/

	/* first we do the top (right) half of matrix */
	for (i = matrix_length / 2 + 1; i < matrix_length; i++)
	{
		double base_x = i - (matrix_length / 2) - 0.5;

		sum = 0;
		for (j = 1; j <= 50; j++)
		{
			double r = base_x + 0.02 * j;

			if (r <= radius)
				sum += exp(-SQR(r) / (2 * SQR(std_dev)));
		}

		cmatrix[i] = sum / 50;
	}

	/* mirror the thing to the bottom half */
	for (i = 0; i <= matrix_length / 2; i++)
		cmatrix[i] = cmatrix[matrix_length - 1 - i];

	/* find center val -- calculate an odd number of quanta to make it
	* symmetric, even if the center point is weighted slightly higher
	* than others.
	*/
	sum = 0;
	for (j = 0; j <= 50; j++)
		sum += exp(-SQR(-0.5 + 0.02 * j) / (2 * SQR(std_dev)));

	cmatrix[matrix_length / 2] = sum / 51;

	/* normalize the distribution by scaling the total sum to one */
	sum = 0;
	for (i = 0; i < matrix_length; i++)
		sum += cmatrix[i];

	for (i = 0; i < matrix_length; i++)
		cmatrix[i] = cmatrix[i] / sum;

	return matrix_length;
}

void CSmoothFilter::GetGaussKernel(float fSigma)
{
	float radius = fSigma;

	double *cmatrix = NULL;;
	m_nKernelLen = GenConvolveMatrix(radius, &cmatrix);

	if (bSaveDebug)
	{
		printf("len=%d\n", m_nKernelLen);
		for (int i = 0; i < m_nKernelLen; i++)
			printf("%e\n", cmatrix[i]);
	}

	m_pFilter = new int[m_nKernelLen];

	int sum = 0;
	for (int i = 0; i < m_nKernelLen; i++)
	{
		m_pFilter[i] = (int)(cmatrix[i] * 256 + 0.5);
		sum += m_pFilter[i];
	}

	if (sum != 256)
	{//put rounding error to center
		m_pFilter[m_nKernelLen / 2] += (256 - sum);
	}
}

void CSmoothFilter::GaussTopBoardProcess(CRGBYUVImage* pIn, int** pLines)
{
	int nD = pIn->GetDim();
	int nWidth = pIn->GetWidth();
	int nHeight = pIn->GetHeight();

	int nRadius = ((m_nKernelLen - 1) >> 1);

	int **pSumLine = new int*[nRadius + 1];
	for (int y = 0; y <= nRadius; y++)
	{
		pSumLine[y] = new int[nWidth * nD];
		GaussFilterLine(pIn->GetImageLine(y), pSumLine[y], nWidth, nRadius, nD);
	}

	// change order, board type use mirror.
	for (int i = 0; i < nRadius; i++)
	{
		memcpy(pLines[i], pSumLine[nRadius - 1 - i], sizeof(int) * nWidth * nD);
	}

	for (int i = nRadius, k = 0; i < m_nKernelLen; i++, k++)
	{
		memcpy(pLines[i], pSumLine[k], sizeof(int) * nWidth * nD);
	}

	for (int i = 0; i < nRadius + 1; i++)
	{
		delete[] pSumLine[i];
	}
	delete[] pSumLine;
}

void CSmoothFilter::GaussBottomBoardProcess(CRGBYUVImage* pIn, int** pLines)
{
	int nD = pIn->GetDim();
	int nWidth = pIn->GetWidth();
	int nHeight = pIn->GetHeight();
	int nRadius = ((m_nKernelLen - 1) >> 1);

	// bottom line use mirr board type.
	int **pSumLine = new int*[nRadius];
	for (int i = 0; i < nRadius; i++)
	{
		pSumLine[i] = new int[nWidth * nD];
		memcpy(pSumLine[i], pLines[m_nKernelLen - 1 - i], sizeof(int) * nWidth * nD);
	}

	int n = 0;
	int dy = 0;
	int Size = m_nKernelLen * m_nKernelLen;
	for (int y = nHeight - nRadius; y < nHeight; y++)
	{
		BYTE* pInLine = pIn->GetImageLine(y);
		for (int x = 0; x < nWidth; x++)
		{
			int k = 0;
			int Sum[3] = { 0, 0, 0 };
			for (dy = 0; dy < m_nKernelLen; dy++)
			{
				for (k = 0; k < 3; k++)
				{
					Sum[k] += pLines[dy][3 * x + k] * m_pFilter[dy];
				}
			}

			for (k = 0; k < 3; k++)
			{
				int Value = Sum[k] >> 8;
				pInLine[3 * x + k] = Clip(Value);
			}
		}
		for (dy = 0; dy < m_nKernelLen - 1; dy++)
		{
			memcpy(pLines[dy], pLines[dy + 1], (nWidth) * sizeof(int) * nD);
		}
		memcpy(pLines[m_nKernelLen - 1], pSumLine[n], (nWidth) * sizeof(int) * nD);
		n++;
	}

	for (int i = 0; i < nRadius; i++)
	{
		delete[] pSumLine[i];
	}
	delete[] pSumLine;
}

void CSmoothFilter::GaussFilter(CRGBYUVImage* pIn, int** pLines, int nD)
{
	int nWidth = pIn->GetWidth();
	int nHeight = pIn->GetHeight();

	int nRadius = ((m_nKernelLen - 1) >> 1);

	int dy = 0;
	int n = 0;
	int Size = m_nKernelLen * m_nKernelLen;
	for (int y = 0; y < nHeight - nRadius; y++)
	{
		BYTE* pInLine = pIn->GetImageLine(y);
		for (int x = 0; x < nWidth; x++)
		{
			int Sum[3] = {0, 0, 0};
			for (dy = 0; dy < m_nKernelLen; dy++)
			{
				for (n = 0; n < 3; n++)
				{
					Sum[n] += pLines[dy][3 * x + n] * m_pFilter[dy];
				}
			}

			for (n = 0; n < 3; n++)
			{
				int Value = Sum[n] >> 8;
				pInLine[3 * x + n] = Clip(Value);
			}
		}
		for (dy = 0; dy < m_nKernelLen - 1; dy++)
		{
			memcpy(pLines[dy], pLines[dy + 1], (nWidth) * sizeof(int) * nD);
		}
		GaussFilterLine(pIn->GetImageLine(y + (nRadius + 1)), pLines[m_nKernelLen - 1], nWidth, nRadius, nD);
	}
}

void CSmoothFilter::GaussFilterLine(BYTE* pInLine, int* pOutLine, int nWidth, int nRadius, int nD)
{
	int x, dx;
	BYTE* pLine = new BYTE[(nWidth + 2 * nRadius) * nD];
	BYTE* pStart = new BYTE[nRadius * nD];
	BYTE* pEnd = new BYTE[nRadius * nD];

	// image board type select.
	for (int i = 0; i < nRadius; i++)
	{
		for (int k = 0; k < nD; k++)
		{
			pStart[3 * i + k] = pInLine[3 * (nRadius - i) + k];
			pEnd[3 * i + k] = pInLine[3 * (nWidth - 1 - i) + k];
		}
	}

	memcpy(pLine, pStart, nRadius * nD);
	memcpy(pLine + nRadius * nD, pInLine, nWidth * nD);
	memcpy(pLine + (nRadius + nWidth) * nD, pEnd, nRadius * nD);

	int n = 0;
	int nNum = 0;
	for (x = nRadius; x < nWidth + nRadius; x++)
	{
		int nB = 0, nG = 0, nR = 0;
		int k = 0;
		for (dx = -nRadius; dx <= nRadius; dx++)
		{
			nB += ((int)pLine[3 * (x - dx) + 0] * m_pFilter[k]);
			nG += ((int)pLine[3 * (x - dx) + 1] * m_pFilter[k]);
			nR += ((int)pLine[3 * (x - dx) + 2] * m_pFilter[k]);
			k++;
		}
		
		pOutLine[3 * nNum + 0] = (nB >> 8);
		pOutLine[3 * nNum + 1] = (nG >> 8);
		pOutLine[3 * nNum + 2] = (nR >> 8);

		nNum++;
	}

	delete pLine;
	delete pStart;
	delete pEnd;
}

void CSmoothFilter::SumLine(BYTE* pInLine, BYTE* pMaskLine, int* pOutLine, int* pVarLine, int nWidth, int nD, int nRadius)
{
	int x, dx;
	BYTE* pLine = new BYTE[(nWidth + 2 * nRadius) * nD];
	BYTE* pStart = new BYTE[nRadius * nD];
	BYTE* pEnd = new BYTE[nRadius * nD];

	// image board type select.
	for (int i = 0; i < nRadius; i++)
	{
		for (int k = 0; k < nD; k++)
		{
			pStart[3 * i + k] = pInLine[3 * (nRadius - i) + k];
			pEnd[3 * i + k] = pInLine[3 * (nWidth - 1 - i) + k];
		}
	}

	memcpy(pLine, pStart, nRadius * nD);
	memcpy(pLine + nRadius * nD, pInLine, nWidth * nD);
	memcpy(pLine + (nRadius + nWidth) * nD, pEnd, nRadius * nD);

	int k = 0;
	for (x = nRadius; x < nWidth + nRadius; x++)
	{
		int sum[3] = { 0, 0, 0 };
		int sum2[3] = { 0, 0, 0 };
		for (dx = -nRadius; dx <= nRadius; dx++)
		{
			{
				sum[0] += ((int)pLine[3 * (x + dx) + 0]);
				sum[1] += ((int)pLine[3 * (x + dx) + 1]);
				sum[2] += ((int)pLine[3 * (x + dx) + 2]);

				sum2[0] += (int)pLine[3 * (x + dx) + 0] * (int)pLine[3 * (x + dx) + 0];
				sum2[1] += (int)pLine[3 * (x + dx) + 1] * (int)pLine[3 * (x + dx) + 1];
				sum2[2] += (int)pLine[3 * (x + dx) + 2] * (int)pLine[3 * (x + dx) + 2];
			}
		}
		pOutLine[3 * k + 0] = sum[0];
		pOutLine[3 * k + 1] = sum[1];
		pOutLine[3 * k + 2] = sum[2];

		pVarLine[3 * k + 0] = sum2[0];
		pVarLine[3 * k + 1] = sum2[1];
		pVarLine[3 * k + 2] = sum2[2];

		k++;
	}

	delete pLine;
	delete pStart;
	delete pEnd;
}

void CSmoothFilter::TopBoardProcess(CRGBYUVImage* pIn, CGrayImage* pSkinMask, int** pLines, int** pVarLines, int nRadius)
{
	int nD = pIn->GetDim();
	int nWidth = pIn->GetWidth();
	int nHeight = pIn->GetHeight();
	int nWinSize = 2 * nRadius + 1;

	int **pSumLine = new int*[nRadius + 1];
	int **pSum2Line = new int*[nRadius + 1];
	for (int y = 0; y <= nRadius; y++)
	{
		pSumLine[y] = new int[nWidth * nD];
		pSum2Line[y] = new int[nWidth * nD];

		BYTE* pMaskLine = pSkinMask->GetImageLine(y);
		SumLine(pIn->GetImageLine(y), pMaskLine, pSumLine[y], pSum2Line[y], nWidth, nD, nRadius);
	}

	// change order, board type use mirror.
	for (int i = 0; i < nRadius; i++)
	{
		memcpy(pLines[i], pSumLine[nRadius - 1 - i], sizeof(int) * nWidth * nD);
		memcpy(pVarLines[i], pSum2Line[nRadius - 1 - i], sizeof(int) * nWidth * nD);
	}

	for (int i = nRadius, k = 0; i < nWinSize; i++, k++)
	{
		memcpy(pLines[i], pSumLine[k], sizeof(int) * nWidth * nD);
		memcpy(pVarLines[i], pSum2Line[k], sizeof(int) * nWidth * nD);
	}

	for (int i = 0; i < nRadius + 1; i++)
	{
		delete[] pSumLine[i];
		delete[] pSum2Line[i];
	}
	delete[] pSumLine;
	delete[] pSum2Line;
}

void CSmoothFilter::BottomBoardProcess(CRGBYUVImage* pIn, CGrayImage* pSkinMask, int** pLines, int** pVarLines, int nRadius, int nFilterSigma)
{
	int nD = pIn->GetDim();
	int nWidth = pIn->GetWidth();
	int nHeight = pIn->GetHeight();
	int nWinSize = 2 * nRadius + 1;

	// bottom line use mirr board type.
	int **pSumLine = new int*[nRadius];
	int **pSum2Line = new int*[nRadius];
	for (int i = 0; i < nRadius; i++)
	{
		pSumLine[i] = new int[nWidth * nD];
		pSum2Line[i] = new int[nWidth * nD];

		memcpy(pSumLine[i], pLines[nWinSize - 1 - i], sizeof(int) * nWidth * nD);
		memcpy(pSum2Line[i], pVarLines[nWinSize - 1 - i], sizeof(int) * nWidth * nD);
	}

	int n = 0;
	int dy = 0;
	int Size = nWinSize * nWinSize;
	for (int y = nHeight - nRadius; y < nHeight; y++)
	{
		BYTE* pInLine = pIn->GetImageLine(y);
		for (int x = 0; x < nWidth; x++)
		{
			unsigned int Sum[3] = { 0, 0, 0 };
			unsigned int Sum2[3] = { 0, 0, 0 };
			for (dy = 0; dy < nWinSize; dy++)
			{
				Sum[0] += (pLines[dy][3 * x + 0]);
				Sum[1] += (pLines[dy][3 * x + 1]);
				Sum[2] += (pLines[dy][3 * x + 2]);

				Sum2[0] += (pVarLines[dy][3 * x + 0]);
				Sum2[1] += (pVarLines[dy][3 * x + 1]);
				Sum2[2] += (pVarLines[dy][2 * x + 2]);
			}

			for (int k = 0; k < 3; k++)
			{
				int Mean = Sum[k] / Size;
				int Var = (Sum2[k] - Sum[k] * Mean) / Size;
				int KR = 1024 * Var / (Var + nFilterSigma);

				int Value = (((1024 - KR) * Mean + KR * pInLine[3 * x + k]) >> 10);

				int nDiff = (int)pInLine[3 * x + k] - Value;

				// add part of noise back.
				pInLine[3 * x + k] = Clip(Value + (nDiff * m_nAddNoisePercent / 128));
			}
		}
		for (dy = 0; dy < nWinSize - 1; dy++)
		{
			memcpy(pLines[dy], pLines[dy + 1], (nWidth) * sizeof(int) * nD);
			memcpy(pVarLines[dy], pVarLines[dy + 1], (nWidth) * sizeof(int) * nD);
		}
		memcpy(pLines[nWinSize - 1], pSumLine[n], (nWidth) * sizeof(int) * nD);
		memcpy(pVarLines[nWinSize - 1], pSum2Line[n], (nWidth) * sizeof(int) * nD);
		n++;
	}

	for (int i = 0; i < nRadius; i++)
	{
		delete[] pSumLine[i];
		delete[] pSum2Line[i];
	}
	delete[] pSumLine;
	delete[] pSum2Line;
}

void CSmoothFilter::LocalStatisticsFilter(CRGBYUVImage* pIn, CGrayImage* pSkinMask, int** pLines, int** pVarLines, int nRadius, int nFilterSigma)
{
	int nD = pIn->GetDim();
	int nWidth = pIn->GetWidth();
	int nHeight = pIn->GetHeight();
	int nWinSize = 2 * nRadius + 1;

	int dy = 0;
	int Size = nWinSize * nWinSize;
	for (int y = 0; y < nHeight - nRadius; y++)
	{
		BYTE* pInLine = pIn->GetImageLine(y);
		BYTE* pMaskLine = pSkinMask->GetImageLine(y);
		for (int x = 0; x < nWidth; x++)
		{
			unsigned int Sum[3] = { 0, 0, 0 };
			unsigned int Sum2[3] = { 0, 0, 0 };
			{
				//if (pMaskLine[x] > 0)
				{
					for (dy = 0; dy < nWinSize; dy++)
					{
						Sum[0] += (pLines[dy][3 * x + 0]);
						Sum[1] += (pLines[dy][3 * x + 1]);
						Sum[2] += (pLines[dy][3 * x + 2]);

						Sum2[0] += (pVarLines[dy][3 * x + 0]);
						Sum2[1] += (pVarLines[dy][3 * x + 1]);
						Sum2[2] += (pVarLines[dy][3 * x + 2]);
					}
					for (int n = 0; n < 3; n++)
					{
						int Mean = Sum[n] / Size;
						int Var = (Sum2[n] - Sum[n] * Mean) / Size;
						int KR = 1024 * Var / (Var + nFilterSigma);

						int Value = (((1024 - KR) * Mean + KR * pInLine[3 * x + n]) >> 10);

						int nDiff = (int)pInLine[3 * x + n] - Value;

						// add part of noise back.
						pInLine[3 * x + n] = Clip(Value + (nDiff * m_nAddNoisePercent / 128));
					}
				}
			}
		}
		for (dy = 0; dy < nWinSize - 1; dy++)
		{
			memcpy(pLines[dy], pLines[dy + 1], (nWidth) * sizeof(int) * nD);
			memcpy(pVarLines[dy], pVarLines[dy + 1], (nWidth) * sizeof(int) * nD);
		}
		SumLine(pIn->GetImageLine(y + (nRadius + 1)), pMaskLine, pLines[nWinSize - 1], pVarLines[nWinSize - 1], nWidth, nD, nRadius);
	}
}