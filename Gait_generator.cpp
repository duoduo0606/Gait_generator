//
// Created by Yuhang Xing on 10/9/20.
//

#include "Gait_generator.h"

using namespace std;

Gait_generator::Gait_generator()
{
    full_cycle_time = 8;
    time_step = 1;
    gait_para_var = {20,0,0,0};

    rf_pos[0] = B_L/2;
    rf_pos[1] = -(B_W/2+L1);
    rf_pos[2] = -L3;
    rf_pos[3] = 1;
    rb_pos[0] = -B_L/2;
    rb_pos[1] = -(B_W/2+L1);
    rb_pos[2] = -L3;
    rb_pos[3] = 1;
    lf_pos[0] = B_L/2;
    lf_pos[1] = B_W/2+L1;
    lf_pos[2] = -L3;
    lf_pos[3] = 1;
    lb_pos[0] = -B_L/2;
    lb_pos[1] = B_W/2+L1;
    lb_pos[2] = -L3;
    lb_pos[3] = 1;

    rf_time_para = {0,2};
    rb_time_para = {2,4};
    lf_time_para = {4,6};
    lb_time_para = {6,8};

    //runner();

}

void Gait_generator::runner()
{
    vector<float> rf_theta;
    vector<float> rb_theta;
    vector<float> lf_theta;
    vector<float> lb_theta;

    vector<vector<float>> leg_theta;

    xyz_position rf_target_position;
    xyz_position rb_target_position;
    xyz_position lf_target_position;
    xyz_position lb_target_position;

    int i,k,p,n;

    n = int(full_cycle_time/time_step);

    for (i = 0; i < n; i++)
    {
        t = i*time_step;
        cout << "t=" << t << endl;

        rf_target_position = target_position_generator(rf_pos);
        rf_theta = motor_theta_generator(rf_target_position,rf_time_para);

        rb_target_position = target_position_generator(rb_pos);
        rb_target_position.px = -rb_target_position.px;
        rb_theta = motor_theta_generator(rb_target_position,rb_time_para);

        lf_target_position = target_position_generator(lf_pos);
        lf_target_position.py = -lf_target_position.py;
        lf_theta = motor_theta_generator(lf_target_position,lf_time_para);

        lb_target_position = target_position_generator(lb_pos);
        lb_target_position.px = -lb_target_position.px;
        lb_target_position.py = -lb_target_position.py;
        lb_theta = motor_theta_generator(lb_target_position,lb_time_para);

        leg_theta.push_back(rf_theta);
        leg_theta.push_back(rb_theta);
        leg_theta.push_back(lf_theta);
        leg_theta.push_back(lb_theta);

        for (k = 0; k < 4; k++)
        {
            //cout<< "leg_theta" << k << "\t";
            for (p = 0; p < 3; p++)
            {
                //cout << leg_theta[k][p] << "\t";
            }
            //cout << endl;
        } //end k,p
    } //end i
}//end runner

Gait_generator::xyz_position Gait_generator::target_position_generator(float leg_pos[])
{
    float tran_matrix[4][4];
    float p[4];
    int i,j,k;
    xyz_position target_position;

    for (k = 0; k < 4; k++)
    {
        p[k] = 0;
    }

    tran_matrix[0][0] = cos(gait_para_var.yaw_angle);
    tran_matrix[1][0] = sin(gait_para_var.yaw_angle);
    tran_matrix[2][0] = 0;
    tran_matrix[3][0] = 0;
    tran_matrix[0][1] = -sin(gait_para_var.yaw_angle);
    tran_matrix[1][1] = cos(gait_para_var.yaw_angle);
    tran_matrix[2][1] = 0;
    tran_matrix[3][1] = 0;
    tran_matrix[0][2] = 0;
    tran_matrix[1][2] = 0;
    tran_matrix[2][2] = 1;
    tran_matrix[3][2] = 0;
    tran_matrix[0][3] = gait_para_var.step_length;
    tran_matrix[1][3] = gait_para_var.step_width;
    tran_matrix[2][3] = gait_para_var.step_depth;
    tran_matrix[3][3] = 1;

    for (i = 0; i < 4; i++){
        for (j = 0; j < 4; j++){
              p[i] = p[i] + tran_matrix[i][j]*leg_pos[j];
              //cout << tran_matrix[i][j] << endl;
        }
        //cout << p[0] <<endl;
    }

    target_position.px = p[0] - leg_pos[0];
    target_position.py = p[1] - leg_pos[1];
    target_position.pz = p[2] - leg_pos[2];

    //cout << target_position.px << endl;
    //cout << p[1] << endl;

    return target_position;
}


