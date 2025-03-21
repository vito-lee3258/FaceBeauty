#include "Beautification.h"

imageLighten::imageLighten(void)
{
	// initialize parameter list.
	Initialize("ParameterList");
}

imageLighten::~imageLighten()
{

}

bool imageLighten::RunBeautify(CYUV420Image* pMainYUV, char* fileName)
{
	int nW = pMainYUV->GetWidth();
	int nH = pMainYUV->GetHeight();

	// compute skin mask map list.
	SkinLineMappingList();

	// compute lighten line map list.
	CurveMappingList();

	CGaussianPyramid2 Pyramid;
	pDownScaleYUV.Create(nW / 2, nH / 2);
	if (Pyramid.DownScaleImage(pMainYUV, &pDownScaleYUV, false, false))
	{
		printf("Down Scale YUV420 ... \n");
	}

	pUpScaleYUV.Create(nW, nH);
	if (Pyramid.UpScaleImage(&pDownScaleYUV, &pUpScaleYUV, false, false))
	{
		printf("Up scale YUV444 to YUV420 ...\n");
	}

	// Convert down scale YUV444 to BGR.
	pBGR.Create(nW / 2, nH / 2);
	pBGR.Copy(&pDownScaleYUV);
	
	pBGR.YCbCr2RGB();
	if (m_nSaveAndPrintDebugInfo)
	{
		pBGR.SaveToBMPFile("BGR.bmp");
	}

	// find skin mask.
	pSkinMask.Create(nW / 2, nH / 2);
	FindSkinMask(&pDownScaleYUV, &pSkinMask);

	// high pass filter.
	HighPassFilter(&pBGR, &pSkinMask);

	CGrayImage UpScaleSkinMask;
	UpScaleSkinMask.Create(nW, nH);
	if (Pyramid.UpScaleImage(&pSkinMask, &UpScaleSkinMask, false, false))
	{
		printf("Up scale skin mask ... \n");
	}

	if (m_nSaveAndPrintDebugInfo)
	{
		UpScaleSkinMask.SaveToBMPFile("UpScaleSkinMask.BMP");
		pBGR.SaveToBMPFile("ProcessedBGR.bmp");
	}

	// convert processed BGR image to YUV444.
	pBGR.RGB2YCbCr();

	// adjust saturation and hue in YUV444.
	AdjustHueAndSat(&pDownScaleYUV, &pBGR, &pSkinMask);

	CYUV420Image UpScaleYUV420;
	UpScaleYUV420.Create(nW, nH);
	if (Pyramid.UpScaleImage(&pBGR, &UpScaleYUV420, false, false))
	{
		printf("Up scale smoothed image ...\n");
	}

	// add high pass data back in full size.		
	AddHighPassBackAndBlend(pMainYUV, &pUpScaleYUV, &UpScaleYUV420, &UpScaleSkinMask);

	pMainYUV->Copy(&UpScaleYUV420);

	return true;
}

void imageLighten::FindSkinMask(CRGBYUVImage* YCbCr,CGrayImage* SkinMask)
{
	int nW = YCbCr->GetWidth();
	int nH = YCbCr->GetHeight();

	for (int y = 0; y < nH; y++)
	{
		BYTE* pYCbCrLine = YCbCr->GetImageLine(y);
		BYTE* pMaskLine = SkinMask->GetImageLine(y);
		for (int x = 0; x < nW; x++)
		{

			BYTE Y = pYCbCrLine[3 * x + 0];
			BYTE Cb = pYCbCrLine[3 * x + 1];
			BYTE Cr = pYCbCrLine[3 * x + 2];

			int percentY = m_nLineMapListY[Y];
			int percentCb = m_nLineMapListCb[Cb];
			int percentCr = m_nLineMapListCr[Cr];

			int percent = (percentY * percentCb * percentCr) * 128 / (m_nSkinTransitionWidth * m_nSkinTransitionWidth * m_nSkinTransitionWidth);

			// pixel in skin area.
			pMaskLine[x] = (int)percent;
		}
	}

	if (m_nSaveAndPrintDebugInfo)
	{
		SkinMask->SaveToBMPFile("skinMask.bmp");
	}
}

