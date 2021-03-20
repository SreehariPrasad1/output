#include<bits/stdc++.h>
using namespace std;
int main()
{
    ofstream fout;
    ifstream fin;
    fin.open("input.txt");
    string s,line,first,num,line2;
    string items[100];
    int prices[100];
    vector<pair<int,string>> hash;
    getline(fin,first);
    int n = 0,i;
    for (i = first.length()-1; i > 0; i--)
    {   
        if(first[i] == ' ') {
            break;
        }
        num.push_back(first[i]);
    }
    stringstream numextract(num); 
    numextract >> n;
    int what = n;
    cout<<"initial "<<what<<endl;
    getline(fin,line);
    getline(fin,line);
    getline(fin,line);
    i = 0;
    while(fin) {
        fin>>line;
        if(line[line.length()-1] != ':') {
            fin>>line2; fin>>num;
            line.push_back(' ');
            line.append(line2);
            stringstream numextract(num); 
            numextract>>n;
            items[i] = line;    prices[i] = n;
            hash.push_back(make_pair(n,line));
            //cout<<items[i]<<" out "<<n<<endl;
            i++;
        }
        else {
            items[i] = line;
            fin>>num;
            stringstream numextract(num); 
            numextract>>n;
            items[i] = line;    prices[i] = n;
            //cout<<items[i]<<" in "<<n<<endl;
            hash.push_back(make_pair(n,line));
            i++;
        }
    }
    i--;
    hash.pop_back();
    sort(hash.begin(),hash.end());
    for(auto x : hash)
    {
        cout<<x.first<<' '<<x.second<<endl;
    }
    int index = 0, min = INT_MAX;
    for (int j = 0; j < i-4; j++)
    {
        if(hash[j+3].first - hash[j].first < min) {
            index = j;
            min = hash[j+3].first - hash[j].first;
            //cout<<"Difference "<<hash[j+3].first - hash[j].first<<endl;
            //cout<<hash[j].second<<' '<< hash[j+3].second<<endl;
        }
    }
    cout<<min<<endl;
    cout<<index<<endl;
    fout.open("output.txt"); 
    fout<<"The goodies selected for distribution are:"<<endl;
    fout<<endl;
    cout<<"The valie of aifnafjk"<<n<<endl;
    while(what > 0) {
        string op;
        op.append(hash[index].second);
        op.append(" ");
        ostringstream str1; 
        str1 << num;
        string lol = str1.str(); 
        op.append(lol);
        fout<<op<<endl;
        index++;
        what--;
    }
    fout<<endl;
    fout<<"And the difference between the chosen goodie with highest price and the lowest price is "<<min;
}