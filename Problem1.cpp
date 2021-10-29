#include <iostream>
using namespace std;
#include <cmath>

//Generate random number between 1 and 0
float random_number()
{   
      float r = (float)rand()/(float)RAND_MAX;
      return r;
}

//Variance
float calculate_variance(float numbers[], float mean, int numberOfPoints)
{
    float variance =0;
    
    //Loop through number list
    for(int i=0; i< numberOfPoints; i++){
        //Square difference number and mean
        variance +=pow((numbers[i]-mean),2);
    }
    //Divide by length of list
    variance /= numberOfPoints;
    return variance;
}


int main(int argc, char** argv ){
    
    //Length of list
    int N = stoi(argv[1]);
    float total = 0;
    
    //Initialize list of length N
    float nums[N];
    float mean;
    float variance;
    
    //For every number
    for( int i = 0; i<N;i++)
    {
        //Generate new random float and assignt to list.
        nums[i] = random_number();
        //Add total sum of number
        total += nums[i];
	}
    
    //Divide sum of numbers/length of list
    mean = total/N;
    variance = calculate_variance(nums, mean,N);
    
    //Print out results of mean and variance.
    cout<< "For length:"<<N<<"\n";
    cout << "The mean is:"<< mean<<"\n";
    cout << "The variance is" << variance<<"\n";
    return 0;
}
