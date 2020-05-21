#pragma once

#include <GL/glu.h>

class Planet {
public:
    Planet(double diameter = 1.0, double distance = 0.0, double spin_period = 0.0, double rotation_period = 0.0) :
    diameter_(diameter),
    distance_(distance),
    spin_period_(spin_period),
    rotation_period_(rotation_period) {

    }

    void step(double t) {
        if (rotation_period_) {
            rotation_angle_ += 360.0 * t / rotation_period_;
        }
        if (spin_period_) {
            spin_angle_ = spin_angle_ + 360.0 * t / spin_period_;
        }
    }

    void set_color(double r, double g, double b) {
        r_ = r;
        g_ = g;
        b_ = b;
    }

    void draw() {
        glPushMatrix();

        glRotated(rotation_angle_, 0.0, 0.0, 1.0);
        glTranslated(distance_, 0.0, 0.0);
        glRotated(-rotation_angle_ + spin_angle_, 0.0, 0.0, 1.0);

        double half_cube_size = diameter_ / 2.0;

        // bottom
        glColor3d(r_, g_, b_);
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // top
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glEnd();

        // left
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // right
        glBegin(GL_POLYGON);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // front
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, -half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, -half_cube_size, -half_cube_size);
        glEnd();

        // back
        glBegin(GL_POLYGON);
        glVertex3d(-half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, half_cube_size);
        glVertex3d(half_cube_size, half_cube_size, -half_cube_size);
        glVertex3d(-half_cube_size, half_cube_size, -half_cube_size);
        glEnd();

        glPopMatrix();
    }
private:
    double diameter_;
    double distance_;
    double spin_period_;
    double rotation_period_;
    double r_ = 1.0;
    double g_ = 1.0;
    double b_ = 1.0;

    double rotation_angle_ = 0.0;
    double spin_angle_ = 0.0;
};
