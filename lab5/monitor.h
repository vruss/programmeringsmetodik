//
// Created by viro on 2019-11-28.
//

#ifndef LAB5_MONITOR_H
#define LAB5_MONITOR_H


#include <string>
#include <ostream>

class monitor
{
private:
    std::string name;
    std::string brand;
    std::string resolution;
    double inches;

public:
    monitor() = default;

    monitor(const std::string& name, const std::string& brand, const std::string& resolution, double inches);

    bool operator==(const monitor& rhs) const;

    bool operator!=(const monitor& rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const monitor& monitor);

    double getInches() const;
};


#endif //LAB5_MONITOR_H
