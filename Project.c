#include <stdio.h>
#include <ncurses.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#define MAX_USERS 1000
#define FILENAME "users.txt"



char map[150][80];
    int level=1;
    int gold=0;
    int score=0;

    int player_x;
   int player_y;
   int player_color=1;

   int finish_games=0;

   int x_show_corridor[5][10000];

   int y_show_corridor[5][10000];

   int show_corridors=0;

    int player_health=100;

    int gorosnegy=0;

    int food_count=0;

    int lose_game=0;

    int finish_game=0;

    int loading_game=0;

    int game_difficulty=2;

    typedef struct{
    int x;
    int y;
    int length;
    int height;
    int door_1;
    int door_2;
    int room_type;
    }room;

   room  rooms[4][6];

   int show_rooms[4][6];

   int rams_number;

   time_t time_1;
   time_t time_2;
   time_t time_3;
   time_t time_4;
   time_t time_5;
   time_t time_6;

   time_t time_7;
   time_t time_8;
   time_t time_9;
   time_t time_10;
   time_t time_11;
   time_t time_12;
   time_t time_13;
   time_t time_14;
   time_t time_15;
   time_t time_16;

   time_t time_17;
   time_t time_18;
   time_t time_19;

   int x[6];
   int y[6];
   int length[6];
   int height[6];
   int door_1[6];
   int door_2[6];
   int x_pillar[6];
   int y_pillar[6];
   int x_gold[6];
   int y_gold[6];
   int x_step[6];
   int y_step[6];
   int x_food[6];
   int y_food[6];
   int x_trap[6];
   int y_trap[6];


   int rams_door_opened[5];

   int mace_count=1;
   int sword_count=0;
   int dagger_count=0;
   int magic_wand_count=0;
   int arrow_count=0;
   int speed_spell_count=0;
   int damage_spell_count=0;
   int health_spell_count=0;
   int ancient_key_count=0;

   int demon_health=5;
   int fire_health=10;
   int giant_health=15;
   int snake_health=20;
   int undeed_health=30;

   int selected_weapon=1;

   int speed_spell_effect=0;
   int damage_spell_effect=0;
   int health_spell_effect=0;

   time_t last_time;
   time_t current_time;
   time_t last_time_2;
   time_t current_time_2;

   char no_get='a';

   int giant_moves[7];
   int undeed_moves[7];
   int stop_giant[7];
   int stop_snake[7];
   int stop_undeed[7];


   int stair_x;
   int stair_y;



typedef struct {
    char map[150][80];
    int x_show_corridor[5][10000];
    int y_show_corridor[5][10000];
    int show_corridors;
    int player_x;
    int player_y;
    int level;
    int score;
    int gold;
    int player_health;
    int gorosnegy;
    int game_difficulty;
    int player_color;
    int selected_weapon;
    int mace_count;
    int sword_count;
    int dagger_count;
    int arrow_count;
    int magic_wand_count;
    int speed_spell_count;
    int damage_spell_count;
    int health_spell_count;
    int rams_door_opened[5];
    int show_rooms[4][6];
    room rooms[4][6];
} gamedata;






   void generate_map_1(){
   for(int i=0;i<150;i++){
   for(int j=0;j<80;j++){
   map[i][j]=' ';

}
}
}



   void using_food_page(){



   start_color();

   init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);

   int temp=(current_time-last_time);
   int temp_2=(current_time_2-last_time_2);

   int h=0;

   while(h==0){

clear();


   current_time=time(NULL);
   last_time=(current_time-temp);
   current_time_2=time(NULL);
   last_time_2=(current_time_2-temp_2);

   mvprintw(20,10,"foods_number : %d",food_count);

   mvprintw(24,10,"press u to use food");
   mvprintw(26,10,"press b to back to game");

   switch(gorosnegy){

   case(0):{
   attron(COLOR_PAIR(3));
   mvprintw(22,10,"🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩");
   attroff(COLOR_PAIR(3));
   break;
   }
   case(10):case(5):case(15):{
   attron(COLOR_PAIR(3));
   mvprintw(22,10,"🟩🟩🟩🟩🟩🟩🟩🟩🟩");
   attroff(COLOR_PAIR(3));
   break;
   }
   case(20):case(25):{
   attron(COLOR_PAIR(3));
   mvprintw(22,10,"🟩🟩🟩🟩🟩🟩🟩🟩");
   attroff(COLOR_PAIR(3));
   break;
   }
   case(30):case(35):{
   attron(COLOR_PAIR(5));
   mvprintw(22,10,"🟨🟨🟨🟨🟨🟨🟨");
   attroff(COLOR_PAIR(5));
   break;
   }
   case(40):case(45):{
   attron(COLOR_PAIR(5));
   mvprintw(22,10,"🟨🟨🟨🟨🟨🟨");
   attroff(COLOR_PAIR(5));
   break;
   }
case(50):case(55):{
   attron(COLOR_PAIR(5));
   mvprintw(22,10,"🟨🟨🟨🟨🟨");
   attroff(COLOR_PAIR(5));
   break;
   }
case(60):case(65):{
   attron(COLOR_PAIR(2));
   mvprintw(22,10,"🟥🟥🟥🟥");
   attroff(COLOR_PAIR(2));
   break;
   }
case(70):case(75):{
   attron(COLOR_PAIR(2));
   mvprintw(22,10,"🟥🟥🟥");
   attroff(COLOR_PAIR(2));
   break;
   }
case(80):case(85):{
   attron(COLOR_PAIR(2));
   mvprintw(22,10,"🟥🟥");
   attroff(COLOR_PAIR(2));
   break;
   }
case(90):case(95):{
   attron(COLOR_PAIR(2));
   mvprintw(22,10,"🟥");
   attroff(COLOR_PAIR(2));
   break;
   }
case(100):{
   attron(COLOR_PAIR(2));
   mvprintw(22,10,"🟥");
   attroff(COLOR_PAIR(2));
   break;
   }

    }

  noecho();
  char a=getch();
  echo();
   switch(a){

   case('u'):{
      current_time=time(NULL);
   last_time=(current_time-temp);
   current_time_2=time(NULL);
   last_time_2=(current_time_2-temp_2);
   if(food_count!=0){
   food_count-=1;
   if(game_difficulty==1){
   gorosnegy-=30;
   }
   if(game_difficulty==2){
   gorosnegy-=20;
   }
   if(game_difficulty==3){
   gorosnegy-=10;
   }
   if(gorosnegy<0){
   gorosnegy=0;
   }
   }
   break;
   }

   case('b'):{
  h=1;
     current_time=time(NULL);
   last_time=(current_time-temp);
   current_time_2=time(NULL);
   last_time_2=(current_time_2-temp_2);
  break;
  }

  }

   }




    }


    void show_assets(){

clear();





    int temp=(current_time-last_time);
    int temp_2=(current_time_2-last_time_2);

    int k=0;

    while(k==0){

clear();



    mvprintw(17,10,
    "press p to put your weapon in backpack");
    mvprintw(20,10,"m   Mace : %d  damage : 5  board : 1\n"
    ,mace_count);
mvprintw(22,10,"d   Dagger : %d  damage : 12  board : 5\n"
    ,dagger_count);
mvprintw(24,10,"w   Magic wand : %d  damage : 15  board : 10\n"
    ,magic_wand_count);
mvprintw(26,10,"a   Normal Arrow : %d  damage : 5  board : 5\n"
    ,arrow_count);
mvprintw(28,10,"s   Sword : %d  damage : 10  board : 1\n"
    ,sword_count);
mvprintw(30,10,"S   Speed spell : %d\n"
    ,speed_spell_count);
mvprintw(32,10,"D   Damage Spell : %d\n"
    ,damage_spell_count);
mvprintw(34,10,"h   Health Spell : %d\n"
    ,health_spell_count);
mvprintw(36,10,"Ancient key : %d\n"
    ,ancient_key_count);
mvprintw(38,10,"press e to exit");


    switch(selected_weapon){

    case(1):{
   mvprintw(40,10,"Your_weapon : Mace");
   break;
   }
case(2):{
   mvprintw(40,10,"Your_weapon : Dagger");
   break;
   }
case(3):{
   mvprintw(40,10,"Your_weapon : Magic Wand");
   break;
   }
case(4):{
   mvprintw(40,10,"Your_weapon : Normal Arrow");
   break;
   }
case(5):{
   mvprintw(40,10,"Your_weapon : Sword");
   break;
   }
case(6):{
   mvprintw(40,10,"Your_weapon : any weapon");
   break;
   }

    }


    noecho();
    char choice=getch();
    echo();

    switch(choice){

    case('p'):{
    selected_weapon=6;
    break;
    }
    case('m'):{
    if(selected_weapon==6){
    selected_weapon=1;
    mvprintw(45,10,"Your weapon change to Mace");
    getch();
    }
    else {
    mvprintw(45,10,"first put your weapon in backpack");
    getch();
    }
    break;
    }
    case('d'):{
    if(selected_weapon==6){
    if(dagger_count!=0){
    selected_weapon=2;
    mvprintw(45,10,"Your weapon change to Dagger");
    }
    else{
    mvprintw(45,10,"You have not Dagger in your backpack");
    }
    getch();
    }
else {
    mvprintw(45,10,"first put your weapon in backpack");
    getch();
    }
    break;
    }
case('w'):{
    if(selected_weapon==6){
    if(magic_wand_count!=0){
    selected_weapon=3;
    mvprintw(45,10,"Your weapon change to Magic Wand");
    }
    else{
    mvprintw(45,10,"You have not Magic Wand in your backpack");
    }
    getch();
    }
else {
    mvprintw(45,10,"first put your weapon in backpack");
    getch();
    }
    break;
    }
case('a'):{
    if(selected_weapon==6){
    if(arrow_count!=0){
    selected_weapon=4;
    mvprintw(45,10,"Your weapon change to Normal Arrow");
    }
    else{
    mvprintw(45,10,"You have not Normal Arrow in your backpack");
    }
    getch();
    }
else {
    mvprintw(45,10,"first put your weapon in backpack");
    getch();
    }
    break;
    }
case('s'):{
    if(selected_weapon==6){
    if(sword_count!=0){
    selected_weapon=5;
    mvprintw(45,10,"Your weapon change to Sword");
    }
    else{
    mvprintw(45,10,"You have not Sword in your backpack");
    }
    getch();
    }
else {
    mvprintw(45,10,"first put your weapon in backpack");
    getch();
    }
    break;
    }

    case('S'):{
    if(speed_spell_count!=0){
    speed_spell_count-=1;
    speed_spell_effect=10;
    mvprintw(45,10,"You use Speed spell");
    getch();
    }
    else{
    mvprintw(45,10,"You have not Speed Spell in your backpack");
    getch();
    }
    break;
    }

case('D'):{
    if(damage_spell_count!=0){
    damage_spell_count-=1;
    damage_spell_effect=10;
    mvprintw(45,10,"You use Damage Spell");
    getch();
    }
    else{
    mvprintw(45,10,"You have not Damage Spell in your backpack");
    getch();
    }
    break;
    }

case('h'):{
    if(health_spell_count!=0){
    health_spell_count-=1;
    health_spell_effect=10;
    mvprintw(45,10,"You use Health spell");
    getch();
    }
    else{
    mvprintw(45,10,"You have not Health Spell in your backpack");
    getch();
    }
    break;
    }

    case('e'):{
    k=1;
    break;
    }

    default:{
    mvprintw(45,10,"Invalid character");
    getch();
    break;
    }

    }

    }

    current_time=time(NULL);
    last_time=(current_time-temp);
current_time_2=time(NULL);
    last_time_2=(current_time_2-temp_2);

clear();




    }



void save_game(const char *filename, gamedata *data) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("error in saving game\n");
        return;
    }

    fwrite(data, sizeof(gamedata), 1, file);
    fclose(file);


}


void load_game(const char *filename, gamedata *data) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("error in loading game\n");
        return;
    }

    fread(data, sizeof(gamedata), 1, file);
    fclose(file);


}



    void generate_map_2(){




   srand(time(NULL));


   int check_room;

   for(int i=0;i<6;i+=0){
  check_room=1;
  x[i]=(2+(rand()%123));
  y[i]=(7+(rand()%55));
  length[i]=(rand()%20);
  height[i]=(rand()%15);
  for(int j=0;j<i;j++){

  if((((x[i]>=(x[j]-2))&&
  (x[i]<=(x[j]+length[j]+5)))||
  (((x[i]+length[i])>=(x[j]-2))
  &&((x[i]+length[i])<=(x[j]+length[j]+5))))
  &&(((y[i]>=(y[j]-2))
  &&(y[i]<=(y[j]+height[j]+5)))||
  (((y[i]+height[i])>=(y[j]-2))
  &&((y[i]+height[i])<=(y[j]+height[j]+5))))){

check_room=0;
break;
}

}
  if((length[i]<10)||(height[i]<10)){
  check_room=0;
}

  for(int j=0;j<i;j++){
  if(((x[i]-x[j]-length[j]<3)&&(x[i]-x[j]-length[j]>=0))||
  ((x[j]-x[i]-length[i]<3)&&(x[j]-x[i]-length[i]>=0))||
  ((y[i]-y[j]-height[j]<3)&&(y[i]-y[j]-height[j]>=0))||
  ((y[j]-y[i]-height[i]<3)&&(y[j]-y[i]-height[i]>=0)))
   {
   check_room=0;
   break;
   }
   }


  if(check_room==1){
  i++;
}

}

   for(int i=0;i<6;i++){

  for(int j=x[i];j<=x[i]+length[i];j++){
  map[j][y[i]]='-';
  map[j][y[i]+height[i]]='-';
}
  for(int j=y[i];j<=y[i]+height[i];j++){
  map[x[i]][j]='|';
  map[x[i]+length[i]][j]='|';
}

}



  int n_1=rand()%6;
  int n_2=rand()%6;
  int n_3=rand()%6;

  int p_1;
  int p_2;
  int p_3;
  int p_4;
  int p_5;
  int p_6;
  int p_7;
  int p_8;

   while((n_1==n_2)||(n_1==n_3)||(n_2==n_3)){
   n_2=rand()%6;
   n_3=rand()%6;
   }

  for(int i=0;i<6;i++){
  if((i!=n_1)&&(i!=n_2)){
  if(i!=n_3){
  door_1[i]=(rand()%length[i]);
  door_2[i]=(rand()%length[i]);
  map[x[i]+door_1[i]][y[i]]='+';
  map[x[i]+door_2[i]][y[i]+height[i]]='+';
}
  else {
  door_1[i]=(rand()%length[i]);
  door_2[i]=(rand()%length[i]);
  map[x[i]+door_1[i]][y[i]]='@';
  map[x[i]+door_2[i]][y[i]+height[i]]='@';
}
}
  else {
  door_1[i]=(rand()%length[i]);
  door_2[i]=(rand()%length[i]);
  map[x[i]+door_1[i]][y[i]]='!';
  map[x[i]+door_2[i]][y[i]+height[i]]='!';
  }
}


  for(int i=0;i<6;i++){

  for(int j=(x[i]+1);j<(x[i]+length[i]);j++){
  for(int k=(y[i]+1);k<(y[i]+height[i]);k++){
  map[j][k]='.';

}
}
}

  int t=(rand()%5);
  for(int i=t;i<(t+2);i++){
  while(1){
  x_pillar[i]=(rand()%(length[i]-1));
  y_pillar[i]=(rand()%(height[i]-1));
  if(map[x[i]+x_pillar[i]+1][y[i]+y_pillar[i]+1]=='.'){
 map[x[i]+x_pillar[i]+1][y[i]+y_pillar[i]+1]='O';
 break;
}
}
}

int t_1=(rand()%4);
  for(int i=t_1;i<(t_1+1);i++){
  while(1){
  x_gold[i]=(rand()%(length[i]-1));
  y_gold[i]=(rand()%(height[i]-1));
 if(map[x[i]+x_gold[i]+1][y[i]+y_gold[i]+1]=='.'){
  map[x[i]+x_gold[i]+1][y[i]+y_gold[i]+1]='g';
break;
}
}
}
int t_2=(rand()%6);
  for(int i=t_2;i<(t_2+1);i++){
  while(1){
  x_step[i]=(rand()%(length[i]-1));
  y_step[i]=(rand()%(height[i]-1));
 if(map[x[i]+x_step[i]+1][y[i]+y_step[i]+1]=='.'){
  map[x[i]+x_step[i]+1][y[i]+y_step[i]+1]='<';
  stair_x=(x[i]+x_step[i]+1);
  stair_y=(y[i]+y_step[i]+1);
break;
}
}
}

   int t_10=(rand()%6);
  for(int i=t_10;i<(t_10+1);i++){
  while(1){
  x_step[i]=(rand()%(length[i]-1));
  y_step[i]=(rand()%(height[i]-1));
 if(map[x[i]+x_step[i]+1][y[i]+y_step[i]+1]=='.'){
  map[x[i]+x_step[i]+1][y[i]+y_step[i]+1]='k';
break;
}
}
}

int t_4=(rand()%4);
  for(int i=t_4;i<(t_4+3);i++){
  while(1){
  x_food[i]=(rand()%(length[i]-1));
  y_food[i]=(rand()%(height[i]-1));
 if(map[x[i]+x_food[i]+1][y[i]+y_food[i]+1]=='.'){
  map[x[i]+x_food[i]+1][y[i]+y_food[i]+1]='f';
break;
}
}
}


  int z;
  int k;

  int t_6=(rand()%6);
  for(int i=t_6;i<(t_6+1);i++){
  while(1){
  z=(rand()%(length[i]-1));
  k=(rand()%(height[i]-1));
 if(map[x[i]+z+1][y[i]+k+1]=='.'){
  map[x[i]+z+1][y[i]+k+1]='v';
break;
}
}
}

  int t_7=(rand()%6);
  for(int i=t_7;i<(t_7+1);i++){
  while(1){
  z=(rand()%(length[i]-1));
  k=(rand()%(height[i]-1));
 if(map[x[i]+z+1][y[i]+k+1]=='.'){
  map[x[i]+z+1][y[i]+k+1]='h';
break;
}
}
}

     int t_8=(rand()%6);
  for(int i=t_8;i<(t_8+1);i++){
  while(1){
  z=(rand()%(length[i]-1));
  k=(rand()%(height[i]-1));
 if(map[x[i]+z+1][y[i]+k+1]=='.'){
  map[x[i]+z+1][y[i]+k+1]='d';
break;
}
}
}



  int x_1;
  int y_1;
  int x_2;
  int y_2;
  int x_3;
  int y_3;

    while(1){
  x_1=(rand()%(length[n_1]-1));
  y_1=(rand()%(height[n_1]-1));
 if(map[x[n_1]+x_1+1][y[n_1]+y_1+1]=='.'){
  map[x[n_1]+x_1+1][y[n_1]+y_1+1]='v';
break;
}
}

  while(1){
  x_1=(rand()%(length[n_2]-1));
  y_1=(rand()%(height[n_2]-1));
 if(map[x[n_2]+x_1+1][y[n_2]+y_1+1]=='.'){
  map[x[n_2]+x_1+1][y[n_2]+y_1+1]='v';
break;
}
}

   while(1){
  x_2=(rand()%(length[n_1]-1));
  y_2=(rand()%(height[n_1]-1));
 if(map[x[n_1]+x_2+1][y[n_1]+y_2+1]=='.'){
  map[x[n_1]+x_2+1][y[n_1]+y_2+1]='h';
break;
}
}

   while(1){
  x_2=(rand()%(length[n_2]-1));
  y_2=(rand()%(height[n_2]-1));
 if(map[x[n_2]+x_2+1][y[n_2]+y_2+1]=='.'){
  map[x[n_2]+x_2+1][y[n_2]+y_2+1]='h';
break;
}
}

  while(1){
  x_3=(rand()%(length[n_1]-1));
  y_3=(rand()%(height[n_1]-1));
 if(map[x[n_1]+x_3+1][y[n_1]+y_3+1]=='.'){
  map[x[n_1]+x_3+1][y[n_1]+y_3+1]='d';
break;
}
}

  while(1){
  x_3=(rand()%(length[n_2]-1));
  y_3=(rand()%(height[n_2]-1));
 if(map[x[n_2]+x_3+1][y[n_2]+y_3+1]=='.'){
  map[x[n_2]+x_3+1][y[n_2]+y_3+1]='d';
break;
}
}

   for(int i=0;i<6;i++){

   rooms[level-1][i].x=x[i];
  rooms[level-1][i].y=y[i];
  rooms[level-1][i].length=length[i];
  rooms[level-1][i].height=height[i];
  rooms[level-1][i].door_1=door_1[i];
  rooms[level-1][i].door_2=door_2[i];

   if((i==n_1)||(i==n_2)){
  rooms[level-1][i].room_type=2;
   }
   else {

   rooms[level-1][i].room_type=1;
   }

    }

   int hayola_type[6];
   int hayola_type_2[6];

   for(int i=0;i<6;i++){

   if((i!=n_1)&&(i!=n_2)){

   hayola_type[i]=(1+rand()%5);

  while(1){
  z=(rand()%(length[i]-1));
  k=(rand()%(height[i]-1));
 if(map[x[i]+z+1][y[i]+k+1]=='.'){
  if(hayola_type[i]==1){
  map[x[i]+z+1][y[i]+k+1]='D';
  }
  else if(hayola_type[i]==2){
  map[x[i]+z+1][y[i]+k+1]='F';
  }
  else if(hayola_type[i]==3){
  map[x[i]+z+1][y[i]+k+1]='G';
  }
  else if(hayola_type[i]==4){
  map[x[i]+z+1][y[i]+k+1]='S';
  }
  else if(hayola_type[i]==5){
  map[x[i]+z+1][y[i]+k+1]='U';
  }

break;
}
}

   }

    }


 for(int i=0;i<6;i++){

   if((i!=n_1)&&(i!=n_2)){

   hayola_type_2[i]=(1+rand()%5);

   while(hayola_type_2[i]==hayola_type[i]){
   hayola_type_2[i]=(1+rand()%5);
   }

  while(1){
  z=(rand()%(length[i]-1));
  k=(rand()%(height[i]-1));
 if(map[x[i]+z+1][y[i]+k+1]=='.'){
  if(hayola_type_2[i]==1){
  map[x[i]+z+1][y[i]+k+1]='D';
  }
  else if(hayola_type_2[i]==2){
  map[x[i]+z+1][y[i]+k+1]='F';
  }
  else if(hayola_type_2[i]==3){
  map[x[i]+z+1][y[i]+k+1]='G';
  }
  else if(hayola_type_2[i]==4){
  map[x[i]+z+1][y[i]+k+1]='S';
  }
  else if(hayola_type_2[i]==5){
  map[x[i]+z+1][y[i]+k+1]='U';
  }

break;
}
}

   }

    }


   for(int i=0;i<6;i++){

  int weapon_type=(1+rand()%4);

   while(1){
  z=(rand()%(length[i]-1));
  k=(rand()%(height[i]-1));
 if(map[x[i]+z+1][y[i]+k+1]=='.'){

  if(weapon_type==1){
  map[x[i]+z+1][y[i]+k+1]='o';
  }
  else if(weapon_type==2){
  map[x[i]+z+1][y[i]+k+1]='w';
  }
  else if(weapon_type==3){
  map[x[i]+z+1][y[i]+k+1]='a';
  }
  else if(weapon_type==4){
  map[x[i]+z+1][y[i]+k+1]='s';
  }

break;
}
}

   }



int x_location;
int y_location;

 for(int i=0;i<5;i++){

   int t_3=(rand()%2);

   if(t_3==0){
   x_location=(x[i]+door_1[i]);
   y_location=(y[i]-1);

}
   else {
   x_location=(x[i]+door_2[i]);
   y_location=(y[i]+height[i]+1);

}

   if(x_location<(x[i+1]+length[i+1]+1)){

   while(x_location!=(x[i+1]+length[i+1]+1)){

  map[x_location][y_location]='#';

  if((map[x_location+1][y_location]=='#')||(map[x_location+1][y_location]==' '))
 {
   x_location+=1;
 }
 else {
  y_location+=1;

}
}
}

   else if(x_location>(x[i+1]+length[i+1]+1)){

   while(x_location!=(x[i+1]+length[i+1]+1)){

  map[x_location][y_location]='#';

  if((map[x_location-1][y_location]=='#')||(map[x_location-1][y_location]==' '))
 {
   x_location-=1;
 }
 else {
  y_location+=1;

}
}
}
   if(y_location<(y[i+1]-1)){

   while(y_location!=(y[i+1]-1)){

  map[x_location][y_location]='#';

if((map[x_location][y_location+1]=='#')||(map[x_location][y_location+1]==' '))
{
  y_location+=1;
}
   else {
   x_location+=1;
}
}
}


   else if(y_location>(y[i+1]-1)){

   while(y_location!=(y[i+1]-1)){

  map[x_location][y_location]='#';

  if((map[x_location][y_location-1]=='#')||(map[x_location][y_location-1]==' '))
{
  y_location-=1;
}
  else {
  x_location+=1;
}
}
}

   while(x_location!=(x[i+1]+door_1[i+1])){
   map[x_location][y_location]='#';
   x_location-=1;
   map[x_location][y_location]='#';

}



}


for(int i=0;i<6;i++){


  for(int j=(x[i]-1);(j<=x[i]+length[i]+1);j++){
  map[j][y[i]-1]='#';
  map[j][y[i]+height[i]+1]='#';
}
  for(int j=(y[i]-1);j<=(y[i]+height[i]+1);j++){
  map[x[i]-1][j]='#';
  map[x[i]+length[i]+1][j]='#';
}


}


   int q_2=0;

  while(q_2<6){
    p_3=rand()%150;
    p_4=rand()%80;
   if(map[p_3][p_4]=='.'){
   map[p_3][p_4]='t';
   q_2++;
   }
   }

   int q_3=0;

  while(q_3<6){
   p_5=rand()%150;
   p_6=rand()%80;
   if(map[p_5][p_6]=='.'){
   map[p_5][p_6]='$';
   q_3++;
   }
   }


  int q_4=0;

  while(q_4<5){
   p_5=rand()%150;
   p_6=rand()%80;
   if(map[p_5][p_6]=='#'){
   while(((map[p_5][p_6]=='#')||(map[p_5][p_6]==' '))&&(p_5>5)&&(p_6>5)){
   map[p_5][p_6]='#';
   p_5-=1;
   p_6-=1;
   }
   q_4++;
   }
   }

  int q_8=0;

  while(q_8<5){
   p_5=rand()%150;
   p_6=rand()%80;
   if(map[p_5][p_6]=='#'){
   while(((map[p_5][p_6]=='#')||(map[p_5][p_6]==' '))&&(p_5<140)&&(p_6<75)){
   map[p_5][p_6]='#';
   p_5+=1;
   p_6+=1;
   }
   q_8++;
   }
   }

  int q_9=0;

  while(q_9<5){
   p_5=rand()%150;
   p_6=rand()%80;
   if(map[p_5][p_6]=='#'){
   while(((map[p_5][p_6]=='#')||(map[p_5][p_6]==' '))&&(p_5>5)&&(p_6<75)){
   map[p_5][p_6]='#';
   p_5-=1;
   p_6+=1;
   }
   q_9++;
   }
   }


  int q_5=0;

  while(q_5<3){
   p_5=rand()%150;
   p_6=rand()%80;
   if(map[p_5][p_6]=='#'){
   while(((map[p_5][p_6]=='#')||(map[p_5][p_6]==' '))&&(p_6>5)){
   map[p_5][p_6]='#';
   p_6-=1;
   }
   q_5++;
   }
   }

   int q_6=0;

  while(q_6<3){
   p_5=rand()%150;
   p_6=rand()%80;
   if(map[p_5][p_6]=='#'){
   while(((map[p_5][p_6]=='#')||(map[p_5][p_6]==' '))&&(p_5<140)){
   map[p_5][p_6]='#';
   p_5+=1;
   }
   q_6++;
   }
   }

   int q_7=0;

  while(q_7<5){
   p_5=rand()%150;
   p_6=rand()%80;
   if(map[p_5][p_6]=='#'){
   while(((map[p_5][p_6]=='#')||(map[p_5][p_6]==' '))&&(p_5<140)&&(p_6>5)){
   map[p_5][p_6]='#';
   p_5+=1;
   p_6-=1;
   }
   q_7++;
   }
   }

   for(int i=5;i<140;i++){
   if((map[i][5]=='#')||(map[i][5]==' ')){
   map[i][5]='#';
   }
   }

   for(int i=5;i<=140;i++){
   if((map[i][75]=='#')||(map[i][75]==' ')){
   map[i][75]='#';
   }
   }

   for(int j=5;j<75;j++){
   if((map[5][j]=='#')||(map[5][j]==' ')){
   map[5][j]='#';
   }
   }

   for(int j=5;j<75;j++){
   if((map[140][j]=='#')||(map[140][j]==' ')){
   map[140][j]='#';
   }
   }


   for(int i=0;i<150;i++){
   for(int j=1;j<79;j++){
   if(map[i][j]=='#'){
   if((map[i][j-1]=='.')||(map[i][j+1]=='.')){
   map[i][j]='.';
   }
   else if((map[i][j-1]=='|')&&(map[i][j+1]=='|')){
   map[i][j]='|';
   }

   }
   }
   }

   int q=0;

  while(q<5){
   p_1=rand()%150;
   p_2=rand()%80;
   if(map[p_1][p_2]=='#'){

   map[p_1][p_2]='&';
   q++;
   }
   }




}


   void generate_map_3(){

   for(int i=10;i<30;i++){
   for(int j=10;j<30;j++){
   map[i][j]='.';
   }
   }

   int z;
   int k;

   int m=0;

   while(m<10){
   z=(rand()%30);
   k=(rand()%30);
   if(map[z][k]=='.'){
   map[z][k]='$';
   m++;
   }
   }

   int m_2=0;

   while(m_2<2){
   z=(rand()%30);
   k=(rand()%30);
   if(map[z][k]=='.'){
   map[z][k]='g';
   m_2++;
   }
   }

   int m_3=0;

   while(m_3<5){
   z=(rand()%30);
   k=(rand()%30);
   if(map[z][k]=='.'){
   map[z][k]='t';
   m_3++;
   }
   }

int m_4=0;

   while(m_4<1){
   z=(rand()%30);
   k=(rand()%30);
   if(map[z][k]=='.'){
   map[z][k]='D';
   m_4++;
   }
   }

int m_5=0;

   while(m_5<1){
   z=(rand()%30);
   k=(rand()%30);
   if(map[z][k]=='.'){
   map[z][k]='F';
   m_5++;
   }
   }
int m_6=0;

   while(m_6<1){
   z=(rand()%30);
   k=(rand()%30);
   if(map[z][k]=='.'){
   map[z][k]='G';
   m_6++;
   }
   }

int m_7=0;

   while(m_7<1){
   z=(rand()%30);
   k=(rand()%30);
   if(map[z][k]=='.'){
   map[z][k]='S';
   m_7++;
   }
   }

int m_8=0;

   while(m_8<1){
   z=(rand()%30);
   k=(rand()%30);
   if(map[z][k]=='.'){
   map[z][k]='U';
   m_8++;
   }
   }




    }


   void find_room_number(int e,int f){



   for(int i=0;i<6;i++){

  if(((rooms[level-1][i].x+rooms[level-1][i].door_1==e)&&(rooms[level-1][i].y==f))
  ||((rooms[level-1][i].x+rooms[level-1][i].door_2==e)&&(rooms[level-1][i].y+
  rooms[level-1][i].height==f))){

  show_rooms[level-1][i]=1;
   break;
   }
   }


    }

  int find_room_number_2(int e,int f){
   int i;
   for(i=0;i<6;i++){

  if(((rooms[level-1][i].x+rooms[level-1][i].door_1==e)
  &&(rooms[level-1][i].y==f))
  ||((rooms[level-1][i].x+rooms[level-1][i].door_2==e)
   &&(rooms[level-1][i].y+
  rooms[level-1][i].height==f))){
   break;
   }
   }

   return i;
    }

