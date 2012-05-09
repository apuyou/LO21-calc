#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <string>
#include <stdexcept>

using namespace std;

class Erreur: public exception{
private:
    string info;
public:
    Erreur(const string& x):info(x){}
    string get_info() const{ return info; }
    const char* what() const throw(){return info.c_str();}
    ~Erreur()throw(){}
};

void f(){
    throw Erreur("declenchement d'une exception");
}

#endif // EXCEPTION_H
