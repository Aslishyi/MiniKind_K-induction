//
// Created by 李奕星 on 2024/4/11.
//

#include "LustreNode.h"

#include <utility>

LustreNode::LustreNode() = default;

LustreNode::LustreNode(std::string name, std::vector<std::string> inputs, std::vector<std::string> outputs,
                       std::vector<std::string> vars, std::vector<std::string> bodyLines,
                       std::vector<std::pair<std::string,std::string>> states) {
    this->name = std::move(name);
    this->inputs = std::move(inputs);
    this->outputs = std::move(outputs);
    this->vars = std::move(vars);
    this->bodyLines = std::move(bodyLines);
    this->states = std::move(states);
}

std::string LustreNode::getName() {
    return this->name;
}

std::vector<std::string> LustreNode::getBodyLines() {
    return this->bodyLines;
}

std::vector<std::string> LustreNode::getVars() {
    return this->vars;
}

std::vector<std::string> LustreNode::getOutputs() {
    return this->outputs;
}

std::vector<std::string> LustreNode::getInputs() {
    return this->inputs;
}

std::vector<std::pair<std::string, std::string>> LustreNode::getStates() {
    return this->states;
}

void LustreNode::showNodeMessage() {
    CheckTool::print("NodeName: ", this->getName());
    CheckTool::print("NodeInput: ", this->getInputs());
    CheckTool::print("NodeOutput", this->getOutputs());
    CheckTool::print("NodeVars", this->getVars());
    CheckTool::print("NodeBodys", this->getBodyLines());
    CheckTool::print("NodeStates:");
    for(const auto& item: this->getStates()){
        std::cout<<"From [" + item.first + "] to [" + item.second + "]"<< std::endl;
    }
}

std::string LustreNode::getNodeMessage() {
    std::string nodeMessage;
    nodeMessage += ("NodeName: " + this->getName() + "\n");
    nodeMessage += ("NodeInput: " + StringVectorTool::mergeStringVector(this->getInputs()) + "\n");
    nodeMessage += ("NodeOutput: " + StringVectorTool::mergeStringVector(this->getOutputs()) + "\n");
    nodeMessage += ("NodeVars: "+ StringVectorTool::mergeStringVector(this->getVars()) + "\n");
    nodeMessage += ("NodeBodys: " + StringVectorTool::mergeStringVector(this->getBodyLines()) + "\n");
    nodeMessage += "NodeStates:\n";
    for(const auto& item: this->getStates()){
        nodeMessage += "From [" + item.first + "] to [" + item.second + "]\n";
    }

    return nodeMessage;
}




