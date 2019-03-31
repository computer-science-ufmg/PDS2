#include <map>
#include <string>
#include <iomanip>
#include <algorithm>
#include <iostream>

using namespace std;

struct Indice {
  map<string, int> words;
  int word_count;

  Indice();
  void push(string word);
  void print_index();
};

typedef struct Indice Indice;