void imageLighten::SkinLineMappingList()
{
	for (int k = 0; k < 256; k++)
	{
		int percentY = 0;
		int percentCb = 0;
		int percentCr = 0;

		BYTE Y = k;
		BYTE Cb = k;
		BYTE Cr = k;

		// Y
		if (Y < m_nMinY)
		{
			percentY = 0;
		}
		else if (Y < (m_nMinY + m_nSkinTransitionWidth) && Y >= m_nMinY)
		{
			percentY = (Y - m_nMinY);
		}
		else if (Y >= (m_nMinY + m_nSkinTransitionWidth) && (m_nMaxY - m_nSkinTransitionWidth) >= Y)
		{
			percentY = m_nSkinTransitionWidth;
		}
		else if ((m_nMaxY - m_nSkinTransitionWidth) < Y && Y <= m_nMaxY)
		{
			percentY = m_nSkinTransitionWidth - (Y - (m_nMaxY - m_nSkinTransitionWidth));
		}
		else if (Y > m_nMaxY)
		{
			percentY = 0;
		}

		// Cb
		if (Cb < m_nMinCb)
		{
			percentCb = 0;
		}
		else if (Cb >= m_nMinCb && Cb < (m_nMinCb + m_nSkinTransitionWidth))
		{
			percentCb = (Cb - m_nMinCb);
		}
		else if (Cb >= (m_nMinCb + m_nSkinTransitionWidth) && Cb <= (m_nMaxCb - m_nSkinTransitionWidth))
		{
			percentCb = m_nSkinTransitionWidth;
		}
		else if ((m_nMaxCb - m_nSkinTransitionWidth) < Cb && Cb <= m_nMaxCb)
		{
			percentCb = m_nSkinTransitionWidth - (Cb - (m_nMaxCb - m_nSkinTransitionWidth));
		}
		else if (Cb > m_nMaxCb)
		{
			percentCb = 0;
		}

		// Cr
		if (Cr < m_nMinCr)
		{
			percentCr = 0;
		}
		else if (Cr < (m_nMinCr + m_nSkinTransitionWidth) && Cr >= m_nMinCr)
		{
			percentCr = (Cr - m_nMinCr);
		}
		else if (Cr >= (m_nMinCr + m_nSkinTransitionWidth) && Cr <= (m_nMaxCr - m_nSkinTransitionWidth))
		{
			percentCr = m_nSkinTransitionWidth;
		}
		else if (Cr > (m_nMaxCr - m_nSkinTransitionWidth) && Cr <= m_nMaxCr)
		{
			percentCr = m_nSkinTransitionWidth - (Cr - (m_nMaxCr - m_nSkinTransitionWidth));
		}
		else if (Cr > m_nMaxCr)
		{
			percentCr = 0;
		}

		m_nLineMapListY[Y] = percentY;
		m_nLineMapListCb[Cb] = percentCb;
		m_nLineMapListCr[Cr] = percentCr;
	}
}

