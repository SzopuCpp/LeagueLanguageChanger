#include "JsonManager.hpp"

namespace llc {
    JsonManager::JsonManager(const std::string _file) : m_fileName(std::move(_file)) {
        std::ifstream istream(m_fileName, std::ios_base::in | std::ios_base::app);

        istream >> m_content;
        istream.close();
    }

    void JsonManager::save() {
        std::ofstream ostream(m_fileName, std::ios_base::out | std::ios_base::trunc);

        ostream << std::setw(3) << m_content;
        ostream.close();
    }

    void JsonManager::load(std::string _file) {
        m_fileName = std::move(_file);

        std::ifstream istream(m_fileName, std::ios_base::in | std::ios_base::app);

        m_content.clear();

        istream >> m_content;
        istream.close();
    }
} // llc