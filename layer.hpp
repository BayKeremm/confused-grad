#ifndef LAYER
#define LAYER
#include <vector>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include "neuron.hpp"
class Layer{
    public:
        Layer(int input_size, int layer_size,
            std::function<float(float)> activation);
        
        std::vector<float> forward(std::vector<float> input);

        friend std::ostream & operator<<(std::ostream & os, Layer layer);
        std::vector<Neuron> & getNeurons()  {return m_neurons;}
        int getLayerSize() const {return m_layer_size;}
        int getInputSize() const {return m_input_size;}
    private:
        std::vector<Neuron> m_neurons;
        int m_layer_size;
        int m_input_size;
};


std::vector<float> Layer::forward(std::vector<float> input){
    std::vector<float> result{};
    result.reserve(m_layer_size);
    if(input.size() == m_input_size){
        for(auto & n: m_neurons){
            auto res = n.forward(input);
            result.push_back(res);
        }
            return result;
    }else{
        throw std::logic_error{"input size of the layer and the actual input size do not match"};
    }
}



std::ostream & operator<<(std::ostream & os, Layer layer)
{
    os << "Layer info:" << "\n";
    os << "\t" << "layer size: " << layer.getLayerSize() << "\n"; 
    os << "\t" << "input size: " << layer.getInputSize() << "\n"; 
    for(const auto & n: layer.getNeurons()){
        os << n;
    }
    return os;
}

Layer::Layer(int input_size, int layer_size,std::function<float(float)> activation)
: m_layer_size{layer_size}, m_input_size{input_size}
{
    m_neurons.reserve(layer_size);
    for(auto i{0}; i < layer_size; i++){
        m_neurons.emplace_back(input_size,activation);
    }
}
#endif