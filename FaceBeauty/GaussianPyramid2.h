#ifndef __GAUSSIAN_PYRAMID2_H_
#define __GAUSSIAN_PYRAMID2_H_

#include "../ImgLib/Filter.h"

class CGaussianPyramid2
{
private:
	void HDownScaleByteLine(BYTE *pInLine, WORD *pOutLine, int nWidth, int nDim);
	void VDownScaleByteLine(WORD *pInLines[], BYTE *pOutLine, int nWidth, int nDim, bool bDitheringEnable, int nE[]);
	void HDownScaleShortLine(short *pInLine, int *pOutLine, int nWidth, int nDim);
	void VDownScaleShortLine(int *pInLines[], short *pOutLine, int nWidth, int nDim, bool bDitheringEnable, int nE[]);
	void HDownScaleWordLine(WORD *pInLine, int *pOutLine, int nWidth, int nDim);
	void VDownScaleWordLine(int *pInLines[], WORD *pOutLine, int nWidth, int nDim, bool bDitheringEnable, int nE[]);

	void HDownScaleByteLine2(BYTE *pInLine, WORD *pOutLine, int nWidth, int nDim);
	void VDownScaleByteLine2(WORD *pInLines[], BYTE *pOutLine, int nWidth, int nDim, bool bDitheringEnable, int nE[]);
	void HDownScaleShortLine2(short *pInLine, int *pOutLine, int nWidth, int nDim);
	void VDownScaleShortLine2(int *pInLines[], short *pOutLine, int nWidth, int nDim, bool bDitheringEnable, int nE[]);
	void HDownScaleWordLine2(WORD *pInLine, int *pOutLine, int nWidth, int nDim);
	void VDownScaleWordLine2(int *pInLines[], WORD *pOutLine, int nWidth, int nDim, bool bDitheringEnable, int nE[]);

	void HUpScaleByteLine(BYTE *pInLine, WORD *pOutLine, int nWidth, int nDim);
	void VUpScaleByteLine(WORD *pInLines[], BYTE *pOutLine, int bYFlag, int nWidth, int nDim, bool bDitheringEnable, int nE[]);
	void HUpScaleShortLine(short *pInLine, int *pOutLine, int nWidth, int nDim);
	void VUpScaleShortLine(int *pInLines[], short *pOutLine, int bYFlag, int nWidth, int nDim, bool bDitheringEnable, int nE[]);
	void HUpScaleWordLine(WORD *pInLine, int *pOutLine, int nWidth, int nDim);
	void VUpScaleWordLine(int *pInLines[], WORD *pOutLine, int bYFlag, int nWidth, int nDim, bool bDitheringEnable, int nE[]);

	void HUpScaleByteLine2(BYTE *pInLine, WORD *pOutLine, int nWidth, int nDim);
	void VUpScaleByteLine2(WORD *pInLines[], BYTE *pOutLine, int bYFlag, int nWidth, int nDim, bool bDitheringEnable, int nE[]);
	void HUpScaleShortLine2(short *pInLine, int *pOutLine, int nWidth, int nDim);
	void VUpScaleShortLine2(int *pInLines[], short *pOutLine, int bYFlag, int nWidth, int nDim, bool bDitheringEnable, int nE[]);
	void HUpScaleWordLine2(WORD *pInLine, int *pOutLine, int nWidth, int nDim);
	void VUpScaleWordLine2(int *pInLines[], WORD *pOutLine, int bYFlag, int nWidth, int nDim, bool bDitheringEnable, int nE[]);

	void HDownScaleByteLine(BYTE *pInLine, BYTE *pOutLine, int nWidth, int nDim);
	void VDownScaleByteLine(BYTE *pInLines[], BYTE *pOutLine, int nWidth, int nDim);
	void HDownScaleShortLine(short *pInLine, short *pOutLine, int nWidth, int nDim);
	void VDownScaleShortLine(short *pInLines[], short *pOutLine, int nWidth, int nDim);

	void HUpScaleByteLine(BYTE *pInLine, BYTE *pOutLine, int nWidth, int nDim);
	void VUpScaleByteLine(BYTE *pInLines[], BYTE *pOutLine, int bYFlag, int nWidth, int nDim);
	void HUpScaleShortLine(short *pInLine, short *pOutLine, int nWidth, int nDim);
	void VUpScaleShortLine(short *pInLines[], short *pOutLine, int bYFlag, int nWidth, int nDim);

	void HDownScaleByteLine2(BYTE *pInLine, BYTE *pOutLine, int nWidth, int nDim);
	void VDownScaleByteLine2(BYTE *pInLines[], BYTE *pOutLine, int nWidth, int nDim);
	void HDownScaleShortLine2(short *pInLine, short *pOutLine, int nWidth, int nDim);
	void VDownScaleShortLine2(short *pInLines[], short *pOutLine, int nWidth, int nDim);

	void HBicubicUpScale2ByteLine(BYTE *pInLine, BYTE *pOutLine, int nWidth, int nDim);
	void HBicubicUpScale2ShortLine(short *pInLine, short *pOutLine, int nWidth, int nDim, int nMin, int nMax);

