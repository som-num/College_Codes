// // 


// #include <iostream>

// using namespace std;

// void enqueue(string *tracks, int &track_n, char &input, int *number_list){
//     int parcial_num = 0;
//     int duplicate = track_n;
//     string songs[]= {"Kill Bill (by SZA)", "Flowers (by Miley Cyrus)", "BESO (by ROSALIA)", "Players (by Coi Leray)",
//     "Calm Down (by Rema)", "Intentions(by Justin Bieber)", "Uham (by Dilaw)", "Cupid (by FIFTY FIFTY)", "Pasilyo (by Sunkissed Lola)",
//     "Elevate (by Jeff Grecia)", "Mahika (By Adie)", "Anti-Hero (by Taylor Swift)"};

//     if (track_n == 10){
//         cout << "Your Playlist reached the maximum number of tracks" <<endl;
//         input = ' ';
//     }
//     else{
//         cout << "Available Songs: " <<endl;
//         for (int i= 0; i<sizeof(songs)/sizeof(songs[0]); i++){
//             if(i == 3){
//                 cout <<i+1<< ") " <<songs[i] << endl;
//             } else{
//                 cout <<i+1<< ") "<< songs[i] << "\t";
//             }
//         }
//         char a;
//         cout << endl <<endl;
//         cout <<"Add songs to the your Top 10 List" <<endl;
//         cout << "Number of song/s to be added:\t"; cin >> parcial_num;
//         cout << endl;
//         while((parcial_num + track_n) > 10){
//             cout << "Exceded the maximum number of tracks(Input Lower)" <<endl;
//             cout << "Number of song/s to be added:\t"; cin >> parcial_num;
//         }
//         track_n += parcial_num;
//         cout << "(Type the number of the song you want to add)" <<endl;

//         for(int i =duplicate; i<track_n; i++){
//             int track_number;
//             string song;
//             bool repeated = false; // initialize a flag to check for repeated songs
//             do {
//                 cout << "Top " << i+1 << ": "; cin >> track_number;
//                 repeated = false;
//                 // check if the selected song has already been added
//                 for(int j = 0; j < i; j++) {
//                     if(number_list[j] == track_number) {
//                         cout << "This song has already been added. Please select another one." << endl;
//                         repeated = true;
//                         break;
//                     }
//                 }
//             } while(repeated);
//             song = songs[track_number-1];
//             cout << "Adding " << song << " to  your playlist..."<<endl;
//             tracks[i] = song;
//             number_list[i] = track_number;

//         }
//     }
// }

// void updatingPlaylist(string *tracks, int &track_n){
// 	cout << endl;
// 	cout << "My Top Songs:  (in queue)" <<endl;
// 	for(int i = 0; i<track_n;i++){
// 		cout << "\t" << i+1 << ") " << tracks[i] <<endl;
// 	} 
//     if(track_n != 10){
// 	    cout << "\t" << track_n + 1 << "-" << 10 << ") Empty track/s" << endl;
//     }
// }
// void no_name_function(){
	
// 	cout << endl;
// 	cout << "Created Song List\t0" <<endl;
// 	cout << "Added Tracks\t\t0" <<endl<<endl;
// 	cout << "Restart Program. ";
	
// }
// void dequeue(string *tracks, int &track_n, int *number_list){
// 	cout << "Removed song: " << tracks[0] <<endl;
// 	for(int i =0; i<track_n; i++){
//         tracks[i] = tracks[i+1];
// 		number_list[i] = number_list[i+1];
//     }
//     track_n = track_n - 1;
// }
// void peek(string *tracks){
//     cout << "My Top Song: " << tracks[0] <<endl;
// } 
// char otherOptions(){
// 	char input;
// 	cout << "(l-f-e-q-s-p-b)" <<endl;
// 	cout << "Choose from options: "; cin >> input;
// 	while(input != 'l' && input != 'f' && input != 'e' && input != 'q' &&
// 	input != 's' && input != 'p' && input != 'f' && input != 'b'){
// 		cout << "You entered a wrong character" <<endl;
// 		cout << "(l-f-e-q-s-p-c)" <<endl;
// 		cout << "Choose from options: "; cin >> input;
// 	}

// 	return input;
// }

