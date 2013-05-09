#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

unsigned inversions(const string &dna){
    unsigned c = 0,g = 0,t = 0;
    unsigned ret = 0;
    for (int i=0; i<dna.size(); ++i) {
        switch (dna[i]) {
            case 'A':
                ret += c+g+t;
                break;
            case 'C':
                ret += g+t;
                ++c;
                break;
            case 'G':
                ret += t;
                ++g;
                break;
            case 'T':
                ++t;
                break;
            default:
                break;
        }
    }
    return ret;
}

int main(){
    typedef map<unsigned, vector<string> > Map;
    Map sorted_map;
    unsigned n,m;
    cin >> n >> m;
    while (m--) {
        string dna;
        cin >> dna;
        unsigned invs = inversions(dna);
//        cerr << dna << ": " << invs << endl;
        sorted_map[invs].push_back(dna);
    }
    Map::const_iterator it;
    for (it=sorted_map.begin(); it!=sorted_map.end(); ++it) {
//        cerr << it->first << endl;
        vector<string>::const_iterator vit;
        for (vit=it->second.begin(); vit!=it->second.end(); ++vit) {
            cout << *vit << endl;
        }
    }
}
