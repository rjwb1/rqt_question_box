#ifndef __CONFIG_H__
#define __CONFIG_H__

#include <ros/ros.h>

namespace config
{
    template<typename T>
    T get(const ros::NodeHandle& nh, const std::string& param)
    {
        T out;
        if(!ros::param::get(param, out))
            throw ros::Exception(param + " is not defined");

        return out;
    }
}

#endif //__CONFIG_H__
