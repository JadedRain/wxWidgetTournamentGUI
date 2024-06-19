#pragma once
#include <wx/wx.h>
#include <wx/spinctrl.h>
#include <vector>
#include <map>
#include "Player.h"
#include "Team.h"
#include "Tournament_Runner.h"

class Mainframe : public wxFrame {
private:
	int width;
	int height;
	int max_teams = 8;
	bool is_panel_shown = false;
	wxWindow* shown_panel;
	wxArrayString roles;
	Tournament_Runner tournament;

	map<wxString, vector<Player>> players;
	vector<Team> teams;

	// Program colors
	wxColor main_background_color = wxColor(50, 50, 50);
	wxColor main_text_color = wxColor(175, 175, 175);
	wxColor textctrl_background_color = wxColor(70, 70, 70);
	wxColor menu_background_color = wxColor(60, 60, 60);
	wxColor menu_hover_color = wxColor(80, 80, 80);
	wxColor title_color = wxColor(200, 200, 200);
	wxColor menu_text_color = wxColor(180, 180, 180);

	// Program fonts
	wxFont title_font;
	wxFont header_font;
	wxFont main_font;

	// Heading controls
	wxStaticText* title;
	wxStaticText* player_heading;
	wxStaticText* team_heading;
	wxStaticText* tournament_heading;

	// Player controls
	wxStaticText* player_name_text;
	wxTextCtrl* player_name_control;
	wxStaticText* player_role_text;
	wxChoice* player_roles;
	wxStaticText* player_power_text;
	wxSpinCtrl* player_power;
	wxStaticText* player_power_subtext;
	wxButton* add_player_button;

	// Team controls
	wxStaticText* team_name;
	wxTextCtrl* team_name_entry;
	wxButton* team_add_button;
	wxListBox* team_list;

	// Tournament controls
	wxStaticText* team_list_text;
	wxListBox* tournament_team_list;
	wxButton* create_bracket_button;
	wxButton* run_round_button;

	// Program panels
	wxPanel* main_panel;
	wxPanel* heading_panel;
	wxPanel* player_panel;
	wxPanel* team_panel;
	wxPanel* tournament_panel;


public:
	Mainframe(const wxString& title, int width, int height);

private:
	// Setup
	void CreateControls();
	void CreateHeader();
	void CreatePanels();
	void CreatePlayerPanelControls();
	void CreateTeamPanelControls();
	void CreateTournamentPanelControls();

	// Bind Events
	void BindControls();
	void BindHeaderControls();
	void BindPlayerControls();
	void BindTeamControls();

	// Style
	void StyleHeader();
	void StylePanels();
	void StylePlayerControls();
	void StyleTeamControls();
	void StyleTournamentControls();

	// Events
	void OnHeadingClick(wxMouseEvent& evt);
	void OnMouseOver(wxMouseEvent& evt);
	void OnMouseLeave(wxMouseEvent& evt);
	void OnAddPlayer(wxCommandEvent& evt);
	void OnAddTeam(wxCommandEvent& evt);
	void OnCreateBracket(wxCommandEvent& evt);
	void OnRunRound(wxCommandEvent& evt);

	// Helper functions
	void ToggleShown(wxWindow* window);
	Team AddPlayersToTeam(wxString team_name);
};