	void VBicubicUpScale2ByteLine(BYTE *pInLines[], BYTE *pOutLine, int nWidth, int nDim, int bYFlag);
	void VBicubicUpScale2ShortLine(short *pInLines[], short *pOutLine, int nWidth, int nDim, int nMin, int nMax, int bYFlag);

protected:
	virtual bool DownScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable);
	virtual bool UpScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable);
	virtual bool DownScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable);
	virtual bool UpScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable);
	virtual bool DownScaleWordImage(WORD *pInImage, WORD *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable);
	virtual bool UpScaleWordImage(WORD *pInImage, WORD *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable);

	virtual bool DownScaleByteImage2(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable);
	virtual bool UpScaleByteImage2(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable);
	virtual bool DownScaleShortImage2(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable);
	virtual bool UpScaleShortImage2(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable);
	virtual bool DownScaleWordImage2(WORD *pInImage, WORD *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable);
	virtual bool UpScaleWordImage2(WORD *pInImage, WORD *pOutImage, int nWidth, int nHeight, int nDim, bool bDitheringEnable);

	virtual void HDownScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim);
	virtual void VDownScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim);
	virtual void HDownScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim);
	virtual void VDownScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim);

	virtual void HDownScaleByteImage2(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim);
	virtual void VDownScaleByteImage2(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim);
	virtual void HDownScaleShortImage2(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim);
	virtual void VDownScaleShortImage2(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim);

	virtual void HUpScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim);
	virtual void VUpScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim);
	virtual void HUpScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim);
	virtual void VUpScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim);


	virtual void FillByteImage(BYTE *pInImage, BYTE *pOutImage, int nInWidth, int nInHeight, int nOutWidth, int nOutHeight, int nDim);
	virtual void FillShortImage(short *pInImage, short *pOutImage, int nInWidth, int nInHeight, int nOutWidth, int nOutHeight, int nDim);
	virtual void FillWordImage(WORD *pInImage, WORD *pOutImage, int nInWidth, int nInHeight, int nOutWidth, int nOutHeight, int nDim);

	virtual void SubtractByteEdge(BYTE *pInImage0, BYTE *pInImage1, short *pOutImage, int nWidth, int nHeight, int nDim);
	virtual void AddBackByteEdge(BYTE *pInImage, short *pEdgeImage, BYTE *pOutImage, int nWidth, int nHeight, int nEdgeWidth, int nEdgeHeight, int nDim);

	virtual void SubtractShortEdge(short *pInImage0, short *pInImage1, short *pOutImage, int nWidth, int nHeight, int nDim);
	virtual void AddBackShortEdge(short *pInImage, short *pEdgeImage, short *pOutImage, int nWidth, int nHeight, int nEdgeWidth, int nEdgeHeight, int nDim);

	virtual void SubtractWordEdge(WORD *pInImage0, WORD *pInImage1, short *pOutImage, int nWidth, int nHeight, int nDim);
	virtual void AddBackWordEdge(WORD *pInImage, short *pEdgeImage, WORD *pOutImage, int nWidth, int nHeight, int nEdgeWidth, int nEdgeHeight, int nDim);

	virtual void SimpleHDownScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, int nS);
	virtual void SimpleVDownScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, int nS);
	virtual void SimpleHVDownScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, int nS);

	virtual void SimpleHDownScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, int nS);
	virtual void SimpleVDownScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, int nS);
	virtual void SimpleHVDownScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, int nS);

	virtual void SimpleHUpScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, int nS);
	virtual void SimpleVUpScaleByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim, int nS);

	virtual void SimpleHUpScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, int nS);
	virtual void SimpleVUpScaleShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, int nS);

	virtual bool BicubicUpScale2ByteImage(BYTE *pInImage, BYTE *pOutImage, int nWidth, int nHeight, int nDim);
	virtual bool BicubicUpScale2ShortImage(short *pInImage, short *pOutImage, int nWidth, int nHeight, int nDim, int nMin, int nMax);

