#include "pch.h"
#include "Hcn.h"

Hcn::Hcn()
{
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
}

Hcn::Hcn(int mx1, int my1, int mx2, int my2)
{
	x1 = mx1;
	y1 = my1;
	x2 = mx2;
	y2 = my2;
}

void Hcn::dichtrai(int d)
{
	x1 = x1 - d;
	x2 = x2 - d;
}

void Hcn::dichphai(int d)
{
	x1 = x1 + d;
	x2 = x2 + d;
}

void Hcn::dichlen(int d)
{
	y1 = y1 - d;
	y2 = y2 - d;
}

void Hcn::dichxuong(int d)
{
	y1 = y1 + d;
	y2 = y2 + d;
}

void Hcn::vehinh(CClientDC* pdc)
{
	pdc->Rectangle(x1, y1, x2, y2);
}
