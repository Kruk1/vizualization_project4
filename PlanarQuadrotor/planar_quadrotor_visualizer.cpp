#include "planar_quadrotor_visualizer.h"

PlanarQuadrotorVisualizer::PlanarQuadrotorVisualizer(PlanarQuadrotor *quadrotor_ptr): quadrotor_ptr(quadrotor_ptr) {}

/**
 * TODO: Improve visualizetion
 * 1. Transform coordinates from quadrotor frame to image frame so the circle is in the middle of the screen
 * 2. Use more shapes to represent quadrotor (e.x. try replicate http://underactuated.mit.edu/acrobot.html#section3 or do something prettier)
 * 3. Animate proppelers
 */
void PlanarQuadrotorVisualizer::render(std::shared_ptr<SDL_Renderer> &gRenderer) {
    Eigen::VectorXf state = quadrotor_ptr->GetState();
    float q_x, q_y, q_theta;

    /* x, y, theta coordinates */
    q_x = state[0];
    q_y = state[1];
    q_theta = state[2];

    float x_1,y_1,x_2,y_2;
    float l = 36;
    x_1 = q_x - cos(q_theta)*l;
    y_1 = q_y - sin(q_theta)*l;
    x_2 = cos(q_theta)*l + q_x;
    y_2 = q_y + sin(q_theta)*l;

    for(int i = 0; i <5;i++){
        lineColor(gRenderer.get(), x_1,y_1+i,x_2,y_2+i,0xFF414141);
    }

    filledEllipseColor(gRenderer.get(), x_1+18, y_1-10,8, 3, 0xFFFF0000);
    filledEllipseColor(gRenderer.get(), x_1+2, y_1-10,8, 3, 0xFFFF0000);
    filledEllipseColor(gRenderer.get(), x_2-18, y_2-10,8, 3, 0xFFFF0000);
    filledEllipseColor(gRenderer.get(), x_2-2, y_2-10,8, 3, 0xFFFF0000);
    lineColor(gRenderer.get(), x_1+10,y_1,x_1+10,y_1-10,0xFF000000);
    lineColor(gRenderer.get(), x_2-10,y_2,x_2-10,y_2-10,0xFF000000);
}
