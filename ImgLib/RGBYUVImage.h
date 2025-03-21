#ifndef __RGBYUV_IMAGE_H_
#define __RGBYUV_IMAGE_H_

#include "BasicImageArray.h"

class CRGBAImage : public CBasicImageArray_BYTE
{
public:
	bool Create(int nWidth, int nHeight)
	{
		return SetImageSize(nWidth, nHeight, 4);
	}
};

class CRGBYUVImage : public CBasicImageArray_BYTE
{
public:
	bool Create(int nWidth, int nHeight)
	{
		return SetImageSize(nWidth, nHeight, 3);
	}
	bool Copy(CRGBYUVImage *pImage)
	{
		if (!SetImageSize(pImage->GetWidth(), pImage->GetHeight(), 3))return false;
		memcpy(GetImageData(), pImage->GetImageData(), m_nWidth * m_nHeight * 3);
		return true;
	}
	bool CopyRect(CRGBYUVImage *pImage, int nLeft, int nTop, int nRight, int nBottom)
	{
		int i, x, y, tx;
		int nWidth = pImage->GetWidth();
		
		if (!SetImageSize(nRight - nLeft, nBottom - nTop, 3))return false;

		for (y = nTop; y < nBottom; y++)
		{
			BYTE *pIn = pImage->GetImageLine(y);
			BYTE *pOut = GetImageLine(y - nTop);
			for (x = nLeft; x < nRight; x++)
			{
				if (x < 0)
					tx = 0;
				else if (x >= nWidth)
					tx = nWidth - 1;
				else
					tx = x;

				for (i = 0; i < 3; i++)
				{
					*(pOut++) = pIn[tx * 3 + i];
				}
			}
		}

		return true;
	}

	void RGB2YCbCr(bool bDithering=false);
	void YCbCr2RGB(bool bDithering=false);
	bool LoadFromBMPFile(char *pFileName);
	bool SaveToBMPFile(char *pFileName);

	bool LoadYUV444File(char *pFileName, int nWidth, int nHeight);
	bool SaveYUV444File(char *pFileName);

	bool GetHistogram(int pHistB[], int pHistG[], int pHistR[]);
	bool GetHistogram(int nChannel, int pHist[]);
};

class CYUV422Image : public CBasicImageArray_BYTE
{
public:
	bool Create(int nWidth, int nHeight)
	{
		nWidth = (nWidth >> 1) << 1;
		return SetImageSize(nWidth, nHeight, 2);
	}

	bool YUV444ToYUV422(CRGBYUVImage *pYUV444Image);
	bool YUV422ToYUV444(CRGBYUVImage *pYUV444Image);

	/*
		nYUYVFormat = 0, YUYV
		nYUYVFormat = 1, YVYU
		nYUYVFormat = 2, UYVY
		nYUYVFormat = 3, VYUY
	*/
	bool SaveToYUV422File(char *pFileName, int nYUYVFormat=0);
	bool LoadFromYUV422File(char *pFileName, int nWidth, int nHeight, int nYUYVFormat=0);
};

class CFloatImage : public CBasicImageArray_FLOAT
{
public:
	bool Create(int nWidth, int nHeight)
	{
		return SetImageSize(nWidth, nHeight, 1);
	}

	bool Create(int nWidth, int nHeight, int ch)
	{
		return SetImageSize(nWidth, nHeight, ch);
	}

	bool Copy(CFloatImage *pImage)
	{
		if (!SetImageSize(pImage->GetWidth(), pImage->GetHeight(), 1))return false;
		memcpy(m_pData, pImage->GetImageData(), m_nWidth*m_nHeight * sizeof(float));
		return true;
	}

	void SaveTxtFile(char *filename)
	{
		FILE *fp;
		fopen_s(&fp, filename, "wt");

		if (fp == NULL)
		{
			printf("Error in saving file %s\n", filename);
			return;
		}

		int y, x;
		for (y = 0; y < m_nHeight; y++)
		{
			float *pLine = GetImageLine(y);

			for (x = 0; x < m_nWidth; x++)
			{
				fprintf_s(fp, "%f\t", pLine[x]);
			}
			fprintf_s(fp, "\n");
		}
		fclose(fp);
	}

