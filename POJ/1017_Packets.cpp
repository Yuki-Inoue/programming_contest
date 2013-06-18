#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>

using namespace std;

istream &get_nums(istream &is, vector<int> &nums){
    for (int i=1; i<=6; ++i)
        is >> nums[i];
    return is;
}

int main(){
    vector<int> packets(7,0);
    while (get_nums(cin, packets) &&
           accumulate(packets.begin(), packets.end(), 0))
    {
        int subparcels[4] = {0,0,0,0};
        int parcels = 0;

        int div3_to_1subparcels[4]
        = { 0, 7, 6, 5};
        int div3_to_2subparcels[4]
        = { 0, 5, 3, 1};


        parcels += packets[6];

        parcels += packets[5];
        subparcels[1] += 11 * packets[5];

        parcels += packets[4];
        subparcels[2] += 5 * packets[4];

        parcels += packets[3] / 4
        + static_cast<bool>(packets[3] % 4);
        subparcels[1] += div3_to_1subparcels[packets[3] % 4];
        subparcels[2] += div3_to_2subparcels[packets[3] % 4];

        int sub_utilized = min(subparcels[2], packets[2]);
        subparcels[2] -= sub_utilized;
        packets[2] -= sub_utilized;

        parcels += packets[2] / 9
        + static_cast<bool>(packets[2] % 9);

        if (packets[2] % 9)
            subparcels[2] += 9 - packets[2] % 9;

        subparcels[1] += subparcels[2] * 4;

        sub_utilized = min(subparcels[1], packets[1]);
        packets[1] -= sub_utilized;
        subparcels[1] -= sub_utilized;

        parcels += packets[1] / 36
        + static_cast<bool>(packets[1] % 36);

        cout << parcels << endl;
    }
}
