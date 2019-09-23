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
string nmespace = string(3,'\t'); //amount of tabs after Name
string clsspace = string(2,'\t'); //amount of tabs after Class
string rcespace = string(3,'\t'); //amount of tabs after Race
string srcspace = string(2,'\t'); //amount of tabs after Subrace

//Name
string nme = "Nik Nok";
//Class
string cls = "Artificer";
//Level
int lvl = 1;
//Subclass
string scl = "Battle Smith";
//Race
string rce = "Tiefling";
//Subrace
string src = "Mephistopheles";
//Background
string bkg = "Clan Crafter";
//Alignment
string aln = "Neutral Good";
//Hit Points
int hp;
//Max HP
int mhp;
//Temp Hit Points
int thp;
//Hit Dice
int hd 	= 8;
//Proficiency Bonus
int pro = 2;
//Strength
int str = 12;
//Dexterity
int dex = 13;
//Constitution
int con = 14;
//Intelligence
int itl = 16;
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
	return 10 + amod(dex);
}
//Armor: Scale Mail
int amr = 14;
//Armor Weight ([L]ight, [M]edium, [H]eavy)
char arw = 'm';
//Armor Class
int arc = acc(amr, arw);
//Spell Slots
int slot1=2;
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
	cout << "[H]eal\t\t\t\t" << "[I]nfusions\t\t\t" << "[Q]uit\n";
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
	cout << "Spear: 1d6 Piercing\n\tThrown 20/60, 1d8 Versatile\n";
	cout << "Handaxe: 1d6 Slashing\n\tThrown 20/60\n";
	cout << "Light Crossbow: 1d8 Piercing\n\tAmmunition, ";
	cout << "Two-Handed, Range 80/320, Loading\n";
	dline();
}

//Armor List
void armor(){
	cout << "Armor: \n\t";
	cout << "Unarmored: Base AC: " << 10 << " + " << amod(dex);
	cout << " = " << 10 + amod(dex) << "\n\t";
	cout << "Scale Mail: Base AC: " << 14 << " + " << min(2, amod(dex));
	cout << " = " << 14 + min(2,amod(dex)) << "\n\t\t";
	cout << "Medium, Stealth Disadvantage" << endl;
	line();
}

//Equipment List
void equip(){
	cout << "Equipment:\n";
	cout << "Theives' Tools, Painter's Supplies" << endl;
	cout << "Dungeoneer's Pack:\n\t";
	cout << "Backpack, Crowbar, Hammer, 10 Pitons, 10 Torches,\n\t";
	cout << "Tinderbox, 10 Days of Rations, Waterskin,\n\t";
	cout << "50 Feet of Hempen Rope" << endl;
	dline();
}

//Skill Prof List
void spro(){
	cout << "Skills: Perception, Arcana, History, Insight";
}

//Proficiency List
void prof(){
	cout << "Proficiencies:\n\t";
	cout << "Armor: Light Armor, Medium Armor, Shields";
	cout << "\n\t";
	cout << "Weapons: Simple Weapons, Hand Crossbows, Heavy Crossbows";
	cout << "\n\t";
	cout << "Tools: Thieves' Tools, Tinker's Tools, Cartographer's Tools,\n\t\t";
	cout << "Painter's Supplies";
	cout << "\n\t";
	cout << "Saving Throws: Constitution, Intelligence";
	cout << "\n\t";
	spro();
	cout << "\n\t";
	cout << "Languages: Common, Infernal, Dwarvish, Draconic" << endl;
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
	spro();
	cout << endl;
	dline();
}

//Cantrip Spells
void cantrips(){
	cout << "Mage Hand:\n\t";
	cout << "Casting Time: 1 Action\t\t\t";
	cout << "Range: 30 Feet\n\t";
	cout << "Duration: 1 Minute\t\t\t";
	cout << "Components: V,S\n\n\t";
	cout << "Can't Attack, Can't Activate Magic Items\n\t";
	cout << "Can't Carry more than 10 Pounds\n";
	line();
	cout << "Magic Stone:\n\t";
	cout << "Casting Time: 1 Bonus Action\t\t";
	cout << "Range: 30 Feet\n\t";
	cout << "Duration: 1 Minute\t\t\t";
	cout << "Components: V,S\n\n\t";
	cout << "Cast on 1-3 Pebbles. Thrown Range is 60 Feet\n\t";
	cout << "Thrown Damage: 1d6 + " << amod(sab) << endl;
	line();
	cout << "Mending:\n\t";
	cout << "Casting Time: 1 Minute\t\t\t";
	cout << "Range: Touch\n\t";
	cout << "Duration: Instantaneous\t\t\t";
	cout << "Components: V,S,M (Two Lodestones)\n\n\t";
	cout << "Repairs a break or tear in an object you touch. Break or tear\n\t";
	cout << "can be no larger than 1 foot in any dimension. Mending leaves no\n\t";
	cout << "trace off former damage. Can physically repair magic item or\n\t";
	cout << "construct, but can't restore magic to such an object.\n";
}

