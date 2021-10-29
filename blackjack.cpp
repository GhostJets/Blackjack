#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
  int chips = 1000;
  int card3,ace,bet,winnings,game = 0;
  char play;       
  char betconfirm;
  string move;
  srand((unsigned) time (0));
  while(game == 0){
    int winlose = 0;
    while ((play != 'Y')&&(play != 'y')){
      if (chips <= 0 ){
        cout<<"Sorry, your out of chips.\n";
        return 0;
      }
      else{       
      cout<<"Welcome to Blackjack!\nwould you like to play?\nY or N\n";     //This Block/While loop tells the player if they want to play the game or not.
      cin>>play;
      if ((play == 'Y')||(play == 'y')){
        
      }
      else if ((play == 'N')||(play == 'n')){
        return 0;
      }
      else{
        cout<<"Error input again!\n\n";
      }
      
    }
    }
    while((betconfirm !='Y')&&(betconfirm !='y')){  //This Block/While loop asks the player how much they want to bet and give them a chance to confirm it.
      cout<<"How much would you like to bet? minimum of 2 and maximum of 500\n";
      cin>>bet;
      if ((bet>=2)&&(bet<=500)){ // This if makes sure the bet is between or are 2 and 500
        cout<<"Your bet is "<<bet<<"\n";
        cout<<"Is this correct? Y or N\n"; // This makes the user confirm their bet.
        cin>>betconfirm;
      }
      else {
        cout<<"Error! Please input a number between 2 and 500\n";
      }
    }
      chips = chips - bet;
      cout<<"Your new chip total is "<<chips<<"\n";
      int dhand,phand; // These variables stand for dealers hand and players hand.
      int p_card [3]; //This array is used to represent the players cards.
      int d_card [3]; //This array is used to represent the dealers cards.
      int deck [13]= {11,2,3,4,5,6,7,8,9,10,10,10,10}; //This array is used to represent a deck of cards.
      int card1 = rand () % 12+0; //These 2 RNGs are to give the player their hand.
      int card2 = rand () % 12+0;
      p_card [0] = deck [card1]; // These 2 get the random number and correlates them to the deck array.
      p_card [1] = deck [card2];
      phand = p_card [0] + p_card [1]; // This adds the 2 cards into a hand.
      while(winlose == 0){ //flag variable to cancel out the loop if you get a blackjack first hand.
      if (phand == 21){ // if you get blackjack on the first turn you win.
        cout<<"Your cards are "<<p_card [0]<<" and "<<p_card [1]<<"\n"<<"Your total is "<<phand<<"\n"; 
        cout<<"You Win!\n";
        winnings = bet * 2.5;
        chips = chips + winnings;
        cout<<"Your new chip total is "<<chips<<"\n"; // this displays your new chip total after the game.
        betconfirm = 'm';
        play = 'm';
        cout<<"play again? 0 = Yes 1 = No\n";
        cin>>game;
        break;
      }
      cout<<"Your cards are "<<p_card [0]<<" and "<<p_card [1]<<"\n"<<"Your total is "<<phand<<"\n";
      if (p_card [0] == 11){ // this is for if card 1 is an ace
        int ace; // variable for changing ace from 11 to 1
        cout<<"You have an ace would you like it to be a one or eleven.\n";
        cin>>ace;
        if (ace == 1){
          p_card [0] = 1;
        }
        else if (ace == 11){
          p_card [0] = 11;
        }
        phand = p_card [0] + p_card [1];
        cout<<"Your new total is "<<phand<<"\n";
      }
      else if (p_card [1] == 11){ // this is for if card 2 is an ace
        cout<<"You have an ace would you like it to be a one or eleven.\n";
        cin>>ace;
        if (ace == 1){
          p_card [1] = 1;
        }
        else if (ace == 11){
          p_card [1] = 11;
        }
        phand = p_card [0] + p_card [1];
        cout<<"Your new total is "<<phand<<"\n";
      }
      card1 = rand () % 12+0; //These 2 RNGs are to give the dealer their hand.
      card2 = rand () % 12+0;
      d_card [0] = deck [card1];  // These 2 get the random number and correlates them to the deck array.
      d_card [1] = deck [card2];
      dhand = d_card [0] + d_card [1];  // This adds the 2 cards into a hand.
      cout<<"The Dealer has a "<<d_card [0]<<" and a "<<d_card[1]<<" totaling "<<dhand<<"\n";
      while ((move != "stand")&&(phand < 21)) { // This Block/While Loop lets the player hit and stand, and make them lose if you
        cout<<"Would you like to hit or stand\n";
        cin>>move;
        if (move == "hit"){
            card3 = rand () % 12+0; //  card3 and p_card [2] is for a 3rd card or beyond as it adds itself to the hand then replace itself if needed.
            p_card [2] = deck [card3]; // correlates random number to a card in the deck array.
            cout<<"You drew a "<<p_card [2]<<"\n";
            if (p_card [2] == 11) {
              cout<<"You have an ace would you like it to be a one or eleven.\n"; // if your 3 or beyond card is an ace this lets you decide whether its a 11 or 1
              cin>>ace;
              if (ace == 1){
                p_card [2] = 1;
              }
            else if (ace == 11){
                p_card [2] = 11;
              }
      }
            phand = phand  + p_card [2];
          cout<<"Your new total is "<<phand<<"\n";
      }
      else if ((move!="hit")&&(move!="stand")){ //this detects if you typed something other than hit or stand.
        cout<<"Error! please enter hit or stand.\n";
      }
        }
        if (phand > 21){ // this detects whether you went over 21 or not.
          cout<<"You Lose!\n";
          cout<<"Your new chip total is "<<chips<<"\n";
          betconfirm = 'm';
          play = 'm';
          move = "m";
          cout<<"play again? 0 = Yes 1 = No\n";
          cin>>game;
          winlose = 1;
        }
      while (phand <= 21){
      while (dhand <= 16){ // This Block/While Loop is the Dealers moves if its hand is less than or equal to 16 it hitsand 17 and above it stands.  
        cout<<"Dealer hits\n";
        card3 = rand () % 12+0;
        d_card [2] = deck [card3];
        dhand = dhand + card3;
        cout<<"The Dealer now has "<<dhand<<"\n";
        if (dhand > 21){
          cout<<"Dealer Loses!\n";
          cout<<"You Win!\n";
          winnings = bet * 2;
          chips = chips + winnings;
          cout<<"Your new chip total is "<<chips<<"\n";
          betconfirm = 'm';
          play = 'm';
          move = "m";
          cout<<"play again? 0 = Yes 1 = No\n";
          cin>>game;
          break;
      }
        else {
      }
  }
      cout<<"The Dealer Stands.\n";

      if (phand > dhand){
        cout<<"You Win!\n";
        cout<<"The Dealer had "<<dhand<<"\n";
        winnings = bet * 2;
        chips = chips + winnings;
        cout<<"Your new chip total is "<<chips<<"\n";
        betconfirm = 'm'; // These variables are for the reset 
        play = 'm';
        move = "m";
        cout<<"play again? 0 = Yes 1 = No\n";
        cin>>game;
        winlose = 1;
        break;
      }
      else if (dhand > phand){                            // These if and else if statements are the win conditions you can either win, lose,
        cout<<"You Lose!\n";                              // or tie which is a win for the player.
        cout<<"The Dealer had "<<dhand<<"\n";
        cout<<"Your new chip total is "<<chips<<"\n";
        betconfirm = 'm';
        play = 'm';
        move = "m";
        cout<<"play again? 0 = Yes 1 = No\n";
        cin>>game;
        winlose = 1;
        break;
      }
      else {
        cout<<"You Win because of a tie!\n";
        winnings = bet * 2;
        chips = chips + winnings;
        cout<<"Your new chip total is "<<chips<<"\n";
        betconfirm = 'm';
        play = 'm';
        move = "m";
        cout<<"play again? 0 = Yes 1 = No\n";
        cin>>game;
        winlose = 1;
        break;
      }
      }
}
}
}