vector<float> Gait_generator::motor_theta_generator(xyz_position target_position,time_para leg_time_para)
{
    float sup_vel_x,lift_vel_x,sup_vel_y,lift_vel_y;
    float step_hight;
    float del_t;
    vector<float> theta;
    xyz_position time_t_position;

    del_t = leg_time_para.t2-leg_time_para.t1;

    sup_vel_x = target_position.px/(full_cycle_time-del_t);
    lift_vel_x = target_position.px/del_t;
    //cout << lift_vel_x << endl;
    sup_vel_y = target_position.py/(full_cycle_time-del_t);
    lift_vel_y = target_position.py/del_t;

    if ((t >= 0) && (t < leg_time_para.t1))
    {
        time_t_position.px = -sup_vel_x*t;
        time_t_position.py = -sup_vel_y*t;
        time_t_position.pz = 0;
        //cout << "in sup1" << endl;
    }

    if ((t >= leg_time_para.t1) && (t < leg_time_para.t2))
    {
        time_t_position.px = -sup_vel_x*leg_time_para.t1+lift_vel_x*(t-leg_time_para.t1);
        //cout << "here" << time_t_position.px << endl;
        //cout << leg_time_para.t1 << endl;
        time_t_position.py = -sup_vel_y*leg_time_para.t1+lift_vel_y*(t-leg_time_para.t1);
        time_t_position.pz = -4*step_hight/(del_t*del_t)*(t-leg_time_para.t1)*(t-leg_time_para.t2);
        //cout << "in lift" << t << endl;
    }

    if ((t >= leg_time_para.t2) && (t < full_cycle_time))
    {
        time_t_position.px = -sup_vel_x*leg_time_para.t1+target_position.px-sup_vel_x*(t-leg_time_para.t2);
        time_t_position.py = -sup_vel_y*leg_time_para.t1+target_position.py-sup_vel_y*(t-leg_time_para.t2);
        time_t_position.pz = 0;
        //cout << "in sup2" << t << endl;
    }
    //cout << time_t_position.px << endl;
    theta = DH_inversekinematic(time_t_position);

    return theta;
}

vector<float> Gait_generator::DH_inversekinematic(xyz_position time_t_pos)
{
    vector<float> theta;
    float px,py,pz;
    float m,a,b,theta1,theta2,theta3;
    float l0;

    l0 = 1/2*B_L - L2;

    px = time_t_pos.px;
    py = time_t_pos.py;
    pz = time_t_pos.pz;
/*
    theta1 = atan2(-px,py) - atan2(sqrt(px*px+py*py-L3*L3),L3);
    m = px*cos(theta1) + py*sin(theta1);
    theta3 = acos((m*m+pz*pz-L1*L1-L2*L2)/(2*L1*L2));
    theta2 = atan2(pz*(L1+L2*cos(theta3))-L2*sin(theta3),m*(L1+L2*cos(theta3))+pz*L2*sin(theta3));
*/

    theta1 = atan2(L3,sqrt((px-l0)*(px-l0)+py*py-L3*L3))+atan2(py,(px-l0));
    m = ((pow((pz-l0),2)+pow((cos(theta1)*px+sin(theta1)*py-l0*cos(theta1)),2)-L1*L1-L2*L2-L3*L3)/(2*L1));
    theta3 = atan2(L2,L3)+atan2(m,sqrt(L2*L2+L3*L3-m*m));
    a = L2*cos(theta3)-L3*sin(theta3)+L1;
    b = L2*sin(theta3)+L3*cos(theta3);
    theta2 = atan2((pz-l0),sqrt(a*a+b*b-(pz-l0)*(pz-l0)))-atan2(b,a);

    theta.push_back(theta1);
    theta.push_back(theta2);
    theta.push_back(theta3);

    cout << pz << endl;
    //cout << py << endl;
    //cout << theta1 << endl;

    return theta;
}