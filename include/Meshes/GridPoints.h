#ifndef MESHES_GRID_POINTS_H
#define MESHES_GRID_POINTS_H

#include <vector>

/*
TODO: maybe look into making this not use vector - lighter weight?
*/
namespace Meshes
{

	enum class dimension{ DNONE, D1, D2, D3 };
/*
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
			float* ptr_ = nullptr;
			size_t sc_ = 0;
		protected:
		public:
			Iterator(float* p_start, size_t scale) : ptr_(p_start), sc_(scale) {}
			~Iterator() {}
			float operator* () const
			{
				return *ptr_;
			}

			Iterator& operator++()
			{
				ptr_ += sc_;
				return *this;
			}

			Iterator& operator--()
			{
				ptr_ -= sc_;
				return *this;
			}

			float* operator->() 
			{
				return ptr_;
			}
		};

		Iterator begin() { return Iterator(&p_[0], s_); }
		Iterator end() { return Iterator(&p_[l_], s_); }
	};

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

	typedef std::vector< std::vector<float> > Grid;
	typedef std::vector<float> GridPoint;

	class GridPoints
	{
	private:
		Grid gp_;
		size_t s_ = 0;
		size_t l_ = 0;
		dimension d_ = dimension::DNONE;

	protected:
	public:
		
		GridPoints(int np, dimension d);
		~GridPoints();

		Grid::iterator begin();
		Grid::iterator end();
	};
} // namespace Meshes

#endif