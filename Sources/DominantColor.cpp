#include "../Includes/DominantColor.h"

DominantColors& DominantColors::get()
{
    static DominantColors instance;
    return instance;
}

double DominantColors::calculateDistance(int R1, int G1, int B1, int R2, int G2, int B2)
{
    return sqrt((double)((R1-R2)*(R1-R2) + (G1-G2)*(G1-G2) + (B1-B2)*(B1-B2)));
}

vector<QColor> DominantColors::countDominantColors(QImage image)
{
    
    unsigned char R, G, B;
    unsigned sumR = 0;
    unsigned sumG = 0;
    unsigned sumB = 0;

    int w = image.width();
    int h = image.height();


    for (int y = 0; y < h; ++y)
        for (int x = 0; x < w; ++x) {
            B = qBlue(image.pixel(x,y));
            G = qGreen(image.pixel(x,y));
            R = qRed(image.pixel(x,y));

            sumR += R;
            sumG += G;
            sumB += B;
        }

    unsigned meanR = sumR / (w*h);
    unsigned meanG = sumG / (w*h);
    unsigned meanB = sumB / (w*h);

    vector<Color> dominant_colors;
    dominant_colors.reserve(DOMINANTCOLORS_NUMBER);
    Color newColor(meanR, meanG, meanB);
    newColor.points.reserve(w*h);
    dominant_colors.push_back(newColor);
    
    for (int i = 0; i < DOMINANTCOLORS_NUMBER; ++i) {
        bool changesPerformed = true;

        int* oldDominantColorsAssignment = new int[w*h]();
        int* newDominantColorsAssignment = new int[w*h]();

        for (int j = 0; j < w*h; ++j) {
            oldDominantColorsAssignment[j] = -1;
            newDominantColorsAssignment[j] = -1;
        }
        while (changesPerformed) {
            changesPerformed = false;
            for (int j = 0; j < w*h; ++j)
                oldDominantColorsAssignment[j] = newDominantColorsAssignment[j];

            for (unsigned j = 0; j < dominant_colors.size(); ++j)
                dominant_colors[j].points.clear();

            for (int y = 0; y < h; ++y)
                for (int x = 0; x < w; ++x) {
                    int toWhichDominantColorThisPointBelongs = 0;
                    double oldDistance = std::numeric_limits<double>::max();
                    double newDistance = 0;
 
                    for (unsigned k = 0; k < dominant_colors.size(); ++k) {
                        newDistance = calculateDistance(qRed(image.pixel(x,y)), qGreen(image.pixel(x,y)), qBlue(image.pixel(x,y)), dominant_colors[k].R, dominant_colors[k].G, dominant_colors[k].B);
                        if(newDistance < oldDistance) {
                            toWhichDominantColorThisPointBelongs = k;
                            oldDistance = newDistance;
                        }
                    }

                    dominant_colors[toWhichDominantColorThisPointBelongs].points.push_back(x+y*w);
                    newDominantColorsAssignment[x+y*w] = toWhichDominantColorThisPointBelongs;
                    if(!changesPerformed && newDominantColorsAssignment[x+y*w] != oldDominantColorsAssignment[x+y*w])
                        changesPerformed = true;
                }
            
            if(changesPerformed) {
                for (unsigned j = 0; j < dominant_colors.size(); ++j) {
                    if (!dominant_colors[j].points.size())
                        continue;
                    unsigned newSumR = 0; 
                    unsigned newSumG = 0;
                    unsigned newSumB = 0;
                    for (unsigned k = 0; k < dominant_colors[j].points.size(); ++k) {
                        int x = dominant_colors[j].points[k] % w;
                        int y = dominant_colors[j].points[k] / w;
                        newSumB += qBlue(image.pixel(x,y));
                        newSumG += qGreen(image.pixel(x,y));
                        newSumR += qRed(image.pixel(x,y));
                    }

                    dominant_colors[j].B = newSumB / dominant_colors[j].points.size();
                    dominant_colors[j].G = newSumG / dominant_colors[j].points.size();
                    dominant_colors[j].R = newSumR / dominant_colors[j].points.size();
                }
            }
        }

        delete[] oldDominantColorsAssignment;
        delete[] newDominantColorsAssignment;

        if (i == DOMINANTCOLORS_NUMBER-1)
            continue;

        double maxVariance = 0;
        double variance = 0;
        int highestVarianceIndex = 0;
        

        for (unsigned j = 0; j < dominant_colors.size(); ++j) {
            variance = calculateVariance(image, dominant_colors[j]);
            if(variance > maxVariance) {
                highestVarianceIndex = j;
                maxVariance = variance;
            }
        }

        unsigned char R = dominant_colors[highestVarianceIndex].R;
        unsigned char G = dominant_colors[highestVarianceIndex].G;
        unsigned char B = dominant_colors[highestVarianceIndex].B;

        if (R == 255)
            R -= 2;
        if (G == 255)
            G -= 2;
        if (B == 255)
            B -= 2;

        Color color(R+1, G+1, B+1);
        color.points.reserve(w*h);
        dominant_colors.push_back(color);
    }

    vector<QColor> dominantColors;
    dominantColors.reserve(8);
    
    for (int i = 0; i < DOMINANTCOLORS_NUMBER; ++i)
        dominantColors.push_back(QColor(dominant_colors[i].R, dominant_colors[i].G, dominant_colors[i].B));

    return dominantColors;
}

double DominantColors::calculateVariance(QImage image, Color color)
{
    unsigned sumR = 0; 
    unsigned sumG = 0; 
    unsigned sumB = 0;
    unsigned sumRSquared = 0;
    unsigned sumGSquared = 0;
    unsigned sumBSquared = 0;

    unsigned char R;
    unsigned char G;
    unsigned char B;

    unsigned size = color.points.size();

    if(size <= 1)
        return 0;

    for(unsigned i = 0; i < size; ++i) {
        int x = color.points[i] % image.width();
        int y = color.points[i] / image.width();

        R = qRed(image.pixel(x, y));
        G = qGreen(image.pixel(x, y));
        B = qBlue(image.pixel(x, y));

        sumR += R;
        sumG += G;
        sumB += B;
        sumRSquared += R*R;
        sumGSquared += G*G;
        sumBSquared += B*B;
    }

    int varianceR = size * sumRSquared - sumR*sumR;
    varianceR /= size * (size - 1);
    int varianceG = size * sumGSquared - sumG*sumG;
    varianceG /= size * (size - 1);
    int varianceB = size * sumBSquared - sumB*sumB;
    varianceB /= size * (size - 1);

    return sqrt((double)(varianceR*varianceR + varianceG*varianceG + varianceB*varianceB));
}