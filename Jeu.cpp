#include <iomanip>
#include <sstream>
#include "Jeu.h"
#include <regex>;

using namespace std;

Jeu::Jeu()
{
    //玩家选择是否选择港口拓展包
    cout<<"Voulez-vous jouer a la version etendue (Port)?   y/n"<<endl;
    char ver;
    cin>>ver;
    if(ver=='y') {
        //new出港口版本
        this->d = new Deckgangkou();
        version = 1;
    }
    if(ver=='n') {
        //生成标准版
        this->d = new Deck();
        version = 0;
    }
    //游戏初始化定义
    this->slot_count = 0;
    this->gameover = false;
    this->turn = 0;
    this->deal();
//选择游玩人数，并创建玩家
    while(1) {
        if (version == 0) {
            cout << "Combien y a-t-il de joueurs(2~4)" << endl;
            cin >> player_number;
            //判断输入是否正确
            if (cin.fail()) {
                cin.clear();
                cin.ignore(2048, '\n');
            } else if (player_number < 5 && player_number > 1) {
                break;
            }
            cout << "Veuillez entrer un nombre de 2 a 4" << endl;
        }
        else if(version==1){
            cout << "Combien y a-t-il de joueurs(2~5)" << endl;
            cin >> player_number;
            //判断输入是否正确
            if (cin.fail()) {
                cin.clear();
                cin.ignore(2048, '\n');
            } else if (player_number < 6 && player_number > 1) {
                break;
            }
            cout << "Veuillez entrer un nombre de 2 a 5" << endl;
        }
    }
//玩家选择是否生成AI
    cout<<"Avez-vous besoin de  joueurs d'ordinateu  y/n"<<endl;
    char reponse;
    cin >> reponse;
    if(reponse=='y')
    {
        cout<<"Combien y a-t-il de joueurs d'ordinateu(1~)"<<endl;
        cin>>ai_number;
    }

    for(int i=1; i <= player_number-ai_number; i++)
    {
        string non_jouer;
        cout<<"Quel est le nom du Joueur "<<i <<endl;
        cin>>non_jouer;
        this->create_player(non_jouer);
    }

    for(int i=1;i<=ai_number;i++)
    {
        string p="AIjoueur"+to_string(i);
        this->create_player(p);
    }
}
//创建玩家
void Jeu::create_player(string name)
{
	Joueur *p = new Joueur();
	p->banque = new Banque();
	p->nom = name;

    Cartes_jaune *c;
    c = new gare();
    p->Cartes_jaune.push_back(c);
    c = new marche();
    p->Cartes_jaune.push_back(c);
    c = new parc_de_loisirs();
    p->Cartes_jaune.push_back(c);
    c = new tour_de_tele();
    p->Cartes_jaune.push_back(c);
    c = new port();
    p->Cartes_jaune.push_back(c);
    c = new aeroport();
    p->Cartes_jaune.push_back(c);
    c = new hotel_de_ville();
    p->Cartes_jaune.push_back(c);
    if(version==0){
        p->Cartes_jaune.pop_back();
        p->Cartes_jaune.pop_back();
        p->Cartes_jaune.pop_back();
    }

    Cartes_bleu *b;
	b = new mais(); p->Cartes_bleu.push_back(b);

	Cartes_vert *g;
	g = new boulangerie(); p->Cartes_vert.push_back(g);

	players.push_back(p);
}

void Jeu::deal()
{
	Cartes *c;
	bool exists;
	while (this->d->deck.size() > 0 && this->slot.size() < 35)
	{
		exists = false;
		c = this->d->deck.back();
		for (int i = 0; i < this->slot.size(); i++)
		{
			if ( c->get_name().compare(this->slot[i][0]->get_name()) == 0 )
			{
				slot[i].push_back(c);
				exists = true;
				break;
			}
		}

		if (!exists)
		{
			vector<Cartes*> v;
			v.push_back(c);
			this->slot.push_back(v);
			this->slot_count++;
		}
		this->d->deck.pop_back();
	}
}

Deck* Jeu::get_deck()
{
	return this->d;
}

