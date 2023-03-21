#ifndef LICORICE_H
#define LICORICE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class LicorIce {
  private:

    string name;
    int shatterScore; // higher is more difficult to shatter
    int weapon; // 0 to 1000, higher is better

    //write friend operator in employee class description
    //friend void setNickName(Employee &, string);

public:
  LicorIce();
  ~LicorIce();

  friend bool operator<(const LicorIce &, const LicorIce &);
  friend bool operator>(const LicorIce &, const LicorIce &);
  friend bool operator<=(const LicorIce &, const LicorIce &);
  friend bool operator>=(const LicorIce &, const LicorIce &);
  friend ostream & operator<<(ostream &, const LicorIce &);

  int fireWeapon(); // returns an int from 0 to p-1
  int getShatterScore() {return shatterScore;}
  int getWeapon() {return weapon;}
  string getName() {return name;}

  void setWeapon(int weaponScore) {weapon = weaponScore;}
  void setName (string newName) {name = newName;}
  void setShatter(int newShatter) {shatterScore = newShatter;}
};

#endif
