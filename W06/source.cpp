#include "header.h"

//CItem
CItem::CItem() : name(""), size(0), roAttr(0), hiAttr(0){};

CItem::CItem(const string name) : name(name), size(0), roAttr(0), hiAttr(0){};

CItem::CItem(const string name, const int s) : name(name), size(s), roAttr(0), hiAttr(0){};
CItem::CItem(const string name, const bool hiAttr, const bool roAttr) : name(name), size(0), roAttr(roAttr), hiAttr(hiAttr){};

void CItem::print(bool printHidden, string t)
{
    if (printHidden | !hiAttr)
    {
        cout << name << endl;
        cout << t << "Size: " << size << endl;
        cout << t << "Read only attributes: " << roAttr << endl;
        cout << t << "Hidden attributes: " << hiAttr << endl;
    }
}

CItem *CFolder::removeByName(const string name)
{
    bool flag = false;
    int n = this->content.size();
    for (int i = 0; i < n; ++i)
    {
        if (content[i]->getName() == name)
        {
            --numFolders;
            size -= content[i]->getSize();
            content.erase(content.begin() + i);
            flag = true;
            break;
        }
    }

    if (flag)
    {
        cout << "Successfully remove folder " << name << endl;
        return this;
    }

    cout << "Removal failed! No folder name: " << name << endl;
    return nullptr;
}

int CItem::getSize()
{
    return size;
}

string CItem::getName()
{
    return name;
}

bool CItem::getHi()
{
    return hiAttr;
}

//Folder
CFolder::CFolder(const string name)
    : CItem(name), numFiles(0), numFolders(0){};

CFolder::CFolder(const string fName, const bool hi, const bool ro)
    : CItem(fName, hi, ro), numFiles(0), numFolders(0){};

void CFolder::input(string fName)
{
    int choice;
    while (1)
    {
        cout << "Current folder: " << fName << ":\\" << endl;
        cout << "Enter 1 to add a folder, 2 to add a file or 0 to go back" << endl;
        cin >> choice;
        cin.ignore(1);

        CItem *pItem = nullptr;

        if (choice == 1)
        {
            string nname;
            bool hi, ro;
            cout << "Folder name: ";
            getline(cin, nname, '\n');
            cout << "Hidden?";
            cin >> hi;
            cout << "Read only?";
            cin >> ro;
            pItem = new CFolder(nname, hi, ro);
            cout << "Continue add something in " << fName << ":\\" << pItem->getName() << "?" << endl;
            cin >> choice;
            if (choice)
                pItem->input(fName + ":\\" + pItem->getName());
            ++numFolders;
        }
        else if (choice == 2)
        {
            pItem = new CFile("", 0);
            pItem->input("");
            ++numFiles;
        }
        else
            return;

        content.push_back(pItem);

        int sum = 0;
        for (int i = 0; i < content.size(); ++i)
            sum += content[i]->getSize();
        this->size = sum;
    }
}

void CFolder::add(CFile *rhs)
{
    ++numFiles;
    size += rhs->getSize();
    content.push_back(rhs);
}

void CFolder::add(CFolder *rhs)
{
    ++numFolders;
    size += rhs->getSize();
    content.push_back(rhs);
}

void CFolder::print(bool printHidden, string t)
{
    if (printHidden | !hiAttr)
    {
        cout << t << "Folder: ";
        CItem::print(printHidden, t);
        cout << t << "Number of files: " << numFiles << endl;
        cout << t << "Number of folders: " << numFolders << endl;
        cout << t << "Content:" << endl;

        for (int i = 0; i < this->content.size(); ++i)
        {
            content[i]->print(printHidden, t + "    ");
        }
    }
}

CItem *CFolder::findByName(const string name)
{
    if (this->name == name)
        return this;

    CItem *p;
    int n = this->content.size();
    for (int i = 0; i < n; ++i)
    {
        p = content[i]->findByName(name);
        if (p)
            return p;
    }

    return nullptr;
}

int CFolder::getNumFiles()
{
    return numFiles;
}

int CFolder::getNumFolders()
{
    return numFolders;
}

void CFolder::setHidden(bool isHidden, bool isAppToChild)
{
    hiAttr = isHidden;
    int n = this->content.size();
    if (isAppToChild)
    {
        for (int i = 0; i < n; ++i)
        {
            content[i]->setHidden(isHidden, isAppToChild);
        }
    }
}

//File
CFile::CFile(const string name, const int s)
    : CItem(name, s){};

void CFile::print(bool printHidden, string t)
{
    if (printHidden | !hiAttr)
    {
        cout << t << "File: ";
        CItem::print(printHidden, t);
    }
}

CItem *CFile::removeByName(const string name)
{
    return nullptr;
}

CItem *CFile::findByName(const string name)
{
    if (this->name == name)
        return this;
    return nullptr;
}

void CFile::setHidden(bool isHidden, bool isAppToChild)
{
    hiAttr = isHidden;
}

void CFile::input(string fName)
{
    cout << "File name: ";
    getline(cin, name, '\n');
    cout << "File size: ";
    cin >> size;
    cout << "Hidden?";
    cin >> hiAttr;
    cout << "Read only?";
    cin >> roAttr;
}