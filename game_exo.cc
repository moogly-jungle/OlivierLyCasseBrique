#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>
using namespace std;

int main() {

  cout << "bonjour" << endl;

  int n=0;
  while (1) {
    system("clear"); /* efface l'écran du terminal */
    for (int i=0; i<n; i++) 
      cout << endl;
    cout << "hello world!" << endl;
    
    n = (n+1) % 20;
    usleep(20 * 1000);
  }
}
