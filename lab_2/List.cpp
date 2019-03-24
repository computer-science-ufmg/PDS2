#include "List.hpp"

List::List(){
	this->size = 0;
	this->head = NULL;
}

void List::insert(int value){
	Node* node = new Node;
	node->value = value;
	node->next = this->head;
	this->head = node;
	this->size++;
}

void List::clearList() {
	if (this->size > 0){
		Node* current = this->head;
		Node* next = current->next;
		this->head = NULL;
		delete current;
		this->size--;
		while(next){
			current = next;
			next = current->next;
			delete current;
			this->size--;
		}
	}
}

void List::print(){
	Node* current = this->head;
	if (this->size > 0){
		while(current){
			std::cout << current->value << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}
	else{
		std::cout << "-" << std::endl;
		return;
	}
}

int List::removeFirst(){
	if(this->size == 0) return -1;
	Node* current = this->head;
	int value = current->value;
	this->head = current->next;
	this->size--;
	delete current;
	return value;
}

int List::indexOf(int value){
	if (this->size > 0){
		int index = 0;
		Node* current = this->head;
		while(current){
			if(current->value == value) return index;
			current = current->next;
			index++;
		}
		return -1;
	}
	else{
		return -1;
	}
}

void List::remove(int value){
	if(this->size == 0) return;
	int index = this->indexOf(value);
	if(index == -1) return;
	if(index == 0){
		Node* current = this->head;
		this->head = this->head->next;
		this->size--;
		delete current;
	}
	else{
		Node* previous = this->head;
		Node* current = this->head->next;
		for (int i = 1; i != index; i++) {
			if (current) {
				previous = current;
				current = current->next;
			}
			else return;
		}
		previous->next = current->next;
		this->size--;
		delete current;
	}
}
