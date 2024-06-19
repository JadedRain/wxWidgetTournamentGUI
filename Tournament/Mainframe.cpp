#include "Mainframe.h"
#include <wx/wx.h>

Mainframe::Mainframe(const wxString& title, int width, int height) : wxFrame(nullptr, wxID_ANY, title) {
	this->width = width;
	this->height = height;
	srand((unsigned)time(nullptr));

	roles.Add("Top");
	roles.Add("Jungle");
	roles.Add("Mid");
	roles.Add("ADC");
	roles.Add("Support");

	CreateControls();
	BindControls();

	CreateStatusBar();

}

void Mainframe::CreateControls() {
	main_panel = new wxPanel(this, wxID_ANY);
	main_panel->SetBackgroundColour(main_background_color);

	CreateHeader();
	CreatePanels();
}

void Mainframe::CreateHeader() {
	heading_panel = new wxPanel(main_panel, wxID_ANY, wxPoint(5, 5), wxSize(this->width, 25));
	title = new wxStaticText(heading_panel, wxID_ANY, "Tournament Runner", wxPoint(0, 0), wxSize(200, 30), wxALIGN_CENTER_HORIZONTAL);
	player_heading = new wxStaticText(heading_panel, wxID_ANY, "Players", wxPoint(225, 2), wxSize(100, 20), wxALIGN_CENTER_HORIZONTAL);
	team_heading = new wxStaticText(heading_panel, wxID_ANY, "Teams", wxPoint(350, 2), wxSize(100, 20), wxALIGN_CENTER_HORIZONTAL);
	tournament_heading = new wxStaticText(heading_panel, wxID_ANY, "Tournament", wxPoint(475, 2), wxSize(100, 20), wxALIGN_CENTER_HORIZONTAL);
	StyleHeader();
}
void Mainframe::CreatePanels() {
	player_panel = new wxPanel(main_panel, wxID_ANY, wxPoint(0, 40), wxSize(this->width, this->height - 50));
	CreatePlayerPanelControls();
	team_panel = new wxPanel(main_panel, wxID_ANY, wxPoint(0, 40), wxSize(this->width, this->height - 50));
	CreateTeamPanelControls();
	tournament_panel = new wxPanel(main_panel, wxID_ANY, wxPoint(0, 40), wxSize(this->width, this->height - 50));
	CreateTournamentPanelControls();

	StylePanels();
}
void Mainframe::CreatePlayerPanelControls() {
	player_name_text = new wxStaticText(player_panel, wxID_ANY, "Player Name:", wxPoint(5, 10));
	player_name_control = new wxTextCtrl(player_panel, wxID_ANY, "", wxPoint(5, 32), wxSize(100, 25), wxTE_PROCESS_ENTER);
	player_role_text = new wxStaticText(player_panel, wxID_ANY, "Player Role:", wxPoint(5, 75));
	player_roles = new wxChoice(player_panel, wxID_ANY, wxPoint(5, 100), wxDefaultSize, roles);
	player_power_text = new wxStaticText(player_panel, wxID_ANY, "Player Power:", wxPoint(5, 150));
	player_power = new wxSpinCtrl(player_panel, wxID_ANY, "", wxPoint(7, 170), wxSize(75, 25), 16384L, 0, 100);
	player_power_subtext = new wxStaticText(player_panel, wxID_ANY, "(Power will be set randomly if left at 0)", wxPoint(90, 175));
	add_player_button = new wxButton(player_panel, wxID_ANY, "Add Player", wxPoint(5, 220), wxSize(100, 25));

	for (int i = 0; i < roles.size(); i++) {
		wxStaticText* role = new wxStaticText(player_panel, wxID_ANY, roles[i], wxPoint(50 + (150 * i), 300));
		role->SetForegroundColour(main_text_color);
		wxListBox* role_players = new wxListBox(player_panel, wxID_ANY, wxPoint(50 + (150 * i), 325), wxSize(-1, 200));
		role_players->SetBackgroundColour(textctrl_background_color);
		role_players->SetForegroundColour(main_text_color);
		role_players->SetName(wxString::Format("%s-playerpanel", roles[i]));
	}

	StylePlayerControls();

}
void Mainframe::CreateTeamPanelControls() {
	team_name = new wxStaticText(team_panel, wxID_ANY, "Team Name:", wxPoint(350, 10), wxDefaultSize, wxTEXT_ALIGNMENT_CENTER);
	team_name_entry = new wxTextCtrl(team_panel, wxID_ANY, "", wxPoint(350, 32), wxSize(100, 25), wxTE_PROCESS_ENTER);
	
	for (int i = 0; i < roles.size(); i++) {
		wxStaticText* role = new wxStaticText(team_panel, wxID_ANY, roles[i], wxPoint(50 + (150 * i), 100));
		role->SetForegroundColour(main_text_color);
		wxListBox* role_players = new wxListBox(team_panel, wxID_ANY, wxPoint(50 + (150 * i), 125), wxSize(-1, 200));
		role_players->SetBackgroundColour(textctrl_background_color);
		role_players->SetForegroundColour(main_text_color);
		role_players->SetName(wxString::Format("%s-teampanel", roles[i]));
	}

	team_add_button = new wxButton(team_panel, wxID_ANY, "Add Team", wxPoint(50, 350));
	team_list = new wxListBox(team_panel, wxID_ANY, wxPoint(350, 350), wxSize(255, 100));

	StyleTeamControls();
}
void Mainframe::CreateTournamentPanelControls() {
	team_list_text = new wxStaticText(tournament_panel, wxID_ANY, "Team List", wxPoint(20, 1));
	tournament_team_list = new wxListBox(tournament_panel, wxID_ANY, wxPoint(5, 25), wxSize(100, 300));
	create_bracket_button = new wxButton(tournament_panel, wxID_ANY, "Create Bracket", wxPoint(5, 350));
	run_round_button = new wxButton(tournament_panel, wxID_ANY, "Play Round", wxPoint(500, 350));
}

