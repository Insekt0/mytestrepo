#ifndef DOMINANTCOLOR_H
#define DOMINANTCOLOR_H

#include "common.h"

#include <QColor>
#include <QImage>
#include <QRgb>
#include <vector>

using namespace std;

class Color
{
public:
    unsigned char R, G, B;
    Color() { };
    Color(unsigned char R, unsigned char G, unsigned char B) { this->R = R;  this->G = G;  this->B = B; }
    vector<int> points;
};

class DominantColors {
public:
    static DominantColors& get();
    vector<QColor> countDominantColors(QImage);
    double calculateDistance(vector<QColor>&, vector<QColor>&);
private:
    double calculateDistance(int R1, int G1, int B1, int R2, int G2, int B2);
    DominantColors() { }
    double calculateVariance(QImage, Color);
};

#endif // DOMINANTCOLOR_H