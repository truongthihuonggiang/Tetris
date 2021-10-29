#pragma once
class Hcn
{
public:
	int x1, y1, x2, y2;
	Hcn();
	Hcn(int mx1, int my1, int mx2, int my2);
	void dichtrai(int d);
	void dichphai(int d);
	void dichlen(int d);
	void dichxuong(int d);
	void vehinh(CClientDC* pdc);

};

