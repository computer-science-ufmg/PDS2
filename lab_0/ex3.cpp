#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main(){
  int number;
  vector<int> odd, even;
  string input_file_name;
  ifstream input_file, line;

  cin >> input_file_name;
  input_file.open(input_file_name, ios::in);
  if(input_file.is_open()){
    while (input_file >> number) {
      if(number%2) {
        odd.push_back(number);
      }
      else {
        even.push_back(number);
      }
    }
  }
  else return 1;

  for(vector<int>::size_type i = 0; i < even.size(); i++){
    cout << even.at(i) << " ";
  }
  cout << endl;
  for(vector<int>::size_type i = 0; i < odd.size(); i++){
    cout << odd.at(i) << " ";
  }
  cout << endl;
  return 0;
}
