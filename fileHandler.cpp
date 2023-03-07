#include <iostream>
#include <fstream>
#include <string>
#include <vector>

void readFromFile(const std::string& filename, std::vector<std::string>& lines)
{
    std::string line;
    std::ifstream input_file(filename);
    if (!input_file.is_open()) {
        std::cerr << "Could not open the file - '"
             << filename << "'" << std::endl;
    }
    for (const auto &i : lines)
        std::cout << i << std::endl;
    input_file.close();
}
void writeToFile(const std::string& filename, std::string message,std::vector<std::string>& lines)
{
    std::ofstream file_out;
    file_out.open(filename, std::ofstream::app);
    if (!file_out.is_open()) 
    {
        std::cout << "failed to open " << filename << '\n';
    }
    else 
    {
        file_out << message << std::endl;
        lines.push_back(message);
    }
    file_out.close();
}
void deleteFromFile(const std::string& filename,std::string eraseindex,std::vector<std::string>& lines) 
{
    std::ifstream oldfile(filename);
    
    lines.erase(lines.begin()+ stoi(eraseindex));
    // contents of path must be copied to a temp file then
    // renamed back to the path file
    std::ofstream temp;
    temp.open("temp.txt");

    std::string line;
    while (std::getline(oldfile, line)) {
        // write all lines to temp other than the line marked for erasing
        if (line != lines[stoi(eraseindex)])
            temp << line << std::endl;
    }

    temp.close();
    oldfile.close();

    // required conversion for remove and rename functions
    const char * p = filename.c_str();
    std::remove(p);
    std::rename("temp.txt", p);
}