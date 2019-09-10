#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
//Ability Score to Ability Mod
int amod(int ascr){return (ascr-10)/2;}
int page = 0;
string input;
char let;
string nmespace = string(4,'\t'); //amount of tabs after Name
string clsspace = string(3,'\t'); //amount of tabs after Class
string rcespace = string(4,'\t'); //amount of tabs after Race
string srcspace = string(3,'\t'); //amount of tabs after Subrace

//Name
string nme = "";
//Class
string cls = "";
//Level
int lvl = 1;
//Subclass
string scl = "";
//Race
string rce = "";
//Subrace
string src = "";
//Background
string bkg = "";
//Alignment
string aln = "";
//Hit Points
int hp;
//Max HP
int mhp;
//Temp Hit Points
int thp;
//Hit Dice
int hd 	= 6;
//Proficiency Bonus
int pro = 2;
//Strength
int str = 10;
//Dexterity
int dex = 10;
//Constitution
int con = 10;
//Intelligence
int itl = 10;
//Wisdom
int wis = 10;
//Charisma
int cha = 10;
//Con ASI Array {4,6,8,10,12,14,16,19}
int flasi[] = 	{0,0,0,0 ,0 ,0 ,0 ,0};
//Armor Class Calculator
int acc(int amr, char arw){
	if (arw >= 'A' && arw <= 'Z'){arw += 32;}
	if (arw == 'l'){return amr + amod(dex);}
	if (arw == 'm'){return amr + min(amod(dex), 2);}
	if (arw == 'h'){return amr;}
}
//Armor
int amr = 10;
//Armor Weight ([L]ight, [M]edium, [H]eavy)
int arw = 'l';
//Armor Class
int arc = acc(amr, arw);
//Spell Slots
int slot1=0;
int slot2=0;
int slot3=0;
int slot4=0;
int slot5=0;
int slot6=0;
int slot7=0;
int slot8=0;
int slot9=0;
//Spellcasting Ability
string sa = "Intelligence";
int sab = itl;
//Spell Save DC
int ssv = 8 + amod(sab) + pro;
//Spell Attack Modifier
int sak = amod(sab) + pro;

void cs()		{cout << string(100,'\n');} 		//Clear Screen
void line()		{cout << string(100,'-') << endl;}	//Single Line
void dline()	{cout << string(100,'=') << endl;}	//Double Line
void ctr(int i)		{cout << string(i,'\n');}			//Raise from Bottom

//Selection Page
void options(){
	cout << "[M]ain\t\t\t\t" << "[W]eapons\t\t\t" << "[E]quipment\n";
	cout << "[P]roficiencies\t\t\t" << "S[k]ills\t\t\t" << "[S]pells\n";
	cout << "[F]eats\t\t\t\t" << "[T]emp HP\t\t\t" << "[D]amage\n";
	cout << "[H]eal\t\t\t\t" << "[C]lear\t\t\t\t" << "[Q]uit\n";
	dline();
}
//Total Constitution Score
int tcn(){
	int tot = con;
	for(int i=0; i<8;i++){
		tot += flasi[i];
	}
	return tot;
}
//Avg Hip Point Calculator
void ahp(){
	hp = hd + amod(con);
	if(lvl > 1){
		for(int i = 1; i < 20;i++){
			if (lvl > i){
				hp += (hd/2 + 1) + amod(con);
				if (i >= 4) {hp += flasi[0];}
				if (i >= 6) {hp += flasi[1];}
				if (i >= 8) {hp += flasi[2];}
				if (i >=10) {hp += flasi[3];}
				if (i >=12) {hp += flasi[4];}
				if (i >=14) {hp += flasi[5];}
				if (i >=16) {hp += flasi[6];}
				if (i >=19) {hp += flasi[7];}
			}
		}
	}
	mhp = hp;
}

//Ability Scores and Modifiers
void ability(){
	cout << "Ability Scores:\n";
	cout << "Str: " << str << " ";
    if(amod(str) >= 0){cout << "+";}
    cout << amod(str) << "\t\t\t";
	cout << "Dex: " << dex << " ";
    if(amod(dex) >= 0){cout << "+";}
    cout << amod(dex) << "\t\t\t";
	cout << "Con: " << con << " ";
    if(amod(con) >= 0){cout << "+";}
    cout << amod(con) << endl;
	cout << "Int: " << itl << " ";
    if(amod(itl) >= 0){cout << "+";}
    cout << amod(itl) << "\t\t\t";
	cout << "Wis: " << wis << " ";
    if(amod(wis) >= 0){cout << "+";}
    cout << amod(wis) << "\t\t\t";
	cout << "Cha: " << cha << " ";
    if(amod(cha) >= 0){cout << "+";}
    cout << amod(cha) << endl;
    line();
}