vector<vector<Cartes *>> Jeu::get_slot()
{
	return this->slot;
}
//骰子随机
void Jeu::rolling_dice(int dice_count)
{
	this->dice1 = rand()%6+1;
	this->dice2 = 0;

	if (dice_count == 2)
	{
		this->dice2 = rand()%6+1;
	}
	this->dice = this->dice1 + this->dice2;
}
//打印卡牌
void print_card(Cartes *c)
{
	cout << left <<
		setw(10) << c->get_string_color() <<
		setw(25) << c->get_name() <<
		setw(5) << c->get_cost() <<
		setw(5) << c->get_value() <<
		setw(5) << c->get_low_roll() <<
		setw(5) << c->get_high_roll() << endl;
}
void print_yellowcard(Cartes *c)
{
    cout << left <<
         setw(10) << c->get_string_color() <<
         setw(25) << c->get_name() <<
         setw(5) << c->get_cost() <<
         setw(5) << c->get_value() <<
         setw(5) << c->get_low_roll() <<
         setw(5) << c->get_high_roll();
}

void print_card_heading()
{
	cout << left <<
		setw(10) << "couleur" <<
		setw(25) << "nom" <<
		setw(5) << "cout" <<
		setw(5) << "val" <<
		setw(5) << "min" <<
		setw(5) << "max" << endl;
}

void Jeu::view_slot_cards(bool cls)
{
	if (cls) system("cls");
	cout << left <<
		setw(5) << "slot" <<
		setw(5) << "qty";
	print_card_heading();
	for (int i = 0; i < this->slot.size(); i++)
	{
		cout << left <<
			setw(5) << i <<
			setw(5) << this->slot[i].size();
		print_card(this->slot[i][0]);
	}
	cout << endl;
}
//查看玩家卡牌
void Jeu::view_player_cards(int index, bool cls)
{
	if (cls) system("cls");
	print_card_heading();
	for (int i = 0; i < this->players[index]->Cartes_bleu.size(); i++) { print_card(this->players[index]->Cartes_bleu[i]); }
	cout << endl;
	for (int i = 0; i < this->players[index]->Cartes_vert.size(); i++) { print_card(this->players[index]->Cartes_vert[i]); }
	cout << endl;
	for (int i = 0; i < this->players[index]->Cartes_rouge.size(); i++) { print_card(this->players[index]->Cartes_rouge[i]); }
	cout << endl;
	for (int i = 0; i < this->players[index]->Cartes_violet.size(); i++) { print_card(this->players[index]->Cartes_violet[i]); }
	cout << endl;
	for (int i = 0; i < this->players[index]->Cartes_jaune.size(); i++) {
	    print_yellowcard(this->players[index]->Cartes_jaune[i]);
	if(this->players[index]->Cartes_jaune[i]->active == false)
        cout<<"non construit";
	else
	    cout<<"construit";
	cout<<endl;
	}
	cout << endl;
}

vector<string> split(string str)
{
	stringstream ss(str);
	string item;
	vector<string> tokens;
	while (getline(ss, item, ' ')) {
		tokens.push_back(item);
	}
	return tokens;
}
//根据游戏中玩家输入实现购买等效果
int Jeu::player_input(string message)
{
	string cmds = "(no)"
		"|(vue [0-9]+)"
		"|(vue table)"
		"|(acheter [0-9]*)";
	regex view(cmds);
	bool complete = false;
	while (true)
	{
		string str;
		getline(cin, str);
		vector<string> input = split(str);
		if (!regex_match(str, view))
		{
//			cout << "Commande inconnue" << endl;
		}
		else if (input[0] == "no")
		{
		    if(version==1) {
                if (this->players[this->turn]->Cartes_jaune[5]->active == true) {
                    this->players[this->turn]->banque->deposit(10);
                    return -1;
                }
            }
            return -1;
		}
//查看桌面或者某玩家的牌
		else if (input[0] == "vue")
		{
			if (input[1] == "table") view_slot_cards(true);

			else if (stoi(input[1]) > this->players.size() - 1)
			{
				cout << "Il n’y a pas de Joueur " << stoi(input[1]) << endl;
				continue;
			}
			else view_player_cards(stoi(input[1]), true);
			cout << message << endl;
		}
//购买
		else if (input[0] == "acheter")
		{
			if (stoi(input[1]) > this->slot.size()-1)
			{
				cout << "Pas de carte a player_number: " << stoi(input[1]) << endl;
				continue;
			}
			if (this->players[this->turn]->banque->get_coins() < this->slot[stoi(input[1])][0]->get_cost())
			{
				cout << "Vous ne pouvez pas vous le permettre" << endl;
				continue;
			}
			return stoi(input[1]);
		}
	}
	return 'a';
}

