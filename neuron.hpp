#ifndef NEURON
#define NEURON
#include <vector>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <iostream>

class Neuron
{
    public:
        Neuron(int input_size, std::function<float(float)> activation);
        float forward(std::vector<float> input);

        friend std::ostream & operator<<(std::ostream & os, Neuron neuron);
        std::vector<float> & getWeights() {return m_weights;}

    private:
       std::vector<float> m_weights; 
       std::function<float(float)> m_activation;
       static inline bool seeded{false};
       float m_bias{1};
};

std::ostream & operator<<(std::ostream & os, Neuron neuron){
    os << "\tNeuron weights" << "\n\t";
    for(auto & w : neuron.getWeights()){
        os << w << " ";
    }
    os << std::endl;
    return os;
}
Neuron::Neuron(int input_size,std::function<float(float)> activation)
: m_activation{activation} 
{
    if(!seeded){
        std::srand (static_cast <unsigned> (std::time(0)));
        seeded = true;
    }
    m_weights.reserve(input_size);
    for(int i{0}; i < input_size ; i++){
        float r = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX));
        m_weights.push_back(r);
    }
}
float Neuron::forward(std::vector<float> input){
    if(input.size() == m_weights.size()){
        std::vector<float> result{input};
        std::transform(m_weights.begin(), m_weights.end(), 
                        input.begin(),result.begin(), std::multiplies<float>());
        return m_activation(std::accumulate(result.begin(), result.end(), 0.0));
    }
    else{
        throw std::logic_error{"dimensions do not match in forward pass"};
    }
}
#endif