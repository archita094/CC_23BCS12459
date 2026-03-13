#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
int singleElement(vector<int>& arr) {
    int result = 0;
    int n = arr.size();

    for (int i = 0; i < 32; i++) {
        int sum = 0;

        for (int j = 0; j < n; j++) {
            if ((arr[j] >> i) & 1)
                sum++;
        }

        if (sum % 3 != 0)
            result |= (1 << i);
    }

    return result;
}
int main()
{
    int n;
    cin>>n;
    int a;
    vector<int>ar;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        ar.push_back(a);
    }
    cout<<singleElement(ar);
    return 0;
}