	void SaveToBMPData(CRGBYUVImage *pImage, float norm = -1)
	{
		int x, y;
		if (norm <= 0)
		{
			for (y = 0; y < m_nHeight; y++)
			{
				float *pLine = GetImageLine(y);
				for (x = 0; x < m_nWidth; x++)
				{
					if (pLine[x] > norm)norm = pLine[x];
				}
			}
		}

		pImage->Create(m_nWidth, m_nHeight);
		for (y = 0; y < m_nHeight; y++)
		{
			float *pLine = GetImageLine(y);
			BYTE *pOutLine = pImage->GetImageLine(y);
			for (x = 0; x < m_nWidth; x++)
			{
				if (pLine[x] > norm)
				{
					pOutLine[3 * x] = 255;
					pOutLine[3 * x + 1] = 255;
					pOutLine[3 * x + 2] = 255;
				}
				else if (pLine[x] < 0)
				{
					pOutLine[3 * x] = 0;
					pOutLine[3 * x + 1] = 0;
					pOutLine[3 * x + 2] = 0;
				}
				else
				{
					int data = (int)(0.5 + pLine[x] / norm*255.0f);
					if (data > 255)data = 255;
					if (data < 0)data = 0;
					pOutLine[3 * x] = data;
					pOutLine[3 * x + 1] = data;
					pOutLine[3 * x + 2] = data;
				}
			}
		}

	}
};

class CYUV420Image
{
protected:
	BYTE *m_pData;
	BYTE *m_pYPlane;
	BYTE *m_pUVPlane;
	int m_nWidth;
	int m_nHeight;

	void HIntUVLine(BYTE *pInLine, WORD *pOutLine, int nWidth);
public:
	CYUV420Image()
	{
		m_pData = m_pYPlane = m_pUVPlane = NULL;
		m_nWidth = m_nHeight = 0;
	}
	~CYUV420Image()
	{
		if (m_pData != NULL)delete[] m_pData;
	}

	bool Copy(CYUV420Image *pImage)
	{
		if (!Create(pImage->GetWidth(), pImage->GetHeight()))return false;

		memcpy(m_pYPlane, pImage->GetYImage(), m_nWidth*m_nHeight);
		memcpy(m_pUVPlane, pImage->GetUVImage(), (m_nWidth / 2)*(m_nHeight / 2) * 2);

		return true;
	}
	bool CopyRect(CYUV420Image *pImage, int nLeft, int nTop, int nRight, int nBottom)
	{
		int x, tx, y;
		int nWidth = pImage->GetWidth();

		nLeft = (nLeft >> 1) << 1;
		nTop = (nTop >> 1) << 1;
		nRight = ((nRight >> 1) + (nRight & 1)) << 1;
		nBottom = ((nBottom >> 1) + (nBottom & 1)) << 1;
		if (!Create(nRight - nLeft, nBottom - nTop))return false;

		for (y = nTop; y < nBottom; y++)
		{
			BYTE *pInY = pImage->GetYLine(y);
			BYTE *pOutY = GetYLine(y - nTop);
			for (x = nLeft; x < nRight; x++)
			{
				if (x < 0)
					tx = 0;
				else if (x >= nWidth)
					tx = nWidth - 1;
				else
					tx = x;

				*(pOutY++) = pInY[tx];
			}
		}

		for (y = nTop; y < nBottom; y += 2)
		{
			BYTE *pInUV = pImage->GetUVLine(y);
			BYTE *pOutUV = GetUVLine(y - nTop);
			for (x = nLeft; x < nRight; x += 2)
			{
				if (x < 0)
					tx = 0;
				else if (x >= nWidth)
					tx = nWidth - 2;
				else
					tx = x;

				*(pOutUV++) = pInUV[tx];
				*(pOutUV++) = pInUV[tx + 1];
			}
		}

		return true;
	}
	bool ReplaceRect(CYUV420Image *pImage, int &nLeft, int &nTop, int &nRight, int &nBottom)
	{
		int y;

		nLeft = (nLeft >> 1) << 1;
		nTop = (nTop >> 1) << 1;
		nRight = ((nRight >> 1) + (nRight & 1)) << 1;
		nBottom = ((nBottom >> 1) + (nBottom & 1)) << 1;

		if (nLeft < 0 || nRight < 0 || nTop < 0 || nBottom < 0)return false;
		if (nLeft >= m_nWidth || nRight > m_nWidth || nTop >= m_nHeight || nBottom >= m_nHeight)return false;

		for (y = nTop; y < nBottom; y++)
		{
			BYTE *pInY = pImage->GetYLine(y - nTop);
			BYTE *pOutY = GetYLine(y) + nLeft;
			memcpy(pOutY, pInY, nRight - nLeft);
		}
		for (y = nTop; y < nBottom; y += 2)
		{
			BYTE *pInUV = pImage->GetUVLine(y - nTop);
			BYTE *pOutUV = GetUVLine(y) + nLeft;
			memcpy(pOutUV, pInUV, nRight - nLeft);
		}

		return true;
	}

