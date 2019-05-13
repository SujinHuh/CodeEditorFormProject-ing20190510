#pragma once
/*
���ϸ�: Region
�ۼ��� : 2019��05��09��
�ۼ��� : �����
���: ������ �����.
���� :
*/
//Region.h
#ifndef _REGIONCONTROLLER_H
#define _REGIONCONTROLLER_H
#include <afxwin.h>
#include <string>
using namespace std;

typedef signed long int Long;
class CodeEditorForm;
class Glyph;
class RegionController {
public:
	RegionController();
	RegionController(Long firstX, Long firstY, Long secondX, Long secondY, string contents);
	~RegionController();
	HRGN MakeRegion();
	void DrawRegion(HDC hdc);
	bool GetIsBeing() const;
	//CRgn GetSelectedRgn() const;

public:
	Long firstX;
	Long secondX;
	Long firstY;
	Long secondY;
	CRgn selectedRgn;
	COLORREF backgroundColor;
	COLORREF letterColor;
	HBRUSH brush;
	string contents;
	bool isBeing = FALSE;
};

inline bool RegionController::GetIsBeing() const {
	
	return this->isBeing;
}



#endif //_REGIONCONTROLLER_H