//Level One Spells
void slot_one(){
	cout << "Arcane Weapon:\n\t";
	cout << "Casting Time: 1 Bonus Action\t\t";
	cout << "Range: Self\n\t";
	cout << "Duration: 1 Hour, Concentration\t\t";
	cout << "Components: V,S\n\n\t";
	cout << "Channel Magic into a Simple or Martial Weapon.\n\t";
	cout << "Until Spell ends weapon does 1d6 extra damage of\n\t";
	cout << "type (Acid, Cold, Fire, Lightning, Poison, Thunder)\n\t";
	cout << "Weapon is now magical. Bonus Action change damage type.\n\t";
	cout << "Using 3rd level slot or higher, user can concentrate\n\t";
	cout << "on spell for up to 8 hours." << endl;
	line();
	cout << "Cure Wounds:\n\t";
	cout << "Casting Time: 1 Action\t\t\t";
	cout << "Range: Touch\n\t";
	cout << "Duration: Instantaneous\t\t\t";
	cout << "Components: V,S\n\n\t";
	cout << "Heal Creature 1d8 + " << amod(sab) << "\n\t";
	cout << "When Casting at a higher level does 1d8 extra healing\n\t";
	cout << "for each slot level above level 1\n";
}

//Level Two Spells
void slot_two(){
}

//Level Three Spells
void slot_three(){
}

//Level Four Spells
void slot_four(){
}

//Level Five Spells
void slot_five(){
}

//Level Six Spells
void slot_six(){
}

//Level Seven Spells
void slot_seven(){
}

//Level Eight Spells
void slot_eight(){
}

//Level Nine Spells
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
	line();
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
	cout << "Magical Tinkering:\n\t";
	cout << "Touch tiny nonmagical object as an action and\n\t";
	cout << "give it one of the following magical properties:\n\t\t";
	cout << "-The object sheds bright light in a 5-foot radius\n\t\t";
	cout << "and dim light for an additional 5-feet\n\t\t";
	cout << "-When touched by creature, Object emits message\n\t\t";
	cout << "heard up to 10 feet away.\n\t\t";
	cout << "-The object emits odor or nonverbal sound.\n\t\t";
	cout << "Can be heard from up to 10 feet away.\n\t\t";
	cout << "-Static Visual Effect appears on the surface.\n\t\t";
	cout << "This effect can be a picture, up to 25 words,\n\t\t";
	cout << "lines and shapes, or a mixture of these effects.\n\t";
	cout << "Effect lasts indefinietly. Caster can use an action\n\t";
	cout << "to make the effect end early. The max number of objects\n\t";
	cout << "the caster can effect is equal to their Intelligence Modifier.\n";
	line();
	cout << "Ritual Casting:\n\t";
	cout << "Caster can cast Artificer spells as a ritual if that spell\n\t";
	cout << "has the ritual tag and caster has the spell prepared.\n";
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
	cout << "\t\t\t\tCurrent HP: " << hp << endl;
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

//Arcane Infusions
void infuse(){
	cout << "Arcane Infusions:\nInfuse Items: 2\n";
	cout << "Enhanced Defense:\n\t";
	cout << "Item: Suit of armor or shield\n\t";
	cout << "Creature gains a bonus +1 to Armor Class while\n\t";
	cout << "wearing(armor) or wielding(shield) the inflused item.\n\t";
	cout << "The bonus increases to +2 when you reach\n\t";
	cout << "12th level in this class." << endl;
	line();
	cout << "Enhanced Weapon:\n\t";
	cout << "Item: Simple or Martial Weapon\n\t";
	cout << "This magic weapon grants a +1 bonus to attack\n\t";
	cout << "and damage rolls made with it.";
	cout << "The bonus increases to +2 when you reach\n\t";
	cout << "12th level in this class." << endl;
	line();
	cout << "Returning Weapon:\n\t";
	cout << "Item: Simple or Martial Weapon with the Thrown Property\n\t";
	cout << "This magic weapon grants a +1 bonus to attack and\n\t";
	cout << "damage rolls made with it, and it returns to the\n\t";
	cout << "wielder's hand immediately after it is used to\n\t";
	cout << "make a ranged attack." << endl;
	dline();
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
			armor();
			weapons();
			options();
			ctr(18);
		}
		//Equipment
		else if(let=='e'){
			cs();
			base();
			armor();
			equip();
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
			ctr(5);
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
		//Arcane Infusions
		else if(let=='i'){
			cs();
			base();
			infuse();
			options();
			ctr(10);
		}
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

