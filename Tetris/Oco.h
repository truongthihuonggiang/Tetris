#pragma once
#include "Hcnmau.h"
class Oco :
    public Hcnmau
{
public:
    int trangthai; //0 tuc la ko co gach, 1 tuc la co gach
    Oco() :Hcnmau() {
        trangthai = 0;
    }
    Oco(int mx1, int my1, int mx2, int my2, int mr, int mg, int mb) :Hcnmau(mx1, my1, mx2, my2, mr, mg, mb) {
        trangthai = 0;
    }
    void vehinh(CClientDC* pdc);
};

