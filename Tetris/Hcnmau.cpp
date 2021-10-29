#include "pch.h"
#include "Hcnmau.h"

void Hcnmau::vehinh(CClientDC* pdc)
{
	CBrush* nb = new CBrush(RGB(r, g, b));
	CBrush* ob;
	ob = pdc->SelectObject(nb);
	Hcn::vehinh(pdc);
	pdc->SelectObject(ob);
	delete nb;
}
