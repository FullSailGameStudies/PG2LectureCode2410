// Day10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>



/*
    ╔══════════╗
    ║ File I/O ║
    ╚══════════╝

    3 things are required for File I/O:
    1) Open the file
    2) read/write to the file
    3) close the file



*/
int main()
{
    std::cout << "Hello PG2!\n";
    std::string path = "";// "C:\\temp\\2410\\";
    std::string fileName = "pg2_2410.csv";
    std::string fullPath = path + fileName;

    //1. open the file
    std::ofstream outFile(fullPath);
    char delim = '^';
    if (outFile.is_open())
    {
        //2. write to the file
        //      <<  insertion operator
        // separate each piece of data with the delimiter
        outFile << "Batman rules! Aquaman drools." << delim << 5;
        outFile << delim << 420.12 << delim << true;
        outFile << delim << "Superman is an alien.";
    }
    else
        std::cout << fullPath << " could not be opened.\n";

    //3. close the file
    outFile.close();

    /*

        ╔════════════════╗
        ║ write csv data ║
        ╚════════════════╝

        [  Open the file  ]
        [  Write to the file  ]
        [  Close the file  ]

        you need the path to the file
            use full path ( drive + directories + filename )
            or use relative path ( directories + filename )
            or current directory ( filename )

        Make sure to separate the data in the file with a delimiter.
        The delimiter is important because it is used
            to separate the data when reading the file back in.


        Lecture code: set a filePath variable, open an output file, write some csv data to it
    */


    /*

        ╔═══════════════╗
        ║ read csv data ║
        ╚═══════════════╝

        [  Open the file  ]
        [  read the file  ]
        [  Close the file  ]

        Lecture code: using the filePath variable, open an input file, use getline to read a line, print the line
    */
    std::string input;
    std::getline(std::cin, input);

    //1. open the file
    std::ifstream inFile(fullPath);
    if (inFile.is_open())
    {
        //2. read the file
        //stops reading the file when a \n or end of stream
        std::getline(inFile, input, '\n');

        std::cout << "\n" << input << "\n";

        //parse the data out of the string
        std::string data;
        std::stringstream inputStream(input);

        try
        {
            std::getline(inputStream, data, delim);
            std::cout << data << "\n";

            std::getline(inputStream, data, delim);
            int iNum = std::stoi(data);
            std::cout << iNum << "\n";

            std::getline(inputStream, data, delim);
            double dNum = std::stod(data);
            std::cout << dNum << "\n";

            std::getline(inputStream, data, delim);
            bool bNum;// = std::stoi(data);
            bNum = data == "1";
            //bNum = (data == "1") ? true : false;//ternary operator
            //if (data == "1") bNum = true;
            //else bNum = false;
            std::cout << ((bNum) ? "true" : "false") << "\n";

            std::getline(inputStream, data, delim);
            std::cout << data << "\n";

        }
        catch (const std::exception& ex)
        {
            std::cout << "Could not read the file. Incorrect format.\n" << ex.what() << "\n";
        }
    }
    else
        std::cout << fullPath << " could not be opened.\n";

    //3. close the file
    inFile.close();


    /*

        ╔═════════════════════╗
        ║ parsing csv strings ║
        ╚═════════════════════╝
        
        use getline on a string stream instead of a file stream

        Lecture code: 
            using the line read in above, use a stringstream to split the line using getline.
            store the separate items in a vector
            parse each item in the vector to an appropriate variable.
        

    */





    /*

        CHALLENGE:

        Parse the multi csv string (below) to get the data.
        NOTE: the data is a collection of object data.
        There are multiple delimiters.
        Separate on the first delimiter (collectionSeparator) to get the csv data for each object.
        Then, separate the object csv data on objectSeparator to get the details of the object.

        EX: hero#hero#hero   each hero is separated by a #
            name^secret^age  the details of each hero is separated by a ^

    */
    std::string multi = "Batman^Bruce Wayne^35#Superman^Clark Kent^25#Wonder Woman^Diana Prince^25#Aquaman^Arthur Curry^12";
    char collectionSeparator = '#';
    char objectSeparator = '^';

    std::stringstream multiStream(multi);
    std::string heroCSV;
    //for (;std::getline(multiStream,heroCSV, collectionSeparator);)
    while(!multiStream.eof())
    {
        std::getline(multiStream, heroCSV, collectionSeparator);

        std::string name, secret;
        int age;

        std::stringstream heroStream(heroCSV);
        std::getline(heroStream, name, objectSeparator);
        std::getline(heroStream, secret, objectSeparator);
        std::string ageStr;
        std::getline(heroStream, ageStr, objectSeparator);
        age = std::stoi(ageStr);

        std::cout << "Hello citizens. I am " << name;
        std::cout << "! (aka " << secret << "). I am ";
        std::cout << age << " years old.\n";
    }
}