int find_room_number_3(int e,int f){
   int i;
   for(i=0;i<6;i++){

  if(((rooms[level-1][i].x<=e)
  &&(rooms[level-1][i].x+rooms[level-1][i].length>=e))
  &&((rooms[level-1][i].y<=f)
   &&(rooms[level-1][i].y+
  rooms[level-1][i].height>=f))){
   break;
   }
   }

   return i;
    }

int find_room_number_4(int e,int f){
   int i;
   for(i=0;i<6;i++){

  if(((rooms[level-1][i].x<e)
  &&(rooms[level-1][i].x+rooms[level-1][i].length>e))
  &&((rooms[level-1][i].y<f)
   &&(rooms[level-1][i].y+
  rooms[level-1][i].height>f))){
   break;
   }
   }

   return i;
    }

   int inter_rams_page(int number){



   start_color();

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);

  int error_count=0;

     int temp=(current_time-last_time);
     int temp_2=(current_time_2-last_time_2);

   while (1){
   current_time=time(NULL);
   current_time_2=time(NULL);
   last_time=(current_time-temp);
   last_time_2=(current_time_2-temp_2);
   int rams;
clear();
   refresh();

   mvprintw(30,10,"Ancient key : %d",ancient_key_count);
   mvprintw(33,10,"inter 1 to use Ancient Key");
   mvprintw(18,10,"inter rams");
   mvscanw(20,10,"%d",&rams);

   if(rams==1){
   if(ancient_key_count>0){
   mvprintw(25,10,"You use Ancient key");
   ancient_key_count-=1;

   getch();
clear();



   return 1;
   }
   else {
   attron(COLOR_PAIR(5));
   mvprintw(25,10,"You have not Ancient Key");
   attroff(COLOR_PAIR(5));
   getch();
   }
   }

   else if(rams==number){
   current_time=time(NULL);
   current_time_2=time(NULL);
   last_time=(current_time-temp);
   last_time_2=(current_time_2-temp_2);
   mvprintw(25,10,"rams is correct");

   getch();
clear();



   return 1;
   }

   else {
   current_time=time(NULL);
   current_time_2=time(NULL);
   last_time=(current_time-temp);
   last_time_2=(current_time_2-temp_2);
   error_count ++;

   if(error_count==1){
   mvprintw(25,10,"rams is incorrect");
   getch();
   }
   else if(error_count==2){
   attron(COLOR_PAIR(5));
   mvprintw(25,10,"rams is incorrect");
   attroff(COLOR_PAIR(5));
   getch();
   }
   else if(error_count==3){
   attron(COLOR_PAIR(2));
   mvprintw(25,10,"rams is incorrect");
   attroff(COLOR_PAIR(2));
   getch();
clear();



   return 0;
   }

   }

   }

   }


   int check_enemy(int x,int y){

   if((map[x][y]=='D')||
   (map[x][y]=='F')||
   (map[x][y]=='G')||
   (map[x][y]=='S')||
   (map[x][y]=='U')){
   return 1;
   }
   else {
   return 0;
   }

   }



  int move_player(int dx,int dy){

    if((map[player_x+dx][player_y+dy]=='.')
    || (map[player_x+dx][player_y+dy]=='#')){
    player_x+=dx;
    player_y+=dy;
    if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
    if(map[player_x][player_y]=='#'){
   x_show_corridor[level-1][show_corridors]=player_x;
   y_show_corridor[level-1][show_corridors]=player_y;
   show_corridors ++;
   }
    return 1;
    }
else if(map[player_x+dx][player_y+dy]=='<'){
   player_x+=dx;
   player_y+=dy;
   time_5=time(NULL);
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }
   else if(map[player_x+dx][player_y+dy]=='+'){
int u=find_room_number_2(player_x+dx,player_y+dy);
   if(show_rooms[level-1][u]==0){
time_6=time(NULL);
   }
   find_room_number((player_x+dx),(player_y+dy));
   player_x+=dx;
   player_y+=dy;
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }

   else if(map[player_x+dx][player_y+dy]=='!'){
   int u=find_room_number_2(player_x+dx,player_y+dy);
   if(show_rooms[level-1][u]==0){
time_6=time(NULL);
   }
   find_room_number(player_x+dx,player_y+dy);
   map[player_x+dx][player_y+dy]='?';
   player_x+=dx;
   player_y+=dy;
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }

   else if(map[player_x+dx][player_y+dy]=='^'){
   player_x+=dx;
   player_y+=dy;
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }

   else if(map[player_x+dx][player_y+dy]=='?'){
   player_x+=dx;
   player_y+=dy;
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }

   else if(map[player_x+dx][player_y+dy]=='t'){

   map[player_x+dx][player_y+dy]='^';
   player_x+=dx;
  player_y+=dy;
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
  if(no_get!='g'){
  player_health-=10;
  time_3=time(NULL);
   }
  else {
  no_get='a';
  }

  return 1;

}

   else if(map[player_x+dx][player_y+dy]=='&'){
   if(no_get!='g'){
   rams_number=(1000+rand()%9000);
   time_4=time(NULL);
   }
   else {
   no_get='a';
   }
   map[player_x+dx][player_y+dy]='#';
   player_x+=dx;
   player_y+=dy;
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }

   else if(map[player_x+dx][player_y+dy]=='@'){

   if(rams_door_opened[level-1]==0){

   if(inter_rams_page(rams_number)){
   player_x+=dx;
   player_y+=dy;
   rams_door_opened[level-1]=1;
  find_room_number(player_x,player_y);
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   time_6=time(NULL);
   }

   }
   else {
   player_x+=dx;
   player_y+=dy;
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }

   }

   else if(map[player_x+dx][player_y+dy]=='k'){
   map[player_x+dx][player_y+dy]='.';
   player_x+=dx;
   player_y+=dy;
   if(no_get!='g'){
   ancient_key_count++;
   }
   else {
   no_get='a';
   }
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }

   else if(map[player_x+dx][player_y+dy]=='v'){
   map[player_x+dx][player_y+dy]='.';
   player_x+=dx;
   player_y+=dy;
   if(no_get!='g'){
   speed_spell_count++;
   }
   else {
   no_get='a';
   }
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }
   else if(map[player_x+dx][player_y+dy]=='d'){
   map[player_x+dx][player_y+dy]='.';
   player_x+=dx;
   player_y+=dy;
   if(no_get!='g'){
   damage_spell_count++;
   }
   else {
   no_get='a';
   }
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }
   else if(map[player_x+dx][player_y+dy]=='C'){
   map[player_x+dx][player_y+dy]='.';
   player_x+=dx;
   player_y+=dy;
   if(no_get!='g'){
   dagger_count++;
   }
   else {
   no_get='a';
   }
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }
   else if(map[player_x+dx][player_y+dy]=='h'){
   map[player_x+dx][player_y+dy]='.';
   player_x+=dx;
   player_y+=dy;
   if(no_get!='g'){
   health_spell_count++;
   }
   else {
   no_get='a';
   }
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }
   else if(map[player_x+dx][player_y+dy]=='o'){
   map[player_x+dx][player_y+dy]='.';
   player_x+=dx;
   player_y+=dy;
   if(no_get!='g'){
   dagger_count+=10;
   }
   else {
   no_get='a';
   }
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }

   else if(map[player_x+dx][player_y+dy]=='w'){
   map[player_x+dx][player_y+dy]='.';
   player_x+=dx;
   player_y+=dy;
   if(no_get!='g'){
   magic_wand_count+=8;
   }
   else {
   no_get='a';
   }
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }
else if(map[player_x+dx][player_y+dy]=='B'){
   map[player_x+dx][player_y+dy]='.';
   player_x+=dx;
   player_y+=dy;
   if(no_get!='g'){
   magic_wand_count++;
   }
   else {
   no_get='a';
   }
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }
   else if(map[player_x+dx][player_y+dy]=='a'){
   map[player_x+dx][player_y+dy]='.';
   player_x+=dx;
   player_y+=dy;
   if(no_get!='g'){
   arrow_count+=20;
   }
   else {
   no_get='a';
   }
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }
else if(map[player_x+dx][player_y+dy]=='A'){
   map[player_x+dx][player_y+dy]='.';
   player_x+=dx;
   player_y+=dy;
   if(no_get!='g'){
   arrow_count++;;
   }
   else {
   no_get='a';
   }
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }
   else if(map[player_x+dx][player_y+dy]=='s'){
   map[player_x+dx][player_y+dy]='.';
   player_x+=dx;
   player_y+=dy;
   if(no_get!='g'){
   sword_count=1;
   }
   else {
   no_get='a';
   }
   if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
   }

   else if(map[player_x+dx][player_y+dy]=='f'){

  if(food_count<5){
  if(no_get!='g'){
  food_count+=1;
  time_2=time(NULL);
  }
  else {
  no_get='a';
  }
}
  map[player_x+dx][player_y+dy]='.';
  player_x+=dx;
  player_y+=dy;
  if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
  return 1;
   }

    else if(map[player_x+dx][player_y+dy]=='$'){

    map[player_x+dx][player_y+dy]='.';
    player_x+=dx;
    player_y+=dy;
    if(no_get!='g'){
    gold+=1;
    score+=10;
    time_1=time(NULL);
    }
    else {
    no_get='a';
    }
    if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
    }

else if(map[player_x+dx][player_y+dy]=='g'){

    map[player_x+dx][player_y+dy]='.';
    player_x+=dx;
    player_y+=dy;
    if(no_get!='g'){
    gold+=5;
    score+=50;
    time_1=time(NULL);
    }
    else {
    no_get='a';
    }
    if(speed_spell_effect>0){
    speed_spell_effect-=1;
    }
    if(damage_spell_effect>0){
    damage_spell_effect-=1;
    }
    if(health_spell_effect>0){
    health_spell_effect-=1;
    }
   return 1;
    }


   return 0;
}


    int treasure_room(){




    last_time=time(NULL);
    last_time_2=time(NULL);

    char player='@';


   int giant_moves=0;
   int undeed_moves=0;
   int stop_giant=0;
   int stop_snake=0;
   int stop_undeed=1;


   int enemy_count=5;


while((map[player_x][player_y]!='.')||(map[player_x][player_y]!='^')){

   player_x=(rand()%60);
   player_y=(rand()%50);

   }


    while(1){

    clear();




current_time=time(NULL);
   current_time_2=time(NULL);


   if(game_difficulty==1){

   if(gorosnegy<30){
   if(current_time_2-last_time_2>=3){
   if(health_spell_effect>0){
   player_health+=10;
   }
   else {
   player_health+=4;
   }
   last_time_2=current_time_2;
   }
   }
   else if(gorosnegy<60){
   if(current_time_2-last_time_2>=3){
   if(health_spell_effect>0){
   player_health+=5;
   }
   else {
   player_health+=2;
   }
   last_time_2=current_time_2;
   }
   }
   else if(gorosnegy<=100){
   if(current_time_2-last_time_2>=7){
   if(health_spell_effect>0){
   player_health+=2;
   }
   else {
   player_health-=2;
   }
   last_time_2=current_time_2;
   }
   }
   if(current_time-last_time>=45){
   gorosnegy+=5;
   last_time=current_time;
   }
   if(gorosnegy>100){
   gorosnegy=100;
   }
   if(player_health>100){
   player_health=100;
   }


   }

   if(game_difficulty==2){

   if(gorosnegy<30){
   if(current_time_2-last_time_2>=5){
   if(health_spell_effect>0){
   player_health+=6;
   }
   else {
   player_health+=2;
   }
   last_time_2=current_time_2;
   }
   }
   else if(gorosnegy<60){
   if(current_time_2-last_time_2>=5){
   if(health_spell_effect>0){
   player_health+=3;
   }
   else {
   player_health+=1;
   }
   last_time_2=current_time_2;
   }
   }
   else if(gorosnegy<=100){
   if(current_time_2-last_time_2>=5){
   if(health_spell_effect>0){
   player_health-=0;
   }
   else {
   player_health-=4;
   }
   last_time_2=current_time_2;
   }
   }
   if(current_time-last_time>=21){
   gorosnegy+=10;
   last_time=current_time;
   }
   if(gorosnegy>100){
   gorosnegy=100;
   }
   if(player_health>100){
   player_health=100;
   }


   }
    if(game_difficulty==3){

   if(gorosnegy<30){
   if(current_time_2-last_time_2>=7){
   if(health_spell_effect>0){
   player_health+=4;
   }
   else {
   player_health+=1;
   }
   last_time_2=current_time_2;
   }
   }
   else if(gorosnegy<60){
   if(current_time_2-last_time_2>=5){
   if(health_spell_effect>0){
   player_health+=1;
   }
   else {
   player_health+=0;
   }
   last_time_2=current_time_2;
   }
   }
   else if(gorosnegy<=100){
   if(current_time_2-last_time_2>=5){
   if(health_spell_effect>0){
   player_health-=3;
   }
   else {
   player_health-=10;
   }
   last_time_2=current_time_2;
   }
   }
   if(current_time-last_time>=9){
   gorosnegy+=15;
   last_time=current_time;
   }
   if(gorosnegy>100){
   gorosnegy=100;
   }
   if(player_health>100){
   player_health=100;
   }


   }


   if(demon_health<=0){
   for(int i=10;i<30;i++){
   for(int j=10;j<30;j++){
   if(map[i][j]=='D'){
   map[i][j]='.';
   demon_health=5;
   score+=5;
   }
   }
   }
   }
   if(fire_health<=0){
   for(int i=10;i<30;i++){
   for(int j=10;j<30;j++){
   if(map[i][j]=='F'){
   map[i][j]='.';
   fire_health=10;
   score+=10;
   }
   }
   }
   }
   if(giant_health<=0){
   for(int i=10;i<30;i++){
   for(int j=10;j<30;j++){
   if(map[i][j]=='G'){
   map[i][j]='.';
   giant_health=15;
   score+=15;
   }
   }
   }
   }
   if(snake_health<=0){
   for(int i=10;i<30;i++){
   for(int j=10;j<30;j++){
   if(map[i][j]=='S'){
   map[i][j]='.';
   snake_health=20;
   score+=20;
   }
   }
   }
   }
   if(undeed_health<=0){
   for(int i=10;i<30;i++){
   for(int j=10;j<30;j++){
   if(map[i][j]=='U'){
   map[i][j]='.';
   undeed_health=30;
   score+=30;
   }
   }
   }
   }


   for(int i=player_x-1;i<player_x+2;i++){
   for(int j=player_y-1;j<player_y+2;j++){
   if(map[i][j]=='D'){
   player_health-=1;
   time_7=time(NULL);
   }
   else if(map[i][j]=='F'){
   player_health-=2;
   time_8=time(NULL);
   }
else if(map[i][j]=='G'){
   if(giant_moves==5){
   giant_moves=0;
   }
player_health-=3;
time_9=time(NULL);
   }
else if(map[i][j]=='S'){
player_health-=4;
time_10=time(NULL);
   }
else if(map[i][j]=='U'){
if(undeed_moves==5){
   undeed_moves=0;
   }
stop_undeed=0;
player_health-=5;
time_11=time(NULL);
  }

  }
  }



for(int i=10;i<30;i++){
   for(int j=10;j<30;j++){
   if(map[i][j]=='G'){
   if((stop_giant==0)&&(giant_moves<5)){
   if((player_x<i)&&(player_y<j)){
   if((player_x!=i-1)||(player_y!=j-1)){
   if(check_enemy(i-1,j-1)==0){
   map[i-1][j-1]='G';
   map[i][j]='.';
   giant_moves++;
   }
   i=150;
   j=80;
    }

   }
   else if((player_x<i)&&(player_y>j)){
   if((player_x!=i-1)||(player_y!=j+1)){
   if(check_enemy(i-1,j+1)==0){
   map[i-1][j+1]='G';
   map[i][j]='.';
   giant_moves++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x<i)&&(player_y=j)){
   if(player_x!=i-1){
   if(check_enemy(i-1,j)==0){
   map[i-1][j]='G';
   map[i][j]='.';
   giant_moves++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y<j)){
   if((player_x!=i+1)||(player_y!=j-1)){
   if(check_enemy(i+1,j-1)==0){
   map[i+1][j-1]='G';
   map[i][j]='.';
   giant_moves++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y>j)){
   if((player_x!=i+1)||(player_y!=j+1)){
   if(check_enemy(i+1,j+1)==0){
   map[i+1][j+1]='G';
   map[i][j]='.';
   giant_moves++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y=j)){
   if(player_x!=i+1){
   if(check_enemy(i+1,j)==0){
   map[i+1][j]='G';
   map[i][j]='.';
   giant_moves++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y<j)){
   if(player_y!=j-1){
   if(check_enemy(i,j-1)==0){
   map[i][j-1]='G';
   map[i][j]='.';
   giant_moves++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y>j)){
   if(player_y!=j+1){
   if(check_enemy(i,j+1)==0){
   map[i][j+1]='G';
   map[i][j]='.';
   giant_moves++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y=j)){
   i=150;
   j=80;
   }

   }

   }

   }
   }

   for(int i=10;i<30;i++){
   for(int j=10;j<30;j++){

   if(map[i][j]=='S'){
   if(stop_snake==0){
   if((player_x<i)&&(player_y<j)){
   if((player_x!=i-1)||(player_y!=j-1)){
   if(check_enemy(i-1,j-1)==0){
   map[i-1][j-1]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x<i)&&(player_y>j)){
   if((player_x!=i-1)||(player_y!=j+1)){
   if(check_enemy(i-1,j+1)==0){
   map[i-1][j+1]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x<i)&&(player_y=j)){
   if(player_x!=i-1){
   if(check_enemy(i-1,j)==0){
   map[i-1][j]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y<j)){
   if((player_x!=i+1)||(player_y!=j-1)){
   if(check_enemy(i+1,j-1)==0){
   map[i+1][j-1]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y>j)){
   if((player_x!=i+1)||(player_y!=j+1)){
   if(check_enemy(i+1,j+1)==0){
   map[i+1][j+1]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y=j)){
   if(player_x!=i+1){
   if(check_enemy(i+1,j)==0){
   map[i+1][j]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y<j)){
   if(player_y!=j-1){
   if(check_enemy(i,j-1)==0){
   map[i][j-1]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y>j)){
   if(player_y!=j+1){
   if(check_enemy(i,j+1)==0){
   map[i][j+1]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y=j)){
   i=150;
   j=80;
   }

   }

   }

   }
   }

   for(int i=10;i<30;i++){
   for(int j=10;j<30;j++){

   if(map[i][j]=='U'){
   if((stop_undeed==0)&&(undeed_moves<5)){
   if((player_x<i)&&(player_y<j)){
   if((player_x!=i-1)||(player_y!=j-1)){
   if(check_enemy(i-1,j-1)==0){
   map[i-1][j-1]='U';
   map[i][j]='.';
   undeed_moves++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x<i)&&(player_y>j)){
   if((player_x!=i-1)||(player_y!=j+1)){
   if(check_enemy(i-1,j+1)==0){
   map[i-1][j+1]='U';
   map[i][j]='.';
   undeed_moves++;
   }
   i=150;
   j=80;
   }

   }
    else if((player_x<i)&&(player_y=j)){
   if(player_x!=i-1){
   if(check_enemy(i-1,j)==0){
   map[i-1][j]='U';
   map[i][j]='.';
   undeed_moves++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y<j)){
   if((player_x!=i+1)||(player_y!=j-1)){
   if(check_enemy(i+1,j-1)==0){
   map[i+1][j-1]='U';
   map[i][j]='.';
   undeed_moves++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y>j)){
   if((player_x!=i+1)||(player_y!=j+1)){
   if(check_enemy(i+1,j+1)==0){
   map[i+1][j+1]='U';
   map[i][j]='.';
   undeed_moves++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y=j)){
   if(player_x!=i+1){
   if(check_enemy(i+1,j)==0){
   map[i+1][j]='U';
   map[i][j]='.';
   undeed_moves++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y<j)){
   if(player_y!=j-1){
   if(check_enemy(i,j-1)==0){
   map[i][j-1]='U';
   map[i][j]='.';
   undeed_moves++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y>j)){
   if(player_y!=j+1){
   if(check_enemy(i,j+1)==0){
   map[i][j+1]='U';
   map[i][j]='.';
   undeed_moves++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y=j)){
   i=150;
   j=80;
   }

   }

   }


   }

   }








for(int j=0;j<35;j++){
   for(int k=0;k<35;k++){
   if(map[j][k]=='!'){
   mvprintw(k,j,"?");
   }
   else if(map[j][k]=='t'){
   mvprintw(k,j,".");
   }
    else if(map[j][k]=='$'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='g'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='f'){
   mvaddstr(k,j,".");
   }
     else if(map[j][k]=='k'){
   mvprintw(k,j,".");
   }

   else if(map[j][k]=='v'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='d'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='h'){
   mvaddstr(k,j,".");
   }

   else if(map[j][k]=='o'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='C'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='B'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='A'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='w'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='a'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='s'){
   mvaddstr(k,j,".");
   }
  else if(map[j][k]=='<'){
   if(level==4){
   mvaddstr(k,j,"💰");
   }
   else {
   mvprintw(k,j,"%c",map[j][k]);
   }
   }
   else if(map[j][k]=='#'){
   mvaddstr(k,j,"\u2589");
   }
   else {
  mvprintw(k,j,"%c",map[j][k]);
  }
}
}

  for(int j=0;j<150;j++){
  for(int k=0;k<80;k++){
   if(map[j][k]=='$'){
   attron(COLOR_PAIR(2));
   mvaddstr(k,j,"🟡");
   attroff(COLOR_PAIR(2));
   }
   else if(map[j][k]=='g'){
   attron(COLOR_PAIR(2));
   mvaddstr(k,j,"⚫️");
   attroff(COLOR_PAIR(2));
   }
   else if(map[j][k]=='f'){
   attron(COLOR_PAIR(3));
   mvaddstr(k,j,"🍎");
   attroff(COLOR_PAIR(3));
   }
     else if(map[j][k]=='k'){
   attron(COLOR_PAIR(5));
   mvprintw(k,j,"∆");
   attroff(COLOR_PAIR(5));
   }

   else if(map[j][k]=='v'){
   attron(COLOR_PAIR(4));
   mvaddstr(k,j,"💨");
   attroff(COLOR_PAIR(4));
   }
   else if(map[j][k]=='d'){
   attron(COLOR_PAIR(3));
   mvaddstr(k,j,"🔥");
   attroff(COLOR_PAIR(3));
   }
   else if(map[j][k]=='h'){
   attron(COLOR_PAIR(3));
   mvaddstr(k,j,"❤️");
   attroff(COLOR_PAIR(3));
   }

   else if(map[j][k]=='o'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🗡️");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='C'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🗡️");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='B'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🪄");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='A'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🏹");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='w'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🪄");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='a'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🏹");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='s'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"⚔️");
   attroff(COLOR_PAIR(1));
   }
   }
   }



if(player_color==1){
   mvprintw(player_y,player_x,"%c",player);
   }
   else if(player_color==2){
   attron(COLOR_PAIR(5));
   mvprintw(player_y,player_x,"%c",player);
   attroff(COLOR_PAIR(5));
   }

else if(player_color==3){
   start_color();
   attron(COLOR_PAIR(2));
   mvprintw(player_y,player_x,"%c",player);
   attroff(COLOR_PAIR(2));
   }

else if(player_color==4){
   attron(COLOR_PAIR(3));
   mvprintw(player_y,player_x,"%c",player);
   attroff(COLOR_PAIR(3));
   }

else if(player_color==5){
   attron(COLOR_PAIR(4));
   mvprintw(player_y,player_x,"%c",player);
   attroff(COLOR_PAIR(4));
   }




   if(current_time-time_1<=10){
   mvprintw(2,60,"You save gold");
   }

   if(current_time-time_2<=10){
   mvprintw(3,10,"You get food");
   }

   if(current_time-time_3<=10){
   mvprintw(2,10,"You fall in trap");
   }

   if(current_time-time_4<=30){
   if(rams_number!=0){
   mvprintw(40,50,"rams : %d",rams_number);
   }
   }

if(current_time-time_5<=10){
   mvprintw(1,60,"You go to new floor");
   }

if(current_time-time_6<=10){
   mvprintw(1,10,"You go to new room");
   }
   if(current_time-time_7<=10){
   mvprintw(37,30,"The Demon attacked you");
   }

if(current_time-time_8<=10){
   mvprintw(37,30,"The Fire Breathing Monster attacked you");
   }

if(current_time-time_9<=10){
   mvprintw(37,30,"The Giant attacked you");
   }

if(current_time-time_10<=10){
   mvprintw(37,30,"The Snake attacked you");
   }

if(current_time-time_11<=10){
   mvprintw(37,30,"The Undeed attacked you");
   }

   if(current_time-time_12<=5){
   if(demon_health==5){
   mvprintw(38,30,"You kill the Demon");
   }
   else {
   mvprintw(38,30,"Demon : health : %d",demon_health);
   }
   }

   if(current_time-time_13<=5){
   if(fire_health==10){
   mvprintw(38,30,"You kill the Fire Breathing Monster");
   }
   else {
   mvprintw(38,30,"Fire Breathing Monster : health : %d",fire_health);
   }
   }

   if(current_time-time_14<=5){
   if(giant_health==15){
   mvprintw(38,30,"You kill the Giant");
   }
   else {
   mvprintw(38,30,"Giant : health : %d",giant_health);
   }
   }

   if(current_time-time_15<=5){
   if(snake_health==20){
   mvprintw(38,30,"You kill the Snake");
   }
   else {
   mvprintw(38,30,"Snake : health : %d",snake_health);
   }
   }

   if(current_time-time_16<=5){
   if(undeed_health==30){
   mvprintw(38,30,"You kill the Undeed");
   }
   else {
   mvprintw(38,30,"Undeed : health : %d",undeed_health);
   }
   }

   if(current_time-time_17<=5){
   mvprintw(39,50,"You have not Dagger in your backpack");
   }

   if(current_time-time_18<=5){
   mvprintw(39,50,"You have not Magic Wand in your backpack");
   }

   if(current_time-time_19<=5){
   mvprintw(39,50,"You have not Normal Arrow in your backpack");
   }
   switch(gorosnegy){

   case(0):{
   attron(COLOR_PAIR(3));
   mvprintw(41,5,"🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩");
   attroff(COLOR_PAIR(3));
   break;
   }
   case(10):case(5):case(15):{
   attron(COLOR_PAIR(3));
   mvprintw(41,5,"🟩🟩🟩🟩🟩🟩🟩🟩🟩");
   attroff(COLOR_PAIR(3));
   break;
   }
   case(20):case(25):{
   attron(COLOR_PAIR(3));
   mvprintw(41,5,"🟩🟩🟩🟩🟩🟩🟩🟩");
   attroff(COLOR_PAIR(3));
   break;
   }
   case(30):case(35):{
   attron(COLOR_PAIR(5));
   mvprintw(41,5,"🟨🟨🟨🟨🟨🟨🟨");
   attroff(COLOR_PAIR(5));
   break;
   }
   case(40):case(45):{
   attron(COLOR_PAIR(5));
   mvprintw(41,5,"🟨🟨🟨🟨🟨🟨");
   attroff(COLOR_PAIR(5));
   break;
   }
case(50):case(55):{
   attron(COLOR_PAIR(5));
   mvprintw(41,5,"🟨🟨🟨🟨🟨");
   attroff(COLOR_PAIR(5));
   break;
   }
case(60):case(65):{
   attron(COLOR_PAIR(2));
   mvprintw(41,5,"🟥🟥🟥🟥");
   attroff(COLOR_PAIR(2));
   break;
   }
case(70):case(75):{
   attron(COLOR_PAIR(2));
   mvprintw(41,5,"🟥🟥🟥");
   attroff(COLOR_PAIR(2));
   break;
   }
case(80):case(85):{
   attron(COLOR_PAIR(2));
   mvprintw(41,5,"🟥🟥");
   attroff(COLOR_PAIR(2));
   break;
   }
case(90):case(95):{
   attron(COLOR_PAIR(2));
   mvprintw(41,5,"🟥");
   attroff(COLOR_PAIR(2));
   break;
   }
case(100):{
   attron(COLOR_PAIR(2));
   mvprintw(41,5,"🟥");
   attroff(COLOR_PAIR(2));
   break;
   }

    }
    mvprintw(42,5,"foods_number : %d",food_count);
   mvprintw(43,5,"score : %d  gold : %d  floor : 4  health : %d  ",score,gold,player_health);
   noecho();
   char z=getch();
   echo();
      switch(z){

      case('a'):{


   if(speed_spell_effect>0){
   move_player(0,-2);
   }
   else {
   move_player(0,-1);
   }
    break;
   }

   case('b'):{


   if(speed_spell_effect>0){
   move_player(2,0);
   }
   else {
   move_player(1,0);
   }
      break;
   }

   case('c'):{


    if(speed_spell_effect>0){
   move_player(0,2);
   }
   else {
   move_player(0,1);
   }
      break;
   }

   case('d'):{


   if(speed_spell_effect>0){
   move_player(-2,0);
   }
   else {
   move_player(-1,0);
   }
      break;
   }

   case('e'):{


    if(speed_spell_effect>0){
   move_player(2,-2);
   }
   else {
   move_player(1,-1);
    }
   break;
   }

   case('f'):{


    if(speed_spell_effect>0){
   move_player(2,2);
   }
   else {
   move_player(1,1);
   }
   break;
   }
   case('g'):{


  if(speed_spell_effect>0){
   move_player(-2,2);
   }
   else {
   move_player(-1,1);
   }
    break;
   }

   case('h'):{


   if(speed_spell_effect>0){
   move_player(-2,-2);
   }
   else {
   move_player(-1,-1);
   }
   break;
   }

   case('p'):{




noecho();
   char h=getch();
   echo();
      switch(h){

      case('a'):{


      move_player(0,-2);
      break;
   }

   case('b'):{


      move_player(2,0);
      break;
   }

   case('c'):{


      move_player(0,2);
      break;
   }

   case('d'):{


      move_player(-2,0);
      break;
   }

   case('e'):{


      move_player(2,-2);
      break;
   }

   case('f'):{


      move_player(2,2);
      break;
   }

   case('g'):{


      move_player(-2,2);
      break;
   }
   case('h'):{


      move_player(-2,-2);
      break;
   }

   }

   break;
   }

    case('q'):{



    no_get='g';

   noecho();
   char h=getch();
   echo();
      switch(h){

      case('a'):{


      move_player(0,-1);
      break;
   }

   case('b'):{


      move_player(1,0);
      break;
   }

   case('c'):{


      move_player(0,1);
      break;
   }

   case('d'):{


      move_player(-1,0);
      break;
   }

   case('e'):{



    move_player(1,-1);
      break;
   }

   case('f'):{


      move_player(1,1);
      break;
   }

   case('g'):{


      move_player(-1,1);
      break;
   }
   case('h'):{


      move_player(-1,-1);
      break;
   }

   }

    break;
    }

   case('r'):{


   finish_game=1;
   break;
   }

   case('i'):{


   show_assets();
   break;
   }

   case('E'):{


   using_food_page();
   break;
   }
   case(' '):{



   if(selected_weapon==1){
   if(damage_spell_effect>0){
   for(int i=player_x-1;i<player_x+2;i++){
   for(int j=player_y-1;j<player_y+2;j++){
   if(map[i][j]=='D'){
   demon_health-=10;
   time_12=time(NULL);
   }
   else if(map[i][j]=='F'){
   fire_health-=10;
   time_13=time(NULL);
   }
   else if(map[i][j]=='G'){
   giant_health-=10;
   time_14=time(NULL);
   }
else if(map[i][j]=='S'){
    snake_health-=10;
   time_15=time(NULL);
   }
else if(map[i][j]=='U'){
   undeed_health-=10;
   time_16=time(NULL);
   }
   }
   }
   }
   else {
   for(int i=player_x-1;i<player_x+2;i++){
   for(int j=player_y-1;j<player_y+2;j++){
   if(map[i][j]=='D'){
   demon_health-=5;
   time_12=time(NULL);
   }
   else if(map[i][j]=='F'){
   fire_health-=5;
   time_13=time(NULL);
   }
   else if(map[i][j]=='G'){
   giant_health-=5;
   time_14=time(NULL);
   }
else if(map[i][j]=='S'){
    snake_health-=5;
   time_15=time(NULL);
   }
else if(map[i][j]=='U'){
   undeed_health-=5;
   time_16=time(NULL);
   }
   }
   }
   }

   }

   else if(selected_weapon==5){
   if(damage_spell_effect>0){
   for(int i=player_x-1;i<player_x+2;i++){
   for(int j=player_y-1;j<player_y+2;j++){
   if(map[i][j]=='D'){
   demon_health-=20;
   time_12=time(NULL);
   }
   else if(map[i][j]=='F'){
   fire_health-=20;
   time_13=time(NULL);
   }
   else if(map[i][j]=='G'){
   giant_health-=20;
   time_14=time(NULL);
   }
else if(map[i][j]=='S'){
    snake_health-=20;
   time_15=time(NULL);
   }
else if(map[i][j]=='U'){
   undeed_health-=20;
   time_16=time(NULL);
   }

   }
   }
   }
   else {
for(int i=player_x-1;i<player_x+2;i++){
   for(int j=player_y-1;j<player_y+2;j++){
   if(map[i][j]=='D'){
   demon_health-=10;
   time_12=time(NULL);
   }
   else if(map[i][j]=='F'){
   fire_health-=10;
   time_13=time(NULL);
   }
   else if(map[i][j]=='G'){
   giant_health-=10;
   time_14=time(NULL);
   }
else if(map[i][j]=='S'){
    snake_health-=10;
   time_15=time(NULL);
   }
else if(map[i][j]=='U'){
   undeed_health-=10;
   time_16=time(NULL);
   }

   }
   }
   }
   }
   else if(selected_weapon==2){
   if(dagger_count!=0){
   if(damage_spell_effect>0){

   noecho();
   char direction_2=getch();
   echo();

   switch(direction_2){

   case('a'):{
   for(int j=player_y-1;j>player_y-6;j--){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j+1]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=24;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=24;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=24;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=24;
   time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=24;
   time(NULL);
   dagger_count-=1;
   break;
   }
   if(j==(player_y-5)){
   map[player_x][j]='C';
   dagger_count-=1;
   break;
   }

   }

   break;
   }
   case('b'):{
   for(int i=player_x+1;i<player_x+6;i++){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i-1][player_y]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=24;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=24;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=24;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=24;
   time_15=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=24;
   time_16=time(NULL);
   dagger_count-=1;
   break;
   }
   if(i==(player_x+5)){
   map[i][player_y]='C';
   dagger_count-=1;
   break;
   }

   }

   break;
   }
   case('c'):{
   for(int j=player_y+1;j<player_y+6;j++){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j-1]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=24;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=24;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=24;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=24;
   time_15=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=24;
   time_16=time(NULL);
   dagger_count-=1;
   break;
   }
   if(j==(player_y+5)){
   map[player_x][j]='C';
   dagger_count-=1;
   break;
   }

   }

   break;
   }
   case('d'):{
   for(int i=player_x-1;i>player_x-6;i--){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i+1][player_y]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=24;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=24;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=24;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=24;
   time_15=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=24;
   time_16=time(NULL);
   dagger_count-=1;
   break;
   }
   if(i==(player_x-5)){
   map[i][player_y]='C';
   dagger_count-=1;
   break;
   }

   }

   break;
   }

   }

   }
   else {

noecho();
   char direction_2=getch();
   echo();

   switch(direction_2){

   case('a'):{
   for(int j=player_y-1;j>player_y-6;j--){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j+1]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=12;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=12;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=12;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=12;
   time_15=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=12;
   time_16=time(NULL);
   dagger_count-=1;
   break;
   }
   if(j==(player_y-5)){
   map[player_x][j]='C';
   dagger_count-=1;
   break;
   }

   }

   break;
   }
   case('b'):{
   for(int i=player_x+1;i<player_x+6;i++){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i-1][player_y]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=12;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=12;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=12;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=12;
   time_15=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=12;
   time_16=time(NULL);
   dagger_count-=1;
   break;
   }
   if(i==(player_x+5)){
   map[i][player_y]='C';
   dagger_count-=1;
   break;
   }


   }
   break;
   }
   case('c'):{
   for(int j=player_y+1;j<player_y+6;j++){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j-1]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=12;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=12;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=12;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=12;
   time_15=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=12;
   time_16=time(NULL);
   dagger_count-=1;
   break;
   }
   if(j==(player_y+5)){
   map[player_x][j]='C';
   dagger_count-=1;
   break;
   }


   }
   break;
   }
   case('d'):{
   for(int i=player_x-1;i>player_x-6;i--){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i+1][player_y]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=12;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=12;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=12;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=12;
   time_15=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=12;
   time_16=time(NULL);
   dagger_count-=1;
   break;
   }
   if(i==(player_x-5)){
   map[i][player_y]='C';
   dagger_count-=1;
   break;
   }


   }
   break;
   }

   }

   }

   }

   else {

   time_17=time(NULL);

   }

   }

   else if(selected_weapon==3){
   if(magic_wand_count!=0){
   if(damage_spell_effect>0){

   noecho();
   char direction_2=getch();
   echo();

   switch(direction_2){

   case('a'):{
   for(int j=player_y-1;j>player_y-11;j--){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j+1]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=30;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=30;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=30;
   time_14=time(NULL);
   magic_wand_count-=1;
   stop_giant=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=30;
   time(NULL);
   magic_wand_count-=1;
   stop_snake=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=30;
   time(NULL);
   magic_wand_count-=1;
   stop_undeed=1;
   break;
   }
   if(j==(player_y-10)){
   map[player_x][j]='B';
   magic_wand_count-=1;
   break;
   }

   }

   break;
   }
    case('b'):{
   for(int i=player_x+1;i<player_x+11;i++){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i-1][player_y]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=30;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=30;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=30;
   time_14=time(NULL);
   magic_wand_count-=1;
   stop_giant=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=30;
   time_15=time(NULL);
   magic_wand_count-=1;
   stop_snake=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=30;
   time_16=time(NULL);
   magic_wand_count-=1;
   stop_undeed=1;
   break;
   }
   if(i==(player_x+10)){
   map[i][player_y]='B';
   magic_wand_count-=1;
   break;
   }

   }

   break;
   }
   case('c'):{
   for(int j=player_y+1;j<player_y+11;j++){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j-1]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=30;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=30;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=30;
   time_14=time(NULL);
   magic_wand_count-=1;
   stop_giant=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=30;
   time_15=time(NULL);
   magic_wand_count-=1;
   stop_snake=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=30;
   time_16=time(NULL);
   magic_wand_count-=1;
   stop_undeed=1;
   break;
   }
   if(j==(player_y+10)){
   map[player_x][j]='B';
   magic_wand_count-=1;
   break;
   }

   }

   break;
   }
   case('d'):{
   for(int i=player_x-1;i>player_x-11;i--){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i+1][player_y]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=30;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=30;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=30;
   time_14=time(NULL);
   magic_wand_count-=1;
   stop_giant=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=30;
   time_15=time(NULL);
   magic_wand_count-=1;
   stop_snake=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=30;
   time_16=time(NULL);
   magic_wand_count-=1;
   stop_undeed=1;
   break;
   }
   if(i==(player_x-10)){
   map[i][player_y]='B';
   magic_wand_count-=1;
   break;
   }

   }

   break;
   }

   }

   }
   else {

noecho();
   char direction_2=getch();
   echo();

   switch(direction_2){

   case('a'):{
   for(int j=player_y-1;j>player_y-11;j--){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j+1]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=15;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=15;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=15;
   time_14=time(NULL);
   magic_wand_count-=1;
   stop_giant=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=15;
   time_15=time(NULL);
   magic_wand_count-=1;
   stop_snake=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=15;
   time_16=time(NULL);
   magic_wand_count-=1;
   stop_undeed=1;
   break;
   }
   if(j==(player_y-10)){
   map[player_x][j]='B';
   magic_wand_count-=1;
   break;
   }

   }

   break;
   }
   case('b'):{
   for(int i=player_x+1;i<player_x+11;i++){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i-1][player_y]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=15;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=15;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=15;
   time_14=time(NULL);
   magic_wand_count-=1;
   stop_giant=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=15;
   time_15=time(NULL);
   magic_wand_count-=1;
   stop_snake=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=15;
   time_16=time(NULL);
   magic_wand_count-=1;
   stop_undeed=1;
   break;
   }
   if(i==(player_x+10)){
   map[i][player_y]='B';
   magic_wand_count-=1;
   break;
   }


   }
   break;
   }
   case('c'):{
   for(int j=player_y+1;j<player_y+11;j++){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j-1]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=15;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=15;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=15;
   time_14=time(NULL);
   magic_wand_count-=1;
   stop_giant=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=15;
   time_15=time(NULL);
   magic_wand_count-=1;
   stop_snake=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=15;
   time_16=time(NULL);
   magic_wand_count-=1;
   stop_undeed=1;
   break;
   }
   if(j==(player_y+10)){
   map[player_x][j]='B';
   magic_wand_count-=1;
   break;
   }


   }
   break;
   }
   case('d'):{
   for(int i=player_x-1;i>player_x-11;i--){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i+1][player_y]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=15;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=15;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=15;
   time_14=time(NULL);
   magic_wand_count-=1;
   stop_giant=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=15;
   time_15=time(NULL);
   magic_wand_count-=1;
   stop_snake=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=15;
   time_16=time(NULL);
   magic_wand_count-=1;
   stop_undeed=1;
   break;
   }
   if(i==(player_x-10)){
   map[i][player_y]='B';
   magic_wand_count-=1;
   break;
   }


   }
   break;
   }

   }

   }

   }
   else {

   time_18=time(NULL);

   }

   }

