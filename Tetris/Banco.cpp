#include "pch.h"
#include "Banco.h"

Banco::Banco()
{
	diem = 0;
	level = 1;
	tocdo = 1;
	dk = 0;
	int d = 40;
	pg = NULL;
	khungve = Hcnmau(XDAU, YDAU, XDAU + RONG, YDAU + CAO,255,255,255);
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			ds[i][j] = Oco(XDAU + j * d, YDAU + i * d, XDAU + j * d + d, YDAU + i * d + d, 255, 255, 255);
		}
	}
	

}

void Banco::vehinh(CClientDC* pdc)
{
	khungve.vehinh(pdc);
	CString strdiem, strlevel,strstart;
	strdiem.Format(_T("Diem cua ban: %d    "), diem);
	strlevel.Format(_T("Level: %d    "), level);
	if(dk == 0 && thua == 0)
		strstart.Format(_T("bam phim space de bat dau"));
	pdc->TextOutW(XDAU + RONG + 50, YDAU + 50, strdiem);
	pdc->TextOutW(XDAU + RONG + 50, YDAU + 100, strlevel);
	pdc->TextOutW(XDAU + 120, YDAU + CAO / 2 - 50, strstart);
	if (pg)
		pg->vehinh(pdc);
	for(int i = 0; i< 20; i++)
		for (int j = 0; j < 12; j++)
		{
			ds[i][j].vehinh(pdc);
		}
	if (thua == 1)
	{
		CString strthua;
		strthua.Format(_T("Game Over"));
		pdc->TextOutW(XDAU + 120, YDAU + CAO / 2 - 50, strthua);
	}
	//pg = new Gachthang(XDAU +800 + RONG / 2 - D, YDAU , 0, 255, 0, XDAU, YDAU);
	//pg->vehinh(pdc);
}

void Banco::capnhathinh(CClientDC* pdc)
{
	while (dk == 1)
	{
		vehinh(pdc);
		Sleep(100);
	}
	if (thua == 1)
	{
		CString strthua;
		strthua.Format(_T("Game Over"));
		pdc->TextOutW(XDAU + 120, YDAU + CAO / 2 - 50, strthua);
	}
}

void Banco::khoitaogach()
{
	int t = 0;
	t = rand() % 4;
	//tam gan t = 0
	//t = 3;
	if (t == 0)
	{
		pg = new Gachvuong(XDAU + RONG / 2 - D, YDAU - 3 * D, 0, 255, 0,XDAU,YDAU);
	}
	if (t == 1) //khoi tao gach thang
	{
		pg = new Gachthang(XDAU + RONG / 2 - D, YDAU - 3 * D, 255, 255, 0, XDAU, YDAU);
	}
	if (t == 2) //khoi tao gach thang
	{
		pg = new GachT(XDAU + RONG / 2 - D, YDAU - 3 * D, 0, 255, 255, XDAU, YDAU);
	}
	if (t == 3) //khoi tao gach thang
	{
		pg = new GachL(XDAU + RONG / 2 - D, YDAU - 3 * D, 255, 0, 255, XDAU, YDAU);
	}
}

void Banco::capnhatgachroi()
{
	while (dk == 1)
	{
		if (pg )
		{
			int luutru = 0;
			if (pg->getYmax() < khungve.y2)
			{
				pg->dichxuong();
				int i, j, k;
				int d = 40;
				for (k = 0; k < 4; k++)
				{
					i = (pg->gach[k].y2 - YDAU) / d - 1;
					j = (pg->gach[k].x2 - XDAU) / d - 1;
					if (ds[i][j].trangthai == 1 && /*i >= 0 &&*/ j >= 0)
					{
						pg->dichlen();
						luutru = 1;
						break;
					}
					
				}
				
			}
			else
			{
				luutru = 1;
			}
			if(luutru == 1)
			{
				//neu khong dich xuong duoc thi ghi nhan thong tin vao dsoco
				int i, j, k;
				int d = 40;
				for (k = 0; k < 4; k++)
				{
					i = (pg->gach[k].y2 - YDAU) / d -1;
					j = (pg->gach[k].x2 - XDAU) / d-1;
					if (i >= 0 && j >= 0)
					{
						ds[i][j].trangthai = 1;
						ds[i][j].r = pg->r;
						ds[i][j].g = pg->g;
						ds[i][j].b = pg->b;
					}
					
				}
				//kiem tra co tinh diem va xoa gach dc hay khong
				kiemtralaydiem();
				//kiem tra thua
				
				if (pg->getYmin() < khungve.y1)
				{
					thua = 1;
					dk = 0;
				}
				//tao gach moi
				khoitaogach();
			}
			Sleep(500);
		}

	}
	
}

