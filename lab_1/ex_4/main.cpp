#include "Indice.hpp"
#include <iostream>
#include <sstream>

using namespace std;

int main(int argc, char const *argv[]) {
  Indice *index = new Indice();
  string line, text, word;

  while(getline(cin, line)){
    text += ' '+line;
  }
  istringstream string_stream(text);
  while (string_stream >> word) {
    index->push(word);
  }
  index->print_index();
  delete index;
  return 0;
}
