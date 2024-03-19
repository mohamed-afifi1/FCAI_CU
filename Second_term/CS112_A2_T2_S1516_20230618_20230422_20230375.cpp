/*
Name: Menna Mohammed Hekal.
ID: 20230422
Section: S15, 16
Cipher_name: Atbash Cipher
########################################
Name: Mohamed Ayman Afifi
ID: 20230618
Section: S15, 16
Cipher_name: Xor Cipher
########################################
Name: Mahmoud Fathy Mohamed
ID:20230375
Section: S15, 16
Cipher_name: Substitution Cipher
*/

#include<iostream>
#include<string>
#include<iomanip>
#include <vector>
using namespace std;

//Atbash Cipher
/*This Program has 2 versions:
version1 that make all letters reversed as A is Z and B is Y, etc..
version2 that make each half is refereed alone as A be M and M is A, etc..
*/

//version 1:
void cipherVersion1(string message) {
    string newLetter  ; //To store char after reverse.
    for (int i = 0; i < message.size(); i++) {
        if (isalpha(message[i])) { // to check that char is English letter.
            message[i] = toupper(message[i]); // to make all char in capital case.
            newLetter += 'Z' - (message[i] - 'A'); // Reverse the letter.
        }
         // ignore the char if it isn't in English letter
        }
    cout << "Cipher: " << newLetter << endl; // print the word after ciphering it.
}

// version 2:
void version2 (string message){
    string newLetter;
    for (int i = 0; i < message.size(); i++) {
        if (isalpha(message[i])) {
            message[i] = toupper(message[i]);
            if ( 'A' <= message[i]&& message[i] <= 'M'){
                newLetter += 'M' - (message[i] - 'A'); // Reverse the letter.
                }
            else if ('N' <= message[i] && message[i] <= 'Z'){
                 newLetter += 'Z' - (message[i] - 'N');
            }
           }
         // ignore the char if it isn't in English letter
            }
       cout << "Cipher: " << newLetter << endl; // print the word after ciphering it.
}

void atpashCipher()
{
    while (true) {
        int choice; //declare the variable.
        cout << "Enter your choice:\n1- Version1\n2- Version 2\n3- End\n";
        cin >> choice; // take the variable from user.
        if (choice == 1 || choice == 2) {
            string message;
            cout << "Enter the message: ";
            cin.ignore(); // Clear newline character from previous input
            getline(cin, message);
            if (choice == 1) {
                cout << "Plain:  " << message << endl;
                cipherVersion1(message); //call the function of version 1
            } else if (choice == 2) {
                cout << "Plain:  " << message << endl;
                version2(message); //call the function of version 2
            }}
        else if (choice == 3)
            return; // End the programe
        else {
            cout << "Invalid choice\n";
        }
    }
}

//########################################################################


//XOR Cipher

void cypher( string str, string secret)
{
    /*
    take string and secret key and xor every letter from string with every letter from secret key.
    then print the result.
    */
    vector<int> result;
    for(int i = 0; i < int(str.size()); i++)
    {
        result.push_back(str[i] ^ secret[i % secret.size()]);
    }
     cout << "cypher text :";
    for(int  i = 0; i < int(result.size()); i++)
    {
        if(isprint(result[i]))
        cout << char(result[i]);
    }
    cout << endl <<"hex :";
    for(int  i = 0; i < int(result.size()); i++)
    {
        cout <<setw(2) << setfill('0') << hex << result[i] << ' ';
    }
    cout << endl;
    
}

void decypher (string hexString, string secret)
{
     /*
    take string and secret key and tern string of hexdecimal numbers into arry of decimal numbers
    and xor every number from array with every letter from secret key.
    then print the result.
    */
     istringstream iss(hexString);
    vector<int> intArray;
    int byte;
    while (iss >> hex >> byte) 
        intArray.push_back(byte);
    for(int i = 0; i < intArray.size(); i++)
    {
        cout << char(intArray[i] ^ secret[i%secret.size()]);
    }
    cout << endl;
}


