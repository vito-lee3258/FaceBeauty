#ifndef __SMOOTH_FILTER5X5_H_
#define __SMOOTH_FILTER5X5_H_

#include "../ImgLib/Filter.h"

#define bSaveDebug 0

class CSmoothFilter
{
protected:
	virtual void HSmoothFilterLine(BYTE *pInLine, WORD *pOutLine, int nWidth, int nPitch, int nDim);
	virtual void VSmoothFilterLine(WORD *pInLines[], BYTE *pOutLine, int nE[], int nWidth, int nPitch, int nDim, bool bDitheringEnable);

	// gaussian filter
	virtual void GaussFilter(CRGBYUVImage* pIn, int** pLines, int nD);
	virtual void GaussTopBoardProcess(CRGBYUVImage* pIn, int** pLines);
	virtual void GaussBottomBoardProcess(CRGBYUVImage* pIn, int** pLines);
	virtual void GaussFilterLine(BYTE* pInLine, int* pOutLine, int nWidth, int nRadius, int nD);
	virtual void GetGaussKernel(float fSigma);
	virtual int GenConvolveMatrix(double radius, double **cmatrix_p);

	// box filter.
	virtual void BoxFilterLine(BYTE* pInLine, int* pOutLine, int nWidth, int nRadius);

	// local stastistics filter.
	virtual void SumLine(BYTE* pInLine, BYTE* pMaskLine, int* pOutLine, int* pVarLine, int nWidth, int nD, int nRadius);
	virtual void TopBoardProcess(CRGBYUVImage* pIn, CGrayImage* pSkinMask, int** pLines, int** pVarLines, int nRadius);
	virtual void BottomBoardProcess(CRGBYUVImage* pIn, CGrayImage* pSkinMask, int** pLines, int** pVarLines, int nRadius, int nFilterSigma);
	virtual void LocalStatisticsFilter(CRGBYUVImage* pIn, CGrayImage* pSkinMask, int** pLines, int** pVarLines, int nRadius, int nFilterSigma);

public:

	virtual bool SmoothYUVImage(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage, bool bDitheringEnable = true);
	virtual bool SmoothYImage(CGrayImage *pInImage, CGrayImage *pOutImage, bool bDitheringEnable = true);

	virtual void FastLocalStatistics(CRGBYUVImage* pIn, CGrayImage* pSkinMask, int nRadius, int nFilterSigma, int nAddNoisePer);

	virtual void BoxFilter(CGrayImage* pIn, int nRadius);
	virtual void GaussSmooth(CRGBYUVImage* pIn, int nRadius);


protected:

	inline int Clip(int value)
	{
		value = value > 255 ? 255 : value;
		value = value < 0 ? 0 : value;

		return value;
	}

	inline double SQR(double x)
	{
		return x * x;
	}
	
private:
	int m_nAddNoisePercent;
	int m_nKernelLen; 
	int* m_pFilter = nullptr;
};

#endif

