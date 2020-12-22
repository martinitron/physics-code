#include "Meshes/GridPoints.h"

namespace Meshes
{

	GridPoints::GridPoints(int np, dimension d) : d_(d)
	{
		switch (d_)
		{
		case dimension::D1:
			s_ = 1;
			break;
		case dimension::D2:
			s_ = 2;
			break;
		case dimension::D3:
			s_ = 3;
			break;
		}
		
		l_ = static_cast<size_t>(np) * s_;
		p_ = new float[l_]; 
		// Initialise the array
		for (int i = 0; i < l_; i++)
		{
			p_[i] = 0;
		}
	}

	GridPoints::~GridPoints()
	{
		delete p_;
	}



/*
	GridPoints1D::GridPoints1D(int np, dimension d) : GridPoints(np, d)
	{
		
	}

	GridPoints1D::~GridPoints1D()
	{

	}
	GridPoints2D::GridPoints2D(int np, dimension d) : GridPoints(np, d)
	{
		
	}

	GridPoints2D::~GridPoints2D()
	{

	}

	GridPoints3D::GridPoints3D(int np, dimension d) : GridPoints(np, d)
	{
		
	}

	GridPoints3D::~GridPoints3D()
	{

	}
*/
}