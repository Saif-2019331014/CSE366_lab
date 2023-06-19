/// task 2 - finding Even Parity codeword of a dataword and simulating data corruption

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

#define endl    "\n"

char calculateEvenParity(const string& dataword)
{
    int cnt = 0;

    for(int i=0; i<dataword.size(); ++i)
        if(dataword[i] == '1')
            cnt++;

    return ((cnt%2)+'0');
}

string addParityBit(const string& dataword)
{
    char parityBit = calculateEvenParity(dataword);
    return (dataword+parityBit);
}

bool isCorrupted(const string& codeword)
{
    char receivedParityBit = codeword.back();
    string dataword = codeword.substr(0, codeword.size()-1);
    char calculatedParityBit = calculateEvenParity(dataword);
    return (receivedParityBit != calculatedParityBit);
}

int main()
{
    string dataword;
    cout<<"Enter the dataword: ";
    cin>>dataword;
    string codeword = addParityBit(dataword);
    cout<<"Added parity: "<<codeword.back()<<endl;
    cout<<"Generated Codeword: "<<codeword<<endl;

    /// Simulating corruption by flipping random bits
    /// parity check (whether it's even parity or odd parity) cannot detect even number of corrupted bits
    cout<<endl<<"Data corruption simulation"<<endl;
    srand(time(0));

    while(1)
    {
        int sz = codeword.size();
        string corruptedCodeword = codeword;
        bool alreadyCorrupted[sz] = {false};
        int counter = (rand()%sz)+1;

        while(counter)
        {
            int flipIndex = rand()%sz;

            if(!alreadyCorrupted[flipIndex])
            {
                corruptedCodeword[flipIndex] = (corruptedCodeword[flipIndex] == '0') ? '1' : '0';
                alreadyCorrupted[flipIndex] = true;
                counter--;
            }
        }

        cout<<"Actual codeword: "<<codeword<<endl;
        cout<<"Corrupted codeword: "<<corruptedCodeword<<endl;
        cout<<"Real verdict: Received codeword is corrupted."<<endl;

        /// Check if the parity checker can detect if the codeword is corrupted
        bool isCorruptedFlag = isCorrupted(corruptedCodeword);
        cout<<"Parity checker verdict: ";

        if(isCorruptedFlag)
            cout<<"Received codeword is corrupted."<<endl;
        else
            cout<<"Received codeword is not corrupted."<<endl;

        cout<<endl<<"Do you want to simulate again? (Y/y or N/n) ";
        char ch;
        cin>>ch;
        ch = toupper(ch);

        if(ch == 'N')
            break;
    }

    return 0;
}
