/******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include <termios.h>
#include <fcntl.h>
using namespace std;

/* retourne 0 si aucune touche n'est appuyée, 
 * sinon retourne le code ASCII de la touche */
int read_keybord();

/******************************************************************************/
#define H 20
#define L 30

char screen[H][L];

void screen_display() {
  system("clear");
  for (int i=0; i<H; i++) {
    for (int j=0; j<L; j++) {
      cout << screen[i][j];
    }
    cout << endl;
  }
}

void clear_screen() {
  for (int i=0; i<H; i++)
    for (int j=0; j<L; j++)
      screen[i][j] = ' ';
}

/******************************************************************************/
double x = 0.0;
double y = 0.0;

void update_game(int key) {
  screen[(int)x][(int)y] = 'X';
  x = x + 0.2;
  y = y + 0.05;
}

/******************************************************************************/

int main() {
  int key;
  do {
    key = read_keybord();
    clear_screen();
    update_game(key);
    screen_display();
    usleep(20 * 1000);
  } while (key != 'q');
}

/******************************************************************************/

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;

  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

  ch = getchar();

  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);

  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }

  return 0;
}

int read_keybord() {
  int key;
  if (kbhit())
    key = getc(stdin);
  else
    key = 0;
  return key;
}

/******************************************************************************/
/******************************************************************************/
