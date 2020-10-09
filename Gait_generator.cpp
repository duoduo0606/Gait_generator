//
// Created by Yuhang Xing on 10/9/20.
//

#include "Gait_generator.h"


using namespace std;

Gait_generator::Gait_generator()
{
    Gait_generator::full_cycle_time = 8;
    Gait_generator::t = 0;
    //step_length,step_width,step_depth,yaw_angle
    Gait_generator::gait_para_var = {50,0,0,0};
    rf_pos[0] = B_L/2+2*L2;
    rf_pos[1] = -(B_W/2+L1);
    rf_pos[2] = -L3;
    rf_pos[3] = 1;
    rb_pos[0] = B_L/2;
    rb_pos[1] = -(B_W/2+L1);
    rb_pos[2] = -L3;
    rb_pos[3] = 1;
    lf_pos[0] = B_L/2+2*L2;
    lf_pos[1] = B_W/2+L1;
    lf_pos[2] = -L3;
    lf_pos[3] = 1;
    lb_pos[0] = B_L/2;
    lb_pos[1] = B_W/2+L1;
    lb_pos[2] = -L3;
    lb_pos[3] = 1;

    runner();

//    rf_pos = {B_L/2+2*L2,-(B_W/2+L1),-L3,1};
//    rb_pos = {-B_L/2,-(B_W/2+L1),-L3,1};
//    lf_pos = {B_L/2+2*L2,B_W/2+L1,-L3,1};
//    lb_pos = {-B_L/2,B_W/2+L1,-L3,1};
}
/*
void Gait_generator::runner()
{
    vector<float> rf_theta;
    xyz_position rf_target_position;

    rf_target_position = target_position_generator(rf_pos);
    rf_theta = motor_theta_generator(rf_target_position,t);

}
*/
Gait_generator::xyz_position target_position_generator(float leg_pos[])
{
    float tran_matrix[4][4];
    float p[4];
    int i,j;

    Gait_generator::xyz_position target_position;

    tran_matrix[0][0] = cos(Gait_generator::gait_para_var.yaw_angle);
    tran_matrix[1][0] = sin(Gait_generator::gait_para_var.yaw_angle);
    tran_matrix[2][0] = 0;
    tran_matrix[3][0] = 0;
    tran_matrix[0][1] = -sin(Gait_generator::gait_para_var.yaw_angle);
    tran_matrix[1][1] = cos(Gait_generator::gait_para_var.yaw_angle);
    tran_matrix[2][1] = 0;
    tran_matrix[3][1] = 0;
    tran_matrix[0][2] = 0;
    tran_matrix[1][2] = 0;
    tran_matrix[2][2] = 1;
    tran_matrix[3][2] = 0;
    tran_matrix[0][3] = Gait_generator::gait_para_var.step_length;
    tran_matrix[1][3] = Gait_generator::gait_para_var.step_width;
    tran_matrix[2][3] = Gait_generator::gait_para_var.step_depth;
    tran_matrix[3][3] = 1;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
              p[i] = p[i] + tran_matrix[i][j]*leg_pos[j];
        }
    }

    target_position.px = p[0] - leg_pos[0];
    target_position.py = p[1] - leg_pos[1];
    target_position.pz = p[2] - leg_pos[2];

    return target_position;
}


vector<float> motor_theta_generator(xyz_position target_position,time_para leg_time_para)
{
    xyz_position target_position;

    float sup1_portion,lift_portion,sup2_portion;

    sup1_portion = leg_time_para.t1/Gait_generator::full_cycle_time;
    lift_portion = (leg_time_para.t2 - leg_time_para.t1)/Gait_generator::full_cycle_time;
    sup2_portion = (Gait_generator::full_cycle_time - leg_time_para.t2)/Gait_generator::full_cycle_time;

    if (Gait_generator::t > 0) && (Gait_generator::t < leg_time_para.t1)
    {
        target_position.px
    }

    if (Gait_generator::t > leg_time_para.t1) && (ait_generator::t < leg_time_para.t2)
    {

    }


}
