#include "pch.h"
#include "Gachthang.h"

void Gachthang::xoayhinh()
{
	if (trangthai == 0)
	{
		gach[0].x1 = gach[1].x1 - D;
		gach[0].x2 = gach[0].x1 + D;
		gach[0].y1 = gach[1].y1;
		gach[0].y2 = gach[0].y1 + D;
		
		gach[2].x1 = gach[1].x1 + D;
		gach[2].x2 = gach[2].x1 + D;
		gach[2].y1 = gach[1].y1;
		gach[2].y2 = gach[1].y2;

		gach[3].x1 = gach[1].x1 + 2 * D;
		gach[3].x2 = gach[3].x1 + D;
		gach[3].y1 = gach[1].y1;
		gach[3].y2 = gach[1].y2;

		trangthai = 1;
	}
	else
	{
		gach[0].x1 = gach[1].x1;
		gach[0].x2 = gach[1].x2;
		gach[0].y1 = gach[1].y1 - D;
		gach[0].y2 = gach[1].y2 - D;

		gach[2].x1 = gach[1].x1;
		gach[2].x2 = gach[1].x2;
		gach[2].y1 = gach[1].y1 + D;
		gach[2].y2 = gach[1].y2 + D;

		gach[3].x1 = gach[1].x1;
		gach[3].x2 = gach[1].x2;
		gach[3].y1 = gach[1].y1 + 2*D;
		gach[3].y2 = gach[1].y2 + 2*D;

		trangthai = 0;
	}
}

void Gachthang::traxoayhinh()
{
	xoayhinh();
}
