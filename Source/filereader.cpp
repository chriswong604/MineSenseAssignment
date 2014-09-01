/**
  * Class: FileReader
  * Purpose: The FileReader class opens a file and stores every line of the file.
  */


#include "filereader.h"

/**
 * FileReader Contructor
 * @param source - the file to be read
 */
FileReader::FileReader(QString source)
{
    readFile(source);
}

/**
 * Method: readFile() - Reads the source file and saves every line of the file.
 * @param source - the file to be read
 */
void FileReader::readFile(QString source)
{
    QFile sourceFile(source);
    if(sourceFile.open(QFile::ReadOnly | QFile::Text)){
        QTextStream in(&sourceFile);
        while(!in.atEnd()){
            allText << in.readLine();
        }
    }
    else{
        qDebug() << "Could not open the file for reading";
    }

    sourceFile.close();
}

/**
 * Method: getText()
 * @return - Returns the List of data by lines.
 */
QStringList FileReader::getText()
{
    return allText;
}
