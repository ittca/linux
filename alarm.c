/* simple Alarm for linux
   needs vlc installed or a change of the command to open your favorit music player (on the music function)
   to run this file run "gcc -o timer timer.c && ./alarm" on this file directory
   to run this file as a command, run "gcc -o timer timer.c && sudo chmod +x timer && sudo cp timer /usr/bin/" on this file directory		*/
//    ______ __  ______  ______  ______       ______  ______  __      ______  _____   ______
//   /\__  _/\ \/\  __ \/\  ___\/\  __ \     /\  ___\/\  __ \/\ \    /\  __ \/\  __-./\  __ \
//   \/_/\ \\ \ \ \  __ \ \ \__ \ \ \/\ \    \ \ \___\ \  __ \ \ \___\ \  __ \ \ \/\ \ \ \/\ \
//      \ \_\\ \_\ \_\ \_\ \_____\ \_____\    \ \_____\ \_\ \_\ \_____\ \_\ \_\ \____-\ \_____\
//       \/_/ \/_/\/_/\/_/\/_____/\/_____/     \/_____/\/_/\/_/\/_____/\/_/\/_/\/____/ \/_____/ 2020

#include <stdio.h>									// printf(), scanf()
#include <stdlib.h>									// system()
#include <unistd.h>               // sleep()

int horas, minutos, segundos, inp1, inp2, musica = 2;
int vezes = 4;
int tempo = 45;
int intervalo = 15;
char os_return[100];

void system_hour();
void system_return(char *a);
void music();
int str_size(char *str);
int is_int(char *str);
int sti(char *str);
void str_replace(char *str, char *str2);
int isCharInt(char *str);
int input_int(char *msg);
void input_int2();


int main(int argc,char *argv[]){
	int a = 1;
  int b = 0;
  char *menu = "   ############ My timer ############\n\n\n\t1. Pomodoro\n\t2. Alarm\n\t3. Settings\n\t4. Exit\n\n\t»» ";
  char *pomodoro = "\n\n##################################################################################\n\t\t\t\tPomodoro\n##################################################################################\n";
  char *pause = "\n\n##################################################################################\n\t\t\ttime for a pause, Break!\n##################################################################################\n";
  char *finnish = "\n\n###########################################################################################\n  Pomodoro's time had finnish!, go breed fresh air, have fun, repite whenever you want!\n###########################################################################################\n";
  char *pomoSettings = "\n\n##################################################################################\n\t\t\t\t\tPomodoro settings\n##################################################################################\n";
  while (a != 0){
		if (argc == 1){
      do{
        system("clear");
        b = input_int(menu);
      }while (b < 1 || b > 4);
		} else {
			inp1 = sti(argv[1]);
			inp2 = sti(argv[2]);
			b = 3;
		}
		if(b == 1){
			int vv = vezes;
			while (vv != 0){
				system("cvlc http://www.shinsen-radio.org:8000/shinsen-radio.64.ogg &");
				sleep(1);
				system("clear");
				printf(pomodoro);
				sleep(tempo*60);
				system("killall vlc");
				system("cvlc /home/tiago/Música/Metal_productivity.mp3 &");
				sleep(1);
				if (vv != 1){
					system("clear");
					printf(pause);
					sleep(22);
					system("killall vlc");
					sleep(intervalo*60);
				} else {
					system("clear");
					printf(finnish);
					sleep(22);
					system("killall vlc");
				}
				vv--;
			}
		}
		else if (b == 2){
      do {
				input_int2();
			} while (inp1 < 0 || inp1 > 23 || inp2 < 0 || inp2 > 59);					// if correct time was inserted the code go on
			int t = 1, r, sleeptime;
      system_hour();
			while(t){
				while ( inp1!=horas || inp2 != minutos){
					if (inp1 == horas && inp2 > minutos) sleeptime = (inp2-minutos)*60 - segundos+2;
					else sleeptime = (60-minutos)*60 - segundos+2;
			    system("clear");
			    printf("####################	Alarm	set to     %d : %d   ####################\n\n",inp1,inp2);	// title
					sleep(sleeptime);
          system_hour();
				}
				const char *c;
				r = 1;
				while (r){
          music();
					sleep(4);
					char str3[100];
					system("clear");
					printf("\n\n\n\n\tGood Morning!\n\n\tPress r to turn off the Alarm, Any Key to more 10 minutes\n\n\t\t\t\t");
					scanf(" %s", str3);
					system("killall vlc");
					if (str3[0] == 'r'){r = 0; t = 0;}
					else{
            system_hour();
						inp2 = minutos + 10;
						if(inp2 > 59){
							inp2 = inp2 - 60;
							inp1++;
							if (inp1 > 23)inp1 = 0;
						}
						r = 0;}
				}
			}
		}
		else if(b == 3){
			system("clear");
			printf(pomoSettings);
			printf("\nChoose the number of times for the pomodoro time\n»» ");
			scanf(" %d",&vezes);
			system("clear");
			printf(pomoSettings);
			printf("\nChoose the pomodoro's time in minutes\n»» ");
			scanf(" %d",&tempo);
			system("clear");
			printf(pomoSettings);
			printf("\nChoose the break time in minutes\n»» ");
			scanf(" %d",&intervalo);
			system("clear");
			printf("\n\n##################################################################################\n\t\t\tYour definitions had been saved with success!\n##################################################################################\n");
			sleep(3);
		}
		else if(b == 4){a = 0;}
	}
	printf("\n\tSee you next time!.\n");
  sleep(3);
	return 0;
}


