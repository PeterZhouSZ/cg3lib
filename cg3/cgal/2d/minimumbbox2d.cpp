/*
 * This file is part of cg3lib: https://github.com/cg3hci/cg3lib
 * This Source Code Form is subject to the terms of the GNU GPL 3.0
 *
 * @author Stefano Nuvoli (stefano.nuvoli@gmail.com)
 */

#include "minimumbbox2d.h"

#include <cg3/meshes/dcel/dcel.h>

#include <CGAL/Polygon_2.h>
#include <CGAL/min_quadrilateral_2.h>
#include <CGAL/ch_graham_andrew.h>
#include <CGAL/Simple_cartesian.h>

namespace cg3 {
namespace cgal {
namespace internal {

typedef CGAL::Simple_cartesian<double>                          CK;
typedef CK::Point_2                                             CK_Point_2;
typedef CGAL::Polygon_2<CK>                                     CK_Polygon_2;

} //namespace cg3::cgal::internal

#ifdef  CG3_DCEL_DEFINED
/**
 * @ingroup cg3cgal
 * @brief getMinRectangle2D
 * @param dcel
 * @return
 */
std::vector<Point2Dd> minRectangle2D(const Dcel* dcel)
{
    std::vector<Point2Dd> points;

    for (const Dcel::Vertex* v : dcel->vertexIterator())
        points.push_back(Point2Dd(v->coordinate().x(),v->coordinate().y()));

    return minRectangle2D(points);
}
#endif

/**
 * @ingroup cg3cgal
 * @brief getMinRectangle2D
 * @param points
 * @param isConvexHull
 * @return
 */
std::vector<Point2Dd> minRectangle2D(
        const std::vector<Point2Dd>& points,
        bool isConvexHull)
{
    std::vector<internal::CK_Point_2> cgalCHPoints;

    if (isConvexHull) {
        for (const Point2Dd p : points) {
            internal::CK_Point_2 point(p.x(), p.y());
            cgalCHPoints.push_back(point);
        }
    }
    else {
        std::vector<internal::CK_Point_2> cgalPoints;

        for (const Point2Dd p : points) {
            internal::CK_Point_2 point(p.x(), p.y());
            cgalPoints.push_back(point);
        }

        //Compute convex hull
        CGAL::ch_graham_andrew(cgalPoints.begin(), cgalPoints.end(), std::back_inserter(cgalCHPoints));
    }

    //Compute the minimal enclosing rectangle p_m
    internal::CK_Polygon_2 p_m;
    CGAL::min_rectangle_2(
        cgalCHPoints.begin(), cgalCHPoints.end(), std::back_inserter(p_m));

    std::vector<Point2Dd> rectanglePoints;
    for (internal::CK_Polygon_2::Vertex_const_iterator it = p_m.vertices_begin(); it != p_m.vertices_end(); it++) {
        const internal::CK_Point_2 p = *it;
        rectanglePoints.push_back(Point2Dd(p.x(), p.y()));
    }

    return rectanglePoints;
}


} //namespace cg3::cgal
} //namespace cg3
