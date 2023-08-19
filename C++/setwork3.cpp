#include <iostream>
#include <string>
#include <map>
#include <bits/stdc++.h>
               
using namespace std;



string sentence;
int arr[];
 void countLetters(){
     cout<<"Enter a sentence: ";getline(cin,sentence);
    //  string arr[sentence.size()];
    for(int i=0;i<=sentence.size();i++){
        int counter=0;
        char letter;
        letter = sentence[i];
        for(int j=0;sentence[j] != '\0';j++){
            if(letter == sentence[j]){
                counter++;
            }
            arr[j]=counter;
            
        }
        // string recounter = to_string(counter);
        // string word = letter+"="+recounter;
        // arr[i] = word;
        cout<<letter<<"="<<counter<<",";
        // cout<<to_string(counter);
        // cout<< arr[i];
    }
}

 void mapLetters(){
    map<char,int> letterCount;
     cout<<"Enter a sentence: ";getline(cin,sentence);
    for(int i=0;i<=sentence.size();i++){
        
       if (letterCount.find(sentence[i]) == letterCount.end()){
            if(sentence[i] != ' '){
                letterCount.insert(make_pair(sentence[i],1));

            }
        
       }
       else{
        letterCount[sentence[i]]++;
       }
       }
       for(auto& it : letterCount){
        cout<<it.first<<" = "<<it.second<<" , ";
       }
      

    }

int main(){
    // countLetters();
    mapLetters();
    cout<<endl<<endl;

   
}