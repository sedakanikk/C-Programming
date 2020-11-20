#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define PROPERTY_COUNT 13
typedef enum block_type{start=0 ,property ,fortune ,tax ,punish}b_type;
typedef enum player_type{none=-1, car, cap}player_type;

typedef struct
{
    player_type type;
    int current_block_id;
    int owned_blocks[PROPERTY_COUNT];
    int account;
    int turn_to_wait;
    char *player_name;
} player;

typedef struct block
{
    int id;
    char * name;
    int price;
    int rent;
    int rent_1;
    int rent_2;
    int rent_3;
    int house_price;
    int h_count;
    player owner;
    b_type type;
    struct block *next;
} block;

// for fortune card
typedef enum {free_house=1, time_travel, garnishment, generosity, treasure_hunter}card_type;

typedef struct
{
    card_type type;
} fortune_card;


void after_dice_menu(block board[24], player* current_player, player* other);

// rolls a dice
int roll_dice()
{
    int i=rand()%6+1;
    return i;
}
// to show user properties
void show_property_deed(block board[24])
{
    int exit_flag=0,i,selection;
    while (exit_flag==0)
    {
        printf("Please select a property to see details:\n");
        for (i = 0; i < 24; ++i) {
            if (board[i].type==property)
                printf("%d -\t%s \n",board[i].id,board[i].name);
        }
        printf("0 -\tExit\n");
        scanf("%d",&selection);
        if (selection==0)
            exit_flag=1;
        else {
            if (selection > 0 && selection < 24 && board[selection].type == property) {
                printf("\n\n---------------------------------\n");
                if (strlen(board[selection].name) < 8)
                    printf("|\t\t%s\t\t|\n", board[selection].name);
                else
                    printf("|\t    %s\t\t|\n", board[selection].name);
                printf("---------------------------------\n");
                printf("|\tRent \t\t%d$\t|\n", board[selection].rent);
                printf("|\tRent 1 H \t%d$\t|\n", board[selection].rent_1);
                printf("|\tRent 2 H \t%d$\t|\n", board[selection].rent_2);
                printf("|\tRent 3 H \t%d$\t|\n", board[selection].rent_3);
                printf("---------------------------------\n");
                printf("|\tHouse Price \t%d$\t|\n", board[selection].house_price);
                printf("|\tHouse count \t%d\t|\n", board[selection].h_count);
                printf("---------------------------------\n\n\n");
            } else printf("\nWrong Selection! Please Try Again.\n\n");
        }
    }
}
// to show user the board
void show_board(block board[24], player player_one, player player_two)
{
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    int i=0,space_flag=0;
    for (i=0;i<7;i++)
    {
        if (strlen(board[i].name)<8)
            printf("|\t%s\t\t",board[i].name);
        else
            printf("|\t%s\t",board[i].name);
    }
    printf("|\n");
    for (i=0;i<7;i++)
    {
        if (board[i].type==property || board[i].type==tax)
            printf("|\t%d$ \t\t",board[i].price);
        else if (strlen(board[i].name)<8)
            printf("|\t     \t\t");
        else
            printf("|\t\t \t");
    }
    printf("|\n");
    for (i=0;i<7;i++)
    {
        space_flag=0;
        printf("|\t");
        if (i==player_one.current_block_id && i==player_two.current_block_id)
        {
            printf("%s---%s \t",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {
            if (i == player_one.current_block_id) {
                printf("%s \t\t", player_one.player_name);
                space_flag = 1;
            }
            if (i == player_two.current_block_id) {
                printf("%s \t\t", player_two.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(board[i].name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }
    }
    printf("|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    //Middle
    for (i=1;i<6;i++)
    {
        //Names

        if (strlen(board[24-i].name)<8)
            printf("|\t%s\t\t|",board[24-i].name);
        else
            printf("|\t%s\t|",board[24-i].name);
        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");

        if (strlen(board[i+6].name)<8)
            printf("|\t%s\t\t|",board[i+6].name);
        else
            printf("|\t%s\t|",board[i+6].name);
        printf("\n");
        //prices
        if (board[24-i].type==property || board[24-i].type==tax)
            printf("|\t%d$ \t\t|",board[24-i].price);
        else if (strlen(board[24-i].name)<8)
            printf("|\t     \t|");
        else
            printf("|\t\t \t|");


        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");

        if (board[6+i].type==property || board[6+i].type==tax)
            printf("|\t%d$ \t\t",board[6+i].price);
        else if (strlen(board[6+i].name)<8)
            printf("|\t     \t");
        else
            printf("|\t\t \t");

        printf("|\n");
        //spaces

        space_flag=0;
        printf("|\t");
        if (24-i==player_one.current_block_id && 24-i==player_two.current_block_id)
        {
            printf("%s---%s \t|",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {
            if (24 - i == player_one.current_block_id) {
                printf("%s \t\t|", player_one.player_name);
                space_flag = 1;
            }
            if (24 - i == player_two.current_block_id) {
                printf("%s \t\t|", player_two.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(board[24-i].name)<8)
                printf("\t\t|");
            else
                printf("    \t\t|");
        }

        printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
        space_flag=0;
        printf("|\t");
        if (6+i==player_one.current_block_id && 6+i==player_two.current_block_id)
        {
            printf("%s---%s \t",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {

            if (6+i==player_one.current_block_id)
            {
                printf("%s \t\t",player_one.player_name);
                space_flag=1;
            }
            if (6+i==player_two.current_block_id)
            {
                printf("%s \t\t",player_two.player_name);
                space_flag=1;
            }
        }

        if (space_flag==0) {
            if (strlen(board[6+i].name)<8)
                printf("\t\t");
            else
                printf("    \t\t");
        }

        printf("|\n");
        if (i!=5) {
            printf("-------------------------");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
            printf("-------------------------");
            printf("\n");
        }

    }
    //bottom row
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
    for (i=18;i>=12;i--)
    {
        if (strlen(board[i].name)<8)
            printf("|\t%s\t\t",board[i].name);
        else
            printf("|\t%s\t",board[i].name);
    }
    printf("|\n");
    for (i=18;i>=12;i--)
    {
        if (board[i].type==property || board[i].type==tax)
            printf("|\t%d$ \t\t",board[i].price);
        else if (strlen(board[i].name)<8)
            printf("|\t     \t\t");
        else
            printf("|\t\t \t");
    }
    printf("|\n");
    for (i=18;i>=12;i--)
    {
        space_flag=0;
        printf("|\t");
        if (i==player_one.current_block_id && i==player_two.current_block_id)
        {
            printf("%s---%s \t",player_one.player_name,player_two.player_name);
            space_flag=1;
        }
        else {
            if (i == player_one.current_block_id) {
                printf("%s \t\t", player_one.player_name);
                space_flag = 1;
            }
            if (i == player_two.current_block_id) {
                printf("%s \t\t", player_two.player_name);
                space_flag = 1;
            }
        }
        if (space_flag==0) {
            if (strlen(board[i].name)<8)
                printf("     \t\t");
            else
                printf(" \t\t");
        }

    }
    printf("|\n");
    printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
}
// for linkedlist 
void init_board_linkedList(block* board_linked) {
    block *other;
    block *before;


    block temp;
    player temp_player;

    temp_player.type=none;
    board_linked->id=0;
    board_linked->name="Start";
    board_linked->price=0;
    board_linked->rent=0;
    board_linked->rent_1=0;
    board_linked->rent_2=0;
    board_linked->rent_3=0;
    board_linked->owner=temp_player;
    board_linked->house_price=0;
    board_linked->h_count=0;
    board_linked->type=start;

    before = board_linked;

    other = (block*)malloc(sizeof(block));
    other->id=1;
    other->name="Esenyurt";
    other->price=16000;
    other->rent=800;
    other->rent_1=4000;
    other->rent_2=9000;
    other->rent_3=25000;
    other->house_price=10000;
    other->h_count=0;
    other->type=property;
    other->owner=temp_player;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=2;
    other->name="Car park";
    other->price=1500;
    other->rent=0;
    other->rent_1=0;
    other->rent_2=0;
    other->rent_3=0;
    other->house_price=0;
    other->h_count=0;
    other->type=tax;
    other->owner=temp_player;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=3;
    other->name="Fortune Card";
    other->price=0;
    other->rent=0;
    other->rent_1=0;
    other->rent_2=0;
    other->rent_3=0;
    other->owner=temp_player;
    other->house_price=0;
    other->h_count=0;
    other->type=fortune;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=4;
    other->name="Tuzla";
    other->price=16500;
    other->rent=850;
    other->rent_1=4250;
    other->rent_2=9500;
    other->rent_3=26000;
    other->owner=temp_player;
    other->house_price=12000;
    other->h_count=0;
    other->type=property;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=5;
    other->name="Arnavutkoy";
    other->price=17000;
    other->rent=850;
    other->rent_1=4500;
    other->rent_2=10000;
    other->rent_3=28000;
    other->house_price=12000;
    other->owner=temp_player;
    other->h_count=0;
    other->type=property;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=6;
    other->name="Wait 2 turn";
    other->price=2;
    other->rent=0;
    other->rent_1=0;
    other->rent_2=0;
    other->rent_3=0;
    other->owner=temp_player;
    other->house_price=0;
    other->h_count=0;
    other->type=punish;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=7;
    other->name="Catalca";
    other->price=20000;
    other->rent=1000;
    other->rent_1=5000;
    other->rent_2=12000;
    other->rent_3=30000;
    other->house_price=13000;
    other->owner=temp_player;
    other->h_count=0;
    other->type=property;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=8;
    other->name="Beykoz";
    other->price=23000;
    other->rent=1100;
    other->rent_1=5500;
    other->rent_2=12500;
    other->rent_3=33000;
    other->house_price=13000;
    other->owner=temp_player;
    other->h_count=0;
    other->type=property;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=9;
    other->name="Fortune Card";
    other->price=0;
    other->rent=0;
    other->rent_1=0;
    other->rent_2=0;
    other->rent_3=0;
    other->owner=temp_player;
    other->house_price=0;
    other->h_count=0;
    other->type=fortune;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=10;
    other->name="Car fix";
    other->price=1750;
    other->rent=0;
    other->rent_1=0;
    other->rent_2=0;
    other->rent_3=0;
    other->owner=temp_player;
    other->house_price=0;
    other->h_count=0;
    other->type=tax;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=11;
    other->name="Maltepe";
    other->price=30000;
    other->rent=1350;
    other->rent_1=7000;
    other->rent_2=15000;
    other->rent_3=40000;
    other->house_price=15000;
    other->owner=temp_player;
    other->h_count=0;
    other->type=property;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=12;
    other->name="Bills";
    other->price=2000;
    other->rent=0;
    other->rent_1=0;
    other->rent_2=0;
    other->rent_3=0;
    other->owner=temp_player;
    other->house_price=0;
    other->h_count=0;
    other->type=tax;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=13;
    other->name="Sisli";
    other->price=33000;
    other->rent=1500;
    other->rent_1=8000;
    other->rent_2=16000;
    other->rent_3=42000;
    other->house_price=16000;
    other->owner=temp_player;
    other->h_count=0;
    other->type=property;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=14;
    other->name="Oil";
    other->price=2250;
    other->rent=0;
    other->rent_1=0;
    other->rent_2=0;
    other->rent_3=0;
    other->owner=temp_player;
    other->house_price=0;
    other->h_count=0;
    other->type=tax;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=15;
    other->name="Fortune Card";
    other->price=0;
    other->rent=0;
    other->rent_1=0;
    other->rent_2=0;
    other->rent_3=0;
    other->owner=temp_player;
    other->house_price=0;
    other->h_count=0;
    other->type=fortune;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=16;
    other->name="Atasehir";
    other->price=35000;
    other->rent=1600;
    other->rent_1=8500;
    other->rent_2=17000;
    other->rent_3=45000;
    other->house_price=17000;
    other->owner=temp_player;
    other->h_count=0;
    other->type=property;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=17;
    other->name="Sariyer";
    other->price=40000;
    other->rent=1750;
    other->rent_1=9500;
    other->rent_2=19000;
    other->rent_3=48000;
    other->house_price=19000;
    other->owner=temp_player;
    other->h_count=0;
    other->type=property;
    before->next = other;
    before =other;
    other = (block*)malloc(sizeof(block));

    other->id=18;
    other->name="Wait 1 turn";
    other->price=1;
    other->rent=0;
    other->rent_1=0;
    other->rent_2=0;
    other->rent_3=0;
    other->house_price=0;
    other->owner=temp_player;
    other->h_count=0;
    other->type=punish;
    before->next = other;
    before = other;

    other = (block*)malloc(sizeof(block));
    other->id=19;
    other->name="Kadikoy";
    other->price=43000;
    other->rent=1900;
    other->rent_1=11000;
    other->rent_2=21500;
    other->rent_3=55000;
    other->house_price=23000;
    other->owner=temp_player;
    other->h_count=0;
    other->type=property;
    before->next = other;
    before = other;

    other = (block*)malloc(sizeof(block));
    other->id=20;
    other->name="Besiktas";
    other->price=60000;
    other->rent=2500;
    other->rent_1=15000;
    other->rent_2=28000;
    other->rent_3=60000;
    other->house_price=30000;
    other->owner=temp_player;
    other->h_count=0;
    other->type=property;
    before->next = other;
    before = other;

    other = (block*)malloc(sizeof(block));
    other->id=21;
    other->name="Fortune Card";
    other->price=0;
    other->rent=0;
    other->rent_1=0;
    other->rent_2=0;
    other->rent_3=0;
    other->house_price=0;
    other->owner=temp_player;
    other->h_count=0;
    other->type=fortune;
    before->next = other;
    before = other;

    other = (block*)malloc(sizeof(block));
    other->id=22;
    other->name="Vocation";
    other->price=5000;
    other->rent=0;
    other->rent_1=0;
    other->rent_2=0;
    other->rent_3=0;
    other->owner=temp_player;
    other->house_price=0;
    other->h_count=0;
    other->type=tax;
    before->next = other;
    before = other;

    other = (block*)malloc(sizeof(block));
    other->id=23;
    other->name="Bebek";
    other->price=70000;
    other->rent=3500;
    other->rent_1=20000;
    other->rent_2=35500;
    other->rent_3=65000;
    other->house_price=35000;
    other->owner=temp_player;
    other->h_count=0;
    other->type=property;
    before->next = other;
    before = other;
}

// initialized every data for array 
void init_board(block board[24])
{
    block temp;
    player temp_player;
    temp_player.type=none;

    temp.id=0;
    temp.name="Start";
    temp.price=0;
    temp.rent=0;
    temp.rent_1=0;
    temp.rent_2=0;
    temp.rent_3=0;
    temp.owner=temp_player;
    temp.house_price=0;
    temp.h_count=0;
    temp.type=start;
    board[temp.id]=temp;

    temp.id=2;
    temp.name="Car park";
    temp.price=1500;
    temp.type=tax;
    board[temp.id]=temp;

    temp.id=3;
    temp.name="Fortune Card";
    temp.price=0;
    temp.rent=0;
    temp.rent_1=0;
    temp.rent_2=0;
    temp.rent_3=0;
    temp.owner=temp_player;
    temp.house_price=0;
    temp.h_count=0;
    temp.type=fortune;
    board[temp.id]=temp;

    temp.id=9;
    temp.name="Fortune Card";
    board[temp.id]=temp;

    temp.id=15;
    temp.name="Fortune Card";
    board[temp.id]=temp;

    temp.id=21;
    temp.name="Fortune Card";
    board[temp.id]=temp;

    temp.id=10;
    temp.name="Car fix";
    temp.price=1750;
    temp.type=tax;
    board[temp.id]=temp;

    temp.name="Bills";
    temp.id=12;
    temp.price=2000;
    board[temp.id]=temp;

    temp.name="Oil";
    temp.id=14;
    temp.price=2250;
    board[temp.id]=temp;
    
    temp.name="Vocation";
    temp.id=22;
    temp.price=5000;
    board[temp.id]=temp;

    temp.type=punish;
    temp.name="Wait 2 turn";
    temp.price=2;
    temp.id=6;
    board[temp.id]=temp;

    temp.name="Wait 1 turn";
    temp.price=1;
    temp.id=18;
    board[temp.id]=temp;

    temp.id=1;
    temp.name="Esenyurt";
    temp.price=16000;
    temp.rent=800;
    temp.rent_1=4000;
    temp.rent_2=9000;
    temp.rent_3=25000;
    temp.house_price=10000;
    temp.h_count=0;
    temp.type=property;
    board[temp.id]=temp;

    temp.id=4;
    temp.name="Tuzla";
    temp.price=16500;
    temp.rent=850;
    temp.rent_1=4250;
    temp.rent_2=9500;
    temp.rent_3=26000;
    temp.house_price=12000;
    temp.h_count=0;
    temp.type=property;
    board[temp.id]=temp;

    temp.id=5;
    temp.name="Arnavutkoy";
    temp.price=17000;
    temp.rent=850;
    temp.rent_1=4500;
    temp.rent_2=10000;
    temp.rent_3=28000;
    temp.house_price=12000;
    temp.h_count=0;
    temp.type=property;
    board[temp.id]=temp;

    temp.id=7;
    temp.name="Catalca";
    temp.price=20000;
    temp.rent=1000;
    temp.rent_1=5000;
    temp.rent_2=12000;
    temp.rent_3=30000;
    temp.house_price=13000;
    temp.h_count=0;
    temp.type=property;
    board[temp.id]=temp;

    temp.id=8;
    temp.name="Beykoz";
    temp.price=23000;
    temp.rent=1100;
    temp.rent_1=5500;
    temp.rent_2=12500;
    temp.rent_3=33000;
    temp.house_price=13000;
    temp.h_count=0;
    temp.type=property;
    board[temp.id]=temp;

    temp.id=11;
    temp.name="Maltepe";
    temp.price=30000;
    temp.rent=1350;
    temp.rent_1=7000;
    temp.rent_2=15000;
    temp.rent_3=40000;
    temp.house_price=15000;
    temp.h_count=0;
    temp.type=property;
    board[temp.id]=temp;

    temp.id=13;
    temp.name="Sisli";
    temp.price=33000;
    temp.rent=1500;
    temp.rent_1=8000;
    temp.rent_2=16000;
    temp.rent_3=42000;
    temp.house_price=16000;
    temp.h_count=0;
    temp.type=property;
    board[temp.id]=temp;

    temp.id=16;
    temp.name="Atasehir";
    temp.price=35000;
    temp.rent=1600;
    temp.rent_1=8500;
    temp.rent_2=17000;
    temp.rent_3=45000;
    temp.house_price=17000;
    temp.h_count=0;
    temp.type=property;
    board[temp.id]=temp;

    temp.id=17;
    temp.name="Sariyer";
    temp.price=40000;
    temp.rent=1750;
    temp.rent_1=9500;
    temp.rent_2=19000;
    temp.rent_3=48000;
    temp.house_price=19000;
    temp.h_count=0;
    temp.type=property;
    board[temp.id]=temp;

    temp.id=19;
    temp.name="Kadikoy";
    temp.price=43000;
    temp.rent=1900;
    temp.rent_1=11000;
    temp.rent_2=21500;
    temp.rent_3=55000;
    temp.house_price=23000;
    temp.h_count=0;
    temp.type=property;
    board[temp.id]=temp;

    temp.id=20;
    temp.name="Besiktas";
    temp.price=60000;
    temp.rent=2500;
    temp.rent_1=15000;
    temp.rent_2=28000;
    temp.rent_3=60000;
    temp.house_price=30000;
    temp.h_count=0;
    temp.type=property;
    board[temp.id]=temp;

    temp.id=23;
    temp.name="Bebek";
    temp.price=70000;
    temp.rent=3500;
    temp.rent_1=20000;
    temp.rent_2=35500;
    temp.rent_3=65000;
    temp.house_price=35000;
    temp.h_count=0;
    temp.type=property;
    board[temp.id]=temp;
}
// to show player's properties
void show_player_properties(block board[24], player current_player)
{
    int i,counter=0,selection;
    while (selection!=0) {
        printf("----------------------------------------\n");
        for (i = 0; i < PROPERTY_COUNT; i++) {
            if (current_player.owned_blocks[i] != -1) {
                printf("%d - %s\n", board[current_player.owned_blocks[i]].id,
                       board[current_player.owned_blocks[i]].name);
                counter++;
            }
        }
        if (counter == 0)
        {
            printf("You have not owned any property yet.\n");
            printf("----------------------------------------\n");
            selection=0;
        }
        else
        {
            printf("0 - Back \n");
            printf("----------------------------------------\n");
            printf("Please select an property to see details.\n");
            scanf("%d", &selection);

            if (selection!=0) {
                if (board[selection].owner.type != current_player.type)
                    printf("You made a wrong selection!\n");
                else {
                    printf("\n\n---------------------------------\n");
                    if (strlen(board[selection].name) < 8)
                        printf("|\t\t%s\t\t|\n", board[selection].name);
                    else
                        printf("|\t    %s\t\t|\n", board[selection].name);
                    printf("---------------------------------\n");
                    printf("|\tRent \t\t%d$\t|\n", board[selection].rent);
                    printf("|\tRent 1 H \t%d$\t|\n", board[selection].rent_1);
                    printf("|\tRent 2 H \t%d$\t|\n", board[selection].rent_2);
                    printf("|\tRent 3 H \t%d$\t|\n", board[selection].rent_3);
                    printf("---------------------------------\n");
                    printf("|\tHouse Price \t%d$\t|\n", board[selection].house_price);
                    printf("|\tHouse count \t%d\t|\n", board[selection].h_count);
                    printf("---------------------------------\n\n\n");
                }
            }
        }
    }
}
// to build a house or houses depend on player's choice 
int build_house(block* current_block, player* current_player)
{
    int flag=0;
    if (current_player->type==current_block->owner.type)
    {
        if (current_block->h_count<3)
        {
            if (current_block->house_price<=current_player->account)
            {
                flag=1;
                current_player->account-=current_block->house_price;
                current_block->h_count+=1;
                printf("Congratiulations! You have built a house on %s.\n",current_block->name);
            }
            else
                printf("You don't have enough money to build house!\n");
        }
        else
            printf("You can't buy more than 3 houses in a property!\n");
    }
    else
        printf("You don't have permission to build house on this property!\n ");
    return flag;
}
// calculates number of properties of current player's
int count_properties(player current_player)
{
    int i,count=0;
    for (i=0;i<PROPERTY_COUNT;i++)
    {
        if (current_player.owned_blocks[i]!=-1)
            count++;
    }
    return count;
}
// if player want to sell or computer has to sell property 
void sell_property(block board[24], player* current_player)
{
    int property_id,flag=0,is_owned=-1,i,index,counter=0;
        if (current_player->type == 0 && count_properties(*current_player)!=0) { // if car
            for (i = 0; i < PROPERTY_COUNT; i++) {
                if (current_player->owned_blocks[i] != -1) {
                    printf("%d - %s\n", board[current_player->owned_blocks[i]].id,
                           board[current_player->owned_blocks[i]].name);
                    counter++;
                }
            }
            printf("0 - Back\n");
            printf("Please select to sell the property:\n");

            scanf("%d",&property_id);
            if (property_id!=0)
            {
                for(i=0;i<PROPERTY_COUNT;i++)
                {
                    if (current_player->owned_blocks[i]==property_id)
                    {
                        is_owned=1;
                        index=i;
                        break;
                    }
                }
                if(is_owned!=-1)
                {
                    current_player->owned_blocks[index]=-1;
                    player temp;
                    board[property_id].owner.type=none;
                    if(board[property_id].h_count==0)current_player->account+=board[property_id].price/2;
                    if(board[property_id].h_count==1)
                    {
                        current_player->account+=(board[property_id].price+board[property_id].house_price)/2;
                    }
                    if(board[property_id].h_count==2)
                    {
                        current_player->account+=(board[property_id].price+(2*board[property_id].house_price))/2;
                    }
                    if(board[property_id].h_count==3)
                    {
                        current_player->account+=(board[property_id].price+(3*board[property_id].house_price))/2;
                    }
                }
            }
        } 
        else if (current_player->type == 1 && count_properties(*current_player)!=0) { // if computer, cap
            int max_id=0, max=0;
            counter=0;
            for (i = 0; i < PROPERTY_COUNT; i++) {
                if (current_player->owned_blocks[i] != -1) {
                    printf("%d - %s\n", board[current_player->owned_blocks[i]].id,
                           board[current_player->owned_blocks[i]].name);
                    counter++;
                    if(board[current_player->owned_blocks[i]].price > max) {
                        max = board[current_player->owned_blocks[i]].price;
                        max_id = board[current_player->owned_blocks[i]].id;
                    }
                }

            }
            printf("Selected to sell the property:\n");
            printf("%d - %s\n", max_id, board[max_id].name);

            if (max_id != 0)
            {
                for(i=0;i<PROPERTY_COUNT;i++)
                {
                    if (current_player->owned_blocks[i]==max_id)
                    {
                        is_owned=1;
                        index=i;
                        break;
                    }
                }
                if(is_owned!=-1)
                {
                    current_player->owned_blocks[index]=-1;
                    player temp;
                    board[max_id].owner.type=none;
                    if(board[max_id].h_count==0)current_player->account+=board[max_id].price/2;
                    if(board[max_id].h_count==1)
                    {
                        current_player->account+=(board[max_id].price+board[max_id].house_price)/2;
                    }
                    if(board[max_id].h_count==2)
                    {
                        current_player->account+=(board[max_id].price+(2*board[max_id].house_price))/2;
                    }
                    if(board[max_id].h_count==3)
                    {
                        current_player->account+=(board[max_id].price+(3*board[max_id].house_price))/2;
                    }
                }
            }
        } 
        else
            printf("You don't have any property to sell.\n");
}

int insufficient_fund(block board[24], player* current_player,int required_money)
{
    int selection,flag=1;
    if(current_player->type == 0) { // if cap
        while (selection!=4 && current_player->account<required_money && count_properties(*current_player)!=0)
        {
            printf("You don't have enough money to continue your transaction.You need %d$ more. Please select an option to continue: \n",required_money-current_player->account);
            printf("1- Sell Property\n");
            printf("2- Show my Properties\n");
            printf("3- Show my Account\n");
            printf("0- Back\n");
            scanf("%d",&selection);
            switch (selection)
            {
                case 1:
                    sell_property(board,current_player);
                    break;
                case 2:
                    show_player_properties(board,*current_player);
                    break;
                case 3:
                    printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
                    break;
                case 0:
                    flag=0;
                    break;
                default:
                    printf("You made a wrong selection!\n");
                    break;

            }
        }
    }
    else if(current_player->type == 1) { // if computer
        while (selection!=4 && current_player->account<required_money && count_properties(*current_player)!=0)
        {
            printf("Computer don't have enough money to continue its transaction. It need %d$ more. Selected an option to continue: \n",required_money-current_player->account);
            printf("1- Sell Property\n");
            printf("2- Show my Properties\n");
            printf("3- Show my Account\n");
            printf("0- Back\n");
            selection = 1;
            switch (selection)
            {
                case 1:
                    sell_property(board,current_player);
                    break;
                case 2:
                    show_player_properties(board,*current_player);
                    break;
                case 3:
                    printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
                    break;
                case 0:
                    flag=0;
                    break;
                default:
                    printf("You made a wrong selection!\n");
                    break;
            }
        }
    }
    return flag;
}
// if player is on other player's property, then player have to pay rent to other player
void pay_rent(block board[24], player* current_player,player * owner)
{
    int rent=0,owned_property_count;
    rent=board[current_player->current_block_id].rent;
    if (board[current_player->current_block_id].h_count == 1)
        rent=board[current_player->current_block_id].rent_1;
    if (board[current_player->current_block_id].h_count == 2)
        rent=board[current_player->current_block_id].rent_2;
    if (board[current_player->current_block_id].h_count == 3)
        rent=board[current_player->current_block_id].rent_3;
    if (rent>current_player->account)
    {
        owned_property_count=count_properties(*current_player);
        while(rent>current_player->account && owned_property_count!=0)
        {
            insufficient_fund(board,current_player,rent);
            owned_property_count=count_properties(*current_player);
        }
    }
    if (rent<current_player->account)
    {
        current_player->account-=rent;
        owner->account+=rent;
    } else
        current_player->account=0;
}

void add_to_owned(player* current_player)
{
    int i;
    for ( i = 0; i < PROPERTY_COUNT; ++i) {
        if (current_player->owned_blocks[i]==-1) {
            current_player->owned_blocks[i] = current_player->current_block_id;
            printf("Current block id %d\n",current_player->current_block_id);
            break;
        }
    }
    printf("\n");
}

void copy_owner(player* old, player* new)
{
    int i;
    old->type=new->type;
    old->account=new->account;
    old->turn_to_wait=new->turn_to_wait;
    old->player_name=new->player_name;
    old->current_block_id=new->current_block_id;
    for ( i = 0; i < PROPERTY_COUNT; ++i) {
        old->owned_blocks[i]=new->owned_blocks[i];
    }
}
// if player wants to buy property which is on
void buy_property(block* current_block, player* current_player)
{
    if (current_block->price<=current_player->account)
    {
        current_player->account-=current_block->price;
        copy_owner(&current_block->owner,current_player);
        add_to_owned(current_player);

        printf("Congratiulations! You have buy %s.\n",current_block->name);
        printf("You left %d$ in your account.\n",current_player->account);

    }
    else
        printf("You don't have enough money to buy this property!\n");
}
// if player bought a property then, asks player to if player wants to build a house 
void house_dialog(block board[24], player* current_player)
{
    int house_flag=1,selection,insuf_flag=1,build_flag=1;
    while (house_flag && build_flag) {
        printf("Do you want to build house on %s ?\n",
               board[current_player->current_block_id].name);
        printf("1- Yes\n");
        printf("2- No\n");
        scanf("%d", &selection);
        if (selection == 1) {

            if (current_player->account < board[current_player->current_block_id].house_price) {
                while (count_properties(*current_player)!=0 && current_player->account<board[current_player->current_block_id].house_price && insuf_flag==1)
                    insuf_flag=insufficient_fund(board,current_player,board[current_player->current_block_id].house_price);
            }
            if (current_player->account >= board[current_player->current_block_id].house_price)
                build_flag=build_house(&board[current_player->current_block_id], current_player);
            else
                house_flag=0;
        } else
            house_flag=0;
    }
}
// chooce a random number for fortune cards
int pick_card() {
    int card = rand()%5+1;
    return card;
}
// if fortune card is free house, then builds a free house
int build_free_house(block* current_block, player* current_player)
{
    int flag=0;
    if (current_player->type==current_block->owner.type)
    {
        if (current_block->h_count<3)
        {
            flag=1;
            current_player->account-=current_block->house_price;
            current_block->h_count+=1;
            printf("Congratiulations! You have built a house on %s.\n",current_block->name);

        }
    }
    else
        printf("You don't have permission to build house on this property!\n ");
    return flag;
}
// if player is on fortune card block, then does something 
void fortune_cards(block board[24], player* current_player, player* other) {
    fortune_card card;
    int no = pick_card();

    switch (no)
    {
        case 1:
            card.type = 1;
            printf("Your fortune card is Free House.\n");
            int count = count_properties(*current_player);
            if(count == 0)
                printf("%s doesn't have any property. So, can not build a house.\n", current_player->player_name);
            else {
                int ran = 0;
                while( build_free_house(&board[current_player->owned_blocks[ran]], current_player) == 0 ) {
                    ran++;
                    if(ran >= count){
                        printf("Your house count is full in every property.\n");
                        break;
                    }
                }
            }
            break;
        case 2:
            card.type = 2;
            printf("Your fortune card is Time Travel.\n");
            int dice = roll_dice();
            printf("Computer rolled the dice: %d\n", dice);
            if(dice>=1 && dice<=3) {
                current_player->current_block_id = (current_player->current_block_id + 2);
                printf("%s's current position is %s after forwarded by 2 block from Fortune Card.\n", 
                        current_player->player_name, board[current_player->current_block_id].name);
            }
            else {
                current_player->current_block_id = (current_player->current_block_id - 2);
                printf("%s's current position is %s after backwarded by 2 block from Fortune Card.\n", 
                        current_player->player_name, board[current_player->current_block_id].name);
            }
            after_dice_menu(board, current_player, other);
            break;
        case 3:
            card.type = 3;
            printf("Your fortune card is Garnishment.\n");
            printf("%s paid 5000$ to the bank.\n", current_player->player_name);
            current_player->account -= 5000;
            break;
        case 4:
            card.type = 4;
            printf("Your fortune card is Generosity.\n");
            printf("%s gave 10000$ to %s.\n", current_player->player_name, other->player_name);
            current_player->account -= 10000;
            other->account += 10000;
            break;
        case 5:
            card.type = 5;
            printf("Your fortune card is Treasure Hunter.\n");
            printf("%s took 20000$ from the bank.\n", current_player->player_name);
            current_player->account += 20000;
            break;
    }
}
// game started
void after_dice_menu(block board[24], player* current_player, player* other)
{
    int selection,insuf_flag=1;
    switch (board[current_player->current_block_id].type)
    {
        case property:
            printf("%s has arrived %s \n",current_player->player_name,board[current_player->current_block_id].name);
            if (board[current_player->current_block_id].owner.type == -1)
            {
                if(current_player->type == 1) {//if computer
                    int i, sum_of_properties=0, number_of_properties=0, average=0;
                    for(i=0; i<24; i++) {
                        if(board[i].type == 1) { //if property
                            sum_of_properties += board[i].price;
                            number_of_properties++;
                        }
                    }
                    average = sum_of_properties / number_of_properties;
                    if(board[current_player->current_block_id].price < average) {
                        selection = 1;
                    }
                    else {
                        int res = roll_dice();
                        int next_block=(current_player->current_block_id + res);
                        printf("Computer rolled the dice: %d\n", res);
                        if(res>=1 && res<=3) {
                            selection = 1;
                        }
                        else{
                            break;
                        }
                    }
                }
                else { //if player
                    printf("Do you want to buy %s ?\n",board[current_player->current_block_id].name);
                    printf("1- Yes\n");
                    printf("2- No\n");
                    scanf("%d",&selection);
                }
                if (selection == 1)
                {
                    if (current_player->account < board[current_player->current_block_id].price)
                    {
                        while (count_properties(*current_player)!=0 && current_player->account < board[current_player->current_block_id].price)
                        {
                            insufficient_fund(board, current_player, board[current_player->current_block_id].price);
                        }
                    }
                    buy_property(&board[current_player->current_block_id],current_player);
                    if (current_player->type == 0 && current_player->type == board[current_player->current_block_id].owner.type) { // if car
                        house_dialog(board,current_player);
                    }
                    else if (current_player->type == 1 && current_player->type == board[current_player->current_block_id].owner.type && 
                            count_properties(*current_player) == (PROPERTY_COUNT-1)/3) { // if computer
                        int res = roll_dice();
                        printf("Computer rolled the dice: %d\n", res);
                        if(res>=1 && res<=3) {
                            if (current_player->account < board[current_player->current_block_id].house_price) {
                                while (count_properties(*current_player)!=0 && current_player->account<board[current_player->current_block_id].house_price && insuf_flag==1)
                                    insufficient_fund(board,current_player,board[current_player->current_block_id].house_price);
                            }
                            build_house(&board[current_player->current_block_id], current_player);
                        }
                    }
                }
            }
            else if(current_player->type == 0 && board[current_player->current_block_id].owner.type == current_player->type) {
                house_dialog(board, current_player);
            }
            else if(current_player->type == 1 && board[current_player->current_block_id].owner.type == current_player->type && 
                count_properties(*current_player) == (PROPERTY_COUNT-1)/3 ) {
                int res = roll_dice();
                printf("Computer rolled the dice: %d\n", res);
                if(res>=1 && res<=3) {
                    if (current_player->account < board[current_player->current_block_id].house_price) {
                        while (count_properties(*current_player)!=0 && current_player->account<board[current_player->current_block_id].house_price)
                            insufficient_fund(board,current_player,board[current_player->current_block_id].house_price);
                    }
                    build_house(&board[current_player->current_block_id], current_player);
                }
            }
            else
                pay_rent(board,current_player,other);
            break;
        case fortune:
            printf("%s has arrived fortune card block. \n",current_player->player_name);
            fortune_cards(board, current_player, other);
            break;
        case tax:
            printf("%s has arrived tax block(%s)\n",current_player->player_name,board[current_player->current_block_id].name);
            while (count_properties(*current_player)!=0 && current_player->account<board[current_player->current_block_id].price) {
                insuf_flag = insufficient_fund(board, current_player,
                                               board[current_player->current_block_id].price);
                if (insuf_flag == 0 && current_player->account < board[current_player->current_block_id].price)
                    printf("You must pay your tax!\n");
            }
            if (current_player->account>board[current_player->current_block_id].price)
                current_player->account=current_player->account-board[current_player->current_block_id].price;
            else
                current_player->account=0;
            break;
        case punish:
            printf("%s has punished for %d turn. \n",current_player->player_name,board[current_player->current_block_id].price);
            current_player->turn_to_wait+=board[current_player->current_block_id].price;
            break;
    }
}
// to chooce an option
void turn(block board[24], player* current_player, player * other)
{
    int flag=1,next_block;
    while(flag)
    {
        int selection;
        printf("1 - Roll the dice\n");
        printf("2 - Show my account\n");
        printf("3 - Show my properties\n");
        printf("4 - Show property deeds\n");
        printf("5 - Buy Property\n");
        printf("6 - Buy house \n");
        printf("7 - Sell property\n");
        printf("Please select an option to continue (%s):\n",current_player->player_name);
        scanf("%d",&selection);
        switch(selection)
        {
            case 1:
                if (current_player->turn_to_wait==0) {
                    int res = roll_dice();
                    next_block=(current_player->current_block_id + res);
                    if(current_player->type == 0)
                        printf("Player rolled the dice: %d\n", res);
                    else if(current_player->type == 1)
                        printf("Computer rolled the dice: %d\n", res);
                    if (next_block>=24)current_player->account+=10000;
                    current_player->current_block_id = next_block % 24;
                    after_dice_menu(board,current_player,other);
                    flag = 0;
                } else
                {
                    printf("You need to wait %d turn to continue.\n",current_player->turn_to_wait);
                    current_player->turn_to_wait-=1;
                    flag=0;
                }
                break;
            case 2:
                printf("\n\nThere are %d $ in your account.\n\n",current_player->account);
                break;
            case 3:
                show_player_properties(board,*current_player);
                break;
            case 4:
                show_property_deed(board);
                break;
            case 5:
                if (board[current_player->current_block_id].type==property && board[current_player->current_block_id].owner.type==-1)
                    buy_property(&board[current_player->current_block_id],current_player);
                else
                    printf("You don't have permission to buy this block!\n");
                break;
            case 6:
                if (current_player->type==board[current_player->current_block_id].owner.type)
                    house_dialog(board,current_player);
                else
                    printf("You don't have permission to build house on this block!\n");
                break;
            case 7:
                sell_property(board,current_player);
                break;
            default:
                printf("Wrong selection!\n");
        }
    }
}

int check_end(player current_player)
{
    int owned_property_count=count_properties(current_player);
    if (current_player.account<=0 && owned_property_count==0)
        return 1;
    else 
        return 0;
}
// the game is starts from here
void play_game(block board[24], player* player_one, player* player_two)
{
    int is_end=0;
    printf("Welcome to Monopoly! Computer(%s) will roll the dice first.\n",player_one->player_name);
    while(is_end!=1)
    {
        printf("%s :%d$ , %s:%d$\n",player_one->player_name,player_one->account,player_two->player_name,player_two->account);
        turn(board,player_one,player_two);
        show_board(board,*player_one,*player_two);
        is_end=check_end(*player_one);
        if (is_end==0)
        {
            printf("%s :%d$ , %s:%d$\n",player_one->player_name,player_one->account,player_two->player_name,player_two->account);
            turn(board,player_two,player_one);
            show_board(board,*player_one,*player_two);
            is_end=check_end(*player_two);
            if (is_end==1)
                printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",player_two->player_name,player_two->player_name);
        } else
            printf("%s don't have enough money to payment, unfortunately %s lost the game!\n",player_one->player_name,player_one->player_name);

    }

}

void init_owned(player* current_player)
{
    int i;
    for (i=0;i<PROPERTY_COUNT;i++) {
        current_player->owned_blocks[i]=-1;
    }

}

int main() {

    //for linked list
    block *head;
    head = (block*)malloc(sizeof(block));
    init_board_linkedList(head);

    //for array
    block board[24];
    init_board(board);
    srand(time(NULL));
    player player_one,player_two;

    player_one.player_name="Cap";
    player_one.type=cap;
    player_one.current_block_id=0;
    player_one.turn_to_wait=0;
    player_one.account=100000;
    init_owned(&player_one);

    player_two.player_name="Car";
    player_two.type=car;
    player_two.current_block_id=0;
    player_two.turn_to_wait=0;
    player_two.account=100000;
    init_owned(&player_two);

    show_board(board,player_one,player_two);
    play_game(board,&player_one,&player_two);

    return 0;
}