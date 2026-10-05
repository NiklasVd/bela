#include "match.h"
#include <iostream>
#include <ostream>
using namespace std;

int main(int count, char** params) {
    std::cout << "Bela Card Game -- Niklas Vd, 2026 (c)" << std::endl;
    
    match m;
    m.add_human_player("anisa");
    m.add_human_player("niklas");
    m.start_match();

    return 0;
}