#include<iostream>
#include"neuron.hpp"
#include"layer.hpp"
#include"network.hpp"
float sigmoid(float sum){
    return sum / (1 + std::abs(sum)); //apx
}
float dummy(float sum){
    return sum;
}
using namespace std;
int main(){
    //Layer layer{2,3,dummy};    
    //cout << layer;
    //vector<float> input {1,1};
    //auto res = layer.forward(input);
    //for(const auto & r: res){
        //cout << r << " ";
    //}
    //cout << endl;

    Network network{1,2,3};
    
    return 0;
}