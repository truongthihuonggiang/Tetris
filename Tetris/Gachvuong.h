#pragma once
#include "Gach.h"
class Gachvuong :
    public Gach
{
public:
    Gachvuong():Gach(){}
    Gachvuong(int mx, int my, int mr, int mg, int mb,int mxdau, int mydau) {
        r = mr;
        g = mg;
        b = mb;
        trangthai = 0;
        gach[0] = Hcnmau(mx, my, mx + D, my + D, r, g, b);
        gach[1] = Hcnmau(mx + D, my, mx + D + D, my + D, r, g, b);
        gach[2] = Hcnmau(mx , my + D, mx + D, my + D + D, r, g, b);
        gach[3] = Hcnmau(mx + D , my + D, mx + D + D, my + D + D, r, g, b);
        xdau = mxdau;
        ydau = mydau;
    }
};

