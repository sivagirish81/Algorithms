#include "src/survival_of_the_fittest_implementation.cpp"
#include <iostream>
#include <math.h>
#include <limits>

using namespace std;

typedef std::numeric_limits< double > dbl;

//You can test/use your code here.

//returns the duration from start to end times in sec
//double time_elapsed(struct timespec *start, struct timespec *end);

int main()
{
    double range = pow(10, -9);
    survival_of_the_fittest_implementation obj1;
    //clock_gettime(CLOCK_REALTIME, &start_time);
    vector<double> tmp = obj1.solve(100, 10, 10);
    //clock_gettime(CLOCK_REALTIME, &end_time);

    cout << tmp[0] << " " << tmp[1] << " " << tmp[2] << "\n";
    //Sets precision to show specified number of digits. Refer, 
    //https://stackoverflow.com/questions/554063/how-do-i-print-a-double-value-with-full-precision-using-cout
    cout.precision(dbl::max_digits10);
    cout << tmp[0]-range<<" "<<tmp[0]+range<<" "<<"\n";
    //printf("%lf, ", time_elapsed(&start_time, &end_time));
    return 0;
}

/*
double time_elapsed(struct timespec *start, struct timespec *end) {
	double t;
	t = (end->tv_sec - start->tv_sec); // diff in seconds
	t += (end->tv_nsec - start->tv_nsec) * 0.000000001; //diff in nanoseconds
	return t;
}
*/