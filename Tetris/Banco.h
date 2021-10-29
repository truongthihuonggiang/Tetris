#pragma once
#include "Hcn.h"
#include "Hcnmau.h"
#include "Gachvuong.h"
#include "Gachthang.h"
#include "GachT.h"
#include "GachL.h"
#include "Gach.h"
#include "Oco.h"
#define XDAU 50
#define YDAU 50
#define CAO  800
#define RONG  480
class Banco
{
public:
	int diem, level, tocdo, dk;
	Hcnmau khungve;
	int thua = 0;
	Gach  *pg;
	Oco ds[20][12];
	Banco();
	void vehinh(CClientDC* pdc);
	void capnhathinh(CClientDC* pdc);
	void khoitaogach();
	void capnhatgachroi();
	void batdaugame();
	void bamphimdichuyen(UINT nchar);
	int cothedichchuyen();
	int kiemtrathua();
	int kiemtralaydiem();


};

