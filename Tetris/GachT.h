#pragma once
#include "Gach.h"
class GachT :
    public Gach
{
public:
    GachT():Gach(){}
    GachT(int mx, int my, int mr, int mg, int mb, int mxdau, int mydau) {
        r = mr;
        g = mg;
        b = mb;
        trangthai = 0;
        gach[0] = Hcnmau(mx - D, my, mx , my + D, r, g, b);
        gach[1] = Hcnmau(mx, my , mx + D, my +  D, r, g, b);
        gach[2] = Hcnmau(mx + D, my , mx +2* D, my + D, r, g, b);

        gach[3] = Hcnmau(mx, my +  D, mx + D, my + 2 * D, r, g, b);
        xdau = mxdau;
        ydau = mydau;
    }
    void xoayhinh();
    void traxoayhinh();
};

