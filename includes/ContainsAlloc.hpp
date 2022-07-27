#ifndef CONTAINS_ALLOC_HPP
#define CONTAINS_ALLOC_HPP

# include <cstring>
# include <iostream>

class	ContainsAlloc
{
	private:
		char *_alloc;
	public:
		ContainsAlloc(void):
			_alloc(new char[100])
		{
			for (int i = 0 ; i < 100 ; i++)
				_alloc[i] = '\0';
		}
		ContainsAlloc(ContainsAlloc const & src):
			_alloc(new char[100])
		{
			char *srcAlloc = src.getAlloc();
			for (int i = 0 ; i < 100 ; i++)
			{
				if (i == 100)
					_alloc[i] = '\0';
				else if (srcAlloc[i] != '\0')
					_alloc[i] = srcAlloc[i];
				else 
					_alloc[i] = '\0';
			}
		}
		ContainsAlloc(const char *s):
			_alloc(new char[100])
		{
			for (int i = 0 ; i < 100 ; i++)
			{
				if (i == 100)
					_alloc[i] = '\0';
				else if (s[i] != '\0')
					_alloc[i] = s[i];
				else 
					_alloc[i] = '\0';
			}
		}
		ContainsAlloc &operator=(ContainsAlloc const &rhs)
		{
			if (&rhs == this)
				return (*this);

			char *	_tmp = new char[100];

			char *rhsAlloc = rhs.getAlloc();
			for (int i = 0 ; i < 100 ; i++)
			{
				if (i == 100 - 1)
					_tmp[i] = '\0';
				else if (rhsAlloc[i] != '\0')
					_tmp[i] = rhsAlloc[i];
				else 
					_tmp[i] = '\0';
			}
			delete [] _alloc;
			_alloc = _tmp;
			return (*this);
		}
		~ContainsAlloc(void) {delete [] _alloc;}
		char *getAlloc(void) const
		{
			return (_alloc);
		}	
		bool operator==(ContainsAlloc const &rhs) const
		{
			return (strcmp(_alloc, rhs.getAlloc()) == 0);
		}
		bool operator!=(ContainsAlloc const &rhs) const
		{
			return (strcmp(_alloc, rhs.getAlloc()) != 0);
		}
		bool operator<(ContainsAlloc const &rhs) const
		{
			return (strcmp(_alloc, rhs.getAlloc()) < 0);
		}
		bool operator>(ContainsAlloc const &rhs) const
		{
			return (strcmp(_alloc, rhs.getAlloc()) > 0);
		}
		bool operator<=(ContainsAlloc const &rhs) const
		{
			return (strcmp(_alloc, rhs.getAlloc()) <= 0);
		}
		bool operator>=(ContainsAlloc const &rhs) const
		{
			return (strcmp(_alloc, rhs.getAlloc()) >= 0);
		}

};

std::ostream &	operator<<(std::ostream & o, ContainsAlloc const & rhs);
//	FUNCTION OVERLOAD TO '<<' OPERATOR



#endif
