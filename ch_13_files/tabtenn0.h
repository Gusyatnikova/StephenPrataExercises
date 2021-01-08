#pragma once

#include <iostream>

class TableTennisPlayer {
private:
    std::string firstname;
    std::string lastname;
    bool hasTable;
public:
    TableTennisPlayer(const std::string &fn = "none",
                      const std::string &ln = "none",
                      bool ht = false);
    TableTennisPlayer(const TableTennisPlayer &ttp);
    ~TableTennisPlayer();
    void Name() const;
    bool HasTable() const { return hasTable; }
    void ResetTable(bool v) { hasTable = v; }
};

class RatedPlayer : public TableTennisPlayer {
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r = 0, const std::string &fn = "none",
                const std::string &ln = "none", bool ht = false);
    RatedPlayer(unsigned int r, const TableTennisPlayer &tp);
    ~RatedPlayer();
    unsigned int Rating() const { return rating; }
    void ResetRating(unsigned int r) { rating = r; }
};