//Character Stats and Descriptions
void base(){
	dline();
	cout << "Name: " << nme << nmespace;
	cout << "Class: " << cls << " " << lvl << clsspace;
	cout << "Subclass: " << scl << endl;
	cout << "Race: " << rce << rcespace;
	cout << "Subrace: " << src << srcspace;
	cout << "Background: " << bkg << endl;
	cout << "Alignment: " << aln << endl;
	line();
	cout << "Hit Points: " << hp << "(" << thp << ")";
	cout << "\t\tProficiency Bonus: +" << pro;
	cout << "\t\tArmor Class: " << arc << endl;
	line();
	ability();
	cout << "Hit Dice:\n\t\t\t\t1d" << hd;
	cout << " per " << cls << " level";
	cout << endl;
	dline();
}

//Saves List
void saves(){
	cout << "Saving Throws:\n" << "Str: ";
	if(amod(str) >= 0){cout << "+";}
	cout << amod(str) << "\t\t\t\tDex: ";
	if(amod(dex) >= 0){cout << "+";}
	cout << amod(dex) << "\t\t\t\tCon: ";
	if(amod(con) >= 0){cout << "+";}
	cout << amod(con) << "\nInt: ";
	if(amod(itl) >= 0){cout << "+";}
	cout << amod(itl) << "\t\t\t\tWis: ";
	if(amod(wis) >= 0){cout << "+";}
	cout << amod(wis) << "\t\t\t\tCha: ";
	if(amod(cha) >= 0){cout << "+";}
	cout << amod(cha) << endl;
	dline();
}

//Clear Screen with Char Stats
void clear(){
	cs();
	if(hp==0){
		cout << "\t\t\t\tUnconscious" << endl;
	}
	base();
	saves();
	options();
	ctr(22);
}

//Weapon List
void weapons(){
	cout << "Weapons: \n";
	dline();
}

//Armor List
void armor(){
	cout << "Armor: \n";
	dline();
}

//Equipment List
void equip(){
	cout << "Equipment:\n";
	dline();
}

//Skill Prof List
void spro(){
	cout << "Skills: ";
}

//Proficiency List
void prof(){
	cout << "Proficiencies:\n\t";
	cout << "Armor: ";
	cout << "\n\t";
	cout << "Weapons: ";
	cout << "\n\t";
	cout << "Tools: ";
	cout << "\n\t";
	cout << "Saving Throws: ";
	cout << "\n\t";
	spro();
	cout << "\n\t";
	cout << "Languages: " << endl;
	dline();
}

//Skills List
void skills(){
	cout << "Skills:" << endl;
	cout << "Str: ";
	if(amod(str) >= 0){cout << "+";}
	cout << amod(str);
	cout << "\t\t\t\t\t";
	cout << "Int: ";
	if(amod(itl) >= 0){cout << "+";}
	cout << amod(itl) << endl;
	cout << "\tAthletics\t\t\t\tArcana" << endl;
	cout << "Dex: ";
	if(amod(dex) >= 0){cout << "+";}
	cout << amod(dex);
	cout << "\t\t\t\t\t\tHistory" << endl;
	cout << "\tAcrobatics\t\t\t\tInvestigation" << endl;
	cout << "\tSleight of Hand\t\t\t\tNature" << endl;
	cout << "\tStealth\t\t\t\t\tReligion" << endl;
	cout << "Wis: ";
	if(amod(wis) >= 0){cout << "+";}
	cout << amod(wis);
	cout << "\t\t\t\t\t";
	cout << "Cha: ";
	if(amod(cha) >= 0){cout << "+";}
	cout << amod(cha) << endl;
	cout << "\tAnimal Handling\t\t\t\tDeception" << endl;
	cout << "\tInsight\t\t\t\t\tIntimidation" << endl;
	cout << "\tMedicine\t\t\t\tPerformance" << endl;
	cout << "\tPerception\t\t\t\tPersuasion" << endl;
	cout << "\tSurvival\n";
	cout << "Passive Perception: " << 10+amod(wis) << endl;
	line();
	cout << "Proficient ";
	spro;
	cout << endl;
	dline();
}
//Cantrip Spells
void cantrips(){
}
//Level Spells
void slot_one(){
}
//Level Spells
void slot_two(){
}
//Level Spells
void slot_three(){
}
//Level Spells
void slot_four(){
}
//Level Spells
void slot_five(){
}
//Level Spells
void slot_six(){
}
//Level Spells
void slot_seven(){
}
//Level Spells
void slot_eight(){
}
//Level Spells
void slot_nine(){
}

