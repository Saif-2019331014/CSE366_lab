/// task 4 - finding the Checksum codeword for a list of n-bit numbers

#include <iostream>
#include <vector>

using namespace std;

/// Just change the value of SIZE and MAX depending on your checksum type
const int SIZE = 4; /// number of bits
const int MAX = 15; /// (2^SIZE)-1

int findChecksum(int& Sum)
{
    int leftSum, rightSum, Checksum;

    while(1)
    {
        leftSum = Sum>>SIZE;
        rightSum = Sum&MAX;

        if(leftSum == 0)
            break;

        Sum = leftSum+rightSum;
    }

    Checksum = ~Sum;
    Checksum &= MAX;
    return Checksum;
}

int main()
{
    int numberofUnits, Sum = 0, Checksum;
    cout<<"Enter the number of units in the dataword: ";
    cin>>numberofUnits;
    vector<int> Units(numberofUnits);
    cout<<"Enter the unit values:"<<endl;

    for(int i=0; i<numberofUnits; ++i)
    {
        cin>>Units[i];
        Sum += Units[i];
    }

    Checksum = findChecksum(Sum);
    cout<<"Checksum: "<<Checksum<<endl;
    cout<<"Checksum codeword: {";

    for(int val: Units)
        cout<<val<<", ";

    cout<<Checksum<<"}"<<endl;
    return 0;
}
