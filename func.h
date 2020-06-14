#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <regex>
#include <exception>
#include <string>
#include <vector>
#include <sstream>
using std::vector;
using std::map;
typedef unsigned int uint;
typedef map<std::string, vector<uint>> mapas;
mapas streamas();
bool tikrinimas(mapas& mapai, std::string& w);
bool tikrinimas(mapas& mapai, std::string& w)
{
    mapas::iterator it = mapai.begin();
    while(it != mapai.end())
    {
        if(it->first == w)
            return true;
        it++;
    }
    return false;
}

mapas streamas()
{
    mapas Tekstas;
    std::string eil;
    std::string word;
    std::ifstream fd;
    fd.open("textas.txt");
    if(fd.fail()) throw std::runtime_error("Toks failas neegzistuoja.");
    for(uint i=0; !fd.eof(); i++)
    {
        std::getline(fd,eil,'\n');
        std::regex reg("((http|https):\\/\\/)?(www\\.)?(\\w+\\.(com|org|lt)){1}");
        eil = std::regex_replace(eil,reg," ");
        std::transform(eil.begin(),eil.end(),eil.begin(),::tolower);
        mapas::iterator it = Tekstas.begin();
        while (it != Tekstas.end())
        {
            if (it->first == word)
            {
                it->second.push_back(i + 1);
                break;
            }
		++it;
        }
        std::regex regx("\\W");
        eil = std::regex_replace(eil,regx," ");
        std::stringstream ss(eil);
        while(ss >> word)
        {
            if(!tikrinimas(Tekstas,word))
            {
                vector<uint> init{1};
                Tekstas.insert(mapas::value_type(word,init));
            }
            else
            {
            	mapas::iterator it = Tekstas.begin();
                while (it != Tekstas.end())
                {
                    if (it->first == word)
                    {
                    it->second.push_back(i + 1);
                    break;
                    }
                it++;
                }
            }
        }
        eil.clear();
    }
    return Tekstas;
}
