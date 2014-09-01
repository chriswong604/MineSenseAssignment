#ifndef FILEREADER_H
#define FILEREADER_H
#include <QFile>
#include <QString>
#include <QStringList>
#include <QTextStream>
#include <QDebug>
using namespace std;

class FileReader
{

public:
    FileReader(QString source);
    QStringList getText();
private:
    void readFile(QString source);
    QStringList allText;
};

#endif // FILEREADER_H
