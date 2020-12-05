#ifndef header
#define header

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CItem
{
public:
    CItem();
    CItem(const string name);
    CItem(const string name, const int s);
    CItem(const string name, const bool hiAttr, const bool roAttr);

    virtual void print(bool printHidden, string t);
    virtual CItem *removeByName(const string name) = 0;
    virtual CItem *findByName(const string name) = 0;
    virtual void setHidden(const bool isHidden, const bool isAppToChild) = 0;
    virtual void input(string fName = "") = 0;

    int getSize();
    string getName();
    bool getHi();

protected:
    string name;
    int size;
    bool roAttr, hiAttr;
};

class CFile : public CItem
{
public:
    CFile(const string name, const int s);

    void print(bool printHidden, string t);
    void setHidden(const bool isHidden, const bool isAppToChild);
    void input(string fName = "");

    CItem *removeByName(const string name);
    CItem *findByName(const string name);
};

class CFolder : public CItem
{
public:
    CFolder(const string fName);
    CFolder(const string fName, const bool hi, const bool ro);

    void add(CFile *rhs);
    void add(CFolder *rhs);
    void print(bool printHidden, string t);
    void setHidden(const bool isHidden, const bool isAppToChild);
    void input(string fName = "");

    CItem *removeByName(const string name);
    CItem *findByName(const string name);

    int getNumFolders();
    int getNumFiles();
    vector<CItem *> content;

private:
    int numFiles, numFolders;
    //    vector<CItem *> content;
};

#endif