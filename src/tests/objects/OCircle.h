#pragma once
#include "Object.h"
class OCircle : public Object
{
private:
    /* data */
public:
    OCircle(float centerX, float centerY, float radius, int res);
    void GenerateCircle(float radius, int res);
    float m_radius;
    int m_resolution;
};