void Jeu::rolldice()
{
    if(version==1) {
        for (int i = 0; i < players.size(); i++) {
            players[i]->Cartes_jaune[6]->active = true;
        }
    }
	system("cls");
	this->deal();
	this->view_slot_cards(true);
	this->view_player_cards(this->turn, false);
	
	int dice_count = 1;

	// 判断火车站是否被建造，并选择骰子数
	if (this->players[this->turn]->Cartes_jaune[0]->active)
	{
        cout << "1 or 2 des: "<<endl;
        if(this->turn < player_number-ai_number) {
            cin >> dice_count;
        }
        //AI玩家掷骰子
        else if(this->turn >= player_number-ai_number){
            int res=rand() % 2 + 1;
            if(res==1)
                cout << players[this->turn]->nom << " choisit de lancer 1 de" << endl;
            if(res==2)
                cout << players[this->turn]->nom << " ne choisit pas de lancer 2 des" << endl;
            dice_count=res;
        }
	}
    this->rolling_dice(dice_count);

	// 广播塔
	if (this->players[this->turn]->Cartes_jaune[3]->active)
	{
        cout << "Vous avez lance les des a " << this->dice << ". Allez-vous lancer les des a nouveau   (y/n): "<<endl;
        char response;
	    if(this->turn < player_number-ai_number) {
            cin >> response;
        }
	    //AI玩家选择
	    else if(this->turn >= player_number-ai_number){
            int res=rand() % 2 + 1;
            if(res==1)  {response='y';
            cout << players[this->turn]->nom << " choisit de relancer" << endl;}
            if(res==2)  {response='n';
            cout << players[this->turn]->nom << " ne choisit pas de relancer" << endl;}
	    }
        if (response == 'y') this->rolling_dice(dice_count);
	}
    // 判断玩家是否有港口
    if(version==1) {
        if (this->players[this->turn]->Cartes_jaune[4]->active) {
            if (this->dice > 10) {
                //可以选择点数加2
                cout << "\n"
                        "Vous pouvez ajouter deux points aux des " << ". ajouter?   (y/n): ";
                char response;
                if (this->turn < player_number - ai_number) {
                    cin >> response;
                } else if (this->turn >= player_number - ai_number) {
                    int res = rand() % 2 + 1;
                    if (res == 1) {
                        response = 'y';
                        cout << players[this->turn]->nom << " choisit de ajouter 2" << endl;
                    }
                    if (res == 2) {
                        response = 'n';
                        cout << players[this->turn]->nom << " ne choisit pas de ajouter 2" << endl;
                    }
                }
                if (response == 'y') this->dice += 2;
            }
        }
    }
	cout << endl;
	cout << "Joueur: " << this->players[this->turn]->nom << " | Piece: " << this->players[this->turn]->banque->get_coins() << " | a lance les des a " << this->dice << endl;
	this->red_card_check();
}
//根据结算顺序check各类牌->红->蓝->绿—>紫
void Jeu::red_card_check()
{
    cout<<"Cheque cartes rouge  | ";
	int tracker = this->turn - 1;
	if (tracker < 0) tracker = this->players.size() - 1;

	while (tracker != this->turn)
	{
		for (int i = 0; i < this->players[tracker]->Cartes_rouge.size(); i++)
		{
			if (this->dice <= this->players[tracker]->Cartes_rouge[i]->get_high_roll() &&
				this->dice >= this->players[tracker]->Cartes_rouge[i]->get_low_roll())
			{
				Cartes *c = NULL;
				// 购物中心
				if (this->players[tracker]->Cartes_jaune[1]->active) c = this->players[tracker]->Cartes_rouge[i];
				this->players[tracker]->Cartes_rouge[i]->action(
					this->players[tracker]->banque,
					this->players[this->turn]->banque,
					c,
					NULL,
					0
					);
			}
			//if (this->players[i]->banque->get_coins() == 0) break;
		}
		tracker--;
		if (tracker < 0) tracker = this->players.size() - 1;
	}
	cout<<"piece: "<<this->players[turn]->banque->get_coins()<<endl;
	this->blue_card_check();
}

