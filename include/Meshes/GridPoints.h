#ifndef MESHES_GRID_POINTS_H
#define MESHES_GRID_POINTS_H

namespace Meshes
{

	enum class dimension{ D1, D2, D3 };

	class GridPoints
	{
	private:
	protected:
		float* p_; // array pointer
		dimension d_;
		size_t l_ = 0; // lower case L, length of full array
		size_t s_ = 0; // 1,2,3 dimesion scale
	public:
		GridPoints(int np, dimension d);
		~GridPoints();

		class Iterator
		{
		private:
		protected:
		public:
			Iterator() {}
			~Iterator() {}
		};
	};
/*
	class GridPoints1D : public GridPoints
	{
	private:
	protected:
	public:
		GridPoints1D() = delete;
		GridPoints1D(int np, dimension d);
		~GridPoints1D();

		void setSize();
	};

	class GridPoints2D : public GridPoints
	{
	private:
	protected:
	public:
		GridPoints2D() = delete;
		GridPoints2D(int np, dimension d);
		~GridPoints2D();
	};

	class GridPoints3D : public GridPoints
	{
	private:
	protected:
	public:
		GridPoints3D() = delete;
		GridPoints3D(int np, dimension d);
		~GridPoints3D();
	};
*/
} // namespace Meshes

#endif