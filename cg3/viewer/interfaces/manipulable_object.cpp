/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Alessandro Muntoni (muntoni.alessandro@gmail.com)
 */

#include "manipulable_object.h"

namespace cg3 {

ManipulableObject::ManipulableObject() : ManipulableObject(0.7)
{
}

ManipulableObject::ManipulableObject(double grabbingFactor) :
    axis(false),
    keepsGrabbingMouse(false),
    gf(grabbingFactor)
{
    setSpinningSensitivity(100.0);
}

bool ManipulableObject::drawRelativeAxis() const
{
    return axis;
}

void ManipulableObject::setDrawRelativeAxis(bool b) const
{
    axis = b;
}

const double* ManipulableObject::matrix() const
{
    return ManipulatedFrame::matrix();
}

/**
 * @brief ManipulableObject::position
 * @return the position of the center of the object Frame
 */
Pointd ManipulableObject::position() const
{
    qglviewer::Vec p(ManipulatedFrame::position());
    return Pointd(p.x, p.y, p.z);
}

bool ManipulableObject::grabsMouse() const
{
    return ManipulatedFrame::grabsMouse();
}

void ManipulableObject::setGrabbingFactor(double gf)
{
    this->gf = gf;
}

double ManipulableObject::grabbingFactor() const
{
    return gf;
}

void ManipulableObject::checkIfGrabsMouse(int x, int y, const qglviewer::Camera* const camera)
{
    qglviewer::Vec center(sceneCenter().x(), sceneCenter().y(), sceneCenter().z());
    const qglviewer::Quaternion qt = rotation();
    center = qt.rotate(center);
    const qglviewer::Vec extreme(center.x + sceneRadius(), center.y + sceneRadius(), center.z + sceneRadius());
    const qglviewer::Vec pos(position().x(), position().y(), position().z());
    const qglviewer::Vec proj = camera->projectedCoordinatesOf(pos + center);
    const qglviewer::Vec projex = camera->projectedCoordinatesOf(pos + extreme);
    const int threshold = std::sqrt ( std::pow((proj.x - projex.x), 2) +
                                std::pow((proj.y - projex.y), 2) ) * gf;
    setGrabsMouse(keepsGrabbingMouse || ((fabs(x - proj.x) < threshold) && (fabs(y - proj.y) < threshold)));
}

void ManipulableObject::mousePressEvent(QMouseEvent* const event, qglviewer::Camera* const camera)
{
    ManipulatedFrame::mousePressEvent(event, camera);
    if (grabsMouse())
        keepsGrabbingMouse = true;
}

void ManipulableObject::mouseReleaseEvent(QMouseEvent* const event, qglviewer::Camera* const camera)
{
    ManipulatedFrame::mouseReleaseEvent(event, camera);
    keepsGrabbingMouse = false;
}

} //namespace cg3