void Jeu::blue_card_check()
{
    cout<<"Cheque cartes bleu   | ";
	for (int i = 0; i < this->players.size(); i++)
	{
		for (int j = 0; j < this->players[i]->Cartes_bleu.size(); j++)
		{
			if (this->dice <= this->players[i]->Cartes_bleu[j]->get_high_roll() &&
				this->dice >= this->players[i]->Cartes_bleu[j]->get_low_roll())
			{
			    //金枪鱼船
//              int i = 0;
//              while (i < this->players[this->turn]->Cartes_bleu.size() &&
//              this->players[this->turn]->Cartes_bleu[i]->get_name() != "Thonier")
//                  i++;
//              if (i < this->players[this->turn]->Cartes_bleu.size()) {
//                  for (int k = 0; i < players.size(); i++) {
//                      int j = 0;
//                      while (i <= this->players[this->turn]->Cartes_bleu.size() &&
//                      this->players[this->turn]->Cartes_bleu[i]->get_name().compare("Thonier"))
//                          j++;
//                      int m;
//                      while (m <= j)
//                          this->players[k]->banque->deposit(rand()%12+1);
//                      m++;
//                  }
//              }
              this->players[i]->Cartes_bleu[j]->action(
					this->players[i]->banque,
					NULL,
					NULL,
					NULL,
					0
					);
			}
		}
	}
    cout<<"piece: "<<this->players[turn]->banque->get_coins()<<endl;
	this->green_card_check();
}
void Jeu::green_card_check()
{
    cout<<"Cheque cartes vert   | ";
	for (int i = 0; i < this->players[this->turn]->Cartes_vert.size(); i++)
	{
		if (this->dice <= this->players[this->turn]->Cartes_vert[i]->get_high_roll() &&
			this->dice >= this->players[this->turn]->Cartes_vert[i]->get_low_roll())
		{
			Cartes *c = NULL;
			// 购物中心
			if (this->players[this->turn]->Cartes_jaune[1]->active) c = this->players[this->turn]->Cartes_vert[i];
			int val = 0;
			Icon icon = this->players[this->turn]->Cartes_vert[i]->get_icon();
			if (icon != Icon::none)
			{
				for (int j = 0; j < this->players[this->turn]->Cartes_vert.size(); j++)
				{
					if (icon == this->players[this->turn]->Cartes_vert[j]->get_icon()) val++;
				}
			}
			this->players[this->turn]->Cartes_vert[i]->action(
				this->players[this->turn]->banque,
				NULL,
				c,
				NULL,
				val
				);
		}
	}
    cout<<"piece: "<<this->players[turn]->banque->get_coins()<<endl;
	this->purple_card_check();
}

