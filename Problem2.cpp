#include "Problem2.h"

// Generate a random number
double rnd()
{
    double r = (double)rand()/(RAND_MAX);
    return r;
}


//Dice simulation
int dice()
{
    double r = rnd();
   
    //If statement to decide number on dice
    if (r<((double)1/6))
    {
        return 1;
    }
    else if(r<((double)2/6))
    {
        return 2;
    }
    else if(r<((double)3/6))
    {
        return 3;
    }
    else if(r<((double)4/6))
    {
        return 4;
    }
    else if(r<((double)5/6))
    {
        return 5;
    }
    else
    {
        return 6;
    }
}

//Simulate two dice
int two_dice()
{
    //Sum of the values of the two dice
    int score = dice() + dice();
    return score;
}

int main(int argc, char** argv){
    //Number of times dice will be thrown
    int trials =stoi(argv[1]);
    int score = 0;
    
    //Vector holds scores of the dice
    vector<int> scores(12,0);
    
    for(int i = 0; i< trials; i++){
        score = two_dice();
        scores[score] += 1;
    }

    for (int i = 2;i<13; i ++){
        cout<< "Score" << i<< ": " << scores[i] << "times \n";        
    }
   
    return 0;
   
}
