#include "func.h"

int main()
{
        mapas Tekstas = streamas();
        mapas::iterator it = Tekstas.begin();
        if(it->first.size() == 0)
        throw std::runtime_error("Failas tuscias");
        bool tus = true;
        for(const auto& x : Tekstas)
        {
            tus = false;
            std::cout<<x.first;
            for(int i=0; i<20-x.first.size(); i++)
            {
                std::cout<<" ";
            }
            std::cout<<"  pasikartoja "<<x.second.size() << "kartus eilutese";
            for(const auto&a : x.second)
            {
                std::cout<<a<<" ";
            }
            std::cout<<std::endl;
        }
    if(tus)
        {
        std::cout<<"Zodziu nera"<<std::endl;
    }
    std::cout<<"URL'ai:"<<std::endl;
    vector<std::string> URL;
    std::ifstream fd("textas.txt");
    std::string eilutes;
    for(uint i=0; !fd.eof(); i++)
    {
        std::getline(fd,eilutes,'\n');
        try
        {
            std::regex reg("((http|https):\\/\\/)?(www\\.)?(\\w+\\.(com|org|lt)){1}");
            std::sregex_iterator next(eilutes.begin(), eilutes.end(), reg);
            std::sregex_iterator end;
            while (next != end)
                {
                    std::smatch match = *next;
                    if (match.str() != "")
                    URL.push_back(match.str());
                    next++;
                }
        }
	catch (std::regex_error & e)
	{
		std::cout << e.what() << std::endl;
	}
    }
    if(URL.empty())
    {
        std::cout<<"URL nera"<<std::endl;
    }
    else
    {
        for(const auto& url : URL)
        {
            std::cout<<url<<std::endl;
        }
    }
}
