#include <string>

class Worker {
private:
    std::string fullname;
    long id;
protected:
    virtual void Data() const;
    virtual void Get();
public:
    Worker() : fullname("no one"), id(0L) {}
    Worker(const std::string &name, long n)
            : fullname(name), id(n) {}
    virtual ~Worker() = 0;
    virtual void Set() = 0;
    virtual void Show() const = 0;
};

class Waiter : virtual public Worker {
private:
    int panache;
protected:
    void Data() const;
    void Get();
public:
    Waiter() : Worker(), panache(0) {}
    Waiter(const std::string &name, long n, int p = 0 )
            : Worker(name, n), panache(p) {}
    Waiter(const Worker &w, int p = 0)
            : Worker(w), panache(p) {}
    void Set();
    void Show() const;
};

class Singer : virtual public Worker {
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenoir};
    enum {Vtypes = 7};
    void Data() const;
    void Get();
private:
    static char *pv[Vtypes];
    int voice;
public:
    Singer() : Worker(), voice(other) {}
    Singer(const std::string &name, long n, int v = other)
            : Worker(name, n), voice(v) {}
    Singer(const Worker &worker, int v = other)
            : Worker(worker), voice(v) {}
    void Set();
    void Show() const;
};

class SingingWaiter : public Singer, public Waiter {
protected:
    void Data() const;
    void Get();
public:
    SingingWaiter() {}
    SingingWaiter(const std::string name, long n, int p = 0, int v = other)
            : Worker(name, n), Singer(name, n, v), Waiter(name, n, p) {}
    SingingWaiter(const Worker &worker, int p = 0, int v = other)
            : Worker(worker), Singer(worker, v), Waiter(worker, p) {}
    SingingWaiter(const Singer &singer, int p = 0)
            : Worker(singer), Singer(singer), Waiter(singer, p) {}
    void Set();
    void Show() const;
};