void Xor()
{
    string str , secret;
    string exit, choice;
    while(exit != "yes")
    {
        cout << "what you want to do: \n 1: cypher text\n 2:dicypher text\n (any thing else will exit)\n";
        cin >> choice;
        if(choice == "1")
        {
           cout <<"enter text you want to cypher\n";
           cin.ignore();
           getline(cin, str);
           cout <<"enter secret key\n"; 
            cin >> secret;
            
            cypher(str, secret);
        }
        else if (choice == "2")
        {
            cout <<"enter text you want to decypher\n";
            cin.ignore();
            getline(cin, str);
            cout <<"enter secret key\n"; 
            cin >> secret;
            decypher(str, secret);
        }
        else
        {
            exit = "yes";
        }

    }
}

//########################################################################

//Substitution Cipher

const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";


//get a string with the cipher alphabet
string get_cipher_string(string key){
    //initialize the alphabet with the key
    string sub = key;

    //loop through the alphabet and add any letter that isn't added already;
    for(char i : ALPHABET){
        if(sub.find(i) >= sub.length()){
            sub += i;
        }
    }

    return sub;
}


//get the alphabet to decipher the string
string get_decipher_string(string key){
    
    
    char deciph_sub[26];

    //for every letter in the key, set the element in the deciph at the index of the letter (such that 'a' is 0) to the letter in index in the original alphabet
    //example
    //key:      zebracdfghijklmnopqstuvwxy
    //decipher: ecfgbhijklmnopqrsdtuvwxyza
    for(int i = 0;i<26;i++){
        deciph_sub[key[i] - 'a'] = ALPHABET[i];
    }

    //return the array as a string
    return string(deciph_sub);
}


//cipher the text using a key
string sub_cipher(string str,string key){

    //ge the cipher string
    string sub = get_cipher_string(key);


    string ciph = "";

    //for every char in the string if the char is not a alphabet letter add it directly, else get it's substitution in the string
    for(char i : str){
        if(!isalpha(i)){
            ciph += i;
            continue;
        }
        ciph += sub[tolower(i) - 'a'];
    }

    return ciph;
}


//decipher the text using the dicypher key
string sub_decipher(string str,string key){
    string sub = get_cipher_string(key);

    sub = get_decipher_string(sub);

    return sub_cipher(str,sub);
}


//main function for the program
void substitution(){
    cout << "-------Simple Substitution Cipher-------\n";
    cin.ignore();
    while(true){
        cout << "1) cipher\n";
        cout << "2) decipher\n";
        cout << "0) exit\n";
        
        //get the input
        string option;
        getline(cin,option);


        if(option == "0")
            break;
        //check if the user wants to cipher or dicypher since both require the same inputs
        else if(option == "1" || option == "2"){
            string str, key;
            cout << "Insert the sentence: ";
            getline(cin,str);
            cout << "Insert the 5 letters key: ";
            getline(cin,key);

            //loop unitl the key is valid, if there is no problem the loop will break other wise it will keep repeating until the input is valid
            while(true){
                if(key.length() != 5){
                    cout << "Key must be 5 letters: ";
                    getline(cin,key);
                    continue;
                }
                cout << key.length() << endl;
                
                bool flag = false;
                //check for repeating letters
                string repeat = "";

                for(char i : key){
                    if(!isalpha(i)){
                        cout << "Key must be letters only: ";
                        getline(cin,key);
                        flag = true;
                        break;
                    }
                    if(repeat.find(i) < repeat.length()){
                        cout << "Key cant have repeating letters: ";
                        getline(cin,key);
                        flag = true;
                        break;
                    }
                    repeat += i;
                }
                if(!flag)
                    break;
            }

            if(option == "1"){
                cout << "original text: " << str << "        ,using key: " << key << endl;
                cout << "ciphered text: " << sub_cipher(str,key) << endl;
            }
            else{
                cout << "ciphered text: " << str << "        ,key: " << key << endl;
                cout << "deciphered text: " << sub_decipher(str,key) << endl;
            }
        }
        else{
            cout << "Please insert a valid number \n";
        }

    }
}
//main function
int main()
{
    while (true)
    {
        cout << "Welcome to the Cipher program!\n what cipher you want to do\n";
        cout << "1) Atbash\n";
        cout << "2) XOR\n";
        cout << "3) Substitution\n";
        cout << "(any thing else will exit)\n";
        string option;
        cin >> option;
        if(option == "1"){
            atpashCipher();
        }
        else if (option == "2") {
            Xor();
        }
        else if (option == "3") {
            substitution();
        }
        else{
            break;
        }
    }
    return 0;
}

