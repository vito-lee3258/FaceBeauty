#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>
#include <windows.h>

#include "../ImgLib/Filter.h"
#include "Beautification.h"

#define strcat_s  strcat

using namespace std;

#include <math.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if (argc < 4)
	{
		std::cout << "Parameters ERROR !!!" << std::endl;
		return -1;
	}

	int nW = atoi(argv[2]);
	int nH = atoi(argv[3]);
	char* pInFile = argv[1];
	char* parameterList = argv[4];

	// Face beauty.
	imageLighten Beauty;
	if (!Beauty.LoadParameterFile(parameterList))
	{
		Beauty.SaveParameterFile("defaultParameters.txt");

		printf("Load parameter ERROR ! \n");
		return -1;
	}
	Beauty.SaveParameterFile("defaultParameters.txt");

	// Load 420 and process.
	CYUV420Image YUVIn;
	YUVIn.Create(nW, nH);
	if (YUVIn.LoadYUV420File(pInFile, nW, nH, 1))
	{
		CRGBYUVImage OriImg;
		OriImg.Create(nW, nH);
		YUVIn.YUV420ToYUV444(&OriImg);
		OriImg.YCbCr2RGB();

		char* pName = "_ori.bmp";
		strcat(pInFile, pName);

		OriImg.SaveToBMPFile(pInFile);

		int t1 = GetTickCount();

		if (Beauty.RunBeautify(&YUVIn, pInFile))
		{
			printf("Image process done ... \n");
		}

		int t2 = GetTickCount();

		printf("Time cost of beautify: %d ms\n", (t2 - t1));

		CRGBYUVImage Result;
		Result.Create(nW, nH);
		YUVIn.YUV420ToYUV444(&Result);
		Result.YCbCr2RGB();

		char* pName2 = "_result.bmp";
		strcat(pInFile, pName2);
		Result.SaveToBMPFile(pInFile);
	}
	return 0;
}