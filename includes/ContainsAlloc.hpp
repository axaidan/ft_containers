#ifndef CONTAINS_ALLOC_HPP
#define CONTAINS_ALLOC_HPP

class	ContainsAlloc
{
	private:
		char *_alloc;
	public:
		ContainsAlloc(void):
			_alloc(new char[100])
		{	}
		ContainsAlloc(ContainsAlloc const & src):
			_alloc(new char[100])
		{
			char *srcAlloc = src.getAlloc();
			int i;
			i = 0;
			while (srcAlloc[i] != '\0')
			{
				_alloc[i] = srcAlloc[i];
				i++;
			}
			_alloc[i] = '\0';
		}
		ContainsAlloc(const char *s):
			_alloc(new char[100])
		{
			int i;
			i = 0;
			while (s[i] != '\0')
			{
				_alloc[i] = s[i];
				i++;
			}
			_alloc[i] = '\0';
		}
		ContainsAlloc &operator=(ContainsAlloc const &rhs)
		{
			char *rhsAlloc = rhs.getAlloc();
			int i;
			i = 0;
			while (rhsAlloc[i] != '\0')
			{
				_alloc[i] = rhsAlloc[i];
				i++;
			}
			_alloc[i] = '\0';
			return (*this);
		}
		~ContainsAlloc(void) {delete [] _alloc;}
		char *getAlloc(void) const
		{
			return (_alloc);
		}	
};
#endif
