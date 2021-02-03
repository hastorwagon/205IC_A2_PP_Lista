#include "FunkcjeListy.h"

int main() {

    for (int i=0; i<6; i++) {
        DodajNaKoniecListy(i);
        WypiszOdPoczatku();

    }
    for (int i=0; i<3; i++) {
        DodajNaPoczatekListy();
        WypiszOdKonca();
    }

    DodajDoSrodka(78);

    for (int i=4; i>=0; i--) {
        WypiszOdPoczatku();
        UsunZListy();
    }


    return 0;
}