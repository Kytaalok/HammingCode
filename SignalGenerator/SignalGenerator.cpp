#include "SignalGenerator.h"
/*
bits - ������� ������������������ �� 0 � 1 � ��������� ����
method - ����� ��������������
dt - ��� �������������
A - ���������
bitDuration - ������������ �������� ���������
polarity - ���������� (0 - ������, 1 - ���������������)
*/
std::vector<Dot> generateSignalFromBits(const std::string& bits,
    conversionMethod method, double dt, double A, double bitDuration, bool polarity)
{
    std::vector<Dot> series;
    double r = 3, td = 0.05, h = 6;
    for (double x = 0; x <= 2 * r; x += td) series.emplace_back(x, sqrt(r * r - (x - r) * (x - r)));
    for (double x = 2 * r; x >= 0; x -= td) series.emplace_back(x, -sqrt(r * r - (x - r) * (x - r)));
    for (double x = 0; x >= -2 * r; x -= td) series.emplace_back(x, sqrt(r * r - (x + r) * (x + r)));
    for (double x = -2 * r; x <= 0; x += td) series.emplace_back(x, -sqrt(r * r - (x + r) * (x + r)));
    for (double x = 0; x <= r; x += td) series.emplace_back(x, sqrt(r * r - (x - r) * (x - r)));
    for (double y = r; y <= h; y += td) series.emplace_back(r, y);
    for (double x = r; x >= -r; x -= td) series.emplace_back(x, h + sqrt(r * r - x * x));
    for (double y = h; y >= r; y -= td) series.emplace_back(-r, y);
    return series;
}