bool imageLighten::CurveMappingList()
{
	// gamma curve map-list.	
	if (m_bUseGammaCurve)
	{
		float fGamma = m_nGamma / 100.0;
		for (int i = 0; i < 256; i++)
		{
			m_nLookUpTable[i] = BYTE(pow(i / 255.0, fGamma) * 255.0);
		}
	}
	else
	{
		for (int k = 0; k < 256; k++)
		{
			BYTE R = k;
			int temp = 0;

			if (R <= m_nPoint_1 && m_nPoint_1 != 0)
			{
				temp = (R + (m_nPoint_1 - R) * (m_nDelta_0 - m_nDelta_1) / m_nPoint_1 + m_nDelta_1);
			}
			else if (R <= m_nPoint_2 && (m_nPoint_2 - m_nPoint_1) != 0)
			{
				temp = R + (m_nPoint_2 - R) * (m_nDelta_1 - m_nDelta_2) / (m_nPoint_2 - m_nPoint_1) + m_nDelta_2;
			}
			else if (R <= m_nPoint_3 && (m_nPoint_3 - m_nPoint_2) != 0)
			{
				temp = R + (m_nPoint_3 - R) * (m_nDelta_2 - m_nDelta_3) / (m_nPoint_3 - m_nPoint_2) + m_nDelta_3;
			}
			else if (R <= m_nPoint_4 && (m_nPoint_4 - m_nPoint_3) != 0)
			{
				temp = R + (m_nPoint_4 - R) * (m_nDelta_3 - m_nDelta_4) / (m_nPoint_4 - m_nPoint_3) + m_nDelta_4;
			}
			else if (R <= m_nPoint_5 && (m_nPoint_5 - m_nPoint_4) != 0)
			{
				temp = R + (m_nPoint_5 - R) * (m_nDelta_4 - m_nDelta_5) / (m_nPoint_5 - m_nPoint_4) + m_nDelta_5;
			}
			else if (R <= m_nPoint_6 && (m_nPoint_6 - m_nPoint_5) != 0)
			{
				temp = R + (m_nPoint_6 - R) * (m_nDelta_5 - m_nDelta_6) / (m_nPoint_6 - m_nPoint_5) + m_nDelta_6;
			}
			else if (R <= m_nPoint_7 && (m_nPoint_7 - m_nPoint_6) != 0)
			{
				temp = R + (m_nPoint_7 - R) * (m_nDelta_6 - m_nDelta_7) / (m_nPoint_7 - m_nPoint_6) + m_nDelta_7;
			}
			else
			{
				std::cout << "Lighten line's setting out off range !!! \n";
				return false;
			}

			m_nLookUpTable[k] = Clip(temp);
		}
	}

	// use skin mask to add high pass data.
	for (int i = 0; i < 129; i++)
	{
		if (m_nMaskValue_0 == m_nMaskValue_1)
		{
			printf("m_nMaskValue_0 equal m_nMaskValue_1, ERROR ! \n");
			return false;
		}
		if (i <= m_nMaskValue_0)
		{
			m_nAddNoisePercent[i] = m_nNoisePercent_0;
		}
		else if (i <= m_nMaskValue_1)
		{
			if (m_nNoisePercent_0 == m_nNoisePercent_1)
				m_nAddNoisePercent[i] = m_nNoisePercent_0;
			else
				m_nAddNoisePercent[i] = m_nNoisePercent_1 + (m_nNoisePercent_0 - m_nNoisePercent_1) * (m_nMaskValue_1 - i) / (m_nMaskValue_1 - m_nMaskValue_0);
		}
		else
		{
			m_nAddNoisePercent[i] = m_nNoisePercent_1;
		}
	}
}

void imageLighten::HighPassFilter(CRGBYUVImage* pIn, CGrayImage* SkinMask)
{
	int nW = pIn->GetWidth();
	int nH = pIn->GetHeight();

	// copy origin image.
	CRGBYUVImage OriImage;
	OriImage.Create(nW, nH);
	OriImage.Copy(pIn);

	// Lighten image.
	AdjustSaturationAndLighten(pIn, SkinMask);

	// smooth face.
	LocalStatisticsFilter(pIn, SkinMask);

	// image fusion.
	Blend(pIn, &OriImage, SkinMask);

	// image sharpen.	
	if (m_bSharpenInDownScale)
	{
		ImageSharpen(pIn, m_nDownScaleSigma_0, m_nDownScaleSigma_1);
	}
}

