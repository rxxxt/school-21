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
		typedef std::__wrap_iter<pointer> iterator;
		typedef std::__wrap_iter<const_pointer> const_iterator;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename std::iterator_traits<iterator>::difference_type difference_type;
		typedef typename allocator_type::size_type size_type;

	private:
		allocator_type _allocator;
		pointer _begin;
		pointer _end;
		pointer _end_capacity;

	public:
		explicit vector(const allocator_type& alloc = allocator_type())
				:_allocator(alloc),
				 _begin(nullptr),
				 _end(nullptr),
				 _end_capacity(nullptr) { }

		explicit vector(size_type n, const value_type& value = value_type(),
				const allocator_type& alloc = allocator_type())
				:_allocator(alloc)
		{
			initialization(n);
			for (; n>0; --n, ++_end)
				_allocator.construct(_end, value);
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last,
				const allocator_type& alloc = allocator_type())
				:_allocator(alloc)
		{
			size_type n = last-first;
			initialization(n);
			for (; first!=last; ++first, ++_end)
				_allocator.construct(_end, *first);
		}

		vector(const vector& x)
				:_allocator(x._allocator)
		{
			initialization(x.size());
			for (pointer first; first!=x._end; ++first, ++_end)
				_allocator.construct(_end, *first);
		}

		~vector()
		{
			clear();
			_allocator.deallocate(_begin, capacity());
		}

		vector& operator=(const vector& x) //TODO: Доделать!
		{
			if (*this!=x) {
				clear();
				insert(begin(), x.begin(), x._end());
			}
			return *this;
		}

		iterator begin()
		{
			return _begin;
		}

		const_iterator begin() const
		{
			return _begin;
		}

		iterator end()
		{
			return _end;
		}

		const_iterator end() const
		{
			return _end;
		}

		reverse_iterator rbegin()
		{
			return _end;
		}

		const_reverse_iterator rbegin() const
		{
			return _end;
		}

		reverse_iterator rend()
		{
			return _begin;
		}

		const_reverse_iterator rend() const
		{
			return _begin;
		}

		size_type size() const
		{
			return _end-_begin;
		}

		size_type max_size() const
		{
			return _allocator.max_size();
		}

		void resize(size_type n, value_type value = value_type()) // TODO: переделать
		{
			size_type length = size();
			if (length>n) {
				while (length-->n)
					pop_back();
			}
			else
				insert(_end(), n-length, value);
		}

		size_type capacity() const
		{
			return _end_capacity-_begin;
		}

		bool empty() const
		{
			return size()==0;
		}

		void reserve(size_type n) //TODO: переделать
		{
			if (n>capacity()) {
				pointer first = _begin;
				size_type length = size();
				size_type size_capacity = capacity();
				initialization(n);
				for (size_type i = 0; i<length; ++i)
					*_end++ = first[i];
				_allocator.deallocate(first, size_capacity);
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
			return *(_begin+n);
		}

		const_reference at(size_type n) const
		{
			return at(n);
		}

		reference front()
		{
			return *_begin;
		}

		const_reference front() const
		{
			return *_begin;
		}

		reference back()
		{
			return *(_end-1);
		}

		const_reference back() const
		{
			return back();
		}

		template<class InputIterator>
		void assign(InputIterator first, InputIterator last)
		{
			clear();
			insert(_begin, first, last);
		}

		void assign(size_type n, const value_type& value)
		{
			clear();
			insert(_begin, n, value);
		}

		void push_back(const value_type& value)
		{
			if (_end==_end_capacity)
				reserve(capacity()*2);
			*_end++ = value;
		}

		void pop_back()
		{
			_allocator.destroy(back());
			_end--;
		}

		iterator insert(iterator position, const value_type& value)
		{
			pointer last;

			if (size()<capacity()) {
				last = _end;
				for (; last!=position; --last)
					*last = *(last-1);
				*last = value;
				++_end;
				return position;
			}
			else {
				pointer first = _begin;
				last = _end;
				size_type size_capacity = capacity();
				initialization(capacity()+1);
				size_type i = 0;
				for (; first+i!=position; ++i, ++_end)
					*_end = first[i];
				pointer new_position = _end;
				*_end++ = value;
				for (; first+i!=last; ++i, ++_end)
					*_end = first[i];
				_allocator.deallocate(first, size_capacity);
				return new_position;
			}
		}

		void insert(iterator position, size_type n, const value_type& value)
		{
			pointer last;

			if (size()+n<capacity()) {
				_end += n;
				last = _end-1;
				for (; last!=position+n; --last)
					*last = *(last-n);
				for (; n>0; --n, --last)
					*last = value;
			}
			else {
				pointer first = _begin;
				last = _end;
				size_type size_capacity = capacity();
				initialization(capacity()+n);
				size_type i = 0;
				for (; first+i!=position; ++i, ++_end)
					*_end = first[i];
				for (; n>0; --n, ++_end)
					*_end = value;
				for (; first+i!=last; ++i, ++_end)
					*_end = first[i];
				_allocator.deallocate(first, size_capacity);
			}
		}

		template<class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last)
		{
			pointer it;
			size_type n = last-first;
			if (size()+n<capacity()) {
				_end += n;
				it = _end-1;
				for (; it!=position+n; --it)
					*it = *(it-n);
				it -= n;
				for (; first!=last; ++first, ++it)
					*it = *first;
			}
			else {
				it = _begin;
				pointer ite = _end;
				size_type size_capacity = capacity();
				initialization(capacity()+n);
				size_type i = 0;
				for (; it+i!=position; ++i, ++_end)
					*_end = it[i];
				for (; first!=last; ++first, ++_end)
					*_end = *first;
				for (; it+i!=ite; ++i, ++_end)
					*_end = it[i];
				_allocator.deallocate(it, size_capacity);
			}
		}

		iterator erase(iterator position)
		{
			_allocator.destroy(&(*position));
			for (pointer it = position+1; it!=_end; ++it)
				*(it-1) = *it;
			--_end;
			return position;
		}

		iterator erase(iterator first, iterator last)
		{
			size_type n = last-first;
			pointer it = first;
			for (; it!=last; ++it)
				_allocator.destroy(&(*it));
			for (; it!=_end; ++it)
				*(it-n) = *it;
			_end -= n;
			return first;
		}

		void swap(vector& x)
		{
			std::swap(_allocator, x._allocator);
			std::swap(_begin, x._begin);
			std::swap(_end, x._end);
			std::swap(_end_capacity, x._end_capacity);
		}

		void clear()
		{
			for (size_type length = size(); length>0; --length)
				_allocator.destroy(--_end);
		}

		allocator_type get_allocator() const
		{
			return _allocator;
		}

	private:
		void initialization(size_type n)
		{
			check_range(n);
			_begin = _allocator.allocate(n);
			_end = _begin;
			_end_capacity = _begin+n;
		}

		void check_range(size_type n)
		{
			if (n>max_size())
				throw std::length_error("vector");
		}
	};

	template<class T, class Alloc>
	bool operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
	{
		if (lhs.size()!=rhs.size())
			return false;

		typename vector<T, Alloc>::const_iterator it1 = lhs.begin();
		typename vector<T, Alloc>::const_iterator it2 = lhs.begin();

		for (; it1!=lhs._end; ++it1, ++it2)
			if (*it1!=*it2)
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
		typename vector<T, Alloc>::const_iterator it1 = lhs.begin();
		typename vector<T, Alloc>::const_iterator it2 = lhs.begin();

		for (; it1!=lhs._end; ++it1, ++it2) {
			if (it2==rhs._end || *it2<*it1)
				return false;
			else if (*it1<*it2)
				return true;
		}
		return it2!=rhs._end;
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