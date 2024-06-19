#include "App.h"
#include <wx/wx.h>
#include "Mainframe.h"

wxIMPLEMENT_APP(App);

bool App::OnInit() {
	int width = 800;
	int height = 600;
	Mainframe* main_frame = new Mainframe("Tournament", width, height);
	main_frame->SetClientSize(width, height);
	main_frame->Center();
	main_frame->Show();
	return true;
}
