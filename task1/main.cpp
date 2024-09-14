#include <QCoreApplication>
#include <QFile>
#include <QTextStream>
#include <QRandomGenerator>
#include <QString>
#include <QRegularExpression>
#include <iostream>

QString generateRandomString(int length)
{
	const QString possibleCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
	QString randomString;
	for(int i = 0; i < length; ++i) 
	{
        	int index = QRandomGenerator::global()->bounded(possibleCharacters.length());
        	randomString.append(possibleCharacters.at(index));
    	}
    	return randomString;
}

void generateCSVFile(const QString& fileName, int rows, int columns) 
{
    	QFile file(fileName);
    	if (file.open(QIODevice::WriteOnly)) 
	{
        	QTextStream stream(&file);
        	for (int i = 0; i < rows; ++i) 
		{
            		QStringList row;
            		for (int j = 0; j < columns; ++j) 
			{
                		row << generateRandomString(8);
            		}
            	stream << row.join(",") << "\n";
        }
        file.close();
    }
}

bool strStartswithVowLet(const QString& str) 
{
    QRegularExpression regex("^[AEIOUaeiou]");
    QRegularExpressionMatch match = regex.match(str);
    return match.hasMatch();  
}

QString replaceOddDigitsWithHash(const QString& str) 
{
   	 QString result = str;
    	for (int i = 0; i < result.size(); ++i) 
	{
        	if (result[i].isDigit() && result[i].digitValue() % 2 != 0) 
            	result[i] = '#';
    	}
    	return result;
}

void processCSVFile(const QString& inputFileName, const QString& outputFileName) 
{
   	QFile inputFile(inputFileName);
	QFile outputFile(outputFileName);
    
    	if (inputFile.open(QIODevice::ReadOnly) && outputFile.open(QIODevice::WriteOnly)) 
	{
        	QTextStream in(&inputFile);
        	QTextStream out(&outputFile);

        	while (!in.atEnd()) 
		{
            		QString line = in.readLine();
            		QStringList columns = line.split(",");

			if (std::any_of(columns.begin(), columns.end(), [](const QString& column) {
        			return !strStartswithVowLet(column);
    			})) 
			{

    			for (QString& column : columns) 
        			column = replaceOddDigitsWithHash(column);
    		

    			out << columns.join(",") << "\n"; 
					
            		}
        	}

        	inputFile.close();
       	 	outputFile.close();
    	}
}
int main(int argc, char *argv[]) 
{
    	generateCSVFile("output.csv", 1024, 6);//task A
	processCSVFile("output.csv", "edited_output.csv");//task B
	return 0;
}