else if(selected_weapon==4){
   if(arrow_count!=0){
   if(damage_spell_effect>0){

   noecho();
   char direction_2=getch();
   echo();

   switch(direction_2){

   case('a'):{
   for(int j=player_y-1;j>player_y-6;j--){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j+1]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=10;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=10;
   time_13=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=10;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=10;
   time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=10;
   time(NULL);
   arrow_count-=1;
   break;
   }
   if(j==(player_y-5)){
   map[player_x][j]='A';
   arrow_count-=1;
   break;
   }

   }

   break;
   }
    case('b'):{
   for(int i=player_x+1;i<player_x+6;i++){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i-1][player_y]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=10;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=10;
   time_13=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=10;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=10;
   time_15=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=10;
   time_16=time(NULL);
   arrow_count-=1;
   break;
   }
   if(i==(player_x+5)){
   map[i][player_y]='A';
   arrow_count-=1;
   break;
   }

   }

   break;
   }
   case('c'):{
   for(int j=player_y+1;j<player_y+6;j++){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j-1]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=10;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=10;
   time_13=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=10;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=10;
   time_15=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=10;
   time_16=time(NULL);
   arrow_count-=1;
   break;
   }
   if(j==(player_y+5)){
   map[player_x][j]='A';
   arrow_count-=1;
   break;
   }

   }

   break;
   }
   case('d'):{
   for(int i=player_x-1;i>player_x-6;i--){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i+1][player_y]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=10;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=10;
   time_13=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=10;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=10;
   time_15=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=10;
   time_16=time(NULL);
   arrow_count-=1;
   break;
   }
   if(i==(player_x-5)){
   map[i][player_y]='A';
   arrow_count-=1;
   break;
   }

   }

   break;
   }

   }

   }
   else {

noecho();
   char direction_2=getch();
   echo();

   switch(direction_2){

   case('a'):{
   for(int j=player_y-1;j>player_y-6;j--){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j+1]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=5;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=5;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=5;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=5;
   time_15=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=5;
   time_16=time(NULL);
   arrow_count-=1;
   break;
   }
   if(j==(player_y-5)){
   map[player_x][j]='A';
   arrow_count-=1;
   break;
   }

   }

   break;
   }
   case('b'):{
   for(int i=player_x+1;i<player_x+6;i++){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i-1][player_y]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=5;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=5;
   time_13=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=5;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=5;
   time_15=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=5;
   time_16=time(NULL);
   arrow_count-=1;
   break;
   }
   if(i==(player_x+5)){
   map[i][player_y]='A';
   arrow_count-=1;
   break;
   }


   }
   break;
   }
   case('c'):{
   for(int j=player_y+1;j<player_y+6;j++){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j-1]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=5;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=5;
   time_13=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=5;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=5;
   time_15=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=5;
   time_16=time(NULL);
   arrow_count-=1;
   break;
   }
   if(j==(player_y+5)){
   map[player_x][j]='A';
   arrow_count-=1;
   break;
   }


   }
   break;
   }
   case('d'):{
   for(int i=player_x-1;i>player_x-6;i--){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i+1][player_y]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=5;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=5;
   time_13=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=5;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=5;
   time_15=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=5;
   time_16=time(NULL);
   arrow_count-=1;
   break;
   }
   if(i==(player_x-5)){
   map[i][player_y]='A';
   arrow_count-=1;
   break;
   }


   }
   break;
   }

   }

   }

   }
   else {

   time_19=time(NULL);

   }

   }



   break;
   }

   case('s'):{

   clear();



for(int i=player_x-5;i<player_x+6;i++){
   for(int j=player_y-5;j<player_y+6;j++){
   if(map[i][j]=='!'){
   mvprintw(j,i,"?");
   }
   else if(map[i][j]=='t'){
   mvprintw(j,i,"^");
   }
   else if(map[i][j]=='$'){
   attron(COLOR_PAIR(2));
   mvaddstr(j,i,"🟡");
   attroff(COLOR_PAIR(2));
   }
   else if(map[i][j]=='g'){
   attron(COLOR_PAIR(2));
   mvaddstr(j,i,"⚫️");
   attroff(COLOR_PAIR(2));
   }
    else if(map[i][j]=='f'){
   attron(COLOR_PAIR(3));
   mvaddstr(j,i,"🍎");
   attroff(COLOR_PAIR(3));
   }
   else if(map[i][j]=='k'){
   attron(COLOR_PAIR(5));
   mvprintw(j,i,"∆");
   attroff(COLOR_PAIR(5));
   }
   else if(map[i][j]=='v'){
   attron(COLOR_PAIR(4));
   mvaddstr(j,i,"💨");
   attroff(COLOR_PAIR(4));
   }
   else if(map[i][j]=='d'){
   attron(COLOR_PAIR(3));
   mvaddstr(j,i,"🔥");
   attroff(COLOR_PAIR(3));
   }
   else if(map[i][j]=='h'){
   attron(COLOR_PAIR(3));
   mvaddstr(j,i,"❤️");
   attroff(COLOR_PAIR(3));
   }

   else if(map[i][j]=='o'){
   attron(COLOR_PAIR(1));
   mvaddstr(j,i,"🗡️");
   attroff(COLOR_PAIR(1));
   }
   else if(map[i][j]=='C'){
   attron(COLOR_PAIR(1));
   mvaddstr(j,i,"🗡️");
   attroff(COLOR_PAIR(1));
   }
   else if(map[i][j]=='w'){
   attron(COLOR_PAIR(1));
   mvaddstr(j,i,"🪄");
   attroff(COLOR_PAIR(1));
   }
   else if(map[i][j]=='B'){
   attron(COLOR_PAIR(1));
   mvaddstr(j,i,"🪄");
   attroff(COLOR_PAIR(1));
   }
   else if(map[i][j]=='A'){
   attron(COLOR_PAIR(1));
   mvaddstr(j,i,"🏹");
   attroff(COLOR_PAIR(1));
   }
   else if(map[i][j]=='a'){
   attron(COLOR_PAIR(1));
   mvaddstr(j,i,"🏹");
   attroff(COLOR_PAIR(1));
   }
   else if(map[i][j]=='s'){
   attron(COLOR_PAIR(1));
   mvaddstr(j,i,"⚔️");
   attroff(COLOR_PAIR(1));
   }
   else if(map[i][j]=='<'){
   if(level==4){
   mvaddstr(j,i,"💰");
   }
   else {
   mvprintw(j,i,"%c",map[i][j]);
   }
   }
   else {
  mvprintw(j,i,"%c",map[i][j]);
  }

   }
   }

   noecho();
   getch();
   echo();

   break;
   }

   case('M'):{
   clear();



   for(int j=0;j<150;j++){
   for(int k=0;k<80;k++){
   if(map[j][k]=='!'){
   mvprintw(k,j,"?");
   }
   else if(map[j][k]=='t'){
   mvprintw(k,j,"^");
   }
    else if(map[j][k]=='$'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='g'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='f'){
   mvaddstr(k,j,".");
   }
     else if(map[j][k]=='k'){
   mvprintw(k,j,".");
   }

   else if(map[j][k]=='v'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='d'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='h'){
   mvaddstr(k,j,".");
   }

   else if(map[j][k]=='o'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='C'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='B'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='A'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='w'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='a'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='s'){
   mvaddstr(k,j,".");
   }
  else if(map[j][k]=='<'){
   if(level==4){
   mvaddstr(k,j,"💰");
   }
   else {
   mvprintw(k,j,"%c",map[j][k]);
   }
   }
   else if(map[j][k]=='#'){
   mvaddstr(k,j,"\u2589");
   }
   else {
  mvprintw(k,j,"%c",map[j][k]);
  }
}
}

  for(int j=0;j<150;j++){
  for(int k=0;k<80;k++){
   if(map[j][k]=='$'){
   attron(COLOR_PAIR(2));
   mvaddstr(k,j,"🟡");
   attroff(COLOR_PAIR(2));
   }
   else if(map[j][k]=='g'){
   attron(COLOR_PAIR(2));
   mvaddstr(k,j,"⚫️");
   attroff(COLOR_PAIR(2));
   }
   else if(map[j][k]=='f'){
   attron(COLOR_PAIR(3));
   mvaddstr(k,j,"🍎");
   attroff(COLOR_PAIR(3));
   }
     else if(map[j][k]=='k'){
   attron(COLOR_PAIR(5));
   mvprintw(k,j,"∆");
   attroff(COLOR_PAIR(5));
   }

   else if(map[j][k]=='v'){
   attron(COLOR_PAIR(4));
   mvaddstr(k,j,"💨");
   attroff(COLOR_PAIR(4));
   }
   else if(map[j][k]=='d'){
   attron(COLOR_PAIR(3));
   mvaddstr(k,j,"🔥");
   attroff(COLOR_PAIR(3));
   }
   else if(map[j][k]=='h'){
   attron(COLOR_PAIR(3));
   mvaddstr(k,j,"❤️");
   attroff(COLOR_PAIR(3));
   }

   else if(map[j][k]=='o'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🗡️");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='C'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🗡️");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='B'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🪄");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='A'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🏹");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='w'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🪄");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='a'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🏹");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='s'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"⚔️");
   attroff(COLOR_PAIR(1));
   }
   }
   }


  noecho();
  getch();
  echo();
  break;
}
   case('w'):{


     noecho();
     char direction=getch();
     echo();
     switch(direction){

     case('a'):{



      while(move_player(0,-1)){}
      break;
   }

   case('b'):{



      while(move_player(1,0)){}
      break;
   }

   case('c'):{



      while(move_player(0,1)){}
      break;
   }

   case('d'):{


      while(move_player(-1,0)){}
      break;
   }

case('e'):{


      while(move_player(1,-1)){}
      break;
   }

   case('f'):{


      while(move_player(1,1)){}
      break;
   }

   case('g'):{


      while(move_player(-1,1)){}
      break;
   }

   case('h'):{


      while(move_player(-1,-1)){}
      break;
   }

   }
   break;
   }



