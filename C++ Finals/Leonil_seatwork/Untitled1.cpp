#include <iostream>
//#include <windows.h>
#include <string>
using namespace std;


void search(string text, string toSearch){
	int textLength = text.length(), toSearchLength = toSearch.length(), count=0;
	bool itMatched;
	
	cout<< "\033[1;32m Number of all Characters: " <<textLength<<endl;
	
	for(int i = 0; i<textLength;i++){	 //for comparing each characters index
		cout<<"\t"<<i+1<<"\t"<<text[i]<<endl;
	}
	cout<<"\033[1;0m"<<endl;
	
	for(int i = 0; i<textLength; i++){ //outer loop if where mag start
		itMatched = true;
		if(toSearch[0] == text[i]){
			for(int j = 1; j<toSearchLength; j++){ //inner loop for comparing character
				if(toSearch[j] != text[i+j]){
					itMatched = false;
					break;
				}
			}
			if(itMatched){
				count++;
				if(count == 1)
					cout << "\033[1;32m Result: " <<endl;
				cout << "\t\t\t[" << count << "] " << "starts at "<< i+1<<", ends in " << i + toSearchLength<<endl;
			}
			
		}
	}
	if(count == 0){
		cout<< "\033[1;31m Phrase didn't matched \033[1;0m"<<endl;
		} else{
			cout<< "\033[1;35m \t\t\t====== END OF RESULT======\033[1;0m \n"<<endl;
			}
}
void userText(string &text, string &toSearch, char s_n){
	//ang escape sequence are for colors dont kalibog
	
	if(s_n == 'n'){
		cout<< endl;
		cout << "Input Text: \033[1;34m";
		getline(cin, text);
		cout <<"\033[1;0m";
	}	
	cout << endl;
	cout << "Your Text: \033[1;34m"<< text<<"\033[1;0m"<<endl;
	cout << "Search For: \033[1;34m";
	for(int i = 0; i<toSearch.length(); i++){
		toSearch[i] = tolower(toSearch[i]);
	}
	for(int i =0; i<text.length(); i++){
		text[i] = tolower(text[i]);
	}
	getline(cin, toSearch);
	cout << "\033[1;0m Finding Match..." <<endl;
	//Sleep(1000);
	cout << endl;
}
int main() {
	system("Color 0A");//kolor kolor sa program
	
	char y_n, s_n = 'n';
	string text;
	string toSearch;
	cout << "\033[1;35m \t\t\t======STRING MATCHING====== \033[1;0m" <<endl;
	
	bool exit = false;
	
	while(!exit){ //for the program to check if true = proceed
		userText(text, toSearch, s_n);
		search(text, toSearch);
		bool wrongKeyword;
		do{
		cout << "Search Again? [y/n] ";
		cin>> y_n;
		cin.ignore(5, '\n');
		
		switch(y_n){
			case 'y':
			wrongKeyword = false;
			bool anotherWrongKW;
			do{
				cout << "Use Same Text[s] | Input New Text[n] "; cin>> s_n;
				cin.ignore(5, '\n');
				switch(s_n){
					case 's':
					anotherWrongKW = false;
					break;
					case 'n':
					anotherWrongKW = false;
					break;
					default:
					cout<<"\033[1;31m Oops Invalid Input!\033[1;0m"<<endl;
					anotherWrongKW = true;
					break;
					}
				}while(anotherWrongKW); 
			break;
			case 'n':
			exit = true;
			wrongKeyword = false;
			cout<< "Program Exited. "<< endl;
			break;
			default:
			wrongKeyword = true;
			cout<< "\033[1;31m You entered a wrong keyword \033[1;0m"<<endl;
			break;
			}
		
		} while(wrongKeyword);
		
		
		}
	
	return 0;
}
