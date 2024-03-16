#include "LSTMCell.h"


void run() {

  int features = 10;
  LSTMCell* cell = new LSTMCell(features);

  delete cell;
}



int main() {

  run();
  return 0;
}
