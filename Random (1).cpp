#include <iostream>
#include <time.h>

using namespace std;
int last = 0;

int randm(int max){
time_t seconds;
seconds = time (NULL);
int temp = seconds;
//cout<<"temp is "<<temp <<"\n";
last = ((temp+last) ) % 99;
//cout<<"last is "<<last*max <<"\n";
return last%max;
}

int main() {
  std::cout << "Hello World!\n";

  char integerArr [10] = {'0','1','2','3','4','5','6','7','8','9'};

  char smallAlpha[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
  char capitalAlpha[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

  char specialChars [] ={'*','#','&','$'};

  int length = 0;

  int flag = 1;


  while(flag) {
    cout << "Please select your choice :\n" << "1. Generate Password\n" << "2. Exit \n";
  int input;
  cin>> input;

  switch(input) {
    case 1:
     {
       int flag2 = 1;

  while(flag2) {
  cout << "Enter the length of Password between 12 to 32.\n";

   cin>>length ;

    randm(length);
   if (length > 32 || length < 12){
     cout << "Please Enter correct length\n";
   }
   else {
     flag2 = 0;
   }
}
//randm(length);

//cout << "Your lenght is " << length <<"\n";
// n6#Rb5&Qb1&DA
string password;

int random = 0;

for(int i = 0;i<length;i++){
  //cout << i << "\n";
  // Set First char of password small
  if(i == 0){
    random = (int)randm(26);
    password[0] = smallAlpha[random];
  }
    // Set Last char of password  capital
  else if(i == length-1){
    random = (int)randm(26);
    password[length-1] = capitalAlpha[random];
  }
  else if((i%4) == 1){
    random = (int)randm(10);
    //cout << "Random in integer is " << random << "\n";
    password[i] = integerArr[random];
  }
  else if((i%4) == 2){
    //cout << "Random in special is " << random << "\n";
    random = (int)randm(4);
    password[i] = specialChars[random];
  }
   else if((i%4) == 3){
    random = (int)randm(26);
    //cout << "Random in capital is " << random << "\n";
    password[i] = capitalAlpha[random];
  }
   else if((i%4) == 0){
    random = (int)randm(26);
    //cout << "Random in small is " << random << "\n";
    password[i] = smallAlpha[random];
  }
}
cout << "Password is "<< password << "\n";
  }
  break;
case 2:
  flag = 0;
  break;
default:
  cout << "Please select correct choice. \n";
  }
}
}