void music(){
	switch(musica)
	{
	case 1:
		system("cvlc https://soundcloud.com/nocopyrightsounds/unknown-brain-matafaka-feat-marvin-divine &");
		break;
	case 2:
		system("cvlc https://soundcloud.com/nathan-due/nightcore-alone-tonight-digital-daggers &");
		break;
	case 3:
		system("cvlc https://soundcloud.com/nightcorenocopyright-434283379/nightcore-wrecking-ball-metal &");
		break;
	case 4:
		system("cvlc https://soundcloud.com/sarahjcmusic/i-dont-know-demo &");
		break;
	}
}
int str_size(char *str){
  int n;
  for (n = 0; str[n] != '\0'; n++);
  return n;
}
int is_int(char *str){
  int a = str_size(str);
  for (int n = 0; str[n] < a; n++){
    if (str[n] < 48 || str[n] > 57){
      if(str[n] == 45 && n == 0){
      } else { return 0;}
    }
  }
  return 1;
}

int isCharInt(char *str){
  int a = str_size(str);
  for (int n = 0; str[n]; n++){
    if (str[n] < 48 || str[n] > 57){      // numbers  0 1 2 3 4 5 6 7 8 9
      if(str[n] == 45 && n == 0){         // for - (minus only on the first position, negative numbers)
      } else { return 0;}
    }
  }
  return 1;
}

int sti(char *str){
  int a = 0, b = 1, i = 0;
  if(str[0] == '-'){
    b = -1;
    i++;
  }
  for(;str[i];++i) a = a*10 + str[i] - '0';
  return b*a;
}
void str_replace(char *str, char *str2){
  int b = str_size(str);
  int c = str_size(str2);
  int n;
  for(n = 0; n < b; n++)str[n]='\0';
  for(n = 0; n < c; n++)str[n]=str2[n];
  str[n]='\0';
}
int input_int(char *msg){
  int a;
  int b = 1;
  while (b){
    char str[100];
    system("clear");
    printf("%s",msg);
    scanf("%s", str);
    if (isCharInt(str)){
      a = sti(str);
      b = 0;
    }
  }
  return a;
}
void input_int2(){
  int b = 1;
  char *msg_err = malloc(256);
  str_replace(msg_err,"");
  while (b){
    char str[100];
    char str2[100];
    system("clear");							// clear screen
    printf("####################	Alarm	####################\n");	// title
    if (inp1 < 0 || inp1 > 23) printf("\t\thours must be between 00 and 23");	// warning message about hours input
    if (inp2 < 0 || inp2 > 59) printf("\t\tminutes must be between 00 and 59");	// warning message about minutes input
    if (msg_err != "")printf("%s\n", msg_err);
    inp1 = 0;
    inp2 = 0;
    printf("\nChoose the Alarm time: ");					// asking for user input
    scanf(" %s %s", str,str2);
    if (is_int(str) && is_int(str2)){
      inp1 = sti(str);
      inp2 = sti(str2);
      if (inp1 < 0 || inp1 > 23) inp1 = sti(str);	  // warning message about hours input
      if (inp2 < 0 || inp2 > 59) inp2 = sti(str2);	// warning message about minutes input
      b = 0;
    } else {
      str_replace(msg_err,"\t\tPlease input only numbers like  07 15");
    }
  }
}

void system_return(char *a){ // needs 1 global variable char os_return[100];
  int b = str_size(a);
  char c[b];
  mkstemp("tmp543765");
  sprintf(c, "%s > tmp543765", a);
  system(c);
  FILE *d = fopen("tmp543765", "r");
  while (fgets(os_return, 1000, d) != NULL);
  fclose(d);
  system("rm tmp543765");
}
void system_hour(){  // needs 4 global variables char os_return[100];
  system_return("date");
  int n = 0;
  int nn = 0;
  int nnn = 0;
  char hh[3] = "  ";
  char mm[3] = "  ";
  char ss[3] = "  ";
  for(int i = 0; i < str_size(os_return);i++){
    if (n == 4 && os_return[i] != ' '){
      if(os_return[i]==':'){nn++;nnn = 0;}
      else{
        if(nn==0){ hh[nnn] = os_return[i];nnn++;}
        else if(nn==1){mm[nnn] = os_return[i];nnn++;}
        if(nn==2){ss[nnn] = os_return[i];nnn++;}
      }
    }
    if (os_return[i] == ' ')n++;
  }
  horas = sti(hh);
  minutos = sti(mm);
  segundos = sti(ss);
}
