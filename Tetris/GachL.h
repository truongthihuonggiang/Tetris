#pragma once
#include "Gach.h"
class GachL :
    public Gach
{
public:
    GachL():Gach(){}
    GachL(int mx, int my, int mr, int mg, int mb, int mxdau, int mydau) {
        r = mr;
        g = mg;
        b = mb;
        trangthai = 0;
        gach[0] = Hcnmau(mx, my, mx + D, my + D, r, g, b);
        gach[1] = Hcnmau(mx , my + D, mx + D , my + 2* D, r, g, b);
        gach[2] = Hcnmau(mx, my + 2* D, mx + D, my + 3 * D, r, g, b);
        gach[3] = Hcnmau(mx + D, my + 2 * D, mx + 2* D, my + 3 * D, r, g, b);

        xdau = mxdau;
        ydau = mydau;
    }
    void xoayhinh();
    void traxoayhinh();
};