void imageLighten::AdjustSaturationAndLighten(CRGBYUVImage* pIn, CGrayImage* pSkinMask)
{
	printf("Start to filter the image and skin mask ...\n");

	int nW = pIn->GetWidth();
	int nH = pIn->GetHeight();

	int nValue = 0;
	int nBGR[3] = { 0, 0, 0 };
	for (int y = 0; y < nH; y++)
	{
		BYTE* pLine = pIn->GetImageLine(y);
		BYTE* pMaskLine = pSkinMask->GetImageLine(y);
		for (int x = 0; x < nW; x++)
		{
			int B = pLine[3 * x + 0];
			int G = pLine[3 * x + 1];
			int R = pLine[3 * x + 2];
			nValue = max(R, max(G, B));

			if (nValue == 0)
			{
				nBGR[2] = R;
				nBGR[1] = G;
				nBGR[0] = B;
			}
			else if (nValue == R)
			{
				nBGR[2] = m_nLookUpTable[R];
				nBGR[1] = Clip(nBGR[2] - ((nBGR[2] * (R - G)) / R));
				nBGR[0] = Clip(nBGR[2] - ((nBGR[2] * (R - B)) / R));
			}
			else if (nValue == G)
			{
				nBGR[1] = m_nLookUpTable[G];
				nBGR[2] = Clip(nBGR[1] - ((nBGR[1] * (G - R)) / G));
				nBGR[0] = Clip(nBGR[1] - ((nBGR[1] * (G - B)) / G));
			}
			else if (nValue == B)
			{
				nBGR[0] = m_nLookUpTable[B];
				nBGR[1] = Clip(nBGR[0] - ((nBGR[0] * (B - G)) / B));
				nBGR[2] = Clip(nBGR[0] - ((nBGR[0] * (B - R)) / B));
			}

			pLine[3 * x + 0] = nBGR[0];
			pLine[3 * x + 1] = nBGR[1];
			pLine[3 * x + 2] = nBGR[2];
		}
	}

	if (m_nSaveAndPrintDebugInfo)
	{
		pIn->SaveToBMPFile("Lighten.bmp");
	}
}


void imageLighten::Lighten(CRGBYUVImage* pIn)
{
	int nW = pIn->GetWidth();
	int nH = pIn->GetHeight();

	int nMax = 0;
	int nBGR[3] = { 0, 0, 0 };
	for (int y = 0; y < nH; y++)
	{
		BYTE* pLine = pIn->GetImageLine(y);
		for (int x = 0; x < nW; x++)
		{
			nBGR[0] = pLine[3 * x + 0];
			nBGR[1] = pLine[3 * x + 1];
			nBGR[2] = pLine[3 * x + 2];

			nMax = max(nBGR[0], max(nBGR[1], nBGR[2]));
			if (nMax == nBGR[0])
				pLine[3 * x + 0] = m_nLookUpTable[nBGR[0]];
			if (nMax == nBGR[1])
				pLine[3 * x + 1] = m_nLookUpTable[nBGR[1]];
			if (nMax == nBGR[2])
				pLine[3 * x + 2] = m_nLookUpTable[nBGR[2]];
		}
	}

	if (m_nSaveAndPrintDebugInfo)
	{
		pIn->SaveToBMPFile("Lighten.bmp");
	}
}

void imageLighten::LocalStatisticsFilter(CRGBYUVImage* pIn, CGrayImage* pSkinMask)
{
	int nW = pSkinMask->GetWidth();
	int nH = pSkinMask->GetHeight();

	CSmoothFilter Smooth;
	int nMaskRadius = m_nMaskRadius;
	Smooth.BoxFilter(pSkinMask, nMaskRadius);

	// filter BGR channel.
	int nFilterSigma = m_nFilterSigma;
	int nRadius = m_nLocalStatisticsRadius;

	Smooth.FastLocalStatistics(pIn, pSkinMask, nRadius, nFilterSigma, m_nAddNoisePercent_0);
    
	if (m_nSaveAndPrintDebugInfo)
	{
		pIn->SaveToBMPFile("LocalFilterAndLighten.bmp");
		pSkinMask->SaveToBMPFile("FilterMask.bmp");
	}
}