void Mainframe::StyleHeader() {
	heading_panel->SetBackgroundColour(menu_background_color);
	main_font = wxFont(wxFontInfo(wxSize(0, 17)));
	main_panel->SetFont(main_font);
	header_font = wxFont(wxFontInfo(wxSize(0, 16)));
	player_heading->SetFont(header_font);
	team_heading->SetFont(header_font);
	tournament_heading->SetFont(header_font);
	title_font = wxFont(wxFontInfo(wxSize(0, 20)).Bold());
	title->SetFont(title_font);
	title->SetForegroundColour(title_color);
	player_heading->SetForegroundColour(menu_text_color);
	team_heading->SetForegroundColour(menu_text_color);
	tournament_heading->SetForegroundColour(menu_text_color);
}
void Mainframe::StylePanels() {
	player_panel->SetLabel(wxString::Format("%d", player_heading->GetId()));
	player_panel->SetBackgroundColour(main_background_color);
	player_panel->Hide();
	team_panel->SetLabel(wxString::Format("%d", team_heading->GetId()));
	team_panel->SetBackgroundColour(main_background_color);
	team_panel->Hide();
	tournament_panel->SetLabel(wxString::Format("%d", tournament_heading->GetId()));
	tournament_panel->SetBackgroundColour(main_background_color);
	tournament_panel->Hide();
}
void Mainframe::StylePlayerControls() {
	player_name_text->SetForegroundColour(main_text_color);
	player_name_control->SetBackgroundColour(textctrl_background_color);
	player_name_control->SetForegroundColour(main_text_color);
	player_role_text->SetForegroundColour(main_text_color);
	player_roles->SetBackgroundColour(textctrl_background_color);
	player_roles->SetForegroundColour(main_text_color);
	player_power_text->SetForegroundColour(main_text_color);
	player_power->SetBackgroundColour(textctrl_background_color);
	player_power->SetForegroundColour(main_text_color);
	player_power_subtext->SetForegroundColour(main_text_color);
	player_power_subtext->SetFont(wxFont(wxFontInfo(wxSize(0, 13))));
}
void Mainframe::StyleTeamControls() {
	team_name->SetForegroundColour(main_text_color);
	team_name_entry->SetBackgroundColour(textctrl_background_color);
	team_name_entry->SetForegroundColour(main_text_color);
	team_list->SetBackgroundColour(textctrl_background_color);
	team_list->SetForegroundColour(main_text_color);
}
void Mainframe::BindControls() {
	BindHeaderControls();
	BindPlayerControls();
	BindTeamControls();
	BindTournamentControls();

}
void Mainframe::BindHeaderControls() {
	for (int i = 1; i < heading_panel->GetChildren().size(); i++) {
		heading_panel->GetChildren()[i]->Bind(wxEVT_ENTER_WINDOW, &Mainframe::OnMouseOver, this);
		heading_panel->GetChildren()[i]->Bind(wxEVT_LEAVE_WINDOW, &Mainframe::OnMouseLeave, this);

		heading_panel->GetChildren()[i]->Bind(wxEVT_LEFT_DOWN, &Mainframe::OnHeadingClick, this);
	}
}
void Mainframe::BindPlayerControls() {
	add_player_button->Bind(wxEVT_BUTTON, &Mainframe::OnAddPlayer, this);
	player_name_control->Bind(wxEVT_TEXT_ENTER, &Mainframe::OnAddPlayer, this);
}
void Mainframe::BindTeamControls() {
	team_add_button->Bind(wxEVT_BUTTON, &Mainframe::OnAddTeam, this);
	team_name_entry->Bind(wxEVT_TEXT_ENTER, &Mainframe::OnAddTeam, this);
}
void Mainframe::BindTournamentControls() {

	create_bracket_button->Bind(wxEVT_BUTTON, &Mainframe::OnCreateBracket, this);
}

