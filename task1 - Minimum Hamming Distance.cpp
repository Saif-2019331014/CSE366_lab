/// task 1 - finding Minimum Hamming Distance in a set of codewords

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define endl    "\n"

int hammingDistance(const string& str1, const string& str2)
{
    int distance = 0;

    if(str1.size() != str2.size())
        return -1;

    for(int i=0; i<str1.size(); ++i)
        if(str1[i] != str2[i])
            distance++;

    return distance;
}

int minimumHammingDistance(const vector<string>& codewords)
{
    if(codewords.size() < 2)
        return 0;

    int minDistance = codewords[0].length();

    for(int i=0; i<codewords.size(); ++i)
        for(int j=i+1; j<codewords.size(); ++j)
            minDistance = min(minDistance, hammingDistance(codewords[i], codewords[j]));

    return minDistance;
}

int main()
{
    int numofCodewords;
    cout<<"Enter the number of codewords: ";
    cin>>numofCodewords;
    vector<string> codewords(numofCodewords);
    cout<<"Enter the codewords:"<<endl;

    for(int i=0; i<numofCodewords; ++i)
        cin>>codewords[i];

    int minDistance = minimumHammingDistance(codewords);
    cout<<"The minimum Hamming Distance of the given set of codewords: "<<minDistance<<endl;
    return 0;
}
