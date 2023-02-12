#ifndef LEAGUELANGUAGECHANGER_DATASTRUCT_HPP
#define LEAGUELANGUAGECHANGER_DATASTRUCT_HPP

#include <string>

namespace llc {

    struct DataStruct {
        std::string m_language;
        std::string m_lolPath;

        std::string MakeCommand() const;
    };

} // llc

#endif //LEAGUELANGUAGECHANGER_DATASTRUCT_HPP