case('S'):{

   gamedata game;

   for(int i=0;i<150;i++){
   for(int j=0;j<80;j++){
   game.map[i][j]=map[i][j];
   }
   }

   for(int i=0;i<level;i++){
   for(int j=0;j<show_corridors;j++){
   game.x_show_corridor[i][j]=x_show_corridor[i][j];
   game.y_show_corridor[i][j]=y_show_corridor[i][j];
   }
   }
   game.show_corridors=show_corridors;

    game.player_x=player_x;
    game.player_y=player_y;
    game.level = level;
    game.score = score;
    game.gold = gold;
    game.player_health=player_health;
    game.gorosnegy=gorosnegy;
    game.selected_weapon = selected_weapon;
    game.mace_count = mace_count;
    game.sword_count = sword_count;
    game.dagger_count = dagger_count;
    game.arrow_count = arrow_count;
    game.magic_wand_count = magic_wand_count;

   for(int i=0;i<level;i++){
   for(int j=0;j<6;j++){
   game.show_rooms[i][j]=show_rooms[i][j];

   game.rooms[i][j].x=rooms[i][j].x;
   game.rooms[i][j].y=rooms[i][j].y;
   game.rooms[i][j].length=rooms[i][j].length;
   game.rooms[i][j].height=rooms[i][j].height;
   game.rooms[i][j].door_1=rooms[i][j].door_1;
   game.rooms[i][j].door_2=rooms[i][j].door_2;
   game.rooms[i][j].room_type=rooms[i][j].room_type;

  }
  }

   for(int i=0;i<level;i++){
   game.rams_door_opened[i]=rams_door_opened[i];
   }
   game.speed_spell_count=speed_spell_count;
   game.damage_spell_count=damage_spell_count;
   game.health_spell_count=health_spell_count;

   game.game_difficulty=game_difficulty;
   game.player_color=player_color;

   save_game("save.dat",&game);

   finish_game=1;


   break;
   }




   }


   if(player_health<=0){
   finish_games++;
   clear();


   mvprintw(15,10,"you lose");
   mvprintw(17,10,"score : %d gold :%d ",score,gold);
   noecho();
   getch();
   echo();
   clear();


   lose_game=1;
   player_health=100;

   return 1;

    break;
    }

   if(finish_game==1){
   clear();

   return 1;

   break;
   }


   if(demon_health<=0){
   for(int i=10;i<30;i++){
   for(int j=10;j<30;j++){
   if(map[i][j]=='D'){
   map[i][j]='.';
   demon_health=5;
   score+=5;
   }
   }
   }
   }
   if(fire_health<=0){
   for(int i=10;i<30;i++){
   for(int j=10;j<30;j++){
   if(map[i][j]=='F'){
   map[i][j]='.';
   fire_health=10;
   score+=10;
   }
   }
   }
   }
   if(giant_health<=0){
   for(int i=10;i<30;i++){
   for(int j=10;j<30;j++){
   if(map[i][j]=='G'){
   map[i][j]='.';
   giant_health=15;
   score+=15;
   }
   }
   }
   }
   if(snake_health<=0){
   for(int i=10;i<30;i++){
   for(int j=10;j<30;j++){
   if(map[i][j]=='S'){
   map[i][j]='.';
   snake_health=20;
   score+=20;
   }
   }
   }
   }
   if(undeed_health<=0){
   for(int i=10;i<30;i++){
   for(int j=10;j<30;j++){
   if(map[i][j]=='U'){
   map[i][j]='.';
   undeed_health=30;
   score+=30;
   }
   }
   }
   }

   enemy_count=0;

   for(int i=5;i<35;i++){
   for(int j=5;j<35;j++){
   if(check_enemy(i,j)){
   enemy_count ++;
   }
   }
   }


   if(enemy_count==0){

   clear();

   return 1;

   break;

   }






    }



    return 1;



    }


    void handle_game(int level_1){


    if(level==5){
    if(treasure_room()){
    level++;
    }

    }

    else {

   srand(time(NULL));
   start_color();

    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);

    setlocale(LC_ALL, "");

     if(loading_game==0){
     show_corridors=0;
     }

   char player='@';

   rams_door_opened[level-1]=0;

   rams_door_opened[4]=0;

   rams_number=0;

    if(loading_game==0){
    for(int i=0;i<6;i++){

    show_rooms[level-1][i]=0;
    }
    }

    for(int i=0;i<7;i++){
   giant_moves[i]=0;
   undeed_moves[i]=0;
   stop_giant[i]=0;
   stop_snake[i]=0;
   stop_undeed[i]=1;
   }

   if(loading_game==0){
   while(map[player_x][player_y]!='#'){

   player_x=(rand()%60);
   player_y=(rand()%50);

   }
   }

   int n;
   int n_2;


   last_time=time(NULL);
   last_time_2=time(NULL);

   while(1){
   clear();



   current_time=time(NULL);
   current_time_2=time(NULL);


   if(game_difficulty==1){

   if(gorosnegy<30){
   if(current_time_2-last_time_2>=3){
   if(health_spell_effect>0){
   player_health+=10;
   }
   else {
   player_health+=4;
   }
   last_time_2=current_time_2;
   }
   }
   else if(gorosnegy<60){
   if(current_time_2-last_time_2>=3){
   if(health_spell_effect>0){
   player_health+=5;
   }
   else {
   player_health+=2;
   }
   last_time_2=current_time_2;
   }
   }
   else if(gorosnegy<=100){
   if(current_time_2-last_time_2>=7){
   if(health_spell_effect>0){
   player_health+=2;
   }
   else {
   player_health-=2;
   }
   last_time_2=current_time_2;
   }
   }
   if(current_time-last_time>=45){
   gorosnegy+=5;
   last_time=current_time;
   }
   if(gorosnegy>100){
   gorosnegy=100;
   }
   if(player_health>100){
   player_health=100;
   }


   }


   if(game_difficulty==2){

   if(gorosnegy<30){
   if(current_time_2-last_time_2>=5){
   if(health_spell_effect>0){
   player_health+=6;
   }
   else {
   player_health+=2;
   }
   last_time_2=current_time_2;
   }
   }
   else if(gorosnegy<60){
   if(current_time_2-last_time_2>=5){
   if(health_spell_effect>0){
   player_health+=3;
   }
   else {
   player_health+=1;
   }
   last_time_2=current_time_2;
   }
   }
   else if(gorosnegy<=100){
   if(current_time_2-last_time_2>=5){
   if(health_spell_effect>0){
   player_health-=0;
   }
   else {
   player_health-=4;
   }
   last_time_2=current_time_2;
   }
   }
   if(current_time-last_time>=21){
   gorosnegy+=10;
   last_time=current_time;
   }
   if(gorosnegy>100){
   gorosnegy=100;
   }
   if(player_health>100){
   player_health=100;
   }


   }

   if(game_difficulty==3){

   if(gorosnegy<30){
   if(current_time_2-last_time_2>=7){
   if(health_spell_effect>0){
   player_health+=4;
   }
   else {
   player_health+=1;
   }
   last_time_2=current_time_2;
   }
   }
   else if(gorosnegy<60){
   if(current_time_2-last_time_2>=5){
   if(health_spell_effect>0){
   player_health+=1;
   }
   else {
   player_health+=0;
   }
   last_time_2=current_time_2;
   }
   }
   else if(gorosnegy<=100){
   if(current_time_2-last_time_2>=5){
   if(health_spell_effect>0){
   player_health-=3;
   }
   else {
   player_health-=10;
   }
   last_time_2=current_time_2;
   }
   }
   if(current_time-last_time>=9){
   gorosnegy+=15;
   last_time=current_time;
   }
   if(gorosnegy>100){
   gorosnegy=100;
   }
   if(player_health>100){
   player_health=100;
   }


   }




   n=find_room_number_3(player_x,player_y);

   if(n<6){

   if(demon_health<=0){
   for(int i=rooms[level-1][n].x;i<(rooms[level-1][n].x
   +rooms[level-1][n].length);i++){
   for(int j=rooms[level-1][n].y;j<(rooms[level-1][n].y
   +rooms[level-1][n].height);j++){
   if(map[i][j]=='D'){
   map[i][j]='.';
   demon_health=5;
   score+=5;
   }
   }
   }
   }
   else if(fire_health<=0){
   for(int i=rooms[level-1][n].x;i<(rooms[level-1][n].x
   +rooms[level-1][n].length);i++){
   for(int j=rooms[level-1][n].y;j<(rooms[level-1][n].y
   +rooms[level-1][n].height);j++){
   if(map[i][j]=='F'){
   map[i][j]='.';
   fire_health=10;
   score+=10;
   }
   }
   }
   }
   else if(giant_health<=0){
   for(int i=rooms[level-1][n].x;i<(rooms[level-1][n].x
   +rooms[level-1][n].length);i++){
   for(int j=rooms[level-1][n].y;j<(rooms[level-1][n].y
   +rooms[level-1][n].height);j++){
   if(map[i][j]=='G'){
   map[i][j]='.';
   giant_health=15;
   stop_giant[n]=0;
   giant_moves[n]=0;
   score+=15;
   }
   }
   }
   }
   else if(snake_health<=0){
   for(int i=rooms[level-1][n].x;i<(rooms[level-1][n].x
   +rooms[level-1][n].length);i++){
   for(int j=rooms[level-1][n].y;j<(rooms[level-1][n].y
   +rooms[level-1][n].height);j++){
   if(map[i][j]=='S'){
   map[i][j]='.';
   snake_health=20;
   stop_snake[n]=0;
   score+=20;
   }
   }
   }
   }
   else if(undeed_health<=0){
   for(int i=rooms[level-1][n].x;i<(rooms[level-1][n].x
   +rooms[level-1][n].length);i++){
   for(int j=rooms[level-1][n].y;j<(rooms[level-1][n].y
   +rooms[level-1][n].height);j++){
   if(map[i][j]=='U'){
   map[i][j]='.';
   undeed_health=30;
   stop_undeed[n]=0;
   undeed_moves[n]=1;
   score+=30;
   }
   }
   }
   }



   }


for(int i=player_x-1;i<player_x+2;i++){
   for(int j=player_y-1;j<player_y+2;j++){
   if(map[i][j]=='D'){
   player_health-=1;
   time_7=time(NULL);
   }
   else if(map[i][j]=='F'){
   player_health-=2;
   time_8=time(NULL);
   }
else if(map[i][j]=='G'){
   if(giant_moves[n_2]==5){
   giant_moves[n_2]=0;
   }
player_health-=3;
time_9=time(NULL);
   }
else if(map[i][j]=='S'){
player_health-=4;
time_10=time(NULL);
   }
else if(map[i][j]=='U'){
if(undeed_moves[n_2]==5){
   undeed_moves[n_2]=0;
   }
stop_undeed[n_2]=0;
player_health-=5;
time_11=time(NULL);
   }

   }
   }



    n_2=find_room_number_4(player_x,player_y);

   if(n_2<6){

   for(int i=rooms[level-1][n_2].x;i<(rooms[level-1][n_2].x
   +rooms[level-1][n_2].length);i++){
   for(int j=rooms[level-1][n_2].y;j<(rooms[level-1][n_2].y
   +rooms[level-1][n_2].height);j++){
   if(map[i][j]=='G'){
   if((stop_giant[n_2]==0)&&(giant_moves[n_2]<5)){
   if((player_x<i)&&(player_y<j)){
   if((player_x!=i-1)||(player_y!=j-1)){
   if(check_enemy(i-1,j-1)==0){
   map[i-1][j-1]='G';
   map[i][j]='.';
   giant_moves[n_2]++;
   }
   i=150;
   j=80;
    }

   }
   else if((player_x<i)&&(player_y>j)){
   if((player_x!=i-1)||(player_y!=j+1)){
   if(check_enemy(i-1,j+1)==0){
   map[i-1][j+1]='G';
   map[i][j]='.';
   giant_moves[n_2]++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x<i)&&(player_y=j)){
   if(player_x!=i-1){
   if(check_enemy(i-1,j)==0){
   map[i-1][j]='G';
   map[i][j]='.';
   giant_moves[n_2]++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y<j)){
   if((player_x!=i+1)||(player_y!=j-1)){
   if(check_enemy(i+1,j-1)==0){
   map[i+1][j-1]='G';
   map[i][j]='.';
   giant_moves[n_2]++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y>j)){
   if((player_x!=i+1)||(player_y!=j+1)){
   if(check_enemy(i+1,j+1)==0){
   map[i+1][j+1]='G';
   map[i][j]='.';
   giant_moves[n_2]++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y=j)){
   if(player_x!=i+1){
   if(check_enemy(i+1,j)==0){
   map[i+1][j]='G';
   map[i][j]='.';
   giant_moves[n_2]++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y<j)){
   if(player_y!=j-1){
   if(check_enemy(i,j-1)==0){
   map[i][j-1]='G';
   map[i][j]='.';
   giant_moves[n_2]++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y>j)){
   if(player_y!=j+1){
   if(check_enemy(i,j+1)==0){
   map[i][j+1]='G';
   map[i][j]='.';
   giant_moves[n_2]++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y=j)){
   i=150;
   j=80;
   }

   }

   }

   }
   }

   for(int i=rooms[level-1][n_2].x;i<(rooms[level-1][n_2].x
   +rooms[level-1][n_2].length);i++){
   for(int j=rooms[level-1][n_2].y;j<(rooms[level-1][n_2].y
   +rooms[level-1][n_2].height);j++){

   if(map[i][j]=='S'){
   if(stop_snake[n_2]==0){
   if((player_x<i)&&(player_y<j)){
   if((player_x!=i-1)||(player_y!=j-1)){
   if(check_enemy(i-1,j-1)==0){
   map[i-1][j-1]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x<i)&&(player_y>j)){
   if((player_x!=i-1)||(player_y!=j+1)){
   if(check_enemy(i-1,j+1)==0){
   map[i-1][j+1]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x<i)&&(player_y=j)){
   if(player_x!=i-1){
   if(check_enemy(i-1,j)==0){
   map[i-1][j]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y<j)){
   if((player_x!=i+1)||(player_y!=j-1)){
   if(check_enemy(i+1,j-1)==0){
   map[i+1][j-1]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y>j)){
   if((player_x!=i+1)||(player_y!=j+1)){
   if(check_enemy(i+1,j+1)==0){
   map[i+1][j+1]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y=j)){
   if(player_x!=i+1){
   if(check_enemy(i+1,j)==0){
   map[i+1][j]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y<j)){
   if(player_y!=j-1){
   if(check_enemy(i,j-1)==0){
   map[i][j-1]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y>j)){
   if(player_y!=j+1){
   if(check_enemy(i,j+1)==0){
   map[i][j+1]='S';
   map[i][j]='.';
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y=j)){
   i=150;
   j=80;
   }

   }

   }

   }
   }

   for(int i=rooms[level-1][n_2].x;i<(rooms[level-1][n_2].x
   +rooms[level-1][n_2].length);i++){
   for(int j=rooms[level-1][n_2].y;j<(rooms[level-1][n_2].y
   +rooms[level-1][n_2].height);j++){

   if(map[i][j]=='U'){
   if((stop_undeed[n_2]==0)&&(undeed_moves[n_2]<5)){
   if((player_x<i)&&(player_y<j)){
   if((player_x!=i-1)||(player_y!=j-1)){
   if(check_enemy(i-1,j-1)==0){
   map[i-1][j-1]='U';
   map[i][j]='.';
   undeed_moves[n_2]++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x<i)&&(player_y>j)){
   if((player_x!=i-1)||(player_y!=j+1)){
   if(check_enemy(i-1,j+1)==0){
   map[i-1][j+1]='U';
   map[i][j]='.';
   undeed_moves[n_2]++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x<i)&&(player_y=j)){
   if(player_x!=i-1){
   if(check_enemy(i-1,j)==0){
   map[i-1][j]='U';
   map[i][j]='.';
   undeed_moves[n_2]++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y<j)){
   if((player_x!=i+1)||(player_y!=j-1)){
   if(check_enemy(i+1,j-1)==0){
   map[i+1][j-1]='U';
   map[i][j]='.';
   undeed_moves[n_2]++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y>j)){
   if((player_x!=i+1)||(player_y!=j+1)){
   if(check_enemy(i+1,j+1)==0){
   map[i+1][j+1]='U';
   map[i][j]='.';
   undeed_moves[n_2]++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x>i)&&(player_y=j)){
   if(player_x!=i+1){
   if(check_enemy(i+1,j)==0){
   map[i+1][j]='U';
   map[i][j]='.';
   undeed_moves[n_2]++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y<j)){
   if(player_y!=j-1){
   if(check_enemy(i,j-1)==0){
   map[i][j-1]='U';
   map[i][j]='.';
   undeed_moves[n_2]++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y>j)){
   if(player_y!=j+1){
   if(check_enemy(i,j+1)==0){
   map[i][j+1]='U';
   map[i][j]='.';
   undeed_moves[n_2]++;
   }
   i=150;
   j=80;
   }

   }
   else if((player_x=i)&&(player_y=j)){
   i=150;
   j=80;
   }

   }

   }


   }

   }



     }


   if(map[stair_x][stair_y]!='<'){

   if((map[stair_x][stair_y]=='D')||
    (map[stair_x][stair_y]=='F')||
    (map[stair_x][stair_y]=='G')||
    (map[stair_x][stair_y]=='S')||
    (map[stair_x][stair_y]=='U')){

    }
    else {
   map[stair_x][stair_y]='<';
   }

   }



   for(int i=player_x-5;i<player_x+6;i++){
   for(int j=player_y-5;j<player_y+6;j++){
   if(map[i][j]=='!'){
   mvprintw(j,i,"-");
   }
   else if(map[i][j]=='#'){
   if((i!=player_x)||(j!=player_y)){
   mvaddstr(j,i,"\u258A");
   }
   }
   else if(map[i][j]=='|'){
   mvprintw(j,i,"%c",map[i][j]);
   }
   else if(map[i][j]=='-'){
   mvprintw(j,i,"%c",map[i][j]);
   }
   else if(map[i][j]=='+'){
   mvprintw(j,i,"%c",map[i][j]);
   }
   else if(map[i][j]=='&'){
   mvprintw(j,i,"%c",map[i][j]);
   }
   else if(map[i][j]=='@'){
   if(rams_door_opened[level-1]!=0){
   attron(COLOR_PAIR(3));
   mvprintw(j,i,"@");
  attroff(COLOR_PAIR(3));
   }
   else{
   attron(COLOR_PAIR(2));
   mvprintw(j,i,"@");
   attroff(COLOR_PAIR(2));
   }

   }



   }
   }

   for(int i=0;i<6;i++){
   if(show_rooms[level-1][i]==1){
   if(rooms[level-1][i].room_type==1){

for(int j=rooms[level-1][i].x;j<rooms[level-1][i].x+rooms[level-1][i].length+1;j++){
   for(int k=rooms[level-1][i].y;k<rooms[level-1][i].y+rooms[level-1][i].height+1;k++){
   if(map[j][k]=='!'){
  attron(COLOR_PAIR(4));
  mvprintw(k,j,"-");
  attroff(COLOR_PAIR(4));
   }
   else if(map[j][k]=='t'){
   attron(COLOR_PAIR(4));
   mvprintw(k,j,".");
   attroff(COLOR_PAIR(4));
   }

    else if(map[j][k]=='$'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='g'){
   mvaddstr(k,j,".");
   }
     else if(map[j][k]=='k'){
   mvprintw(k,j,".");
   }
   else if(map[j][k]=='f'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='v'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='d'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='h'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='o'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='C'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='w'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='a'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='B'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='A'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='s'){
   mvaddstr(k,j,".");
   }
else if(map[j][k]=='<'){
   if(level==4){
   mvaddstr(k,j,"💰");
   }
   else {
   mvprintw(k,j,"%c",map[j][k]);
   }
   }
   else if(map[j][k]=='@'){
   if(rams_door_opened[level-1]!=0){
   attron(COLOR_PAIR(3));
   mvprintw(k,j,"@");
  attroff(COLOR_PAIR(3));
   }
   else {
   attron(COLOR_PAIR(2));
   mvprintw(k,j,"@");
   attroff(COLOR_PAIR(2));
   }
   }
   else {
  mvprintw(k,j,"%c",map[j][k]);
  }

   }

   }
   for(int j=rooms[level-1][i].x;j<rooms[level-1][i].x+rooms[level-1][i].length+1;j++){
   for(int k=rooms[level-1][i].y;k<rooms[level-1][i].y+rooms[level-1][i].height+1;k++){

if(map[j][k]=='$'){
   attron(COLOR_PAIR(2));
   mvaddstr(k,j,"🟡");
   attroff(COLOR_PAIR(2));
   }
   else if(map[j][k]=='g'){
   attron(COLOR_PAIR(2));
   mvaddstr(k,j,"⚫️");
   attroff(COLOR_PAIR(2));
   }
   else if(map[j][k]=='k'){
   attron(COLOR_PAIR(5));
   mvprintw(k,j,"∆");
   attroff(COLOR_PAIR(5));
   }
   else if(map[j][k]=='f'){
   attron(COLOR_PAIR(3));
   mvaddstr(k,j,"🍎");
   attroff(COLOR_PAIR(3));
   }
   else if(map[j][k]=='v'){
   attron(COLOR_PAIR(4));
   mvaddstr(k,j,"💨");
   attroff(COLOR_PAIR(4));
   }
   else if(map[j][k]=='d'){
   attron(COLOR_PAIR(3));
   mvaddstr(k,j,"🔥");
   attroff(COLOR_PAIR(3));
   }
   else if(map[j][k]=='h'){
   attron(COLOR_PAIR(3));
   mvaddstr(k,j,"❤️");
   attroff(COLOR_PAIR(3));
   }
   else if(map[j][k]=='o'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🗡️");
    attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='C'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🗡️");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='w'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🪄");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='a'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🏹");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='B'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🪄");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='A'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🏹");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='s'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"⚔️");
   attroff(COLOR_PAIR(1));
   }

   }

   }


   }

   else {
   for(int j=rooms[level-1][i].x;j<rooms[level-1][i].x+rooms[level-1][i].length+1;j++){
   for(int k=rooms[level-1][i].y;k<rooms[level-1][i].y+rooms[level-1][i].height+1;k++){
   if(map[j][k]=='!'){
  attron(COLOR_PAIR(4));
   mvprintw(k,j,"-");
  attroff(COLOR_PAIR(4));
   }
   else if(map[j][k]=='t'){
   attron(COLOR_PAIR(4));
   mvprintw(k,j,".");
   attroff(COLOR_PAIR(4));
   }

    else if(map[j][k]=='$'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='g'){
   mvaddstr(k,j,".");
   }
     else if(map[j][k]=='k'){
   mvprintw(k,j,".");
   }
   else if(map[j][k]=='f'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='v'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='d'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='h'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='o'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='C'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='w'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='a'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='B'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='A'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='s'){
   mvaddstr(k,j,".");
   }
else if(map[j][k]=='<'){
   if(level==4){
   mvaddstr(k,j,"💰");
   }
   else {
   mvprintw(k,j,"%c",map[j][k]);
   }
   }
   else if(map[j][k]=='@'){
   if(rams_door_opened[level-1]!=0){
   attron(COLOR_PAIR(3));
   mvprintw(k,j,"@");
  attroff(COLOR_PAIR(3));
   }
   else {
   attron(COLOR_PAIR(2));
   mvprintw(k,j,"@");
   attroff(COLOR_PAIR(2));
   }
   }
   else {
  attron(COLOR_PAIR(4));
  mvprintw(k,j,"%c",map[j][k]);
  attroff(COLOR_PAIR(4));
  }

   }

   }

for(int j=rooms[level-1][i].x;j<rooms[level-1][i].x+rooms[level-1][i].length+1;j++){
   for(int k=rooms[level-1][i].y;k<rooms[level-1][i].y+rooms[level-1][i].height+1;k++){

if(map[j][k]=='$'){
   attron(COLOR_PAIR(2));
   mvaddstr(k,j,"🟡");
   attroff(COLOR_PAIR(2));
   }
   else if(map[j][k]=='g'){
   attron(COLOR_PAIR(2));
   mvaddstr(k,j,"⚫️");
   attroff(COLOR_PAIR(2));
   }
   else if(map[j][k]=='k'){
   attron(COLOR_PAIR(5));
   mvprintw(k,j,"∆");
   attroff(COLOR_PAIR(5));
   }
   else if(map[j][k]=='f'){
   attron(COLOR_PAIR(3));
   mvaddstr(k,j,"🍎");
   attroff(COLOR_PAIR(3));
   }
   else if(map[j][k]=='v'){
   attron(COLOR_PAIR(4));
   mvaddstr(k,j,"💨");
   attroff(COLOR_PAIR(4));
   }
   else if(map[j][k]=='d'){
   attron(COLOR_PAIR(3));
   mvaddstr(k,j,"🔥");
   attroff(COLOR_PAIR(3));
   }
   else if(map[j][k]=='h'){
   attron(COLOR_PAIR(3));
   mvaddstr(k,j,"❤️");
   attroff(COLOR_PAIR(3));
   }
   else if(map[j][k]=='o'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🗡️");
    attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='C'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🗡️");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='w'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🪄");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='a'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🏹");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='B'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🪄");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='A'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🏹");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='s'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"⚔️");
   attroff(COLOR_PAIR(1));
   }

   }

   }


   }

   }
   }



   for(int i=0;i<show_corridors;i++){
    mvaddstr(y_show_corridor[level-1][i],x_show_corridor[level-1][i],"\u258A");
   }


   if(player_color==1){
   mvprintw(player_y,player_x,"%c",player);
   }
   else if(player_color==2){
   attron(COLOR_PAIR(5));
   mvprintw(player_y,player_x,"%c",player);
   attroff(COLOR_PAIR(5));
   }

else if(player_color==3){
   start_color();
   attron(COLOR_PAIR(2));
   mvprintw(player_y,player_x,"%c",player);
   attroff(COLOR_PAIR(2));
   }

else if(player_color==4){
   attron(COLOR_PAIR(3));
   mvprintw(player_y,player_x,"%c",player);
   attroff(COLOR_PAIR(3));
   }

else if(player_color==5){
   attron(COLOR_PAIR(4));
   mvprintw(player_y,player_x,"%c",player);
   attroff(COLOR_PAIR(4));
   }




   if(current_time-time_1<=10){
   mvprintw(2,60,"You save gold");
   }

   if(current_time-time_2<=10){
   mvprintw(3,10,"You get food");
   }

   if(current_time-time_3<=10){
   mvprintw(2,10,"You fall in trap");
   }

   if(current_time-time_4<=30){
   if(rams_number!=0){
   mvprintw(80,50,"rams : %d",rams_number);
   }
   }

if(current_time-time_5<=10){
   mvprintw(1,60,"You go to new floor");
   }

if(current_time-time_6<=10){
   mvprintw(1,10,"You go to new room");
   }

   if(current_time-time_7<=10){
   mvprintw(77,30,"The Demon attacked you");
   }

if(current_time-time_8<=10){
   mvprintw(77,30,"The Fire Breathing Monster attacked you");
   }

if(current_time-time_9<=10){
   mvprintw(77,30,"The Giant attacked you");
   }

if(current_time-time_10<=10){
   mvprintw(77,30,"The Snake attacked you");
   }

if(current_time-time_11<=10){
   mvprintw(77,30,"The Undeed attacked you");
   }

   if(current_time-time_12<=5){
   if(demon_health==5){
   mvprintw(78,30,"You kill the Demon");
   }
   else {
   mvprintw(78,30,"Demon : health : %d",demon_health);
   }
   }

   if(current_time-time_13<=5){
   if(fire_health==10){
   mvprintw(78,30,"You kill the Fire Breathing Monster");
   }
   else {
   mvprintw(78,30,"Fire Breathing Monster : health : %d",fire_health);
   }
   }

   if(current_time-time_14<=5){
   if(giant_health==15){
   mvprintw(78,30,"You kill the Giant");
   }
   else {
   mvprintw(78,30,"Giant : health : %d",giant_health);
   }
   }

   if(current_time-time_15<=5){
   if(snake_health==20){
   mvprintw(78,30,"You kill the Snake");
   }
   else {
   mvprintw(78,30,"Snake : health : %d",snake_health);
   }
   }

   if(current_time-time_16<=5){
   if(undeed_health==30){
   mvprintw(78,30,"You kill the Undeed");
   }
   else {
   mvprintw(78,30,"Undeed : health : %d",undeed_health);
   }
   }

   if(current_time-time_17<=5){
   mvprintw(79,50,"You have not Dagger in your backpack");
   }

   if(current_time-time_18<=5){
   mvprintw(79,50,"You have not Magic Wand in your backpack");
   }

   if(current_time-time_19<=5){
   mvprintw(79,50,"You have not Normal Arrow in your backpack");
   }



switch(gorosnegy){

   case(0):{
   attron(COLOR_PAIR(3));
   mvprintw(81,5,"🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩");
   attroff(COLOR_PAIR(3));
   break;
   }
   case(10):case(5):case(15):{
   attron(COLOR_PAIR(3));
   mvprintw(81,5,"🟩🟩🟩🟩🟩🟩🟩🟩🟩");
   attroff(COLOR_PAIR(3));
   break;
   }
   case(20):case(25):{
   attron(COLOR_PAIR(3));
   mvprintw(81,5,"🟩🟩🟩🟩🟩🟩🟩🟩");
   attroff(COLOR_PAIR(3));
   break;
   }
   case(30):case(35):{
   attron(COLOR_PAIR(5));
   mvprintw(81,5,"🟨🟨🟨🟨🟨🟨🟨");
   attroff(COLOR_PAIR(5));
   break;
   }
   case(40):case(45):{
   attron(COLOR_PAIR(5));
   mvprintw(81,5,"🟨🟨🟨🟨🟨🟨");
   attroff(COLOR_PAIR(5));
   break;
   }
case(50):case(55):{
   attron(COLOR_PAIR(5));
   mvprintw(81,5,"🟨🟨🟨🟨🟨");
   attroff(COLOR_PAIR(5));
   break;
   }
case(60):case(65):{
   attron(COLOR_PAIR(2));
   mvprintw(81,5,"🟥🟥🟥🟥");
   attroff(COLOR_PAIR(2));
   break;
   }
case(70):case(75):{
   attron(COLOR_PAIR(2));
   mvprintw(81,5,"🟥🟥🟥");
   attroff(COLOR_PAIR(2));
   break;
   }
case(80):case(85):{
   attron(COLOR_PAIR(2));
   mvprintw(81,5,"🟥🟥");
   attroff(COLOR_PAIR(2));
   break;
   }
case(90):case(95):{
   attron(COLOR_PAIR(2));
   mvprintw(81,5,"🟥");
   attroff(COLOR_PAIR(2));
   break;
   }
case(100):{
   attron(COLOR_PAIR(2));
   mvprintw(81,5,"🟥");
   attroff(COLOR_PAIR(2));
   break;
   }

    }


   mvprintw(82,5,"foods_number : %d",food_count);
   mvprintw(83,5,"score : %d  gold : %d  floor : %d  health : %d  ",score,gold,level,player_health);
   noecho();
   char z=getch();
   echo();
      switch(z){

      case('a'):{


   if(speed_spell_effect>0){
   move_player(0,-2);
   }
   else {
   move_player(0,-1);
   }
    break;
   }

   case('b'):{


   if(speed_spell_effect>0){
   move_player(2,0);
   }
   else {
   move_player(1,0);
   }
      break;
   }

   case('c'):{


    if(speed_spell_effect>0){
   move_player(0,2);
   }
   else {
   move_player(0,1);
   }
      break;
   }

   case('d'):{


   if(speed_spell_effect>0){
   move_player(-2,0);
   }
   else {
   move_player(-1,0);
   }
      break;
   }

   case('e'):{


    if(speed_spell_effect>0){
   move_player(2,-2);
   }
   else {
   move_player(1,-1);
    }
   break;
   }

   case('f'):{


    if(speed_spell_effect>0){
   move_player(2,2);
   }
   else {
   move_player(1,1);
   }
   break;
   }

   case('g'):{


  if(speed_spell_effect>0){
   move_player(-2,2);
   }
   else {
   move_player(-1,1);
   }
    break;
   }

   case('h'):{


   if(speed_spell_effect>0){
   move_player(-2,-2);
   }
   else {
   move_player(-1,-1);
   }
   break;
   }

   case('p'):{




noecho();
   char h=getch();
   echo();
      switch(h){

      case('a'):{


      move_player(0,-2);
      break;
   }

   case('b'):{


      move_player(2,0);
      break;
   }

   case('c'):{


      move_player(0,2);
      break;
   }

   case('d'):{


      move_player(-2,0);
      break;
   }

   case('e'):{


      move_player(2,-2);
      break;
   }

   case('f'):{


      move_player(2,2);
      break;
   }

   case('g'):{


      move_player(-2,2);
      break;
   }

   case('h'):{


      move_player(-2,-2);
      break;
   }

   }

   break;
   }

    case('q'):{



    no_get='g';

   noecho();
   char h=getch();
   echo();
      switch(h){

      case('a'):{


      move_player(0,-1);
      break;
   }

   case('b'):{


      move_player(1,0);
      break;
   }

   case('c'):{


      move_player(0,1);
      break;
   }

   case('d'):{


      move_player(-1,0);
      break;
   }

   case('e'):{



    move_player(1,-1);
      break;
   }

   case('f'):{


      move_player(1,1);
      break;
   }

   case('g'):{


      move_player(-1,1);
      break;
   }

   case('h'):{


      move_player(-1,-1);
      break;
   }

   }

    break;
    }

   case('r'):{


   finish_game=1;
   break;
   }

   case('i'):{


   show_assets();
   break;
   }

   case('E'):{


   using_food_page();
   break;
   }

   case(' '):{



   if(selected_weapon==1){
   if(damage_spell_effect>0){
   for(int i=player_x-1;i<player_x+2;i++){
   for(int j=player_y-1;j<player_y+2;j++){
   if(map[i][j]=='D'){
   demon_health-=10;
   time_12=time(NULL);
   }
   else if(map[i][j]=='F'){
   fire_health-=10;
   time_13=time(NULL);
   }
   else if(map[i][j]=='G'){
   giant_health-=10;
   time_14=time(NULL);
   }
else if(map[i][j]=='S'){
    snake_health-=10;
   time_15=time(NULL);
   }
else if(map[i][j]=='U'){
   undeed_health-=10;
   time_16=time(NULL);
   }
   }
   }
   }
   else {
   for(int i=player_x-1;i<player_x+2;i++){
   for(int j=player_y-1;j<player_y+2;j++){
   if(map[i][j]=='D'){
   demon_health-=5;
   time_12=time(NULL);
   }
   else if(map[i][j]=='F'){
   fire_health-=5;
   time_13=time(NULL);
   }
   else if(map[i][j]=='G'){
   giant_health-=5;
   time_14=time(NULL);
   }
else if(map[i][j]=='S'){
    snake_health-=5;
   time_15=time(NULL);
   }
else if(map[i][j]=='U'){
   undeed_health-=5;
   time_16=time(NULL);
   }
   }
   }
   }

   }

   else if(selected_weapon==5){
   if(damage_spell_effect>0){
   for(int i=player_x-1;i<player_x+2;i++){
   for(int j=player_y-1;j<player_y+2;j++){
   if(map[i][j]=='D'){
   demon_health-=20;
   time_12=time(NULL);
   }
   else if(map[i][j]=='F'){
   fire_health-=20;
   time_13=time(NULL);
   }
   else if(map[i][j]=='G'){
   giant_health-=20;
   time_14=time(NULL);
   }
else if(map[i][j]=='S'){
    snake_health-=20;
   time_15=time(NULL);
   }
else if(map[i][j]=='U'){
   undeed_health-=20;
   time_16=time(NULL);
   }

   }
   }
   }
   else {
for(int i=player_x-1;i<player_x+2;i++){
   for(int j=player_y-1;j<player_y+2;j++){
   if(map[i][j]=='D'){
   demon_health-=10;
   time_12=time(NULL);
   }
   else if(map[i][j]=='F'){
   fire_health-=10;
   time_13=time(NULL);
   }
   else if(map[i][j]=='G'){
   giant_health-=10;
   time_14=time(NULL);
   }
else if(map[i][j]=='S'){
    snake_health-=10;
   time_15=time(NULL);
   }
else if(map[i][j]=='U'){
   undeed_health-=10;
   time_16=time(NULL);
   }

   }
   }
   }
   }


   else if(selected_weapon==2){
   if(dagger_count!=0){
   if(damage_spell_effect>0){

   noecho();
   char direction_2=getch();
   echo();

   switch(direction_2){

   case('a'):{
   for(int j=player_y-1;j>player_y-6;j--){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j+1]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=24;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=24;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=24;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=24;
   time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=24;
   time(NULL);
   dagger_count-=1;
   break;
   }
   if(j==(player_y-5)){
   map[player_x][j]='C';
   dagger_count-=1;
   break;
   }

   }

   break;
   }

   case('b'):{
   for(int i=player_x+1;i<player_x+6;i++){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i-1][player_y]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=24;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=24;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=24;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=24;
   time_15=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=24;
   time_16=time(NULL);
   dagger_count-=1;
   break;
   }
   if(i==(player_x+5)){
   map[i][player_y]='C';
   dagger_count-=1;
   break;
   }

   }

   break;
   }

   case('c'):{
   for(int j=player_y+1;j<player_y+6;j++){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j-1]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=24;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=24;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=24;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=24;
   time_15=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=24;
   time_16=time(NULL);
   dagger_count-=1;
   break;
   }
   if(j==(player_y+5)){
   map[player_x][j]='C';
   dagger_count-=1;
   break;
   }

   }

   break;
   }

   case('d'):{
   for(int i=player_x-1;i>player_x-6;i--){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i+1][player_y]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=24;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=24;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=24;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=24;
   time_15=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=24;
   time_16=time(NULL);
   dagger_count-=1;
   break;
   }
   if(i==(player_x-5)){
   map[i][player_y]='C';
   dagger_count-=1;
   break;
   }

   }

   break;
   }

   }

   }



   else {

noecho();
   char direction_2=getch();
   echo();

   switch(direction_2){

   case('a'):{
   for(int j=player_y-1;j>player_y-6;j--){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j+1]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=12;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=12;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=12;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=12;
   time_15=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=12;
   time_16=time(NULL);
   dagger_count-=1;
   break;
   }
   if(j==(player_y-5)){
   map[player_x][j]='C';
   dagger_count-=1;
   break;
   }

   }

   break;
   }

   case('b'):{
   for(int i=player_x+1;i<player_x+6;i++){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i-1][player_y]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=12;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=12;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=12;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=12;
   time_15=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=12;
   time_16=time(NULL);
   dagger_count-=1;
   break;
   }
   if(i==(player_x+5)){
   map[i][player_y]='C';
   dagger_count-=1;
   break;
   }


   }
   break;
   }

   case('c'):{
   for(int j=player_y+1;j<player_y+6;j++){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j-1]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=12;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=12;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=12;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=12;
   time_15=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=12;
   time_16=time(NULL);
   dagger_count-=1;
   break;
   }
   if(j==(player_y+5)){
   map[player_x][j]='C';
   dagger_count-=1;
   break;
   }


   }
   break;
   }

   case('d'):{
   for(int i=player_x-1;i>player_x-6;i--){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i+1][player_y]='C';
   dagger_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=12;
   time_12=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=12;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=12;
   time_14=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=12;
   time_15=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=12;
   time_16=time(NULL);
   dagger_count-=1;
   break;
   }
   if(i==(player_x-5)){
   map[i][player_y]='C';
   dagger_count-=1;
   break;
   }


   }
   break;
   }

   }

   }

   }

   else {

   time_17=time(NULL);

   }

   }

else if(selected_weapon==3){
   if(magic_wand_count!=0){
   if(damage_spell_effect>0){

   noecho();
   char direction_2=getch();
   echo();

   switch(direction_2){

   case('a'):{
   for(int j=player_y-1;j>player_y-11;j--){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j+1]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=30;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=30;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=30;
   stop_giant[n_2]=1;
   time_14=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=30;
   stop_snake[n_2]=1;
   time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=30;
   stop_undeed[n_2]=1;
   time(NULL);
   magic_wand_count-=1;
   break;
   }
   if(j==(player_y-10)){
   map[player_x][j]='B';
   magic_wand_count-=1;
   break;
   }

   }

   break;
   }
    case('b'):{
   for(int i=player_x+1;i<player_x+11;i++){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i-1][player_y]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=30;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=30;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=30;
   stop_giant[n_2]=1;
   time_14=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=30;
   stop_snake[n_2]=1;
   time_15=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=30;
   stop_undeed[n_2]=1;
   time_16=time(NULL);
   magic_wand_count-=1;
   break;
   }
   if(i==(player_x+10)){
   map[i][player_y]='B';
   magic_wand_count-=1;
   break;
   }

   }

   break;
   }
   case('c'):{
   for(int j=player_y+1;j<player_y+11;j++){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j-1]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=30;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=30;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=30;
   stop_giant[n_2]=1;
   time_14=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=30;
   stop_snake[n_2]=1;
   time_15=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=30;
   stop_undeed[n_2]=1;
   time_16=time(NULL);
   magic_wand_count-=1;
   break;
   }
   if(j==(player_y+10)){
   map[player_x][j]='B';
   magic_wand_count-=1;
   break;
   }

   }

   break;
   }
   case('d'):{
   for(int i=player_x-1;i>player_x-11;i--){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i+1][player_y]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=30;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=30;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=30;
   stop_giant[n_2]=1;
   time_14=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=30;
   stop_snake[n_2]=1;
   time_15=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=30;
   stop_undeed[n_2]=1;
   time_16=time(NULL);
   magic_wand_count-=1;
   break;
   }
   if(i==(player_x-10)){
   map[i][player_y]='B';
   magic_wand_count-=1;
   break;
   }

   }

   break;
   }

   }

   }
   else {

noecho();
   char direction_2=getch();
   echo();

   switch(direction_2){

   case('a'):{
   for(int j=player_y-1;j>player_y-11;j--){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j+1]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=15;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=15;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=15;
   stop_giant[n_2]=1;
   time_14=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=15;
   stop_snake[n_2]=1;
   time_15=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=15;
   stop_undeed[n_2]=1;
   time_16=time(NULL);
   magic_wand_count-=1;
   break;
   }
   if(j==(player_y-10)){
   map[player_x][j]='B';
   magic_wand_count-=1;
   break;
   }

   }

   break;
   }
   case('b'):{
   for(int i=player_x+1;i<player_x+11;i++){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i-1][player_y]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=15;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=15;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=15;
   stop_giant[n_2]=1;
   time_14=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=15;
   stop_snake[n_2]=1;
   time_15=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=15;
   stop_undeed[n_2]=1;
   time_16=time(NULL);
   magic_wand_count-=1;
   break;
   }
   if(i==(player_x+10)){
   map[i][player_y]='B';
   magic_wand_count-=1;
   break;
   }


   }
   break;
   }
   case('c'):{
   for(int j=player_y+1;j<player_y+11;j++){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j-1]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=15;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=15;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=15;
   stop_giant[n_2]=1;
   time_14=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=15;
   stop_snake[n_2]=1;
   time_15=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=15;
   stop_undeed[n_2]=1;
   time_16=time(NULL);
   magic_wand_count-=1;
   break;
   }
   if(j==(player_y+10)){
   map[player_x][j]='B';
   magic_wand_count-=1;
   break;
   }


   }
   break;
   }
   case('d'):{
   for(int i=player_x-1;i>player_x-11;i--){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i+1][player_y]='B';
   magic_wand_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=15;
   time_12=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=15;
   time_13=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=15;
   stop_giant[n_2]=1;
   time_14=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=15;
   stop_snake[n_2]=1;
   time_15=time(NULL);
   magic_wand_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=15;
   stop_undeed[n_2]=1;
   time_16=time(NULL);
   magic_wand_count-=1;
   break;
   }
   if(i==(player_x-10)){
   map[i][player_y]='B';
   magic_wand_count-=1;
   break;
   }


   }
   break;
   }

   }

   }

   }
   else {

   time_18=time(NULL);

   }

   }

