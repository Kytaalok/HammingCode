#pragma once
#include "../SignalGenerator/SignalGenerator.h"
#include <vector>
enum class noiseForm {
	a, // �������������
	asinbx, // ��������������
	axx // ������������
};
std::vector<Dot> generateNoise(int randSeed, const std::vector<Dot>& signal, double t, double dt, double nu, double dnu,
	noiseForm form, bool polarity, std::vector<double> params);