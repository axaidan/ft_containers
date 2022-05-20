#ifndef CONTAINS_ALLOC_HPP
#define CONTAINS_ALLOC_HPP

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
			char *rhsAlloc = rhs.getAlloc();
			for (int i = 0 ; i < 100 ; i++)
			{
				if (i == 100)
					_alloc[i] = '\0';
				else if (rhsAlloc[i] != '\0')
					_alloc[i] = rhsAlloc[i];
				else 
					_alloc[i] = '\0';
			}
			return (*this);
		}
		~ContainsAlloc(void) {delete [] _alloc;}
		char *getAlloc(void) const
		{
			return (_alloc);
		}	
};
#endif
