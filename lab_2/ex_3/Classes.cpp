#include <iostream>
#include "Classes.hpp"

using namespace std;

int ClasseBase::get_var_public(){
  return this->var_public;
}

int ClasseBase::get_var_private(){
  return this->var_private;
}

int ClasseBase::get_var_protected(){
  return this->var_protected;
}

void ClasseBase::set_var_public(int v){
  this->var_public = v;
}

void ClasseBase::set_var_private(int v){
  this->var_private = v;
}

void ClasseBase::set_var_protected(int v){
  this->var_protected = v;
}

//----------------------------------------------------------------------------//

int A2::get_var_public(){
  return ClasseBase::get_var_public();
}

string A2::get_var_private(){
  return "Inacessivel";
}

int A2::get_var_protected(){
  return ClasseBase::get_var_protected();
}

int A2::get_var_public2(){
  return this->var_public2;
}

int A2::get_var_private2(){
  return this->var_private2;
}

int A2::get_var_protected2(){
  return this->var_protected2;
}

void A2::set_var_public2(int v){
  this->var_public2 = v;
}

void A2::set_var_private2(int v){
  this->var_private2 = v;
}

void A2::set_var_protected2(int v){
  this->var_protected2 = v;
}

void A2::set_var_public(int v){
   ClasseBase::set_var_public(v);
}

void A2::set_var_private(int v){
  // cout << "Inacessivel" << endl;
}

void A2::set_var_protected(int v){
   ClasseBase::set_var_protected(v);
}

//----------------------------------------------------------------------------//

string A3::get_var_public(){
  return "Inacessivel";
}

string A3::get_var_protected(){
  return "Inacessivel";
}

string A3::get_var_private2(){
  return "Inacessivel";
}

int A3::get_var_public3(){
  return this->var_public3;
}

int A3::get_var_private3(){
  return this->var_private3;
}

int A3::get_var_protected3(){
  return this->var_protected3;
}

void A3::set_var_private2(int v){
  // cout << "Inacessivel" << endl;
}

void A3::set_var_public3(int v){
  this->var_public3 = v;
}

void A3::set_var_private3(int v){
  this->var_private3 = v;
}

void A3::set_var_protected3(int v){
  this->var_protected3 = v;
}

//----------------------------------------------------------------------------//

ClassePublica::ClassePublica(){
    var_public = 0;
    var_protected = 0;
}

string ClassePublica::get_var_private(){
  return "Inacessivel";
}

void ClassePublica::set_var_private(int v){
  // cout << "Inacessivel" << endl;
}

//----------------------------------------------------------------------------//

ClassePrivada::ClassePrivada(){
}

int ClassePrivada::get_var_public(){
  return ClasseBase::get_var_public();
}

string ClassePrivada::get_var_private(){
  return "Inacessivel";
}

int ClassePrivada::get_var_protected(){
  return ClasseBase::get_var_protected();
}

void ClassePrivada::set_var_public(int v){
   ClasseBase::set_var_public(v);
}

void ClassePrivada::set_var_private(int v){
   // ClasseBase::set_var_private(v);
}

void ClassePrivada::set_var_protected(int v){
   ClasseBase::set_var_protected(v);
}

//----------------------------------------------------------------------------//

int OverloadPrivada::get_var_public(){
  return this->var_public;
}

int OverloadPrivada::get_var_private(){
  return this->var_private;
}

int OverloadPrivada::get_var_protected(){
  return this->var_protected;
}

void OverloadPrivada::set_var_public(int v){
  this->var_public = v;
}

void OverloadPrivada::set_var_private(int v){
  this->var_private = v;
}

void OverloadPrivada::set_var_protected(int v){
  this->var_protected = v;
}
