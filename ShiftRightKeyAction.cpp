
/*
���ϸ� : ShiftRightKeyAction.cpp
�ۼ����� : 2019�� 05�� 02��
�ۼ��� : �迵��
��� : ����Ʈ ������ ����Ű ���ÿ��� ����
���� :
*/

#include "ShiftRightKeyAction.h"
#include "CodeEditorForm.h"
#include "Glyph.h"
#include "FontMatrix.h"
#include "CaretCoordinator.h"
#include "RegionController.h"

ShiftRightKeyAction::ShiftRightKeyAction(CodeEditorForm *codeEditorForm) :KeyAction(codeEditorForm) {
	
}

ShiftRightKeyAction:: ~ShiftRightKeyAction() {

}

void ShiftRightKeyAction::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
	Long firstX, secondX;
	Long firstY, secondY;
	Long previousLineCurrent, nextLineCurrent;
	Long previousMemoCurrent, nextMemoCurrent;
	Long fontHeight;
	string contents = "";
	CaretCoordinator coordinator;
	Long firstCurrent, lastCurrent;
	Glyph *letter;


	firstCurrent = this->codeEditorForm->current->GetCurrent();
	firstX = coordinator.GetXPos(this->codeEditorForm->fontMatrix, this->codeEditorForm->current);
	firstY = coordinator.GetYPos(this->codeEditorForm->fontMatrix, this->codeEditorForm->memo->GetCurrent());
	
	previousLineCurrent = this->codeEditorForm->current->GetCurrent();
	nextLineCurrent = this->codeEditorForm->current->Next();
	
	if (previousLineCurrent == nextLineCurrent) {
		previousMemoCurrent = this->codeEditorForm->memo->GetCurrent();
		nextMemoCurrent = this->codeEditorForm->memo->Next();
		if (previousMemoCurrent != nextMemoCurrent) {
			this->codeEditorForm->current = this->codeEditorForm->memo->GetAt(this->codeEditorForm->current->GetCurrent());
			this->codeEditorForm->current->First();
		}
	}

	lastCurrent = this->codeEditorForm->current->GetCurrent();
	secondX = coordinator.GetXPos(this->codeEditorForm->fontMatrix, this->codeEditorForm->current);
	secondY = coordinator.GetYPos(this->codeEditorForm->fontMatrix, this->codeEditorForm->memo->GetCurrent());
	fontHeight = this->codeEditorForm->fontMatrix->GetHeight();
	secondY = secondY + fontHeight;

	while (firstCurrent < lastCurrent) {
		letter = this->codeEditorForm->current->GetAt(firstCurrent);
		contents += letter->GetContents();
		firstCurrent++;
	}

	RegionController *regionController = new RegionController(firstX, firstY, secondX, secondY + fontHeight, contents);

	this->codeEditorForm->regionController = regionController;

	this->codeEditorForm->regionController->MakeRegion();

	this->codeEditorForm->Invalidate();
}