void imageLighten::AddNoiseBack(CRGBYUVImage* pIn, CRGBYUVImage* pFiltered)
{
	printf("Start to add noise back in down-scale image ...\n");

	int nW = pIn->GetWidth();
	int nH = pIn->GetHeight();

	if (m_nAddNoisePercent_0 == 0)
	{
		printf("Do not add noise back in down scale levle ... \n");
		pIn->Copy(pFiltered);
		return;
	}

	for (int y = 0; y < nH; y++)
	{
		BYTE* pLine = pIn->GetImageLine(y);
		BYTE* pFilteredLine = pFiltered->GetImageLine(y);
		for (int x = 0; x < nW; x++)
		{
			int nSmoothBGR[3], nDiffBGR[3], nBGR[3];

			nSmoothBGR[0] = pFilteredLine[3 * x + 0];
			nSmoothBGR[1] = pFilteredLine[3 * x + 1];
			nSmoothBGR[2] = pFilteredLine[3 * x + 2];

			for (int i = 0; i < 3; i++)
			{
				nBGR[i] = pLine[3 * x + i];

				// get high pass.
				nDiffBGR[i] = (int)nBGR[i] - (int)nSmoothBGR[i];

				// add part of highpass back.
				pLine[3 * x + i] = Clip(nSmoothBGR[i] + (nDiffBGR[i] * m_nAddNoisePercent_0 >> 7));
			}
		}
	}

	if (m_nSaveAndPrintDebugInfo)
	{
		pIn->SaveToBMPFile("AddbackNoise.bmp");
	}
}

void imageLighten::AddHighPassBackAndBlend(CYUV420Image* pMainYUV, CYUV420Image* pMainYUV2, CYUV420Image* pSmoothYUV, CGrayImage* pMask)
{
	printf("Start to add high pass data back in full size ...\n");

	int nW = pMainYUV->GetWidth();
	int nH = pMainYUV->GetHeight();

	for (int y = 0; y < nH; y++)
	{
		BYTE* pMainLine = pMainYUV->GetYLine(y);
		BYTE* pMainLine2 = pMainYUV2->GetYLine(y);
		BYTE* pSmoothLine = pSmoothYUV->GetYLine(y);
		BYTE* pMaskLine = pMask->GetImageLine(y);
		for (int x = 0; x < nW; x++)
		{
			// get high pass.
			int nDiffValue = (int)pMainLine[x] - (int)pMainLine2[x];

			// Use skin mask to add part of highpass back.
			if (pMaskLine[x] == 0)
			{
				pSmoothLine[x] = Clip((int)pSmoothLine[x] + nDiffValue);
			}
			else
			{
				pSmoothLine[x] = Clip(pSmoothLine[x] + ((nDiffValue * m_nAddNoisePercent[int(pMaskLine[x])]) / 128));
			}
		}
	}
}

void imageLighten::Blend(CRGBYUVImage* pIn, CRGBYUVImage* pOri, CGrayImage* pSkinMask)
{
	int nW = pIn->GetWidth();
	int nH = pIn->GetHeight();

	// adjust saturation and fusion.
	int temp[3] = {0, 0, 0};
	for (int y = 0; y < nH; y++)
	{
		BYTE* pLine = pIn->GetImageLine(y);
		BYTE* pOriLine = pOri->GetImageLine(y);
		BYTE* pSkinMaskLine = pSkinMask->GetImageLine(y);
		for (int x = 0; x < nW; x++)
		{
			// adjust saturation.
			int nBGR[3] = { 0, 0, 0 };
			nBGR[2] = (int)pLine[3 * x + 2];
			nBGR[1] = (int)pLine[3 * x + 1];
			nBGR[0] = (int)pLine[3 * x + 0];

			// image fusion in final step.
			temp[0] = ((int)pOriLine[3 * x + 0] * (128 - pSkinMaskLine[x]) + nBGR[0] * pSkinMaskLine[x]) >> 7;
			temp[1] = ((int)pOriLine[3 * x + 1] * (128 - pSkinMaskLine[x]) + nBGR[1] * pSkinMaskLine[x]) >> 7;
			temp[2] = ((int)pOriLine[3 * x + 2] * (128 - pSkinMaskLine[x]) + nBGR[2] * pSkinMaskLine[x]) >> 7;

			pLine[3 * x + 0] = Clip(temp[0]);
			pLine[3 * x + 1] = Clip(temp[1]);
			pLine[3 * x + 2] = Clip(temp[2]);
		}
	}

	if (m_nSaveAndPrintDebugInfo)
	{
		pIn->SaveToBMPFile("Fusion.bmp");
	}
}