else if(selected_weapon==4){
   if(arrow_count!=0){
   if(damage_spell_effect>0){

   noecho();
   char direction_2=getch();
   echo();

   switch(direction_2){

   case('a'):{
   for(int j=player_y-1;j>player_y-6;j--){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j+1]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=10;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=10;
   time_13=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=10;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=10;
   time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=10;
   time(NULL);
   arrow_count-=1;
   break;
   }
   if(j==(player_y-5)){
   map[player_x][j]='A';
   arrow_count-=1;
   break;
   }

   }

   break;
   }
    case('b'):{
   for(int i=player_x+1;i<player_x+6;i++){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i-1][player_y]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=10;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=10;
   time_13=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=10;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=10;
   time_15=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=10;
   time_16=time(NULL);
   arrow_count-=1;
   break;
   }
   if(i==(player_x+5)){
   map[i][player_y]='A';
   arrow_count-=1;
   break;
   }

   }

   break;
   }
   case('c'):{
   for(int j=player_y+1;j<player_y+6;j++){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j-1]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=10;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=10;
   time_13=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=10;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=10;
   time_15=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=10;
   time_16=time(NULL);
   arrow_count-=1;
   break;
   }
   if(j==(player_y+5)){
   map[player_x][j]='A';
   arrow_count-=1;
   break;
   }

   }

   break;
   }
   case('d'):{
   for(int i=player_x-1;i>player_x-6;i--){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i+1][player_y]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=10;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=10;
   time_13=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=10;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=10;
   time_15=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=10;
   time_16=time(NULL);
   arrow_count-=1;
   break;
   }
   if(i==(player_x-5)){
   map[i][player_y]='A';
   arrow_count-=1;
   break;
   }

   }

   break;
   }

   }

   }
   else {

noecho();
   char direction_2=getch();
   echo();

   switch(direction_2){

   case('a'):{
   for(int j=player_y-1;j>player_y-6;j--){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j+1]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=5;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=5;
   time_13=time(NULL);
   dagger_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=5;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=5;
   time_15=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=5;
   time_16=time(NULL);
   arrow_count-=1;
   break;
   }
   if(j==(player_y-5)){
   map[player_x][j]='A';
   arrow_count-=1;
   break;
   }

   }

   break;
   }
   case('b'):{
   for(int i=player_x+1;i<player_x+6;i++){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i-1][player_y]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=5;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=5;
   time_13=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=5;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=5;
   time_15=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=5;
   time_16=time(NULL);
   arrow_count-=1;
   break;
   }
   if(i==(player_x+5)){
   map[i][player_y]='A';
   arrow_count-=1;
   break;
   }


   }
   break;
   }
   case('c'):{
   for(int j=player_y+1;j<player_y+6;j++){
   if((map[player_x][j]=='-')||(map[player_x][j]=='O')){
   map[player_x][j-1]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[player_x][j]=='D'){
   demon_health-=5;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='F'){
   fire_health-=5;
   time_13=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='G'){
   giant_health-=5;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='S'){
   snake_health-=5;
   time_15=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[player_x][j]=='U'){
   undeed_health-=5;
   time_16=time(NULL);
   arrow_count-=1;
   break;
   }
   if(j==(player_y+5)){
   map[player_x][j]='A';
   arrow_count-=1;
   break;
   }


   }
   break;
   }
   case('d'):{
   for(int i=player_x-1;i>player_x-6;i--){
   if((map[i][player_y]=='|')||(map[i][player_y]=='O')){
   map[i+1][player_y]='A';
   arrow_count-=1;
   move_player(0,0);
   break;
   }
   else if(map[i][player_y]=='D'){
   demon_health-=5;
   time_12=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='F'){
   fire_health-=5;
   time_13=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='G'){
   giant_health-=5;
   time_14=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='S'){
   snake_health-=5;
   time_15=time(NULL);
   arrow_count-=1;
   break;
   }
   else if(map[i][player_y]=='U'){
   undeed_health-=5;
   time_16=time(NULL);
   arrow_count-=1;
   break;
   }
   if(i==(player_x-5)){
   map[i][player_y]='A';
   arrow_count-=1;
   break;
   }


   }
   break;
   }

   }

   }

   }
   else {

   time_19=time(NULL);

   }

   }



   break;
   }

   case('s'):{

   clear();



for(int i=player_x-5;i<player_x+6;i++){
   for(int j=player_y-5;j<player_y+6;j++){
   if(map[i][j]=='!'){
   mvprintw(j,i,"?");
   }
   else if(map[i][j]=='t'){
   mvprintw(j,i,"^");
   }
   else if(map[i][j]=='$'){
   attron(COLOR_PAIR(2));
   mvaddstr(j,i,"🟡");
   attroff(COLOR_PAIR(2));
   }
   else if(map[i][j]=='g'){
   attron(COLOR_PAIR(2));
   mvaddstr(j,i,"⚫️");
   attroff(COLOR_PAIR(2));
   }
    else if(map[i][j]=='f'){
   attron(COLOR_PAIR(3));
   mvaddstr(j,i,"🍎");
   attroff(COLOR_PAIR(3));
   }
   else if(map[i][j]=='k'){
   attron(COLOR_PAIR(5));
   mvprintw(j,i,"∆");
   attroff(COLOR_PAIR(5));
   }
   else if(map[i][j]=='v'){
   attron(COLOR_PAIR(4));
   mvaddstr(j,i,"💨");
   attroff(COLOR_PAIR(4));
   }
   else if(map[i][j]=='d'){
   attron(COLOR_PAIR(3));
   mvaddstr(j,i,"🔥");
   attroff(COLOR_PAIR(3));
   }
   else if(map[i][j]=='h'){
   attron(COLOR_PAIR(3));
   mvaddstr(j,i,"❤️");
   attroff(COLOR_PAIR(3));
   }

   else if(map[i][j]=='o'){
   attron(COLOR_PAIR(1));
   mvaddstr(j,i,"🗡️");
   attroff(COLOR_PAIR(1));
   }
   else if(map[i][j]=='C'){
   attron(COLOR_PAIR(1));
   mvaddstr(j,i,"🗡️");
   attroff(COLOR_PAIR(1));
   }
   else if(map[i][j]=='w'){
   attron(COLOR_PAIR(1));
   mvaddstr(j,i,"🪄");
   attroff(COLOR_PAIR(1));
   }
   else if(map[i][j]=='B'){
   attron(COLOR_PAIR(1));
   mvaddstr(j,i,"🪄");
   attroff(COLOR_PAIR(1));
   }
   else if(map[i][j]=='A'){
   attron(COLOR_PAIR(1));
   mvaddstr(j,i,"🏹");
   attroff(COLOR_PAIR(1));
   }
   else if(map[i][j]=='a'){
   attron(COLOR_PAIR(1));
   mvaddstr(j,i,"🏹");
   attroff(COLOR_PAIR(1));
   }
   else if(map[i][j]=='s'){
   attron(COLOR_PAIR(1));
   mvaddstr(j,i,"⚔️");
   attroff(COLOR_PAIR(1));
   }
   else if(map[i][j]=='<'){
   if(level==4){
   mvaddstr(j,i,"💰");
   }
   else {
   mvprintw(j,i,"%c",map[i][j]);
   }
   }
   else {
  mvprintw(j,i,"%c",map[i][j]);
  }

   }
   }

   noecho();
   getch();
   echo();

   break;
   }

   case('M'):{
   clear();



   for(int j=0;j<150;j++){
   for(int k=0;k<80;k++){
   if(map[j][k]=='!'){
   mvprintw(k,j,"?");
   }
   else if(map[j][k]=='t'){
   mvprintw(k,j,"^");
   }
    else if(map[j][k]=='$'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='g'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='f'){
   mvaddstr(k,j,".");
   }
     else if(map[j][k]=='k'){
   mvprintw(k,j,".");
   }

   else if(map[j][k]=='v'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='d'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='h'){
   mvaddstr(k,j,".");
   }

   else if(map[j][k]=='o'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='C'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='B'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='A'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='w'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='a'){
   mvaddstr(k,j,".");
   }
   else if(map[j][k]=='s'){
   mvaddstr(k,j,".");
   }
  else if(map[j][k]=='<'){
   if(level==4){
   mvaddstr(k,j,"💰");
   }
   else {
   mvprintw(k,j,"%c",map[j][k]);
   }
   }
   else if(map[j][k]=='#'){
   mvaddstr(k,j,"\u2589");
   }
   else {
  mvprintw(k,j,"%c",map[j][k]);
  }
}
}

  for(int j=0;j<150;j++){
  for(int k=0;k<80;k++){
   if(map[j][k]=='$'){
   attron(COLOR_PAIR(2));
   mvaddstr(k,j,"🟡");
   attroff(COLOR_PAIR(2));
   }
   else if(map[j][k]=='g'){
   attron(COLOR_PAIR(2));
   mvaddstr(k,j,"⚫️");
   attroff(COLOR_PAIR(2));
   }
   else if(map[j][k]=='f'){
   attron(COLOR_PAIR(3));
   mvaddstr(k,j,"🍎");
   attroff(COLOR_PAIR(3));
   }
     else if(map[j][k]=='k'){
   attron(COLOR_PAIR(5));
   mvprintw(k,j,"∆");
   attroff(COLOR_PAIR(5));
   }

   else if(map[j][k]=='v'){
   attron(COLOR_PAIR(4));
   mvaddstr(k,j,"💨");
   attroff(COLOR_PAIR(4));
   }
   else if(map[j][k]=='d'){
   attron(COLOR_PAIR(3));
   mvaddstr(k,j,"🔥");
   attroff(COLOR_PAIR(3));
   }
   else if(map[j][k]=='h'){
   attron(COLOR_PAIR(3));
   mvaddstr(k,j,"❤️");
   attroff(COLOR_PAIR(3));
   }

   else if(map[j][k]=='o'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🗡️");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='C'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🗡️");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='B'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🪄");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='A'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🏹");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='w'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🪄");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='a'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"🏹");
   attroff(COLOR_PAIR(1));
   }
   else if(map[j][k]=='s'){
   attron(COLOR_PAIR(1));
   mvaddstr(k,j,"⚔️");
   attroff(COLOR_PAIR(1));
   }
   }
   }


  noecho();
  getch();
  echo();
  break;
}
   case('w'):{


     noecho();
     char direction=getch();
     echo();
     switch(direction){

     case('a'):{



      while(move_player(0,-1)){}
      break;
   }

   case('b'):{



      while(move_player(1,0)){}
      break;
   }

   case('c'):{



      while(move_player(0,1)){}
      break;
   }

   case('d'):{


      while(move_player(-1,0)){}
      break;
   }

case('e'):{


      while(move_player(1,-1)){}
      break;
   }

   case('f'):{


      while(move_player(1,1)){}
      break;
   }

   case('g'):{


      while(move_player(-1,1)){}
      break;
   }

   case('h'):{


      while(move_player(-1,-1)){}
      break;
   }

   }
   break;
   }


   case('S'):{

   gamedata game;

   for(int i=0;i<150;i++){
   for(int j=0;j<80;j++){
   game.map[i][j]=map[i][j];
   }
   }

for(int i=0;i<level;i++){
   for(int j=0;j<show_corridors;j++){
   game.x_show_corridor[i][j]=x_show_corridor[i][j];
   game.y_show_corridor[i][j]=y_show_corridor[i][j];
   }
   }
   game.show_corridors=show_corridors;

    game.player_x=player_x;
    game.player_y=player_y;
    game.level = level;
    game.score = score;
    game.gold = gold;
    game.player_health=player_health;
    game.gorosnegy=gorosnegy;
    game.selected_weapon = selected_weapon;
    game.mace_count = mace_count;
    game.sword_count = sword_count;
    game.dagger_count = dagger_count;
    game.arrow_count = arrow_count;
    game.magic_wand_count = magic_wand_count;

   for(int i=0;i<level;i++){
   for(int j=0;j<6;j++){
   game.show_rooms[i][j]=show_rooms[i][j];

   game.rooms[i][j].x=rooms[i][j].x;
   game.rooms[i][j].y=rooms[i][j].y;
   game.rooms[i][j].length=rooms[i][j].length;
   game.rooms[i][j].height=rooms[i][j].height;
   game.rooms[i][j].door_1=rooms[i][j].door_1;
   game.rooms[i][j].door_2=rooms[i][j].door_2;
   game.rooms[i][j].room_type=rooms[i][j].room_type;

  }
  }

  for(int i=0;i<level;i++){
   game.rams_door_opened[i]=rams_door_opened[i];
   }
   game.speed_spell_count=speed_spell_count;
   game.damage_spell_count=damage_spell_count;
   game.health_spell_count=health_spell_count;

   game.game_difficulty=game_difficulty;
   game.player_color=player_color;

   save_game("save.dat",&game);

   finish_game=1;


   break;
   }







   }


   if(player_health<=0){
   finish_games++;
   clear();


   mvprintw(15,10,"you lose");
   mvprintw(17,10,"score : %d gold :%d ",score,gold);
   noecho();
   getch();
   echo();
   clear();


   lose_game=1;
   player_health=100;
   level=1;
    break;
    }

   if(finish_game==1){
   clear();



   break;
   }

   if(map[player_x][player_y]=='<'){
   level+=1;
   clear();



   break;

   }

   }

   }



   }




