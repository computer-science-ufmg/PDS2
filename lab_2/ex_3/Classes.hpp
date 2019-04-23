#include <string>
#ifndef CLASSES_H
#define CLASSES_H

class ClasseBase{
  public:
    int var_public;
    int get_var_public();
    int get_var_private();
    int get_var_protected();
    void virtual set_var_public(int v);
    void virtual set_var_private(int v);
    void virtual set_var_protected(int v);
  private:
    int var_private;
  protected:
    int var_protected;
};


class A2 : private ClasseBase{
  public:
  	int var_public2;
    int get_var_public();
    std::string get_var_private();
    int get_var_protected();
    int get_var_public2();
    int get_var_private2();
    int get_var_protected2();
    void set_var_public2(int v);
    void virtual set_var_private2(int v);
    void set_var_protected2(int v);
    void set_var_public(int v) override;
    void set_var_private(int v) override;
    void set_var_protected(int v) override;
  private:
  	int var_private2;
  protected:
  	int var_protected2;
};


class A3 : public A2{
  public:
  	int var_public3;
    std::string get_var_public();
    std::string get_var_protected();
    std::string get_var_private2();
    int get_var_public3();
    int virtual get_var_private3();
    int get_var_protected3();
    void set_var_private2(int v) override;
    void set_var_public3(int v);
    void set_var_private3(int v);
    void set_var_protected3(int v);
  private:
  	int var_private3;
  protected:
  	int var_protected3;
};


class ClassePublica : public ClasseBase{
  public:
  	int var_public3;
    ClassePublica();
    std::string get_var_private();
    void set_var_private(int v) override;
  private:
  	int var_private3;
  protected:
  	int var_protected3;
};


class ClassePrivada : private ClasseBase{
  public:
    ClassePrivada();
    int get_var_public();
    std::string get_var_private();
    int get_var_protected();
    void set_var_public(int v) override;
    void set_var_private(int v) override;
    void set_var_protected(int v) override;
};

class OverloadPrivada : private ClasseBase{
	public:
    	int var_public;
      int get_var_public();
      int get_var_private();
      int get_var_protected();
      void set_var_public(int v) override;
      void set_var_private(int v) override;
      void set_var_protected(int v) override;
	private:
    	int var_private;
	protected:
    	int var_protected;
};

#endif
