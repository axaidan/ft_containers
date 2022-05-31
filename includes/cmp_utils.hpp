#ifndef CMP_UTILS_HPP
# define CMP_UTILS_HPP

namespace ft {

template	<class InpIt1, class InpIt2>
bool		lexicographical_compare (InpIt1 first1, InpIt1 last1,
		InpIt2 first2, InpIt2 last2)
{
	while (first1!=last1)
	{
		if (first2==last2 || *first2<*first1) return false;
		else if (*first1<*first2) return true;
		++first1; ++first2;
	}
	return (first2!=last2);
}

template	<class InpIt1, class InpIt2, class Compare>
bool 		lexicographical_compare (InpIt1 first1, InpIt1 last1,
		InpIt2 first2, InpIt2 last2,
		Compare comp)
{
	while (first1!=last1)
	{
		//if (first2==last2 || *first2<*first1)
		if (first2==last2 || comp(*first2, *first1))
			return false;
		//else if (*first1<*first2)
		else if (comp(*first1, *first2))
			return true;
		++first1; ++first2;
	}
	return (first2!=last2);
}

template	<class InpIt1, class InpIt2>
bool		equal(InpIt1 first1, InpIt1 last1, InpIt2 first2)
{
	while (first1 != last1)
	{
		if ((*first1 == *first2) == false)
			return false;
		++first1; ++first2;
	}
	return true;
}

/*
template	<class InpIt1>
bool		equal(InpIt1 first1, InpIt1 last1, InpIt1 first2)
{
	while (first1!=last1)
	{
		if (!(*first1 == *first2))
			return false;
		++first1; ++first2;
	}
	return true;
}
*/

}	// namespace ft

#endif // CMP_UTILS_HPP
