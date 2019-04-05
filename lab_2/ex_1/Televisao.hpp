#ifndef TELEVISAO_H
#define TELEVISAO_H

class Televisao{
  private:
    unsigned int canal;
    unsigned int volume;
  public:
    Televisao();
    void setCanal(int c);
    void setVolume(int v);
    int getCanal();
    int getVolume();
};

#endif
