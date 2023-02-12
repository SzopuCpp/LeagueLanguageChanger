cmake_minimum_required(VERSION 3.24)
project(LeagueLanguageChanger)

set(CMAKE_CXX_STANDARD 20)

find_package(nlohmann_json CONFIG REQUIRED)
add_executable(LeagueLanguageChanger src/main.cpp src/LolLangaugeChanger/App.cpp src/LolLangaugeChanger/App.hpp src/LolLangaugeChanger/JsonManager/JsonManager.cpp src/LolLangaugeChanger/JsonManager/JsonManager.hpp src/LolLangaugeChanger/JsonManager/DataStruct.cpp src/LolLangaugeChanger/JsonManager/DataStruct.hpp)
target_link_libraries(${PROJECT_NAME} PRIVATE nlohmann_json::nlohmann_json)