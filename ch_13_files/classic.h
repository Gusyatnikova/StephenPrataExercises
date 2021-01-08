#pragma once
class Cd {
private:
    //char performers[50];
    //char label[20];
    char *performers;
    char *label;
    int selections;
    double playtime;
public:
    Cd(const char *p, const char *l,
            int s, double pt);
    Cd(const Cd &c);
    Cd();
    virtual ~Cd();
    virtual void Report() const;
    Cd &operator=(const Cd &c);
};

class Classic : public Cd {
private:
    char *main;
public:
    Classic(const char *m, const char *p, const char *l,
            int c, double pt);
    Classic(const Classic &c);
    Classic();
    ~Classic() override;
    void Report() const override;
    Classic& operator=(const Classic &src);
};
