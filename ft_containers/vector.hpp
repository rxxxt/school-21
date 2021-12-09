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
			initialization(n);
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
			initialization(n);
			while (first!=last) {
				allocator.construct(end++, *first++);
			}
		}

		vector(const vector& x)
				:allocator(x.allocator)
		{
			size_type n = x.end-x.begin;
			initialization(n);
			pointer first = x.begin;
			while (first!=x.end) {
				allocator.construct(end++, *first++);
			}
		}

		~vector()
		{
			clear();
			allocator.deallocate(begin, capacity());
		}

		vector& operator=(const vector& x)
		{
			if (*this!=x) {
				clear();
				//TODO:
			}
			return *this;
		}

//		iterator begin()
//		{
//			return begin;
//		}
//
//		const_iterator begin() const
//		{
//			return begin;
//		}
//
//		iterator end()
//		{
//			return end;
//		}
//
//		const_iterator end() const
//		{
//			return end;
//		}
//
//		reverse_iterator rbegin()
//		{
//			return end;
//		}
//
//		const_reverse_iterator rbegin() const
//		{
//			return end;
//		}
//
//		reverse_iterator rend()
//		{
//			return begin;
//		}
//
//		const_reverse_iterator rend() const
//		{
//			return begin;
//		}

		size_type size() const
		{
			return end-begin;
		}

		size_type max_size() const
		{
			return allocator.max_size();
		}

		void resize(size_type n, value_type value = value_type())
		{
			size_type size = size();
			if (size>n) {
				while (size-->n)
					pop_back();
			}
			else {
				//TODO: insert
			}
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
			if (n>capacity()) {
				pointer first = begin;
				size_type size = size();
				size_type size_capacity = capacity();
				initialization(n);
				for (size_type i = 0; i<size; ++i) {
					
				}
				while (size-->0)
					*end++ = *first++;
				allocator.deallocate();
			}
		}

		reference operator[](size_type n)
		{
			return at(n);
		}

		const_reference operator[](size_type n) const
		{
			return at(n);
		}

		reference at(size_type n)
		{
			if (n>size())
				throw std::out_of_range("vector");

			return *(begin+n);
		}

		const_reference at(size_type n) const
		{
			return at(n);
		}

		reference front()
		{
			return *begin;
		}

		const_reference front() const
		{
			return *begin;
		}

		reference back()
		{
			return *(end-1);
		}

		const_reference back() const
		{
			return back();
		}

		template<class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{

		}

		void assign(size_type n, const value_type& value)
		{
			clear();
			//TODO:
		}

		void push_back(const value_type& value)
		{
			if (end==end_capacity) {
				//TODO:
			}
			allocator.construct(end++, value);
		}

		void pop_back()
		{
			allocator.destroy(back());
			end--;
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
			std::swap(allocator, x.allocator);
			std::swap(begin, x.begin);
			std::swap(end, x.end);
			std::swap(end_capacity, x.end_capacity);
		}

		void clear()
		{
			for (size_type size = size(); size>0; --size) {
				allocator.destroy(--end);
			}
		}

		allocator_type get_allocator() const
		{
			return allocator;
		}

	private:
		void initialization(size_type n)
		{
			begin = allocator.allocate(n);
			end = begin;
			end_capacity = begin+n;
		}
	};

	template<class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		if (lhs.size()!=rhs.size())
			return false;

		typename vector<T, Alloc>::const_iterator first1 = lhs.begin();
		typename vector<T, Alloc>::const_iterator first2 = lhs.begin();

		for (; first1!=lhs.end; ++first1, ++first2)
			if (*first1!=*first2)
				return false;
		return true;
	}

	template<class T, class Alloc>
	bool operator!=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return !(lhs==rhs);
	}

	template<class T, class Alloc>
	bool operator<(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		typename vector<T, Alloc>::const_iterator first1 = lhs.begin();
		typename vector<T, Alloc>::const_iterator first2 = lhs.begin();

		for (; first1!=lhs.end; ++first1, ++first2) {
			if (first2==rhs.end || *first2<*first1)
				return false;
			else if (*first1<*first2)
				return true;
		}
		return first2!=rhs.end;
	}

	template<class T, class Alloc>
	bool operator<=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return !(rhs<lhs);
	}

	template<class T, class Alloc>
	bool operator>(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return rhs<lhs;
	}

	template<class T, class Alloc>
	bool operator>=(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		return !(lhs<rhs);
	}

	template<class T, class Alloc>
	void swap(vector<T, Alloc>& x, vector<T, Alloc>& y)
	{
		x.swap(y);
	}

}

#endif