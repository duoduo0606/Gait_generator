//
// Created by Yuhang Xing on 10/9/20.
//

#ifndef GAIT_GENERATOR_GAIT_GENERATOR_H
#define GAIT_GENERATOR_GAIT_GENERATOR_H

#include <vector>
#include <cmath>
#include <iostream>

#define L1 70
#define L2 50
#define L3 45

#define B_L 360
#define B_W 80


using namespace std;

class Gait_generator
{
public:
    Gait_generator();
    //-----Structure type declaration-----

    struct xyz_position
    {
        float px;
        float py;
        float pz;
    };

    struct gait_para
    {
        float step_length;
        float step_width;
        float step_depth;
        float yaw_angle;
    };

    struct time_para
    {
        float t1;//end of 1st supporting segment
        float t2;//start of 2nd supporting segment
    };

    //-----variable declaration-----
    float full_cycle_time,t;
    static gait_para gait_para_var;//{step_length,step_width,step_depth,yaw_angle}
    float rf_pos[4],rb_pos[4],lf_pos[4],lb_pos[4];

    //-----Function declaration-----
    void runner();
    xyz_position target_position_generator(float leg_pos[]);
    vector<float> motor_theta_generator(xyz_position target_position,float t);
    vector<float> DH_inversekinematic(xyz_position delta_position);


};

#endif //GAIT_GENERATOR_GAIT_GENERATOR_H
