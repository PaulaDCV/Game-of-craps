

#include "Problem2.h"
#include "Problem3.h"

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


//Game of Craps simulation
vector<int> game_craps(){
    int score = 0;
    bool game = true;
    int throws = 0;
    int point;
    int win;
    
    //Start game throw dice and add 1 to throws
    score = two_dice();
    cout << "Dice shows:" << score << "\n";
    throws += 1;
    
    //Automatic Loss
    if((score == 2)||(score==3)||(score==12)){
        win = 0;
        game = false;
    }
    
    //Automatic Win
    else if((score==7)||(score==11)){
        win = 1;
        game = false;
    }
    
    //Point
    else{
        
        point = score;
        
        //While game is still going
        while(game){
            
            //Throw dice
            score = two_dice();
            throws += 1;
            
            //Loss
            if(score == 7){
                game = false;
                win = 0;
            }
            //Win
            else if(score == point){
                game = false;
                win = 1;
            }
            
            //Omitted else as game continues and nothing happens
        }
    }
    
    vector<int> results;
    //Results vontains the win or loss value(0 or 1) and the number of throws taken
    results.push_back(win);
    results.push_back(throws);
    return  results;
}
int main(int arcg, char** argv){
    int numberGames = stoi(argv[1]);
    vector<int> game;
    
    //Set random seed to null
    srand(time(NULL));
    
    //File that data will be written to
    std::ofstream outfile("test.dat");
    
    //Run games
    for(int i=0; i <numberGames ; i++ )
    {
        game = game_craps();
        //Write to file
        std::copy(game.begin(), game.end(), std::ostream_iterator<int>(outfile," "));
    }
    //Close file
    outfile.close();

    return 0;
}
