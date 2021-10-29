#include "pch.h"
#include "Gach.h"

Gach::Gach()
{

	for (int i = 0; i < 4; i++)
	{
		gach[i] = Hcnmau();
	}
	r = 0;
	g = 0;
	b = 0;
	trangthai = 0;
	xdau = 0;
	ydau = 0;
}

void Gach::dichtrai()
{
	for (int i = 0; i < 4; i++)
	{
		gach[i].dichtrai(D);
	}
}

void Gach::dichphai()
{
	for (int i = 0; i < 4; i++)
	{
		gach[i].dichphai(D);
	}
}

void Gach::dichxuong()
{
	for (int i = 0; i < 4; i++)
	{
		gach[i].dichxuong(D);
	}
}

void Gach::dichlen()
{
	for (int i = 0; i < 4; i++)
	{
		gach[i].dichlen(D);
	}
}

void Gach::xoayhinh()
{

}

void Gach::traxoayhinh()
{
}

int Gach::getYmax()
{
	int max = 0;
	for (int i = 0; i < 4; i++)
	{
		if (max < gach[i].y2)
			max = gach[i].y2;
	}
	return max;
}

int Gach::getYmin()
{
	int min = 100;
	min = gach[0].y1;
	for (int i = 0; i < 4; i++)
	{
		if (min > gach[i].y1)
			min = gach[i].y1;
	}
	return min;
}

int Gach::getXmax()
{
	int max = 0;
	for (int i = 0; i < 4; i++)
	{
		if (max < gach[i].x2)
			max = gach[i].x2;
	}
	return max;
}

int Gach::getXmin()
{
	int min = 100;
	 min = gach[0].x1;
	for (int i = 0; i < 4; i++)
	{
		if (min > gach[i].x1)
			min = gach[i].x1;
	}
	return min;
}

void Gach::vehinh(CClientDC* pdc)
{
	for (int i = 0; i < 4; i++)
	{
		if(gach[i].y1 >= ydau)
			gach[i].vehinh(pdc);
	}
}