void Mainframe::OnHeadingClick(wxMouseEvent& evt) {
	if (FindWindowByLabel(wxString::Format("%d", evt.GetId()))) {
		ToggleShown(FindWindowByLabel(wxString::Format("%d", evt.GetId())));
	}
}
void Mainframe::OnMouseOver(wxMouseEvent& evt) {
	wxWindow* object = FindWindowById(evt.GetId());
	object->SetBackgroundColour(menu_hover_color);
	object->Refresh();
	SetCursor(wxCURSOR_HAND);
}
void Mainframe::OnMouseLeave(wxMouseEvent& evt) {
	wxWindow* object = FindWindowById(evt.GetId());
	object->SetBackgroundColour(menu_background_color);
	object->Refresh();
	SetCursor(wxCURSOR_DEFAULT);

}
void Mainframe::OnAddPlayer(wxCommandEvent& evt) {
	wxString player_name = player_name_control->GetValue();
	wxString choosen_role = player_roles->GetStringSelection();
	int choosen_power = player_power->GetValue();

	if (player_name == "") {
		player_name = "Unnamed";
	}
	if (choosen_role == "") {
		player_roles->SetSelection(rand() % player_roles->GetCount());
		choosen_role = player_roles->GetStringSelection();
		player_roles->SetSelection(-1);
	}
	if (choosen_power == 0) {
		choosen_power = rand() % 100 + 1;
	}
	wxListBox* player_role_box = (wxListBox*)FindWindowByName(wxString::Format("%s-playerpanel", choosen_role));
	player_role_box->Insert(player_name, player_role_box->GetCount());
	wxListBox* team_role_box = (wxListBox*)FindWindowByName(wxString::Format("%s-teampanel", choosen_role));
	team_role_box->Insert(player_name, team_role_box->GetCount());
	
	players[choosen_role].push_back(Player((std::string)player_name, (std::string)choosen_role, choosen_power));
}
void Mainframe::OnAddTeam(wxCommandEvent& evt) {
	wxString team_name = team_name_entry->GetValue();
	if (team_name == "") {
		team_name = "Unammed";
	}

	if (team_list->GetCount() < max_teams) {
		team_list->Insert(team_name, team_list->GetCount());
		tournament_team_list->Insert(team_name, tournament_team_list->GetCount());
		teams.push_back(AddPlayersToTeam(team_name));
	}
}
void Mainframe::OnCreateBracket(wxCommandEvent& evt) {
	tournament = Tournament_Runner(teams);
	tournament.create_bracket();
	vector<array<Team, 2>> bracket = tournament.get_bracket();
	for (int i = 0; i < bracket.size(); i++) {
		wxStaticText* series = new wxStaticText(tournament_panel, wxID_ANY,
			wxString::Format("%s vs. %s", bracket[i][0].get_name(), bracket[i][1].get_name()),
			wxPoint(200, 10 + i * 50));
	}

}
void Mainframe::OnRunRound(wxCommandEvent& evt) {

}

void Mainframe::ToggleShown(wxWindow* window) {
	if (window->IsShown()) {
		window->Hide();
		is_panel_shown = false;
	}
	else if (!window->IsShown() and is_panel_shown) {
		shown_panel->Hide();
		window->Show();
		shown_panel = window;
	}
	else {
		window->Show();
		shown_panel = window;
		is_panel_shown = true;
	}
}
Team Mainframe::AddPlayersToTeam(wxString team_name) {
	Team team = Team((std::string)team_name);
	for (int i = 0; i < roles.GetCount(); i++) {
		wxListBox* role_players = (wxListBox*)FindWindowByName(wxString::Format("%s-teampanel", roles[i]));
		if (role_players->GetSelection() != wxNOT_FOUND) {
			Player player = players[roles[i]][role_players->GetSelection()];
			team.set_member((std::string)roles[i], player);
		}
	}
	return team;

}