	bool Create(int nWidth, int nHeight)
	{
		if (m_pData != NULL)delete[] m_pData;
		m_pData = m_pYPlane = m_pUVPlane = NULL;
		m_nWidth = m_nHeight = 0;

		nWidth = (nWidth >> 1) << 1;
		nHeight = (nHeight >> 1) << 1;
		m_pData = new BYTE[nWidth*nHeight + (nWidth / 2)*(nHeight / 2) * 2];
		if (m_pData == NULL)return false;

		m_pYPlane = m_pData;
		m_pUVPlane = m_pData + nWidth*nHeight;
		m_nWidth = nWidth;
		m_nHeight = nHeight;
		return true;
	}

	__inline int GetWidth() { return m_nWidth; }
	__inline int GetHeight() { return m_nHeight; }
	__inline BYTE *GetYImage() { return m_pYPlane; }
	__inline BYTE *GetUVImage() { return m_pUVPlane; }

	__inline BYTE *GetYLine(int nY)
	{
		if (nY < 0)nY = 0;	if (nY >= m_nHeight)nY = m_nHeight - 1;
		return m_pYPlane + nY*m_nWidth;
	}
	__inline BYTE *GetUVLine(int nY)
	{
		if (nY < 0)nY = 0;	if (nY >= m_nHeight)nY = m_nHeight - 1;
		return m_pUVPlane + (nY >> 1)*m_nWidth;
	}

	bool Crop(int nLeft_Margin, int nTop_Margin, int nRight_Margin, int nBottom_Margin)
	{
		if (m_pData == NULL)return false;

		if (nLeft_Margin < 0)nLeft_Margin = 0;		if (nLeft_Margin >= m_nWidth)nLeft_Margin = m_nWidth - 1;
		if (nRight_Margin < 0)nRight_Margin = 0;		if (nRight_Margin >= m_nWidth)nRight_Margin = m_nWidth - 1;
		if (nTop_Margin < 0)nTop_Margin = 0;			if (nTop_Margin >= m_nHeight)nTop_Margin = m_nHeight - 1;
		if (nBottom_Margin < 0)nBottom_Margin = 0;	if (nBottom_Margin >= m_nHeight)nBottom_Margin = m_nHeight - 1;

		int x, y;
		int nLeft = (nLeft_Margin >> 1) << 1;
		int nTop = (nTop_Margin >> 1) << 1;
		int nW = m_nWidth - nLeft_Margin - nRight_Margin;
		int nH = m_nHeight - nTop_Margin - nBottom_Margin;

		nW = (nW >> 1) << 1;
		nH = (nH >> 1) << 1;
		if ((nW < 2) || (nH < 2))return false;

		if (nW == m_nWidth&&nH == m_nHeight)return true;

		BYTE *pOut = m_pYPlane;
		for (y = 0; y < nH; y++)
		{
			BYTE *pIn = GetYLine(y + nTop) + nLeft;
			for (x = 0; x < nW; x++)
			{
				*(pOut++) = *(pIn++);
			}
		}
		pOut = m_pYPlane + nW*nH;
		for (y = 0; y < nH; y += 2)
		{
			BYTE *pIn = GetUVLine(y + nTop) + nLeft;
			for (x = 0; x < nW; x += 2)
			{
				*(pOut++) = *(pIn++);
				*(pOut++) = *(pIn++);
			}
		}
		m_pUVPlane = m_pYPlane + nW*nH;
		m_nWidth = nW;
		m_nHeight = nH;

		return true;
	}

	bool YUV444ToYUV420(CRGBYUVImage *pYUV444Image);
	bool YUV420ToYUV444(CRGBYUVImage *pYUV444Image, bool bSimpleUV = false);

	bool LoadYUV420File(char *pFileName, int nWidth, int nHeight, int bUVOrder = 0, int bInterleaveUV = 1);
	bool SaveYUV420File(char *pFileName, int bUVOrder = 0, int bInterleaveUV = 1);
};


#endif
