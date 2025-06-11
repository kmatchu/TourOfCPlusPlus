#include <iostream>
using namespace std;

int main(){
    cout << "Type the letter W\n";
    char answer = 0;
    cin >> answer;
    switch(answer){
    case 'W':
        cout << "Nice job.\n";
        break;
    default:
        cout << "Wrong entry.\n";
        break;
    }
    return 0;
}