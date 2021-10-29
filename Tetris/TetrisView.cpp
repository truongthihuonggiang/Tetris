
// TetrisView.cpp : implementation of the CTetrisView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Tetris.h"
#endif

#include "TetrisDoc.h"
#include "TetrisView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTetrisView

IMPLEMENT_DYNCREATE(CTetrisView, CView)

BEGIN_MESSAGE_MAP(CTetrisView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_KEYDOWN()
END_MESSAGE_MAP()

// CTetrisView construction/destruction

CTetrisView::CTetrisView() noexcept
{
	// TODO: add construction code here
	banco = Banco();

}

CTetrisView::~CTetrisView()
{
}

BOOL CTetrisView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTetrisView drawing

void CTetrisView::OnDraw(CDC* /*pDC*/)
{
	CTetrisDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	CClientDC pdc(this);
	banco.vehinh(&pdc);
}

void CTetrisView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTetrisView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTetrisView diagnostics

#ifdef _DEBUG
void CTetrisView::AssertValid() const
{
	CView::AssertValid();
}

void CTetrisView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTetrisDoc* CTetrisView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTetrisDoc)));
	return (CTetrisDoc*)m_pDocument;
}
#endif //_DEBUG


// CTetrisView message handlers
UINT capnhathinh(LPVOID pParam)
{
	int ran = 0;
	CTetrisView* cview = (CTetrisView*)pParam;
	CClientDC pdc(cview);
	cview->banco.capnhathinh(&pdc);
	return 0;
}
UINT capnhatgachroi(LPVOID pParam)
{
	int ran = 0;
	CTetrisView* cview = (CTetrisView*)pParam;
	cview->banco.capnhatgachroi();
	return 0;
}

void CTetrisView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: Add your message handler code here and/or call default
	if (nChar == 32)// bat dau game
	{
		batdaugame();
	}
	else
		banco.bamphimdichuyen(nChar);
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


int CTetrisView::batdaugame()
{
	// TODO: Add your implementation code here.
	banco.batdaugame();
	AfxBeginThread(capnhatgachroi, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	AfxBeginThread(capnhathinh, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	
	return 0;
}
