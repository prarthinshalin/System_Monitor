#include <string>
#include <vector>
#include "processor.h"

#include "linux_parser.h"

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
    std::vector<std::string> info = LinuxParser::CpuUtilization();

    //Account for guest time
    float user = std::stof(info[0]) - std::stof(info[8]);
    float nice = std::stof(info[1]) - std::stof(info[9]);

    float idle = std::stof(info[3]) + std::stof(info[4]);
    float nonIdle = user + nice + std::stof(info[2]) + std::stof(info[5]) + std::stof(info[6]) + std::stof(info[7]);
    
    return nonIdle / (idle + nonIdle);
}