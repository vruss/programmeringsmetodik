//
// Created by Viktor Rosvall (viro1702) on 2019-12-04.
// Student at Mid Sweden University.
//
// Course name: DT047G Programming Methodology
// File name: utility.h
//

#ifndef PROJECT_UTILITY_H
#define PROJECT_UTILITY_H

/**
 * @brief   Class with basic utility functions
 *
 * This class contains basic utility and math functions such as
 * degree to radian conversions.
 */
class utility
{
private:

public:

    /**
     * @brief   Converts degrees to radians
     *
     * @param degrees   input degrees
     * @return          output radians
     */
    static float degToRad(float degrees);

    /**
     * @brief   Converts radians to degrees
     *
     * @param radians   input radians
     * @return          output degrees
     */
    static float radToDeg(float radians);

};


#endif //PROJECT_UTILITY_H
