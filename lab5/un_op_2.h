//
// Created by viro on 2019-12-02.
//

#ifndef LAB5_UN_OP_2_H
#define LAB5_UN_OP_2_H


class un_op_2
{
private:
    double average;

public:
    explicit un_op_2(double average) : average(average)
    {
    }

    double operator()(double value);

};


#endif //LAB5_UN_OP_2_H
