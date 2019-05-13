#include "RegionController.h"

RegionController::RegionController()
{
}

RegionController::RegionController(Long firstX, Long firstY, Long secondX, Long secondY, string contents)
{
	CBrush brush;
	brush.CreateSolidBrush(RGB(37, 111, 253));

	this->contents = contents;
	this->firstX = firstX;
	this->firstY = firstY;
	this->secondX = secondX;
	this->secondY = secondY;
	this->contents = contents;

	this->backgroundColor = RGB(37, 111, 253);
	this->letterColor = RGB(255, 255, 255);
	this->brush = (HBRUSH)brush.GetSafeHandle();
}

RegionController::~RegionController()
{
}

HRGN RegionController::MakeRegion()
{
	HRGN hrgn;
	bool succed;

	succed = this->selectedRgn.CreateRectRgn(this->firstX, this->firstY, this->secondX, this->secondY);

	if (succed == TRUE){
		hrgn = (HRGN)this->selectedRgn.GetSafeHandle();
		this->isBeing = TRUE;
	}

	return hrgn;
}

void RegionController::DrawRegion(HDC hdc)
{
//#if 0
	CString cString;

	FillRgn(hdc, selectedRgn, brush);
	SetTextColor(hdc, letterColor);
	SetBkColor(hdc, backgroundColor);

	cString = CString(contents.c_str());
	TextOut(hdc, firstX, firstY, cString, contents.length());

	PaintRgn(hdc, selectedRgn);
//#endif
}
