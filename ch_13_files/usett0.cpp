#include "tabtenn0.h"

/*
int main() {
    TableTennisPlayer player1("Chick", "Blizzard", true);
    TableTennisPlayer player2("Tara", "Boomdea", false);
    player1.Name();
    if (player1.HasTable()) {
        std::cout << ": has a table.\n";
    } else {
        std::cout << ": hasn't a table.\n";
    }
    player2.Name();
    if (player2.HasTable()) {
        std::cout << ": has a table.\n";
    } else {
        std::cout << ": hasn't a table.\n";
    }
    TableTennisPlayer player3;
    player3.Name();
    if (player3.HasTable()) {
        std::cout << ": has a table.\n";
    } else {
        std::cout << ": hasn't a table.\n";
    }
    return 0;
}*/
void Show(const TableTennisPlayer &ttp) {
    ttp.Name();
    std::cout << "\nTable: ";
    if (ttp.HasTable()) {
        std::cout << "yes\n";
    } else {
        std::cout << "no\n";
    }
}
/*int main() {
    TableTennisPlayer player1("Tara", "Boomdea", false);
    RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
    Show(rplayer1);
    Show(player1);
    std::cout << "Name: ";
    rplayer1.Name();
    std::cout << "; Rating: " << rplayer1.Rating() << std::endl;
    RatedPlayer rplayer2(1212, player1);
    std::cout << "Name: ";
    rplayer2.Name();
    std::cout << "; Rating: " << rplayer2.Rating() << std::endl;
    //
    RatedPlayer olaf1(1840, "Olaf", "Loaf", true);
    TableTennisPlayer olaf2(olaf1);
    RatedPlayer olaf3(1840, "Olaf3", "Loaf3", true);
    TableTennisPlayer winner = olaf3;
    return 0;
}*/
//---------------p.671----------------------------------//