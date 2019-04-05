#include <iostream>
#include "List.hpp"

int main(){
  List *L = new List();
  int n, k;

  std::cin >> n;
  std::cin >> k;
  for (int i = 0; i <= n; i++) {
    L->insert(i);
  }
  L->print();
  std::cout << L->size << std::endl;
  for (size_t i = 0; i < k; i++) {
    L->removeFirst();
  }
  L->print();
  std::cout << L->size << std::endl;
  for (int i = 0; i <= n-k; i += 2) {
    L->remove(i);
  }
  L->print();
  std::cout << L->size << std::endl;
  L->clearList();
  delete L;
  
  return 0;
}
