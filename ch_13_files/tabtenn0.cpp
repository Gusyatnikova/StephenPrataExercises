#include "tabtenn0.h"

TableTennisPlayer::TableTennisPlayer(const std::string &fn,
                                     const std::string &ln, bool hs)
        : firstname(fn), lastname(ln), hasTable(hs) {
    std::cout << "TableTennisPlayer(const std::string &fn,"
                 "const std::string &ln, bool hs)\n";
}

TableTennisPlayer::TableTennisPlayer(const TableTennisPlayer &ttp)
        : firstname("__" + ttp.firstname + "__"),
          lastname("__" + ttp.lastname + "__"),
          hasTable(ttp.hasTable) {
    std::cout << "TableTennisPlayer(const TTP &ttp)\n";
}

TableTennisPlayer::~TableTennisPlayer() {
    std::cout << "~TableTennisPlayer() -"
              << lastname << ", " << firstname << ";\n";
}

void TableTennisPlayer::Name() const {
    std::cout << lastname << ", " << firstname;
}

RatedPlayer::RatedPlayer(unsigned int r, const std::string &fn,
                         const std::string &ln, bool ht)
        : TableTennisPlayer(fn, ln, ht), rating(r) {
    std::cout << "RatedPlayer(TTP(fn, ln,ht), rating(r))\n";
}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer &tp)
        : TableTennisPlayer(tp), rating(r) {
    std::cout << "RatedPlayer(TTP(const TTP &tp), rating(r))\n";
}

RatedPlayer::~RatedPlayer() {
    std::cout << "~RatedTennisPlayer()"
              << rating << ";\n";
}

