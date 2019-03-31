#include "Indice.hpp"

using namespace std;

Indice::Indice(){
  this->word_count = 0;
}

void Indice::push(string word){
  if(word.size() >= 3){
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    this->words[word]++;
  }
  this->word_count++;
}

void Indice::print_index(){
  float percentual;
  map<string, int>::iterator it;
  for (it = this->words.begin(); it != this->words.end(); ++it) {
    percentual = it->second/(float)this->word_count;
    cout << it->first << ' ' << it->second << ' ' << std::fixed << std::setprecision(2) << percentual << endl;
  }
}