void imageLighten::ImageSharpen(CRGBYUVImage* pIn, int nSigma_0, int nSigma_1)
{
	printf("Sharpen image in down scale image ...\n");

	int nW = pIn->GetWidth();
	int nH = pIn->GetHeight();

	CRGBYUVImage Filter1, Filter2;
	Filter1.Create(nW, nH);
	Filter2.Create(nW, nH);

	CSmoothFilter Smooth;
	Filter1.Copy(pIn);
	Filter2.Copy(pIn);

	if (nSigma_0 > 0)
	{
		float fSigma0 = nSigma_0;
		Smooth.GaussSmooth(&Filter1, fSigma0);
	}

	if (nSigma_1 > 0)
	{
		float fSigma1 = nSigma_1;
		Smooth.GaussSmooth(&Filter2, fSigma1);
	}

	for (int y = 0; y < nH; y++)
	{
		BYTE* pLines = pIn->GetImageLine(y);
		BYTE* pGauss1 = Filter1.GetImageLine(y);
		BYTE* pGauss2 = Filter2.GetImageLine(y);
		for (int x = 0; x < nW; x++)
		{
			for (int i = 0; i < 3; i++)
			{
				int temp = 0;
				int nDiff = (int)pGauss1[3 * x + i] - (int)pGauss2[3 * x + i];

				if(nDiff > 0)
					temp = (int)pLines[3 * x + i] + (m_nPositiveDiff * nDiff >> 7);
				else
					temp = (int)pLines[3 * x + i] + (m_nNegativeDiff * nDiff / 128);

				pLines[3 * x + i] = Clip(temp);
			}
		}
	}
}

void imageLighten::AdjustHueAndSat(CRGBYUVImage* pOriYUV, CRGBYUVImage* pProcessedYUV, CGrayImage* pMask)
{
	int nW = pOriYUV->GetWidth();
	int nH = pOriYUV->GetHeight();

	float nTheta = m_nAdjustHue / 180.0;
	int nC = cos(nTheta) * 4096;
	int nS = sin(nTheta) * 4096;

	int nU = 0;
	int nV = 0;
	int nUV[2] = { 0, 0 };
	for (int y = 0; y < nH; y++)
	{
		BYTE* pMaskLine = pMask->GetImageLine(y);
		BYTE* pOriLine = pOriYUV->GetImageLine(y);
		BYTE* pOutLine = pProcessedYUV->GetImageLine(y);
		for (int x = 0; x < nW; x++)
		{
			if (pMaskLine[x] == 0)
			{
				pOutLine[3 * x + 1] = pOriLine[3 * x + 1];
				pOutLine[3 * x + 2] = pOriLine[3 * x + 2];
			}
			else
			{
				// adjust saturation.
				if (m_bKeepSaturantion)// U' = U * (Y' / Y), V' = V * (Y' / Y).
				{
					nUV[0] = ((int)pOriLine[3 * x + 1] - 128) * pOutLine[3 * x + 0] * (16384 + pMaskLine[x] * m_nAdjustSaturation) / (pOriLine[3 * x + 0] * 16384);//16384 = 128 * 128.
					nUV[1] = ((int)pOriLine[3 * x + 2] - 128) * pOutLine[3 * x + 0] * (16384 + pMaskLine[x] * m_nAdjustSaturation) / (pOriLine[3 * x + 0] * 16384);
				}
				else// use origin UV to adjust saturation and hue.
				{
					nUV[0] = ((int)pOriLine[3 * x + 1] - 128) * (16384 + pMaskLine[x] * m_nAdjustSaturation) / 16384;
					nUV[1] = ((int)pOriLine[3 * x + 2] - 128) * (16384 + pMaskLine[x] * m_nAdjustSaturation) / 16384;
				}

				// adjust Hue.
				nU = 128 + (nUV[0] * nC + nUV[1] * nS) / 4096;
				nV = 128 + (nUV[1] * nC - nUV[0] * nS) / 4096;

				pOutLine[3 * x + 1] = Clip(nU);
				pOutLine[3 * x + 2] = Clip(nV);
			}
		}
	}
}