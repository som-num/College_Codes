// #include <iostream>
// using namespace std;

// int main(){
	
// //	int studentAge, sumOfStudentGrade;
// //	string studentName;
// //	float studentAverage;	
// //	cout << true + true+'\t';


// //int a =15, b=55, c= 100;
// //
// //cout << " BEFORE "<<endl;
// //cout << "A = " <<a<< " B = " <<b<< " c = " <<c<<endl;
// //swap(a,b);
// //swap(c,a);
// //cout << " AFTER "<<endl;
// //cout << "A = " <<a<< " B = " <<b<< " c = " <<c<<endl;

// // int a,b; 

// // int random = rand()%100+1;
// // 	for (int a=0; a<120;a++){
// // 		cout<<char (219); 
// // 		random = rand()%10+1;
// // 		if(a>=60){
// // 			random =0.1;
			
// // 		}
// // 		delay(100*random)
// // 	}

















// //Pyramid
// int a,b;

// cout<< "Enter first \n";
// cin >> a;
// cout<< "Enter second \n";
// cin >> b;
// for (int i=0;i<=a;i++){
// 	for(int k=b-i;k>0;k--)
// 	cout<<" ";
// 	for(int j=0;j<=i;j++){
// 		cout<<"x";
// 	}
// 	cout<<endl;
// }

// /*for(int i=0; i<=10;i++){
// 	for(int j=0;j<=i;j++){
// 		cout <<"x ";
// 	}
// 	cout<<endl;
// }
// */

// /*
// //C++
// int n,i, j;
//     for (i = 0; i < 10; i++) {
//     	if(i==0 || i==9){
//     		cout<<" ";
// 		}
//         cout <<"*";
//         for (j = 0; j < (10 - 1); j++) {
        	
//             if (i == 0 || i == 10 - 1){
//                 cout <<"*";
//             }
//             else if(i==8 && j==8 || i==1 && j==8){
//             	for(n=0;n<10;n++){
//             		cout << " ";
// 				}
//             	cout<<"*";
// 			}
//         }
//         cout <<"\n";
//     }
//     */

// }

// //octal and hexadecimal digits limit
 


#include <iostream>
using namespace std;

extern int otherFunction();
// void otherFunction(){
//     char a = 'B';
//     cout<<"Value of a:"<<a<<endl;
// }

int main(){
    char a ='A';
    otherFunction();
}