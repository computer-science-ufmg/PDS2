#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {
  ifstream file;
  string word;
  map<string, int> words;
  int word_count = 0;
  float percentual;

  file.open("input.pds");
  while (file >> word) {
    if(word.size() >= 3){
      transform(word.begin(), word.end(), word.begin(), ::tolower);
      words[word]++;
    }
    word_count++;
  }
  map<string, int>::iterator it;
  for (it = words.begin(); it != words.end(); ++it) {
    percentual = it->second/(float)word_count;
    cout << it->first << ' ' << it->second << ' ' << std::fixed << std::setprecision(2) << percentual << endl;
  }
  file.close();
  return 0;
}
