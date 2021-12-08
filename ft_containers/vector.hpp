#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <memory>

namespace ft {
	template<class T, class Alloc = std::allocator<T> >
	class vector {

	public:
		typedef T value_type;
		typedef Alloc allocator_type;
		typedef typename allocator_type::reference reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer pointer;
		typedef typename allocator_type::const_pointer const_pointer;
//        typedef __wrap_iter<pointer> iterator;
//        typedef __wrap_iter<const_pointer> const_iterator;
//        typedef std::reverse_iterator<iterator> reverse_iterator;
//        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
//		typedef typename iterator_traits<iterator>::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;

	private:
		allocator_type allocator;
		pointer begin;
		pointer end;
		pointer end_capacity;

	public:
		explicit vector(const allocator_type& alloc = allocator_type())
				:allocator(alloc),
				 begin(nullptr),
				 end(nullptr),
				 end_capacity(nullptr) { }

		explicit vector(size_type n, const value_type& value = value_type(),
				const allocator_type& alloc = allocator_type())
				:allocator(alloc)
		{
			if (n>max_size())
				throw std::length_error("vector");

			begin = allocator.allocate(n);
			end = begin;
			end_capacity = begin+n;

			while (n--) {
				allocator.construct(end++, value);
			}
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type())
				:allocator(alloc)
		{
			size_type n = last-first;

			if (n>max_size())
				throw std::length_error("vector");

			begin = allocator.allocate(n);
			end = begin;
			end_capacity = begin+n;

			while (first!=last) {
				allocator.construct(end++, *first++);
			}
		}

		vector(const vector& x)
				:allocator(x.allocator)
		{
			size_type n = x.end-x.begin;

			begin = allocator.allocate(n);
			end = begin;
			end_capacity = begin+n;

			pointer first = x.begin;
			
			while (first!=x.end) {
				allocator.construct(end++, *first++);
			}
		}

		~vector()
		{

		}

		vector& operator=(const vector& x)
		{

		}

//		iterator begin()
//		{
//
//		}
//
//		const_iterator begin() const
//		{
//
//		}
//
//		iterator end()
//		{
//
//		}
//
//		const_iterator end() const
//		{
//
//		}
//
//		reverse_iterator rbegin()
//		{
//
//		}
//
//		const_reverse_iterator rbegin() const
//		{
//
//		}
//
//		reverse_iterator rend()
//		{
//
//		}
//
//		const_reverse_iterator rend() const
//		{
//
//		}

		size_type size() const
		{
			return end-begin;
		}

		size_type max_size() const
		{
			return allocator.max_size();
		}

		void resize(size_type n, value_type val = value_type())
		{

		}

		size_type capacity() const
		{
			return end_capacity-begin;
		}

		bool empty() const
		{
			return size()==0;
		}

		void reserve(size_type n)
		{

		}

		reference operator[](size_type n)
		{

		}

		const_reference operator[](size_type n) const
		{

		}

		reference at(size_type n)
		{

		}

		const_reference at(size_type n) const
		{

		}

		reference front()
		{

		}

		const_reference front() const
		{

		}

		reference back()
		{

		}

		const_reference back() const
		{

		}

		template<class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{

		}

		void assign(size_type n, const value_type& value)
		{

		}

		void push_back(const value_type& value)
		{

		}

		void pop_back()
		{

		}

//		iterator insert(iterator position, const value_type& val)
//		{
//
//		}
//
//		void insert(iterator position, size_type n, const value_type& val)
//		{
//
//		}
//
//		template<class InputIterator>
//		void insert(iterator position, InputIterator first, InputIterator last)
//		{
//
//		}
//
//		iterator erase(iterator position)
//		{
//
//		}
//
//		iterator erase(iterator first, iterator last)
//		{
//
//		}

		void swap(vector& x)
		{

		}

		void clear()
		{

		}

		allocator_type get_allocator() const
		{
			return allocator;
		}
	};

	template<class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{

	}

	template<class T, class Alloc>
	bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{

	}

	template<class T, class Alloc>
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{

	}

	template<class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{

	}

	template<class T, class Alloc>
	bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{

	}

	template<class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{

	}

	template<class T, class Alloc>
	void swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
	{

	}

}

#endif