public:
	bool DownScaleImage(CBasicImageArray_BYTE *pInImage, CBasicImageArray_BYTE *pOutImage, bool bDitheringEnable = false, bool bDownSample = false)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();
		if (!pOutImage->SetImageSize(nWidth >> 1, nHeight >> 1, nDim))return false;

		if (bDownSample)
		{
			return DownScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, bDitheringEnable);
		}
		else
		{
			return DownScaleByteImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, bDitheringEnable);
		}
	}
	bool DownScaleImage(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage, bool bDitheringEnable = false, bool bDownSample = false)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		if (!pOutImage->Create(nWidth >> 1, nHeight >> 1))return false;

		if (bDownSample)
		{
			return DownScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 3, bDitheringEnable);
		}
		else
		{
			return DownScaleByteImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 3, bDitheringEnable);
		}
	}
	bool DownScaleImage(CGrayImage *pInImage, CGrayImage *pOutImage, bool bDitheringEnable = false, bool bDownSample = false)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		if (!pOutImage->Create(nWidth >> 1, nHeight >> 1))return false;

		if (bDownSample)
		{
			return DownScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 1, bDitheringEnable);
		}
		else
		{
			return DownScaleByteImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 1, bDitheringEnable);
		}
	}
	bool DownScaleImage(CYUV420Image *pInImage, CRGBYUVImage *pOutImage, bool bDitheringEnable = false, bool bDownSample = false)
	{
		int x, y;
		CGrayImage YImage;
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		
		if (!YImage.Create(nWidth >> 1, nHeight >> 1))return false;
		if (!pOutImage->Create(nWidth >> 1, nHeight >> 1))return false;

		if (bDownSample)
		{
			if (!DownScaleByteImage(pInImage->GetYImage(), YImage.GetImageData(), nWidth, nHeight, 1, bDitheringEnable))return false;
		}
		else
		{
			if (!DownScaleByteImage2(pInImage->GetYImage(), YImage.GetImageData(), nWidth, nHeight, 1, bDitheringEnable))return false;
		}

		for (y = 0; y < (nHeight >> 1); y++)
		{
			BYTE *pY = YImage.GetImageLine(y);
			BYTE *pUV = pInImage->GetUVLine(y * 2);
			BYTE *pYUV = pOutImage->GetImageLine(y);
			for (x = 0; x < (nWidth >> 1); x++)
			{
				pYUV[0] = *(pY++);
				pYUV[1] = *(pUV++);
				pYUV[2] = *(pUV++);
				pYUV += 3;
			}
		}

		return true;
	}
	bool DownScaleImage(CMultipleChannelImage *pInImage, CMultipleChannelImage *pOutImage, bool bDitheringEnable = false, bool bDownSample = false)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (!pOutImage->Create(nWidth>>1, nHeight>>1, nDim, pInImage->m_nBit))return false;
		pOutImage->m_nMAXS = pInImage->m_nMAXS;
		pOutImage->m_nBLK = pInImage->m_nBLK;

		if (bDownSample)
		{
			return DownScaleShortImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, bDitheringEnable);
		}
		else
		{
			return DownScaleShortImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, bDitheringEnable);
		}
	}
	bool DownScaleImage(CBasicImageArray_WORD *pInImage, CBasicImageArray_WORD *pOutImage, bool bDitheringEnable = false, bool bDownSample = false)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (!pOutImage->SetImageSize(nWidth >> 1, nHeight >> 1, nDim))return false;

		if (bDownSample)
		{
			return DownScaleWordImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, bDitheringEnable);
		}
		else
		{
			return DownScaleWordImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, bDitheringEnable);
		}
	}

	bool UpScaleImage(CBasicImageArray_BYTE *pInImage, CBasicImageArray_BYTE *pOutImage, bool bDitheringEnable = false, bool bUpSample = false)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (!pOutImage->SetImageSize(nWidth * 2, nHeight * 2, nDim))return false;

		if (bUpSample)
		{
			return UpScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, bDitheringEnable);
		}
		else
		{
			return UpScaleByteImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, bDitheringEnable);
		}
	}
	bool UpScaleImage(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage, bool bDitheringEnable = false, bool bUpSample = false)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth * 2, nHeight * 2))return false;

		if (bUpSample)
		{
			return UpScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 3, bDitheringEnable);
		}
		else
		{
			return UpScaleByteImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 3, bDitheringEnable);
		}
	}
	bool UpScaleImage(CGrayImage *pInImage, CGrayImage *pOutImage, bool bDitheringEnable = false, bool bUpSample = false)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth * 2, nHeight * 2))return false;

		if (bUpSample)
		{
			return UpScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 1, bDitheringEnable);
		}
		else
		{
			return UpScaleByteImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 1, bDitheringEnable);
		}
	}
	bool UpScaleImage(CRGBYUVImage *pInImage, CYUV420Image *pOutImage, bool bDitheringEnable = false, bool bUpSample = false)
	{
		int x, y;
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		CGrayImage YImage;

		if (!YImage.Create(nWidth, nHeight))return false;
		if (!pOutImage->Create(nWidth * 2, nHeight * 2))return false;

		for (y = 0; y < nHeight; y++)
		{
			BYTE *pYUV = pInImage->GetImageLine(y);
			BYTE *pY = YImage.GetImageLine(y);
			BYTE *pUV = pOutImage->GetUVLine(y * 2);
			for (x = 0; x < nWidth; x++)
			{
				*(pY++) = pYUV[0];
				*(pUV++) = pYUV[1];
				*(pUV++) = pYUV[2];

				pYUV += 3;
			}
		}

		if (bUpSample)
		{
			return UpScaleByteImage(YImage.GetImageData(), pOutImage->GetYImage(), nWidth, nHeight, 1, bDitheringEnable);
		}
		else
		{
			return UpScaleByteImage2(YImage.GetImageData(), pOutImage->GetYImage(), nWidth, nHeight, 1, bDitheringEnable);
		}
	}
	bool UpScaleImage(CMultipleChannelImage *pInImage, CMultipleChannelImage *pOutImage, bool bDitheringEnable = false, bool bUpSample = false)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (!pOutImage->Create(nWidth << 1, nHeight << 1, nDim, pInImage->m_nBit))return false;
		pOutImage->m_nMAXS = pInImage->m_nMAXS;
		pOutImage->m_nBLK = pInImage->m_nBLK;

		if (bUpSample)
		{
			return UpScaleShortImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, bDitheringEnable);
		}
		else
		{
			return UpScaleShortImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, bDitheringEnable);
		}
	}
	bool UpScaleImage(CBasicImageArray_WORD *pInImage, CBasicImageArray_WORD *pOutImage, bool bDitheringEnable = false, bool bUpSample = false)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (!pOutImage->SetImageSize(nWidth << 1, nHeight << 1, nDim))return false;

		if (bUpSample)
		{
			return UpScaleWordImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, bDitheringEnable);
		}
		else
		{
			return UpScaleWordImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, bDitheringEnable);
		}
	}

	bool HDownScaleImage(CBasicImageArray_BYTE *pInImage, CBasicImageArray_BYTE *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();
		if (!pOutImage->SetImageSize(nWidth >> 1, nHeight, nDim))return false;

		HDownScaleByteImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim);

		return true;
	}
	bool HDownScaleImage(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth >> 1, nHeight))return false;

		HDownScaleByteImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 3);

		return true;
	}
	bool HDownScaleImage(CGrayImage *pInImage, CGrayImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth >> 1, nHeight))return false;

		HDownScaleByteImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 1);

		return true;
	}
	bool HDownScaleImage(CMultipleChannelImage *pInImage, CMultipleChannelImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();
		if (!pOutImage->Create(nWidth >> 1, nHeight, nDim, pInImage->m_nBit))return false;
		pOutImage->m_nMAXS = pInImage->m_nMAXS;
		pOutImage->m_nBLK = pInImage->m_nBLK;

		HDownScaleShortImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim);

		return true;
	}

	bool HUpScaleImage(CBasicImageArray_BYTE *pInImage, CBasicImageArray_BYTE *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();
		if (!pOutImage->SetImageSize(nWidth << 1, nHeight, nDim))return false;

		HUpScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim);

		return true;
	}
	bool HUpScaleImage(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth << 1, nHeight))return false;

		HUpScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 3);

		return true;
	}
	bool HUpScaleImage(CGrayImage *pInImage, CGrayImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth << 1, nHeight))return false;

		HUpScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 1);

		return true;
	}
	bool HUpScaleImage(CMultipleChannelImage *pInImage, CMultipleChannelImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();
		if (!pOutImage->Create(nWidth << 1, nHeight, nDim, pInImage->m_nBit))return false;
		pOutImage->m_nMAXS = pInImage->m_nMAXS;
		pOutImage->m_nBLK = pInImage->m_nBLK;

		HUpScaleShortImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim);

		return true;
	}

	bool VDownScaleImage(CBasicImageArray_BYTE *pInImage, CBasicImageArray_BYTE *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();
		if (!pOutImage->SetImageSize(nWidth, nHeight >> 1, nDim))return false;

		VDownScaleByteImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim);

		return true;
	}
	bool VDownScaleImage(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth, nHeight >> 1))return false;

		VDownScaleByteImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 3);

		return true;
	}
	bool VDownScaleImage(CGrayImage *pInImage, CGrayImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth, nHeight >> 1))return false;

		VDownScaleByteImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 1);

		return true;
	}
	bool VDownScaleImage(CMultipleChannelImage *pInImage, CMultipleChannelImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();
		if (!pOutImage->Create(nWidth, nHeight >> 1, nDim, pInImage->m_nBit))return false;
		pOutImage->m_nMAXS = pInImage->m_nMAXS;
		pOutImage->m_nBLK = pInImage->m_nBLK;

		VDownScaleShortImage2(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim);

		return true;
	}

	bool VUpScaleImage(CBasicImageArray_BYTE *pInImage, CBasicImageArray_BYTE *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();
		if (!pOutImage->SetImageSize(nWidth, nHeight << 1, nDim))return false;

		VUpScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim);

		return true;
	}
	bool VUpScaleImage(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth, nHeight << 1))return false;

		VUpScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 3);

		return true;
	}
	bool VUpScaleImage(CGrayImage *pInImage, CGrayImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth, nHeight << 1))return false;

		VUpScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 1);

		return true;
	}
	bool VUpScaleImage(CMultipleChannelImage *pInImage, CMultipleChannelImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();
		if (!pOutImage->Create(nWidth, nHeight << 1, nDim, pInImage->m_nBit))return false;
		pOutImage->m_nMAXS = pInImage->m_nMAXS;
		pOutImage->m_nBLK = pInImage->m_nBLK;

		VUpScaleShortImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim);

		return true;
	}

	bool ExtendImage(CBasicImageArray_BYTE *pInImage, CBasicImageArray_BYTE *pOutImage, int nS)
	{
		if (nS < 0)return false;

		int nMask = (1 << nS) - 1;
		int nInWidth = pInImage->GetWidth();
		int nInHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();
		int nOutWidth = nInWidth + (((1 << nS) - (nInWidth&nMask))&nMask);
		int nOutHeight = nInHeight + (((1 << nS) - (nInHeight&nMask))&nMask);

		if (pOutImage->GetWidth() != nOutWidth || pOutImage->GetHeight() != nOutHeight || pOutImage->GetDim() != nDim)
		{
			if (!pOutImage->SetImageSize(nOutWidth, nOutHeight, nDim))return false;
		}

		FillByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nInWidth, nInHeight, nOutWidth, nOutHeight, nDim);

		return true;
	}
	bool ExtendImage(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage, int nS)
	{
		if (nS < 0)return false;

		int nMask = (1 << nS) - 1;
		int nInWidth = pInImage->GetWidth();
		int nInHeight = pInImage->GetHeight();
		int nOutWidth = nInWidth + (((1 << nS) - (nInWidth&nMask))&nMask);
		int nOutHeight = nInHeight + (((1 << nS) - (nInHeight&nMask))&nMask);

		if (pOutImage->GetWidth() != nOutWidth || pOutImage->GetHeight() != nOutHeight)
		{
			if (!pOutImage->Create(nOutWidth, nOutHeight))return false;
		}

		FillByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nInWidth, nInHeight, nOutWidth, nOutHeight, 3);

		return true;
	}
	bool ExtendImage(CGrayImage *pInImage, CGrayImage *pOutImage, int nS)
	{
		if (nS < 0)return false;

		int nMask = (1 << nS) - 1;
		int nInWidth = pInImage->GetWidth();
		int nInHeight = pInImage->GetHeight();
		int nOutWidth = nInWidth + (((1 << nS) - (nInWidth&nMask))&nMask);
		int nOutHeight = nInHeight + (((1 << nS) - (nInHeight&nMask))&nMask);

		if (pOutImage->GetWidth() != nOutWidth || pOutImage->GetHeight() != nOutHeight)
		{
			if (!pOutImage->Create(nOutWidth, nOutHeight))return false;
		}

		FillByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nInWidth, nInHeight, nOutWidth, nOutHeight, 1);

		return true;
	}
	bool ExtendImage(CMultipleChannelImage *pInImage, CMultipleChannelImage *pOutImage, int nS)
	{
		if (nS < 0)return false;

		int nMask = (1 << nS) - 1;
		int nInWidth = pInImage->GetWidth();
		int nInHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();
		int nOutWidth = nInWidth + (((1 << nS) - (nInWidth&nMask))&nMask);
		int nOutHeight = nInHeight + (((1 << nS) - (nInHeight&nMask))&nMask);

		if (pOutImage->GetWidth() != nOutWidth || pOutImage->GetHeight() != nOutHeight || pOutImage->GetDim()!=nDim)
		{
			if (!pOutImage->Create(nOutWidth, nOutHeight, nDim, pInImage->m_nBit))return false;
		}
		pOutImage->m_nMAXS = pInImage->m_nMAXS;
		pOutImage->m_nBLK = pInImage->m_nBLK;

		FillShortImage(pInImage->GetImageData(), pOutImage->GetImageData(), nInWidth, nInHeight, nOutWidth, nOutHeight, nDim);

		return true;
	}
	bool ExtendImage(CBasicImageArray_WORD *pInImage, CBasicImageArray_WORD *pOutImage, int nS)
	{
		if (nS < 0)return false;

		int nMask = (1 << nS) - 1;
		int nInWidth = pInImage->GetWidth();
		int nInHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();
		int nOutWidth = nInWidth + (((1 << nS) - (nInWidth&nMask))&nMask);
		int nOutHeight = nInHeight + (((1 << nS) - (nInHeight&nMask))&nMask);

		if (pOutImage->GetWidth() != nOutWidth || pOutImage->GetHeight() != nOutHeight || pOutImage->GetDim() != nDim)
		{
			if (!pOutImage->SetImageSize(nOutWidth, nOutHeight, nDim))return false;
		}

		FillWordImage(pInImage->GetImageData(), pOutImage->GetImageData(), nInWidth, nInHeight, nOutWidth, nOutHeight, nDim);

		return true;
	}
	bool ExtendImage(CYUV420Image *pInImage, CYUV420Image *pOutImage, int nS)
	{
		if (nS < 1)return false;

		int nMask = (1 << nS) - 1;
		int nInWidth = pInImage->GetWidth();
		int nInHeight = pInImage->GetHeight();
		int nOutWidth = nInWidth + (((1 << nS) - (nInWidth&nMask))&nMask);
		int nOutHeight = nInHeight + (((1 << nS) - (nInHeight&nMask))&nMask);

		if (pOutImage->GetWidth() != nOutWidth || pOutImage->GetHeight() != nOutHeight)
		{
			if (!pOutImage->Create(nOutWidth, nOutHeight))return false;
		}

		FillByteImage(pInImage->GetYImage(), pOutImage->GetYImage(), nInWidth, nInHeight, nOutWidth, nOutHeight, 1);
		FillByteImage(pInImage->GetUVImage(), pOutImage->GetUVImage(), nInWidth >> 1, nInHeight >> 1, nOutWidth >> 1, nOutHeight >> 1, 2);

		return true;
	}

	bool SubtractEdge(CBasicImageArray_BYTE *pInImage0, CBasicImageArray_BYTE *pInImage1, CMultipleChannelImage *pOutImage)
	{
		int nWidth = pInImage0->GetWidth();
		int nHeight = pInImage0->GetHeight();
		int nDim = pInImage0->GetDim();

		if (pInImage1->GetWidth() != nWidth || pInImage1->GetHeight() != nHeight || pInImage1->GetDim() != nDim)return false;

		if (!pOutImage->Create(nWidth, nHeight, nDim, 10))return false;

		SubtractByteEdge(pInImage0->GetImageData(), pInImage1->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim);

		return true;
	}
	bool SubtractEdge(CRGBYUVImage *pInImage0, CRGBYUVImage *pInImage1, CMultipleChannelImage *pOutImage)
	{
		int nWidth = pInImage0->GetWidth();
		int nHeight = pInImage0->GetHeight();

		if (pInImage1->GetWidth() != nWidth || pInImage1->GetHeight() != nHeight)return false;

		if (!pOutImage->Create(nWidth, nHeight, 3, 10))return false;

		SubtractByteEdge(pInImage0->GetImageData(), pInImage1->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 3);

		return true;
	}
	bool SubtractEdge(CGrayImage *pInImage0, CGrayImage *pInImage1, CMultipleChannelImage *pOutImage)
	{
		int nWidth = pInImage0->GetWidth();
		int nHeight = pInImage0->GetHeight();

		if (pInImage1->GetWidth() != nWidth || pInImage1->GetHeight() != nHeight)return false;

		if (!pOutImage->Create(nWidth, nHeight, 1, 10))return false;

		SubtractByteEdge(pInImage0->GetImageData(), pInImage1->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 1);

		return true;
	}
	bool SubtractEdge(CYUV420Image *pInImage0, CYUV420Image *pInImage1, CMultipleChannelImage *pOutImage)
	{
		int nWidth = pInImage0->GetWidth();
		int nHeight = pInImage0->GetHeight();

		if (pInImage1->GetWidth() != nWidth || pInImage1->GetHeight() != nHeight)return false;

		if (!pOutImage->Create(nWidth, nHeight, 1, 10))return false;

		SubtractByteEdge(pInImage0->GetYImage(), pInImage1->GetYImage(), pOutImage->GetImageData(), nWidth, nHeight, 1);

		return true;
	}
	bool SubtractEdge(CMultipleChannelImage *pInImage0, CMultipleChannelImage *pInImage1, CMultipleChannelImage *pOutImage)
	{
		int nWidth = pInImage0->GetWidth();
		int nHeight = pInImage0->GetHeight();
		int nDim = pInImage0->GetDim();

		if (pInImage1->GetWidth() != nWidth || pInImage1->GetHeight() != nHeight || pInImage1->GetDim() != nDim)return false;

		if (pOutImage->GetWidth() != nWidth || pOutImage->GetHeight() != nHeight || pOutImage->GetDim()!=nDim)
		{
			if (!pOutImage->Create(nWidth, nHeight, nDim, pInImage0->m_nBit))return false;
		}

		SubtractShortEdge(pInImage0->GetImageData(), pInImage1->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim);

		return true;
	}
	bool SubtractEdge(CBasicImageArray_WORD *pInImage0, CBasicImageArray_WORD *pInImage1, CMultipleChannelImage *pOutImage)
	{
		int nWidth = pInImage0->GetWidth();
		int nHeight = pInImage0->GetHeight();
		int nDim = pInImage0->GetDim();

		if (pInImage1->GetWidth() != nWidth || pInImage1->GetHeight() != nHeight || pInImage1->GetDim() != nDim)return false;

		if (pOutImage->GetWidth() != nWidth || pOutImage->GetHeight() != nHeight || pOutImage->GetDim() != nDim)
		{
			if (!pOutImage->Create(nWidth, nHeight, nDim, 15))return false;
		}

		SubtractWordEdge(pInImage0->GetImageData(), pInImage1->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim);

		return true;
	}

	bool AddBackEdge(CBasicImageArray_BYTE *pInImage, CMultipleChannelImage *pEdgeImage, CBasicImageArray_BYTE *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nEdgeWidth = pEdgeImage->GetWidth();
		int nEdgeHeight = pEdgeImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (nEdgeWidth < nWidth || nEdgeHeight < nHeight || pEdgeImage->GetDim() != nDim)return false;

		if (pOutImage != pInImage)
		{
			if (!pOutImage->SetImageSize(nWidth, nHeight, nDim))return false;
		}

		AddBackByteEdge(pInImage->GetImageData(), pEdgeImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nEdgeWidth, nEdgeHeight, nDim);

		return true;
	}
	bool AddBackEdge(CRGBYUVImage *pInImage, CMultipleChannelImage *pEdgeImage, CRGBYUVImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nEdgeWidth = pEdgeImage->GetWidth();
		int nEdgeHeight = pEdgeImage->GetHeight();

		if (nEdgeWidth < nWidth || nEdgeHeight < nHeight || pEdgeImage->GetDim() != 3)return false;

		if (pOutImage != pInImage)
		{
			if (!pOutImage->Create(nWidth, nHeight))return false;
		}

		AddBackByteEdge(pInImage->GetImageData(), pEdgeImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nEdgeWidth, nEdgeHeight, 3);

		return true;
	}
	bool AddBackEdge(CGrayImage *pInImage, CMultipleChannelImage *pEdgeImage, CGrayImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nEdgeWidth = pEdgeImage->GetWidth();
		int nEdgeHeight = pEdgeImage->GetHeight();

		if (nEdgeWidth < nWidth || nEdgeHeight < nHeight || pEdgeImage->GetDim() != 1)return false;

		if (pOutImage != pInImage)
		{
			if (!pOutImage->Create(nWidth, nHeight))return false;
		}

		AddBackByteEdge(pInImage->GetImageData(), pEdgeImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nEdgeWidth, nEdgeHeight, 1);

		return true;
	}
	bool AddBackEdge(CYUV420Image *pInImage, CMultipleChannelImage *pEdgeImage, CYUV420Image *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nEdgeWidth = pEdgeImage->GetWidth();
		int nEdgeHeight = pEdgeImage->GetHeight();

		if (nEdgeWidth < nWidth || nEdgeHeight < nHeight || pEdgeImage->GetDim() != 1)return false;

		if (pOutImage != pInImage)
		{
			if (!pOutImage->Create(nWidth, nHeight))return false;

			memcpy(pOutImage->GetUVImage(), pInImage->GetUVImage(), (nWidth >> 1)*(nHeight >> 1) * 2);
		}

		AddBackByteEdge(pInImage->GetYImage(), pEdgeImage->GetImageData(), pOutImage->GetYImage(), nWidth, nHeight, nEdgeWidth, nEdgeHeight, 1);

		return true;
	}
	bool AddBackEdge(CMultipleChannelImage *pInImage, CMultipleChannelImage *pEdgeImage, CMultipleChannelImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nEdgeWidth = pEdgeImage->GetWidth();
		int nEdgeHeight = pEdgeImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (nEdgeWidth < nWidth || nEdgeHeight < nHeight || pEdgeImage->GetDim() != nDim)return false;

		if (pOutImage != pInImage)
		{
			if (!pOutImage->Create(nWidth, nHeight, nDim, pInImage->m_nBit))return false;
		}

		AddBackShortEdge(pInImage->GetImageData(), pEdgeImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nEdgeWidth, nEdgeHeight, nDim);

		return true;
	}
	bool AddBackEdge(CBasicImageArray_WORD *pInImage, CMultipleChannelImage *pEdgeImage, CBasicImageArray_WORD *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nEdgeWidth = pEdgeImage->GetWidth();
		int nEdgeHeight = pEdgeImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (nEdgeWidth < nWidth || nEdgeHeight < nHeight || pEdgeImage->GetDim() != nDim)return false;

		if (pOutImage != pInImage)
		{
			if (!pOutImage->SetImageSize(nWidth, nHeight, nDim))return false;
		}

		AddBackWordEdge(pInImage->GetImageData(), pEdgeImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nEdgeWidth, nEdgeHeight, nDim);

		return true;
	}

	bool SimpleHDownScaleImage(CBasicImageArray_BYTE *pInImage, CBasicImageArray_BYTE *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (!pOutImage->SetImageSize(nWidth >> nS, nHeight, nDim))return false;

		SimpleHDownScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, nS);

		return true;
	}
	bool SimpleHUpScaleImage(CBasicImageArray_BYTE *pInImage, CBasicImageArray_BYTE *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (!pOutImage->SetImageSize(nWidth << nS, nHeight, nDim))return false;

		SimpleHUpScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, nS);

		return true;
	}
	bool SimpleHDownScaleImage(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth >> nS, nHeight))return false;

		SimpleHDownScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 3, nS);

		return true;
	}
	bool SimpleHUpScaleImage(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth << nS, nHeight))return false;

		SimpleHUpScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 3, nS);

		return true;
	}
	bool SimpleHDownScaleImage(CGrayImage *pInImage, CGrayImage *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth >> nS, nHeight))return false;

		SimpleHDownScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 1, nS);

		return true;
	}
	bool SimpleHUpScaleImage(CGrayImage *pInImage, CGrayImage *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth << nS, nHeight))return false;

		SimpleHUpScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 1, nS);

		return true;
	}
	bool SimpleHDownScaleImage(CMultipleChannelImage *pInImage, CMultipleChannelImage *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (!pOutImage->Create(nWidth >> nS, nHeight, nDim, pInImage->m_nBit))return false;
		pOutImage->m_nBLK = pInImage->m_nBLK;
		pOutImage->m_nMAXS = pInImage->m_nMAXS;

		SimpleHDownScaleShortImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, nS);

		return true;
	}
	bool SimpleHUpScaleImage(CMultipleChannelImage *pInImage, CMultipleChannelImage *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (!pOutImage->Create(nWidth << nS, nHeight, nDim, pInImage->m_nBit))return false;
		pOutImage->m_nBLK = pInImage->m_nBLK;
		pOutImage->m_nMAXS = pInImage->m_nMAXS;

		SimpleHUpScaleShortImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, nS);

		return true;
	}

	bool SimpleVDownScaleImage(CBasicImageArray_BYTE *pInImage, CBasicImageArray_BYTE *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (!pOutImage->SetImageSize(nWidth, nHeight >> nS, nDim))return false;

		SimpleVDownScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, nS);

		return true;
	}
	bool SimpleVUpScaleImage(CBasicImageArray_BYTE *pInImage, CBasicImageArray_BYTE *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (!pOutImage->SetImageSize(nWidth, nHeight << nS, nDim))return false;

		SimpleVUpScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, nS);

		return true;
	}
	bool SimpleVDownScaleImage(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth, nHeight >> nS))return false;

		SimpleVDownScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 3, nS);

		return true;
	}
	bool SimpleVUpScaleImage(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth, nHeight << nS))return false;

		SimpleVUpScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 3, nS);

		return true;
	}
	bool SimpleVDownScaleImage(CGrayImage *pInImage, CGrayImage *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth, nHeight >> nS))return false;

		SimpleVDownScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 1, nS);

		return true;
	}
	bool SimpleVUpScaleImage(CGrayImage *pInImage, CGrayImage *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth, nHeight << nS))return false;

		SimpleVUpScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 1, nS);

		return true;
	}
	bool SimpleVDownScaleImage(CMultipleChannelImage *pInImage, CMultipleChannelImage *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (!pOutImage->Create(nWidth, nHeight >> nS, nDim, pInImage->m_nBit))return false;
		pOutImage->m_nBLK = pInImage->m_nBLK;
		pOutImage->m_nMAXS = pInImage->m_nMAXS;

		SimpleVDownScaleShortImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, nS);

		return true;
	}
	bool SimpleVUpScaleImage(CMultipleChannelImage *pInImage, CMultipleChannelImage *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (!pOutImage->Create(nWidth, nHeight << nS, nDim, pInImage->m_nBit))return false;
		pOutImage->m_nBLK = pInImage->m_nBLK;
		pOutImage->m_nMAXS = pInImage->m_nMAXS;

		SimpleVUpScaleShortImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, nS);

		return true;
	}

	bool SimpleHVDownScaleImage(CBasicImageArray_BYTE *pInImage, CBasicImageArray_BYTE *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (!pOutImage->SetImageSize(nWidth >> nS, nHeight >> nS, nDim))return false;

		SimpleHVDownScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, nS);

		return true;
	}
	bool SimpleHVUpScaleImage(CBasicImageArray_BYTE *pInImage, CBasicImageArray_BYTE *pOutImage, int nS = 1)
	{
		CBasicImageArray_BYTE TempImage;

		if (!SimpleHUpScaleImage(pInImage, &TempImage, nS))return false;
		if (!SimpleVUpScaleImage(&TempImage, pOutImage, nS))return false;

		return true;
	}
	bool SimpleHVDownScaleImage(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth >> nS, nHeight >> nS))return false;

		SimpleHVDownScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 3, nS);

		return true;
	}
	bool SimpleHVUpScaleImage(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage, int nS = 1)
	{
		CRGBYUVImage TempImage;

		if (!SimpleHUpScaleImage(pInImage, &TempImage, nS))return false;
		if (!SimpleVUpScaleImage(&TempImage, pOutImage, nS))return false;

		return true;
	}
	bool SimpleHVDownScaleImage(CGrayImage *pInImage, CGrayImage *pOutImage, int nS=1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth >> nS, nHeight >> nS))return false;

		SimpleHVDownScaleByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 1, nS);

		return true;
	}
	bool SimpleHVUpScaleImage(CGrayImage *pInImage, CGrayImage *pOutImage, int nS = 1)
	{
		CGrayImage TempImage;

		if (!SimpleHUpScaleImage(pInImage, &TempImage, nS))return false;
		if (!SimpleVUpScaleImage(&TempImage, pOutImage, nS))return false;

		return true;
	}
	bool SimpleHVDownScaleImage(CMultipleChannelImage *pInImage, CMultipleChannelImage *pOutImage, int nS = 1)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();

		if (!pOutImage->Create(nWidth >> nS, nHeight >> nS, nDim, pInImage->m_nBit))return false;

		SimpleHVDownScaleShortImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, nS);

		return true;
	}
	bool SimpleHVUpScaleImage(CMultipleChannelImage *pInImage, CMultipleChannelImage *pOutImage, int nS = 1)
	{
		CMultipleChannelImage TempImage;

		if (!SimpleHUpScaleImage(pInImage, &TempImage, nS))return false;
		if (!SimpleVUpScaleImage(&TempImage, pOutImage, nS))return false;

		return true;
	}
	bool SimpleHVDownScaleImage(CYUV420Image *pInImage, CRGBYUVImage *pOutImage);
	bool SimpleHVUpScaleImage(CRGBYUVImage *pInImage, CYUV420Image *pOutImage);

	bool BicubicUpScale2Image(CGrayImage *pInImage, CGrayImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth * 2, nHeight * 2))return false;

		return BicubicUpScale2ByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 1);
	}
	bool BicubicUpScale2Image(CRGBYUVImage *pInImage, CRGBYUVImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!pOutImage->Create(nWidth * 2, nHeight * 2))return false;

		return BicubicUpScale2ByteImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, 3);
	}
	bool BicubicUpScale2Image(CRGBYUVImage *pInImage, CYUV420Image *pOutImage)
	{
		int x, y;
		CGrayImage YImage;
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();

		if (!YImage.Create(nWidth, nHeight))return false;
		if (!pOutImage->Create(nWidth * 2, nHeight * 2))return false;

		for (y = 0; y < nHeight; y++)
		{
			BYTE *pYUV = pInImage->GetImageLine(y);
			BYTE *pY = YImage.GetImageLine(y);
			BYTE *pUV = pOutImage->GetUVLine(y * 2);
			for (x = 0; x < nWidth; x++)
			{
				*(pY++) = pYUV[0];
				*(pUV++) = pYUV[1];
				*(pUV++) = pYUV[2];
				pYUV += 3;
			}
		}

		return BicubicUpScale2ByteImage(YImage.GetImageData(), pOutImage->GetYImage(), nWidth, nHeight, 1);
	}
	bool BicubicUpScale2Image(CMultipleChannelImage *pInImage, CMultipleChannelImage *pOutImage)
	{
		int nWidth = pInImage->GetWidth();
		int nHeight = pInImage->GetHeight();
		int nDim = pInImage->GetDim();
		int nBLK = pInImage->m_nBLK;
		int nMAXS = pInImage->m_nMAXS;

		if (!pOutImage->Create(nWidth * 2, nHeight * 2, nDim, pInImage->m_nBit))return false;
		pOutImage->m_nBLK = nBLK;
		pOutImage->m_nMAXS = nMAXS;

		return BicubicUpScale2ShortImage(pInImage->GetImageData(), pOutImage->GetImageData(), nWidth, nHeight, nDim, nBLK, nMAXS);
	}
};

#endif