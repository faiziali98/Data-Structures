#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <sys/time.h>
#include "sorts.cpp"
#include <sstream>

using namespace std;

int timeval_subtract (struct timeval *result, struct timeval *x, struct timeval *y);
vector<long> GenerateRandom(long n, long d);
vector<long> GenerateSorted(long n);
vector<long> GenerateReverseSorted(long n);
vector<long> GenerateAlmostSorted(long n, int s);

//=====================================================================================

int main()
{
	string str;
	vector<long> num, num2;
	bool correct = true;
    int TEST_SIZE = 10000;
    stringstream strs; strs << TEST_SIZE;

    cout << "STARTING TESTS... TEST CASE SIZE = " << strs.str() << "\n\n";

	for (int j = 0; j < 4; j++) {
		if (j == 0) {
			str = "RANDOM        ";
			num = GenerateRandom(TEST_SIZE, 16789);
		} else if (j == 1) {
			str = "SORTED        ";
			num = GenerateSorted(TEST_SIZE);
		} else if (j == 2) {
			str = "REVERSE_SORTED";
			num = GenerateReverseSorted(TEST_SIZE);
		} else if (j == 3) {
			str = "ALMOST_SORTED ";
			num = GenerateAlmostSorted(TEST_SIZE, 16789);
		}

		num2 = InsertionSort(num);
		for (int i = 0; i < TEST_SIZE-1; i++) {
			if (num2[i] > num2[i+1]) {correct = false; break;}
		}
        if (correct) {cout << "INSERTION_SORT        " << str << "           PASSED\n";}
        else         {cout << "INSERTION_SORT        " << str << "           FAILED---\n";}
        correct = true;

		num2 = MergeSort(num);
		for (int i = 0; i < TEST_SIZE-1; i++) {
			if (num2[i] > num2[i+1]) {correct = false; break;}
		}
        if (correct) {cout << "MERGE_SORT            " << str << "           PASSED\n";}
        else         {cout << "MERGE_SORT            " << str << "           FAILED---\n";}
        correct = true;

		num2 = QuickSortArray(num);
		for (int i = 0; i < TEST_SIZE-1; i++) {
			if (num2[i] > num2[i+1]) {correct = false; break;}
		}
        if (correct) {cout << "QUICKSORT_ARRAY       " << str << "           PASSED\n";}
        else         {cout << "QUICKSORT_ARRAY       " << str << "           FAILED---\n";}
        correct = true;

		/*num2 = QuickSortList(num);
		for (int i = 0; i < TEST_SIZE-1; i++) {
			if (num2[i] > num2[i+1]) {correct = false; break;}
		}
        if (correct) {cout << "QUICKSORT_LIST        " << str << "           PASSED\n";}
        else         {cout << "QUICKSORT_LIST        " << str << "           FAILED---\n";}*/
        correct = true;
		num2 = HeapSort(num);
		for (int i = 0; i < TEST_SIZE-1; i++) {
			if (num2[i] > num2[i+1]) {correct = false; break;}
		}
        if (correct) {cout << "HEAP_SORT             " << str << "           PASSED\n";}
        else         {cout << "HEAP_SORT             " << str << "           FAILED---\n";}
        correct = true;
        cout<<"unsorted vector:"<<endl;
            for(int i=0; i<num.size(); i++)
            {
                cout<<num[i]<<" ";
            }
            cout<<endl<<endl;
		num2 = BucketSort(num, 20000);
		for (int i = 0; i < TEST_SIZE-1; i++) {
			if (num2[i] > num2[i+1]) {correct = false; break;}
		}
        if (correct) {cout << "BUCKET_SORT           " << str << "           PASSED\n";}
        else         {cout << "BUCKET_SORT           " << str << "           FAILED---\n";}
        correct = true;

        cout << "\n";
	}

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
