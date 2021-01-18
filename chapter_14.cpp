#include <iostream>
#include <cstring>
#include <string>
#include <valarray>
#include <ctime>

#include "ch_14_files/pair.h"
#include "ch_14_files/worker0.h"
#include "ch_14_files/emp.h"
//14 - 1
/*class Wine {
private:
    std::string label;
    Pair<std::valarray<int>, std::valarray<int>> pair;
    unsigned int year;
public:
    Wine() {
        label = "";
        year = 0;
    }
    Wine(const char *l, int y, const int yr[], const int bot[]) {
        label = l;
        year = y;
        pair.first() = std::valarray<int>(yr, y);
        pair.second() = std::valarray<int>(bot, y);
    }
    Wine(const char *l, int y) {
        label = l;
        year = y;
        pair.first() = pair.second() = std::valarray<int>(y);
    }
    void GetBottles() {
        std::cout << "Enter " << label << " data "
                  << " for " << year << " year(s):\n";
        for (int i = 0; i < year; ++i) {
            std::cout << "Enter year:";
            std::cin >> pair.first()[i];
            //std::cout << std::endl;
            std::cout << "Enter bottles for that year:";
            std::cin >> pair.second()[i];
            //std::cout << std::endl;
            //while(std::cin.get() != '\n') continue;
        }
        while(std::cin.get() != '\n') continue;
    }
    const std::string& Label() const { return label; }
    unsigned int sum() const {
        return pair.second().sum();
    }
    void Show() const {
        std::cout << "Wine: " << label << "\n"
                  << "\tYear\tBottles\n";

        for (int i = 0; i < year; ++i) {
            std::cout << "\t" << pair.first()[i]
                      << "\t" << pair.second()[i] << '\n';
        }
    }
};*/
//14 - 2
/*

class Wine :
        std::string, private Pair<std::valarray<int>, std::valarray<int>> {
private:
    //std::string label;
    //Pair<std::valarray<int>, std::valarray<int>> pair;
    unsigned int year;
public:
    Wine() : std::string(""), year(0) {}
    Wine(const char *l, int y, const int yr[], const int bot[]) {
        std::string() = l;
        year = y;
        Pair::first() = std::valarray<int>(yr, y);
        Pair::second() = std::valarray<int>(bot, y);
    }
    Wine(const char *l, int y) {
        std::string() = l;
        year = y;
        Pair::first() = Pair::second() = std::valarray<int>(y);
    }
    void GetBottles() {
        std::cout << "Enter " << (const std::string&)(*this) << " data "
                  << " for " << year << " year(s):\n";
        for (int i = 0; i < year; ++i) {
            std::cout << "Enter year:";
            std::cin >> Pair::first()[i];
            //std::cout << std::endl;
            std::cout << "Enter bottles for that year:";
            std::cin >> Pair::second()[i];
            //std::cout << std::endl;
            //while(std::cin.get() != '\n') continue;
        }
        while(std::cin.get() != '\n') continue;
    }
    const std::string& Label() const { return (const std::string&)(*this); }
    unsigned int sum() const {
        return Pair::second().sum();
    }
    void Show() const {
        std::cout << "Wine: " << (const std::string&)(*this) << "\n"
                  << "\tYear\tBottles\n";

        for (int i = 0; i < year; ++i) {
            std::cout << "\t" << Pair::first()[i]
                      << "\t" << Pair::second()[i] << '\n';
        }
    }
};

int main() {
    std::cout << "Enter name of wine: ";
    char lab[50];
    std::cin.getline(lab, 50);
    std::cout << "Enter number of years: ";
    int yrs;
    std::cin >> yrs;
    Wine holding(lab, yrs);

    holding.GetBottles();
    holding.Show();
    const int YRS = 3;
    int y[YRS] = {1993, 1995, 1998};
    int b[YRS] = {48, 60, 72};
    Wine more("Gushing Grape Red", YRS, y, b);
    more.Show();
    std::cout << "Total bottles for " << more.Label()
              << ": " << more.sum() << std::endl;
    std::cout << "Bye!\n";
    return 0;
}*/
//14 - 3
/*
template <typename T, int n>
class QueueTp {
private:
    T array[n];
    int front;
    int back;
public:
    QueueTp() : front(-1), back(-1) {}
    QueueTp(const QueueTp& q) {
        front = q.front;
        back = q.back;
        for (int i = 0; i < back; ++i)
            array[i] = q.array[i];
    }
    ~QueueTp() { }
    bool push(const T &val) {
        if (back == n - 1)
            return false;
        if (front == -1) front = 0;
        array[++back] = val;
        return true;
    }
    bool pop(T &val) {
        if (front == -1 || front > back)
            return false;
        val = array[front++];
        return true;
    }
    T& get_first() {
        //if (front >= 0 )
        return array[front];
    }
    T& get_last() {
        //if (front >= 0 )
        return array[back];
    }
    int size() const { return back - front; }
};

const int SIZE = 5;

int main() {
    QueueTp<Worker*, SIZE> lolas;
    int ct;
    for (ct = 0; ct < SIZE; ++ct) {
        char choice;
        std::cout << "Enter the employee category:\n"
                  << "w: waiter s: singer t: singing water q: quit\n";
        std::cin >> choice;
        while(std::strchr("wstq", choice) == NULL) {
            std::cout << "Enter w, s, t, or q:";
            std::cin >> choice;
        }
        if (choice == 'q') break;
        switch (choice) {
            case 'w' :
                lolas.push(new Waiter);
                break;
            case 's' :
                lolas.push(new Singer);
                break;
            case 't':
                lolas.push(new SingingWaiter);
                break;
        }
        std::cin.get();
        lolas.get_last()->Set();
    }
    std::cout << "\nHere is your stuff:\n";
    int i;
    Worker *tmp;
    for (i = 0; i < ct; ++i) {
        std::cout << std::endl;
        lolas.pop(tmp);
        tmp->Show();
        delete tmp;
    }
    std::cout << "Bye!\n";
    return 0;
}*/
//14 - 4
/*
class Person {
protected:
    std::string firstName;
    std::string lastName;
public:
    Person() : firstName(""), lastName("") {}
    virtual ~Person() {}
    Person(const std::string &fn, const std::string &ln)
            : firstName(fn), lastName(ln) {}
    Person(const Person &person)
            : firstName(person.firstName), lastName(person.lastName) {}
    virtual void Set() {
        std::cout << "Enter first name:";
        std::getline(std::cin, firstName);
        std::cout << "Enter last name:";
        std::getline(std::cin, lastName);
    }
    virtual void Show() const {
        std::cout << "Person:\n";
        std::cout << firstName << " " << lastName;
    }
};

class Gunslinger : public virtual Person {
private:
    int count;
    double time;
protected:
    int GetItems() const { return count; }
    double GetTime()const { return time; }
public:
    //Gunslinger() : Person(), count(0), time(0) {}
    ~Gunslinger(){}
    Gunslinger(const std::string &fn = "", const std::string &ln = "",
               int cnt = 0, double t = 0.0) : Person(fn, ln), count(cnt), time(t) {}
    double Draw() const { return time; }
    void Set() {
        Person::Set();
        std::cout << "Enter Item's count:";
        std::cin >> count;
        std::cout << "Enter time: (x.yz)";
        std::cin >> time;
        //std::cin.get();
    }
    virtual void Show() const {
        std::cout << "Gunslinger:\n";
        //Person::Show();
        std::cout << Person::firstName << " " << Person::lastName;
        std::cout << std::endl;
        std::cout << "Items: " << count
                  << " time: " << time;
    }
};

class PokerPlayer : public virtual Person {
private:
public:
    ~PokerPlayer(){}
    PokerPlayer(const std::string &fn = "", const std::string &ln = "")
            : Person(fn, ln) {}
    int Draw() const {
    std::srand(time(NULL));
    return rand() % 53;
    }
    virtual void Show() const{
        std::cout << "PokerPlayer\n";
        std::cout << Person::firstName << " " << Person::lastName;
        std::cout << "\nCard: " << Draw();
    }
};

class BadDude : public Gunslinger, public PokerPlayer {
private:
public:
    BadDude() : Person(), Gunslinger(), PokerPlayer() {}
    BadDude(const std::string &fn, const std::string &ln,
            int c, double t) : Person(fn, ln),
            Gunslinger(fn, ln, c, t), PokerPlayer(fn, ln) {}
    double Gdraw() { return Gunslinger::Draw(); }
    int Cdraw() { return PokerPlayer::Draw(); }
    void Set() {
        Gunslinger::Set();
        PokerPlayer::Person((Person&)(*this));
    }
    void Show() const {
        std::cout << "BadDude:\n";
        //Gunslinger::Show();
        std::cout << Gunslinger::Person::firstName
                  << Gunslinger::Person::lastName
                  << Gunslinger::GetItems()
                  << Gunslinger::GetTime();
        std::cout << " Card: ";
        std::cout << PokerPlayer::Draw();
    }
};

const int SIZE = 5;

int main() {
    Person *persons[SIZE];
    int ct;
    for (ct = 0; ct < SIZE; ++ct) {
        char choice;
        std::cout << "Enter the person's category:\n"
                  << "p: person - g: gunslinger - k: pokerplayer - "
                     " b: baddude - q: quit\n";
        std::cin >> choice;
        while(std::strchr("pgkbq", choice) == NULL) {
            std::cout << "Enter p, g, k, b or q:";
            std::cin >> choice;
        }
        if (choice == 'q') break;
        switch (choice) {
            case 'p' :
                persons[ct] = new Person;
                break;
            case 'g' :
                persons[ct] = new Gunslinger;
                break;
            case 'k':
                persons[ct] = new PokerPlayer;
                break;
            case 'b' :
                persons[ct] = new BadDude;
                break;
        }
        std::cin.get();
        persons[ct]->Set();
    }
    std::cout << "Here is your stuff:\n";
    for (int i = 0; i < ct; ++i) {
        std::cout << std::endl;
        persons[i]->Show();
        std::cout << "\n________________\n";
    }
    for (int i = 0; i < ct; ++i) {
        delete persons[i];
    }
    std::cout << "\nBye!\n";
    return 0;
}*/
//14 - 5

int main() {
    employee em("Trip", "Harris", "Thumper");
    std::cout << em << std::endl; //fname, lname
    em.ShowAll();//fname, lname, job
    manager ma("Amorphia", "Spindragon", "Nuancer", 5);
    std::cout << ma << '\n';
    ma.ShowAll();
    fink fi("Matt", "Oggs", "Oiler", "Juno Barr");
    std::cout << fi << std::endl;
    fi.ShowAll();
    highfink hf(ma, "Curly Kew");
    hf.ShowAll();
    std::cout << "Press a key for next phase:\n";
    std::cin.get();
    highfink hf2;
    hf2.ShowAll();
    std::cout << "Using abstr_emp * pointer:\n";
    abstr_emp * tri[4] = {&em, &fi, &hf, &hf2};
    for (int i = 0; i < 4; ++i) {
        tri[i]->ShowAll();
    }
    return 0;
}
