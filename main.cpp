#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>

void writeToFile(const std::string& filename, std::string message,std::vector<std::string>& lines);
void readFromFile(const std::string& filename, std::vector<std::string>& lines);
void deleteFromFile(const std::string& filename,std::string eraseindex,std::vector<std::string>& lines);
void toUpper(std::string& input);

int main()
{
    constexpr const char* filename("tasks.txt");

    std::vector<std::string> lines;
    std::string input;
    std::string door = 
    R"(
    ..__________..
    ..|         |..
    ..|         |..
    ..| o       |..
    ..|         |..
    ..|         |..
    ..|         |..)";
//..reads through file for the first time to check for file content
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '"
             << filename << "'" << std::endl;
    }
    while (std::getline(input_file, input)){
        lines.push_back(input);
    }
    input_file.close();
//----------------------------------------------
    std::cout << "great day!, here are your current tasks:\n";

    readFromFile(filename, lines);

    std::cout << "\nwhat would you like to do\nadd an item -> enter 1\ndelete an item -> enter 2\nreview tasks -> enter 3\nleave -> enter 4"<< std::endl;
    std::cin >> input;
    while(input != "4"){
        while(input !="1"&& input != "2" && input != "3")
        {
            std::cout << "input was wrong, try again:" << std::endl;
            std::cin >> input;
        }
        if( input == "1")
        {
            std::cout << "add your task below:"<< std::endl;
            std::cin.ignore();
            std::getline(std::cin, input);
            writeToFile(filename, input, lines);
        }
        else if(input == "2")
        {
            std::cout << "which line would you like to delete? (top-most is line 0):"<<std::endl;
            std::cin.ignore();
            std::getline(std::cin, input);
            deleteFromFile(filename, input,lines);
        }
        else 
        {
            std::cout << "here are your current tasks:\n";
            readFromFile(filename, lines);
        }
        std::cout << "\nwhat would you like to do?:"<< std::endl;
        std::cin >> input;

    }
    
    std::cout <<door<< std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout <<"here is the door"<< std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    std::cout <<"bye"<< std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
}
void toUpper(std::string& input)
{
    for(char& i: input)
    {
        i -= 32;
    }
}
