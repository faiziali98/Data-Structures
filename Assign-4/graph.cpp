#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>
#include <fstream>
#include "sorts.cpp"

using namespace std;

// Number theory to the rescue
// Generates a permutation of [0 .. n-1]
// Where d>n and both are prime


int timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y);
vector<long> GenerateRandom(long n, long d);
vector<long> GenerateSorted(long n);
vector<long> GenerateReverseSorted(long n);
vector<long> GenerateAlmostSorted(long n, int s);

//=====================================================================================

int main()
{

	struct timeval start, end, diff;

	long s, n=10;
    ofstream out("time.txt");
	vector<long> num;
    cout<<"Processing..."<<endl;
    for (int str=1;str<=4;str++){
        while (n<=100000){
            cout<<str<<" "<<n<<endl;
            out<<str<<" "<<n<<":"<<endl;
            if(str == 1){
                long d=7;
                num = GenerateRandom(n, d);
            }else if(str == 2){
                num = GenerateSorted(n);
            }else if(str == 3){
                num = GenerateReverseSorted(n);
            }else if(str == 4){
                s=100;
                num = GenerateAlmostSorted(n, s);
            }
            if (n==10)n=10000;else if (n==10000)n=100000;else if (n==100000)n=10000000;

            gettimeofday(&start, NULL);
            num = InsertionSort(num);
            gettimeofday(&end, NULL);
            timeval_subtract(&diff, &end, &start);
            out<<"Sorted in "<<diff.tv_sec<<" seconds and "<<diff.tv_usec<<" microseconds."<<endl;
            gettimeofday(&start, NULL);
            num = MergeSort(num);
            gettimeofday(&end, NULL);
            timeval_subtract(&diff, &end, &start);
            out<<"Sorted in "<<diff.tv_sec<<" seconds and "<<diff.tv_usec<<" microseconds."<<endl;
            gettimeofday(&start, NULL);
            num = QuickSortArray(num);
            gettimeofday(&end, NULL);
            timeval_subtract(&diff, &end, &start);
            out<<"Sorted in "<<diff.tv_sec<<" seconds and "<<diff.tv_usec<<" microseconds."<<endl;
            gettimeofday(&start, NULL);
            num = HeapSort(num);
            gettimeofday(&end, NULL);
            timeval_subtract(&diff, &end, &start);
            out<<"Sorted in "<<diff.tv_sec<<" seconds and "<<diff.tv_usec<<" microseconds."<<endl<<endl;

        }
        n=10;
    }
    cout<<"Successfully Done!!!"<<endl;
    return 0;
}

//=====================================================================================
//Vector Generation Functions

vector<long> GenerateRandom(long d, long n)
{
    vector<long> nums;
    long k, residue;
    for (k = 0; k < d; k++)
    {
        residue = (long) (((long long)k * (long long) n) % d);
        nums.push_back(residue);
    }
    return nums;
}

vector<long> GenerateSorted(long n)
{
    vector<long> nums;
    for (long k = 0; k < n; k++)
    {
        nums.push_back(k);
    }
    return nums;
}

vector<long> GenerateReverseSorted(long n)
{
    vector<long> nums;
    for (long k = n; k > 0; k--)
    {
        nums.push_back(k);
    }
    return nums;
}

vector<long> GenerateAlmostSorted(long n, int s)
{
    vector<long> nums;
    srand ( time(NULL) );
    for (long k = n; k > 0; k--)
    {
        nums.push_back(k);
    }
    int k1, k2;
    long tmp;
    for (size_t i = 0; i < s; i++)
    {
        k1 = rand() % n;
        k2 = rand() % n;
        tmp = nums[k2];
        nums[k2] = nums[k1];
        nums[k1] = tmp;
    }
    return nums;
}

//=====================================================================================
//Timer Function

int timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y)
{

        // Perform the carry for the later subtraction by updating y.
        if (x->tv_usec < y->tv_usec)
        {
                int nsec = (y->tv_usec - x->tv_usec) / 1000000 + 1;
                y->tv_usec -= 1000000 * nsec;
                y->tv_sec += nsec;
        }
        if (x->tv_usec - y->tv_usec > 1000000)
        {
                int nsec = (x->tv_usec - y->tv_usec) / 1000000;
                y->tv_usec += 1000000 * nsec;
                y->tv_sec -= nsec;
        }

        // Compute the time remaining to wait.
        // tv_usec is certainly positive.
        result->tv_sec = x->tv_sec - y->tv_sec;
        result->tv_usec = x->tv_usec - y->tv_usec;

        // Return 1 if result is negative.
        return x->tv_sec < y->tv_sec;
}
