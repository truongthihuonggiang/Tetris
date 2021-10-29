#pragma once
#include "Hcnmau.h"
#define D 40
class Gach
{
public:
	Hcnmau gach[4];
	int r, g, b;
	int trangthai;
	int xdau, ydau;
	Gach();
	void dichtrai();
	void dichphai();
	void dichxuong();
	void dichlen();
	void virtual xoayhinh();
	void virtual traxoayhinh();
	int getYmax();
	int getYmin();
	int getXmax();
	int getXmin();
	void vehinh(CClientDC* pdc);
};

