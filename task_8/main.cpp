#include "../include.h"
#include "../functions.cpp"
#include <ios>
#include <fstream>
#include <vector>
#include <filesystem>


enum Type
{
    WORD,
    SEPARATOR,
};

struct Token
{
    std::string value;
    Type type;
};

Type sym_type(char symbol);
std::vector<Token> change_separators(std::vector<Token> tokens);
std::vector<Token> create_tokens(std::string file_name);
void write_in_file(std::vector<Token> tokens, std::string file_name, int width);

int main()
{
    std::string file_name;
    int width;
    std::string input;

    while(true)
    {
        std::cout << "Enter the path to the file: ";
        std::getline(std::cin, file_name);

        try
        {
            if (!std::filesystem::exists(file_name))
                throw "This file does not exists";

            std::cout << "Enter the width of the text: ";
            std::getline(std::cin, input);
            width = check_input(input);
            if (width < 3)
                throw "Enter the value bigger than 2";
        }
        catch (const char* error)
        {
            std::cerr << error << std::endl;
            continue;
        }
        catch (const std::invalid_argument& ai)
        {
            std::cerr << "Unexpected value" << ai.what() << std::endl;
            continue;
        }
        
        write_in_file(change_separators(create_tokens(file_name)), file_name, width);
    }
}

Type sym_type(char symbol)
{
    switch (symbol)
    {
        case ' ':
        case '\n':
        case '\t':
            return SEPARATOR;
        default:
            return WORD;
    }
}

std::vector<Token> create_tokens(std::string file_name)
{
    std::fstream file;
    file.open(file_name);

    std::vector<Token> tokens;
    Token token;
    token.type = WORD;
    token.value = "";

    /*
    if (file.get(symbol))
    {
        token.value = symbol;
        token.type == sym_type(symbol);
    }
    */
    char symbol;
    int index = 0;

    while(file.get(symbol))
    {
        if(token.type == sym_type(symbol))
        {
            token.value.push_back(symbol);
        }
        else
        {
            tokens.push_back(token);
            token.value = symbol;
            token.type = sym_type(symbol);
        }
    }


    file.close();

    return tokens;
}

std::vector<Token> change_separators(std::vector<Token> tokens)
{
    for (auto it = tokens.begin(); it != tokens.end(); it++)
    {
        int count = 0;
        if (it->type == WORD) continue;
        else
        {
            for (auto str_it = it->value.end(); str_it != it->value.begin() - 1; str_it--)
                if (*str_it == '\n') count++;

            if (count >= 2)
                it->value = "\n\n";
            else
                it->value = " ";
        }
    }
    return tokens;
}

void write_in_file(std::vector<Token> tokens, std::string file_name, int width)
{
    std::fstream file;
    file.open(file_name, std::fstream::out | std::fstream::trunc);

    int count = 0;
    int index = 0;
    for (auto it = tokens.begin(); it != tokens.end(); it++)
    {
        if (it->value == "\n\n") count = 0;
        else
        {
            if (count + it->value.length() <= width)
                count += it->value.length();
            else if ((count + it->value.length() > width) && (it->value.length() <= width))
            {
                file << '\n';
                if (it->value == " ") 
                {
                    count = 0;
                    continue;
                }

                count = it->value.length();
            }
            else
            {
                file << it->value;
                count = it->value.length();
                continue;
            }
        }

        file << it->value;
    }

    file.close();
}
