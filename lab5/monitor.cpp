//
// Created by viro on 2019-11-28.
//

#include "monitor.h"


monitor::monitor(const std::string& name, const std::string& brand, const std::string& resolution, double inches)
        : name(name), brand(brand), resolution(resolution), inches(inches)
{
}

bool monitor::operator==(const monitor& rhs) const
{
    return name == rhs.name;
}

bool monitor::operator!=(const monitor& rhs) const
{
    return !(rhs == *this);
}

std::ostream& operator<<(std::ostream& os, const monitor& monitor)
{
    os << "name: " << monitor.name << " brand: " << monitor.brand << " resolution: " << monitor.resolution
       << " inches: " << monitor.inches;
    return os;
}

double monitor::getInches() const
{
    return inches;
}