void save_score(const char *username, int new_gold, int new_score,int new_finish_game) {
    FILE *file = fopen("scoreboard.txt", "r");
    if (file == NULL) {

        file = fopen("scoreboard.txt", "w");
        fprintf(file, "%s %d %d %d\n", username, new_gold, new_score,new_finish_game);
        fclose(file);
        return;
    }


    char buffer[256];
    char all_data[1000] = "";
    int found = 0;

    while (fgets(buffer, sizeof(buffer), file)) {
        char existing_user[50];
        int gold, score,finish_games;
        sscanf(buffer, "%s %d %d %d", existing_user, &gold, &score,&finish_games);

        if (strcmp(existing_user, username) == 0) {

            gold += new_gold;
            score += new_score;
            finish_games+=new_finish_game;
            snprintf(buffer, sizeof(buffer), "%s %d %d %d\n"
    , existing_user, gold, score,finish_games);
            found = 1;
        }
        strcat(all_data, buffer);
    }

    fclose(file);


    if (!found) {
        snprintf(buffer, sizeof(buffer), "%s %d %d %d\n"
   , username, new_gold, new_score,new_finish_game);
        strcat(all_data, buffer);
    }


    file = fopen("scoreboard.txt", "w");
    fputs(all_data, file);
    fclose(file);
}


