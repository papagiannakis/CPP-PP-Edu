#pragma once
#include "Ass3.h"

vector<Player*> players;
Simple_window* win;
Graph_lib::Image *BackGround;
Text* AnnouncementText;
In_box *inBox;
Button *Submit;

vector<Image*> playerImages;
vector<Text*> playerText;
vector<Text*> playerVotes;

bool isDay;
bool GangsterPlaying;
int DoctorSelection;
bool votingStarted;
int GangSterSelection;
int KilledPlayer=-1;
int currentVoter;
bool votingEnded;

int main()
{
	isDay= false;
	GangsterPlaying = true;

	BackGround = new Graph_lib::Image(Point(0,0),"images/Night.jpg");
	win = new Simple_window(Point(100,100),600,400,"Town of Salem");
	
	inBox = new In_box(Point(400,370),100,30,"Input");
	win->attach(*inBox);
	
	Submit = new Button(Point(500,370),50,30,"Submit",SubmitCallback);
	win->attach(*Submit);
	win->attach(*BackGround);


	/*Load players from file and print them*/
	Init("Players.txt");
	ShowPlayers();
	AnnouncementText = new Text(Point(150,20), "It is night and the gangster selects which player will leave");
    AnnouncementText->set_font(Graph_lib::Font::times_bold);
	AnnouncementText->set_color(Color::white);
    AnnouncementText->set_font_size(20);
	
	win->attach(*AnnouncementText);
	
	
	win->wait_for_button();

}

void SubmitCallback(Address, Address pw){
		
	int input = inBox->get_int();
	
	if(!isDay){
		if(GangsterPlaying){
			GangSterSelection =input;
			GangsterPlaying = false;
			AnnouncementText->set_label("Gangster selected player " + to_string(input) );
			win->redraw();
		}else{
			DoctorSelection = input;
			AnnouncementText->set_label("Doctor selected player " + to_string(input) );
			win->redraw();
			isDay = true;
		}
	}

	if(isDay){
		
		if(!votingStarted){
			ChangeBackground();
			if(GangSterSelection == DoctorSelection){
				AnnouncementText->set_label("The day has started! Doctor saved player " + to_string(GangSterSelection) );
				win->redraw();
			}else{
				KilledPlayer = GangSterSelection;
				string Label = "The day has started! Gangster killed player " + to_string(GangSterSelection);
				
				AnnouncementText->set_label(Label);
				win->redraw();
				
			}
			startVoting();
		}else if(!votingEnded){
			if (currentVoter==KilledPlayer) {
				currentVoter++;
				return;
			}
			if(input == KilledPlayer){
				return;
			}

			

			int vote = input;
			AnnouncementText->set_label("Player " + to_string(currentVoter) + " voted Player " + to_string(input));
			int votes =stoi(playerVotes[input]->label());
			
			playerVotes[input]->set_label(to_string(votes+1));
			currentVoter++;
			win->redraw();


			if(currentVoter==players.size()){
				votingEnded = true;
			}
		}

		if(votingEnded){
			int i = FindPlayerWithMaxVotes();
			win->detach(*playerImages[i]);
			win->detach(*playerText[i]);
			for(int i=0;i<playerVotes.size();i++){
				win->detach(*playerVotes[i]);
			}
			win->detach(*inBox);
			win->detach(*Submit);
			win->redraw();
		}
	}


}

int FindPlayerWithMaxVotes(){
	int max = -1;
	int maxi = 0;
	for(int i=0;i<playerVotes.size();i++){
		int votes = stoi(playerVotes[i]->label());
		if(max< votes) {
			max=votes;
			maxi = i;
		}
	}
	return maxi;
}

void ChangeBackground(){
	win->detach(*BackGround);
	BackGround = new Graph_lib::Image(Point(0,0),"images/Day.jpg");
	win->attach(*BackGround);

	for(int i=0;i<players.size();i++){
		
		if(i==GangSterSelection && i!=DoctorSelection) {
			continue;
		}
		win->detach(*playerImages[i]);
		win->attach(*playerImages[i]);
		

		win->detach(*playerText[i]);
		win->attach(*playerText[i]);
	
	}
	
	win->detach(*AnnouncementText);
	win->attach(*AnnouncementText);
	AnnouncementText->set_color(Color::black);
}
void startVoting(){
	
	votingStarted = true;
	
	for(int i=0;i<playerText.size();i++){
		Text* txt;
		if(i==KilledPlayer){
			txt = new Text(Point(900,900), "-1");
			txt->set_font(Graph_lib::Font::times_bold);
			txt->set_color(Color::black);
			txt->set_font_size(1);

		}else{
			txt = new Text(Point(playerText[i]->point(0).x+40,playerText[i]->point(0).y), "0");
			txt->set_font(Graph_lib::Font::times_bold);
			txt->set_color(Color::black);
			txt->set_font_size(20);
		}

		playerVotes.push_back(txt);
		win->attach(*txt);
	}
}

void ShowPlayers(){

	
	int xx = 140;
	int yy = 100;

	int x_offset = 50;
	int y_offset = 50;
	
	for(int i=0;i<players.size();i++){
		if(yy>200){
			y_offset = -y_offset;
		}

		if(xx>=350){
			x_offset = -x_offset;
		}

		if(yy<=60){
			y_offset = -y_offset;
		}
		yy+=y_offset;
		xx+=x_offset;
		
		Image* im;
		if(players[i]->GetRole()=="Civilian")
			im = new Image(Point(xx,yy),"images/Civilian.jpg");
		else if(players[i]->GetRole()=="Gangster")
			im = new Image(Point(xx,yy),"images/Gangster.jpg");
		else
			im = new Image(Point(xx,yy),"images/Doctor.jpg");
		
		playerImages.push_back(im);

		Text* txt = new Text(Point(xx,yy+15), to_string(i));
		txt->set_font(Graph_lib::Font::times_bold);
		txt->set_color(Color::black);
    	txt->set_font_size(20);
		
		playerText.push_back(txt);

		win->attach(*im);
		win->attach(*txt);
	}
}

void Init(string FileName) {
	ifstream playersFile(FileName);
	string username, role;
	
	/*Read file till you reach the end.*/
	while (!playersFile.eof()) {
		
		/*Get username and role*/
		playersFile >> username;
		playersFile >> role;

		/*Create a new player and add it to global vector*/
		Player* p = new Player(username, true, role);
		players.push_back(p);
	}

}
