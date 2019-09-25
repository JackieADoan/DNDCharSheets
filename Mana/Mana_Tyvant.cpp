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
bool calc = false; //True (average HP)/ False (Manual HP)
string nmespace = string(2,'\t'); //amount of tabs after Name
string clsspace = string(3,'\t'); //amount of tabs after Class
string rcespace = string(3,'\t'); //amount of tabs after Race
string srcspace = string(2,'\t'); //amount of tabs after Subrace

//Name
string nme = "Mana Tyvant";
//Class
string cls = "Cleric";
//Level
int lvl = 2;
//Subclass
string scl = "Forge Domain";
//Race
string rce = "Aasimar";
//Subrace
string src = "Protector";
//Background
string bkg = "Acolyte";
//Alignment
string aln = "Lawful Neutral";
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
int str = 14;
//Dexterity
int dex = 12;
//Constitution
int con = 14;
//Intelligence
int itl = 12;
//Wisdom
int wis = 17;
//Charisma
int cha = 13;
//Manual HP Array
int hpa[] = {hd,6,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
//Con ASI Array {4,6,8,10,12,14,16,19}
int flasi[] = 	{0,0,0,0 ,0 ,0 ,0 ,0};
//Armor Class Calculator
int acc(int amr, char arw, bool shield){
	if (arw >= 'A' && arw <= 'Z'){arw += 32;}
	if (arw == 'l' && shield){return amr + 2 + amod(dex);}
	else if (arw == 'l'){return amr + amod(dex);}
	if (arw == 'm' && shield){return amr + 2 + min(amod(dex), 2);}
	else if (arw == 'm'){return amr + min(amod(dex), 2);}
	if (arw == 'h' && shield){return amr + 2;}
	else if (arw == 'h'){return amr;}
	return 10 + amod(dex);
}
//Armor
int amr = 16;
//Armor Weight ([L]ight, [M]edium, [H]eavy)
int arw = 'h';
//Equiped Shield
bool shield = true;
//Armor Class
int arc = acc(amr, arw, shield);
//Spell Slots
int slot1=4;
int slot2=2;
int slot3=0;
int slot4=0;
int slot5=0;
int slot6=0;
int slot7=0;
int slot8=0;
int slot9=0;
//Spellcasting Ability
string sa = "Wisdom";
int sab = wis;
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
	cout << "[H]eal\t\t\t\t" << "[C]hannel\t\t\t" << "[Q]uit\n";
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
//Manual Hit Point Calculator
void mhc(){
	hp = hd + amod(con);
	if(lvl > 1){
		for(int i = 1; i < 20;i++){
			if (lvl > i){
				hp += hpa[i] + amod(con);
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
//Avg Hit Point Calculator
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
	cout << "Money: 625 GP" << endl;
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
	cout << "Weapons: \n\t";
	cout << "Mace+1: 1d6 + " << 1+amod(str) << " Bludgeoning\n\t\t";
	cout << "+ " << 1+pro+amod(str) << " to attack\n\t\t";
	cout << "has this if used feat on mace\n\t";
	cout << "Light Crossbow: 1d8 + " << amod(dex) << " Piercing\n\t\t";
	cout << "+ " << pro+amod(dex) << " to attack\n\t\t";
	cout << "80/320 Range, Two-Handed\n\t";
	cout << "Mace: 1d6 + " << amod(str) << " Bludgeoning\n\t\t";
	cout << "+ " << pro+amod(str) << " to attack\n";
	dline();
}

//Armor List
void armor(){
	cout << "Damage Resistance: Necrotic, Radiant\n";
	cout << "Armor: \n\t";
	cout << "Shield: +2 to AC\n\t";
	cout << "Shield+1: +3 to AC\n\t\t";
	cout << "Has this if Feature is used on shield\n\t";
	cout << "Unarmored: " << 10 + amod(dex) << " AC\n\t";
	cout << "Chainmail: 16 AC\n\t\t";
	cout << "Heavy, Stealth Disadvantage\n\t";
	cout << "Chainmail+1: 17 AC\n\t\t";
	cout << "Heavy, Stealth Disadvantage\n\t\t";
	cout << "Has this if Feature is used on Chainmail\n";
	dline();
}

//Equipment List
void equip(){
	cout << "Equipment:\n\t";
	cout << "Pouch, Common Clothes, 20 Crossbow Bolts, Waterskin, Candle,\n\t";
	cout << "Alms Box, Incense, 4 days of Rations, Censer, Amulet, Vestements,\n\t";
	cout << "Prayer Book, Tinderbox, Blanket, Backpack, Emblem, Barkybutt\n";
	dline();
}

//Skill Prof List
void spro(){
	cout << "Skills: History, Insight, Persuasion, Religion";
}

//Proficiency List
void prof(){
	cout << "Proficiencies:\n\t";
	cout << "Armor: Light, Medium, Heavy, Shields";
	cout << "\n\t";
	cout << "Weapons: Simple";
	cout << "\n\t";
	cout << "Tools: N/A";
	cout << "\n\t";
	cout << "Saving Throws: Wisdom, Charisma";
	cout << "\n\t";
	spro();
	cout << "\n\t";
	cout << "Languages: Common, Celestial, Elvish, Infernal" << endl;
	cout << "Damage Resistance: Necrotic, Radiant\n";
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
	cout << "Light:\n\t";
	cout << "Casting Time: 1 Action\t\t\t";
	cout << "Range: Touch\n\t";
	cout << "Duration: 1 Hour\t\t\t";
	cout << "Components: V,M(Firefly/Light Moss)\n\n\t";
	cout << "You touch one object that is no larger than 10 feet in any\n\t";
	cout << "dimension. Until the spell ends, the objects sheds bright light\n\t";
	cout << "in a 20-foot radius and dim light for an additional 20 feet. The\n\t";
	cout << "light can be colored as you like. Completely covering the object with\n\t";
	cout << "something opaque blocks the light. The spell ends if you cast it again\n\t";
	cout << "or dismiss it as an action\n\t";
	cout << "If you target an object held or worn creature must succed on a Dexterity\n\t";
	cout << "saving throw to avoid the spell.\n";
	line();
	cout << "Spare the Dying:\n\t";
	cout << "Casting Time: 1 Action\t\t\t";
	cout << "Range: Touch\n\t";
	cout << "Duration: Instantaneous\t\t\t";
	cout << "Components: V,S\n\n\t";
	cout << "You touch a living creature that has 0 points. The\n\t";
	cout << "creature becomes stable. This spell has no effect on undead or constructs.\n";
	line();
	cout << "Sacred Flame:\n\t";
	cout << "Casting Time: 1 Action\t\t\t";
	cout << "Range: 60 Feet\n\t";
	cout << "Duration: Instantaneous\t\t\t";
	cout << "Components: V,S\n\n\t";
	cout << "Flame-like radiance descends on a creature that you can\n\t";
	cout << "See within Range. The target must succeed on a Dexterity\n\t";
	cout << "Saving Throw or take 1d8 radiant damage. The target gains no\n\t";
	cout << "benefit from cover for this saving throw.\n\t";
	cout << "The spell's damage increases by 1d8 at level 5, 11, and 17.\n";
	line();
	cout << "Word of Radiance:\n\t";
	cout << "Casting Time: 1 Action\t\t\t";
	cout << "Range: 5 Feet\n\t";
	cout << "Duration: Instantaneous\t\t\t";
	cout << "Components: V,M(Holy Symbol)\n\n\t";
	cout << "You utter a divine word, and burning radiance erupts from you.\n\t";
	cout << "Each creature of your choice that you can see within range must\n\t";
	cout << "succeed on a Constitution saving throw or take 1d6 radiant damage.\n\t";
	cout << "The spell's damage increases by 1d6 when you reach level 5, 11, 17.\n";

}
//Level Spells
void slot_one(){
	cout << "Cure Wounds:\n\t";
	cout << "Casting Time: 1 Action\t\t\t";
	cout << "Range: Touch\n\t";
	cout << "Duration: Instantaneous\t\t\t";
	cout << "Components: V,S\n\n\t";
	cout << "A creature you touch gains a number of hit points equal\n\t";
	cout << "to 1d8 + " << amod(sab) << ". This spell has no effect on undead or constructs.\n\t";
	cout << "At Higher Levels, When you cast this spell using a spell slot of\n\t";
	cout << "2nd level or higher, the healing increases by 1d8 for each spell\n\t";
	cout << "slot level above the 1st.\n";
	line();
	cout << "Healing Word:\n\t";
	cout << "Casting Time: 1 Bonus Action\t\t";
	cout << "Range: 60 Feet\n\t";
	cout << "Duration: Instantaneous\t\t\t";
	cout << "Components: V\n\n\t";
	cout << "A creature of your choice that you can see within range\n\t";
	cout << "regains hit points equal to 1d4 + " << amod(sab) << ". This spell has no effect\n\t";
	cout << "on undead or constructs.\n\t";
	cout << "At higher levels, When you cast this spell using a spell slot\n\t";
	cout << "of 2nd level or higher, the healing increases by 1d4 for each\n\t";
	cout << "slot level above the 1st.\n";
	line();
	cout << "Guiding Bolt:\n\t";
	cout << "Casting Time: 1 Action\t\t\t";
	cout << "Range: 120 Feet\n\t";
	cout << "Duration: 1 Round\t\t\t";
	cout << "Components: V,S\n\n\t";
	cout << "A flash of light streaks towards a creature of your choice\n\t";
	cout << "within range. Make a ranged spell attack against the target.\n\t";
	cout << "On a hit, the target takes 4d6 radiant damage, and the next\n\t";
	cout << "attack roll made against this target before the end of your\n\t";
	cout << "next turn has advantage, thanks to the mystical dim light\n\t";
	cout << "glittering on the target until then.\n\t";
	cout << "At Hihger Levels, When you cast this spell using a spell slot\n\t";
	cout << "of 2nd level or higher, the damage increases by 1d6 for each\n\t";
	cout << "slot level above the 1st.\n";
	line();
	cout << "Identify:\n\t";
	cout << "Casting Time: 1 Minute\t\t\t";
	cout << "Range: Touch\n\t";
	cout << "Duration: Instantaneous\t\t\t";
	cout << "Components: V,S,M(100gp Pearl, Owl Feather)\n\n\t";
	cout << "You choose one object that you must touch throughout the\n\t";
	cout << "casting of the spell. If it is a magic item or some other\n\t";
	cout << "magic-imbued object, you learn its properties and how to\n\t";
	cout << "use them, whether it require attunement to use, and how many\n\t";
	cout << "charges it has, if any. You learn whether any spells affecting\n\t";
	cout << "the item and what they are. If the item was created by a spell,\n\t";
	cout << "you learn which spell created it.\n\t";
	cout << "If you instead touch a creature throughout the casting, you\n\t";
	cout << "learn what spells, if any, are currently affecting it.\n";
	line();
	cout << "Inflict Wounds:\n\t";
	cout << "Casting Time: 1 Action\t\t\t";
	cout << "Range: Touch\n\t";
	cout << "Duration: Instantaneous\t\t\t";
	cout << "Components: V,S\n\n\t";
	cout << "Make a spell attack against a creature you can reach. On\n\t";
	cout << "a hit, the target takes 3d10 necrotic damage.\n\t";
	cout << "At higher levels, When you cast this spell using a spell\n\t";
	cout << "slot of 2nd level or higher, the damage increases by 1d10\n\t";
	cout << "for each slot level above 1st.\n";
	line();
	cout << "Searing Smite:\n\t";
	cout << "Casting Time: 1 Bonus Aciton\t\t";
	cout << "Range: Self\n\t";
	cout << "Duration: Concentration, 1 Minute\t";
	cout << "Components: V\n\n\t";
	cout << "The next time you hit a creature with a melee weapon\n\t";
	cout << "attack during the spell's duration, your weapon flares with\n\t";
	cout << "with white-hot intensity, and the attack deals an extra 1d6\n\t";
	cout << "fire damage to the target and causes the target to ignite in\n\t";
	cout << "flames. At the start of each of its turns until the spell ends,\n\t";
	cout << "the target must make a Constitution saving throw. On a failed save,\n\t";
	cout << "it takes 1d6 fire damage. On a successful save, the spell ends. If\n\t";
	cout << "the target or a crature within 5 feet of it uses an action to put out\n\t";
	cout << "the flames or if some other effect douses the flames, the spell ends.\n\t";
	cout << "At Higher Levels, When you cast this spell using a spell slot of 2nd\n\t";
	cout << "level or higher, the initial extra damage dealt by the attack increases\n\t";
	cout << "by 1d6 for each slot level abot 1st.\n";
	line();
	cout << "Shield of Faith:\n\t";
	cout << "Casting Time: 1 Bonus Action\t\t";
	cout << "Range: 60 Feet\n\t";
	cout << "Duration: Concentration, 10 Minutes\t";
	cout << "Components: V,S,M(Parchement with Holy Text)\n\n\t";
	cout << "A shimmering appears and surrounds a creature of your choice within\n\t";
	cout << "range, granting it a +2 bonus to AC for the Duration\n";
	line();
	cout << "Purify Food and Drink:\n\t";
	cout << "Casting Time: 1 Action\t\t\t";
	cout << "Range: 10 Feet\n\t";
	cout << "Duration: Instantaneous\t\t\t";
	cout << "Components: V,S\n\n\t";
	cout << "All nonmagical food and drink within a 5-foot-radius sphere\n\t";
	cout << "Centered on a point of your choice within range is purified\n\t";
	cout << "And rendered free of poison and disease.\n";
}
//Level 2 Spells
void slot_two(){
	cout << "Heat Metal:\n\t";
	cout << "Casting Time: 1 Action\t\t\t";
	cout << "Range: 60 Feet\n\t";
	cout << "Duration: Concentration, 1 Minute\t";
	cout << "Components: V,S,M(Iron and Flame)\n\n\t";
	cout << "Choose a manufactured metal object, such as metal weaons or armor,\n\t";
	cout << "That you can see within range. You cause the object to glow red hot.\n\t";
	cout << "Any creature in physical contact with the object takes 2d8 fire damage\n\t";
	cout << "when you cast the spell. Until the spell ends, you can use a bonus action\n\t";
	cout << "on each of your subsequent turns to cuase this damage again.\n\t";
	cout << "If a creature is holding or wearing the object and takes damage from it,\n\t";
	cout << "The creature must make a Constitution saving throw or drop the object if\n\t";
	cout << "It can. If it doesnt drop the object, it has disadvantage on attack rolls\n\t";
	cout << "And ability checks until the start of your turn.\n\t";
	cout << "At higher levels. When you cast thist spell using a spell slot of 3rd level\n\t";
	cout << "or  higher, the damage increases by 1d8 for each slot level above 2nd\n";
	line();
	cout << "Magic Weapon:\n\t";
	cout << "Casting Time: 1 Bonus Action\t\t";
	cout << "Range: Touch\n\t";
	cout << "Duration: Concentration, 1 Hour\t";
	cout << "Components: V,S\n\n\t";
	cout << "You touch a nonmagical weapon. Until the spell ends that weapon becomes a\n\t";
	cout << "Magic weapon with a +1 bonus to attack rolls and damage rolls.\n\t";
	cout << "At Higher Levels. When you cast this spell using a spell slot of 4th level\n\t";
	cout << "or higher, the bonus increases to +2. When you use a spell slot of 6th level\n\t";
	cout << "or higher, the bonus increases to +3.\n";
}
//Level 3 Spells
void slot_three(){
}
//Level 4 Spells
void slot_four(){
}
//Level 5 Spells
void slot_five(){
}
//Level 6 Spells
void slot_six(){
}
//Level 7 Spells
void slot_seven(){
}
//Level 8 Spells
void slot_eight(){
}
//Level 9 Spells
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
	cout << "Blessing of the Forge:\n\t";
	cout << "You gain the ability to imbue magic into a weapon or armor.\n\t";
	cout << "At the end of a long rest, you can touch one nonmagical\n\t";
	cout << "object that is a suit of armor or a simple or martial weapon.\n\t";
	cout << "Until the end of your next long rest or until you die, the\n\t";
	cout << "object becomes a magic item, granting a +1 bonus to AC if it's\n\t";
	cout << "armor or a +1 bonus to attack and damage rolls if it's a weapon.\n\t";
	cout << "Once you use this feature, you can't use it again until you\n\t";
	cout << "finish a long rest.\n";
	line();
	cout << "Healing Hands:\n\t";
	cout << "As an action, you can touch a creature and cause it to regain\n\t";
	cout << "a number of hitpoints equal to your level. Once you use this trait,\n\t";
	cout << "You can't use it again until you finish a long rest.\n";
	line();
	cout << "Radiant Soul: Level 3 Req.\n\t";
	cout << "You can unleash the divine energy as an action. When you do so,\n\t";
	cout << "your eyes glimmer and two luminous, ghost-like wings emerge from\n\t";
	cout << "your back and you gain a flying speed of 30 feet. The transformation\n\t";
	cout << "lasts for 1 min, and once on each of your turns you can deal " << lvl << " extra\n\t";
	cout << "radiant damage, Whenever you damage a creature with an attack or spell.\n\t";
	cout << "You can cancel Radiant Soul with a bonus action, and cannot use it\n\t";
	cout << "again until you take a long rest.\n";
	dline();
}

//Channel Divinity
void divinity(){
	cout << "Channel Divinity:\n";
	cout << "Turn Undead:\n\t";
	cout << "Undead within 30 feet must make a DC 13 Wisdom\n\t";
	cout << "save or be turned for 1 min. or until damaged.\n";
	line();
	cout << "Artisan's Blessing\n\t";
	cout << "You can use your channel divinity to create simple items.\n\t";
	cout << "You conduct an hour-long ritual that crafts a nonmagical\n\t";
	cout << "item that must include some metal: a simple or martial\n\t";
	cout << "weapon, a suit of armor, ten pieces of ammunition, a set\n\t";
	cout << "of tools, or another metal object. The creation is completed\n\t";
	cout << "at the end of the hour, coalescing in an unoccupied space of\n\t";
	cout << "your choice on a surface within 5 feet of you.\n\t";
	cout << "The thing you create can be something that is worth no more\n\t";
	cout << "than 100gp. As part of this ritual, you must lay out metal,\n\t";
	cout << "which can include coins with a value equal to the creation.\n\t";
	cout << "The metal irretrievably coalesces and transforms into the\n\t";
	cout << "creation at the ritual's end, magically forming even nonmagical\n\t";
	cout << "parts of the creation. The ritual can create a duplicate of a\n\t";
	cout << "nonmagical item that contains metal, such as a key, if you\n\t";
	cout << "possess the original during the ritual.\n";
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
	cout << "\t\t\t\tCurrent HP: " << hp << "(" << thp << ")" << endl;
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
	if(calc){ahp();}
	else{mhc();}
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
		//Channel Divinity
		else if(let=='c'){
			cs();
			base();
			divinity();
			options();
			ctr(10);
		;}
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

