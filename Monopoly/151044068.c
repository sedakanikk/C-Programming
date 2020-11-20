#include <stdio.h>
#include <stdlib.h>

typedef enum {noone, cap, car} player_type;
typedef enum {start, property, tax, punish} block_type;

struct player{
	player_type type;
	int current_block_id;
	int owned_block_ids[12];
	int account;
	int turn_to_wait;
	char *name;
} player;

struct block{
	int block_id;
	char *name;
	int price;
	int rent;
	int rent_1;
	int rent_2;
	int rent_3;
	int house_price;
	int house_count;
	struct player owner;
	block_type type;
} block;
// to initialize board
void init_the_board(struct block board[20]) {
	int i;
	//ids assigned
	for(i=0; i<20; i++) {
		board[i].block_id = i;
	}
	// names asssigned
	board[0].name = "Start"; 
	board[1].name = "Esenyurt"; 
	board[2].name = "Car Park"; 
	board[3].name = "Tuzla";
	board[4].name = "Arnavutköy";
	board[5].name = "Wait 2 Turn";
	board[6].name = "Çatalca";
	board[7].name = "Beykoz";
	board[8].name = "Car Fix";
	board[9].name = "Maltepe";
	board[10].name = "Bills";
	board[11].name = "Şişli";
	board[12].name = "Oil";
	board[13].name = "Ataşehir";
	board[14].name = "Sarıyer";
	board[15].name = "Wait 1 Turn";
	board[16].name = "Kadıköy";
	board[17].name = "Beşiktaş";
	board[18].name = "Vocation";
	board[19].name = "Bebek";
	// prices assigned
	board[0].price = 0;
	board[1].price = 16000;
	board[2].price = 0;
	board[3].price = 16500;
	board[4].price = 17000; 
	board[5].price = 0;
	board[6].price = 20000;
	board[7].price = 23000;
	board[8].price = 0;
	board[9].price = 30000;
	board[10].price = 0; 
	board[11].price = 33000;
	board[12].price = 0;
	board[13].price = 35000; 
	board[14].price = 40000;
	board[15].price = 0;
	board[16].price = 43000;
	board[17].price = 60000;
	board[18].price = 0;
	board[19].price = 70000;
	// rents assigned
	board[0].rent = 0;
	board[1].rent = 800;
	board[2].rent = 1500;
	board[3].rent = 850;
	board[4].rent = 875;
	board[5].rent = 2;
	board[6].rent = 1000;
	board[7].rent = 1100;
	board[8].rent = 1750;
	board[9].rent = 1350;
	board[10].rent = 2000;
	board[11].rent = 1500;
	board[12].rent = 2250;
	board[13].rent = 1600;
	board[14].rent = 1750;
	board[15].rent = 1;
	board[16].rent = 1900;
	board[17].rent = 2500;
	board[18].rent = 5000;
	board[19].rent = 3500;

	board[0].rent_1 = 0;
	board[1].rent_1 = 4000;
	board[2].rent_1 = 0;
	board[3].rent_1 = 4250;
	board[4].rent_1 = 4500;
	board[5].rent_1 = 0;
	board[6].rent_1 = 5000;
	board[7].rent_1 = 5500;
	board[8].rent_1 = 0;
	board[9].rent_1 = 7000;
	board[10].rent_1 = 0;
	board[11].rent_1 = 8000;
	board[12].rent_1 = 0;
	board[13].rent_1 = 8500;
	board[14].rent_1 = 9500;
	board[15].rent_1 = 0;
	board[16].rent_1 = 11000;
	board[17].rent_1 = 15000;
	board[18].rent_1 = 0;
	board[19].rent_1 = 20000;

	board[0].rent_2 = 0;
	board[1].rent_2 = 9000;
	board[2].rent_2 = 0;
	board[3].rent_2 = 9500;
	board[4].rent_2 = 10000;
	board[5].rent_2 = 0;
	board[6].rent_2 = 12000;
	board[7].rent_2 = 12500;
	board[8].rent_2 = 0;
	board[9].rent_2 = 15000;
	board[10].rent_2 = 0;
	board[11].rent_2 = 16000;
	board[12].rent_2 = 0;
	board[13].rent_2 = 17000;
	board[14].rent_2 = 19000;
	board[15].rent_2 = 0;
	board[16].rent_2 = 21500;
	board[17].rent_2 = 28000;
	board[18].rent_2 = 0;
	board[19].rent_2 = 35500;

	board[0].rent_3 = 0;
	board[1].rent_3 = 25000;
	board[2].rent_3 = 0;
	board[3].rent_3 = 26000;
	board[4].rent_3 = 28000;
	board[5].rent_3 = 0;
	board[6].rent_3 = 30000;
	board[7].rent_3 = 33000;
	board[8].rent_3 = 0;
	board[9].rent_3 = 40000;
	board[10].rent_3 = 0;
	board[11].rent_3 = 42000;
	board[12].rent_3 = 0;
	board[13].rent_3 = 45000;
	board[14].rent_3 = 48000;
	board[15].rent_3 = 0;
	board[16].rent_3 = 55000;
	board[17].rent_3 = 60000;
	board[18].rent_3 = 0;
	board[19].rent_3 = 65000;
	// house prices assigned
	board[0].house_price = 0;
	board[1].house_price = 10000;
	board[2].house_price = 0;
	board[3].house_price = 12000;
	board[4].house_price = 12000;
	board[5].house_price = 0;
	board[6].house_price = 13000;
	board[7].house_price = 13000;
	board[8].house_price = 0;
	board[9].house_price = 15000;
	board[10].house_price = 0;
	board[11].house_price = 16000;
	board[12].house_price = 0;
	board[13].house_price = 17000;
	board[14].house_price = 19000;
	board[15].house_price = 0;
	board[16].house_price = 23000;
	board[17].house_price = 30000;
	board[18].house_price = 0;
	board[19].house_price = 35000;
	// types assigned
	board[0].type = start;
	board[1].type = property;
	board[2].type = tax;
	board[3].type = property;
	board[4].type = property;
	board[5].type = punish;
	board[6].type = property;
	board[7].type = property;
	board[8].type = tax;
	board[9].type = property;
	board[10].type = tax;
	board[11].type = property;
	board[12].type = tax;
	board[13].type = property;
	board[14].type = property;
	board[15].type = punish;
	board[16].type = property;
	board[17].type = property;
	board[18].type = tax;
	board[19].type = property;
	// owner types assigned
	board[0].owner.type = noone;
	board[1].owner.type = noone;
	board[2].owner.type = noone;
	board[3].owner.type = noone;
	board[4].owner.type = noone;
	board[5].owner.type = noone;
	board[6].owner.type = noone;
	board[7].owner.type = noone;
	board[8].owner.type = noone;
	board[9].owner.type = noone;
	board[10].owner.type = noone;
	board[11].owner.type = noone;
	board[12].owner.type = noone;
	board[13].owner.type = noone;
	board[14].owner.type = noone;
	board[15].owner.type = noone;
	board[16].owner.type = noone;
	board[17].owner.type = noone;
	board[18].owner.type = noone;
	board[19].owner.type = noone;
	// house counts assigned
	board[0].house_count = 0;
	board[1].house_count = 0;
	board[2].house_count = 0;
	board[3].house_count = 0;
	board[4].house_count = 0;
	board[5].house_count = 0;
	board[6].house_count = 0;
	board[7].house_count = 0;
	board[8].house_count = 0;
	board[9].house_count = 0;
	board[10].house_count = 0;
	board[11].house_count = 0;
	board[12].house_count = 0;
	board[13].house_count = 0;
	board[14].house_count = 0;
	board[15].house_count = 0;
	board[16].house_count = 0;
	board[17].house_count = 0;
	board[18].house_count = 0;
	board[19].house_count = 0;
}
// to print board with players's position with their name
void show_board(struct block board[20],struct player player_one, struct player player_two) {
	int i;
	// prints first line for board
	printf("-------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|     %s          ", board[0].name);
	printf("|     %s       ", board[1].name);
	printf("|     %s       ", board[2].name);
	printf("|     %s          ", board[3].name);
	printf("|     %s     ", board[4].name);
	printf("|     %s    ", board[5].name);
	printf("|\n");
	printf("|                    ");
	printf("|     %d$         ", board[1].price);
	printf("|     %d$          ", board[2].rent);
	printf("|     %d$         ", board[3].price);
	printf("|     %d$         ", board[4].price);
	printf("|                    ");
	printf("|\n");
	// to print players name, if player or players is/are not in the first line, prints white spaces
	for(i=0; i<6; i++) {
		if(player_one.current_block_id != i && player_two.current_block_id != i )
			printf("|                    ");
		else if(player_one.current_block_id == i && player_two.current_block_id != i )
			printf("|     %s            ", player_one.name);
		else if(player_one.current_block_id != i && player_two.current_block_id == i )
			printf("|     %s            ", player_two.name);
		else
			printf("|     %s      %s   ", player_one.name, player_two.name);
	}
	printf("|\n");
	// to prints second line, one block and spaces and one block again
	printf("-------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|     %s          ", board[19].name);
	printf("| \t\t\t\t\t\t\t\t\t\t\t ");
	printf("|     %s        ", board[6].name);
	// then prints their price
	printf("|\n");
	printf("|     %d$         ", board[19].price);
	printf("| \t\t\t\t\t\t\t\t\t\t\t ");
	printf("|     %d$         ", board[6].price);
	printf("|\n");
	// to print players name, if player or players is/are not in the line, prints white spaces 
	if(player_one.current_block_id != 19 && player_two.current_block_id != 19 )
		printf("|                    ");
	else if(player_one.current_block_id == 19 && player_two.current_block_id != 19 )
		printf("|     %s            ", player_one.name);
	else if(player_one.current_block_id != 19 && player_two.current_block_id == 19 )
		printf("|     %s            ", player_two.name);
	else
		printf("|     %s      %s   ", player_one.name, player_two.name);
	// to prints spaces
	printf("| \t\t\t\t\t\t\t\t\t\t\t ");
	// to print players name, if player or players is/are not in the line, prints white spaces 
	if(player_one.current_block_id != 6 && player_two.current_block_id != 6 )
		printf("|                    ");
	else if(player_one.current_block_id == 6 && player_two.current_block_id != 6 )
		printf("|     %s            ", player_one.name);
	else if(player_one.current_block_id != 6 && player_two.current_block_id == 6 )
		printf("|     %s            ", player_two.name);
	else
		printf("|     %s      %s   ", player_one.name, player_two.name);
	printf("|\n");
	// prints lines under the blocks
	printf("----------------------");
	printf(" \t\t\t\t\t\t\t\t\t\t\t ");
	printf("----------------------\n");
	// then prints the names and their rents or prices
	printf("|     %s       ", board[18].name);
	printf("| \t\t\t\t\t\t\t\t\t\t\t ");
	printf("|     %s         ", board[7].name);

	printf("|\n");
	printf("|     %d$          ", board[18].rent);
	printf("| \t\t\t\t\t\t\t\t\t\t\t ");
	printf("|     %d$         ", board[7].price);
	printf("|\n");
	// and others like above
	if(player_one.current_block_id != 18 && player_two.current_block_id != 18 )
		printf("|                    ");
	else if(player_one.current_block_id == 18 && player_two.current_block_id != 18 )
		printf("|     %s            ", player_one.name);
	else if(player_one.current_block_id != 18 && player_two.current_block_id == 18 )
		printf("|     %s            ", player_two.name);
	else
		printf("|     %s      %s   ", player_one.name, player_two.name);

	printf("| \t\t\t\t\t\t\t\t\t\t\t ");

	if(player_one.current_block_id != 7 && player_two.current_block_id != 7 )
		printf("|                    ");
	else if(player_one.current_block_id == 7 && player_two.current_block_id != 7 )
		printf("|     %s            ", player_one.name);
	else if(player_one.current_block_id != 7 && player_two.current_block_id == 7 )
		printf("|     %s            ", player_two.name);
	else
		printf("|     %s      %s   ", player_one.name, player_two.name);
	printf("|\n");

	printf("----------------------");
	printf(" \t\t\t\t\t\t\t\t\t\t\t ");
	printf("----------------------\n");

	printf("|     %s       ", board[17].name);
	printf("| \t\t\t\t\t\t\t\t\t\t\t ");
	printf("|     %s        ", board[8].name);

	printf("|\n");
	printf("|     %d$         ", board[17].price);
	printf("| \t\t\t\t\t\t\t\t\t\t\t ");
	printf("|     %d$          ", board[8].rent);
	printf("|\n");

	if(player_one.current_block_id != 17 && player_two.current_block_id != 17 )
		printf("|                    ");
	else if(player_one.current_block_id == 17 && player_two.current_block_id != 17 )
		printf("|     %s            ", player_one.name);
	else if(player_one.current_block_id != 17 && player_two.current_block_id == 17 )
		printf("|     %s            ", player_two.name);
	else
		printf("|     %s      %s   ", player_one.name, player_two.name);

	printf("| \t\t\t\t\t\t\t\t\t\t\t ");

	if(player_one.current_block_id != 8 && player_two.current_block_id != 8 )
		printf("|                    ");
	else if(player_one.current_block_id == 8 && player_two.current_block_id != 8 )
		printf("|     %s            ", player_one.name);
	else if(player_one.current_block_id != 8 && player_two.current_block_id == 8 )
		printf("|     %s            ", player_two.name);
	else
		printf("|     %s      %s   ", player_one.name, player_two.name);
	printf("|\n");

	printf("----------------------");
	printf(" \t\t\t\t\t\t\t\t\t\t\t ");
	printf("----------------------\n");

	printf("|     %s        ", board[16].name);
	printf("| \t\t\t\t\t\t\t\t\t\t\t ");
	printf("|     %s        ", board[9].name);

	printf("|\n");
	printf("|     %d$         ", board[16].price);
	printf("| \t\t\t\t\t\t\t\t\t\t\t ");
	printf("|     %d$         ", board[9].price);
	printf("|\n");

	if(player_one.current_block_id != 16 && player_two.current_block_id != 16 )
		printf("|                    ");
	else if(player_one.current_block_id == 16 && player_two.current_block_id != 16 )
		printf("|     %s            ", player_one.name);
	else if(player_one.current_block_id != 16 && player_two.current_block_id == 16 )
		printf("|     %s            ", player_two.name);
	else
		printf("|     %s      %s   ", player_one.name, player_two.name);

	printf("| \t\t\t\t\t\t\t\t\t\t\t ");

	if(player_one.current_block_id != 9 && player_two.current_block_id != 9 )
		printf("|                    ");
	else if(player_one.current_block_id == 9 && player_two.current_block_id != 9 )
		printf("|     %s            ", player_one.name);
	else if(player_one.current_block_id != 9 && player_two.current_block_id == 9 )
		printf("|     %s            ", player_two.name);
	else
		printf("|     %s      %s   ", player_one.name, player_two.name);
	printf("|\n");

	printf("-------------------------------------------------------------------------------------------------------------------------------\n");
	printf("|     %s    ", board[15].name);
	printf("|     %s        ", board[14].name);
	printf("|     %s       ", board[13].name);
	printf("|     %s            ", board[12].name);
	printf("|     %s          ", board[11].name);
	printf("|     %s          ", board[10].name);
	printf("|\n");
	printf("|                    ");
	printf("|     %d$         ", board[14].price);
	printf("|     %d$         ", board[13].price);
	printf("|     %d$          ", board[12].rent);
	printf("|     %d$         ", board[11].price);
	printf("|     %d$          ", board[10].rent);
	printf("|\n");

	for(i=15; i>9; i--) {
		if(player_one.current_block_id != i && player_two.current_block_id != i )
			printf("|                    ");
		else if(player_one.current_block_id == i && player_two.current_block_id != i )
			printf("|     %s            ", player_one.name);
		else if(player_one.current_block_id != i && player_two.current_block_id == i )
			printf("|     %s            ", player_two.name);
		else
			printf("|     %s      %s   ", player_one.name, player_two.name);
	}
	printf("|\n");

	printf("-------------------------------------------------------------------------------------------------------------------------------\n");
}
// shows the properties which owner's is noone 
void show_properties(struct block board[20]) {
	int i, selection, temp=0;
	int arr[20];
	// assignes array arr to properties what owner type is noone and block type is property
	printf("Please select a property to see details:\n");
	for(i=0; i<20; i++) {
		if(board[i].owner.type == 0 && board[i].price != 0) {
			printf("%d- \t %s\n", i, board[i].name);
			arr[temp++] = i;
		}
	}
	// takes from user to see details of this element
	scanf("%d", &selection);
	// checks all the elements of arr to show on the screen with its id
	for(i=0; i<temp; i++) {
		if(arr[i] == selection) {
			printf("------------------------------------------\n");
			printf("|\t\t%10s \t\t ", board[selection].name);
			printf("|\n");
			printf("------------------------------------------\n");
			printf("|\t Rent \t\t%d$ \t\t ", board[selection].rent);
			printf("|\n");
			printf("------------------------------------------\n");
			printf("|\t Rent 1 H \t%d$ \t\t ", board[selection].rent_1);
			printf("|\n");
			printf("------------------------------------------\n");
			printf("|\t Rent 2 H \t%d$ \t\t ", board[selection].rent_2);
			printf("|\n");
			printf("------------------------------------------\n");
			printf("|\t Rent 3 H \t%d$ \t\t ", board[selection].rent_3);
			printf("|\n");
			printf("------------------------------------------\n");
			printf("|\t House Price \t%d$ \t\t ", board[selection].house_price);
			printf("|\n");
			printf("------------------------------------------\n");
		}
	}
}
// the function calls if user chooce to buy some properties
void buy_property(struct block* current_block, struct player* current_player) {
	// if current block's owner is no one and its type is property and player's account and capacity are enought to buy the property, player can bought this 
	if(current_block->owner.type == 0 && current_block->type == 1 && current_player->account >= current_block->price && current_player->owned_block_ids[11] == 0){
		int i, size;
		// to calculate number of player's block's
		for(i=0; i<11; i++) {
			if(current_player->owned_block_ids[i] == 0) 
				break;
		}
		// then assign it end of the blocks and current block's type is changed respect to player's type
		size=i;
		current_block->owner.type = current_player->type;
		current_player->owned_block_ids[size] = current_block->block_id;
	}
	else if( current_player->account < current_block->price ) { // if user's account is not enought, offer a proposal to sell
		printf("You should sell a few properties.\n");
	}
	else if( current_block->owner.type == current_player->type ){ // if current block's type is same with player's type, the player already bought this block
		printf("You have already bought this property.\n");
	}
	else if( current_block->owner.type != 0 && current_player->type != current_block->owner.type ){ // if current block's type is different from player's type, the other player already bought this block
		printf("The other player have already bought this property.\n");
	}
	else { //for the other blocks 
		printf("This block is not property. So, you can not buy this.\n");
	}
}
// the funtion is called if user chooce to sell own properties
void sell_property(struct block board[20], struct player* current_player) {
	
	int choice = 1, i, temp=0;
	int selling;
	// while player's choice is 1, shows the him/her properties to sell to bank
	while(choice == 1) {
		temp=0;
		printf("1 - Sell property\n");
		printf("2 - Exit\n");
		scanf("%d", &choice);
		// if player's choice is exit, then exit the function
		if(choice == 2)
			break;
		// shows player's properties
		printf("Your properties are:\n");
		for(i=0; i<20; i++) {
			if(board[i].owner.type == current_player->type) {
				temp=1;
				printf("%d- \t %s\n", i, board[i].name);
			}
		}
		// if player has no property, then say it and exit the function
		if(temp==0) {
			printf("There is no property.\n");
			break;
		}
		// if user has some properties, then ask player to choose one of them
		printf("Choose one of them to sell.\n");
		scanf("%d", &selling);
		for(i=0; i<20; i++) {
			// if player's choice's owner is the player, then pay the half of total cost according to number of house/houses and change the properties owner to noone
			if(board[selling].owner.type == current_player->type) {
				temp=1;
				board[selling].owner.type = 0;
				if(board[selling].house_count == 0) {
					current_player->account += board[selling].price/2;
				}
				else if(board[selling].house_count == 1) {
					current_player->account += (board[selling].price+board[selling].house_price)/2;
				}
				else if(board[selling].house_count == 2) {
					current_player->account += 2*(board[selling].price+board[selling].house_price)/2;
				}
				else if(board[selling].house_count == 3) {
					current_player->account += 3*(board[selling].price+board[selling].house_price)/2;
				}				
				board[selling].house_count = 0;
			}
		}
		// if the block's owner is changed, move right properites after that position to right
		if(temp == 1) {
			i=0;
			while(i<12) {
				if(current_player->owned_block_ids[i] == selling ) {
					break;
				}
				i++;
			}
			while(i<11) {
				current_player->owned_block_ids[i] = current_player->owned_block_ids[i+1];
				i++;
			}
		}
	}
}
// the game starts with player's account are 100.000$ and current id's are Start so 0 
void gameplay (struct block board[20], struct player player_one, struct player player_two) {
	int choice, temp=1, i, count=0, tour=0, wait2=2, wait1=1;
	player_one.account = 100000;
	player_two.account = 100000;
	player_one.current_block_id = 0;
	player_two.current_block_id = 0;
	player_one.turn_to_wait = 0;
	player_two.turn_to_wait = 0;
	// firstly show board on the screen
	do {
		show_board(board, player_one, player_two);
		// menu to ask for what the  current player will do
		printf("1 - Rool the dice\n");
		printf("2 - Show my account\n");
		printf("3 - Show my properties\n");
		printf("4 - Show property deeds\n");
		printf("5 - Buy property\n");
		printf("6 - Buy house\n");
		printf("7 - Sell property\n");
		printf("Please select an option to continue: \n");
		scanf("%d", &choice);
		int dice;
		if(choice == 1) { // player's choice is rooling to dice
			dice = rand() % 7; // rooling the dice
			printf("dice : %d\n", dice); // and prints then on the screen to player see that

			if(temp == 1 && player_one.turn_to_wait == 0) { // // if the turn is second player and first player is not waiting, change the position
				player_one.current_block_id += dice;
				// player's position is changed and if player pass the start point, then player earns 10.000$
				if(player_one.current_block_id >= 20) {
					player_one.current_block_id = player_one.current_block_id % 20;
					player_one.account += 10000;
				}
				if(board[player_one.current_block_id].type == 2) { // if player is in the block which type is tax, then pays the rent
					player_one.account -= board[player_one.current_block_id].rent;
				}
				else if(board[player_one.current_block_id].type == 3 && board[player_one.current_block_id].rent == 2 && player_one.turn_to_wait == 0) { // if player is in the waiting two turn block, then waits 2 turn
					player_one.turn_to_wait = 2;
				}
				else if(board[player_one.current_block_id].type == 3 && board[player_one.current_block_id].rent == 1 && player_one.turn_to_wait == 0) { // if player is in the waiting one turn block, then waits 1 turn
					player_one.turn_to_wait = 1;
				}
				temp=2; // second player's turn
				count=1; // now, the player is first player
			}
			else if(board[player_one.current_block_id].type == 3 && board[player_one.current_block_id].rent == 2 && player_one.turn_to_wait > 0) { // if player is in the waiting two turn block, then waits increasing number of turn
				player_one.turn_to_wait--;
				// player's position is changed and if player pass the start point, then player earns 10.000$
				player_two.current_block_id += dice;
				if(player_two.current_block_id >= 20) {
					player_two.current_block_id = player_two.current_block_id % 20;
					player_two.account += 10000;
				}
				if(board[player_two.current_block_id].type == 2) { // if player is in the block which type is tax, then pays the rent
					player_two.account -= board[player_two.current_block_id].rent;
				}
				temp=1; // first player's turn
				count=2; // now, the player is second player
			}
			else if(board[player_one.current_block_id].type == 3 && board[player_one.current_block_id].rent == 1 && player_one.turn_to_wait > 0) { // if player is in the waiting one turn block, then waits increasing number of turn
				player_one.turn_to_wait--;
				// player's position is changed and if player pass the start point, then player earns 10.000$
				player_two.current_block_id += dice;
				if(player_two.current_block_id >= 20) {
					player_two.current_block_id = player_two.current_block_id % 20;
					player_two.account += 10000;
				}
				if(board[player_two.current_block_id].type == 2) { // if player is in the block which type is tax, then pays the rent
					player_two.account -= board[player_two.current_block_id].rent;
				}
				temp=1; // first player's turn
				count=2; // now, the player is second player
			}			
			else if(temp == 2 && player_two.turn_to_wait == 0) { // if the turn is second player
				// player's position is changed and if player pass the start point, then player earns 10.000$
				player_two.current_block_id += dice;
				if(player_two.current_block_id >= 20) {
					player_two.current_block_id = player_two.current_block_id % 20;
					player_two.account += 10000;
				}
				if(board[player_two.current_block_id].type == 2)  {  // if player is in the block which type is tax, then pays the rent
					player_two.account -= board[player_two.current_block_id].rent;
				}
				else if(board[player_two.current_block_id].type == 3 && board[player_two.current_block_id].rent == 2 && player_two.turn_to_wait == 0) { // if player is in the waiting two turn block, then waits 2 turn
					player_two.turn_to_wait = 2;
				}
				else if(board[player_two.current_block_id].type == 3 && board[player_two.current_block_id].rent == 1 && player_two.turn_to_wait == 0) { // if player is in the waiting one turn block, then waits 1 turn
					player_two.turn_to_wait = 1;
				}
				temp=1; // first player's turn
				count=2; // now, the player is second player
			}
			else if(board[player_two.current_block_id].type == 3 && board[player_two.current_block_id].rent == 2 && player_two.turn_to_wait > 0) { // if player is in the waiting two turn block, then waits increasing number of turn
				player_two.turn_to_wait--;
				// player's position is changed and if player pass the start point, then player earns 10.000$
				player_one.current_block_id += dice;
				if(player_one.current_block_id >= 20) {
					player_one.current_block_id = player_one.current_block_id % 20;
					player_one.account += 10000;
				}
				if(board[player_one.current_block_id].type == 2) { // if player is in the block which type is tax, then pays the rent
					player_one.account -= board[player_one.current_block_id].rent;
				}
				temp=2; // second player's turn
				count=1; // now, the player is first player
			}
			else if(board[player_two.current_block_id].type == 3 && board[player_two.current_block_id].rent == 1 && player_two.turn_to_wait > 0) { // if player is in the waiting one turn block, then waits increasing number of turn
				player_two.turn_to_wait--;
				// player's position is changed and if player pass the start point, then player earns 10.000$
				player_one.current_block_id += dice;
				if(player_one.current_block_id >= 20) {
					player_one.current_block_id = player_one.current_block_id % 20;
					player_one.account += 10000;
				}
				if(board[player_one.current_block_id].type == 2) { // if player is in the block which type is tax, then pays the rent
					player_one.account -= board[player_one.current_block_id].rent;
				}
				temp=2; // second player's turn
				count=1; // now, the player is first player
			}
			if(board[player_one.current_block_id].owner.type == player_two.type) { // if player's current position is other player's property's
				if(board[player_one.current_block_id].house_count == 0) { // and there is no house, then pays the rent only
					player_one.account -= board[player_one.current_block_id].rent;
				}
				else if(board[player_one.current_block_id].house_count == 1) { // if there is one house then pays the rent with one house
					player_one.account -= board[player_one.current_block_id].rent_1;
				}
				else if(board[player_one.current_block_id].house_count == 2) { // if there is two houses then pays the rent with two houses
					player_one.account -= board[player_one.current_block_id].rent_2;
				}
				else if(board[player_one.current_block_id].house_count == 3) { // if there is three houses then pays the rent with three houses
					player_one.account -= board[player_one.current_block_id].rent_3;
				}
			}
			else if(board[player_two.current_block_id].owner.type == player_one.type) { // if player's current position is other player's property's
				if(board[player_two.current_block_id].house_count == 0) { // and there is no house, then pays the rent only
					player_two.account -= board[player_two.current_block_id].rent;
				}
				else if(board[player_two.current_block_id].house_count == 1) { // if there is one house then pays the rent with one house
					player_two.account -= board[player_two.current_block_id].rent_1;
				}
				else if(board[player_two.current_block_id].house_count == 2) { // if there is two houses then pays the rent with two houses
					player_two.account -= board[player_two.current_block_id].rent_2;
				}
				else if(board[player_two.current_block_id].house_count == 3) { // if there is three houses then pays the rent with three houses
					player_two.account -= board[player_two.current_block_id].rent_3;
				}
			}
			if( (player_one.turn_to_wait == 2 && player_two.turn_to_wait == 2) || (player_one.turn_to_wait == 1 && player_two.turn_to_wait == 1) ) { // if both of the players are waiting, then plays together
				player_one.turn_to_wait = 0;
				player_two.turn_to_wait = 0;
			}
			else if(player_one.turn_to_wait == 1 && player_two.turn_to_wait == 2) { // if both of the players are waiting, then plays together
				player_one.turn_to_wait = 0;
				player_two.turn_to_wait = 1;			
			}
			else if(player_one.turn_to_wait == 2 && player_two.turn_to_wait == 1) { // if both of the players are waiting, then plays together
				player_one.turn_to_wait = 1;
				player_two.turn_to_wait = 0;			
			}
		}
		else if(choice == 2) {
			 // if user want to see him/her account
			if(count == 1) {
				printf("Your account: %d$\n", player_one.account);
				temp=2;
			}
			else if(count == 2) {
				printf("Your account: %d$\n", player_two.account);
				temp=1;
			}
		}
		else if(choice == 3) {
			// show player to properties which player can buy
			if(count == 0) {
				show_properties(board);
			}
			else if(count == 1) {
				show_properties(board);
				temp=2;
			}
			else if(count == 2) {
				show_properties(board);
				temp=1;
			}
		}
		else if(choice == 4) {
			// to show player to block with its id
			if(count == 1) {
				printf("------------------------------------------\n");
				printf("|\t\t%10s \t\t ", board[player_one.current_block_id].name);
				printf("|\n");
				printf("------------------------------------------\n");
				printf("|\t Rent \t\t%d$ \t\t ", board[player_one.current_block_id].rent);
				printf("|\n");
				printf("------------------------------------------\n");
				printf("|\t Rent 1 H \t%d$ \t\t ", board[player_one.current_block_id].rent_1);
				printf("|\n");
				printf("------------------------------------------\n");
				printf("|\t Rent 2 H \t%d$ \t\t ", board[player_one.current_block_id].rent_2);
				printf("|\n");
				printf("------------------------------------------\n");
				printf("|\t Rent 3 H \t%d$ \t\t ", board[player_one.current_block_id].rent_3);
				printf("|\n");
				printf("------------------------------------------\n");
				printf("|\t House Price \t%d$ \t\t ", board[player_one.current_block_id].house_price);
				printf("|\n");
				printf("------------------------------------------\n");
			}
			else if(count == 2) {
				printf("------------------------------------------\n");
				printf("|\t\t%10s \t\t ", board[player_two.current_block_id].name);
				printf("|\n");
				printf("------------------------------------------\n");
				printf("|\t Rent \t\t%d$ \t\t ", board[player_two.current_block_id].rent);
				printf("|\n");
				printf("------------------------------------------\n");
				printf("|\t Rent 1 H \t%d$ \t\t ", board[player_two.current_block_id].rent_1);
				printf("|\n");
				printf("------------------------------------------\n");
				printf("|\t Rent 2 H \t%d$ \t\t ", board[player_two.current_block_id].rent_2);
				printf("|\n");
				printf("------------------------------------------\n");
				printf("|\t Rent 3 H \t%d$ \t\t ", board[player_two.current_block_id].rent_3);
				printf("|\n");
				printf("------------------------------------------\n");
				printf("|\t House Price \t%d$ \t\t ", board[player_two.current_block_id].house_price);
				printf("|\n");
				printf("------------------------------------------\n");
			}
		}
		else if(choice == 5) {
			// send to function to buy property and ask user to if he/she build house/houses on her/his property
			// if he/she does not want to build house/houses
			if(count == 1) {
				buy_property(&board[player_one.current_block_id], &player_one);
				if(board[player_one.current_block_id].owner.type == player_one.type) {
					char answer;
					printf("Do you want to build one or more house on the property? (Y / N)\n");
					scanf("%s", &answer);
					if(answer == 'Y')
						choice = 6;
					else
						player_one.account -= board[player_one.current_block_id].price;
				}
				temp=2;
			}
			else if(count == 2) {
				buy_property(&board[player_two.current_block_id], &player_two);
				if(board[player_two.current_block_id].owner.type == player_two.type) {
					char answer;
					buy_property(&board[player_two.current_block_id], &player_two);
					printf("Do you want to build one or more house on the property? (Y / N)\n");
					scanf("%s", &answer);				
					if(answer == 'Y')
						choice = 6;
					else
						player_two.account -= board[player_two.current_block_id].price;	
				}		
				temp=1;
			}
		}
		// if player wants to build house/houses on her property 
		if(choice == 6) {
			if(count == 1) {
				int opt;
				printf("How many house will you build? (1 / 2 / 3)\n");
				scanf("%d", &opt);
				if(opt == 1 && board[player_one.current_block_id].house_count < 2 && 
					player_one.account >= (board[player_one.current_block_id].price + 1*board[player_one.current_block_id].house_price) ){ // if player's account is enought for to build one house and number of houses at most 2
					player_one.account -= (board[player_one.current_block_id].price + 1*board[player_one.current_block_id].house_price);
					board[player_one.current_block_id].house_count += 1;
				}
				else if( player_one.account < (board[player_one.current_block_id].price + 1*board[player_one.current_block_id].house_price) ) { // if player's account is not enought
					printf("You should sell a few properties.\n");
				}
				else if(opt == 2 && board[player_one.current_block_id].house_count < 1 && 
					player_one.account >= (board[player_one.current_block_id].price + 2*board[player_one.current_block_id].house_price) ) { // if player's account is enought for to build two house and number of houses at most 1
					player_one.account -= (board[player_one.current_block_id].price + 2*board[player_one.current_block_id].house_price);
					board[player_one.current_block_id].house_count += 2;
				}
				else if( player_one.account < (board[player_one.current_block_id].price + 2*board[player_one.current_block_id].house_price) ) { // if player's account is not enought
					printf("You should sell a few properties.\n");
				}
				else if(opt == 3 && board[player_one.current_block_id].house_count == 0 && 
					player_one.account >= (board[player_one.current_block_id].price + 3*board[player_one.current_block_id].house_price) ) { // if player's account is enought for to build three house and number of house is 0
					player_one.account -= (board[player_one.current_block_id].price + 3*board[player_one.current_block_id].house_price);
					board[player_one.current_block_id].house_count += 3;						
				}
				else if( player_one.account < (board[player_one.current_block_id].price + 3*board[player_one.current_block_id].house_price) ) { // if player's account is not enought
					printf("You should sell a few properties.\n");
				}
				else { // otherwise, wrong choice
					printf("Wrong choice..\n");
				}
				temp=2;
			}
			else if(count == 2) {
				int opt;
				printf("How many house will you build? (1 / 2 / 3)\n");
				scanf("%d", &opt);
				if(opt == 1 && board[player_two.current_block_id].house_count < 2 && 
					player_two.account >= (board[player_two.current_block_id].price + 1*board[player_two.current_block_id].house_price) ) { // if player's account is enought for to build one house and number of houses at most 2
					player_two.account -= (board[player_two.current_block_id].price + 1*board[player_two.current_block_id].house_price);
					board[player_two.current_block_id].house_count += 1;
				}
				else if( player_two.account < (board[player_two.current_block_id].price + 1*board[player_two.current_block_id].house_price) ) { // if player's account is not enought
					printf("You should sell a few properties.\n");
				}
				else if(opt == 2 && board[player_two.current_block_id].house_count < 1 && 
					player_two.account >= (board[player_two.current_block_id].price + 2*board[player_two.current_block_id].house_price) ) { // if player's account is enought for to build two house and number of houses at most 1
					player_two.account -= (board[player_two.current_block_id].price + 2*board[player_two.current_block_id].house_price);
					board[player_two.current_block_id].house_count += 2;
				}
				else if( player_two.account < (board[player_two.current_block_id].price + 2*board[player_two.current_block_id].house_price) ) { // if player's account is not enought
					printf("You should sell a few properties.\n");
				}
				else if(opt == 3 && board[player_two.current_block_id].house_count == 0 && 
					player_two.account >= (board[player_two.current_block_id].price + 3*board[player_two.current_block_id].house_price) ) {  // if player's account is enought for to build two house and number of houses at most 1
					player_two.account -= (board[player_two.current_block_id].price + 3*board[player_two.current_block_id].house_price);
					board[player_two.current_block_id].house_count += 3;
				}
				else if( player_two.account < (board[player_two.current_block_id].price + 3*board[player_two.current_block_id].house_price) ) { // if player's account is not enought
					printf("You should sell a few properties.\n");
				}
				else { // otherwise, wrong choice
					printf("Wrong choice..\n");
				}
				temp=1;
			}
		}
		else if(choice == 7) { // if player wants to sell her/his property
			if(count == 1) {
				sell_property(board, &player_one);
				temp=2;
			}
			else if(count == 2) {
				sell_property(board, &player_two);
				temp=1;
			}			
		}
		tour++;
	} while( choice>0 && choice<8 && (player_one.account > 0 || player_two.account > 0) );
	if(player_one.account <= 0) {
		printf("%s won the game.\n", player_two.name);
	}
	else if(player_two.account <= 0) {
		printf("%s won the game.\n", player_one.name);
	}
}

int main() {
	srand(time(0));

	struct block board[20];
	struct player player_one, player_two;
	player_one.name = "Car";
	player_one.type = car;

	player_two.name = "Cap";
	player_two.type = cap;

	init_the_board(board);
	gameplay (board, player_one, player_two);
	return 0;
}