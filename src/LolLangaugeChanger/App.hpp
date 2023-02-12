#ifndef LEAGUELANGUAGECHANGER_APP_HPP
#define LEAGUELANGUAGECHANGER_APP_HPP

#include <Windows.h>
#include <vector>
#include <string>
#include <map>

#include "JsonManager/JsonManager.hpp"
#include "JsonManager/DataStruct.hpp"

namespace llc {

    class App {
    public:
       App();

       void Start();

    private:
        enum class Color {
            black = 0,
            blue = 1,
            green = 2,
            aqua = 3,
            red = 4,
            purple = 5,
            yellow = 6,
            lightGray = 7,
            gray = 8,
            lightBlue = 9,
            lightGreen = 10,
            lightAqua = 11,
            lightRed = 12,
            lightPurple = 13,
            lightYellow = 14,
            white = 15
        };
        HANDLE m_console;
        App::Color RandomColor() const;
        void SetColor(Color color);
        
        enum class MenuOptions
        {
            runGame,
            setLanguage,
            versionInfo,
            exit
        };
        void PrintTitle();
        void Menu();

        JsonManager m_json;
        DataStruct m_data;
        int LoadData(const char *fileName);
        std::map<int, std::string> m_languages {
                {0, "cs_CZ"},
                {1, "de_DE"},
                {2, "en_US"},
                {3, "en_GB"},
                {4, "en_AU"},
                {5, "es_ES"},
                {6, "es_MX"},
                {7, "fr_FR"},
                {8, "t_ITf"},
                {9, "hu_HU"},
                { 10, "pl_PL" },
                { 11, "pt_BR" },
                { 12, "ro_RO" },
                { 13, "tr_TR" },
                { 14, "el_GR" },
                { 15, "ru_RU" },
                { 16, "ja_JP" }
        };
        std::vector<std::string> m_title = {
            R"( ___        ________   ___)",
            R"(|\  \      |\   __  \ |\  \)",
            R"(\ \  \     \ \  \|\  \\ \  \)",
            R"( \ \  \     \ \  \\\  \\ \  \)",
            R"(  \ \  \____ \ \  \\\  \\ \  \____)",
            R"(   \ \_______\\ \_______\\ \_______\)",
            R"(    \|_______| \|_______| \|_______|)",
            "\n",
            R"( ___        ________   ________    ________   ___  ___   ________   ________   _______)",
            R"(|\  \      |\   __  \ |\   ___  \ |\   ____\ |\  \|\  \ |\   __  \ |\   ____\ |\  ___ \)",
            R"(\ \  \     \ \  \|\  \\ \  \\ \  \\ \  \___| \ \  \\\  \\ \  \|\  \\ \  \___| \ \   __/|)",
            R"( \ \  \     \ \   __  \\ \  \\ \  \\ \  \  ___\ \  \\\  \\ \   __  \\ \  \  ___\ \  \_|/__)",
            R"(  \ \  \____ \ \  \ \  \\ \  \\ \  \\ \  \|\  \\ \  \\\  \\ \  \ \  \\ \  \|\  \\ \  \_|\ \)",
            R"(   \ \_______\\ \__\ \__\\ \__\\ \__\\ \_______\\ \_______\\ \__\ \__\\ \_______\\ \_______\)",
            R"(    \|_______| \|__|\|__| \|__| \|__| \|_______| \|_______| \|__|\|__| \|_______| \|_______|)",
            "\n",
            R"(     ________   ___  ___   ________   ________    ________   _______    ________)",
            R"(    |\   ____\ |\  \|\  \ |\   __  \ |\   ___  \ |\   ____\ |\  ___ \  |\   __  \    )",
            R"(    \ \  \___| \ \  \\\  \\ \  \|\  \\ \  \\ \  \\ \  \___| \ \   __/| \ \  \|\  \   )",
            R"(     \ \  \     \ \   __  \\ \   __  \\ \  \\ \  \\ \  \  ___\ \  \_|/__\ \   _  _\  )",
            R"(      \ \  \____ \ \  \ \  \\ \  \ \  \\ \  \\ \  \\ \  \|\  \\ \  \_|\ \\ \  \\  \| )",
            R"(       \ \_______\\ \__\ \__\\ \__\ \__\\ \__\\ \__\\ \_______\\ \_______\\ \__\\ _\ )",
            R"(        \|_______| \|__|\|__| \|__|\|__| \|__| \|__| \|_______| \|_______| \|__|\|__|)",
        };
    };
}

#endif