//紫卡功能实现
void Jeu::purple_card_check()
{
    cout<<"Cheque cartes violet | ";
	for (int i = 0; i < this->players[this->turn]->Cartes_violet.size(); i++)
	{
        if (this->dice <= this->players[this->turn]->Cartes_violet[i]->get_high_roll() &&
            this->dice >= this->players[this->turn]->Cartes_violet[i]->get_low_roll()) {
            //check体育馆
            if (this->players[this->turn]->Cartes_violet[i]->get_name().compare("stade") == 0) {
                for (int j = 0; j < this->players.size(); j++) {
                    this->players[this->turn]->banque->deposit(this->players[j]->banque->withdraw(2));
                }
            }
            //check电视台
            if (this->players[this->turn]->Cartes_violet[i]->get_name().compare("station_de_television") == 0) {
                cout << endl;
                cout << "Prenez 5 pieces de: ";
                for (int j = 0; j < this->players.size(); j++) {
                    cout << j << this->players[j]->nom << ": " << this->players[j]->banque->get_coins() << "  ";
                }
                cout << endl;
                int player_num;
                if (this->turn < player_number - ai_number) {
                    cin >> player_num;
                    this->players[this->turn]->banque->deposit(this->players[player_num]->banque->withdraw(5));
                }
                //AI玩家选择
                else if (this->turn >= player_number - ai_number) {
                    player_num = rand() % ((player_number- ai_number-1) - 0 + 1) + 0;
                    this->players[this->turn]->banque->deposit(this->players[player_num]->banque->withdraw(5));
                    cout << players[this->turn]->nom << "Prenez 5 pieces de" << this->players[player_num]->nom << endl;
                }
                cout << "Cheque cartes violet | ";
            }
            //check税务局
            if (this->players[this->turn]->Cartes_violet[i]->get_name().compare("regie") == 0) {
                for (int j = 0; j < this->players.size(); j++) {
                    if (this->players[j]->banque->get_coins() >= 10)
                        this->players[this->turn]->banque->deposit(
                                this->players[j]->banque->withdraw(this->players[j]->banque->get_coins() / 2));
                }
            }
            //check出版社
            if (this->players[this->turn]->Cartes_violet[i]->get_name().compare("maison_de_edition") == 0) {
                for (int j = 0; j < this->players.size(); j++) {
                    int m = 0;
                    for (int i = 0; i < this->players[j]->Cartes_rouge.size(); i++)
                        m++;
                    for (int i = 0; i < this->players[j]->Cartes_vert.size(); i++) {
                        if (this->players[j]->Cartes_vert[i]->get_icon() == Icon::bread)
                            m++;
                    }
                    this->players[this->turn]->banque->deposit(this->players[j]->banque->withdraw(m));
                }
            }
            //check商业中心
            if (this->players[this->turn]->Cartes_violet[i]->get_name().compare("centre_commercial") == 0) {
                cout << endl;
                cout << "Cartes d'echange avec un Joueur :" << endl;
                for (int j = 0; j < this->players.size(); j++) {
                    cout << "Joueur: " << j << " " << this->players[j]->nom << endl;
                    cout << "Bleu(1): ";
                    for (int k = 0; k < this->players[j]->Cartes_bleu.size(); k++) {
                        cout << " |" << k << ": " << this->players[j]->Cartes_bleu[k]->get_name();
                    }
                    cout << endl;
                    cout << "Vert(2): ";
                    for (int k = 0; k < this->players[j]->Cartes_vert.size(); k++) {
                        cout << " |" << k << ": " << this->players[j]->Cartes_vert[k]->get_name();
                    }
                    cout << endl;
                    cout << "Rouge(3): ";
                    for (int k = 0; k < this->players[j]->Cartes_rouge.size(); k++) {
                        cout << " |" << k << ": " << this->players[j]->Cartes_rouge[k]->get_name();
                    }
                    cout << endl;
                }
                int player_num;
                int color_num;
                int card_num;
                if (this->turn < player_number - ai_number) {
                    cout << "Selectionnez joueur a prendre: ";
                    cin >> player_num;
                    cout << endl;

                    cout << "Selectionnez couleur a prendre: ";
                    cin >> color_num;
                    cout << endl;

                    cout << "Selectionnez carte a prendre: ";
                    cin >> card_num;
                    cout << endl;
                }
                    //AI玩家选择拿牌
                else {
                    cout << "Selectionnez joueur a prendre: " << endl;
                    player_num = (rand() % ((player_number- ai_number-1) - 0 + 1)) + 0;
                    cout << "Selectionnez couleur a prendre: " << endl;
                    color_num = 2;
                    cout << "Selectionnez carte a prendre: " << endl;
                    card_num = 0;
                    cout << players[turn]->nom << " a pris joueur " << players[player_num]->nom << ":"
                         << this->players[player_num]->Cartes_bleu[card_num]->get_name() << endl;
                }

                if (color_num == 1)
                {
                    this->players[this->turn]->Cartes_bleu.push_back(this->players[player_num]->Cartes_bleu[card_num]);
                    this->players[player_num]->Cartes_bleu.erase(
                            this->players[player_num]->Cartes_bleu.begin() + card_num);
                } else if (color_num == 2)
                {
                    this->players[this->turn]->Cartes_vert.push_back(this->players[player_num]->Cartes_vert[card_num]);
                    this->players[player_num]->Cartes_vert.erase(
                            this->players[player_num]->Cartes_vert.begin() + card_num);
                } else if (color_num == 3)
                {
                    this->players[this->turn]->Cartes_rouge.push_back(
                            this->players[player_num]->Cartes_rouge[card_num]);
                    this->players[player_num]->Cartes_rouge.erase(
                            this->players[player_num]->Cartes_rouge.begin() + card_num);
                }
                if (this->turn < player_number - ai_number) {
                    cout << "Selectionnez Couleur a donner: ";
                    cin >> color_num;
                    cout << endl;

                    cout << "Selectionnez Cartes a donner: ";
                    cin >> card_num;
                    cout << endl;
                }
                    //AI玩家给牌
                else {
                    cout << "Selectionnez Couleur a donner: " << endl;
                    cout << "Selectionnez Cartes a donner: " << endl;
                    color_num = 1;
                    card_num = 0;
                    cout << players[turn]->nom << " a donne la carte: "
                         << this->players[this->turn]->Cartes_bleu[card_num]->get_name() << endl;

                }
                if (color_num == 1)
                {
                    this->players[player_num]->Cartes_bleu.push_back(this->players[this->turn]->Cartes_bleu[card_num]);
                    this->players[this->turn]->Cartes_bleu.erase(
                            this->players[this->turn]->Cartes_bleu.begin() + card_num);
                } else if (color_num == 2)
                {
                    this->players[player_num]->Cartes_vert.push_back(this->players[this->turn]->Cartes_vert[card_num]);
                    this->players[this->turn]->Cartes_vert.erase(
                            this->players[this->turn]->Cartes_vert.begin() + card_num);
                } else if (color_num == 3)
                {
                    this->players[player_num]->Cartes_rouge.push_back(
                            this->players[this->turn]->Cartes_rouge[card_num]);
                    this->players[this->turn]->Cartes_rouge.erase(
                            this->players[this->turn]->Cartes_rouge.begin() + card_num);
                }
                cout << "Cheque cartes violet | ";
            }
        }
	}
    cout<<"piece: "<<this->players[turn]->banque->get_coins()<<endl;
	this->buy_property();
}

