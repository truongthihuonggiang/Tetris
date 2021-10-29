#include "pch.h"
#include "GachT.h"

void GachT::xoayhinh()
{
	if (trangthai == 0)
	{
		gach[2].x1 = gach[1].x1;
		gach[2].x2 = gach[1].x2;
		gach[2].y1 = gach[1].y1 - D;
		gach[2].y2 = gach[1].y2 - D;
		trangthai = 1;
	}
	else
		if (trangthai == 1)
		{
			gach[3].x1 = gach[1].x1 + D;
			gach[3].x2 = gach[1].x2 + D;
			gach[3].y1 = gach[1].y1;
			gach[3].y2 = gach[1].y2;
			trangthai = 2;
		}
		else
			if (trangthai == 2)
			{
				gach[0].x1 = gach[1].x1;
				gach[0].x2 = gach[1].x2;
				gach[0].y1 = gach[1].y1 + D;
				gach[0].y2 = gach[1].y2 + D;
				trangthai = 3;
				
			}
			else
				if (trangthai == 3)
				{	
					gach[2].x1 = gach[3].x1;
					gach[2].x2 = gach[3].x2;
					gach[2].y1 = gach[3].y1;
					gach[2].y2 = gach[3].y2;

					gach[3].x1 = gach[0].x1;
					gach[3].x2 = gach[0].x2;
					gach[3].y1 = gach[0].y1;
					gach[3].y2 = gach[0].y2;

					gach[0].y1 = gach[1].y1;
					gach[0].y2 = gach[1].y2;
					gach[0].x1 = gach[1].x1 - D;
					gach[0].x2 = gach[1].x2 - D;

					trangthai = 0;
				}
}

void GachT::traxoayhinh()
{
	xoayhinh();
	xoayhinh();
	xoayhinh();
}
