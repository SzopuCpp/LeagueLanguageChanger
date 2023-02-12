#ifndef LEAGUELANGUAGECHANGER_JSONMANAGER_HPP
#define LEAGUELANGUAGECHANGER_JSONMANAGER_HPP

#include <nlohmann/json.hpp>
#include <string>
#include <fstream>

namespace llc {

    class JsonManager {
    public:
        nlohmann::json m_content;

        JsonManager() noexcept = default;

        JsonManager(const std::string _file);

        void save();

        void load(std::string _file);

    private:
        std::string m_fileName;
    };

} // llc

#endif //LEAGUELANGUAGECHANGER_JSONMANAGER_HPP
