#include <stdio.h>
#include <stdlib.h>

char os_return[100]; int os_hour; int os_min; int os_seg;

int is_int(int str){if(__builtin_types_compatible_p(typeof(str), int)) return 1;}

int str_size(char *str){
  int n;
  for (n = 0; str[n] != '\0'; n++);
  return n;
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
int isCharFloat(char *str){
  int a = str_size(str);
  int b = 0;
  for (int n = 0; str[n]; n++){
    if (str[n] < 48 || str[n] > 57){      // numbers  0 1 2 3 4 5 6 7 8 9
      if (str[n] == 46){                  // for the ,
        if(n==0){return 0;}               // doesnt allow point on the first position
        b++;
        if(b>1){return 0;}                // will allow only one point on the string
      } else if(str[n] == 45 && n == 0){  // for - (minus only on the first position, negative numbers)
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
void str_replace(char *str, char *str2){
  int b = str_size(str);
  int c = str_size(str2);
  int n;
  for(n = b-1; n >= 0; n--)str[n]='\0';
  for(n = 0; n < c; n++)str[n]=str2[n];
  str[n]='\0';
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
void system_hour(){  // needs 4 global variables char os_return[100]; int os_hour; int os_min; int os_seg;
  system_return("date");
  int n = 0;
  int nn = 0;
  int nnn = 0;
  char h[3] = "  ";
  char m[3] = "  ";
  char s[3] = "  ";
  for(int i = 0; i < str_size(os_return);i++){
    if (n == 4 && os_return[i] != ' '){
      if(os_return[i]==':'){nn++;nnn = 0;}
      else{
        if(nn==0){ h[nnn] = os_return[i];nnn++;}
        else if(nn==1){m[nnn] = os_return[i];nnn++;}
        if(nn==2){s[nnn] = os_return[i];nnn++;}
      }
    }
    if (os_return[i] == ' ')n++;
  }
  os_hour = sti(h);
  os_min = sti(m);
  os_seg = sti(s);
}
