/// task 3 - finding the CRC codeword for given {dataword, divisor} and simulating data corruption

#include <iostream>
#include <string>
#include <time.h>

using namespace std;

#define endl    "\n"

string performCRCdivision(const string& dataword, const string& divisor)
{
    string dividend = dataword;
    int divisorLength = divisor.size();

    for(int i=0; i<divisorLength-1; ++i)
        dividend += '0';

    for(int i=0; i<dividend.size()-divisorLength+1; ++i)
    {
        for(int j=0; j<divisorLength; ++j)
            dividend[i+j] = (dividend[i+j] == divisor[j]) ? '0' : '1';

        while(i<(dividend.size()-divisorLength) && dividend[i+1]!='1')
            ++i;
    }

    return dividend.substr(dataword.size());
}

string addCRCcodeword(const string& dataword, const string& remainder)
{
    return dataword + remainder;
}

bool isCorrupted(const string& codeword, const string& divisor)
{
    string remainder = performCRCdivision(codeword, divisor);

    for(char bit: remainder)
        if(bit == '1')
            return true;

    return false;
}

int main()
{
    string dataword, divisor;
    cout<<"Enter the dataword: ";
    cin>>dataword;
    cout<<"Enter the divisor: ";
    cin>>divisor;
    string remainder = performCRCdivision(dataword, divisor);
    string codeword = addCRCcodeword(dataword, remainder);
    cout<<"Remainder: "<<remainder<<endl;
    cout<<"CRC codeword for the given dataword and divisor: "<<codeword<<endl;

    /// Simulating corruption by flipping random bits
    /// CRC can always detect data corruption. That's why it's the most reliable method
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

        /// Check if the CRC can detect if the codeword is corrupted
        bool isCorruptedFlag = isCorrupted(corruptedCodeword, divisor);
        cout<<"CRC verdict: ";

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
