#include "LolLangaugeChanger/App.hpp"

int main() {
    try {
        llc::App app;
        app.Start();
    }
    catch (nlohmann::json::exception& err) {
        err.what();
    }
}
