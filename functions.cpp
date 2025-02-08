int check_input(std::string input)
{
    for (std::string::iterator it = input.begin(); it != input.end(); it++)
        if (!std::isdigit(*it))
            throw "Unexpected value";
    return std::stoi(input);
}
