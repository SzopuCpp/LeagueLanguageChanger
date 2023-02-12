#include "DataStruct.hpp"
#include <sstream>

namespace llc {
    std::string DataStruct::MakeCommand() const {
        std::ostringstream ss;
        ss << "\""
            << "\"" << m_lolPath << "\""
            << " "
            << "\"" << "--locale=" << m_language << "\""
            << "\"";

        return ss.str();
    }
} // llc