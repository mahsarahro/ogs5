/*
 * EarClippingTriangulation.h
 *
 *  Created on: Feb 23, 2011
 *      Author: TF
 * \copyright
 * Copyright (c) 2015, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 */

#ifndef EARCLIPPINGTRIANGULATION_H_
#define EARCLIPPINGTRIANGULATION_H_

// STL
#include <list>

// GEOLIB
#include "Polygon.h"
#include "Triangle.h"

// MathLib
#include "AnalyticalGeometry.h"

namespace MathLib
{
class EarClippingTriangulation
{
public:
	EarClippingTriangulation(const GEOLIB::Polygon* ply, std::list<GEOLIB::Triangle>& triangles, bool rot = true);
	virtual ~EarClippingTriangulation();

private:
	/**
	 * copies the points of the polygon to the vector _pnts
	 */
	inline void copyPolygonPoints(const GEOLIB::Polygon* polygon);
	inline void rotate();
	inline void ensureCWOrientation();

	inline bool isEar(size_t v0, size_t v1, size_t v2) const;

	inline void initVertexList();
	inline void initLists();
	inline void clipEars();

	/**
	 * a copy of the polygon points
	 */
	std::vector<GEOLIB::Point*> _pnts;
	std::list<size_t> _vertex_list;
	std::list<size_t> _convex_vertex_list;
	std::list<size_t> _ear_list;

	/**
	 * triangles of the triangulation (maybe in the wrong orientation)
	 */
	std::list<GEOLIB::Triangle> _triangles;

	MathLib::Orientation _original_orient;
};
} // end namespace MathLib

#endif /* EARCLIPPINGTRIANGULATION_H_ */
