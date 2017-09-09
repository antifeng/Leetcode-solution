#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};


bool compareByStart(const Interval &a, const Interval &b)
{
    return a.start < b.start;
}

class Solution
{
public:
    vector<Interval> merge(vector<Interval>& intervals)
    {
        if ( intervals.size() < 2 )
            return intervals;

        std::sort( intervals.begin(), intervals.end(), compareByStart );

        for ( vector<Interval>::iterator it = intervals.begin(), nt = it + 1; nt != intervals.end(); )
        {
            while ( nt != intervals.end() && it != nt && it->end >= nt->start )
            {
                it->end = std::max( it->end, nt->end );
                nt = intervals.erase( nt );
            }

            it = nt;

    			if ( nt != intervals.end() )
    				nt += 1;
        }

        return intervals;
    }
};
int main()
{
	std::vector<int> v = {0,1,2,3};
    for(vector<int>::iterator it = v.begin() ; it != v.end() ; ++it)
        std::cout << *it << " ";

	vector<int>::iterator st = v.end();

	v.erase( v.begin() + 2 );
	vector<int>::iterator vt = v.end();

	vector<Interval> vec;
	vec.push_back(Interval(1,3));
	vec.push_back(Interval(2,6));
	vec.push_back(Interval(8,11));
	vec.push_back(Interval(13,15));

	for(vector<Interval>::iterator it = vec.begin(); it != vec.end() ; ++it)
        std::cout << "( "<< it->start <<", " << it->end  << ") ";
	std::cout << endl;

	Solution s;
	s.merge(vec);

	for(vector<Interval>::iterator it = vec.begin(); it != vec.end() ; ++it)
        std::cout << "( "<< it->start <<", " << it->end  << ") ";
	std::cout << endl;
}