//Spells List
void spells(){
	cout << "Spell Level(0-9):";
	cin >> input;
	int l=input.length();
	for(int i = 0; i < l; i++){
		if(input[i]>='A' && input[i]<='z'){
			cs();
			cout << "\t\t\t\t\t\tEnter a Number" << endl;
			base();
			spells();
			return;
		}
	}
	stringstream vert(input);
	int num = 0;
	vert >> num;
	cout << "Spellcasting Ability: " << sa << endl;
	cout << "Spell Save DC: " << ssv << "\t\t";
	cout << "Spell Attack Modifier: " << sak << endl;
	if (num==0){
		cout << "Cantrips: " << endl;
		cantrips();
	}
	if (num==1){
		cout << "Level 1: " << slot1 << " Slot(s)" << endl;
		slot_one();
	}
	if (num==2){
		cout << "Level 2: " << slot2 << " Slot(s)" << endl;
		slot_two();
	}
	if (num==3){
		cout << "Level 3: " << slot3<< " Slot(s)" << endl;
		slot_three();
	}
	if (num==4){
		cout << "Level 4: " << slot4 << " Slot(s)" << endl;
		slot_four();
	}
	if (num==5){
		cout << "Level 5: " << slot5 << " Slot(s)" << endl;
		slot_five();
	}
	if (num==6){
		cout << "Level 6: " << slot6 << " Slot(s)" << endl;
		slot_six();
	}
	if (num==7){
		cout << "Level 7: " << slot7 << " Slot(s)" << endl;
		slot_seven();
	}
	if (num==8){
		cout << "Level 8: " << slot8 << " Slot(s)" << endl;
		slot_eight();
	}
	if (num==9){
		cout << "Level 9: " << slot9 <<" Slot(s)" << endl;
		slot_nine();
	}
	dline();
}

//Features
void feats(){
	cout << "Features:" << endl;
	dline();
}

//Gain Temp HP
void gtp(){
	cout << "\t\t\t\tTemp HP" << " = ";
	cin >> input;
	int l=input.length();
	for(int i = 0; i < l; i++){
		if(input[i]>='A' && input[i]<='z'){
			cs();
			cout << "\t\t\t\t\t\tEnter a Number" << endl;
			base();
			ctr(21);
			gtp();
			return;
		}
	}
	stringstream vert(input);
	int num = 0;
	vert >> num;
	thp = num;
	return;
}

//Lose HP
void lhp(){
	cout << "\t\t\t\tCurrent HP: " << hp+thp << endl;
	cout << "\t\t\t\tDamage taken: ";
	cin >> input;
	int l = input.length();
	for(int i = 0; i < l; i++){
		if(input[i]>='A' && input[i]<='z'){
			cs();
			cout << "\t\t\t\t\t\tEnter a Number" << endl;
			base();
			ctr(21);
			lhp();
			return;
		}
	}
	stringstream vert(input);
	int num = 0;
	vert >> num;
	if(thp>0 && num>=thp){
		num -= thp;
		thp = 0;
		hp -= num;
	}
	else if(thp>0 && num<thp){
		thp -= num;
	}
	else{
		hp -= num;
	}
	if(hp < 0){hp = 0;}
	return;
}

//Gain HP
void ghp(){
	cout << "\t\t\t\tCurrent HP: " << hp << endl;
	cout << "\t\t\t\tAmount Healed: ";
	cin >> input;
	int l = input.length();
	for(int i = 0; i < l; i++){
		if(input[i]>='A' && input[i]<='z'){
			cs();
			cout << "\t\t\t\t\t\tEnter a Number" << endl;
			base();
			ctr(21);
			ghp();
			return;
		}
	}
	stringstream vert(input);
	int num = 0;
	vert >> num;
	hp += num;
	if(hp > mhp){hp = mhp;}
	return;
}

int main(void){
	ahp();
	clear();
	do{
		cin >> input;
		if(input[0]>='A' && input[0]<='z'){
			let = input[0];
			if(let>='A' && let<='Z'){
				let = let + 32;
			}
			input = " ";
		}
		//Main
		if(let=='m'){clear();}
		//Weapons
		else if(let=='w'){
			cs();
			base();
			weapons();
			armor();
			options();
			ctr(18);
		}
		//Equipment
		else if(let=='e'){
			cs();
			base();
			equip();
			armor();
			options();
			ctr(18);
		}
		//Proficiency
		else if(let=='p'){
			cs();
			base();
			prof();
			options();
			ctr(18);
		}
		//Skills
		else if(let=='k'){
			cs();
			base();
			skills();
			options();
			ctr(15);
		}
		//Spells
		else if(let=='s'){
			cs();
			base();
			spells();
			options();
			ctr(18);
		}
		//Features
		else if(let=='f'){
			cs();
			base();
			feats();
			options();
			ctr(15);
		}
		//Temporary Health Points
		else if(let=='t'){
			gtp();
			clear();
		}
		//Damage Taken
		else if(let=='d'){
			lhp();
			clear();
		}
		//Health Healed
		else if(let=='h'){
			ghp();
			clear();
		}
		//Clear Screen
		else if(let=='c'){clear();}
		//Quit Program
		else if(let=='q'){page = -1;}
		//Input Error Handler
		else{
			page = 0;
			cs();
			cout << "\t\t\t\t";
			cout << "|Enter one of the noted options|\n";
			base();
			saves();
			options();
			ctr(22);
		}
		input = " ";
	} while (page >= 0);
}

