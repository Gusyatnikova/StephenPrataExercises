#pragma once
#include <iostream>
#include <string>
//initial
/*
class baseDMA {
private:
    char* label;
    int rating;
public:
    baseDMA(const char *l = "null", int r = 0);
    baseDMA(const baseDMA& rs);
    virtual ~baseDMA();
    baseDMA& operator=(const baseDMA &rhs);
    friend std::ostream& operator<<(
            std::ostream& os, const baseDMA &rs);
};

class lacksDMA : public baseDMA {
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const char *c = "blank",
            const char *l = "null", int r = 0);
    lacksDMA(const char *c, const baseDMA &rs);
    friend std::ostream& operator<<(
            std::ostream& os, const lacksDMA &rhs);
};

class hasDMA : public baseDMA {
private:
    char *style;
public:
    hasDMA(const char *s = "none",
            const char *l = "null", int r = 0);
    hasDMA(const char *s, const baseDMA &r);
    hasDMA(const hasDMA &h);
    ~hasDMA();
    hasDMA& operator=(const hasDMA &h);
    friend std::ostream& operator<<(std::ostream &os, const hasDMA &h);
};*/
//with abstract base class (for 13 - 3)

class AbstractDMA {
private:
    char* label;
public:
    AbstractDMA(const std::string& l);
    AbstractDMA(const AbstractDMA &aDma);
    AbstractDMA();
    virtual ~AbstractDMA();
    AbstractDMA& operator=(const AbstractDMA &aDma);
    virtual void View() const = 0;
    friend std::ostream& operator<<(
            std::ostream& os, const AbstractDMA &aDma);
};

class baseDMA : public AbstractDMA {
private:
    int rating;
public:
    baseDMA(const std::string& l, int r = 0);
    baseDMA(const baseDMA& rs);
    ~baseDMA();
    void View() const;
    baseDMA& operator=(const baseDMA &rhs);
    friend std::ostream& operator<<(
            std::ostream& os, const baseDMA &rs);
};

class lacksDMA : public AbstractDMA {
private:
    enum {COL_LEN = 40};
    char color[COL_LEN];
public:
    lacksDMA(const std::string& c = "blank",
             const std::string& l = "null");
    lacksDMA(const std::string& c, const AbstractDMA &rs);
    void View() const;
    friend std::ostream& operator<<(
            std::ostream& os, const lacksDMA &rhs);
};

class hasDMA : public AbstractDMA {
private:
    char *style;
public:
    hasDMA(const std::string& s = "none",
           const std::string& l = "null");
    hasDMA(const std::string& s, const AbstractDMA &r);
    hasDMA(const hasDMA &h);
    ~hasDMA();
    void View() const;
    hasDMA& operator=(const hasDMA &h);
    friend std::ostream& operator<<(std::ostream &os, const hasDMA &h);
};