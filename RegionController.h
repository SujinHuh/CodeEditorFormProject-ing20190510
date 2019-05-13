#pragma once
/*
파일명: Region
작성일 : 2019년05월09일
작성자 : 허수진
기능: 리전을 만든다.
수정 :
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