// 购买相关流程
void Jeu::buy_property() {
    //市政厅效果若购买时玩家金币数量为0则获得1金币
    if(version==1) {
        if (this->players[this->turn]->banque->get_coins() == 0)
            this->players[this->turn]->banque->deposit(1);
    }
    cout << "Proprietes: apres cartes: " << this->players[this->turn]->banque->get_coins() << endl;
    cout << "Quel edifice souhaitez-vous acheter ?" << endl;
    int selection;
    bool complete = false;
    if (this->turn < player_number-ai_number) {
        while (!complete) {
            selection = this->player_input("Quel edifice souhaitez-vous acheter ?");
            cout << endl;
            if (selection >= 0) {
                int select = selection;
                this->players[this->turn]->banque->withdraw(this->slot[select][0]->get_cost());
                if (Couleur::bleu == this->slot[select][0]->get_color()) {
                    this->players[this->turn]->Cartes_bleu.push_back((Cartes_bleu *) this->slot[select].back());
                    this->slot[select].pop_back();
                    complete = true;
                } else if (Couleur::vert == this->slot[select][0]->get_color()) {
                    this->players[this->turn]->Cartes_vert.push_back((Cartes_vert *) this->slot[select].back());
                    this->slot[select].pop_back();
                    complete = true;
                } else if (Couleur::rouge == this->slot[select][0]->get_color()) {
                    this->players[this->turn]->Cartes_rouge.push_back((Cartes_rouge *) this->slot[select].back());
                    this->slot[select].pop_back();
                    complete = true;
                } else if (Couleur::violet == this->slot[select][0]->get_color()) {
                    bool purp = true;
                    for (int i = 0; i < this->players[this->turn]->Cartes_violet.size(); i++) {
                        if (this->slot[select].back()->get_name().compare(
                                this->players[this->turn]->Cartes_violet[i]->get_name()) == 0) {
                            cout << "Vous avez deja cet etablissement" << endl;
                            purp = false;
                        }
                    }
                    if (purp) {
                        this->players[this->turn]->Cartes_violet.push_back((Cartes_violet *) this->slot[select].back());
                        this->slot[select].pop_back();
                        complete = true;
                    }
                } else if (Couleur::jaune == this->slot[select][0]->get_color()) {
                    bool yel = true;
                    if(version==1) {
                        if (this->players[this->turn]->Cartes_jaune[select - (slot.size()-7)]->active == true) {
                            cout << "Vous avez deja cet etablissement" << endl;
                            yel = false;
                        }
                        if (yel) {
                            this->players[this->turn]->Cartes_jaune[select - (slot.size()-7)]->active = true;
                            this->slot[select].pop_back();
                            complete = true;
                        }
                    }
                    else if(version==0){
                        if (this->players[this->turn]->Cartes_jaune[select - (slot.size()-4)]->active == true) {
                            cout << "Vous avez deja cet etablissement" << endl;
                            yel = false;
                        }
                        if (yel) {
                            this->players[this->turn]->Cartes_jaune[select - (slot.size()-4)]->active = true;
                            this->slot[select].pop_back();
                            complete = true;
                        }
                    }
                }

                if (this->slot[select].size() == 0) {
                    this->slot.erase(this->slot.begin() + select);
                }
            } else {
                break;
            }
        }
        this->end_of_turn();
    }
    //AI玩家购卡
    else  {
        cout<<endl;
        while (!complete) {
            if(version==0)
                selection=rand() % ((slot.size()-1)-0+1)+0;
            else if(version ==1)
                selection=rand() % ((slot.size()-2)-0+1)+0;
            if (selection > slot.size() - 1) {
                selection = 0;
            }
            if(this->players[this->turn]->banque->get_coins() < this->slot[selection][0]->get_cost()){
                complete=true;
                cout<<"AIjoueur ne choisit pas dacheter"<<endl;
                complete=true;
                break;
            }
//            while(this->players[this->turn]->banque->get_coins()<this->slot[selection][0]->get_cost()) {
//                selection++;
//            }
             if (Couleur::jaune == this->slot[selection][0]->get_color()) {
                    for (int i = 0; i < this->players[this->turn]->Cartes_jaune.size(); i++) {
                        if(version==1) {
                            if (this->players[this->turn]->Cartes_jaune[selection - (slot.size()-7)]->active == true) {
//                            selection++;
                                complete = true;
                                cout << "AIjoueur ne choisit pas dacheter" << endl;
                                break;
                            }
                        }
                        else if(version==0){
                            if (this->players[this->turn]->Cartes_jaune[selection - (slot.size()-4)]->active == true) {
//                            selection++;
                                complete = true;
                                cout << "AIjoueur ne choisit pas dacheter" << endl;
                                break;
                            }
                        }
                        if (selection > slot.size() - 1) {
                            selection = 0;
                            break;
                        }
                    }
                }
                if (Couleur::violet == this->slot[selection][0]->get_color()) {
                    for (int i = 0; i < this->players[this->turn]->Cartes_violet.size(); i++) {
                        if (this->slot[selection].back()->get_name().compare(
                                this->players[this->turn]->Cartes_violet[i]->get_name()) == 0) {
//                            selection++;
                            complete=true;
                            cout<<"AIjoueur ne choisit pas dacheter"<<endl;
                            break;
                        }
                    }
                }
            int select = selection;
            this->players[this->turn]->banque->withdraw(this->slot[select][0]->get_cost());
            if (Couleur::bleu == this->slot[select][0]->get_color()) {
                this->players[this->turn]->Cartes_bleu.push_back((Cartes_bleu *) this->slot[select].back());
                this->slot[select].pop_back();
                cout << this->players[this->turn]->nom << " a achete slot" << selection << endl;
                complete = true;
            } else if (Couleur::vert == this->slot[select][0]->get_color()) {
                this->players[this->turn]->Cartes_vert.push_back((Cartes_vert *) this->slot[select].back());
                this->slot[select].pop_back();
                cout << this->players[this->turn]->nom << " a achete slot" << selection << endl;
                complete = true;
            } else if (Couleur::rouge == this->slot[select][0]->get_color()) {
                this->players[this->turn]->Cartes_rouge.push_back((Cartes_rouge *) this->slot[select].back());
                this->slot[select].pop_back();
                cout << this->players[this->turn]->nom << " a achete slot" << selection << endl;
                complete = true;
            } else if (Couleur::violet == this->slot[select][0]->get_color()) {
//                bool purp = true;
//                for (int i = 0; i < this->players[this->turn]->Cartes_violet.size(); i++) {
//                    if (this->slot[select].back()->get_name().compare(
//                            this->players[this->turn]->Cartes_violet[i]->get_name()) == 0) {
//                        cout << "You already have this establishment" << endl;
//                        purp = false;
//                    }
//                }
//                if (purp) {
                    this->players[this->turn]->Cartes_violet.push_back((Cartes_violet *) this->slot[select].back());
                    this->slot[select].pop_back();
                    cout << this->players[this->turn]->nom << " a achete slot" << selection << endl;
                    complete = true;
//                }
            } else if (Couleur::jaune == this->slot[select][0]->get_color()) {
//                bool yel = true;
//                if (this->players[this->turn]->Cartes_jaune[select - 25]->active == true) {
//                    cout << "You already have this establishment" << endl;
//                    yel = false;
//                }
//                if (yel) {
                    if(version == 1){
                        this->players[this->turn]->Cartes_jaune[select - (slot.size()-7)]->active = true;
                        this->slot[select].pop_back();
                        cout << this->players[this->turn]->nom << " a achete slot" << selection << endl;
                        complete = true;
                    }
                    else if(version == 0){
                        this->players[this->turn]->Cartes_jaune[select - (slot.size()-4)]->active = true;
                        this->slot[select].pop_back();
                        cout << this->players[this->turn]->nom << " a achete slot" << selection << endl;
                        complete = true;
                    }
//                }
            }
            if (this->slot[select].size() == 0) {
                this->slot.erase(this->slot.begin() + select);
            }
        }
        this->end_of_turn();
    }
}

