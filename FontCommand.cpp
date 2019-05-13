#include "FontCommand.h"
#include <afxdlgs.h>
#include "CodeEditorForm.h"
#include "FontMatrix.h"

FontCommand::FontCommand(CodeEditorForm* codeEditorForm) :Command(codeEditorForm){
	this->codeEditorForm = codeEditorForm;
}

FontCommand::~FontCommand() {

}

void FontCommand::Execute() {
	CFontDialog fontdlg;
	LOGFONT logfont;
	//CClientDC cdc(this->codeEditorForm);
	HDC hdc;

	hdc = GetDC(this->codeEditorForm->m_hWnd);
	if (fontdlg.DoModal() == IDOK) {

		if (this->codeEditorForm->oldFont != NULL) {
			//cdc.SelectObject(this->codeEditorForm->oldFont);
			SelectObject(hdc, this->codeEditorForm->oldFont->GetSafeHandle());
			this->codeEditorForm->font.DeleteObject();
		}
		ReleaseDC(this->codeEditorForm->m_hWnd, hdc);
		fontdlg.GetCurrentFont(&logfont);
		this->codeEditorForm->font.CreateFontIndirect(&logfont);
	
	}

	this->codeEditorForm->Invalidate();
}
