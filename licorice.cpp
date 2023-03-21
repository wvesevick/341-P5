#include "licorice.h"
#include <stdlib.h>

using namespace std;

LicorIce::LicorIce(){
  name = "";
  shatterScore = 0;
  weapon = 0;
}

LicorIce::~LicorIce(){
  //
}

int LicorIce::fireWeapon(){
  return rand() % (weapon-1);
}

bool operator<(const LicorIce & shatter1, const LicorIce & shatter2) {
  if (shatter1.shatterScore < shatter2.shatterScore) {
    return true;
  } else {
    return false;
  }
} // end operator<

bool operator>(const LicorIce & shatter1, const LicorIce & shatter2) {
  if (shatter1.shatterScore > shatter2.shatterScore) {
    return true;
  } else {
    return false;
  }
} // end operator>

bool operator<=(const LicorIce & shatter1, const LicorIce & shatter2) {
  if (shatter1.shatterScore <= shatter2.shatterScore) {
    return true;
  } else {
    return false;
  }
} // end operator<

bool operator>=(const LicorIce & shatter1, const LicorIce & shatter2) {
  if (shatter1.shatterScore <= shatter2.shatterScore) {
    return true;
  } else {
    return false;
  }
} // end operator<


ostream & operator<<(ostream & out, const LicorIce & info){
  out << info.shatterScore;
  return out;
}
