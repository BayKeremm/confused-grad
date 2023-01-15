#ifndef NETWORK
#define NETWORK
#include <vector>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstdarg>
#include "layer.hpp"

class Network
{
    public:
        template<typename... Args>
        Network(Args... args);
        std::vector<Layer> & getLayers(){return m_layers;}
    private:
        std::vector<Layer> m_layers;
};

template<typename... Args>
Network::Network(Args... args)
{
    //TODO: read parameters and create layers
}


#endif