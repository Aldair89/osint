#include <iostream>
#include <string>
#include <regex>
#include <vector>

std::vector<std::string> FindUserURLs(const std::string& input, const std::string& username)
{
    std::vector<std::string> userURLs;
    std::regex urlRegex(R"(https?://[^\s/$.?#].[^\s]*)");

    std::sregex_iterator it(input.begin(), input.end(), urlRegex);
    std::sregex_iterator end;

    while (it != end)
    {
        std::string url = it->str();
        if (url.find(username) != std::string::npos)
        {
            userURLs.push_back(url);
        }
        ++it;
    }

    return userURLs;
}

void PrintBanner()
{
    std::string banner =
        "   ____             _     \n"
        "  / ___| ___   __ _| |___ \n"
        " | |  _ / _ \\ / _` | / __|\n"
        " | |_| | (_) | (_| | \\__ \\\n"
        "  \\____|\\___/ \\__,_|_|___/\n";

    std::cout << banner << std::endl;
}

int main()
{
    PrintBanner();

    std::string userInput;
    std::string username;

    std::cout << "Ingrese un texto que pueda contener URLs: ";
    std::getline(std::cin, userInput);

    std::cout << "Ingrese un nombre de usuario: ";
    std::cin >> username;

    std::vector<std::string> userURLs = FindUserURLs(userInput, username);

    if (userURLs.empty())
    {
        std::cout << "No se encontraron URLs para el nombre de usuario '" << username << "'." << std::endl;
    }
    else
    {
        std::cout << "URLs encontradas para el nombre de usuario '" << username << "':" << std::endl;
        for (const std::string& url : userURLs)
        {
            std::cout << url << std::endl;
        }
    }

    return 0;
}
