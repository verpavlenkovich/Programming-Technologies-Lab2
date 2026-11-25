
#ifndef ROUTE_H
#define ROUTE_H

#include <iosfwd>
#include <string>

class ROUTE {
private:
    std::string start_;
    std::string finish_;
    int number_;

public:
    ROUTE();

    ROUTE(const std::string& start,
          const std::string& finish,
          int number);

    ROUTE(const ROUTE& other);
    ROUTE& operator=(const ROUTE& other);
    ~ROUTE();

    const std::string& getStart() const;
    const std::string& getFinish() const;
    int getNumber() const;

    void setStart(const std::string& start);
    void setFinish(const std::string& finish);
    void setNumber(int number);

    friend std::istream& operator>>(std::istream& in, ROUTE& route);
    friend std::ostream& operator<<(std::ostream& out, const ROUTE& route);
};

#endif
