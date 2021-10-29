#include "pch.h"
#include "GachL.h"

void GachL::xoayhinh()
{
	if (trangthai == 0)
	{
		gach[0].dichphai(D);
		gach[0].dichxuong(D);
		gach[2].dichtrai(D);
		gach[2].dichlen(D);
		gach[3].dichtrai(2 * D);
		trangthai = 1;
	}
	else
		if (trangthai == 1)
		{
			gach[0].dichtrai(D);
			gach[0].dichxuong(D);
			gach[2].dichlen(D);
			gach[2].dichphai(D);
			gach[3].dichlen(2 * D);

			trangthai = 2;
		}
		else
			if (trangthai == 2)
			{
				gach[0].dichtrai(D);
				gach[0].dichlen(D);
				gach[2].dichphai(D);
				gach[2].dichxuong(D);
				gach[3].dichphai(2*D);
				trangthai = 3;
			}
			else
				if (trangthai == 3)
				{
					gach[0].dichphai(D);
					gach[0].dichlen(D);
					gach[2].dichtrai(D);
					gach[2].dichxuong(D);
					gach[3].dichxuong(2 * D);
					trangthai = 0;
				}

}

void GachL::traxoayhinh()
{
	xoayhinh();
	xoayhinh();
	xoayhinh();
}
