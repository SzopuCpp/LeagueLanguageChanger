#include "App.hpp"
#include <iostream>
#include <random>

#define CONFIG_FILE "LlcConfig.json"

namespace llc {

    App::App() : m_console(GetStdHandle(STD_OUTPUT_HANDLE)){}

    void App::Start() {
        PrintTitle();
        if(LoadData(CONFIG_FILE))
        {
            SetColor(Color::red);
            std::cerr << "[ERROR] Invalid data!";
            return;
        }
        Menu();
    }

    App::Color App::RandomColor() const {
        std::random_device rm;
        std::mt19937 mt(rm());
        std::uniform_int_distribution<int> range(0, 15);

        int color;
        while(true)
        {
            color = range(mt);
            if(color != 0) break;
        }
        return Color(color);
    }

    void App::SetColor(App::Color color) {
        SetConsoleTextAttribute(m_console, static_cast<int>(color));
    }

    void App::PrintTitle() {
        for(const auto& line : m_title) {
            for(const auto& character : line)
            {
                std::cout << character;
                SetColor(RandomColor());
            }
            std::cout << "\n";
        }
        SetColor(Color::lightGray);
        std::cout << "\n\nPress Enter to continue...";
        std::cin.get();
        std::system("cls");
    }

    int App::LoadData(const char *fileName) {
        m_json.Load(fileName);

        if(m_json.m_content.contains("LanguageSettings"))
        {
            if(m_json.m_content["LanguageSettings"].contains("language"))
            {
                m_data.m_language = m_json.m_content["LanguageSettings"]["language"];
            }
            else return 1;
        }
        if(m_json.m_content.contains("Paths"))
        {
            if(m_json.m_content["Paths"].contains("LeagueClient"))
            {
                m_data.m_lolPath = m_json.m_content["Paths"]["LeagueClient"];
            }
            else return 1;
        }
        else return 1;

        return 0;
    }

    void App::Menu() {
        int iOption;
        MenuOptions option;
        std::string enter;

        SetColor(Color::green);
        std::cout << ">>> League of Legends Language Changer <<<\n";
        SetColor(Color::lightGray);

        while(true) {
            std::cout << "Options:\n0 - Run League Client\n1 - Set language\n2 - Show version\n3 - Exit\n\tYour option: ";
            std::cin >> iOption;
            option = static_cast<MenuOptions>(iOption);
            switch (option) {
                case MenuOptions::runGame:
                    std::system("cls");
                    std::system(m_data.MakeCommand().c_str());
                    std::cout << "Launching LeagueClient.exe...";
                    Sleep(5000);
                    std::exit(0);
                    break;

                case MenuOptions::setLanguage:
                    int languageId;
                    std::system("cls");
                    for(const auto&[key, value] : m_languages)
                    {
                        std::cout << key << " - " << value << " \n";
                    }
                    std::cout << "\tChoose languageId: ";
                    std::cin >> languageId;
                    m_json.m_content["LanguageSettings"]["language"] = m_languages[languageId];
                    m_json.Save();
                    m_json.Load(CONFIG_FILE);
                    LoadData(CONFIG_FILE);
                    std::cout << "Language has set to " << m_languages[languageId] << "\n";
                    std::cout << "Press Enter to continue...";
                    std::cin.ignore(1);
                    std::getline(std::cin, enter);
                    break;

                case MenuOptions::versionInfo:
                    std::system("cls");
                    std::cout << "Version created on " << __DATE__ << "\nPress Enter to continue...";
                    std::cin.ignore(1);
                    std::getline(std::cin, enter);
                    break;

                case MenuOptions::exit:
                    std::system("cls");
                    return;
                    break;

                default:
                    std::system("cls");
                    SetColor(Color::red);
                    std::cerr << "[ERROR] Invalid option!";
                    SetColor(Color::lightGray);
                    std::cout << "Press Enter to continue...";
                    std::cin.ignore(1);
                    std::getline(std::cin, enter);
            }

            std::system("cls");
        }
    }
}