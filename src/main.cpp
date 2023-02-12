#include "LolLangaugeChanger/App.hpp"
// system("\"\"D:\\Riot Games\\League of Legends\\LeagueClient.exe\" \"--locale=en_US\"\"");

int main() {
    try {
        llc::App app;
        app.Start();
    }
    catch (nlohmann::json::exception& err) {
        err.what();
    }
}
