#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "../ImgLib/Filter.h"
#include "SmoothFilter.h"
#include "GaussianPyramid2.h"

class imageLighten : public CFilter
{
public:
	imageLighten(void);

	~imageLighten();

	bool RunBeautify(CYUV420Image* pMainYUV, char* fileName);

	void FindSkinMask(CRGBYUVImage* YCbCr, CGrayImage* SkinMask);

	void SkinLineMappingList();

	bool CurveMappingList();

	void HighPassFilter(CRGBYUVImage* pIn, CGrayImage* SkinMask);

	void AdjustSaturationAndLighten(CRGBYUVImage* pIn, CGrayImage* pSkinMask);

	void Lighten(CRGBYUVImage* pIn);

	void LocalStatisticsFilter(CRGBYUVImage* pIn, CGrayImage* pSkinMask);

	void AddNoiseBack(CRGBYUVImage* pIn, CRGBYUVImage* pFiltered);

	void AddHighPassBackAndBlend(CYUV420Image* pMainYUV, CYUV420Image* pMainYUV2, CYUV420Image* pSmoothYUV, CGrayImage* pMask);

	void Blend(CRGBYUVImage* pIn, CRGBYUVImage* pOri, CGrayImage* pSkinMask);

	void ImageSharpen(CRGBYUVImage* pIn, int nSigma_0, int nSigma_1);

	void AdjustHueAndSat(CRGBYUVImage* pOriYUV, CRGBYUVImage* pProcessedYUV, CGrayImage* pMask);

	inline int Clip(int value)
	{
		value = value > 255 ? 255 : value;
		value = value < 0 ? 0 : value;
		
		return value;
	}

public:
	CRGBYUVImage pDownScaleYUV;
	CYUV420Image pUpScaleYUV;
	CRGBYUVImage pBGR;
	CGrayImage pSkinMask;

	BYTE m_nLookUpTable[256];
	int m_nLineMapListY[256];
	int m_nLineMapListCb[256];
	int m_nLineMapListCr[256];
	int m_nAddNoisePercent[129];
public:
	// parameters get from init parameter file.
	int m_nSaveAndPrintDebugInfo;

	// parameters for skin detection.
	int m_nMinY;
	int m_nMinCb;
	int m_nMinCr;

	int m_nMaxY;
	int m_nMaxCb;
	int m_nMaxCr;

	int m_nSkinTransitionWidth;

	int m_nPoint_0;
	int m_nPoint_1;
	int m_nPoint_2;
	int m_nPoint_3;
	int m_nPoint_4;
	int m_nPoint_5;
	int m_nPoint_6;
	int m_nPoint_7;


	int m_nDelta_0;
	int m_nDelta_1;
	int m_nDelta_2;
	int m_nDelta_3;
	int m_nDelta_4;
	int m_nDelta_5;
	int m_nDelta_6;
	int m_nDelta_7;

	int m_bUseGammaCurve;
	int m_nGamma;
	int m_nPositiveDiff;
	int m_nNegativeDiff;
	int m_nLocalStatisticsRadius;
	int m_nFilterSigma;
	int m_nMaskRadius;
	int m_bAddNoiseBackDownScale;
	int m_nAddNoisePercent_0;

	int m_bSharpenSkin;
	int m_bSharpenInDownScale;
	int m_nDownScaleSigma_0;
	int m_nDownScaleSigma_1;

	int m_bSharpenInFullSize;
	int m_nFullSizeGaussSigma_0;
	int m_nFullSizeGaussSigma_1;

	int m_nMaskValue_0;
	int m_nMaskValue_1;
	int m_nMaskValue_2;

	int m_nNoisePercent_0;
	int m_nNoisePercent_1;
	int m_nNoisePercent_2;

	int m_bKeepSaturantion;
	int m_nAdjustSaturation;
	int m_nAdjustHue;

protected:

	virtual bool InitParamList()
	{		
		m_ParamList.Add("nSaveAndPrintDebugInfo", &m_nSaveAndPrintDebugInfo, 0, 1);
		m_nSaveAndPrintDebugInfo = 0;
		
		m_ParamList.Add("nMinY", &m_nMinY, 0, 255);
		m_nMinY = 80;

		m_ParamList.Add("nMinCb", &m_nMinCb, 0, 255);
		m_nMinCb = 85;

		m_ParamList.Add("nMinCr", &m_nMinCr, 0, 255);
		m_nMinCr = 135;

		m_ParamList.Add("nMaxY", &m_nMaxY, 0, 255);
		m_nMaxY = 220;

		m_ParamList.Add("nMaxCb", &m_nMaxCb, 0, 255);
		m_nMaxCb = 135;

		m_ParamList.Add("nMaxCr", &m_nMaxCr, 0, 255);
		m_nMaxCr = 95;

		m_ParamList.Add("nSkinTransitionWidth", &m_nSkinTransitionWidth, 0, 128);
		m_nSkinTransitionWidth = 5;
		
		m_ParamList.Add("nPoint_0", &m_nPoint_0, 0, 255);
		m_nPoint_0 = 0;

		m_ParamList.Add("nPoint_1", &m_nPoint_1, 0, 255);
		m_nPoint_1 = 40;

		m_ParamList.Add("nPoint_2", &m_nPoint_2, 0, 255);
		m_nPoint_2 = 80;

		m_ParamList.Add("nPoint_3", &m_nPoint_3, 0, 255);
		m_nPoint_3 = 120;

		m_ParamList.Add("nPoint_4", &m_nPoint_4, 0, 255);
		m_nPoint_4 = 160;

		m_ParamList.Add("nPoint_5", &m_nPoint_5, 0, 255);
		m_nPoint_5 = 200;

		m_ParamList.Add("nPoint_6", &m_nPoint_6, 0, 255);
		m_nPoint_6 = 240;

		m_ParamList.Add("nPoint_7", &m_nPoint_7, 0, 255);
		m_nPoint_7 = 255;
		
		m_ParamList.Add("nDelta_0", &m_nDelta_0, -255, 255);
		m_nDelta_0 = 6;
		
		m_ParamList.Add("nDelta_1", &m_nDelta_1, -255, 255);
		m_nDelta_1 = 8;

		m_ParamList.Add("nDelta_2", &m_nDelta_2, -255, 255);
		m_nDelta_2 = 10;

		m_ParamList.Add("nDelta_3", &m_nDelta_3, -255, 255);
		m_nDelta_3 = 12;

		m_ParamList.Add("nDelta_4", &m_nDelta_4, -255, 255);
		m_nDelta_4 = 10;

		m_ParamList.Add("nDelta_5", &m_nDelta_5, -255, 255);
		m_nDelta_5 = 8;

		m_ParamList.Add("nDelta_6", &m_nDelta_6, -255, 255);
		m_nDelta_6 = 6;	

		m_ParamList.Add("nDelta_7", &m_nDelta_7,-255, 255);
		m_nDelta_7 = 0;


		m_ParamList.Add("bUseGammaCurve", &m_bUseGammaCurve, 0, 1);
		m_bUseGammaCurve = 1;

		m_ParamList.Add("nGamma", &m_nGamma, -100, 100);
		m_nGamma = 0;

		m_ParamList.Add("nLocalStatisticsRadius", &m_nLocalStatisticsRadius, 0, 256);
		m_nLocalStatisticsRadius = 2;

		m_ParamList.Add("nFilterSigma", &m_nFilterSigma, 0, 65535);
		m_nFilterSigma = 0;

		m_ParamList.Add("nMaskRadius", &m_nMaskRadius, 0, 256);
		m_nMaskRadius = 2;

		m_ParamList.Add("bAddNoiseBackDownScale", &m_bAddNoiseBackDownScale, 0, 1);
		m_bAddNoiseBackDownScale = 1;
		
		m_ParamList.Add("nAddNoisePercent_0", &m_nAddNoisePercent_0, 0, 1000);
		m_nAddNoisePercent_0 = 50;
		
		m_ParamList.Add("bSharpenInDownScale", &m_bSharpenInDownScale, 0, 1);
		m_bSharpenInDownScale = 0;

		m_ParamList.Add("nDownScaleSigma_0", &m_nDownScaleSigma_0, -1, 65535);
		m_nDownScaleSigma_0 = 0;

		m_ParamList.Add("nDownScaleSigma_1", &m_nDownScaleSigma_1, -1, 65535);
		m_nDownScaleSigma_1 = 0;

		m_ParamList.Add("nPositiveDiff", &m_nPositiveDiff, 0, 1024);
		m_nPositiveDiff = 50;

		m_ParamList.Add("nNegativeDiff", &m_nNegativeDiff, 0, 1024);
		m_nNegativeDiff = 50;

		m_ParamList.Add("bSharpenSkin", &m_bSharpenSkin, -1, 65535);
		m_bSharpenSkin = 0;

		m_ParamList.Add("bSharpenInFullSize", &m_bSharpenInFullSize, 0, 1);
		m_bSharpenInFullSize = 0;
		
		m_ParamList.Add("nFullSizeGaussSigma_0", &m_nFullSizeGaussSigma_0, -1, 65535);
		m_nFullSizeGaussSigma_0 = 1;
		
		m_ParamList.Add("nFullSizeGaussSigma_1", &m_nFullSizeGaussSigma_1, -1, 65535);
		m_nFullSizeGaussSigma_1 = 1;

		m_ParamList.Add("nMaskValue_0", &m_nMaskValue_0, 0, 128);
		m_nMaskValue_0 = 43;

		m_ParamList.Add("nMaskValue_1", &m_nMaskValue_1, 0, 128);
		m_nMaskValue_1 = 85;

		m_ParamList.Add("nMaskValue_2", &m_nMaskValue_2, 0, 128);
		m_nMaskValue_2 = 128;
			
		m_ParamList.Add("nNoisePercent_0", &m_nNoisePercent_0, 0, 128);
		m_nNoisePercent_0 = 128;

		m_ParamList.Add("nNoisePercent_1", &m_nNoisePercent_1, 0, 128);
		m_nNoisePercent_1 = 64;

		m_ParamList.Add("nNoisePercent_2", &m_nNoisePercent_2, 0, 128);
		m_nNoisePercent_2 = 0;

		m_ParamList.Add("bKeepSaturantion", &m_bKeepSaturantion, 0, 1);
		m_bKeepSaturantion = 0;

		m_ParamList.Add("nAdjustSaturation", &m_nAdjustSaturation, -128, 128);
		m_nAdjustSaturation = 128;

		m_ParamList.Add("nAdjustHue", &m_nAdjustHue, -180, 180);
		m_nAdjustHue = 0;

		return true;
	}
};