typedef struct {
    char username[50];
    int score;
    int gold;
    int finish_games;
} Player;


void print_scoreboard(const char *filename,char* username_1) {

    start_color();

   init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);


   FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    Player players[100];
    int count = 0;


    while (fscanf(file, "%s %d %d %d",
  players[count].username, &players[count].gold, &players[count].score,&players[count].finish_games) != EOF){
        count++;
    }
    fclose(file);


    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (players[i].score < players[j].score) {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }


    printw("Scoreboard:\n");
    for (int i = 0; i < count; i++) {
    if(strcmp(players[i].username,username_1)==0){
    attron(COLOR_PAIR(2));
    attron(A_BOLD);
    attron(A_UNDERLINE);
    if(i==0){
    printw("%d champion : 🏆%s | Gold: %d | Score: %d | finish_games: %d\n"
    ,i+1, players[i].username, players[i].gold, players[i].score,players[i].finish_games);
    }
    else if(i==1){
    printw("%d legend : 🏆%s | Gold: %d | Score: %d | finish_games: %d\n"
    ,i+1, players[i].username, players[i].gold, players[i].score,players[i].finish_games);
    }
    else if(i==2){
    printw("%d Professional : 🏆%s | Gold: %d | Score: %d | finish_games: %d\n"
    ,i+1, players[i].username, players[i].gold, players[i].score,players[i].finish_games);
    }
   else {
    printw("%d  Username: %s | Gold: %d | Score: %d | finish_games: %d\n"
,i+1, players[i].username, players[i].gold, players[i].score,players[i].finish_games);
    }
    attroff(COLOR_PAIR(2));
    attroff(A_BOLD);
    attroff(A_UNDERLINE);

    }
    else {
    attron(COLOR_PAIR(3));
    if(i==0){
    attron(COLOR_PAIR(3));
    attron(A_BOLD);
    printw("%d champion : 🏆%s | Gold: %d | Score: %d | finish_games: %d\n"
    ,i+1, players[i].username, players[i].gold, players[i].score,players[i].finish_games);
    attroff(A_BOLD);
    attroff(COLOR_PAIR(3));
    }
    else if(i==1){
    attron(A_BOLD);
    attron(COLOR_PAIR(3));
    printw("%d legend : 🏆%s | Gold: %d | Score: %d | finish_games: %d\n"
    ,i+1, players[i].username, players[i].gold, players[i].score,players[i].finish_games);
    attroff(A_BOLD);
    attroff(COLOR_PAIR(3));
    }
    else if(i==2){
    attron(A_BOLD);
    attron(COLOR_PAIR(3));
    printw("%d Professional : 🏆%s | Gold: %d | Score: %d | finish_games: %d\n"
    ,i+1, players[i].username, players[i].gold, players[i].score,players[i].finish_games);
    attroff(A_BOLD);
    attroff(COLOR_PAIR(3));
    }
   else {
    attron(COLOR_PAIR(5));
    printw("%d  Username: %s | Gold: %d | Score: %d | finish_games: %d\n"
,i+1, players[i].username, players[i].gold, players[i].score,players[i].finish_games);
    attroff(COLOR_PAIR(5));
    }

    }

    }
}


 void print_scoreboard_2(const char *filename) {

    start_color();

   init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);


   FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file.\n");
        return;
    }

    Player players[100];
    int count = 0;


    while (fscanf(file, "%s %d %d %d",
  players[count].username, &players[count].gold, &players[count].score,&players[count].finish_games) != EOF){
        count++;
    }
    fclose(file);


    for (int i = 0; i < count - 1; i++) {
   for (int j = i + 1; j < count; j++) {
            if (players[i].score < players[j].score) {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }


    printw("Scoreboard:\n");
    for (int i = 0; i < count; i++) {
    if(i==0){
    attron(COLOR_PAIR(3));
    attron(A_BOLD);
    printw("%d champion : 🏆%s | Gold: %d | Score: %d | finish_games: %d\n"
    ,i+1, players[i].username, players[i].gold, players[i].score,players[i].finish_games);
    attroff(A_BOLD);
    attroff(COLOR_PAIR(3));
    }
    else if(i==1){
    attron(A_BOLD);
    attron(COLOR_PAIR(3));
    printw("%d legend : 🏆%s | Gold: %d | Score: %d | finish_games: %d\n"
    ,i+1, players[i].username, players[i].gold, players[i].score,players[i].finish_games);
    attroff(A_BOLD);
    attroff(COLOR_PAIR(3));
    }
    else if(i==2){
    attron(A_BOLD);
    attron(COLOR_PAIR(3));
    printw("%d Professional : 🏆%s | Gold: %d | Score: %d | finish_games: %d\n"
    ,i+1, players[i].username, players[i].gold, players[i].score,players[i].finish_games);
    attroff(A_BOLD);
    attroff(COLOR_PAIR(3));
    }
   else {
    attron(COLOR_PAIR(5));
    printw("%d  Username: %s | Gold: %d | Score: %d | finish_games: %d\n"
,i+1, players[i].username, players[i].gold, players[i].score,players[i].finish_games);
    attroff(COLOR_PAIR(5));
    }

    }
}




char *existing_usernames[MAX_USERS] = {0};
char *existing_passwords[MAX_USERS] = {0};
int user_count = 0;

int username_exists_in_file( char *username) {
    FILE *file = fopen(FILENAME, "r");
    if (!file) return 0;

    char line[200];
    while (fgets(line, sizeof(line), file)) {
        char stored_username[100];
        sscanf(line, "%s", stored_username);
        if (strcmp(stored_username, username) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int password_exists_in_file( char *password) {
    FILE *file = fopen("passwords.txt", "r");
    if (!file) return 0;

    char line[200];
    while (fgets(line, sizeof(line), file)) {
        char stored_password[100];
        sscanf(line, "%s", stored_password);
        if (strcmp(stored_password, password) == 0) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}


void save_username( char *username) {
    FILE *file = fopen("users.txt", "a");
    if (!file) {
        mvprintw(20, 10, "Error: Unable to open file.");
        return;
    }
    fprintf(file, "%s", username);
    fclose(file);
}

void save_password( char *password) {
    FILE *file_2 = fopen("passwords.txt", "a");
    if (!file_2) {
        mvprintw(20, 10, "Error: Unable to open file.");
        return;
    }
    fprintf(file_2, "%s", password);
    fclose(file_2);
}





int new_user(char *username, char *password, char *gmail) {

    if(username_exists_in_file(username)){
    mvprintw(20,10,"the user already exists");
    return 0;
     }


    if (strlen(password) < 7) {
        mvprintw(20, 10, "Password must be at least 7 characters.");
        return 0;
    }


    int check_password[3] = {0, 0, 0};
    for (int i = 0; i < strlen(password); i++) {
        if (isupper(password[i])) check_password[0] = 1;
        if (islower(password[i])) check_password[1] = 1;
        if (isdigit(password[i])) check_password[2] = 1;
    }

    int valid_password = check_password[0] + check_password[1] + check_password[2];
    if (valid_password != 3) {
        mvprintw(20, 10, "Password must include upper, lower, and digits.");
        return 0;
    }


    int check_gmail[5] = {0, 0, 0, 0, 0};
    for (int i = 0; i < strlen(gmail); i++) {
         if(gmail[i]!='@'){
        check_gmail[0]=1;
        }
        if (gmail[i] == '@') {
            check_gmail[1] = 1;
            if (gmail[i + 1] != '.') check_gmail[2] = 1;

            for (int j = i; j < strlen(gmail); j++) {
                if (gmail[j] == '.') {
                    check_gmail[3] = 1;
                    if (j != strlen(gmail) - 1) check_gmail[4] = 1;
                }
            }
        }
    }

    int valid_gmail = 0;
    for (int i = 0; i < 5; i++) valid_gmail += check_gmail[i];

    if (valid_gmail != 5) {
        mvprintw(20, 10, "Invalid email format.");
        return 0;
    }

    return 1;
}

int main(){

    start_color();
   setlocale(LC_ALL, "");


   init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_YELLOW, COLOR_BLACK);


    initscr();
int g=0;
  while(g==0){
    mvprintw(5, 20, "Welcome to Rogue game");

    char *choices_1[] = {
        "sign up",
        "login",
        "login as guest",
        "exit"
    };
    mvprintw(10, 10, "%s", choices_1[0]);
    mvprintw(11, 10, "%s", choices_1[1]);
    mvprintw(12, 10, "%s", choices_1[2]);
    mvprintw(13, 10, "%s", choices_1[3]);
    attron(COLOR_WHITE);
    char highlight = ' ';
    move(10, 10);
    attroff(COLOR_WHITE);

    int v = 0;
    int w = 0;
    while (w == 0) {
    noecho();
        char c = getch();
        echo();
        switch (c) {
        case 'a': {
        if (v == 0) v += 3;
                else v--;
                attron(COLOR_WHITE);
  mvprintw(10 + v, 10, "%c", highlight);
 mvprintw(10 + v, 10, "%c", choices_1[v][0]);
               attroff(COLOR_WHITE);
                break;
            }
            case 'b': {
                if (v == 3) v -= 3;
                else v++;
                attron(COLOR_WHITE);
  mvprintw(10 + v, 10, "%c", highlight);
 mvprintw(10 + v, 10, "%c", choices_1[v][0]);
                attroff(COLOR_WHITE);
                break;
            }
            case 'c': {
                w = 1;
                break;
            }
        }
    }



    if(v==0){
initscr();
refresh();
clear();


char username[100];
char password[100];
char gmail[100];
mvprintw(10,10,"username");
mvscanw(11,10,"%s",username);
mvprintw(12,10,"password");
mvscanw(13,10,"%s",password);
mvprintw(14,10,"gmail");
mvscanw(15,10,"%s",gmail);


if(new_user(username,password,gmail)){
   mvprintw(20,10,"sign up successful");
   save_username(username);
   save_password(password);
getch();
clear();
initscr();
int exit=0;
  while(exit==0){

  char *choices_2[] = {
        "new game",
        "load game",
        "score board",
        "settings",
        "exit"
    };
    mvprintw(10, 10, "%s", choices_2[0]);
    mvprintw(11, 10, "%s", choices_2[1]);
    mvprintw(12, 10, "%s", choices_2[2]);
    mvprintw(13, 10, "%s", choices_2[3]);
    mvprintw(14, 10, "%s", choices_2[4]);

    attron(COLOR_WHITE);
    char highlight_2 = ' ';
    move(10, 10);
    attroff(COLOR_WHITE);

    int choice = 0;
    int h = 0;
    while (h == 0) {
    noecho();
        char d = getch();
        echo();
        switch (d) {
        case 'a': {
        if (choice == 0) choice += 4;
                else choice--;
                attron(COLOR_WHITE);
  mvprintw(10 + choice, 10, "%c", highlight_2);
 mvprintw(10 + choice, 10, "%c", choices_2[choice][0]);
               attroff(COLOR_WHITE);
                break;
            }
            case 'b': {
                if (choice == 4) choice -= 4;
                else choice++;
                attron(COLOR_WHITE);
  mvprintw(10 + choice, 10, "%c", highlight_2);
 mvprintw(10 + choice, 10, "%c", choices_2[choice][0]);
                attroff(COLOR_WHITE);
                break;
            }
            case 'c': {
                h = 1;
                break;
            }
        }
    }

   if(choice==0){

     while((level!=6)&&(lose_game==0)&&(finish_game==0)){
   if(level!=5){
   generate_map_1();
   generate_map_2();
   handle_game(level);
   }
   else {
   generate_map_1();
   generate_map_3();
   handle_game(level);
   }

}

  if((lose_game==0)&&(finish_game==0)){
  mvprintw(20,10,"you win");
  mvprintw(22,10,"your score : %d your gold : %d ",score,gold);
  noecho();
  getch();
   echo();
  clear();



   }


  if(finish_game==0){
  save_score(username,gold,score,finish_games);
  }
  lose_game=0;
  finish_game=0;
  level=1;

   player_health=100;
   gorosnegy=0;
   food_count=0;

   gold=0;
   score=0;

   mace_count=1;
    sword_count=0;
    dagger_count=0;
    magic_wand_count=0;
    arrow_count=0;
    speed_spell_count=0;
    damage_spell_count=0;
    health_spell_count=0;
    ancient_key_count=0;
    selected_weapon=1;
    speed_spell_effect=0;
    damage_spell_effect=0;
    health_spell_effect=0;


}

   else if(choice==1){

   loading_game=1;

   gamedata loaded_game;

   load_game("save.dat",&loaded_game);

for(int i=0;i<150;i++){
   for(int j=0;j<80;j++){
   map[i][j]=loaded_game.map[i][j];
   }
   }



   show_corridors=loaded_game.show_corridors;

for(int i=0;i<level;i++){
   for(int j=0;j<show_corridors;j++){
   x_show_corridor[i][j]=loaded_game.x_show_corridor[i][j];
   y_show_corridor[i][j]=loaded_game.y_show_corridor[i][j];
   }
   }


    player_x=loaded_game.player_x;
    player_y=loaded_game.player_y;
    level = loaded_game.level;
    score = loaded_game.score;
    gold = loaded_game.gold;
    player_health=loaded_game.player_health;
    gorosnegy=loaded_game.gorosnegy;
    selected_weapon = loaded_game.selected_weapon;
    mace_count = loaded_game.mace_count;
    sword_count = loaded_game.sword_count;
    dagger_count = loaded_game.dagger_count;
    arrow_count = loaded_game.arrow_count;
    magic_wand_count = loaded_game.magic_wand_count;
   game_difficulty=loaded_game.game_difficulty;
   player_color=loaded_game.player_color;

   for(int i=0;i<level;i++){
   for(int j=0;j<6;j++){
   show_rooms[i][j]= loaded_game.show_rooms[i][j];

   rooms[i][j].x=loaded_game.rooms[i][j].x;
   rooms[i][j].y=loaded_game.rooms[i][j].y;
   rooms[i][j].length=loaded_game.rooms[i][j].length;
   rooms[i][j].height=loaded_game.rooms[i][j].height;
   rooms[i][j].door_1=loaded_game.rooms[i][j].door_1;
   rooms[i][j].door_2=loaded_game.rooms[i][j].door_2;
   rooms[i][j].room_type=loaded_game.rooms[i][j].room_type;

  }
  }


   for(int i=0;i<level;i++){
   rams_door_opened[i]=loaded_game.rams_door_opened[i];
   }
   speed_spell_count=loaded_game.speed_spell_count;
   damage_spell_count=loaded_game.damage_spell_count;
   health_spell_count=loaded_game.health_spell_count;


   handle_game(level);

while((level!=6)&&(lose_game==0)&&(finish_game==0)){
   if(level!=5){
   generate_map_1();
   generate_map_2();
   handle_game(level);
   }
   else {
   generate_map_1();
   generate_map_3();
   handle_game(level);
   }

}

  if((lose_game==0)&&(finish_game==0)){
  mvprintw(20,10,"you win");
  mvprintw(22,10,"your score : %d your gold : %d ",score,gold);
  noecho();
  getch();
   echo();
  clear();

   }

  if(finish_game==0){
  save_score(username,gold,score,finish_games);
  }
  lose_game=0;
  finish_game=0;
  level=1;

   player_health=100;
   gorosnegy=0;
   food_count=0;

   gold=0;
   score=0;

   mace_count=1;
    sword_count=0;
    dagger_count=0;
    magic_wand_count=0;
    arrow_count=0;
    speed_spell_count=0;
    damage_spell_count=0;
    health_spell_count=0;
    ancient_key_count=0;
    selected_weapon=1;
    speed_spell_effect=0;
    damage_spell_effect=0;
    health_spell_effect=0;

    loading_game=0;

}

   else if(choice==2){

   clear();




   print_scoreboard("scoreboard.txt",username);


   while(1){

   noecho();
    char u=getch();
   echo();

   if(u=='e'){
   break;
   }

   }


   clear();





}

   else if(choice==3){


   clear();



      char *choices_3[] = {
        "white",
        "yellow",
        "red",
        "green",
        "blue",
        "easy",
        "normal",
        "hard"
    };

    mvprintw(10,5,"player_color");
    mvprintw(15,5,"game_level");
    mvprintw(10, 20, "%s", choices_3[0]);
    mvprintw(11, 20, "%s", choices_3[1]);
    mvprintw(12, 20, "%s", choices_3[2]);
    mvprintw(13, 20, "%s", choices_3[3]);
    mvprintw(14, 20, "%s", choices_3[4]);
    mvprintw(15, 20, "%s", choices_3[5]);
    mvprintw(16, 20, "%s", choices_3[6]);
    mvprintw(17, 20, "%s", choices_3[7]);

    attron(COLOR_WHITE);
    char highlight = ' ';
    move(10, 20);
    attroff(COLOR_WHITE);

    int choice_2 = 0;
    int l = 0;
    while (l == 0) {
    noecho();
        char setting = getch();
        echo();
        switch (setting) {
        case 'a': {
        if (choice_2 == 0) choice_2 += 7;
                else choice_2--;
                attron(COLOR_WHITE);
  mvprintw(10 + choice_2, 20, "%c", highlight);
 mvprintw(10 + choice_2, 20, "%c", choices_3[choice_2][0]);
               attroff(COLOR_WHITE);
                break;
            }
            case 'b': {
                if (choice_2 == 7) choice_2 -= 7;
                else choice_2++;
                attron(COLOR_WHITE);
  mvprintw(10 + choice_2, 20, "%c", highlight);
 mvprintw(10 + choice_2, 20, "%c", choices_3[choice_2][0]);
                attroff(COLOR_WHITE);
                break;
            }
            case 'c': {
                l = 1;
                break;
            }
        }
    }

clear();




  if(choice_2==0){
   player_color=1;
}

   else if(choice_2==1){
   player_color=2;
  }

  else if(choice_2==2){
  player_color=3;
  }

   else if(choice_2==3){
  player_color=4;
  }

   else if(choice_2==4){
  player_color=5;
  }

  else if(choice_2==5){
  game_difficulty=1;}

  else if(choice_2==6){
  game_difficulty=2;
  }

  else if(choice_2==7){
  game_difficulty=3;
  }


}


  else  if(choice==4){
  exit=1;
 }

}
clear();


endwin();

}
     else{
      getch();
       }
clear();


endwin();
}

else if(v==1){

initscr();
refresh();
clear();


char username[100];
char password[100];

mvprintw(10,10,"username");
mvscanw(11,10,"%s",username);
mvprintw(12,10,"password");
mvscanw(13,10,"%s",password);

    if((username_exists_in_file(username))&&(password_exists_in_file(password))){
    mvprintw(20,10,"login successful");
    getch();
clear();


     int exit=0;
initscr();
  while(exit==0){

  char *choices_2[] = {
        "new game",
        "load game",
        "score board",
        "settings",
        "exit"
    };
    mvprintw(10, 10, "%s", choices_2[0]);
    mvprintw(11, 10, "%s", choices_2[1]);
    mvprintw(12, 10, "%s", choices_2[2]);
    mvprintw(13, 10, "%s", choices_2[3]);
    mvprintw(14, 10, "%s", choices_2[4]);

    attron(COLOR_WHITE);
    char highlight_2 = ' ';
    move(10, 10);
    attroff(COLOR_WHITE);

    int choice = 0;
    int h = 0;
    while (h == 0) {
    noecho();
        char d = getch();
        echo();
        switch (d) {
        case 'a': {
        if (choice == 0) choice += 4;
                else choice--;
                attron(COLOR_WHITE);
  mvprintw(10 + choice, 10, "%c", highlight_2);
 mvprintw(10 + choice, 10, "%c", choices_2[choice][0]);
               attroff(COLOR_WHITE);
                break;
            }
            case 'b': {
                if (choice == 4) choice -= 4;
                else choice++;
                attron(COLOR_WHITE);
  mvprintw(10 + choice, 10, "%c", highlight_2);
 mvprintw(10 + choice, 10, "%c", choices_2[choice][0]);
                attroff(COLOR_WHITE);
                break;
            }
            case 'c': {
                h = 1;
                break;
            }
        }
    }



  if(choice==0){

    while((level!=6)&&(lose_game==0)&&(finish_game==0)){
   if(level!=5){
   generate_map_1();
   generate_map_2();
   handle_game(level);
   }
   else {
   generate_map_1();
   generate_map_3();
   handle_game(level);
   }

}


  if((lose_game==0)&&(finish_game==0)){
  mvprintw(20,10,"you win");
  mvprintw(22,10,"your score : %d your gold : %d ",score,gold);

   noecho();
  getch();
  echo();
   clear();



   }

if(finish_game==0){
  save_score(username,gold,score,finish_games);
  }
  lose_game=0;
  finish_game=0;
  level=1;

player_health=100;
   gorosnegy=0;
   food_count=0;

   gold=0;
   score=0;

   mace_count=1;
    sword_count=0;
    dagger_count=0;
    magic_wand_count=0;
    arrow_count=0;
    speed_spell_count=0;
    damage_spell_count=0;
    health_spell_count=0;
    ancient_key_count=0;
    selected_weapon=1;
    speed_spell_effect=0;
    damage_spell_effect=0;
    health_spell_effect=0;

}

   else if(choice==1){

   loading_game=1;

gamedata loaded_game;

   load_game("save.dat",&loaded_game);

for(int i=0;i<150;i++){
   for(int j=0;j<80;j++){
   map[i][j]=loaded_game.map[i][j];
   }
   }

show_corridors=loaded_game.show_corridors;

for(int i=0;i<level;i++){
   for(int j=0;j<show_corridors;j++){
   x_show_corridor[i][j]=loaded_game.x_show_corridor[i][j];
   y_show_corridor[i][j]=loaded_game.y_show_corridor[i][j];
   }
   }

    player_x=loaded_game.player_x;
    player_y=loaded_game.player_y;
    level = loaded_game.level;
    score = loaded_game.score;
    gold = loaded_game.gold;
    player_health=loaded_game.player_health;
    gorosnegy=loaded_game.gorosnegy;
    selected_weapon = loaded_game.selected_weapon;
    mace_count = loaded_game.mace_count;
    sword_count = loaded_game.sword_count;
    dagger_count = loaded_game.dagger_count;
    arrow_count = loaded_game.arrow_count;
    magic_wand_count = loaded_game.magic_wand_count;
   game_difficulty=loaded_game.game_difficulty;
   player_color=loaded_game.player_color;

   for(int i=0;i<level;i++){
   for(int j=0;j<6;j++){
   show_rooms[i][j]= loaded_game.show_rooms[i][j];

   rooms[i][j].x=loaded_game.rooms[i][j].x;
   rooms[i][j].y=loaded_game.rooms[i][j].y;
   rooms[i][j].length=loaded_game.rooms[i][j].length;
   rooms[i][j].height=loaded_game.rooms[i][j].height;
   rooms[i][j].door_1=loaded_game.rooms[i][j].door_1;
   rooms[i][j].door_2=loaded_game.rooms[i][j].door_2;
   rooms[i][j].room_type=loaded_game.rooms[i][j].room_type;

  }
  }

for(int i=0;i<level;i++){
   rams_door_opened[i]=loaded_game.rams_door_opened[i];
   }
   speed_spell_count=loaded_game.speed_spell_count;
   damage_spell_count=loaded_game.damage_spell_count;
   health_spell_count=loaded_game.health_spell_count;


   handle_game(level);

while((level!=6)&&(lose_game==0)&&(finish_game==0)){
   if(level!=5){
   generate_map_1();
   generate_map_2();
   handle_game(level);
   }
   else {
   generate_map_1();
   generate_map_3();
   handle_game(level);
   }

}

  if((lose_game==0)&&(finish_game==0)){
  mvprintw(20,10,"you win");
  mvprintw(22,10,"your score : %d your gold : %d ",score,gold);
  noecho();
  getch();
   echo();
  clear();

   }

  if(finish_game==0){
  save_score(username,gold,score,finish_games);
  }
  lose_game=0;
  finish_game=0;
  level=1;

   player_health=100;
   gorosnegy=0;
   food_count=0;

   gold=0;
   score=0;

   mace_count=1;
    sword_count=0;
    dagger_count=0;
    magic_wand_count=0;
    arrow_count=0;
    speed_spell_count=0;
    damage_spell_count=0;
    health_spell_count=0;
    ancient_key_count=0;
    selected_weapon=1;
    speed_spell_effect=0;
    damage_spell_effect=0;
    health_spell_effect=0;

   loading_game=0;

}

   else if(choice==2){

   clear();



   initscr();
   print_scoreboard("scoreboard.txt",username);

  while(1){

  noecho();
    char u=getch();
  echo();

   if(u=='e'){
   break;
   }

   }

   clear();



   endwin();

}

   else if(choice==3){


   clear();



char *choices_3[] = {
        "white",
        "yellow",
        "red",
        "green",
        "blue",
        "easy",
        "normal",
        "hard"
    };

    mvprintw(10,5,"player_color");
    mvprintw(15,5,"game_level");
    mvprintw(10, 20, "%s", choices_3[0]);
    mvprintw(11, 20, "%s", choices_3[1]);
    mvprintw(12, 20, "%s", choices_3[2]);
    mvprintw(13, 20, "%s", choices_3[3]);
    mvprintw(14, 20, "%s", choices_3[4]);
    mvprintw(15, 20, "%s", choices_3[5]);
    mvprintw(16, 20, "%s", choices_3[6]);
    mvprintw(17, 20, "%s", choices_3[7]);

    attron(COLOR_WHITE);
    char highlight = ' ';
    move(10, 20);
    attroff(COLOR_WHITE);

    int choice_2 = 0;
    int l = 0;
    while (l == 0) {
    noecho();
        char setting = getch();
        echo();
        switch (setting) {
        case 'a': {
        if (choice_2 == 0) choice_2 += 7;
                else choice_2--;
                attron(COLOR_WHITE);
  mvprintw(10 + choice_2, 20, "%c", highlight);
 mvprintw(10 + choice_2, 20, "%c", choices_3[choice_2][0]);
               attroff(COLOR_WHITE);
                break;
            }
            case 'b': {
                if (choice_2 == 7) choice_2 -= 7;
                else choice_2++;
                attron(COLOR_WHITE);
  mvprintw(10 + choice_2, 20, "%c", highlight);
 mvprintw(10 + choice_2, 20, "%c", choices_3[choice_2][0]);
                attroff(COLOR_WHITE);
                break;
            }
            case 'c': {
                l = 1;
                break;
            }
        }
    }

clear();




  if(choice_2==0){
   player_color=1;
}

  else if(choice_2==1){
  player_color=2;
  }

  else if(choice_2==2){
  player_color=3;
  }

   else if(choice_2==3){
  player_color=4;
  }
   else if(choice_2==4){
  player_color=5;
  }

  else if(choice_2==5){
  game_difficulty=1;}

  else if(choice_2==6){
  game_difficulty=2;
  }

  else if(choice_2==7){
  game_difficulty=3;
  }



}





   else if(choice==4){
  exit=1;
 }

}
clear();


endwin();
endwin();
}
    else {
    if(username_exists_in_file(username)){
    mvprintw(20,10,"the password is incorrect");
    }
   else{
    mvprintw(20,10,"the username is incorrect");
    }
    getch();
clear();



endwin();
    }

}

    else if(v==2){


clear();


     int exit=0;
initscr();
  while(exit==0){

  char *choices_2[] = {
        "new game",
        "load game",
        "score board",
        "settings",
        "exit"
    };
    mvprintw(10, 10, "%s", choices_2[0]);
    mvprintw(11, 10, "%s", choices_2[1]);
    mvprintw(12, 10, "%s", choices_2[2]);
    mvprintw(13, 10, "%s", choices_2[3]);
    mvprintw(14, 10, "%s", choices_2[4]);

    attron(COLOR_WHITE);
    char highlight_2 = ' ';
    move(10, 10);
    attroff(COLOR_WHITE);

    int choice = 0;
    int h = 0;
    while (h == 0) {
    noecho();
        char d = getch();
        echo();
        switch (d) {
        case 'a': {
        if (choice == 0) choice += 4;
                else choice--;
                attron(COLOR_WHITE);
  mvprintw(10 + choice, 10, "%c", highlight_2);
 mvprintw(10 + choice, 10, "%c", choices_2[choice][0]);
               attroff(COLOR_WHITE);
                break;
            }
            case 'b': {
                if (choice == 4) choice -= 4;
                else choice++;
                attron(COLOR_WHITE);
  mvprintw(10 + choice, 10, "%c", highlight_2);
   mvprintw(10 + choice, 10, "%c", choices_2[choice][0]);
                attroff(COLOR_WHITE);
                break;
            }
            case 'c': {
                h = 1;
                break;
            }
        }
    }


   if(choice==0){

    while((level!=6)&&(lose_game==0)&&(finish_game==0)){
   if(level!=5){
   generate_map_1();
   generate_map_2();
   handle_game(level);
   }
   else {
   generate_map_1();
   generate_map_3();
   handle_game(level);
   }

}


  if((lose_game==0)&&(finish_game==0)){
  mvprintw(20,10,"you win");
  mvprintw(22,10,"your score : %d your gold : %d ",score,gold);
  noecho();
  getch();
   echo();
   clear();



   }


  lose_game=0;
 finish_game=0;
  level=1;

player_health=100;
   gorosnegy=0;
   food_count=0;

   gold=0;
   score=0;

   mace_count=1;
    sword_count=0;
    dagger_count=0;
    magic_wand_count=0;
    arrow_count=0;
    speed_spell_count=0;
    damage_spell_count=0;
    health_spell_count=0;
    ancient_key_count=0;
    selected_weapon=1;
    speed_spell_effect=0;
    damage_spell_effect=0;
    health_spell_effect=0;

}

   else if(choice==1){

   loading_game=1;

gamedata loaded_game;

   load_game("save.dat",&loaded_game);

for(int i=0;i<150;i++){
   for(int j=0;j<80;j++){
   map[i][j]=loaded_game.map[i][j];
   }
   }


show_corridors=loaded_game.show_corridors;

for(int i=0;i<level;i++){
   for(int j=0;j<show_corridors;j++){
   x_show_corridor[i][j]=loaded_game.x_show_corridor[i][j];
   y_show_corridor[i][j]=loaded_game.y_show_corridor[i][j];
   }
   }

    player_x=loaded_game.player_x;
    player_y=loaded_game.player_y;
    level = loaded_game.level;
    score = loaded_game.score;
    gold = loaded_game.gold;
    player_health=loaded_game.player_health;
    gorosnegy=loaded_game.gorosnegy;
    selected_weapon = loaded_game.selected_weapon;
    mace_count = loaded_game.mace_count;
    sword_count = loaded_game.sword_count;
    dagger_count = loaded_game.dagger_count;
    arrow_count = loaded_game.arrow_count;
    magic_wand_count = loaded_game.magic_wand_count;
   game_difficulty=loaded_game.game_difficulty;
   player_color=loaded_game.player_color;

   for(int i=0;i<level;i++){
   for(int j=0;j<6;j++){
   show_rooms[i][j]= loaded_game.show_rooms[i][j];

   rooms[i][j].x=loaded_game.rooms[i][j].x;
   rooms[i][j].y=loaded_game.rooms[i][j].y;
   rooms[i][j].length=loaded_game.rooms[i][j].length;
   rooms[i][j].height=loaded_game.rooms[i][j].height;
   rooms[i][j].door_1=loaded_game.rooms[i][j].door_1;
   rooms[i][j].door_2=loaded_game.rooms[i][j].door_2;
   rooms[i][j].room_type=loaded_game.rooms[i][j].room_type;

  }
  }

for(int i=0;i<level;i++){
   rams_door_opened[i]=loaded_game.rams_door_opened[i];
   }
   speed_spell_count=loaded_game.speed_spell_count;
   damage_spell_count=loaded_game.damage_spell_count;
   health_spell_count=loaded_game.health_spell_count;


   handle_game(level);

while((level!=6)&&(lose_game==0)&&(finish_game==0)){
   if(level!=5){
   generate_map_1();
   generate_map_2();
   handle_game(level);
   }
   else {
   generate_map_1();
   generate_map_3();
   handle_game(level);
   }

}

  if((lose_game==0)&&(finish_game==0)){
  mvprintw(20,10,"you win");
  mvprintw(22,10,"your score : %d your gold : %d ",score,gold);
  noecho();
  getch();
   echo();
  clear();

   }

  lose_game=0;
  finish_game=0;
  level=1;

   player_health=100;
   gorosnegy=0;
   food_count=0;

   gold=0;
   score=0;

   mace_count=1;
    sword_count=0;
    dagger_count=0;
    magic_wand_count=0;
    arrow_count=0;
    speed_spell_count=0;
    damage_spell_count=0;
    health_spell_count=0;
    ancient_key_count=0;
    selected_weapon=1;
    speed_spell_effect=0;
    damage_spell_effect=0;
    health_spell_effect=0;

    loading_game=0;

}

   else if(choice==2){

   clear();



   initscr();
   print_scoreboard_2("scoreboard.txt");

  while(1){

  noecho();
    char u=getch();
  echo();

   if(u=='e'){
   break;
   }

   }

   clear();



   endwin();

}

   else if(choice==3){


   clear();




char *choices_3[] = {
        "white",
        "yellow",
        "red",
        "green",
        "blue",
        "easy",
        "normal",
        "hard"
    };

    mvprintw(10,5,"player_color");
    mvprintw(15,5,"game_level");
    mvprintw(10, 20, "%s", choices_3[0]);
    mvprintw(11, 20, "%s", choices_3[1]);
    mvprintw(12, 20, "%s", choices_3[2]);
    mvprintw(13, 20, "%s", choices_3[3]);
    mvprintw(14, 20, "%s", choices_3[4]);
    mvprintw(15, 20, "%s", choices_3[5]);
    mvprintw(16, 20, "%s", choices_3[6]);
    mvprintw(17, 20, "%s", choices_3[7]);

    attron(COLOR_WHITE);
    char highlight = ' ';
    move(10, 20);
    attroff(COLOR_WHITE);

    int choice_2 = 0;
    int l = 0;
    while (l == 0) {
    noecho();
        char setting = getch();
        echo();
        switch (setting) {
        case 'a': {
        if (choice_2 == 0) choice_2 += 7;
                else choice_2--;
                attron(COLOR_WHITE);
  mvprintw(10 + choice_2, 20, "%c", highlight);
 mvprintw(10 + choice_2, 20, "%c", choices_3[choice_2][0]);
               attroff(COLOR_WHITE);
                break;
            }
            case 'b': {
                if (choice_2 == 7) choice_2 -= 7;
                else choice_2++;
                attron(COLOR_WHITE);
  mvprintw(10 + choice_2, 20, "%c", highlight);
 mvprintw(10 + choice_2, 20, "%c", choices_3[choice_2][0]);
                attroff(COLOR_WHITE);
                break;
            }
            case 'c': {
                l = 1;
                break;
            }
        }
    }

clear();




  if(choice_2==0){
   player_color=1;
}

  else if(choice_2==1){
  player_color=2;
  }

  else if(choice_2==2){
  player_color=3;
  }

   else if(choice_2==3){
  player_color=4;
  }
   else if(choice_2==4){
  player_color=5;
  }

  else if(choice_2==5){
  game_difficulty=1;}

  else if(choice_2==6){
  game_difficulty=2;
  }

  else if(choice_2==7){
  game_difficulty=3;
  }



}







   else if(choice==4){
  exit=1;
 }

}
clear();


endwin();








}

else if(v==3){
  g=1;

}

}

endwin();
clear();

refresh();

endwin();


return 0;
}


                break;
            }
            case 'b': {
                if (choice_2 == 7) choice_2 -= 7;
                else choice_2++;
                attron(COLOR_WHITE);
  mvprintw(10 + choice_2, 20, "%c", highlight);
 mvprintw(10 + choice_2, 20, "%c", choices_3[choice_2][0]);
                attroff(COLOR_WHITE);
                break;
            }
            case 'c': {
                l = 1;
                break;
            }
        }
    }

clear();




  if(choice_2==0){
   player_color=1;
}

  else if(choice_2==1){
  player_color=2;