// void queueLength(int length){
// 	cout << "Current Queue Length: " << length <<endl;
// }
// bool isFull(int current_length, int hasvalue_length){
// 	if(current_length == hasvalue_length){
// 		return true;
// 	}
// 	return false;
// }
// bool isEmpty(int value_length){
// 	if (value_length == 0){
// 		return true;
// 	}
// 	return false;
// }
// void showQueue(string *tracks, int current_length){
// 	for(int i = 0; i<current_length; i++){
// 		string duplicate;
// 		if(tracks[i] == ""){
// 		duplicate = "Empty Track";					
// 		} else{
// 			duplicate = tracks[i];
// 		}
// 		cout << i + 1 <<") " << duplicate << ", ";
// 	}
// }
// void sumValues(int current_length, int *number_list){
// 	int sum = 0;
// 	for(int i =0; i<current_length; i++){
// 		if(number_list[i] != 0){
// 			sum += number_list[i];
// 		}
// 	}
// 	cout << "Sum: " << sum <<endl;
// }
// void productValues(int current_length, int *number_list){
// 	int product = 1;
// 	for(int i =0; i<current_length; i++){
// 		if(number_list[i] != 0){
// 			product *= number_list[i];
// 		}
// 	}
// 	cout <<endl;
// 	cout << "Product: " << product<<endl<<endl;
// }
// bool containsValue(int current_value, int *number_list, int &trackNum){
// 	int trackNumber;
// 	cout << "Enter Track Number: "; cin >> trackNumber;
// 	for(int i =0; i<current_value; i++){
// 		if(number_list[i] == trackNumber){
// 			trackNum = i;
// 			return true;
// 		}
// 	}
// 	return false;
// }
// int main() {
// 	int MAX_SIZE = 10, track_n = 0;
	
// 	char y_n = 'y';
// 	string tracks[MAX_SIZE];
// 	int trackNumberList[MAX_SIZE];
	
// 	cout << "************ MY TOP 10 SONGS GLOBAL **************" <<endl <<endl;
	
// 	cout << "Create List (type y to continue) "; cin >> y_n;

// 	switch(y_n){
// 		case 'y':
// 			{
// 			char input = 'p';
//             cout << endl;
// 			enqueue(tracks, track_n, input, trackNumberList);
// 			updatingPlaylist(tracks, track_n);
// 			cout <<endl;
// 			cout << "Add more songs(a)" <<endl;
// 			cout << "My Top Song(g)" << endl;
// 			cout << "Remove Top Song(r)" << endl;
// 			cout << "Show more options(s)" <<endl;
			
		
// 			do{
//                 cout <<endl;
//                 cout << "(a-g-r-s)"<<endl;
// 				cout << "Choose option: ";cin >> input;
//                 cout <<endl;
// 			switch(input){
// 				case 'a':
//                     {
// 					enqueue(tracks, track_n, input, trackNumberList);
//                     updatingPlaylist(tracks, track_n);
//                     }
// 					break;
// 				case 'g':
// 					peek(tracks);
// 					break;
// 				case 'r':
// 					{
// 					dequeue(tracks, track_n, trackNumberList);
//                     updatingPlaylist(tracks, track_n);
// 					}
// 					break;
// 				case 's':
// 					{
// 						char returnedChar = 'b';
// 						cout << "Current queue length(l)" <<endl;
// 						cout << "Is queue full?(f)" <<endl;
// 						cout << "Is queue is empty?(e)" <<endl;
// 						cout << "Show Queue(q)"<<endl;
// 						cout <<	"Sum of All Values(s)" <<endl;
// 						cout << "Product of All Values(p)" <<endl;
// 						cout << "Find Song(f)" <<endl; 
// 						cout << "<Back(b)" <<endl<<endl;
// 						cout << endl;
// 					do{
// 						returnedChar = otherOptions();
// 					switch(returnedChar){
// 						case 'l':
// 							queueLength(MAX_SIZE);
// 							break;
// 						case 'f':
// 							{
// 							bool isTrue = isFull(MAX_SIZE, track_n);
// 							if(isTrue){
// 								cout << "Queue is Full" <<endl;
// 							} else{
// 								cout << "Queue is not Full" <<endl;
// 							}
// 							}
// 							break;
// 						case 'e':
// 							{
// 							bool isTrue = isEmpty(track_n);
// 							if(isTrue){
// 								cout << "Queue is Empty" <<endl;
// 							} else{
// 								cout << "Queue is not Empty" <<endl;
// 							}
// 							}
// 							break;
// 						case 'q':
// 							showQueue(tracks, MAX_SIZE);
// 							break;
// 						case 's':
// 							sumValues(MAX_SIZE, trackNumberList);
// 							break;
// 						case 'p':
// 							productValues(MAX_SIZE, trackNumberList);
// 							break;
// 						case 'c':
// 							{
// 							int trackNumber;
// 							bool isTrue = containsValue(MAX_SIZE, trackNumberList, trackNumber);
// 							if(isTrue){
// 								cout << "Song is found at Track Number " <<trackNumber <<endl;
// 							} else{
// 								cout << "Song not found" <<endl;
// 							}
// 							}
// 							break;				
// 					}
// 				} while(returnedChar != 'b');
// 					}	
// 					break;
// 				default:
// 					cout << "You entered a wrong character " << endl;
// 					break;					
// 			}
			
// 			} while(input != 'p');
			
// 		}
// 		break;
// 		default:
// 		no_name_function();
// 		break;
// }

// }


#include<iostream>

using namespace std;

int main(){
	int x = 10;
	int *y = &x;

	cout<< *y ;
}