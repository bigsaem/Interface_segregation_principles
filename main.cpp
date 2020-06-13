#include <iostream>
//Interface Segregation Principle
//Don't create too large interfaces or interfaces that require to implement too much
struct Document;
//struct Imachine
//{
//
//    virtual void scan(Document& doc) = 0;
//    virtual void fax(Document& doc) = 0;
//};
//
//struct Scanner : Imachine
//{
//    void print(Document &doc) override {
//        //not ok
//    }
//
//    void scan(Document &doc) override {
//        //ok
//    }
//
//    void fax(Document &doc) override {
//        //not ok
//    }
//};
////it's generally okay, but the problem happens when user only printer is needed.
//struct MFP : Imachine
//{
//    void print(Document &doc) override {
//
//    }
//
//    void scan(Document &doc) override {
//
//    }
//
//    void fax(Document &doc) override {
//
//    }
//};

struct IPrinter
{
    virtual void print(Document& doc) = 0;
};
struct IScanner
{
    virtual void scan(Document& doc) = 0;
};
struct IFax
{
    virtual void fax(Document& doc) = 0;
};

struct Scanner : IScanner
{
    void scan(Document &doc) override {

    }
};

struct Printer : IPrinter
{
    void print(Document &doc) override {

    }
};

struct IMachine : IPrinter, IScanner{};

struct Machine : IMachine
{
    IPrinter& printer;
    IScanner& scanner;

    Machine(IPrinter &printer, IPrinter &scanner) : printer(printer), scanner(scanner) {};

    void print(Document &doc) override {
        printer.print(doc);
    }

    void scan(Document &doc) override {
        scanner.scan(doc);
    }
};
int main() {

    return 0;
}