void Banco::batdaugame()
{
	dk = 1;
	khoitaogach();
	//capnhatgachroi();
}

void Banco::bamphimdichuyen(UINT nchar)
{
	if (dk == 0)
		return;
	if (nchar == 39)//dich phai
	{
		if (pg->getXmax() < khungve.x2)
		{
			pg->dichphai();
			if (cothedichchuyen() == 0)
				pg->dichtrai();
		}
		

	}
	else
		if (nchar == 37) //qua trai
		{
			if (pg->getXmin() > khungve.x1)
			{
				pg->dichtrai();
				if (cothedichchuyen() == 0)
					pg->dichphai();
			}
			
			
		}
		else
			if (nchar == 40)// di xuong
			{
				if (pg->getYmax() < khungve.y2)
				{
					pg->dichxuong();
					if (cothedichchuyen() == 0)
						pg->dichlen();
				}
				
			}
			else
				if (nchar == 38)//xoay hinh
				{
					pg->xoayhinh();
					if (cothedichchuyen() == 0)
						pg->traxoayhinh();
				}
}

int Banco::cothedichchuyen()
{
	//neu khong dich xuong duoc thi ghi nhan thong tin vao dsoco
	int i, j, k;
	int d = 40;
	for (k = 0; k < 4; k++)
	{
		i = (pg->gach[k].y2 - YDAU) / d - 1;
		j = (pg->gach[k].x2 - XDAU) / d - 1;
		if (/*i >= 0 && */ j >= 0 && i < 20 && j < 12)
		{
			if (ds[i][j].trangthai == 1)
				return 0;

		}
		else
			return 0;

	}
	return 1;
}

int Banco::kiemtrathua()
{
	return 0;
}

int Banco::kiemtralaydiem()
{
	int i = 0;
	int j = 0;
	int cot = 12;
	int hang = 20;
	int mdiem = 0;
	int tong = 0;
	for (i = 0; i < hang; i++)
	{
		 tong = 0;
		for (j = 0; j < cot; j++)
		{
			tong = tong + ds[i][j].trangthai;
			
		}
		if (tong == cot)
		{
			mdiem++;
		}
	}
	if (mdiem == 4)
		mdiem = 40;
	diem = diem + mdiem;
	for (i = 0; i < hang; i++)
	{
		tong = 0;
		for (j = 0; j < cot; j++)
		{
			tong = tong + ds[i][j].trangthai;

		}
		if (tong == cot)
		{
			//xoa hang bang cach dich chuyen cac dong tren xuong duoi

			int k = i;
			int m = 0;
			for(k = i; k > 0; k--)
				for (m = 0; m < cot; m++)
				{
					ds[k][m].trangthai = ds[k - 1][m].trangthai;
					ds[k][m].r = ds[k - 1][m].r;
					ds[k][m].g = ds[k - 1][m].g;
					ds[k][m].b = ds[k - 1][m].b;
				}
			k = 0;
			for (m = 0; m < cot; m++)
			{
				ds[k][m].trangthai = 0;
				ds[k][m].r = 255;
				ds[k][m].g = 255;
				ds[k][m].b = 255;
			}
			i--; //tru i cho 1 de kiem tra hang vua moi thay the hang bi xoa
			
		}
	}
	return 0;
}