//判断游戏胜利条件
void Jeu::end_of_turn()
{
	this->gameover = true;
	for (int i = 0; i < this->players[turn]->Cartes_jaune.size(); i++)
	{
		if (!this->players[turn]->Cartes_jaune[i]->active)
		{
			this->gameover = false;
			break;
		}
	}
	if (this->gameover) { cout << this->players[turn]->nom << " a gagne" << endl; return; }
	cout << "La ronde de " << this->players[turn]->nom << " est terminee. piece: " << this->players[turn]->banque->get_coins();
	this->turn++;

	//游乐场相关判定
	if (this->players[this->turn - 1]->Cartes_jaune[2]->active)
	{
	    if(dice1==dice2) {
	        cout<<endl;
            cout << "Terminez-vous un autre tour?    y/n"  <<endl;
            char response;
            if (this->turn-1 < player_number-ai_number) {
                cin >> response;
                if (response == 'y') turn--;
            }//AI玩家判断
            else if(this->turn-1 >= player_number-ai_number){
                int res=rand() % 2 + 1;
                if(res==1)  {response='y';
                    cout << players[this->turn-1]->nom << " choisit de jouer a nouveau" << endl;
                    turn--;}
                if(res==2)  {response='n';
                    cout << players[this->turn-1]->nom << " ne choisit pas de jouer a nouveau" << endl;}
            }
        }
	}
	if (this->turn == players.size()) this->turn = 0;
	cout << " | " <<"La ronde de "<< this->players[turn]->nom << " prochain" << endl;
	return;
}